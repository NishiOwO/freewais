/*                               -*- Mode: C -*- 
 * $Basename: tcommands.h $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:17:33
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:31:50 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_TCOMMANDS
#define _H_TCOMMANDS

int get_selected_question _AP((void));
void EditQuestion _AP((Widget w,XtPointer closure, XtPointer call_data));
void AddQuestion _AP((Widget w,XtPointer closure, XtPointer call_data));
void DeleteQuestion _AP((Widget w,XtPointer closure, XtPointer call_data));
void DeleteSource _AP((Widget w,XtPointer closure, XtPointer call_data));
#endif
