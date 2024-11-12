/*                               -*- Mode: C -*- 
 * $Basename: stoplist.h $
 * $Revision: 1.6.1.2 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:58:35 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */


#ifndef STOPLIST_H
#define STOPLIST_H

#include "cdialect.h"
#include "cutil.h"

#ifdef AUTO_STOPWORDS /* tung, 2/95 */
#define STOP ".stop"
extern boolean use_both_stoplist;

void add_auto_stopword _AP((char* stopword));
void init_stop_list _AP((char* database_file));
#else
void init_stop_list _AP((void));
#endif
void stop_list_file _AP((char *filename));
void add_stop_word _AP((char *));
void add_stop_file _AP((char *));
char *next_stop_word _AP((void));

#endif /* ndef STOPLIST_H */
