/*                               -*- Mode: C -*- 
 * $Basename: display.c $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:16:13
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:49:47 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: display.c 1.9.1.3 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#define XWAIS
#include "xwais.h"

static ScrollList
MakeQuestionFrame(parent)
Widget parent;
{
  Widget frame, labelwid, button;
  Widget view;
  ScrollList result;
  Arg arglist[TWO];
  Cardinal num_args;

  frame = XtCreateManagedWidget("questions", formWidgetClass, parent, NULL, ZERO);

  labelwid = MakeLabel(frame, "questionlabel", "Questions:", NULL, NULL);

  num_args = 0;
#ifndef MOTIF
  XtSetArg (arglist[ZERO], XtNforceBars, True);
  XtSetArg (arglist[ONE], XtNallowVert, True);
  num_args = 2;
#endif
  view = XtCreateManagedWidget ("qview", viewportWidgetClass,
				frame, arglist, num_args);

  result =
    MakeScrollList(view, "questionWindow", Question_items, 
		   EditQuestion, NULL, NULL);

  button = MakeCommandButton(frame, "qadd", AddQuestion,
			     view, NULL, NULL);
  button = MakeCommandButton(frame, "qedit", EditQuestion,
			     view, NULL, NULL);
  button = MakeCommandButton(frame, "qdelete", DeleteQuestion,
			     view, NULL, NULL);
  return result;
}

static ScrollList
MakeSourceFrame(parent)
Widget parent;
{
  Widget frame, labelwid, button, view;
  ScrollList result;
  Arg arglist[TWO];
  Cardinal num_args;

  frame = XtCreateManagedWidget("tsources", formWidgetClass, parent, NULL, ZERO);

  labelwid = MakeLabel(frame, "sourcelabel", "Sources:", NULL, NULL);

  num_args = 0;
#ifndef MOTIF
  XtSetArg (arglist[ZERO], XtNforceBars, True);
  XtSetArg (arglist[ONE], XtNallowVert, True);
  num_args = 2;
#endif
  view = XtCreateManagedWidget ("tsview", viewportWidgetClass,
				frame, arglist, num_args);

  result =
    MakeScrollList(view, "sourceWindow", Source_items, 
		   EditSource, NULL, NULL);

  button = MakeCommandButton(frame, "sadd", AddSource,
			     view, NULL, NULL);
  button = MakeCommandButton(frame, "sedit", EditSource,
			     view, NULL, NULL);
  button = MakeCommandButton(frame, "sdelete", DeleteSource,
			     view, NULL, NULL);
  return result;
}

static Widget
MakeMessage(parent)
Widget parent;
{
  Widget stringlabelwid;
  Arg arglist[10];
  Cardinal num_args;

  stringlabelwid = MakeLabel(parent, "mainstatuslabel", "Status:",
			     NULL, NULL);
  num_args = 0;
  XtSetArg(arglist[num_args], XtNeditType, XawtextEdit); num_args++;
  XtSetArg(arglist[num_args], XtNsensitive, False); num_args++;
  XtSetArg(arglist[num_args], XtNfromVert, stringlabelwid); num_args++;
  return XtCreateManagedWidget("messageWindow", asciiTextWidgetClass,
			       parent, arglist, num_args);
}

static Widget
MakeSourcePopup(parent)
Widget parent;
{
  Arg args[THREE];
  Widget shell, frame, labelwid, stringlabelwid, button, tmp;
  static String
    namestring,
    serverstring,
    servicestring,
    dbstring,
    cost, units,
    maintainer,
    description;
  int CurrentSource;
  Source source;

  CurrentSource = get_selected_source();

  if (CurrentSource != NO_ITEM_SELECTED) {
    source = findSource(CurrentSource);
    namestring = source->name;
    serverstring = source->server;
    servicestring = source->service;
    dbstring = source->database;
    cost = source->cost;
    units = source->units;
    maintainer = source->maintainer;
    description = source->description;
  } else {
    namestring = "default";
    serverstring = "localhost";
    servicestring = "8000";
    dbstring = "";
    cost = "";
    units = "";
    maintainer = "";
    description = "";
  }

  shell = XtCreatePopupShell("sourcepopup", applicationShellWidgetClass,
			     parent, NULL, ZERO);
  frame = XtCreateManagedWidget("sourcepopupform", formWidgetClass,
				shell, NULL, ZERO);

  stringlabelwid = MakeLabel(frame, "sourcenamelabel", "       Name:", NULL, NULL);
  tmp = snamewid = MakeStringBox(frame, "sourcename", namestring, NULL, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "serverlabel",     "     Server:", tmp, NULL);
  tmp = serverwid = MakeStringBox(frame, "server", serverstring, tmp, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "servicelabel", "    Service:", tmp, NULL);
  tmp = servicewid = MakeStringBox(frame, "service", serverstring, tmp, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "dblabel",      "   Database:", tmp, NULL);
  tmp = dbwid = MakeStringBox(frame, "database", dbstring, tmp, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "costlabel",    "       Cost:", tmp, NULL);
  tmp = costwid = MakeStringBox(frame, "cost", cost, tmp, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "unitlabel",    "      Units:", tmp, NULL);
  tmp = unitwid = MakeStringBox(frame, "costunit", units, tmp, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "maintlabel",   " Maintainer:", tmp, NULL);
  tmp = maintainerwid = MakeStringBox(frame, "maintainer", maintainer, tmp, stringlabelwid);

  stringlabelwid = MakeLabel(frame, "desclabel",    "Description:", tmp, NULL);

  XtSetArg(args[ZERO], XtNeditType, XawtextEdit);
  XtSetArg(args[ONE], XtNstring, description);
  XtSetArg(args[TWO], XtNfromVert, stringlabelwid);

  tmp = descwid = 
    XtCreateManagedWidget("description", asciiTextWidgetClass, frame, args, THREE);

  button = MakeCommandButton(frame, "sdone", CloseSourceEdit, tmp, NULL, NULL);
  MakeCommandButton(frame, "cancel", CancelSourceEdit, tmp, button, NULL);

  return shell;
}

Widget
SetupWaisDisplay(parent)
Widget parent;
{
  Widget form, button;

  form = XtCreateManagedWidget ("form", formWidgetClass,
				parent, NULL, ZERO);

  questionwindow = MakeQuestionFrame(form);

  sourcewindow = MakeSourceFrame(form);

  button = MakeCommandButton(form, "help", XwaisHelp,
			     NULL, NULL, NULL);

  MakeCommandButton(form, "quit", DoQuit, NULL, button, NULL);

  messwidget = MakeMessage(form);

  sourcepopup = MakeSourcePopup(top);

  return form;
}
