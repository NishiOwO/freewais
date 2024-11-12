/*                               -*- Mode: C -*- 
 * $Basename: boolean_op.h $
 * $Revision: 1.3.1.1 $
 * Author          : Huynh Quoc T. Tung
 * Created On      : Sun Oct 17 16:40:58 1993
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 17:30:36 1997
 * Language        : C
 * Update Count    : 21
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * 
 */

#ifndef BOOLEAN_OP_H
#define BOOLEAN_OP_H

typedef struct doc_descr_struct {
  long doc_id;
  double score;
  long numwords;
  long *word_position;
} doc_descr_struct;

typedef struct search_result_struct {
  long operand_id;
  long number_of_hits;
  doc_descr_struct *doc_ids_array;
} search_result_struct;


boolean save_operand_id _AP((long operand_id, search_result_struct* search_result_array));
boolean IsOperator _AP((char* op));
long retriev_result _AP((search_result_struct *search_result, double* result));
boolean boolean_operations _AP((char* operator, search_result_struct* result_array));
#endif /* not BOOLEAN_OP_H */
