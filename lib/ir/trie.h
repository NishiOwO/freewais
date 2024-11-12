/*                               -*- Mode: C -*- 
 * $Basename: trie.h $
 * $Revision: 1.3.1.1.1.1 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:52:38 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */


#ifndef TRIE_H
#define TRIE_H
#include "cdialect.h"
/*
  Trie implementation of dictionary
  */

#define ALPHA_SIZE 37
#define CHUNK_SIZE 4096 /* allocate CHUNK_SIZE units at a time */
#define MAX_BLOCKS 4096 /* maximum number of blocks to hold (maybe realloc)*/


typedef struct _dict_data {
  int next_block;
  int num_occur;
} dict_data;

typedef struct _trie {
  char *string;
  void *datum;
  struct _trie **table;
} trie;

typedef struct _allocator {
  char* tofree[MAX_BLOCKS];
  int blocks_allocated;
  char* next_location;
  int items_left;
  int size;
  void (*dispose)();
} allocator;

typedef struct _trie_allocator {
  allocator* tries;
  allocator* trie_tables;
} trie_allocator;

char* fast_alloc _AP((allocator* x));
void  fast_free _AP((allocator* x));
allocator* make_allocator _AP((int item_size,void (*dispose)(char *item)));
trie_allocator* make_trie_allocator();

typedef trie *trie_table[ALPHA_SIZE];

void **trie_lookup _AP((char* key, trie* dict,trie_allocator* addp));
trie *new_trie _AP((char* word,trie_allocator* alloc));
int encode _AP((unsigned char* word));

extern trie* load_dict _AP((FILE* stream,trie_allocator *alloc));

#endif
