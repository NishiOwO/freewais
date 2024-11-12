/*                               -*- Mode: C -*- 
 * $Basename: util.c $
 * $Revision: 1.6.1.4.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/08  09:12:33
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:10:51 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: util.c 1.6.1.4.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define _C_UTIL

#include "wais.h"
#include "globals.h"

int charlistlength(list)
char **list;
{
  int num;

  if(list) {
    for(num = 0; list[num] != NULL; num++);
    return num;
  }
  else 
    return 0;
}

int listlength(list)
List list;
{
  int num;
  List l;

  for(num = 0, l = list; l != NULL; num++, l = l->nextNode);

  return num;
}

#define BEFORE 1
#define DURING 2
#define QUOTE 5

/* ripped out of gmacs-ui.c */
int find_string_slot(source, key, value, value_size, delete_internal_quotes)
char *source, *key, *value;
long value_size;
Boolean delete_internal_quotes;
{
  char ch;
  short state = BEFORE;
  long position = 0;  /* position in value */
  char *pos =(char*)strstr(source, key); /* address into source */

  value[0] = '\0';		/* initialize to nothing */

  if(NULL == pos)
    return(1);

  for(pos = pos + strlen(key); pos < source + strlen(source); pos++){
    ch = *pos;
    if((state == BEFORE) && (ch == '\"'))
      state = DURING;
    else if ((state == DURING) && (ch == '\\')){
      state = QUOTE;	
      if(!delete_internal_quotes){
	value[position] = ch;
	position++;
	if(position >= value_size){
	  value[value_size - 1] = '\0';
	  return(-1);
	}
      }
    }
    else if ((state == DURING) && (ch == '"')){	
      value[position] = '\0';
      return(0);
    }
    else if ((state == QUOTE) || (state == DURING)){
      if(state ==  QUOTE)
	state = DURING;
      value[position] = ch;
      position++;
      if(position >= value_size){
	value[value_size - 1] = '\0';
	return(-1);
      }
    }
    /* otherwise we are still before the start of the value */
  }
  value[position] = '\0';
  return(-1); /* error because we are in the middle of the string */
}

void find_value(source, key, value, value_size)
char *source, *key, *value;
int value_size;
{
  char ch;
  long position = 0;  /* position in value */
  char *pos =(char*)strstr(source, key); /* address into source */

  value[0] = '\0';		/* initialize to nothing */

  if(NULL == pos)
    return;

  pos = pos + strlen(key);
  ch = *pos;
  /* skip leading quotes and spaces */
  while((ch == '\"') || (ch == ' ')) {
    pos++; ch = *pos;
  }
  for(position = 0; pos < source + strlen(source); pos++){
    if((ch = *pos) == ' ') {
      value[position] = '\0';
      return;
    }
    value[position] = ch;
    position++;
    if(position >= value_size){
      value[value_size - 1] = '\0';
      return;
    }
  }
  value[position] = '\0';
}
