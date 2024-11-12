/*                               -*- Mode: C -*- 
 * $Basename: irsearch.h $
 * $Revision: 1.4.1.1.1.1 $
 * Author          : Brewster Kahle, brewster@think.com
 * Created On      : 3.26.90
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:21:58 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_search_
#define _H_search_

#include "cdialect.h"
#include "irfiles.h"
#include "cutil.h"
#include "futil.h"
#include "irhash.h"
#include "zprot.h"
#include "wprot.h"

/* the default database to use if none is specified */
#define	INFO_DATABASE_NAME	"INFO"
#define MAX_NORMAL_SCORE 1000


extern char *server_name;
extern long tcp_port;

typedef struct hit {
	double 	weight;
	long 	document_id;
	long	start_character;
	long 	end_character;
	char 	filename[MAX_FILE_NAME_LEN + 1];
	char 	headline[MAX_HEADLINE_LEN + 1];
	char 	type[MAX_TYPE_LEN + 1];
	char	date[ANSI_DATE_LENGTH + 1];
	long	number_of_lines;
	long 	document_length;
	long 	best_character;  /* this is the offset into the 
				    document of the character at	
				    the start of the best section */
	long 	best_line;  /* similar to best_character but for lines */
	database *db;
} hit;	

typedef struct search {
	database*		db;	
	double*			document_score_array;
#ifdef BOOLEANS
	double*		prior_score_array;	/* dgg, 12/91 GS TLG */
#endif
	unsigned long		num_best_hits;
	hit*			best_hits;
} search;

/* exported functions */
#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */

boolean run_search 
  _AP((SearchAPDU* aSearch,
       WAISDocumentHeader** headers,
       diagnosticRecord*** diags,char* index_directory, 
       char** seed_words_used,
       long waisProtocolVersion,long* headerNum));

#ifdef __cplusplus
	}
#endif /* def __cplusplus */

#endif
