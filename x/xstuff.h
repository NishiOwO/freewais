/*                               -*- Mode: C -*- 
 * $Basename: xstuff.h $
 * $Revision: 1.6 $
 * Author          : jonathan@Think.COM
 * Created On      : Fri Feb  1 1991
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 09:26:23 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_XSTUFF
#define _H_XSTUFF

#include <X11/Xlib.h>
#include <X11/Xos.h>
#include <X11/Intrinsic.h>
#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <X11/cursorfont.h>
#include <X11/Xatom.h>

#include <X11/Shell.h>
#include <X11/ShellP.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Label.h>
#include <X11/Xaw/AsciiText.h>
#include <X11/Xaw/List.h>
#include <X11/Xaw/Scrollbar.h>
#include <X11/Xaw/Viewport.h>
#include <X11/Xaw/Cardinals.h>
#include <X11/Xaw/Dialog.h>

#include <X11/Xaw/MenuButton.h>
#include <X11/Xaw/SimpleMenu.h>
#include <X11/Xaw/Sme.h>
#include <X11/Xaw/SmeBSB.h>

#include "MyList.h"

#ifdef MOTIF
#include <Xm/Xm.h>
#include <Xm/List.h>
#include <Xm/Form.h>
#include <Xm/PushB.h>
#include <Xm/Separator.h>
#include <Xm/Label.h>
#include <Xm/Text.h>
# define COMMANDBUTTON xmPushButtonWidgetClass
# define COMMANDCALLBACK XmNactivateCallback
# define TEXTWIDGET xmTextWidgetClass
# define NSTRING XmNvalue
# define LABELWIDGET xmLabelWidgetClass
# define NLABEL XmNlabelString
# define VERTVAL False
# define SENSVAL True
#else
# define COMMANDBUTTON commandWidgetClass
# define COMMANDCALLBACK XtNcallback
# define TEXTWIDGET asciiTextWidgetClass
# define NSTRING XtNstring
# define LABELWIDGET labelWidgetClass
# define NLABEL XtNlabel
# define VERTVAL True
# define SENSVAL False
#endif

#endif
