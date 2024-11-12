/*                               -*- Mode: C -*- 
 * $Basename: globals.h $
 * $Revision: 1.8.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 1993/02/16  15:09:27
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:20:45 1997
 * Language        : C
 * Update Count    : 2
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef H_GLOBALS
#define H_GLOBALS

#ifdef MAIN
#define ext
#else
#define ext extern
#endif

ext char* command_name;

ext int NumQuestions;

ext Question the_Question;

ext SList Sources;
ext int NumSources;

#endif
