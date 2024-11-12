/*                               -*- Mode: C -*- 
 * $Basename: futil.c $
 * $Revision: 1.6.1.8.1.3 $
 * Author          : Brewster Kahle
 * Created On      : Mon May  5 11:35:47 1997
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:36:28 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: futil.c 1.6.1.8.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

/* ======================== */
/* ===  File Utilities  === */
/* ======================== */

#include "cdialect.h"

#ifdef THINK_C
  /* file type info */
#include <pascal.h>		/* for CtoPstr */
#include <FileMgr.h>
#define CREATOR 		'WIS1'
#define WAIS_INDEX_FILE_TYPE 	'INDX'
#else
#include <sys/stat.h> /* for stat */
#include <sys/param.h> /* for getwd */

/* for access() */
#include <sys/file.h>
#endif /* THINK_C */

#include "futil.h"
#include "panic.h"

/*----------------------------------------------------------------------*/

static long numFilesCurrentlyOpen = 0;
static long maxNumFilesOpenAtOneTime = 0;

FILE*
fs_fopen(fileName,mode)
char* fileName;
char* mode;
{
  FILE* file = NULL;
  char realMode[100];
  
#ifdef BSD
#define implicitBinary
#endif /* def BSD */
#ifdef ultrix
#define implicitBinary
#endif /* def ultrix */
#ifndef ANSI_LIKE
#define implicitBinary
#endif /* def ANSI_LIKE */



#ifdef implicitBinary
   /* these old os's don't handle the binary mode.  Just remove it */
   long i,j;
   for (i = 0L,j = 0; mode[i] != '\0';i++)
    { if (mode[i] != 'b')
	realMode[j++] = mode[i];
    }
   realMode[j] = '\0';
  file = fopen(fileName,realMode);
#else
  file = fopen(fileName,mode);
#endif /* def implicitBinary */
  
  if (file != NULL)
    { numFilesCurrentlyOpen++;
      if (numFilesCurrentlyOpen > maxNumFilesOpenAtOneTime)
	maxNumFilesOpenAtOneTime = numFilesCurrentlyOpen;
    }
  
  return(file);
}

/*----------------------------------------------------------------------*/

long
fs_fclose(file)
FILE* file;

{
  if (file != NULL)
    { numFilesCurrentlyOpen--;
      return(fclose(file));
    }
  else
    return(0L);
}

/*----------------------------------------------------------------------*/

long fs_fseek(file,offset,wherefrom)
FILE* file;
long offset;
long wherefrom;
{
  long result;
  
  if(NULL == file)
    return -1;
  
  result = fseek(file, offset, wherefrom);

  /*
  if(0 != result) 
    panic("A seek failed:  offset %ld, wherefrom %d.\n",offset, wherefrom);
    */
  return result;
}

/*----------------------------------------------------------------------*/

long fs_ftell(file)
FILE* file;
{
  long result;
  
  if (file == NULL)
    return(0);
    
  result = ftell(file);
  
  if(EOF == result)
    panic("A seek on an index file failed.\n");

  return(result);
}

/*----------------------------------------------------------------------*/

void grow_file(file,length)
FILE* file;
long length;
{
  long current_length;
  s_fseek(file, 0L, SEEK_END);
  current_length = s_ftell(file);
  s_fseek(file, length - current_length, SEEK_END);
}

/*----------------------------------------------------------------------*/

/* writes the high byte first, this makes reading faster */
long write_bytes(value,size,stream)
long value;
long size;
FILE* stream;
{
  long i;
  long answer;
  if((size < sizeof(long)) && (0 != (value >> (size * 8))))
    panic("In a call to write_bytes, the value %ld can not be represented in %ld bytes", value, size);
  for(i = size - 1; i >= 0; i--){
    answer = putc((value >> (i * 8)) & 0xFF, stream);
  }
  if(ferror(stream) != 0) {
    panic("Write failed");
  }
  return(answer);
}

/*----------------------------------------------------------------------*/

