/*                               -*- Mode: C -*- 
 * $Basename: sigsrch.c $
 * $Revision: 1.5.1.6.1.3 $
 * Author          : jonathan@think.com
 * Created On      : 92/02/12  13:47:27
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:04:59 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: sigsrch.c 1.5.1.6.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#include "cdialect.h"
#include "irfiles.h"
#include "irsearch.h"
#include "irext.h"
#include "sigsrch.h"


/* ==================================
 * ===  Initialization Functions  ===
 * ==================================*/

/* set by init_search_engine when cm_mem_percent is non-zero */
long cm_mem_percent_saved = 0; 
long text_size_saved = 0; 
long grow_percent_saved = 0; 

long init_search_engine(file, initialize, for_search, cm_mem_percent,
text_size, grow_percent)
  char* file;
  boolean initialize;
  boolean for_search;
  long cm_mem_percent;
  long text_size;
  long grow_percent;
{
  long for_update;
  char full_filename[MAX_FILE_NAME_LEN+1];
  char *getenv(), *temps;

  waislog(WLOG_MEDIUM, WLOG_INFO, "Starting Seeker-RAM Engine.");

  if(cm_mem_percent != 0)
    cm_mem_percent_saved = cm_mem_percent;
  if(grow_percent != 0)
    grow_percent_saved = grow_percent;
  if(text_size != 0)
    text_size_saved = text_size;

  temps = getenv("SEEKER_TEXT_SIZE");
  if ( temps )
     text_size_saved = atol( temps);

  if( for_search )
    for_update = 0;
  else
    for_update = 1;

  temps = getenv("SEEKER_NOSECURE_SERVER");
  if ( temps )
     for_update = 1;
  strncpy(full_filename, file, MAX_FILE_NAME_LEN);
  strncat(full_filename, "/", MAX_FILE_NAME_LEN);
  strncat(full_filename, database_file(file), MAX_FILE_NAME_LEN);

  return( sig_init( full_filename, (long)initialize, (long)for_search, 
                    for_update, cm_mem_percent_saved) );
}

long finished_search_engine()
{
  waislog(WLOG_MEDIUM, WLOG_INFO, "Shutting down Seeker-RAM Engine.");
  return( sig_exit());
}


/*
 *  ext_open_database: see irext.h
 */

long ext_open_database (db, initialize, for_search)
     database *db;
     boolean initialize;
     boolean for_search;
{
  long for_update;

  if( for_search )
    for_update = 0;
  else
    for_update = 1;
  return( sig_open_database( db, (long)initialize, (long)for_search, 
                             for_update, cm_mem_percent_saved, 
                             text_size_saved, grow_percent_saved));
}
  


/*
 *  ext_close_database: see irext.h
 */

long ext_close_database (db)
     database *db;
{
  return( sig_close_database(db));
}


char *database_file(database_name)
     char *database_name;
{
  return("INDEX");
}

/*===========================*
 *===  Setting Paramters  ===*
 *===========================*/

long max_hit_retrieved = 0;
char **srcs = NULL;

long set_query_parameter (mask, parameters)
     long mask;
     query_parameter_type * parameters;
{
  switch (mask)
    {
    case SET_MAX_RETRIEVED_MASK:
      max_hit_retrieved = parameters->max_hit_retrieved;
      return(0);
      break;
    case SET_SELECT_SOURCE:
      if(NULL != srcs){
	if(NULL != srcs[0])
	  s_free(srcs[0]);
	s_free(srcs);
      }
      srcs = parameters->srcs;
      {long count = 0;
       if(NULL == srcs)
	 waislog(WLOG_LOW, WLOG_INFO, "No sources specified in set_query_parameter");
       else {
	 for(count = 0; srcs[count] != NULL; count++){
	   waislog(WLOG_LOW, WLOG_INFO,
		   "Setting source to '%s'", srcs[count]);
           }

         sig_set_query_parameter( mask, parameters);
	 }
     }
      break;
    default:
      return(-1);
      break;
    }	
  return(0);
}

/*=============================*	
 *===  Searching for words  ===*
 *=============================*/

/* see irext.h for doc */
long init_search_word (db)
     database* db;
{
  return(sig_init_search_word(db));
}

long search_word(word, char_pos, line_pos, weight, doc_id, 
		 word_pair, db)
     char *word; /* the word to be searched for */
     long char_pos;		/* the position of the start of the word */
     long line_pos;		/* is this needed? not for signature system */
     long weight;		/* how important the word looks syntactically,
				   such as is it bold */
     long doc_id;		/* current document, seed words is 0,
				   then it increments into the relevant 
				   document */
     long word_pair;
     database *db;
{
  long number_of_occurances;
  long word_id = 
    look_up_word_in_dictionary(word, &number_of_occurances, db);

  return( sig_search_word(word, char_pos, line_pos,
			  weight, doc_id, number_of_occurances, 
                          ABSOLUTE(word_id), word_pair));
}

/*===================*
 *===  Best Hits  ===*
 *===================*/


long finished_search_word(db)
     database *db;
{ 
  return(sig_finished_search_word(db));
}

/* see irext.h for doc */
long init_best_hit (db)
     database *db;
{
  return(0);
}

/* returns the next best hit */
long best_hit(db, doc_id, best_character, best_line, score)
     database *db;
     long *doc_id;	
     long *best_character;
     long *best_line;
     long *score;
{
  return(sig_best_hit(doc_id, best_character, best_line, score));
}

long finished_best_hit(db)
     database *db;
{ 
  return(sig_finished_best_hit());
}

