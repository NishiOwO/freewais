: Makefile.SH generated from Jmake.tmpl and Jmakefile [jmake 3.0 PL70]
: $X-Id: Jmake.tmpl,v 3.0.1.3 1997/02/28 14:56:16 ram Exp $

case $CONFIG in
'')
	if test -f config.sh; then TOP=.;
	elif test -f ../config.sh; then TOP=..;
	elif test -f ../../config.sh; then TOP=../..;
	elif test -f ../../../config.sh; then TOP=../../..;
	elif test -f ../../../../config.sh; then TOP=../../../..;
	else
		echo "Can't find config.sh."; exit 1
	fi
	. $TOP/config.sh
	;;
esac
case "$0" in
*/*) cd `expr X$0 : 'X\(.*\)/'` ;;
esac
CURRENT=lib
DIR=`echo $CURRENT/ | sed -e 's/\.\///g'`
echo "Extracting ${DIR}Makefile (with variable substitutions)"

INSTALL=`echo $install | sed -e 's,\./i,\$(TOP)/i,'`
DATE=`date`

$spitshell >Makefile <<!GROK!THIS!
########################################################################
# Makefile generated from Makefile.SH on $DATE

SHELL = /bin/sh
JMAKE = jmake
TOP = ..
CURRENT = $CURRENT
DIR = $DIR
INSTALL = $INSTALL

########################################################################
# Parameters set by Configure -- edit config.sh if changes are needed

AR = ar rc
CC = $cc
CTAGS = ctags
MAKE = make
MKDEP = $mkdep \$(DPFLAGS) --
MV = $mv
RANLIB = $ranlib
RM = $rm -f
SED = $sed

########################################################################
# Automatically generated parameters -- do not edit

CTYPEDIR = $ctypedir
CTYPEOBJ = $ctypeobj
REGEXPDIR = $regexpdir
REGEXPOBJ = $regexpobj
EMBED = $embed_ldopts
CFLAGS = $ccflags $optimize $mccflags
SO = $so
REV = $baserev.$patchlevel
PRIVLIB = $installprivlib
PRIVINC = `echo $installprivlib | sed -e s:/lib/:/include/:`
USRINC = $usrinc
SUBDIRS = \$(SUBDIRS)

!GROK!THIS!
$spitshell >>Makefile <<'!NO!SUBS!'
########################################################################
# Jmake rules for building libraries, programs, scripts, and data files
# $X-Id: Jmake.rules,v 3.0.1.6 1997/02/28 14:56:01 ram Exp $

########################################################################
# Force 'make depend' to be performed first -- do not edit

.FORCE_DEPEND::

all:: .FORCE_DEPEND

########################################################################
# Start of Jmakefile
############################ -*- Mode: Makefile -*- ###########################
## $Basename: Makefile.SH $
## $Revision: 1.2 $
## Author          : Ulrich Pfeifer
## Created On      : Tue Mar  8 14:40:27 1994
## Last Modified By: Ulrich Pfeifer
## Last Modified On: Wed May  7 21:03:26 1997
## Language        : Makefile
## Update Count    : 280
## Status          : Unknown, Use with caution!
##
## (C) Copyright 1997, Ulrich Pfeifer, all rights reserved.
##
###############################################################################

SUBDIRS =  $(CTYPEDIR) $(REGEXPDIR) ftw ir

IROBJS = \
ir/any_stemmer.o ir/grundform.o ir/syslog.o ir/ircfiles.o              \
ir/irfileio.o ir/irfiles.o ir/irtfiles.o ir/irkeywords.o ir/stemmer.o  \
ir/sockets.o ir/transprt.o ir/html_entities.o ir/wmessage.o ir/wprot.o \
ir/wutil.o ir/zprot.o ir/zutil.o ir/ztype1.o ir/soundex.o ir/docid.o   \
ir/list.o ir/lock.o ir/udping.o ir/ir.o ir/irretrvl.o ir/stoplist.o    \
ir/irsearch.o ir/synonym.o ir/trie.o ir/field_index.o                  \
ir/field_search.o ir/ui.o ir/sersrch.o ir/irhash.o ir/hash.o           \
ir/irinv.o ir/weight.o ir/boolean_op.o ir/field_l.o ir/field_y.o       \
ir/query_y.o ir/query_l.o

FTWOBJS = ftw/alphasort.o ftw/alloca.o ftw/freedir.o ftw/ftw.o ftw/scandir.o
SRCS    = cutil.c ustubs.c panic.c futil.c
OBJS    = cutil.o ustubs.o panic.o futil.o

all:: libwais.a wais.h

$(CTYPEOBJ) $(REGEXPOBJ) $(FTWOBJS) $(IROBJS): subdirs

depend:: ../mkdep

../mkdep:
	@echo "You have to run Configure in $(TOP) first."; exit 1

depend::
	($(SED) '/^# DO NOT DELETE/q' Makefile && \
	($(MKDEP) $(SOURCES); echo 'foo: bar') | \
	$(SED) -e 's:/usr/include[^ ]*::g; s:$(USRINC)[^ ]*::g; ' \
	-e '/: / b print' -e 'H; d; n; : print' -e 'x; s/\\\n//g' \
	-e 's/  */ /g; s/ :/:/;' -e '/: *$$/d' \
	) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) Makefile.new

