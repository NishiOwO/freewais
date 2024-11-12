/*                               -*- Mode: C -*- 
 * $Basename: freedir.c $
 * $Revision: 1.3.1.2 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:28:34 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */


/* free list malloc'd by scandir */
void
freedir(list)
  char **list;
{
    char **s = list;

    while (*s) { 
	free(*s++);
    }
    free((char *)list);
}
