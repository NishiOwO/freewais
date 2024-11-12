/*                               -*- Mode: C -*- 
 * $Basename: cat.h $
 * $Revision: 1.8.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/06/23  14:09:41
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:52:47 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

typedef struct catbuff {
  Widget	shell;
  SourceID	source;
  ScrollList	List;
  char*		database;
  String*	Items;
  String* 	headlines;
  String*	Docids;
  String*       Types;		/* einet */
  Widget	status;
  long          numDocs;	/* einet */
  void*         nextCat;	/* einet */
} _Catbuff, *Catbuff;

Catbuff build_cat _AP((char* catalog, SourceID source));
Widget MakeCatPopup _AP((Widget parent,Catbuff cat,char *name));

