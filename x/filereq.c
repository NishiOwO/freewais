/*                               -*- Mode: C -*- 
 * $Basename: filereq.c $
 * $Revision: 1.8.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/25  18:51:30
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:48:22 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: filereq.c 1.8.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define FILEREQ_C
#include "xwais.h"
#include <sys/stat.h>

#ifndef S_ISDIR
#define S_ISDIR(foo) ((foo & S_IFMT) == S_IFDIR)
#endif

static char **dirfiles = NULL;

static Boolean
isdir(name)
char* name;
{
  struct stat stats;

  if(stat(name, &stats) < 0) return FALSE;

  if(S_ISDIR(stats.st_mode)) return TRUE;
  else return FALSE;
}

static int last_file = NO_ITEM_SELECTED;

void
SetFileName(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  char dirname[MAX_FILENAME_LEN+1], filename[MAX_FILENAME_LEN+1];
#ifdef MOTIF
  XmListCallbackStruct *l = (XmListCallbackStruct*)call_data;
  long pos = l->item_position-1;
  char *item = dirfiles[pos];
#else
  XawListReturnStruct *l = (XawListReturnStruct*)call_data;
  char* item = l->string;
  long pos = l->list_index;
#endif

  if(!(strcmp(item, "."))) return;
  if(!(strcmp(item, ".."))) {
    char *slash;
    sprintf(dirname, "%s", GetString(dirnamewidget));
    if(dirname[strlen(dirname)-1] == '/')
      dirname[strlen(dirname)-1] = 0;
    slash = (char*)strrchr(dirname, '/');
    if (slash != NULL) *(slash+1) = 0;
    ReplaceText(dirnamewidget, dirname);
    last_file = NO_ITEM_SELECTED;
    SetDir(NULL, NULL, NULL);
    ReplaceText(filenamewidget, "");
    return;
  }
  
  sprintf(dirname, "%s", GetString(dirnamewidget));
  if(dirname[strlen(dirname)-1] != '/')
    strcat(dirname, "/");

  sprintf(filename, "%s%s", dirname, item);

  if(isdir(filename)) {
    strcat(filename, "/");
    ReplaceText(dirnamewidget, filename);
    last_file = NO_ITEM_SELECTED;
    SetDir(NULL, NULL, NULL);
    ReplaceText(filenamewidget, "");
  }
  else {
    if(last_file == pos) {
      last_file = NO_ITEM_SELECTED;
      DoSave(w, closure, call_data);
    }
    else {
      last_file = pos;
      ReplaceText(filenamewidget, item);
    }
  }
}

void SetDir(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  char dirname[MAX_FILENAME_LEN+2];

  last_file = NO_ITEM_SELECTED;

  if(dirfiles != NULL) {
    int i;
    for(i =0; dirfiles[i] != NULL; i++) s_free(dirfiles[i]);
    free(dirfiles);
  }

  strncpy(dirname, GetString(dirnamewidget), MAX_FILENAME_LEN);
  if((dirfiles = GetDirNames(dirname)) == NULL) {
    pathname_directory(dirname, dirname);
    dirfiles = GetDirNames(dirname);
  }

  if(dirname[strlen(dirname)-1] != '/')
    strcat(dirname, "/");
  ReplaceText(dirnamewidget, dirname);

  RebuildListWidget(savelist, dirfiles, LIST_TOP);
}

static void
cancelFile(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  Arg args[1];
  XtPopdown(savereq);
  XtSetArg(args[0], XtNsensitive, False);
  XtSetValues(quitbutton, args, ONE);
}

void SetReqButtons(how)
boolean how;
{
  Arg args[1];
#ifdef MOTIF
  XmString str = XmStringCreateSimple(how? "Save&Quit": "   Save  ");
#else
  char* str = (how? "Save&Quit": "   Save  ");
#endif
  
  XtSetArg(args[0], NLABEL, str);
  XtSetValues(savebutton, args, ONE);
  XtSetArg(args[0], XtNsensitive, how);
  XtSetValues(quitbutton, args, ONE);
}

ScrollList
MakeSaveRequester(parent)
Widget parent;
{
  Widget frame, labelwid, button, view;
  ScrollList result;
  Arg arglist[10];
  Arg args[1];
  Cardinal num_args;

  num_args = 0;
  XtSetArg(arglist[num_args], XtNtitle, "Save As"); num_args++;
  XtSetArg(arglist[num_args], XtNiconName, "Save As"); num_args++;
  savereq = XtCreatePopupShell("savereqpopup", applicationShellWidgetClass, 
			      parent, arglist, num_args);
  frame = XtCreateManagedWidget("savereq", formWidgetClass, savereq, NULL, ZERO);

  labelwid = MakeLabel(frame, "dirlabel", "Directory", NULL, NULL);
  dirnamewidget = MakeStringBox(frame, "dirbox", "", NULL, NULL);

  num_args = 0;
  XtSetArg (arglist[num_args], XtNallowVert, True); num_args++;

  view = XtCreateManagedWidget ("fileview", viewportWidgetClass,
				frame, arglist, num_args);

  result = 
    MakeScrollList(view, "fileWindow", NULL, SetFileName, NULL, NULL);

  labelwid = MakeLabel(frame, "filelabel", "File Name", NULL, NULL);
  filenamewidget = MakeStringBox(frame, "filebox", "", NULL, NULL);

  savebutton = MakeCommandButton(frame, "fileset", setFile,
				 NULL, NULL, NULL);
  cancelbutton = MakeCommandButton(frame, "filecancel", cancelFile,
				   NULL, NULL, NULL);
  quitbutton = MakeCommandButton(frame, "filequit", quitFile,
				   NULL, NULL, NULL);

  SetReqButtons(false);
  return result;
}