/* returns EOF if it gets an error */
long read_bytes(n_bytes,stream)
long n_bytes;
FILE *stream;
{
  long answer = 0;
  unsigned long ch;
  long i;
  for(i = 0; i < n_bytes; i++){
    ch = fgetc(stream);
    if(EOF == ch){
      return(EOF);
    }
    answer = (answer << 8) + (unsigned char)ch;
  }
  return(answer);
}

/*----------------------------------------------------------------------*/

long read_bytes_from_memory(n_bytes,block)
long n_bytes;
unsigned char *block;
{
  long answer = 0;
  unsigned char ch;
  long i;
  for(i = 0; i < n_bytes; i++){
    ch = *(block++);
    answer = (answer << 8) + ch;
  }
  return(answer);
}

/*----------------------------------------------------------------------*/

time_t file_write_date(filename)
char* filename;
{ /* os dependent */
#ifdef THINK_C
	return((time_t)0);  /* not implemented yet */
#else
  struct stat *buf = (struct stat*)s_malloc((size_t)sizeof(struct stat));
  time_t mtime;



   if(0 != stat(filename, buf)) {
     /* might be the compressed one. */
     char buffer[MAX_FILENAME_LEN+2];
     sprintf(buffer, "%s.Z", filename);
     if (0 != stat(buffer, buf)) {
       sprintf(buffer, "%s.gz", filename);
       if (0 != stat(buffer, buf)) {
         panic("could not stat %s", filename);
       }
     }
  }


  mtime =  buf->st_mtime;
  s_free(buf);
  return(mtime);
#endif /* THINK_C */
}

/*----------------------------------------------------------------------*/

long file_length(stream)
FILE* stream;
/* return the length (in bytes) of a stream - leave the current
   position where it was
 */ 
{
  long position = ftell(stream);
  long end = -1;
  s_fseek(stream, 0L, SEEK_END);
  end = ftell(stream);	
  s_fseek(stream,position,SEEK_SET);
  return(end);
}

/*----------------------------------------------------------------------*/

static char *clean_path _AP((char* filename));

static char *clean_path(filename)
char *filename;
/* this takes out the '/../' and the '/./' from the path by modifying 
   the argument and returning it. The pathname passed to it must be a 
   full path. This is not optimized. */
{
#ifndef THINK_C
  char *beginning_ptr = strstr(filename, "/../");
  if(NULL != beginning_ptr){
    /* then we have something to process.
       reverse search for the beginning of the last directory,
       in order to snuff it */
    char *ptr;
    for(ptr = beginning_ptr - 1; ptr >= filename; ptr--){
      if(*ptr == '/'){
	/* then we found the beginning of the path */
	strcpy(ptr, beginning_ptr + strlen("/../") -1);
	clean_path(filename);	/* get the other occurances of /../ */
	break;
      }	
    }
  }
  /* now look for /./ */
  beginning_ptr = strstr(filename, "/./");
  if(NULL != beginning_ptr){
    strcpy(beginning_ptr, beginning_ptr + strlen("/./") -1);
    clean_path(filename);	/* get the other occurances of /./ */
  }
#endif				/* ndef THINK_C */

  return(filename);

}

/*----------------------------------------------------------------------*/
    
char *truename(filename,full_path)
char *filename;
char *full_path;
{
  /* this puts into full_path the full pathname including directory.
   */
#ifdef THINK_C
  strcpy(full_path, filename);
  return(full_path); /* do nothing */
#else
  if('/' == filename[0]){
    /* then it is complete already */
    strcpy(full_path, filename);
    clean_path(full_path);
    return(full_path);
  }
  else{
#ifdef HAS_GETWD
    getwd(full_path);
#else
    getcwd(full_path, MAX_FILENAME_LEN);
#endif
    s_strncat(full_path,"/",MAX_FILENAME_LEN,MAX_FILENAME_LEN);
    s_strncat(full_path,filename,MAX_FILENAME_LEN,MAX_FILENAME_LEN);
    clean_path(full_path);
    return(full_path);
  }
#endif /* THINK_C */
}

/*----------------------------------------------------------------------*/

