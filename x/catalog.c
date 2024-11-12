/*                               -*- Mode: C -*- 
 * $Basename: catalog.c $
 * $Revision: 1.7.1.2 $
 * Author          : jonathan@Think.COM
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:52:11 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef lint
static char *PRCSid = "$Id: catalog.c 1.7.1.2 Mon, 05 May 1997 11:54:27 +0200 pfeifer $";
#endif

#ifndef _C_CATALOG
#define _C_CATALOG

#include "xwais.h"
#include "cat.h"

static Boolean busy = FALSE;
static long last_doc = -1;
static Catbuff scat = NULL;
static Widget cviewbutton, csavebutton;

				/* begin einet */
Widget parentByName(obj,name)
     Widget obj;
     char* name;
{
  while(obj != NULL &&
	strcmp(XtName(obj),name) != 0) obj = XtParent(obj);
  return obj;
}


Catbuff findCat(w)
     Widget w;
{
  Catbuff cat = scat;
  if (cat) 
    while (cat != NULL && cat->shell !=  parentByName(w,"catpopup"))
      cat = (Catbuff) cat->nextCat;
  return cat;
}

int freeCat(cat)
     Catbuff cat;
{
  if (cat->Items) free(cat->Items);
  if (cat->Types) free(cat->Types);
  if (cat->headlines) free(cat->headlines);
  if (cat->Docids) free(cat->Docids);
  free(cat);
}


int killCat(w)
     Widget w;
{
  Catbuff lastCat = NULL;
  Catbuff cat = scat;
  if (cat) { 
    while (cat != NULL && cat->shell !=  parentByName(w,"catpopup")) {
      lastCat = cat;
      cat = (Catbuff) cat->nextCat;
    }
    if (cat == scat) {
      scat = (Catbuff) cat->nextCat;
      freeCat(cat);
    } else {
      lastCat->nextCat = cat->nextCat;
      freeCat(cat);
    }
    return 1;
  }
  return 0;
}
				/* end einet */


Catbuff build_cat(catalog, source)
char* catalog;
SourceID source;
{
  char database[STRINGSIZE], headline[STRINGSIZE], docid[STRINGSIZE];
  char* p = catalog;
  long i, j, numdocs = 0, start, end, size;
  DocumentID docID;
  DocList dl;
  Catbuff result;
/*
  extern char *strstr(), *index();
*/
  if((result = (Catbuff)s_malloc(sizeof(_Catbuff))) == NULL) {
    PrintStatus(STATUS_URGENT, STATUS_HIGH, BADALLOC_MESSAGE);
    return NULL;
  }

  /* get the database name */
  p = strstr(p, "Catalog for database: ");
  if (p == NULL) {
    freeCat(result);
    return NULL;
  }
  p += strlen("Catalog for database: ");
  memset(database, 0, STRINGSIZE);
  strncpy(database, p, strstr(p, "\n")-p);
  while(numdocs == 0 && p != NULL && *p != 0) {
    sscanf(p, "%d total documents", &numdocs);
    p = strstr(p, "\n")+1;
  }

  result->source = source;
  result->database = s_strdup(database);
  result->Items = (String*)s_malloc((numdocs+1)*sizeof(String));
  result->Types = (String*)s_malloc((numdocs+1)*sizeof(String));
  result->headlines = (String*)s_malloc((numdocs+1)*sizeof(String));
  result->Docids = (String*)s_malloc((numdocs+1)*sizeof(String));
  result->numDocs = numdocs;

  /* find the first document */
  p = strstr(p, "\nDocument # ");

  for(i = 0; i < numdocs; i++) {
    char *s, *s2;
    if (p == NULL) {		/* premature end of catalog */
      freeCat(result);
      return NULL;
    }
    /* look for type string */
    s = index(p+1,'\n');
    if (s) {
      *s = '\0';		/* temporarily terminate the sub-string */
      if (s2 = strstr(p,"Type: ")) {
	/* found a type string */
	result->Types[i] = s_strdup(s2+strlen("Type: "));
      } else 
	result->Types[i] = s_strdup("TEXT");
      *s = '\n';		
    }

    /* set headline */
    p = strstr(p, "\nHeadline: ");
    if(p != NULL)
      p++; 
    else {
      freeCat(result);
      return (NULL);
    }
    p += strlen("Headline: ");
    memset(headline, 0, STRINGSIZE);
    strncpy(headline, p, index(p, '\n')-p);
    result->headlines[i] = s_strdup(headline);

    /* set the docid */
    p = index(p, '\n');
    if(p == NULL) break;
    else p += 1+strlen("DocID: ");
    memset(docid, 0, STRINGSIZE);
    strncpy(docid, p, index(p, '\n')-p);
    result->Docids[i] = s_strdup(docid);

    /* build the printable headline */
    sscanf(docid, "%d %d", &start, &end);
    size = end - start;
    if (size > 1024) 
      sprintf(headline, "%4.1fK %s", size/1024.0, result->headlines[i]);
    else
      sprintf(headline, "%5d %s", size, result->headlines[i]);
    result->Items[i] = s_strdup(headline);
      
    /* go to the next catalog record */
    for(j = 0; j < 2; j++) {
      p = index(p, '\n');
      if(p == NULL) break;
      else p++;
    }
  }
  result->nextCat = (void*) scat;
  scat = result;
  return result;
}
  

