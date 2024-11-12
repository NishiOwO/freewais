/*                               -*- Mode: C -*- 
 * $Basename: waisserver.c $
 * $Revision: 1.9.1.13.1.3 $
 * Author          : Harry Morris, morris@think.com
 * Created On      : 5.29.90
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:44:49 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* $Format: "#define SERVER_DATE \"$Date$\""$ */
#define SERVER_DATE "Mon, 05 May 1997 11:54:27 +0200"

#ifndef lint
static char *PRCSid = "$Id: waisserver.c 1.9.1.13.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define INFO_DICT    "INFO.dct"
#define LOCKFILE    "/tmp/INFO.lock" /* while re-indexing INFO */
#define NAPTIME     1		     /* seconds */
#define MAXNAPTIME  0		/* Don't wait, just go on. */

#include "server.h"
#include "sockets.h"
#include <sys/stat.h>
#include "cdialect.h"

#ifdef I_FCNTL
#include <fcntl.h>
#else /* not I_FCNTL */
#include <sys/fcntl.h>
#endif /* not I_FCNTL */

#ifdef SYSV			
#define SIGCHLD SIGCLD
#endif
#include <signal.h>

#ifdef I_SYS_SELECT
#include <sys/select.h>
#endif
#include "cdialect.h"
#include "panic.h"
#include "ustubs.h"
#include "transprt.h"
#include "wmessage.h"
#include "ir.h"
#include "wprot.h"
#include "cutil.h"
#include "futil.h"
#include "irext.h"
#include "irsearch.h"

/* to create the INFO index */
#include "irtfiles.h"
#include "irfiles.h"
#include "irhash.h"

#include <errno.h>
#ifdef Mach 
extern int errno;
#endif

static long bufferSize = BUFSZ; /* how much we are using
                                   (we get one of these per process) */


/* Bitmap association table -- LEB/HSTX 8/5/92 */
#ifdef STELAR
#define LOOKUP_TABLE /archives/stelar/abs/wais/bitmap.table

char *bitmap_table = "LOOKUP_TABLE";

/* char *bitmap_table = "/archives/stelar/abs/wais/bitmap.table"; */
#endif /* STELAR */

/*---------------------------------------------------------------------------*/

#define TIMEOUT_LENGTH 3600 /* one hour timeout. */
#define IDLE_TIME "1 hour"

void
serve_client(in,out, index_directory)
FILE* in;
FILE* out;
char *index_directory;
{ 
  char buf[BUFSZ];		/* contains the message and header */
  char *bufPtr ;		/* points at the begining of the z3950 */
  long size;			/* bytes in the z3950 message */
  WAISMessage header;		/* for storing the header */
  long i;
  long bytesLeft;
  struct itimerval new, old;
  long nextChar;

  new.it_interval.tv_sec = 0;
  new.it_interval.tv_usec = 0;
  new.it_value.tv_sec = TIMEOUT_LENGTH;
  new.it_value.tv_usec = 0;

  bzero(buf, BUFSZ*sizeof(char)); /* avoid umr (up)/8/94 */
  getitimer(ITIMER_REAL, &old);
  while (TRUE)
    {
      /* try to read the header */
      for (i = 0; i < HEADER_LENGTH; i++)
	{ 
	  setitimer(ITIMER_REAL, &new, NULL);
	  nextChar = fgetc(in);
	  if (nextChar == EOF)	/* my connection exited, so will I */
	    { 
	      return;
	    }
	  else
	    buf[i] = (char)nextChar;
	}

      setitimer(ITIMER_REAL, &old, NULL);
      /* parse the header */
      readWAISPacketHeader(buf,&header);

      /* make sure we have the right version.  
	 If we dont, we dont know what to do. */
      if (header.hdr_vers > HEADER_VERSION)
	panic("Incompatable header versions (Current version: %c, supplied version: %c.", 
	      HEADER_VERSION, header.hdr_vers) ;

      /* determine the size of the z3950 message */
      {
	char length_array[11];
	strncpy(length_array, header.msg_len, 10);
	length_array[10] = '\0';
	size = atol(length_array);
      }

      /* set bufPtr to start the z3950 message */
      bufPtr = buf + HEADER_LENGTH ;

      /* read the z3950 message */
      for (i = 0; i < size ; i++) {
	setitimer(ITIMER_REAL, &new, NULL);
	buf[i + HEADER_LENGTH] = (char)fgetc(in) ;
      }

      fflush(in);
      rewind(in);

      /* decode the z3950 if necessary */
      transportDecode((long)header.encoding,bufPtr,&size);
     
      /* XXX handle compression options */

      /* process it the z3950 */
      bytesLeft = bufferSize;

      size = interpret_buffer(bufPtr,size,bufPtr,bytesLeft,
			      &bufferSize,(long)header.hdr_vers,
			      index_directory); 

      /* re-encode the message if necessary */
      transportCode((long)header.encoding,bufPtr,&size); 

      /* XXX handle compression options */

      /* write the new header */
      writeWAISPacketHeader(buf,size,
			    (long)header.msg_type,header.server,
			    (long)header.compression,(long)header.encoding,
			    (long)header.hdr_vers);

      /* write the whole response to the output file */
      for (i = 0; i < size + HEADER_LENGTH; i++)
	fputc(buf[i],out) ;

      fflush(out);		/* flush any file buffers */
      rewind(out);		/* reset the file for read */

    }
}

