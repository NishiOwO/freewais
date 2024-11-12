/*                               -*- Mode: C -*- 
 * $Basename: stemmer.h $
 * $Revision: 1.3.1.1 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:00:18 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef STEMMER_H
#define STEMMER_H

#include "cdialect.h"
#include "cutil.h"


#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */


/* main stemmer routine */
char * stemmer _AP((char *word));


/* smart stemmer */
void smrt_stmr _AP((char *word));


/* plural stemmer */
void news_stmr _AP((char *word));


/* porter's stemmer */
void prtr_stmr _AP((char *word));


/* porter's alternative stemmer */
void alt_prtr_stmr _AP((char *word));


#ifdef __cplusplus
	}
#endif /* def __cplusplus */

#endif /* STEMMER_H */
