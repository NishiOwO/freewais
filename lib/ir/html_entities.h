/*                               -*- Mode: C -*- 
 * html_entities.h -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Ulrich Pfeifer
 * Created On      : Mon Jan 27 22:08:25 1997
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon Jan 27 22:09:53 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * 
 * $$
 * $Log: html_entities.h,v $
 * Revision 2.1  1997/02/08 10:59:31  pfeifer
 *  added cons files
 *
 */

#ifndef HTML_ENTITIES_H
#define HTML_ENTITIES_H
#include "cdialect.h"

void decode_entities _AP((char *line));

#endif
