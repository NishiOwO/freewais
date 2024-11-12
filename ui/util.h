/*                               -*- Mode: C -*- 
 * $Basename: util.h $
 * $Revision: 1.4.1.4.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:32:44
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:10:09 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_UTIL
#define _H_UTIL

#include <cdialect.h>

int charlistlength _AP((char** list));
void listlength _AP((List list));
void find_value _AP((char* source, char* key, char* value, int value_size));
#endif
