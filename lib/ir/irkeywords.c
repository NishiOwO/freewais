/*                               -*- Mode: C -*- 
 * $Basename: irkeywords.c $
 * $Revision: 1.2.1.4.1.2 $
 * Created On      : 7/29/92
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:26:18 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* This program is an attempt to scan into the dictionary and inverted
 * file to determine the keywords that best describe a database.
 * These could then be included in the description file 
 */

#include <sys/types.h>
#include <sys/param.h>
#include "cutil.h"
#include "futil.h"
#include "irfiles.h"
#include "irtfiles.h"
#include "panic.h"
#include "ircfiles.h"
#include "irext.h"

unsigned char *dictionary_header = NULL; /* the dictionary header. 
						  loaded once */

long number_of_blocks = 0;  /* also the length of the dictionary 
					  header block */

unsigned char *dictionary = NULL; /* this is one of the dict blocks */

  char *keywrd[100];
  long keyvalue[100];
  long stored;
  short nKeys = 0;

void free_keywords()
{
  int i;
  for (i=0;i<100;i++) {
    if (keywrd[i]) s_free(keywrd[i]);
  }
}

retreive_keywords(db)
  database* db;
{
  long i,j, k, l, tmp, limit;
  char file[MAX_FILE_NAME_LEN + 1 ];
  double x,y;
  char *ptr;
  int tmpval;

  bzero(keywrd, sizeof(char*)*100);
  
  if(NULL == dictionary_header) {
    FILE *stream = db->dictionary_stream;
    s_fclose(stream);
    db->dictionary_stream = s_fopen(dictionary_filename(file, db), "r+b");
    stream = db->dictionary_stream;
    s_fseek(stream, 0L, SEEK_SET);
    number_of_blocks = read_bytes(DICTIONARY_HEADER_SIZE,stream);
    dictionary_header=
      read_dictionary_block(dictionary_header,DICTIONARY_HEADER_SIZE,
			    number_of_blocks,stream);
    if(NULL == dictionary_header) {
      printf("Could not read dictionary header block in db %s.", db->database_file);
      return(0);
    }
  }
  look_up_total_word_count(db);
  stored = 0;
  for (i=0; i<=number_of_blocks; i++) {
    FILE *stream = db->dictionary_stream;
    dictionary = 
      read_dictionary_block(dictionary,
                            dictionary_block_position(i, dictionary_header),
                            DICTIONARY_BLOCK_SIZE, stream);
    /* 
     * This reads one word too much (up)
     * for (j=0; j<=DICTIONARY_BLOCK_SIZE; j++)
     */
    for (j=0; j<DICTIONARY_BLOCK_SIZE; j++)
      /* 
       *  if (strlen(dictionary_block_word(j, dictionary))) {
       *  
       *  The following should be equivalent:
       */
      if (*(dictionary_block_word(j, dictionary))) {
        tmp = dictionary_block_word_occurances(j, dictionary);
        if (tmp == db->total_word_count)
          goto done;

        /* Search for the position where to insert */
        k=0;
        while (k<stored) {      /* stored is the first *free* entry */
          if (tmp > keyvalue[k]) /* we must insert between k-1 and k */
            break;
          k++;
        }

        /* Now k points to the position at which the
         * keyword should be inserted.
         * Entries at k and above must be shifted
         */

        if (k == stored) {      /* insert at the end */
          if (stored < 50) {    /* if less than 50 are in the array */
            keyvalue[stored]= tmp;
            tmpval=strlen(dictionary_block_word(j, dictionary))+1;
            keywrd[stored] = s_malloc(tmpval);
            strcpy(keywrd[stored], dictionary_block_word(j, dictionary));
            stored++;
          }
        } else {                /* insert in the middle */
          if (stored >= 50) {   /* remove the last key */
            stored--;
            s_free(keywrd[stored]);
            keyvalue[stored] = 0;
          }
          /* shift elements from k to stored-1 one to the right */
          for (l=stored; l>k; l--) { 
            keywrd[l]  = keywrd[l-1];
            keyvalue[l] = keyvalue[l-1];
          }
          stored++;
          tmpval=strlen(dictionary_block_word(j, dictionary))+1;
          keywrd[k] = s_malloc(tmpval);
          strcpy(keywrd[k], dictionary_block_word(j, dictionary));
          keyvalue[k] = tmp;
        }
      }
  }
 done:
  /* done getting, now cull and sort */
  x = 0;
  for (i=0; i<50 && x<0.2; i++)
    x += ((double) keyvalue[i])/db->total_word_count;
  limit = i;
  /* patch from tovio@sage.ucs.uwa.edu.au to fix problem with empty
   *	keywords array
   */
  if (i>0)
    for (i=0; i<=limit-1; i++) {
      for (j=i; j<limit; j++)
        if (strcmp(keywrd[i],keywrd[j])>0) {
          ptr=keywrd[i]; keywrd[i]=keywrd[j]; keywrd[j]=ptr;
        }
    }
  nKeys = limit;
}