char *pathname_name(pathname)
char *pathname;
/* returns a pointer to the leaf name part of full pathname.
   equivalent to common lisp pathname-name. */
{
#ifdef THINK_C
  char *answer = strrchr(pathname, ':');
#else
  char *answer = strrchr(pathname, '/');
#endif	/* THINK_C */

  if(NULL == answer)
    return(pathname);
  return(answer + 1);
}

/*----------------------------------------------------------------------*/

char *pathname_directory(pathname,destination)
char *pathname;
char *destination;
/* returns a pointer to a string of the directory part of
   the pathname and modifies its destination argument.
   This is the equivalent to the common lisp pathname-directory function. */
{
#ifdef THINK_C
  char *dirptr = strrchr(pathname, ':');
#else
  char *dirptr = strrchr(pathname, '/');
#endif /* THINK_C */

  if(NULL == dirptr)
#ifdef THINK_C
    strncpy(destination, pathname, MAX_FILE_NAME_LEN);
#else
    strncpy(destination, "./", MAX_FILENAME_LEN);
#endif /* THINK_C */
  else
    { strncpy(destination, pathname, MAX_FILE_NAME_LEN);
      destination[dirptr - pathname + 1] = '\0';
    }

  return(destination);
}
  
/*----------------------------------------------------------------------*/

/* Setting the Macintosh File type (requires the MacTraps library) */
/* from Util.c by Harry Morris */

#ifdef THINK_C

void 
setFileType(fileName,type,creator)
char* fileName;
FType type;
FType creator;
{ 
  FInfo info;
  OSErr error;
  
  CtoPstr(fileName);
  error = GetFInfo((StringPtr)fileName,0L,&info);
  if (error != noErr)
    panic("error - Can't get file type of file %s, code %ld\n",
          PtoCstr((char*)fileName),noErr);
  info.fdType = type;
  info.fdCreator = creator;
  error = SetFInfo((StringPtr)fileName,0L,&info);
  if (error != noErr)
    panic("error - Can't change file type of file %s, code %ld\n",
          PtoCstr((char*)fileName),noErr);
  PtoCstr((char*)fileName);
}

#endif /* THINK_C */

/*----------------------------------------------------------------------*/

char *current_user_name()
/* returns the current_user_name as a mail address */
{
  static char answer[200];
  char hostname[120];
  
#ifdef THINK_C
  strcpy(answer,"MAC"); /* could look up the name in the chooser */
#else /* ndef THINK_C */

#ifdef I_PWD
#include <pwd.h>  /* for getpwuid */
#endif

  struct passwd *pwent = getpwuid(getuid());

  if (pwent)
  {
    strncpy(answer, pwent->pw_name, 200);
    strncat(answer, "@", 200);
    mygethostname(hostname, 120);
    strncat(answer, hostname, 200);
  }
  else
    strcpy(answer,"unknown");
#endif /* ndef THINK_C */

  return(answer);
}

/*----------------------------------------------------------------------*/

boolean probe_file(filename)
char *filename;
/* return true if it is there, false otherwise.
   Can this be done faster? 
*/
{
  if (filename == NULL)
    return(false);

  if (!strncmp(filename, "http:", 5)) return(true);
  if (!strncmp(filename, "ftp:", 4)) return(true);

  if (access(filename,R_OK) == 0)
    return(true);
  else
    return(false);
}

/*----------------------------------------------------------------------*/

boolean probe_file_possibly_compressed(filename)
char *filename;
/* return true if it is there, false otherwise.
   Can this be done faster? */
{
  if (filename == NULL)
    return(false);
  else 
    if (probe_file(filename)) {
      return(true);
    } else {/* try the compression */
      char buffer[ MAX_FILENAME_LEN * 2 ];
      strcpy(buffer, filename);
      strcat(buffer, ".Z");
      if (probe_file(buffer)) {
        return(true);
      } else { /* try the zipp */
        strcpy(buffer, filename);
        strcat(buffer, ".gz");
        return(probe_file(buffer));
      }
    }
}

/*----------------------------------------------------------------------*/