static DocumentID
makecatdoc(cat, i)
     Catbuff cat;
     long i;
{
  DocumentID docID = NULL;
  char* type;

  if((docID = (DocumentID)s_malloc(sizeof(_DocumentID))) != NULL) {
    docID->rawScore = 1000;
    docID->start = docID->end = -1;
    if((docID->doc = (CRetDocument)s_malloc(sizeof(_CRetDocument))) != NULL) {
      docID->doc->sourceID = cat->source;
      docID->doc->numLines = 0;
      docID->doc->numChars = -1;
      docID->doc->best = 0;
      docID->doc->headline = s_strdup(cat->headlines[i]);
      docID->doc->type = (char **)s_malloc(2*sizeof(char*));
      docID->doc->type[0] = cat->Types[i];
      docID->doc->type[1] = NULL;

      docID->doc->id = (DocID*)s_malloc(sizeof(DocID));
      memset(docID->doc->id, 0, sizeof(DocID));
      docID->doc->id->originalDatabase = stringToAny(cat->database);
      docID->doc->id->originalLocalID = stringToAny(cat->Docids[i]);
    }
  }
  return docID;
}

/* ARGSUSED */
static void
ViewCat(w, closure, call_data)
     Widget w;
     XtPointer closure, call_data;
{
  Catbuff cat = findCat(w);	/* einet */
  static int document_number;

  double_click = FALSE;
  LastClicked = w;

  if(!busy)
    if((document_number = get_selected_item(cat->List->ListWidget)) ==
       NO_ITEM_SELECTED)
      PrintStatus(STATUS_URGENT, STATUS_HIGH, NOSELECT_MESSAGE);
    else {
      DocumentID doc;

      if (document_number != last_doc) {
	last_doc = document_number;
      }
      else {
	messwidget = cat->status;
	if((doc = makecatdoc(cat, document_number)) == NULL)
	  PrintStatus(STATUS_URGENT, STATUS_HIGH, NODOC_MESSAGE);
	else {
	  ViewDoc(doc, doc->doc->type[0], 0, (w == csavebutton));
	}
      }
    }
}

static void
CloseCat(w, closure, call_data)
     Widget w;
     XtPointer closure, call_data;
{
  XtPopdown(parentByName(w,"catpopup"));
  killCat(w);		/* einet */
}

Widget
MakeCatPopup(parent, cat, name)
     Widget parent;
     Catbuff cat;
     char *name;
{
  Widget frame, button, stringlabelwid, view;
  Arg args[TWO];
  static String items[] = {NULL};

  XtSetArg(args[ZERO], XtNtitle, name);
  XtSetArg(args[ONE], XtNiconName, name);
  cat->shell = XtCreatePopupShell("catpopup", applicationShellWidgetClass,
				  parent, args, TWO);
  frame =
    XtCreateManagedWidget("questionpopupform", formWidgetClass,
			  cat->shell, NULL, ZERO);

  stringlabelwid = MakeLabel(frame, "foo", "Catalog of", NULL, NULL);

  stringlabelwid =
    MakeLabel(frame, "qreslabel", "documents:",
	      stringlabelwid, NULL);

  cviewbutton = button = 
    MakeCommandButton(frame, "view", ViewCat,
		      stringlabelwid, NULL, NULL);

  csavebutton = button =
    MakeCommandButton(frame, "qsave", ViewCat,
		      button, NULL, NULL);

  button =
    MakeCommandButton(frame, "qdone", CloseCat,
		      button, NULL, (char *)cat);

  XtSetArg (args[ZERO], XtNallowVert, True);
  XtSetArg (args[ONE], XtNfromVert, NULL);

  view = XtCreateManagedWidget ("rview", viewportWidgetClass,
				frame, args, TWO);

  cat->List = 
    MakeScrollList(view, "catresults", cat->Items,
		   ViewCat, NULL, NULL);

  stringlabelwid =
    MakeLabel(frame, "statuslabel", "Status:",
	      NULL, NULL);

  XtSetArg(args[ZERO], XtNeditType, XawtextEdit);

  cat->status =
    XtCreateManagedWidget("statusWindow", asciiTextWidgetClass,
			  frame, args, ONE);

  return(cat->shell);
}

#endif

