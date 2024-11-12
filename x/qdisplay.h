/*                               -*- Mode: C -*- 
 * $Basename: qdisplay.h $
 * $Revision: 1.8.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:13:03
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:35:14 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_QDISPLAY
#define _H_QDISPLAY

void SetqIcon _AP((Widget parent));
void SettIcon _AP((Widget parent));
Widget MakeQuestionPane _AP((Widget parent,XQuestion question));
Widget MakeTextPopup _AP((Widget parent,Textbuff t,char *name));
QuestionWindow MakeQuestionForm _AP((XQuestion question));
Widget MakeSourcePopup _AP((Widget parent));
Widget MakePrefPopup _AP((Widget parent));
ScrollList MakeSourceFrame _AP((Widget parent));
ScrollList MakeTypeFrame _AP((Widget parent));
void MakeWaisCursors _AP((void));
#endif

