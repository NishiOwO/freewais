/*                               -*- Mode: C -*- 
 * $Basename: field_index.h $
 * $Revision: 1.4.1.4 $
 * Author          : Huynh Quoc T. Tung
 * Created On      : Fri Feb 18 10:23:09 1994
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 17:29:24 1997
 * Language        : C
 * Update Count    : 68
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * 
 */

#include "irfiles.h"
#include "irtfiles.h"

#ifndef FIELD_INDEX_H
#define FIELD_INDEX_H

#define I_GLOBAL 0
#define I_LOCAL  1
#define I_BOTH   2

#define NUMBER_OF_INDEXTYPES 3 /* TEXT, SOUNDEX, PHONIX.  
                                  This is to change 
                                  if new indextype will be implemented */

typedef struct nidx_table {
  long            position;
  long           *begin_tag_pos;
  long           *end_tag_pos;
} nidx_table;

typedef struct layout_struct {
  long            begin_tag_pos;
  long            end_tag_pos;
  long            hline_begin_tag_pos;
  long            len;
  long            offset;
} layout_struct;
  

typedef struct ltable {
  long            field_record_end_pos;
  long            date_tag_pos;
  long            date_begin_tag_pos;
  DateDescription date_desc;
  long            number_of_headlines;
  layout_struct  *layout;
} ltable;

typedef struct index_fields_struct {
  char          **field_names;
  boolean        *numeric;
} index_fields_struct;

void save_nummeric_index_fields _AP((long field_id));
long save_index_fields _AP((char* field_name, long* number_of_elements, long *field_id));
char* match _AP((char* line, long* begin_pos, long* end_pos, long regexp_pos));
long compile_regexp _AP((long number_of_regexp, char** regexp_set));
boolean regexp_bolp _AP((int num));

long check_layout_for_line _AP((char* line));
boolean init_index_fields _AP((boolean* adding_to_existing_index,
                               boolean* create_new_fields,
                               boolean field_adding_to_existing_index,
                               long number_of_fields,
                               database* db));     
boolean open_field_streams_init _AP((boolean initialize,
                                     boolean field_adding_to_existing_index,
                                     long field_id,
                                     database* db));

long count_words _AP((char* line, long* line_length, 
                      boolean* newline_terminated));


long how_index_line _AP((long field_id, char* line, 
                         long* number_of_not_ended_section,
                         long document_id,
                         long weight,
                         long file_position_before_line,
                         long* line_length,
                         boolean* newline_terminated,
                         database* db,
                         wordfunc *wordfunction1,
                         wordfunc *wordfunction2,
                         boolean word_position, 
                         boolean word_pairs,
                         int minwordlen, 
                         char* type));

long index_line_section _AP((long field_id, long fpos,
                             char* line,
                             long document_id,
                             long weight,
                             long file_position_before_line,
                             long* line_length,
                             boolean* newline_terminated,
                             database* db,
                             wordfunc *wordfunction1,
                             wordfunc *wordfunction2,
                             boolean word_position, 
                             boolean word_pairs,
                             int minwordlen, 
                             char* type));	

void clear_fields _AP((database* db));

void clear_Ftable_pos _AP((void));

boolean open_global_Database _AP((boolean initialize, database* db));
long 
fields_getdate_internal  _AP((char            *s,
                              DateDescription *date_desc));

#endif
