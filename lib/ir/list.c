/*                               -*- Mode: C -*- 
 * $Basename: list.c $
 * $Revision: 1.4.1.4.1.3 $
 * Author          : Brewster@think.com
 * Created On      : 92/02/12  13:33:36
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:17:12 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universitšt Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* List Utilities.
 *
 * -brewster
 */


#include "list.h"

/* a list is an end_of_list terminated array */

char empty_tmp = 'f';
void *end_of_list = (void*)&empty_tmp;  /* this is special */

void* car(list)
void **list;
{
  if(end_of_list == *list)
    return(end_of_list);
  else
    return(*list);
}

/* returns the nth element (0 is the first element).
  it returns NULL if it asks for an element off the end (?).
 */

void* nth(number, list)
long number;
void **list;
{
  if(number < length(list))
    return(list[number]);
  else
    return(NULL); 
}

void 
setf_nth(number, elem, list)
long number;
void* elem;
void**list;
/* set the nth element */
{
  if(number < length(list))
    list[number] = elem;
}

void* first(list)
void **list;
{
  return(car(list));
}

void* second(list)
void **list;
{
  return(car(cdr(list)));
}

void* last(list)
void **list;
{
  long len = length(list);
  if (len > 0)
    return(nth(len - 1,list));
  else
    return(NULL);
}

void** cdr(list)
void **list;{
  if(NULL == list)
    return((void**)end_of_list);
  else if(end_of_list == *list)
    return((void**)end_of_list);
  else
    return(list+1);
}

void** nth_cdr(list, n)
void **list;
long n;{
  void** l = list;
  long i;
  for (i = 0; i < n; i++)
    l = cdr(l);
  return(l);
}

void** rest(list)
void **list;
{
  return(cdr(list));
}

void* cadr(list)
void **list;
{
  if(NULL == list)
    return(NULL);
  else if(end_of_list == *list)
    return(NULL);
  else
    return(*(list+1));
}

/* length of a list.  returns -1 if error.*/
long length(list)
void** list;
{
  long count = 0;
  if(list == NULL)
    return(0);
  while(end_of_list != list[count])
    count++;
  return(count);
}

void mapcar(list, function)
void **list;
void (*function)();
{
  if(!null(list)){
    (*function)(car(list));
    mapcar(cdr(list), function);
  }
}

/* pushes the item on the end of the list. returns the list. */
void **collecting(list, item)
void **list;
void *item;
{
  long len = length(list);
  if(0 == len){
    list = (void**)malloc(2 * sizeof(void*));
    list[0] = item;
    list[1] = end_of_list;
    return(list);
  }
  else{
    list = (void **)realloc((char *)list, (len + 2) * sizeof(void*));
    list[len] = item;
    list[len + 1] = end_of_list;
  }
  return(list);
}


void setf_car(list, item)
void** list;
void* item;
{
  list[0] = item;
}

/* returns true if the list is NULL */
boolean null(list)
void **list;
{
  if(list == NULL)
    return(true);
  if(list[0] == end_of_list)
    return(true);
  return(false);
}

boolean free_list(list)
void **list;
{
  if(list != NULL)
    s_free(list);
  return(true);
}

void
sort_list(list, cmp)
void** list;
int (*cmp)();
{ 
  qsort(list,length(list),sizeof(void*),cmp);
}

void**
remove_item_from_list(list, pos)
void** list;
long pos;
{
  long count = pos;
  if (list == NULL || list[0] == end_of_list)
    return(NULL);
  while (end_of_list != list[count])
   { list[count] = list[count + 1];
     count++;
   }
  list = (void**)realloc((char*)list,count*sizeof(void*));
  return(list);
}
