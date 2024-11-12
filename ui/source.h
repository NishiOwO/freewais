/*                               -*- Mode: C -*- 
 * $Basename: source.h $
 * $Revision: 1.10.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/01  13:35:44
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:14:11 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_SOURCE
#define _H_SOURCE

#include <cdialect.h>

#ifndef EXTERN_SOURCE_ITEMS
#define EXTERN_SOURCE_ITEMS extern
#endif
EXTERN_SOURCE_ITEMS char **Source_items;
#undef EXTERN_SOURCE_ITEMS

#ifndef EXTERN_SOURCE_PATH
#define EXTERN_SOURCE_PATH extern
#endif
EXTERN_SOURCE_PATH char *sourcepath;
#undef EXTERN_SOURCE_PATH

typedef struct SourceID {
  char *filename;
} _SourceID, *SourceID;

typedef struct source{
  char *name;
  char *directory;
  char server[STRINGSIZE];
  char service[STRINGSIZE];
  char database[STRINGSIZE];
  char cost[STRINGSIZE];
  char units[STRINGSIZE];
  char *description;
  FILE *connection;
  long buffer_length;
  Boolean initp;
  char *maintainer;
} _Source, *Source;

typedef struct sourcelist {
  SourceID thisSource;
  struct sourcelist *nextSource;
} _SourceList, *SourceList;

typedef struct slist {
  Source thisSource;
  struct slist *nextSource;
} _SList, *SList;

/* functions */

void freeSourceID _AP((SourceID sid));
SourceID copysourceID _AP((SourceID sid));
char** buildSourceItemList _AP((SourceList sourcelist));
char** buildSItemList _AP((SList sourcelist));
short ReadSourceID _AP((FILE* file, SourceID sid));
SourceList ReadListOfSources _AP((FILE* fp));
Boolean ReadSource _AP((Source source, FILE* file));
Boolean ReadSourceFile _AP((Source asource, char* filename, char* directory));
Source loadSource _AP((char* name, char *path));
void set_connection _AP((Source source));
Boolean newSourcep _AP((char* name));
Boolean is_source _AP((char* name, Boolean test));
void SortSourceNames _AP((int n));
void GetSourceNames _AP((char* directory));
void ReadSourceDirectory _AP((char* directory, Boolean test));
void WriteSource _AP((char* directory, Source source, Boolean overwrite));
SourceList makeSourceList _AP((SourceID source, SourceList rest));
SList makeSList _AP((Source source, SList rest));
void FreeSource _AP((Source source));
void FreeSources _AP((SList sources));
Source findsource _AP((char* name, char *path));
Source findSource _AP((int n));
void format_source_cost _AP((char* str, Source source));
void freeSource _AP((SourceID sourceID));
void freeSourceList _AP((SourceList slist));
Boolean init_for_source _AP((Source source, char* request,
			     long length, char* response));
#endif