depend::
	@case '${MFLAGS}' in *[ik]*) set +e;; esac; \
	for i in $(SUBDIRS) ;\
	do \
	(cd $$i ; echo "Depending" "in $(DIR)$$i..."; \
	$(MAKE) $(MFLAGS)  depend); \
	done

test::
	@case '${MFLAGS}' in *[ik]*) set +e;; esac; \
	for i in $(SUBDIRS);\
	do \
	echo "Making "test" in $(DIR)$$i..."; \
	(cd $$i || exit 1; \
	if test ! -f Makefile; then /bin/sh Makefile.SH; fi; \
	$(MAKE) $(MFLAGS) test) \
	done

ALLOBJ = $(CTYPEOBJ) $(REGEXPOBJ) $(OBJS) $(FTWOBJS) $(IROBJS)

libwais.a: $(OBJS) subdirs
	$(RM) $@
	$(AR) $@ $(ALLOBJ)
	$(RANLIB) $@

install:: libwais.a
	$(INSTALL) -c -m 644 libwais.a $(PRIVLIB)
	$(RANLIB) $(PRIVLIB)/libwais.a
	chmod 444 $(PRIVLIB)/libwais.a

deinstall::
	$(RM) $(PRIVLIB)/libwais.a

shared: libwais.$(SO).$(REV)

libwais.$(SO).$(REV): $(OBJS) subdirs
	$(RM) $@
	@case '$(CFLAGS)' in  \
	*pic*) \
	   lddlflags=`perl -MConfig -e 'print $$Config{lddlflags}'` ; \
	   echo $(CC) $$lddlflags -o libwais.$(SO).$(REV) $(ALLOBJ) $(EMBED); \
	   $(CC) $$lddlflags -o libwais.$(SO).$(REV) $(ALLOBJ) $(EMBED);; \
	*) \
	   echo "You probably must add '-fpic' or '-pic' to the CFLAGS"; \
	   exit 1;; \
	       esac

EINC = ir/ui.h cutil.h ir/irext.h ir/irfiles.h ir/irsearch.h ir/irtfiles.h \
	      ir/weight.h ir/docid.h
MKINC = ./mkinc

wais.h: $(EINC)
	-perl $(MKINC) $(CFLAGS) $(EINC) > wais.h

install:: wais.h
	@case '${MFLAGS}' in *[i]*) set +e;; esac; \
	for i in wais.h; do \
	(set -x; $(INSTALL) -c -m 664 $$i $(PRIVINC)); \
	done

deinstall::
	@case '${MFLAGS}' in *[i]*) set +e;; esac; \
	for i in wais.h; do \
	(set -x; $(RM) $(PRIVINC)/$$i); \
	done

local_realclean::
	$(RM) wais.h

########################################################################
# Common rules for default Makefiles -- do not edit

emptyrule::

clean: sub_clean local_clean
realclean: sub_realclean local_realclean
clobber: sub_clobber local_clobber

local_clean::
	$(RM) core *~ *.o

local_realclean:: local_clean

local_clobber:: local_realclean
	$(RM) Makefile config.sh

