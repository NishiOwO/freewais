/*                               -*- Mode: C -*- 
 * $Basename: qcommands.h $
 * $Revision: 1.9.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:24:41
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:36:50 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_QCOMMANDS
#define _H_QCOMMANDS

typedef struct _sbuff {
  Source s;
  char* buffer;
  long buffer_offset;
  long toRead;
  long read_state;
  long page;
  long chars_per_page;
  long doc_size;
  Textbuff textstruct;
  XtInputId xid; /* Input Id from XtAddInput */
} _Sbuff, *Sbuff;

XawTextPosition findstring _AP((char* text,char* string,Boolean casesensitive));
void fuzzButtons _AP((boolean fuzz));
void Abort _AP((Widget w, XtPointer closure,XtPointer call_data));
void Prefs _AP((Widget w, XtPointer closure,XtPointer call_data));
void DoPSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void DontPSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void DoSearch _AP((Widget w, XtPointer closure,XtPointer call_data));
void CloseQuestionEdit _AP((Widget w, XtPointer closure,XtPointer call_data));
void AddResponseToQuestion _AP((Widget w, XtPointer closure,XtPointer call_data));
void AddDocToQuestion _AP((Widget w, XtPointer closure,XtPointer call_data));
void DeleteQuestionDoc _AP((Widget w, XtPointer closure,XtPointer call_data));
void PopupSourceMenu _AP((Widget w, XtPointer closure,XtPointer call_data));
void AddSourceToQuestion _AP((Widget w, XtPointer closure,XtPointer call_data));
void EditQuestionSource _AP((Widget w, XtPointer closure,XtPointer call_data));
void DeleteQuestionSource _AP((Widget w, XtPointer closure,XtPointer call_data));
void doType _AP((Widget w, XtPointer closure,XtPointer call_data));
void SensitizeDelSource _AP((Widget w,XtPointer closure,XtPointer call_data));
void SensitizeAddDoc _AP((Widget w,XtPointer closure,XtPointer call_data));
void SensitizeDelDoc _AP((Widget w,XtPointer closure,XtPointer call_data));
void ViewDoc _AP((DocumentID doc,char* type,long size,Boolean saveit));
void ViewResponse _AP((Widget w, XtPointer closure,XtPointer call_data));
void ViewRelevant _AP((Widget w, XtPointer closure,XtPointer call_data));
void EndText _AP((Widget w, XtPointer closure,XtPointer call_data));
void showKeyword _AP((Widget w, XtPointer closure,XtPointer call_data));
void SaveText _AP((Widget w, XtPointer closure,XtPointer call_data));
void DoSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void DoTSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void DontTSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void setSourceMenu _AP((void));
void addSection _AP((Widget w, XtPointer closure,XtPointer call_data));
void DoSSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void DontSSave _AP((Widget w, XtPointer closure,XtPointer call_data));
void showNext _AP((Widget w, XtPointer closure,XtPointer call_data));
void showPrevious _AP((Widget w, XtPointer closure,XtPointer call_data));
void setFile _AP((Widget w, XtPointer closure,XtPointer call_data));
void quitFile _AP((Widget w, XtPointer closure,XtPointer call_data));
char* GetKeywordsUsed _AP((void));
#endif

