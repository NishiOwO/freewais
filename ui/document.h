/*                               -*- Mode: C -*- 
 * $Basename: document.h $
 * $Revision: 1.4.1.4.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:37:32
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:21:37 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_DOCUMENT
#define _H_DOCUMENT

#include <docid.h>
#include "source.h"

typedef struct CRetDocument
 { 
   /* instance variables */
   DocID *id;
   SourceID sourceID;
   any*			myConnection;				/* really a ConnectionID but circular includes preclude that */
   long 			numLines;    				/* number of lines in document */
   long 			numChars;   				/* number of characters */
   char 		*blocks,*pendingBlocks; 	/* lists of CLineBlocks */
   long 			best;
   char		*source,*headline,*city,*stock,*company,*industry, **type, *date;
   struct CRetDocument 	*next,*prev; 				/* linked docs if there are any */
   char			*paraStarts;					/* i'th paragraph starts at line paraStarts[i] 
   												   -1 terminated 
   												 */
   
 } _CRetDocument, *CRetDocument;

typedef struct DocumentID {
  short rawScore, normalScore;
  long start, end;
  CRetDocument doc;
} _DocumentID, *DocumentID;

typedef struct doclist {
  DocumentID thisDoc;
  struct doclist *nextDoc;
} _DocList, *DocList;

/* functions */

void freeItemList _AP((char** list));
char **buildDocumentItemList _AP((DocList doclist, Boolean scorep));
DocList ReadListOfDocuments _AP((FILE* file));
short ReadFragment _AP((FILE* file, long* dest));
short ReadDoc _AP((FILE* file, CRetDocument doc));
short ReadDocument _AP((DocumentID doc, FILE* file));
CRetDocument MakeNewDocument _AP((void));
DocList makeDocList _AP((DocumentID doc, DocList rest));
DocumentID copy_docid _AP((DocumentID doc));
void WriteDocument _AP((DocumentID doc, FILE* fp));
void sort_document_list _AP((DocList dlist));
DocList findLast _AP((DocList dlist));
DocumentID findDoc _AP((DocList dlist, int number));
DocumentID fillDocumentID _AP((WAISDocumentHeader* docHeader,SourceID source));
void freeDocumentID _AP((DocumentID doc));
void freeDocList _AP((DocList doclist));

#endif
