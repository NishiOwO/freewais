/*                               -*- Mode: C -*- 
 * $Basename: docid.h $
 * $Revision: 1.5.1.1 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:36:57 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universit�t Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */
 
#ifndef docid_h
#define docid_h

#include "cdialect.h"
#include "zprot.h"

#define COPY_WITHOUT_RESTRICTION        0
#define ALL_RIGHTS_RESERVED             1
#define DISTRIBUTION_RESTRICTIONS_APPLY 2

/*---------------------------------------------------------------------------*/

typedef struct DocID{
   any* originalServer;
   any* originalDatabase;
   any* originalLocalID;
   any* distributorServer;
   any* distributorDatabase;
   any* distributorLocalID;
   long copyrightDisposition;
} DocID;

#ifdef __cplusplus
/* declare these as C style functions */
extern "C"
	{
#endif /* def __cplusplus */

DocID* makeDocID _AP((void));

DocID* copyDocID _AP((DocID* doc));

void freeDocID _AP((DocID* doc));

any* GetServer _AP((DocID* doc));

DocID* docIDFromAny _AP((any* rawDocID));

any* anyFromDocID _AP((DocID* docID));

any* GetDatabase _AP((DocID* doc));

any* GetLocalID _AP((DocID* doc));

long GetCopyrightDisposition _AP((DocID* doc));

long ReadDocID _AP((DocID* doc, FILE* file));

long WriteDocID _AP((DocID* doc, FILE* file));

Boolean cmpDocIDs _AP((DocID* d1,DocID* d2));

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
	}
#endif /* def __cplusplus */

#endif /* ifndef docid_h */

