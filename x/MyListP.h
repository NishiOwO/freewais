/*                               -*- Mode: C -*- 
 * $Basename: MyListP.h $
 * $Revision: 1.6.1.2 $
 * Author          : Garrett A. Wollman, Garrett.Wollman@uvm.edu.
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:57:35 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/*
 * MyList.h - private declarations
 *
 * Subclass of the Athena List widget to provide notification on
 * de-selection of list items.
 *
 * Written by Garrett A. Wollman, Garrett.Wollman@uvm.edu.
 *
 * Copyright 1992, University of Vermont and State Agricultural College.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of U.V.M. not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  U.V.M. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * U.V.M. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL U.V.M.
 * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _h_MyListP		/* use programmer's namespace */
#define _h_MyListP

#define MyListP_id "$Id: MyListP.h 1.6.1.2 Mon, 05 May 1997 11:54:27 +0200 pfeifer $"

#include <X11/CoreP.h>
#include <X11/Xaw/SimpleP.h>
#include <X11/Xaw/ListP.h>

typedef struct {
  int MyListDummy;
} MyListClassPart;

typedef struct _MyListClassRec {
  CoreClassPart core_class;
  SimpleClassPart simple_class;
  ListClassPart list_class;
  struct { int MyListDummy; } mylist_class;
} MyListClassRec;

extern MyListClassRec myListClassRec;

typedef struct {
  int MyListDummy;
} MyListPart;

typedef struct _MyListRec {
  CorePart core;
  SimplePart simple;
  ListPart list;
  MyListPart mylist;
} MyListRec;


#endif /* defined( _h_MyListP ) */
