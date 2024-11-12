/*                               -*- Mode: C -*- 
 * $Basename: weight.h $
 * $Revision: 1.5.1.3 $
 * Author          : Huynh Quoc T. Tung
 * Created On      : Fri May 20 09:18:01 1994
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 17:31:46 1997
 * Language        : C
 * Update Count    : 23
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * 
 */

#ifndef WEIGHT_H
#define WEIGHT_H

#include "irfiles.h"

void assign_term_weight_for_doc _AP ((long *number_of_elements, database * db));

#ifdef LITERAL
void write_size_in_ptr _AP ((long size, unsigned char *ptr));
#endif /* LITERAL */

double read_weight_from_memory _AP((long new_weight_size, unsigned char *block));
double read_weight_from_stream _AP((long new_weight_size, FILE * stream));

#endif /* not WEIGHT_H */

