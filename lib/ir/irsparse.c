/*                               -*- Mode: C -*- 
 * $Basename: irsparse.c $
 * $Revision: 1.6.1.3 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:21:16 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */


#define s_malloc malloc
#include <stdio.h>
#include "irsparse.h"
#define NEW(type) (type*)(s_malloc(sizeof(type)))


sparse_array* make_sparse_array(size)
     int size;
{
  sparse_array* tmp;
  tmp = (sparse_array* )s_malloc(sizeof(sparse_array));
  tmp->table = (doclist**)s_malloc(sizeof(doclist*)*size);
  tmp->buckets = size;
  return tmp;
}

double* sparse_aref(array,index)
     sparse_array* array;
     long index;
{
  int hash;
  doclist** ptr;
  hash = index % array->buckets;
  ptr = &array->table[hash];
  while(*ptr != NULL) {

    if((*ptr)->item ==index) {
      return &(*ptr)->val;
    }

    if((*ptr)->item > index) {
      doclist* tmp;
      tmp = NEW(doclist);
      tmp->val = 0.0;
      tmp->item = index;
      tmp->next = *ptr;
      *ptr = tmp;
      return &tmp->item;
    }
    ptr = &(*ptr)->next;
  }
  *ptr = NEW(doclist);
  (*ptr)->item =index;
  (*ptr)->val = 0.0;
  (*ptr)->next = 0;
  return &(*ptr)->item;
}


main() {
  
  sparse_array *foo;
  int t;
  foo = make_sparse_array(1024);
  
  for(t=0;t<10000;t++) {
    long *x;
    
    x = sparse_aref(foo,t);
    *x = t;
  }

  printf("%ld is aref(2000)\n",*(sparse_aref(foo,2000)));
}