/*---------------------------------------------------------------------------*/

typedef struct sigcontext sigcontext_t;

static void
breakKey (s1,s2,s3,s4)
long s1;
long s2;
struct sigcontext *s3;
char *s4;
{
  if(0 != finished_search_engine())
    panic("unable to close search engine");
  panic ("got a ^c");
}

/*---------------------------------------------------------------------------*/

void
childhandler(sig, code, scp, addr)
long sig, code;
struct sigcontext *scp;
char *addr;
{
  wait(NULL);			/* give the kid a decent burial */
  signal (SIGCHLD, childhandler);  /* Dave Judd - IRIX requires resetting signal */
}

/*---------------------------------------------------------------------------*/

void
alarmhandler(sig, code, scp, addr)
long sig, code;
struct sigcontext *scp;
char *addr;
{
  waislog(WLOG_HIGH, WLOG_CLOSE,
	  "Server idle longer %s. Closing server and exiting.", IDLE_TIME);
  if(0 != finished_search_engine())
    panic("unable to close search engine");
  exit(0);
}

/*---------------------------------------------------------------------------*/

Signal_t
seghandler(sig, code, scp, addr)
long sig, code;
struct sigcontext *scp;
char *addr;
{
  waislog(WLOG_HIGH, WLOG_ERROR, "Segmentation violation.");
  waislog(WLOG_HIGH, WLOG_CLOSE, "Bummer. Closing server and exiting.");
#ifdef DUMPCORE
    abort();
#else
  exit(-1);
#endif
}

/*---------------------------------------------------------------------------*/

void
bushandler(sig, code, scp, addr)
long sig, code;
struct sigcontext *scp;
char *addr;
{
  waislog(WLOG_HIGH, WLOG_ERROR, "Bus error.");
  waislog(WLOG_HIGH, WLOG_CLOSE, "Bummer. Closing server and exiting.");
#ifdef DUMPCORE
    abort();
#else
  exit(-1);
#endif
}

/*---------------------------------------------------------------------------*/

#include <pwd.h>

int finduid(name)
char *name;
{
  struct passwd *pwent;

  if ((pwent = getpwnam(name)) == NULL) {
    return -1;
  }

  return(pwent->pw_uid);
}

static  char *index_dir = NULL;
static  time_t info_change_time;
static  int indexing_needed = 0;
static  char *info_dict = INFO_DICT;

extern int alphasort();

/* selecttion function for scandir()
 * trigger on ".src" extension, regular file, and != "INFO.src"
 * Indexing is needed if any of the .src files is younger than 
 * INFO.dct
 */
