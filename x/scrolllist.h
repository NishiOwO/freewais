/*                               -*- Mode: C -*- 
 * $Basename: scrolllist.h $
 * $Revision: 1.6 $
 * Author          : jonathan@Think.COM
 * Created On      : Fri Feb  1 1991
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:33:05 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_SCROLLLIST
#define _H_SCROLLLIST

typedef struct scrollList {
  Widget ListWidget;
  char* name;
  XtCallbackProc callback;
} _ScrollList, *ScrollList;

#endif
