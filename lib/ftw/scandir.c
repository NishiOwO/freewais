/*                               -*- Mode: C -*- 
 * $Basename: scandir.c $
 * $Revision: 1.3.1.5.1.3 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Tue May 13 13:15:16 1997
 * Language        : C
 * Update Count    : 2
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#include "config.h"
#ifndef HAS_SCANDIR

/*
 *  SCANDIR
 *  Scan a directory, collecting all (selected) items into a an array.
 */

#include "cdialect.h"
#include <stdio.h>

#ifndef lint
static char PRCSid[] = "$Id: scandir.c 1.3.1.5.1.3 Tue, 13 May 1997 16:53:20 +0200 pfeifer $";
#endif

/* Initial guess at directory size. */
#define INITIAL_SIZE	20

int
scandir(name, list, selector, sorter)
    char		  *name;
    Direntry_t		***list;
    int			 (*selector)();
    int			 (*sorter)();
{
    register Direntry_t	  **names;
    register Direntry_t	  *entp;
    register DIR	  *dirp;
    register int	   i;
    register int	   size;

    /* Get initial list space and open directory. */
    size = INITIAL_SIZE;
    names = (Direntry_t **)malloc(size * sizeof names[0]);
    if (names == NULL)
	return -1;
    dirp = opendir(name);
    if (dirp == NULL)
	return -1;

    /* Read entries in the directory. */
    for (i = 0; entp = readdir(dirp); )
	if (selector == NULL || (*selector)(entp)) {
	    /* User wants them all, or he wants this one. */
	    if (++i >= size) {
		size <<= 1;
		names = (Direntry_t **)
		    realloc((char *)names, size * sizeof names[0]);
		if (names == NULL) {
		    closedir(dirp);
		    return -1;
		}
	    }

	    /* Copy the entry. */
	    names[i - 1] = (Direntry_t *)malloc(sizeof(Direntry_t) 
					        + NLENGTH(entp)+1);
	    if (names[i - 1] == NULL) {
		closedir(dirp);
		return -1;
	    }
	    names[i - 1]->d_ino = entp->d_ino;
	    names[i - 1]->d_reclen = entp->d_reclen;
#ifdef DIRNAMLEN
	    names[i - 1]->d_namlen = entp->d_namlen;
#endif
	    (void)strcpy(names[i - 1]->d_name, entp->d_name);
	}

    /* Close things off. */
    names[i] = NULL;
    *list = names;
    closedir(dirp);

    /* Sort? */
    if (i && sorter)
	qsort((char *)names, i, sizeof names[0], sorter);

    return i;
}
#else
static int make_ar_happy = 0;
#endif /* HAS_SCANDIR */