static int
srcfiles(e)
	Direntry_t *e;
{
	struct stat sb;
	char *lastdot = strrchr(e->d_name,'.');
	int candidate;

	candidate =	lastdot && 
	      (stat(merge_pathnames(e->d_name,index_dir), &sb) >= 0) && 
	      ((sb.st_mode & S_IFMT) == S_IFREG) &&
	      !strcmp(lastdot,source_ext) && 
	      strcmp(e->d_name,info_dict); /* whew */

        if (candidate) {
	    indexing_needed |= (sb.st_mtime > info_change_time);
	    return 1;
	}
	return 0;
}

/*---------------------------------------------------------------------------*/

#ifdef HAS_SYS_ERRLIST
#ifdef EXTERN_SYS_ERRLIST
extern char *sys_errlist[];
#endif
extern int      errno;
extern int      sys_nerr;
#endif

Pid_t pgrp;

/* detach() was stolen right off of NCSA's httpd */
static void 
detach() {
    int x;

    if((x = fork()) > 0)
        exit(0);
    else if(x == -1) {
	waislog(WLOG_HIGH, WLOG_ERROR, "Error: fork(): %s", 
		Strerror(errno));
        exit(1);
    }
#ifndef NO_SETSID
    if((pgrp=setsid()) == -1) {
	waislog(WLOG_HIGH, WLOG_ERROR, "Error: setsid(): %s", 
		Strerror(errno));
        exit(1);
    }
#else
    if((pgrp=setpgrp(getpid(),0)) == -1) {
	waislog(WLOG_HIGH, WLOG_ERROR, "Error: setpgrp(): %s", 
		Strerror(errno));
        exit(1);
    }
#endif    
}


/*---------------------------------------------------------------------------*/

#ifdef SET_LIMIT
#include <sys/resource.h>
#endif

#define INDEX_FORK

extern char *inet_ntoa ();
extern char *syslog_name;

