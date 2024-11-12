/*                               -*- Mode: C -*- 
 * $Basename: sockets.c $
 * $Revision: 1.6.1.9.1.3 $
 * Author          : Harry Morris, morris@think.com
 * Created On      : 5.29.90
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:03:25 1997
 * Language        : C
 * Update Count    : 37
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: sockets.c 1.6.1.9.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define sockets_c

#include "sockets.h"

#ifdef NOTCPIP			/* we don't have TCPIP */

void 
open_server (port, socket, size)
     long            port;
     long           *socket;
     long            size;
{
}

void 
accept_client_connection (socket, file)
     long            socket;
     FILE          **file;
{
}

void 
close_client_connection (file)
     FILE           *file;
{
}

void 
close_server (socket)
     long            socket;
{
}

FILE           *
connect_to_server (host_name, port)
     char           *host_name;
     long            port;
{
  return (NULL);
}
void 
close_connection_to_server (file)
     FILE           *file;
{
}

#else /* there is TCPIP */

#include <errno.h>
#include "cdialect.h"
#include "panic.h"

#ifdef HAS_SYS_ERRLIST
#ifdef EXTERN_SYS_ERRLIST
#ifndef __NetBSD__
extern char *sys_errlist[];
#endif
#endif
extern int      errno;
#ifndef __NetBSD__
extern int      sys_nerr;
#endif
#endif

char            host_name[255], host_address[255];

/* XXX
   still need:
   non-blocking modes
   special send/recieve functions? (there are now some in ui.c)
   asynchronous calls?
 */

/* define the number of queued connections allowable on each port */
#define QUEUE_SIZE 3

/*---------------------------------------------------------------------------*/
/* Server functions                                                          */
/*---------------------------------------------------------------------------*/

static boolean clr_socket _AP ((struct sockaddr_in * address, long portnumber,
				long *sock));

static          boolean
clr_socket (address, portnumber, sock)
     struct sockaddr_in *address;
     long            portnumber;
     long           *sock;
{
  unsigned long  *S_addr = (unsigned long *) &(address->sin_addr);

  if (errno == EADDRINUSE) {
    /* Try connecting to it */
    if (connect (*sock, (struct sockaddr *) address, sizeof (struct sockaddr_in)) == 0) {
      close (*sock);
      waislog (WLOG_HIGH, WLOG_ERROR,
	       "Cannot bind port %ld: (Address already in use).",
	       portnumber);
      waislog (WLOG_HIGH, WLOG_ERROR,
	       "waisserver is already running on this system");
      panic ("Exiting");
    } else {
      /* Connection failed; probably socket in FIN_WAIT */
      int             one = 1;

      (void) close (*sock);
      if ((*sock = socket (AF_INET, SOCK_STREAM, 0)) < 0)
	panic ("Open socket failed in trying to clear the port.");
      /*printf("Error binding port %d: (address already in use).\n\
         Attempting to clear stale socket...", portnumber); */
      if (setsockopt (*sock, SOL_SOCKET, SO_REUSEADDR,
		 (char *) &one, sizeof (one)) < 0) {
	/*printf("Warning: Setsockopt SO_REUSEADDR failed."); */
      }
      address->sin_family = AF_INET;
      *S_addr = INADDR_ANY;

      address->sin_port = (unsigned short int) htons (portnumber);

      if (bind (*sock, (struct sockaddr *)address, sizeof (*address)) == 0) {
	/*printf("Successfully cleared stale EADDRINUSE error"); */
      }
    }
  }
  return (true);
}

