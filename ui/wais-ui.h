/*                               -*- Mode: C -*- 
 * $Basename: wais-ui.h $
 * $Revision: 1.4.1.4.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:33:37
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:08:28 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_WAIS_UI
#define _H_WAIS_UI

#include "ui.h"

#ifndef MAX_MESSAGE_LEN
#define MAX_MESSAGE_LEN BUFSZ
#endif

#define QUESTION_FILE_VERSION 1

#define CHARS_PER_PAGE 2000

/* function definitions */

void showDiags _AP((diagnosticRecord** d));
void printDiags _AP((diagnosticRecord** d));
void write_text_record_completely _AP((FILE* fp, 
				       WAISDocumentText *record,
				       Boolean quote_string_quotes));
DocList build_response_list _AP((SearchResponseAPDU* response,
				 SourceID source, char** seed_words_used));
void replacecontrolM _AP((char* buffer,long* length));
void SearchWais _AP((Question q));
char* GetWaisDocument _AP((Question q, DocumentID doc,
			   char* type, FILE* fp, long* written));
void RetrieveWaisDocument _AP((void (*start_output)(), void (*end_output)(),
			       Question q, DocumentID doc));

void dumptext _AP((FILE* fp, char* buffer, long size));
void test_connection _AP((Question q));
void close_source _AP((Source source));
DocumentID getNextorPrevDoc _AP((Question q, Source source,
				 DocumentID doc, Boolean nextp));

#endif