/* this opens the file for writing (append)p and then closes it again */
boolean touch_file(filename)
char *filename;
/* return false if error, true otherwise. */
{
  FILE *stream = NULL;
  if (filename == NULL)
    return(false);
  stream = s_fopen(filename, "a");
  if (NULL == stream)
    return(false);
  else
    { s_fclose(stream);
      return(true);
    }
}

/*----------------------------------------------------------------------*/

char *merge_pathnames(pathname, directory)
char *pathname;
char *directory;
{
  /* if the pathname is not complete, then it puts on the directory
     component and returns it in a static variable.  This is Unix specific */
  static char answer[MAX_FILENAME_LEN + 1];
  if((pathname[0] == '/') || (NULL == directory) || directory[0] == '\0')
    return(pathname);
  else{
    answer[0] = '\0';
    strncat(answer, directory, MAX_FILENAME_LEN);
#ifdef THINK_C
    if(directory[strlen(directory) - 1] != ':')
      strncat(answer, ":", MAX_FILENAME_LEN);
#else
    if(directory[strlen(directory) - 1] != '/')
      strncat(answer, "/", MAX_FILENAME_LEN);
#endif
    strncat(answer, pathname, MAX_FILENAME_LEN);
  }
  /* should this call truename? */
  return(answer);
}

/*----------------------------------------------------------------------*/


boolean 
read_string_from_file(stream,array,array_length)
FILE *stream;
char *array;
long array_length;
/* returns true if it wins. */
{
  long ch;
  long char_count = 0;

  array[0] = '\0';
  while(true){
    ch = fgetc(stream);
    if(EOF == ch){
      array[char_count] = '\0';
      return(false);
    }
    else if(char_count == array_length){	    
      array[char_count] = '\0';
      return(false);
    }
    else if('\0' == ch){
      array[char_count] = '\0';
      return(true);
    }
    else
      array[char_count++] = ch;
  }
}

/*----------------------------------------------------------------------*/

/* counts the lines in a file */
long count_lines(stream)
FILE *stream;
{
  long answer = 1;
  char line[100];
  fseek(stream, 0L, SEEK_SET);	
  while(NULL != fgets(line,100L,stream))
    answer++;
  return(answer);
}



/*----------------------------------------------------------------------*/

#ifndef UNCOMPRESSOR
#define UNCOMPRESSOR "zcat"
#endif
#ifndef UNZIPPER
#define UNZIPPER "gzip"
#endif

char*
fs_fzcat(fileName)
char *fileName;
/* uncompress the file fileName
   returns a pointer to the name of the uncompressed file if succeeds
   returns NULL if failed
*/
{


  char buffer[ 2 * MAX_FILENAME_LEN + 10 ];
  long err = 0L;
  

#if (defined(NeXT) || defined(Mach) || defined(BSD43)) || defined(__convex__)
  char tmpFileName[MAX_FILENAME_LEN+1];
#else
  char *tmpFileName = NULL;
#endif				/* NeXT or Mach */
  char *retptr;

  if (fileName == NULL)
    return(NULL);

#if defined(NeXT) || defined(Mach) || defined(BSD43) || defined(__convex__)
  tmpnam(tmpFileName);
  retptr = s_strdup(tmpFileName);
#else
  tmpFileName = tempnam("/tmp/", 0);
  retptr = tmpFileName;
  if (! retptr) {
    return(NULL);
  }
#endif


    strcpy(buffer, fileName);
    strcat(buffer, ".Z");
    if (probe_file(buffer)) {
      sprintf(buffer, "%s %s.Z > %s", UNCOMPRESSOR, fileName, retptr);
    } else {
      sprintf(buffer, "%s -cd %s.gz > %s", UNZIPPER, fileName, retptr);
    }
    system(buffer);
    return(retptr); 



/*   
    if( system(buffer) != 0 ) {
     	waislog(WLOG_HIGH, WLOG_ERROR, "Error excuting system command: %s %ld",buffer, err );
	unlink(retptr);
        s_free(retptr);
        return(NULL);
    }
    else {    
       return(retptr);
    }
*/

}
