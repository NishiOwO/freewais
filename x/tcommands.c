/*                               -*- Mode: C -*- 
 * $Basename: tcommands.c $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:17:18
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:32:28 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: tcommands.c 1.9.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define _C_TCOMMANDS
#define XWAIS
#include "xwais.h"

static Boolean editting_new_question;
static int last_question = NO_ITEM_SELECTED;
extern int last_source;

int get_selected_question()
{
  return(get_selected_item(questionwindow->ListWidget));
}

/* ARGSUSED */
void
EditQuestion(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  char msg[STRINGSIZE];
  int CurrentQuestion;

  double_click = FALSE;
  LastClicked = w;

  if((CurrentQuestion = get_selected_question())
     != NO_ITEM_SELECTED) {
#ifdef MOTIF
    last_question = CurrentQuestion;
#endif
    if (CurrentQuestion == last_question) {
      sprintf(msg, "Opening question: %s\n", Question_items[CurrentQuestion]);
      XwaisPrintf(msg);
      sprintf(msg, "xwaisq \"%s\" &", Question_items[CurrentQuestion]);
      system(msg);
    }
    else last_question = CurrentQuestion;
  }
  else {
    last_question = -1;
    if (NumQuestions > 0)
      XwaisPrintf("No question selected.\nPlease select one and try again.\n");
    else {
      XwaisPrintf("Opening new question\n");
      system("xwaisq &");
    }
  }
}

/* ARGSUSED */
void
AddQuestion(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  Question new;

  double_click = FALSE;
  LastClicked = w;

  XwaisPrintf("Opening new question\n");
  system("xwaisq &");
}

void
DeleteQuestion(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  char msg[STRINGSIZE];
  int CurrentQuestion;

  double_click = FALSE;
  LastClicked = w;

  if((CurrentQuestion = get_selected_question())
     != NO_ITEM_SELECTED) {
    sprintf(msg, "%s%s",
	    app_resources.questionDirectory,
	    Question_items[CurrentQuestion]);
    if(unlink(msg) != 0)
      XwaisPrintf("Error delete Question.\n");

    last_question = NO_ITEM_SELECTED;
    ScanDirs(NULL, NULL);
  }
  else
    XwaisPrintf("No question selected.\nPlease select one and try again.\n");
}

void
DeleteSource(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  char msg[STRINGSIZE];

  double_click = FALSE;
  LastClicked = w;

  if(get_selected_source() != NO_ITEM_SELECTED) {
    sprintf(msg, "%s%s",
	    app_resources.userSourceDirectory,
	    Source_items[get_selected_source()]);

    if (unlink(msg) != 0)
      XwaisPrintf("Error deleting source.\n");
    else {
      last_source = NO_ITEM_SELECTED;
      XawListUnhighlight(sourcewindow->ListWidget);
    }
  }
  else
    XwaisPrintf("No source selected.\nPlease select one and try again.\n");
}
