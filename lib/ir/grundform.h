/*                               -*- Mode: C -*- 
 * grundform.h -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Ulrich Pfeifer
 * Created On      : Fri May  3 09:07:05 1996
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Tue May  7 13:42:01 1996
 * Language        : C
 * Update Count    : 5
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1996, Universität Dortmund, all rights reserved.
 * 
 * $$
 * $Log: grundform.h,v $
 * Revision 2.2  1997/02/04 17:12:30  pfeifer
 * Switched to CVS
 *
 * Revision 2.0.1.1  1996/12/27 16:15:12  pfeifer
 * patch69: New module which implements German grundform reduction via
 * patch69: embeded perl.
 *
 */

#ifndef GRUNDFORM_H
#define GRUNDFORM_H
#include "cdialect.h"
extern char* grundform _AP((char *word));
extern char* stammform _AP((char *word));
extern int my_perl_inited;
#endif 
