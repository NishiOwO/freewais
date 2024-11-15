/*                               -*- Mode: C -*- 
 * $Basename: sighash.h $
 * $Revision: 1.7 $
 * Author          : Brewster@think.com
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:06:10 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universitšt Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* Include file for the irhash.c file.
   Implements the building functions in irext.h */

#ifndef SIGHASH_H
#define SIGHASH_H

#include "cdialect.h"
#include "cutil.h"

#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */

long hash_word _AP((char *wd,long below_n));
word_memory_hashtable *
  init_word_memory_hashtable _AP((long size, long flush_after_n_words,
				  word_memory_hashtable* the_word_memory_hashtable));
void sort_word_memory_hashtable _AP((word_memory_hashtable *the_word_memory_hashtable));
void collapse_word_memory_hashtable _AP((word_memory_hashtable *the_word_memory_hashtable));
void clear_word_memory_hashtable _AP((word_memory_hashtable *the_word_memory_hashtable));
void print_word_memory_hashtable _AP((word_memory_hashtable* the_word_memory_hashtable));

void add_stop_words _AP((word_memory_hashtable *the_word_memory_hashtable));

#ifdef __cplusplus
	}
#endif /* def __cplusplus */

#endif /* nded SIGHASH_H */






