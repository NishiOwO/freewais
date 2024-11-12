/*                               -*- Mode: C -*- 
 * $Basename: list.h $
 * $Revision: 1.5 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:47:05 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_LIST
#define _H_LIST

typedef struct list {
  char *thisNode;
  struct list *nextNode;
} _List, *List;

#endif
