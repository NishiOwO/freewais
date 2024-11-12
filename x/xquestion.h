/*                               -*- Mode: C -*- 
 * $Basename: xquestion.h $
 * $Revision: 1.7.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:19:56
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:27:11 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_XQUESTION
#define _H_XQUESTION

#include "question.h"

typedef struct QuestionWindow {
  Widget shell;
  Widget keywordwid;
  ScrollList Sources;
  ScrollList RelevantDocuments;
  ScrollList ResultDocuments;
  Widget StatusWindow;
  Widget Textwindow;
  char *textbuffer;
} _QuestionWindow, *QuestionWindow;

typedef struct xquestion{
  Question q;
  char **Source_Items;
  char **Relevant_Items;
  char **Result_Items;
  QuestionWindow window;
} _XQuestion, *XQuestion;

/* function definitions */

XQuestion findQuestionWindow();
QuestionWindow MakeQuestionWindow();
void DeleteQuestionWindow();
char **buildQuestionItemList();
DocList build_response_list();
void SearchWais();
boolean init_for_source();
DocumentID getNextorPrevDoc();

#endif
