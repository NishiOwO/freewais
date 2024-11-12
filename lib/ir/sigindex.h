/*                               -*- Mode: C -*- 
 * $Basename: sigindex.h $
 * $Revision: 1.5.1.1 $
 * Author          : Brewster@think.com
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:05:38 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* Include file for the irhash.c file.
   Implements the building functions in irext.h */

#ifndef SIGINDEX_H
#define SIGINDEX_H

#include "cdialect.h"

#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */


/* ============================
 * ===  Building Functions  ===
 * ============================*/

long sig_init_add_word _AP ((database *db, long parameter1, long parameter2));

long sig_add_word _AP((
		       char *word,
		       long char_pos,
		       long line_pos,
		       long weight,
		       long doc_id,
		       time_t date,
		       long pair_word));

long sig_finished_add_word _AP((database *db));


#ifdef __cplusplus
	}
#endif /* def __cplusplus */

/*
 * define constants to interface sig functions
 */

/* update types */
#define ONLINE_UPDATE   1
#define BATCH_UPDATE    2

/* operation mode */
#define ADD_UPDATE 1
#define MOD_UPDATE 2
#define DEL_UPDATE 3


#endif /* nded SIGINDEX_H */