Makefile.SH: Jmakefile
	-@if test -f $(TOP)/.package; then \
	if test -f Makefile.SH; then \
	echo "	$(RM) Makefile.SH~; $(MV) Makefile.SH Makefile.SH~"; \
	$(RM) Makefile.SH~; $(MV) Makefile.SH Makefile.SH~; \
	fi; \
	echo "	$(JMAKE) -DTOPDIR=$(TOP) -DCURDIR=$(CURRENT)" ; \
	$(JMAKE) -DTOPDIR=$(TOP) -DCURDIR=$(CURRENT) ; \
	else touch $@; exit 0; fi

Makefile: Makefile.SH
	/bin/sh Makefile.SH

tags::
	$(CTAGS) -w *.[ch]
	$(CTAGS) -xw *.[ch] > tags

local_clobber::
	$(RM) tags

########################################################################
# Rules for building in sub-directories -- do not edit

subdirs:
	@case '${MFLAGS}' in *[ik]*) set +e;; esac; \
	for i in $(SUBDIRS) ;\
	do \
	(cd $$i ; echo $(VERB) "in $(DIR)$$i..."; \
	$(MAKE) $(MFLAGS) $(FLAGS) $(TARGET)); \
	done

install::
	@$(MAKE) subdirs TARGET=install VERB="Installing" FLAGS=

deinstall::
	@$(MAKE) subdirs TARGET=deinstall VERB="Deinstalling" FLAGS=

install.man::
	@$(MAKE) subdirs TARGET=install.man VERB="Installing man pages" FLAGS=

deinstall.man::
	@$(MAKE) subdirs TARGET=deinstall.man VERB="Deinstalling man pages" FLAGS=

sub_clean::
	@$(MAKE) subdirs TARGET=clean VERB="Cleaning" FLAGS=
	@echo "Back to $(CURRENT) for "clean...

sub_realclean::
	@$(MAKE) subdirs TARGET=realclean VERB="Real cleaning" FLAGS=
	@echo "Back to $(CURRENT) for "realclean...

sub_clobber::
	@$(MAKE) subdirs TARGET=clobber VERB="Clobbering" FLAGS=
	@echo "Back to $(CURRENT) for "clobber...

tag::
	@case '${MFLAGS}' in *[ik]*) set +e;; esac; \
	for i in $(SUBDIRS) ;\
	do \
	(cd $$i ; echo "Tagging" "in $(DIR)$$i..."; \
	$(MAKE) $(MFLAGS)  tag); \
	done

Makefiles::
	@case '${MFLAGS}' in *[ik]*) set +e;; esac; \
	for i in $(SUBDIRS);\
	do \
	echo "Making "Makefiles" in $(DIR)$$i..."; \
	(cd $$i || exit 1; \
	if test ! -f Makefile; then /bin/sh Makefile.SH; fi; \
	$(MAKE) $(MFLAGS) Makefiles) \
	done

Makefiles.SH:: Makefile.SH
	@case '${MFLAGS}' in *[ik]*) set +e;; esac; \
	for i in $(SUBDIRS);\
	do \
	case "$(DIR)$$i/" in \
	*/*/*/*/) newtop=../../../..;; \
	*/*/*/) newtop=../../..;; \
	*/*/) newtop=../..;; \
	*/) newtop=..;; \
	esac; \
	case "$(TOP)" in \
	/*) newtop="$(TOP)" ;; \
	esac; \
	echo "Making Makefiles.SH in $(DIR)$$i..."; \
	(cd $$i || exit 1; $(MAKE) $(MFLAGS) -f ../Makefile \
	Makefile TOP=$$newtop CURRENT=$(DIR)$$i;\
	$(MAKE) $(MFLAGS) Makefiles.SH) \
	done

default::
	@$(MAKE) subdirs TARGET=default VERB="Making all" FLAGS=

########################################################################
# Dependencies generated by make depend
# DO NOT DELETE THIS LINE -- make depend relies on it

# Put nothing here or make depend will gobble it up
.FORCE_DEPEND::
	@echo "You must run 'make depend' in $(TOP) first."; exit 1
!NO!SUBS!
chmod 644 Makefile
$eunicefix Makefile

