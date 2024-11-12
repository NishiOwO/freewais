/*                               -*- Mode: C -*- 
 * $Basename: util.h $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:19:26
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:28:25 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */


#ifndef _H_UTIL
#define _H_UTIL

#define LIST_TOP 1
#define LIST_BOTTOM 2
#define LIST_NONE 0

int get_selected_item _AP((Widget w));
int listlength _AP((List list));
int charlistlength _AP((char **list));
void PrintStatusW _AP((char * str,Widget w, boolean replacep));
void XwaisPrintf _AP((char * str));
void ReplaceText _AP((Widget w,char * str));
void ReplaceAsciiText _AP((Widget w,char * str));
Widget MakeCommandButton _AP((Widget box,char* name,XtCallbackProc function,
			      Widget vlink,Widget hlink,caddr_t data));
Widget MakeListWidget _AP((Widget parent,String name,char **list,
			   XtCallbackProc callback,Widget vlink,Widget hlink));
void RebuildListWidget _AP((ScrollList s,String *list, long action));
ScrollList MakeScrollList _AP((Widget parent,String name,String* items,
			       XtCallbackProc callback, 
			       Widget vlink,Widget hlink));
Widget MakeStringBox _AP((Widget parent,String name,String string,
			  Widget vlink,Widget hlink));
#ifdef MOTIF
Widget MakeScrolledText _AP((Widget parent,String name,String string,
			  Widget vlink,Widget hlink));
#endif
String GetString _AP((Widget w));
Widget MakeLabel _AP((Widget parent,char* name,char* label,
		      Widget vlink,Widget hlink));
int find_string_slot _AP((char* source,char* key,char* value,
			  long value_size, boolean delete_internal_quotes));
void find_value _AP((char* source,char* key,char* value, int value_size));
void SortSources _AP((void));
char* get_filename _AP((char* name));
void Feep _AP((void));
char** GetDirNames _AP((char* directory));
void EndHelp _AP((Widget w, XtPointer closure,XtPointer call_data));
void XwaisHelp _AP((Widget w, XtPointer closure,XtPointer call_data));
#endif
