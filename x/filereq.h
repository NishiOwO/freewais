/*                               -*- Mode: C -*- 
 * $Basename: filereq.h $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/25  18:52:01
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:47:45 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_FILEREQ
#define _H_FILEREQ

void SetFileName _AP((Widget w,XtPointer closure, XtPointer call_data));
void SetDir _AP((Widget w,XtPointer closure, XtPointer call_data));
void SetReqButtons _AP((boolean how));
ScrollList MakeSaveRequester _AP((Widget parent));

#endif
