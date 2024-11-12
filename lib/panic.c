/*                               -*- Mode: C -*- 
 * $Basename: panic.c $
 * $Revision: 1.6.1.4.1.3 $
 * Author          : Morris@think.com
 * Created On      : 92/02/12  13:38:05
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:11:57 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universit�t Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* panic is an error system interface.  On the Mac, it will pop
 * up a little window to explain the problem.
 * On a unix box, it will print out the error and call perror()
 */
 
#include "panic.h"
#include "futil.h"

#include <ctype.h> 

#ifndef EXIT_FAILURE  /* should be in stdlib */
#define EXIT_FAILURE (-1)
#endif /* ndef EXIT_FAILURE */

/*----------------------------------------------------------------------*/

static void exitAction _AP((long error));

static void
exitAction(error)
long error;
{
  long i;
#ifdef THINK_C
  Debugger();
#else
  for (i = 0; i < 100000; i++)
    ;
#endif
#if 0
    abort();
#else
  exit(-1);
#endif
}

/*----------------------------------------------------------------------*/

#define PANIC_HEADER "Fatal Error:  "
#define BELL "\007"

void
#ifdef ANSI_LIKE
  panic(char* format, ...)
#else
panic(va_alist)
va_dcl
#endif
  {
    va_list ap;			/* the variable arguments */
#ifndef ANSI_LIKE
  char *format;

  va_start(ap);
  format = va_arg(ap, char *);
#else
  va_start(ap, format);
#endif

#ifdef THINK_C			/* pop up a dialog box */

  char buffer[1000];		/* hope this is enough space! */
  long i;
  strncpy(buffer,PANIC_HEADER,1000);
  SysBeep(5);
  vsprintf(buffer + strlen(PANIC_HEADER),format,ap);
  for (i = 0L; buffer[i] != '\0'; i++)
    { if (buffer[i] == '\n' || buffer[i] == '\r')
	buffer[i] = ' ';
      }
  gError->PostAlertMessage(buffer);

#else
  
  vwaislog(1, -1, format, ap);
  va_end(ap);

#endif
 
  exitAction(0);
}
  

/*----------------------------------------------------------------------*/
