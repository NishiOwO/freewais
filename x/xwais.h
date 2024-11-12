/*                               -*- Mode: C -*- 
 * $Basename: xwais.h $
 * $Revision: 1.6.1.4.1.3 $
 * Author          : Jonathan Goldman <jonathan@Think.COM>
 * Created On      : 92/03/17  14:21:20
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:23:40 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_XWAIS
#define _H_XWAIS


#include "xstuff.h"

#ifdef _IBMR2
#undef SYSV
#undef void
#endif
 
/* usefull definitions */

#define STRINGSIZE	256

#include "cdialect.h"
#include "wais.h"
#include "text.h"
#include "scrolllist.h"
#include "util.h"
#include "scommands.h"

#ifdef XWAIS
#include "display.h"
#include "tcommands.h"
#else
#include "xquestion.h"
#include "qdisplay.h"
#include "qcommands.h"
#include "filereq.h"
#endif

#ifdef MAIN
#define ext
#else
#define ext extern
#endif

#define NUM_CURSORS 7

ext Cursor wais_cursors[NUM_CURSORS];

ext char *command_name;

ext char *sdir, *cdir;

/*
ext char* wais_log_file_name;
ext FILE* waislogfile;
*/
#define NO_ITEM_SELECTED -1

#define NUMQLINES 3
#define NUMSLINES 3
#define NUMRLINES 6

/*	externals in xwais.c 	*/

ext struct _app_resources {
    char *questionDirectory;
    char *userSourceDirectory;
    char *commonSourceDirectory;
    char *documentDirectory;
    char *helpFile;
    char *removeSeekerCodes;
    char *rescanInterval;
    char *seedWords;
    char *initialSource;
    char *questionName;
    char *filters;
    int maximumResults;
    Boolean doSearch;
    Boolean defaultsInstalled;
    Boolean showKeys;
} app_resources;

ext XtAppContext app_context;

ext XtIntervalId rescantimerid;

ext Widget top, form; /* top level things for display */

ext Widget
  labelwindow,
  messwidget;

ext ScrollList
  questionwindow,
  sourcewindow,
  typewindow,
  savelist;

ext Widget questionpopup,
  qnamewid, keywordwid, sshell, typeshell,
  savereq, dirnamewidget, filenamewidget, maxdocwid;

ext Widget sourcepopup, prefpopup, maxdocwid, sourcepathwid,
  filterwid, snamewid, serverwid, servicewid, dbwid,
  costwid, unitwid, maintainerwid, descwid;

ext Widget searchButton, addSourceButton, delSourceButton,
  addDocButton, delDocButton, helpButton, abortButton, 
  saveAsButton, doneButton;

ext Widget savebutton, viewbutton, cancelbutton, quitbutton;

ext Widget sourcemenu, sourcebutton;

ext String questionname, config, db;

ext Display *CurDpy;

ext int NumQuestions;

ext Source the_Source;

#ifndef XWAIS
ext XQuestion the_Question;
#endif

ext String *Question_items;

ext SList Sources;
extern char **Source_items;
ext int NumSources;

ext char** Type_items;

ext TextList allText;

ext Widget LastClicked;
ext Boolean double_click;

ext void Feep();

extern void DoQuit();

#endif
