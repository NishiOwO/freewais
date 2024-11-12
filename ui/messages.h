/*                               -*- Mode: C -*- 
 * $Basename: messages.h $
 * $Revision: 1.7.1.3 $
 * Author          : jonathan@Think.COM
 * Created On      : 92/06/21  12:40:01
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 10:18:18 1997
 * Language        : C
 * Update Count    : 1
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * (C) Copyright CNIDR (see ../doc/CNIDR/COPYRIGHT)
 */

/* some typical error messages */

#define DIAG_MESSAGE \
 "\nCode: %s, %s"

#define NOSELECT_MESSAGE \
 "\nNo selected item.  Select one and try again."

#define NODOC_MESSAGE \
 "\nUnable to find document.  This should not happen."

#define BADCONNECT_MESSAGE \
 "\nWarning: no information returned.  Possibly a bad connection"

#define BADALLOC_MESSAGE \
 "\nUnable to allocate space."

#define BUFFOVER_MESSAGE \
 "\nBuffer overflow!"

#define SEARCH_MESSAGE \
 "Searching %s..."

#define NOSEARCH_MESSAGE \
 "\nCan't search %s: Init Failure."

#define INITSOURCE_MESSAGE \
 "Initializing connection..."

#define FOUND_MESSAGE \
 "Found %d items."

#define BADWAIS_MESSAGE \
 "Failed to send WAIS request to source"

#define INITFAIL_MESSAGE \
 ": connection failed!"

#define NOSOURCE_MESSAGE \
 "\nCould not find Source: %s. "

#define VIEWSOURCE_MESSAGE \
 "\nViewing source: %s"

#define GETDOC_MESSAGE \
 "Getting \"%s\" from %s..."

#define BADNEXT_MESSAGE \
"\nCould not get next document."

#define BADPREV_MESSAGE \
 "\nCould not get previous document."

#define NOGETDOC_MESSAGE \
 "\nUnable to retrieve \"%s\" from %s."

#define RECEIVE_MESSAGE \
 "\nReceived %d bytes from %s..."

#define NODATA_MESSAGE \
 "\nNo data returned"

#define BADFOPEN_MESSAGE \
 "\nError opening file: %s."

#define ENTERFNAME_MESSAGE \
 "\nYou have to enter a filename."

#define UNKNOWNTYPE_MESSAGE \
 "\nDocument is of type: %s, which is unknown. Using Save routine."

#define FILTER_MESSAGE \
 "\nRunning '%s %s'"

#define ABORT_MESSAGE \
 "\nTransaction Aborted."

#define DONE_MESSAGE \
 "done."

