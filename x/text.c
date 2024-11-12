/*                               -*- Mode: C -*- 
 * $Basename: text.c $
 * $Revision: 1.8.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/06/15  13:44:05
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:31:07 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#include "xwais.h"

TextList
NewText()
{
  TextList result;

  if(NULL != (result = (TextList) s_malloc(sizeof(_TextList)))) {
    if(NULL == (result->thisText = (Textbuff) s_malloc(sizeof(_Textbuff)))) {
      s_free(result);
      result = NULL;
    }
    else {
      result->thisText->shell = NULL;
      result->thisText->textwindow = NULL;
      result->thisText->status = NULL;
      result->thisText->docid = NULL;
      result->thisText->text = NULL;
      result->thisText->type = NULL;
      result->thisText->size = 0;
      result->nextText = allText;
      allText = result;
    }
  }
  return(result);
}

void
KillText(t)
Textbuff t;
{
  TextList a_tList, tmp;

  if(t != NULL) {
    if(t->shell != NULL) XtDestroyWidget(t->shell);
    if(t->text != NULL) s_free(t->text);
    if(t->type != NULL) s_free(t->type);
    for(a_tList = allText; a_tList != NULL; a_tList = a_tList->nextText)
      if(a_tList->thisText == t) {
	if(a_tList->nextText != NULL) {
	  a_tList->thisText = a_tList->nextText->thisText;
	  tmp = a_tList->nextText;
	  a_tList->nextText = a_tList->nextText->nextText;
	  s_free(tmp);
	}
	else {
	  a_tList->thisText = NULL;
	  if(a_tList == allText) {
	    s_free(a_tList);
	    allText = NULL;
	  }
	}
	break;
      }
    s_free(t);
  }
}

Textbuff
findText(w)
Widget w;
{
  TextList a_tList;
  static Widget shell = NULL;

  if (w != NULL) 
    if((shell = XtParent(w)) != NULL)
      shell = XtParent(shell);
  if (shell != NULL) {
    for(a_tList = allText; a_tList != NULL; a_tList = a_tList->nextText)
      if(a_tList->thisText->shell != NULL)
	  if (a_tList->thisText->shell == shell)
	    return a_tList->thisText;
  }
  return NULL;
}

Textbuff
findTextDoc(doc, type)
DocumentID doc;
char *type;
{
  TextList a_tList;

  if (doc != NULL) { 
    for(a_tList = allText; a_tList != NULL; a_tList = a_tList->nextText)
      if(a_tList->thisText != NULL &&
	 a_tList->thisText->docid == doc) {
	if(a_tList->thisText->type != NULL &&
	   type != NULL  &&
	   !strcmp(a_tList->thisText->type, type))
	  return (a_tList->thisText);
      }
  }
  return NULL;
}

