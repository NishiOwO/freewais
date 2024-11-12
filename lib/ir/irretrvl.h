/*                               -*- Mode: C -*- 
 * $Basename: irretrvl.h $
 * $Revision: 1.7.1.1 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:23:49 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef IRRETRVL_H
#define IRRETRVL_H

#include "cdialect.h"
#include "docid.h"
#include "wprot.h"

/* error codes for getDocumentText() */
#define GDT_NoError				0
#define GDT_UnsupportedChunkType		1
#define GDT_BadDocID			       	2
#define GDT_MissingDocID			3
#define GDT_BadRange				4
#define GDT_MissingDatabase			5
#define GDT_BadDatabase				6

WAISDocumentText* getData _AP((DocObj* doc, long* errorCode,
			       char* index_directory));

WAISDocumentText* getDocumentText _AP((DocObj* doc, long* errorCode,
				       char* index_directory));

boolean parseDocID _AP((DocObj* doc,char* filename,long* start_character,
			long* end_character,long* errorCode));

#endif /* ndef IRRETRVL_H */

