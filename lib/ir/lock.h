/*                               -*- Mode: C -*- 
 * $Basename: lock.h $
 * $Revision: 1.3.1.3.1.2 $
 * Author          : Gordon Linoff
 * Created On      : Mon May  5 11:12:09 1997
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:12:59 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 * (C) Copyright 1989, Thinking Machines Corporation
 */

#ifndef _LOCK_H_INCLUDED
#define _LOCK_H_INCLUDED

#include "cdialect.h"

#define INVALID_LOCK          -1
#define LOCK_QUERY             0  /* processing a query */
#define LOCK_UPDATE            1  /* updating database files that
                                   * need exclu access , blocking
                                   * queries */
#define LOCK_DELETE_VERSION    2
#define LOCK_CHECK_POINT       3
#define LOCK_SERVER            4  /* entire server period */
#define LOCK_INDEX             5  /* entire indexing period */
#define NUM_LOCK_TYPES         6

extern long utlk_using_lock _AP((char *dbanme, long lock_type));
extern long utlk_unset_lock _AP((char *dbname, long lock_type));
extern long utlk_set_lock _AP((char *dbname, long lock_type));



#ifdef LOCK_STORAGE_MODULE

#define IN_LOCK_RANGE(l) ((l >= 0) && (l < NUM_LOCK_TYPES))

static char *lock_names[NUM_LOCK_TYPES] = {
    ".query.lock",
    ".update.lock",
    ".delete-version.lock",
    ".check-point.lock",
    ".server.lock",
    ".index.lock"
    };

 
#endif  

#endif /* #ifndef _LOCK_H_INCLUDED */
