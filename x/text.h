/*                               -*- Mode: C -*- 
 * $Basename: text.h $
 * $Revision: 1.8.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/03/17  14:17:54
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:30:26 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * 
 */

#ifndef _H_TEXT
#define _H_TEXT

typedef struct textbuff {
  Widget	shell;
  Widget	textwindow;
  Widget	status;
  DocumentID 	docid;
  char *	text;
  char *	type;
  long 		size;
} _Textbuff, *Textbuff;

typedef struct textlist {
  Textbuff thisText;
  struct textlist *nextText;
} _TextList, *TextList;

/* functions */

TextList NewText _AP((void));
void KillText _AP((Textbuff t));
Textbuff findText _AP((Widget w));
Textbuff findTextDoc _AP((DocumentID doc, char* type));

#endif
