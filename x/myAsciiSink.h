/*                               -*- Mode: C -*- 
 * $Basename: myAsciiSink.h $
 * $Revision: 1.5 $
 * Author          : XConsortium, borrowed by Jonny Goldman
 * Created On      : 90/12/01 13:01:31
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:45:41 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universitšt Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/*
 * $XConsortium: AsciiSink.h,v 1.7 90/12/01 13:01:31 rws Exp $
 */

/***********************************************************
Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Digital or MIT not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

/* (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT) */


#ifndef _myAsciiSink_h
#define _myAsciiSink_h

/***********************************************************************
 *
 * my AsciiSink Object, based on the Athena one.
 *
 ***********************************************************************/

#include <X11/Xaw/TextSink.h>

/* Resources:

 Name		     Class		RepType		Default Value
 ----		     -----		-------		-------------
 echo                Output             Boolean         True
 displayNonprinting  Output             Boolean         True

*/

#define XtCOutput "Output"

#define XtNdisplayNonprinting "displayNonprinting"
#define XtNecho "echo"

/* Class record constants */

extern WidgetClass myasciiSinkObjectClass;

typedef struct _myAsciiSinkClassRec *myAsciiSinkObjectClass;
typedef struct _myAsciiSinkRec      *myAsciiSinkObject;

/************************************************************
 *
 * Public Functions.
 *
 ************************************************************/

#endif /* _myAsciiSrc_h */
/* DON'T ADD STUFF AFTER THIS #endif */
