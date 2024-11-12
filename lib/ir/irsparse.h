/*                               -*- Mode: C -*- 
 * $Basename: irsparse.h $
 * $Revision: 1.4 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:20:36 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef SES_LIST_H
#define SES_LIST_H
typedef struct doclist {
  long item;
  struct doclist* next;
} doclist;

#endif
