/*                               -*- Mode: C -*- 
 * $Basename: alphasort.c $
 * $Revision: 1.7.1.3 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Tue May 13 13:14:52 1997
 * Language        : C
 * Update Count    : 2
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#include "config.h"

#ifndef HAS_ALPHASORT

/*
 *  ALPHASORT
 *  Trivial sorting predicate for scandir; puts entries in alphabetical order.
 */

#include "cdialect.h"
#ifndef MAXNAMLEN
#define MAXNAMLEN 1024
#endif

#ifndef lint
static char PRCSid[] = "$Id: alphasort.c 1.7.1.3 Tue, 13 May 1997 16:53:20 +0200 pfeifer $";
#endif

int
alphasort(d1, d2)
    Direntry_t **d1;
    Direntry_t **d2;
{
    return strcmp(d1[0]->d_name, d2[0]->d_name);
}

#else
static int make_ar_happy = 0;
#endif /* HAS_ALPHASORT */
