/*                               -*- Mode: C -*- 
 * $Basename: sigsrch.h $
 * $Revision: 1.6 $
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 11:03:54 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _sigsrch_h
#define _sigsrch_h

extern long sig_close_database _AP(( database *));
extern long sig_open_database _AP(( database *, long, long, long, long, long, long));
extern long sig_exit _AP(( void));
extern long sig_init _AP(( char *, long, long, long, long));
extern long sig_init_add_word _AP(( database *, long, long));
extern long sig_finished_add_word _AP(( database *));
extern long sig_add_word _AP(( char *, long, long, long, long, long, long));
extern long sig_delete_doc_id _AP(( long, long));
extern long sig_init_search_word _AP(( database *));
extern long sig_search_word _AP(( char *, long, long, long, long, long,
                    long, long));
extern long sig_finished_search_word _AP(( database *));
extern long sig_best_hit _AP(( long *, long *, long *, long *));
extern long sig_finished_best_hit _AP(( void));

#endif
