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
CURRENT=.
DIR=`echo $CURRENT/ | sed -e 's/\.\///g'`
echo "Extracting ${DIR}Makefile (with variable substitutions)"

INSTALL=`echo $install | sed -e 's,\./i,\$(TOP)/i,'`
DATE=`date`

$spitshell >Makefile <<!GROK!THIS!
########################################################################
# Makefile generated from Makefile.SH on $DATE

SHELL = /bin/sh
JMAKE = jmake
TOP = ../..
CURRENT = $CURRENT
DIR = $DIR
INSTALL = $INSTALL

########################################################################
# Parameters set by Configure -- edit config.sh if changes are needed

CC = $cc
CTAGS = ctags
JCFLAGS = \$(CFLAGS) $optimize $ccflags $large
JLDFLAGS = \$(LDFLAGS) $optimize $ldflags
L = $manext
LIBS = $libs
MAKE = make
MKDEP = $mkdep \$(DPFLAGS) --
MV = $mv
RM = $rm -f
SED = $sed

########################################################################
# Automatically generated parameters -- do not edit

CFLAGS = $ccflags $optimize -I. $mccflags
LDFLAGS =  -L\$(TOP)/lib -lwais
DPFLAGS = -I\$(TOP)/lib/ir $mccflags $embed_cflags
MAN3DIR = $man3dir
L = $man3ext
USRINC = $usrinc
OBJECTS =  trunc.o stringtoany.o ftwtest.o scantest.o
SOURCES =  trunc.c stringtoany.c ftwtest.c scantest.c

########################################################################
# New suffixes and associated building rules -- edit with care

.c.o:
	\$(CC) -c \$(JCFLAGS) \$<

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
## $Revision: 1.19 $
## Author          : Ulrich Pfeifer
## Created On      : Tue Mar  8 14:46:34 1994
## Last Modified By: Ulrich Pfeifer
## Last Modified On: Tue May 13 18:07:20 1997
## Language        : Makefile
## Update Count    : 91
## Status          : Unknown, Use with caution!
##
## (C) Copyright 1997, Ulrich Pfeifer, all rights reserved.
##
###############################################################################

OBJS = alphasort.o alloca.o freedir.o ftw.o scandir.o
SRCS = alphasort.c alloca.c freedir.c ftw.c scandir.c

all:: $(OBJS)

depend:: ../../mkdep

../../mkdep:
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

test:: trunc

local_realclean::
	$(RM) trunc

trunc: trunc.o
	$(RM) $@
	if test -f $@; then $(MV) $@ $@~; else exit 0; fi
	$(CC) -o $@ trunc.o $(JLDFLAGS) $(LIBS)

test:: stringtoany

local_realclean::
	$(RM) stringtoany

stringtoany: stringtoany.o
	$(RM) $@
	if test -f $@; then $(MV) $@ $@~; else exit 0; fi
	$(CC) -o $@ stringtoany.o $(JLDFLAGS) $(LIBS)

test:: ftwtest

local_realclean::
	$(RM) ftwtest

ftwtest: ftwtest.o
	$(RM) $@
	if test -f $@; then $(MV) $@ $@~; else exit 0; fi
	$(CC) -o $@ ftwtest.o $(JLDFLAGS) $(LIBS)

test:: scantest

local_realclean::
	$(RM) scantest

scantest: scantest.o
	$(RM) $@
	if test -f $@; then $(MV) $@ $@~; else exit 0; fi
	$(CC) -o $@ scantest.o $(JLDFLAGS) $(LIBS)

install.man:: ftw.man
	$(INSTALL) -c -m 444 ftw.man $(MAN3DIR)/ftw.$(L)

deinstall.man::
	$(RM) $(MAN3DIR)/ftw.$(L)

install.man:: scandir.man
	$(INSTALL) -c -m 444 scandir.man $(MAN3DIR)/scandir.$(L)

deinstall.man::
	$(RM) $(MAN3DIR)/scandir.$(L)

test:: ftwtest scantest
	@echo ftwtest
	./ftwtest /tmp
	@echo scantest
	./scantest /tmp

########################################################################
# Common rules for test Makefiles -- do not edit

emptyrule::

clean: local_clean
realclean: local_realclean
clobber: local_clobber

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
# Empty rules for directories with no sub-directories -- do not edit

install::
	@echo "install in $(CURRENT) done."

deinstall::
	@echo "deinstall in $(CURRENT) done."

install.man::
	@echo "install.man in $(CURRENT) done."

deinstall.man::
	@echo "deinstall.man in $(CURRENT) done."

Makefiles::

Makefiles.SH::

########################################################################
# Dependencies generated by make depend
# DO NOT DELETE THIS LINE -- make depend relies on it

# Put nothing here or make depend will gobble it up
.FORCE_DEPEND::
	@echo "You must run 'make depend' in $(TOP) first."; exit 1
!NO!SUBS!
chmod 644 Makefile
$eunicefix Makefile

