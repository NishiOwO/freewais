/*                               -*- Mode: C -*- 
 * $Basename: sockets.h $
 * $Revision: 1.5.1.1 $
 * Author          : Harry Morris, morris@think.com
 * Created On      : 5.29.90
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:02:15 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef sockets_h
#define sockets_h

#include "cdialect.h"
#include "cutil.h"

#ifndef THINK_C
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif /* THINK_C */

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */

extern char host_name[255], host_address[255];

void open_server _AP((long port,long* socket,long size));
void accept_client_connection _AP((long socket,FILE** file));
void close_client_connection _AP((FILE* file));
void close_server _AP((long socket));
FILE *connect_to_server _AP((char* hname,long port));
void close_connection_to_server _AP((FILE* file));
char *mygethostname _AP((char *hostname, long len));

#ifdef __cplusplus
	}
#endif /* def __cplusplus */

/*---------------------------------------------------------------------------*/

#endif




