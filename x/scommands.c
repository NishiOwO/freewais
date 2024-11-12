/*                               -*- Mode: C -*- 
 * $Basename: scommands.c $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:17:00
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:34:29 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: scommands.c 1.9.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define _C_SCOMMANDS
#define XWAIS
#include "xwais.h"

int last_source = NO_ITEM_SELECTED;

static Source edit_source = NULL;

int get_selected_source()
{
  return(get_selected_item(sourcewindow->ListWidget));
}

/* widget commands */

/* ARGSUSED */
void
EditSource(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  SList s;
  char msg[1000];
  int CurrentSource;

  double_click = FALSE;
  LastClicked = w;

  if ((CurrentSource = get_selected_source())
      != NO_ITEM_SELECTED) {
#ifdef MOTIF
    last_source = CurrentSource;
#endif
    if (last_source == CurrentSource) {
      if(edit_source == NULL) 
	edit_source = (Source)s_malloc(sizeof(_Source));

      if(!ReadSourceFile(edit_source, 
			 Source_items[CurrentSource],
			 app_resources.userSourceDirectory))
	ReadSourceFile(edit_source, 
		       Source_items[CurrentSource],
		       app_resources.commonSourceDirectory);

      sprintf(msg, "Opening source: %s\n", edit_source->name);
      XwaisPrintf(msg);
      PopupSource(edit_source);
    }
    else last_source = CurrentSource;
  } 
  else {
    last_source = -1;
    XwaisPrintf("No source selected.\nPlease selected one and try again.\n");
  }
}

/* ARGSUSED */
void
AddSource(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{

  double_click = FALSE;
  LastClicked = w;

  if(edit_source == NULL) 
    edit_source = (Source)s_malloc(sizeof(_Source));

  edit_source->name = s_strdup("new.src");
  edit_source->directory = s_strdup(app_resources.userSourceDirectory);
  strncpy(edit_source->server, "localhost", STRINGSIZE);
  strncpy(edit_source->service, "8000", STRINGSIZE);
  strncpy(edit_source->database, "database_name", STRINGSIZE);
  edit_source->maintainer = s_strdup("");
  edit_source->description = s_strdup("");
  XwaisPrintf("Opening new source\n");
  PopupSource(edit_source);
}

void PopupSource(s)
Source s;
{
  Arg arglist[10];
  Cardinal num_args;

  if (s != NULL) {
    num_args = 0;
    XtSetArg(arglist[num_args], XtNtitle, s->name); num_args++;
    XtSetValues(sourcepopup, arglist, num_args);
    ReplaceText(snamewid, s->name);
    ReplaceText(serverwid, s->server);
    ReplaceText(servicewid, s->service);
    ReplaceText(dbwid, s->database);
    ReplaceText(costwid, s->cost);
    ReplaceText(unitwid, s->units);
    ReplaceText(maintainerwid, s->maintainer);
    if(s->description == NULL) s->description = s_strdup("");
    ReplaceAsciiText(descwid, s->description);
    XtPopup(sourcepopup, XtGrabNone);
  }
}

/* ARGSUSED */
void CloseSourceEdit(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  char name[STRINGSIZE];

  double_click = FALSE;
  LastClicked = w;

  if (edit_source != NULL) {
    strcpy(name, GetString(snamewid));

    if(!((strlen(name) > 4) && 
	 strstr(name, ".src") &&
	 (!strcmp(".src", strstr(name, ".src")))))
      strcat(name, ".src");

    if(edit_source->name != NULL) s_free(edit_source->name);
    edit_source->name = s_strdup(name);

    if (edit_source->maintainer != NULL) s_free(edit_source->maintainer);
    edit_source->maintainer = s_strdup(GetString(maintainerwid));

    if (edit_source->description != NULL) s_free(edit_source->description);
    edit_source->description = s_strdup(GetAsciiString(descwid));

    strncpy(edit_source->server, GetString(serverwid), STRINGSIZE);
    strncpy(edit_source->service, GetString(servicewid), STRINGSIZE);
    strncpy(edit_source->database, GetString(dbwid), STRINGSIZE);
    strncpy(edit_source->cost, GetString(costwid), STRINGSIZE);
    strncpy(edit_source->units, GetString(unitwid), STRINGSIZE);

    WriteSource(app_resources.userSourceDirectory, edit_source, TRUE);

    /* ScanDirs(NULL, NULL);*/
  }
  else XwaisPrintf("No currently selected source.  This shouldn't happen.\n");
  XtPopdown(sourcepopup);
}

/* ARGSUSED */
void CancelSourceEdit(w, closure, call_data)
Widget w;
XtPointer closure, call_data;
{
  SList s;

  double_click = FALSE;
  LastClicked = w;

  XtPopdown(sourcepopup);
}