void
open_server (port, fd, size)
     long            port;
     long           *fd;
     long            size;
{
  struct sockaddr_in address;
  unsigned long  *S_addr = (unsigned long *) &address.sin_addr;
  memset (&address, 0, sizeof (address));

  /* open the fd */
  if ((*fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
    panic ("can't get file descriptor for socket: %s", Strerror (errno));
  }
  address.sin_family = AF_INET;
  *S_addr = htonl (INADDR_ANY);
  address.sin_port = (unsigned short int) htons (port);
  if (bind (*fd, (struct sockaddr *) &address, sizeof (struct sockaddr)) < 0)
                    clr_socket (&address, port, fd);

  if (listen (*fd, QUEUE_SIZE) < 0)
    panic ("can't open server: %s", Strerror (errno));
}

/* This is a lower level function provided for use by the lisp version of
 * this library 
 * XXX should support non-blocking mode
 */

#ifdef I_ARPA_INET
#include <arpa/inet.h>
#endif

void
fd_accept_client_connection (socket, fd)
     long            socket;
     long           *fd;
{ /* accept an input connection, and open a file on it */
  struct sockaddr_in saddr;
  int                len;

  len = sizeof saddr;

  do {
    errno = 0;
    *fd = accept (socket, (struct sockaddr *)&saddr, &len);
  } while (*fd < 0 && errno == EINTR);

  if (saddr.sin_family == AF_INET) {
#ifdef HAS_GETHOSTENT
    struct hostent *gethostent();
    struct hostent *peer = NULL;

    host_name[0] = '\0';

    peer = gethostbyaddr ((char *) &saddr.sin_addr, 4, AF_INET);
    sprintf (host_address, "%s", inet_ntoa (saddr.sin_addr));
    if (peer != NULL) {
      sprintf (host_name, "%s", peer->h_name);

      waislog (WLOG_MEDIUM, WLOG_CONNECT,
	       "Accepted connection from: %s [%s]",
	       host_name[0] ? host_name : "?", host_address);
    } else {
      waislog (WLOG_MEDIUM, WLOG_CONNECT,
	       "Accepted connection from: [%s]", host_address);
    }
#else /* not HAS_GETHOSTENT */
    waislog (WLOG_MEDIUM, WLOG_CONNECT,
	       "Accepted connection from: [%s]", host_address);
#endif /* not HAS_GETHOSTENT */
  }
  if (*fd < 0)
    panic ("can't accept connection");
}

/* This is the prefered C function for accepting client requests */
void
accept_client_connection (socket, file)
     long            socket;
     FILE          **file;
{
  long            fd;			    /* file descriptor actually used */

  fd_accept_client_connection (socket, &fd);
  if ((*file = fdopen (fd, "r+")) == NULL)
    panic ("can't accept connection");
}

/* When a server wants to end the session with a client */
void
close_client_connection (file)
     FILE           *file;
{
  fclose (file);
}

/* when exiting the top level server process (not the forked
   server processes that come one per client).
   Maybe we need to do this once per client as well.
 */
void
close_server (socket)
     long            socket;
{
  close (socket);
}

/*---------------------------------------------------------------------------*/
/* Client functions                                                          */
/*---------------------------------------------------------------------------*/

/* This is a lower level function provided for use by the lisp version of
 * this library 
 * XXX should support non-blocking mode
 */

#define HOSTNAME_BUFFER_SIZE 120
#define MAX_RETRYS 10

boolean
fd_connect_to_server (hname, port, fd)
     char           *hname;
     long            port;
     long           *fd;
{
  char            hostnamebuf[80];
  long            rc, i;
#ifdef __linux__
  struct addrinfo hints;
  struct addrinfo* result;
  struct addrinfo* rp;
#else
  struct hostent *host;
#endif
  struct sockaddr_in name;
  /* Some systems define sin_addr as union, some dont. So lets assume we
     know what we are doing an copy a long. */
  unsigned int  *S_addr = (unsigned int *) &name.sin_addr;

  memset ((char *) &name, 0, sizeof (name));
  *S_addr = inet_addr (hname);

  if (*S_addr != -1) {
    name.sin_family = AF_INET;
    (void) strcpy (hostnamebuf, hname);
  } else {
#ifdef __linux__
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 1;
    if(getaddrinfo(NULL, hname, &hints, &result) != 0){
      return FALSE;
    }
    for(rp = result; rp != NULL; rp = rp->ai_next){
      *fd = socket (AF_INET, SOCK_STREAM, 0);
      ((struct sockaddr_in*)rp->ai_addr)->sin_port = htons(port);
      if(connect (*fd, rp->ai_addr, rp->ai_addrlen) != -1) break;
      close(*fd);
    }
    freeaddrinfo(result);
    return rp == NULL ? FALSE : TRUE;
#else
    host = gethostbyname (hname);

    if (NULL == host) {
      return FALSE;
    }
    name.sin_family = host->h_addrtype;
#ifdef h_addr
    bcopy (host->h_addr_list[0],
	   (caddr_t) & name.sin_addr, host->h_length);
#endif
    (void) strcpy (hostnamebuf, host->h_name);
#endif
  }
#ifndef __linux__
  hname = hostnamebuf;

  name.sin_port = (unsigned short int) htons (port);

  *fd = socket (AF_INET, SOCK_STREAM, 0);
  for (i = 0; i < MAX_RETRYS; i++) {
    rc = connect (*fd, (struct sockaddr *)&name, sizeof (name));
    if (rc == 0)
      return TRUE;
    else if (errno == EINTR) {
      sleep (1);
    } else {
      perror ("Connect to socket did not work (1)");
      return FALSE;
    }
  }
  return FALSE;
#endif
}

/* This is the prefered C function for initiating client requests */
FILE           *
connect_to_server (hname, port)
     char           *hname;
     long            port;
{
  FILE           *file;
  long            fd;

  if (fd_connect_to_server (hname, port, &fd) == FALSE) {
    perror ("Connect to socket did not work (2)");
    return NULL;
  }
  if ((file = fdopen (fd, "r+")) == NULL) {
    perror ("Connect to socket did not work (3)");
    return NULL;
  }
  return file;
}

void
close_connection_to_server (file)
     FILE           *file;
{
  fclose (file);
}

/*---------------------------------------------------------------------------*/

#endif /* there is TCPIP */

/* Francois and Jonathan Goldman - hostname fix */
char           *
mygethostname (hostname, len)
     char           *hostname;
     long            len;
{
  char            name[255];
  struct hostent *h;

  gethostname (name, 254);
  strcpy (hostname, name);

  h = gethostbyname (name);

  if ((h = gethostbyname (name)) != NULL) {
    if ((strlen (h->h_name) >= len) && (len > 0)) {
      strncpy (hostname, h->h_name, len - 1);
    } else {
      strcpy (hostname, h->h_name);
    }
  } else {
    if ((strlen (name) >= len) && (len > 0)) {
      strncpy (hostname, name, len - 1);
    } else {
      strcpy (hostname, name);
    }
  }

  return (hostname);
}
