/*                               -*- Mode: C -*- 
 * $Basename: status.h $
 * $Revision: 1.7.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/06/14  19:00:05
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:13:00 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_STATUS
#define _H_STATUS

#define STATUS_INFO 1
#define STATUS_CONT 2
#define STATUS_URGENT 3

#define STATUS_LOW 0
#define STATUS_MEDIUM 1
#define STATUS_HIGH 2

void PrintStatus _AP((long logtype, long loglevel, char* format, ...));

#endif /* _H_STATUS */
