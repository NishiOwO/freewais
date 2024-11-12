/*                               -*- Mode: C -*- 
 * $Basename: question.h $
 * $Revision: 1.10.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/12  16:24:47
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:16:10 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_QUESTION
#define _H_QUESTION

#include <cdialect.h>

#ifndef MAX_MESSAGE_LEN
#define MAX_MESSAGE_LEN BUFSZ
#endif

typedef struct question{
  char *type;
  char name[STRINGSIZE];
  char keywords[5000];
  char* keywords_used;
  short version;
  short view;
  char* sourcepath;
  int numsources;
  SourceList Sources;
  int CurrentSource;
  int numdocs;
  DocList RelevantDocuments;
  int CurrentRelDoc;
  int numresdocs;
  int maxresdocs;
  DocList ResultDocuments;
  int CurrentResDoc;
  char request_message[MAX_MESSAGE_LEN]; /* arbitrary message limit */
  char response_message[MAX_MESSAGE_LEN]; /* arbitrary message limit */
  SearchResponseAPDU  *query_response;
  SearchResponseAPDU  *retrieval_response;
  WAISSearchResponse  *query_info;
  Boolean modified;
} _Question, *Question;

short readRect _AP((Question question, FILE* file));
short ReadQuestion _AP((Question question, FILE* file));
void WriteQuestionfp _AP((FILE* fp, Question question));
void WriteQuestion _AP((char* filename, Question question));

#endif
