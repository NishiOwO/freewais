/*                               -*- Mode: C -*- 
 * any_stemmer.c -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Ulrich Pfeifer
 * Created On      : Fri May  3 08:57:03 1996
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Tue Sep 10 16:31:25 1996
 * Language        : C
 * Update Count    : 21
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1996, Universität Dortmund, all rights reserved.
 * 
 * $$
 * $Log: any_stemmer.c,v $
 * Revision 2.2  1997/02/04 17:12:09  pfeifer
 * Switched to CVS
 *
 * Revision 2.0.1.1  1996/12/27 16:06:46  pfeifer
 * patch69: Interface for different stemmers.
 *
 * Revision 1.1  1996/05/07 12:59:19  pfeifer
 * Initial revision
 *
 */

#include "any_stemmer.h"
#include "stemmer.h"
#include "grundform.h"
#include "../defaults.h"        /* need MAX_WORD_LENGTH */

char  index_stemming = '\0';

char * any_stemmer _AP((char tag, char *word));

char *any_stemmer(tag, word)
char tag;
char *word;
{
  /* query parsing will fail if we dropp a keyword. */
  char *result;
  char save_word[MAX_WORD_LENGTH+1];

  if (!strcmp(word,"and") ||
      (!strcmp(word,"not"))) 
    return(string_downcase(word));

  strncpy(save_word, word, MAX_WORD_LENGTH);
  switch (tag) {
  case ENGLISH_STEMMING_TAG:
    (void)string_downcase(word);
    result = stemmer (word);
    break;
  case GERMAN_GRUNDFORM_TAG:
    result = grundform (word);
    break;
  case GERMAN_STAMMFORM_TAG:
    result = stammform (word);
    break;
  default:
    return(string_downcase(word));
  }
  if (!result || !word[0]) {               /* sanity check */
    waislog (WLOG_LOW, WLOG_INDEX, "Word stemmer returned no stem for '%s'", save_word);
    strncpy(word, save_word, MAX_WORD_LENGTH);
  }
  return(string_downcase(word));
}