void
main(argc,argv)
int argc;
char* argv[];
{ FILE *file;
  long socket;
  char *next_argument = next_arg(&argc, &argv), *command_name;
  boolean use_stdio = TRUE;		/* default is true */
  /* char *wais_log_file_name = NULL; */	/* name of file for error output */
  int child_proc;		/* for the child process id */
  char *uid_name = "root";	/* user id so setuid if root */
  int uid = 0;		/* if not specified, leave as root. */
  int child;
  long cm_mem_percent = 0;  /* default */
  struct stat statbuf;
  Direntry_t **list;
  int naptime = 0;
  extern void filename_finish_header_function();
  dataopsrec	dataops;  
  int detach_flag = 0;	/* if specified, fork and setsid() */

#ifdef CACHE_SYN
  int cachesyn = 0;
#endif

#ifdef SET_LIMIT
  struct rlimit rlp;

  getrlimit(RLIMIT_CORE, &rlp);
  rlp.rlim_cur = rlp.rlim_max;
  setrlimit(RLIMIT_CORE, &rlp);
  getrlimit(RLIMIT_DATA, &rlp);
  rlp.rlim_cur = rlp.rlim_max;
  setrlimit(RLIMIT_DATA, &rlp);
#endif

/* dgg -- must duplicate mods to irbuild.c, here is mini-build of INFO.src */
  bzero(&dataops,sizeof(dataops));
  dataops.separator_function= NULL;
  dataops.header_function= NULL;
  dataops.date_function= NULL;
  dataops.finish_header_function= filename_finish_header_function;
  dataops.type= "WSRC";
  dataops.wordDelimiter= wordbreak_notalnum;
  dataops.addseparatorwords= false;
  dataops.extraheaderweight= true;
  dataops.repeat_weight= 1;
  dataops.minwordlen= 2;
  stop_list_file("\0");
  gDelimiters[0]= '\0';  
  wordDelimiter= wordbreak_notalnum;   
/* dgg -- end new inits */

  tcp_port = 210;			/* tcp_port to use */
  command_name = next_argument;
  syslog_name = (syslog_name = (char *)rindex(command_name, '/')) ? (syslog_name + 1) : command_name;
  host_name[0] = 0;
  host_address[0] = 0;

  server_name = s_malloc(255);
  mygethostname(server_name, 255);

  wais_pid = getpid();

  if (!strcmp(command_name, "waisserver.d")) {
    struct sockaddr_in source;
    int sourcelen;

    sourcelen = sizeof(struct sockaddr_in);

    if (!getpeername(fileno(stdout),(struct sockaddr *)&source,&sourcelen)) {
      struct hostent *peer = NULL;

#ifdef __DGUX__
      peer = gethostbyaddr((char *)&source.sin_addr.s_addr, 4, AF_INET);
#else
      peer = gethostbyaddr((char *)&source.sin_addr, 4, AF_INET);
#endif

      if(peer != NULL) {
	sprintf(host_name, "%s", peer->h_name);

	sprintf(host_address, "%s",
#if defined(sparc) && defined(__GNUC__) && defined(INET_NTOA_WITH_POINTER)
		inet_ntoa(&source.sin_addr)
#else
		inet_ntoa(source.sin_addr)
#endif				/* sparc */
		);
      }
    }
    else sprintf(host_address, "Error getting socket: %d, %s.", errno, Strerror(errno));

   use_stdio = TRUE;
  }

  if (argc == 0){
#ifdef CACHE_SYN
    fprintf(stderr,"Usage: %s [-p [port_number]] [-s] [-d directory] [-u user] [-cmmem number] [-cachesyn] [-detach] [-v]\n",
#else
    fprintf(stderr,"Usage: %s [-p [port_number]] [-s] [-d directory] [-u user] [-cmmem number] [-detach] [-v]\n",
#endif
	   command_name);
    fprintf(stderr," -p [port] listen to the port.  If the port is supplied, then\n");
    fprintf(stderr,"    that tcp_port number is used.  If it is not supplied \n");
    fprintf(stderr,"    then the Z39.50 port (210) is used.\n");
    fprintf(stderr," -d directory: means to use the directory as the source of databases.\n");
    fprintf(stderr,"    Defaults to the current directory.\n");
    fprintf(stderr," -e [file]: set log output to file, or /dev/null if not specified.\n");
    fprintf(stderr," -l log_level: set log level.  0 means log nothing,\n");
    fprintf(stderr,"    10 [the default] means log everything.\n");
    fprintf(stderr," -s means listen to standard I/O for queries.  This is the default\n");
    fprintf(stderr," -u user: if started as root, setuid to user after startup.\n");
    fprintf(stderr," -cmmem number: percentage of CM memory to use (CM code only).\n");
#ifdef CACHE_SYN
    fprintf(stderr," -cachesyn: cache synonym table in shared memory (default is don't cache)\n");
#endif
    fprintf(stderr," -detach: fork off a new process and make it the session leader.\n");
    fprintf(stderr,"          (useful when starting from boot scripts)\n");
    fprintf(stderr," -v prints the version.\n");
    exit(1);
  }
  if(NULL == (next_argument = next_arg(&argc, &argv))){
    fprintf(stderr,"No arguments specified\n");
    exit(0);
  }
  while((next_argument != NULL) &&
	('-' == next_argument[0])){

    /* then we have an argument to process */
    if (0 == strcmp("-p", next_argument)){
      char *peek_argument = peek_arg(&argc, &argv);
      use_stdio = FALSE;
      if ((NULL != peek_argument) && /* if we are not out of args */
	  ('-' != peek_argument[0])){ { /* and the next isn't an option... */
	    /* get the port number */
	    tcp_port = atoi(next_arg(&argc, &argv));
	  }			/* end if (explicit tcp_port) */
				    }
    }				/* end if (-p) */
    else if (0 == strcmp("-s", next_argument)){
      use_stdio = TRUE;
    }				/* end if (-s) */

    else if (0 == strcmp("-e", next_argument)) {
      char *peek_argument = peek_arg(&argc, &argv);
      wais_log_file_name = "/dev/null"; /* default to /dev/null */
      if ((peek_argument != NULL) &&
	  ('-' != peek_argument[0])) {
	wais_log_file_name = next_arg(&argc, &argv);
      }				/* end if (explicit log file) */
    }				/* end if (-e) */
    else if (0 == strcmp("-l", next_argument)) {
      wais_log_level = atol(next_arg(&argc, &argv));
    }				/* end if (-l) */
    else if (0 == strcmp("-d", next_argument)) {
      index_dir = next_arg(&argc, &argv);
    }
    else if (0 == strcmp("-v", next_argument)) {
      fprintf(stderr,"%s: %s, %s\n", command_name, VERSION_STRING, SERVER_DATE);
    }
    else if (0 == strcmp("-u", next_argument)) {
      uid_name = next_arg(&argc, &argv);
      if((uid = finduid(uid_name)) < 0)
	panic("Couldn't find user %s.", uid_name);
    }
    else if(0 == strcmp("-cmmem", next_argument)){
      if(NULL == (next_argument = next_arg(&argc, &argv)))
	panic("Expected a number (1-100) for percentage of memory to use");
      cm_mem_percent = atol(next_argument);
      if(cm_mem_percent < 1)
	panic("The -cmmem argument should not be less than 1 and less than 100");
      if(cm_mem_percent > 100)
	panic("Warning: The -cmmem parameter was %ld%%. It should be between 1-100.", cm_mem_percent);
    }
#ifdef CACHE_SYN
    else if (0 == strcmp("-cachesyn", next_argument)) {
      cachesyn = 1;
    }
#endif
    else if (0 == strcmp("-detach", next_argument)) {
      detach_flag = 1;
    }
    else{
      panic("Don't recognize the %s option", next_argument);
    }
    next_argument = next_arg(&argc, &argv);
  }				/* end while (more arguments) */

  if (use_stdio && wais_log_file_name == NULL) 
    wais_log_file_name = "/dev/null";

  if (detach_flag)
    detach();

  if (wais_log_file_name == NULL) 
    waislogfile = stderr;
  else waislogfile = NULL;

  index_dir = index_dir ? index_dir : ".";  
  info_dict = s_strdup(merge_pathnames(info_dict,index_dir));

  if(0 != init_search_engine(index_dir, false, true, cm_mem_percent,0,0))
    panic("unable to initialize search engine");
  
  /* remember timestamp on INFO.dct if rebuilding needed 
   * If it doesnt exist, it's assumed to be *very* old, to force
   * re-indexing
   */
  info_change_time = (stat(info_dict,&statbuf) == -1) ? 0 : statbuf.st_mtime;
  
  /* compare with candidates */

  if (scandir(index_dir, &list, srcfiles, alphasort) < 0) {
      waislog(WLOG_HIGH, WLOG_ERROR, 
	      "Error: reading directory %s, %s", 
	      index_dir, Strerror(errno));
      indexing_needed = FALSE;
  }
  
  /* ok. we know if we need indexing, 
   * and have all the filenames. 
   */
  
  if (info_change_time == 0) indexing_needed = TRUE;
  if (indexing_needed) {
#ifndef DO_NOT_TELL_ABOUT_ME
    extern int sayiamhere _AP(());
    sayiamhere();
#endif

    /* Time to re-index,
     * aquire the lock 
     */
    waislog(WLOG_MEDIUM, WLOG_INDEX,
	    "re-indexing needed, info_change_time=%d",info_change_time); 

    if (open(LOCKFILE, O_WRONLY|O_CREAT|O_EXCL,0666) == -1) {
	  
      /* already locked by somebody else
       * spin  till she finishes
       */
      while (!(stat(LOCKFILE,&statbuf) == -1)) {
	sleep(NAPTIME);
	naptime += NAPTIME;
	waislog(WLOG_MEDIUM, WLOG_INFO,
		"INFO locked, waiting since %d seconds", naptime);
	if (naptime  > MAXNAPTIME)  {

	  waislog(WLOG_HIGH, WLOG_WARNING,
		  "Warning - lockfile %s won't go away after %d seconds, not reindexing.", 
		  LOCKFILE, naptime);
	  break;
	}
      }
      /* if lockfile went away, assume INFO.* build finished
       * so just use it
       */
    } else {			/* we aquired the lock, so rebuild database  */
	  
#ifdef INDEX_FORK
      if (!(child = fork())) {
#endif
	database *db;
	Direntry_t **s = list;
	char filename[MAX_FILENAME_LEN], *dbname;

	waislog(WLOG_MEDIUM, WLOG_INDEX,
		"Creating INFO database, pid=%d",getpid());
	dbname = s_strdup(merge_pathnames("INFO",	index_dir));
#ifdef FIELDS /* tung, 3/94 */
	db = openDatabase(dbname, true, false, false); 
#else
        db = openDatabase(dbname, true, false);
#endif
	s_free(dbname);

	init_add_word(db, 0, 100000L);

	while (list && *s) {		/* index it */
	  strncpy(filename, index_dir, MAX_FILENAME_LEN);
	  if(index_dir[strlen(index_dir) -1] != '/')
	    strncat(filename, "/", MAX_FILENAME_LEN);
	  strncat(filename, (*s)->d_name, MAX_FILENAME_LEN);
	  waislog(WLOG_MEDIUM, WLOG_INDEX,
		  "Indexing %s", filename);
	  index_text_file(filename, &dataops, db, true, false,
			  false, true
#ifdef FIELDS /* tung, 5/94 */ 
			  ,-1
#endif
			  );    
	  s++;
	}
	if (list)
	  freedir(list);		/* array of filenames */
	      
	if(!probe_file(source_filename(filename, db)))
	  write_src_structure(source_filename(filename, db),
			      "INFO", "WSRC", NULL, 0L, true, 
#ifdef FIELDS /* tung, 3/94 */                              
                              tcp_port, db);
#else
                              tcp_port);
#endif
	finished_add_word(db);
	build_catalog(db);
	closeDatabase(db);
	if (unlink(LOCKFILE))
	  panic("Indexer: cant unlink lockfile!\n");
	waislog(WLOG_MEDIUM, WLOG_INDEX,
		"Indexer pid=%d done", getpid());
	      
#ifdef INDEX_FORK
	exit(0);		/* indexing child */
      }
      else if (child == -1) {
	waislog(WLOG_HIGH, WLOG_ERROR,
		"Unable to fork for indexer.");
	exit(1);
      }
      /* wait for child process */
      else while (wait(0) != child) ; /* do nothing */
#endif      
    }
  }


  if (use_stdio == TRUE) {
    if(host_address[0] != 0){
      waislog(WLOG_MEDIUM, WLOG_CONNECT,
	      "Accepted connection from: %s [%s], %s",
	      host_name, host_address, VERSION_STRING);
    }
    else{
      waislog(WLOG_MEDIUM, WLOG_CONNECT,
	      "Couldn't determine peer connection. %s", VERSION_STRING);
    }

    if ( server_security(index_dir,NULL) != true ){
      waislog(WLOG_HIGH, WLOG_INFO,"Closing down server");
      exit(-1);
     }

  }
  else{
    waislog(WLOG_MEDIUM, WLOG_INFO, "Running server %s", VERSION_STRING);
  }

  signal(SIGINT, breakKey);

  signal(SIGCHLD, childhandler);  	/* XXX dont really need this any more */
  signal(SIGALRM, alarmhandler);

  signal(SIGSEGV, seghandler);

  signal(SIGBUS, bushandler);

  if(use_stdio == FALSE)
   { 
     if (tcp_port < 1024 && getuid() != 0) {
       waislog(WLOG_HIGH, WLOG_ERROR,
	       "Error opening port %d:  Must be superuser to use a port < 1024",
	       tcp_port);
       exit(-1);
     }

     open_server(tcp_port,&socket,BUFSZ);

#ifdef SECURE_SERVER
     /* if root, setuid to user specified id. */
     if (uid > 0 && getuid() == 0)  {
       waislog(WLOG_MEDIUM, WLOG_INFO,
	       "Setting uid to %s.", uid_name);
        if (wais_log_file_name && *wais_log_file_name &&
 	   chown(wais_log_file_name,uid,getgid()) < 0)
	 waislog(WLOG_HIGH, WLOG_ERROR,
		 "Unable to chown log file to %s!", uid_name);
       if ( 0 > setuid(uid)) {
	 waislog(WLOG_HIGH, WLOG_ERROR,
		 "Unable to setuid to %s!  Exiting.", uid_name);
	 exit(-1);
       }
     }
#endif

#ifdef CACHE_SYN
     if (cachesyn) {
       /* create and attach master shared memory segment containing info
	* on cached synonyms (see synonym.c) */
       int shm_key = 1, shm_cnt = 0;
       char *pcs = NULL;
       t_cacheSyn *cs = NULL;
       cacheSynId = -1;
       while (cacheSynId == (-1)) {
	 cacheSynId = shmget (shm_key, MAX_SYN_CACHE * sizeof(t_cacheSyn), 
			      0644 | IPC_CREAT | IPC_EXCL);
	 if (cacheSynId == (-1) && errno != EEXIST) 
	    break;
	 shm_key++;
       }
       if (cacheSynId <= 0) {
	 cacheSynId = 0;
	 waislog (WLOG_HIGH, WLOG_WARNING, 
		  "Warning: cannot get shared memory area for synonyms, caching disabled");
       }
       else {
	 /* get shared memory for and initialize t_cacheSyn structure */
	 if ((pcs = (char *) shmat (cacheSynId, 0, 0)) == ((char *)-1)) {
	   cacheSynId = 0;
	   waislog (WLOG_HIGH, WLOG_WARNING, 
		    "Warning: cannot attatch shared memory segment for synonyms, caching disabled");
	 }
	 else {
	   for (shm_cnt = 0; shm_cnt < MAX_SYN_CACHE; 
		shm_cnt++, pcs += sizeof(t_cacheSyn)) {
	     cs = (t_cacheSyn *) pcs;
	     cs->id = 0;
	     (cs->synfile)[0] = '\0';
	   }
	 }
       }
     }
#endif

     while (TRUE) { /* be a server for several connections */
       accept_client_connection(socket,&file);
	  
#ifdef QUERY_FORK
       if ((child_proc = fork()) == 0) {
#endif	      
	      /* grandson handles this connection
	       * double-fork takes care of zombies 
	       */
#ifdef QUERY_FORK
	      if ((child_proc = fork()) == 0) { 
#endif
		wais_pid = getpid();
		log_line = 0;
		serve_client(file, file, index_dir);
		/* but leaves server up */
		close_client_connection(file);
		close_server(socket);
		/* just exits this child */
		waislog(WLOG_MEDIUM, WLOG_CLOSE,
			"Done handling client");
#ifdef QUERY_FORK
		exit(0);
	      } else {
		/* son: orphans the grandchild, so init picks up 
		 * the exit status
		 */
		exit(0);
	      }
          } else {
	      waislog(WLOG_MEDIUM, WLOG_INFO,
		      "Child PID = %d", child_proc);
	      close_client_connection(file);     /* parent shouldn't keep the file */
	  }
#endif
      }
   }
  else if(use_stdio == TRUE)
   { /* connections on stdio don't use child processes yet */
     serve_client(stdin, stdout, index_dir);
     waislog(WLOG_MEDIUM, WLOG_CLOSE,
	     "Done handling client");
      /* close the whole thing */
     if(0 != finished_search_engine())
       panic("unable to close search engine");
     exit(0);
   }
}

/*---------------------------------------------------------------------------*/

