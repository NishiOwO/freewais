/*                               -*- Mode: C -*- 
 * $Basename: irverify.h $
 * $Revision: 1.7 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:17:40 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef irverify_H
#define irverify_H

#include "irfiles.h"

#ifndef docID
#define docID 		unsigned long
#define postingWeight 	unsigned char
#endif

typedef struct serialPostingFile
{ 
  FILE* stream;
  long length;
  long current_index_block;
} serialPostingFile;

typedef struct postingsForATerm
{ 
  char		word[MAX_WORD_LENGTH + 1];
  unsigned long entries;
  docID*	docs;
  postingWeight* weights;
} postingsForATerm;

serialPostingFile* initSerialPostingFile _AP((char* filename));
void disposeSerialPostingFile _AP((serialPostingFile* pf));
void  printPostingsForATerm _AP((postingsForATerm* pfat));
postingsForATerm* getPostingsAt _AP((serialPostingFile* spf,long position));
postingsForATerm* getPostingsForNextTerm _AP((serialPostingFile* spf));
void disposePostingsForATerm _AP((postingsForATerm* pfat));
void removePostings _AP((postingsForATerm* pfat,long start,long run));
void printIndex _AP((database* db));
void printIndexUsingDictionary _AP((database* db));

#endif /* ndef irverify_H */
