/*                               -*- Mode: C -*- 
 * $Basename: scommands.h $
 * $Revision: 1.5 $
 * Author          : jonathan@Think.COM
 * Created On      : Tue Apr 30 1991
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:33:47 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_SCOMMANDS
#define _H_SCOMMANDS

extern void EditSource();
extern void AddSource();
extern void WriteSourcetoFile();
extern void CloseSourceEdit();
extern void CancelSourceEdit();
extern void PopupSource();
extern void sVerticalScroll();
extern void sVerticalJump();
extern void setSourceMenu();

#endif
