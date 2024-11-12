/*                               -*- Mode: C -*- 
 * $Basename: wais.h $
 * $Revision: 1.7.1.4.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/02/15  19:50:24
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:07:46 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

#ifndef _H_WAIS
#define _H_WAIS

/* usefull definitions */

#define STRINGSIZE	256

/* from the IR directory */

#include <cutil.h>
#include <ui.h>
#include <irfileio.h>
#include <sockets.h>

#ifdef _IBMR2
#include <string.h>
#endif /* IBMR2 */

/* for this application */

#include "list.h"
#include "source.h"
#include "document.h"
#include "question.h"
#include "wais-ui.h"
#include "status.h"
#include "messages.h"
#endif

