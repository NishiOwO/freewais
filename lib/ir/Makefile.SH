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
CURRENT=lib/ir
DIR=`echo $CURRENT/ | sed -e 's/\.\///g'`
echo "Extracting ${DIR}Makefile (with variable substitutions)"

DATE=`date`

$spitshell >Makefile <<!GROK!THIS!
########################################################################
# Makefile generated from Makefile.SH on $DATE

SHELL = /bin/sh
JMAKE = jmake
TOP = ../..
CURRENT = $CURRENT
DIR = $DIR

########################################################################
# Parameters set by Configure -- edit config.sh if changes are needed

CC = $cc
CP = $cp
CTAGS = ctags
JLFLAGS = \$(LFLAGS)
JYFLAGS = \$(YFLAGS) $yaccflags
LEX = $lex
MAKE = make
MKDEP = $mkdep \$(DPFLAGS) --
MV = $mv
RM = $rm -f
SED = $sed
YACC = $yacc

########################################################################
# Automatically generated parameters -- do not edit

CFLAGS = $ccflags $optimize $mccflags $embed_cflags
LDFLAGS =  -L\$(TOP)/lib -lwais $socketlib -lm $embed_ldopts
USRINC = $usrinc
OBJECTS =  query_l.o query_y.o field_l.o field_y.o
SOURCES =  query_l.l query_y.y field_l.l field_y.y

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
## $Revision: 1.25 $
## Author          : Ulrich Pfeifer
## Created On      : Tue Mar  8 13:39:44 1994
## Last Modified By: Ulrich Pfeifer
## Last Modified On: Tue May 13 13:17:06 1997
## Language        : Makefile
## Update Count    : 191
## Status          : Unknown, Use with caution!
##
## (C) Copyright 1997, Ulrich Pfeifer, all rights reserved.
##
###############################################################################

YFLAGS = -d -l

SRCS = \
any_stemmer.c grundform.c syslog.c ircfiles.c irfileio.c irfiles.c        \
irtfiles.c irkeywords.c html_entities.c stemmer.c sockets.c transprt.c    \
wmessage.c wprot.c wutil.c zprot.c zutil.c ztype1.c soundex.c docid.c     \
list.c lock.c udping.c ir.c irretrvl.c stoplist.c irsearch.c synonym.c    \
trie.c field_index.c field_search.c ui.c sersrch.c irhash.c hash.c        \
irinv.c weight.c boolean_op.c field_l.c field_y.c query_y.c query_l.c

OBJS = \
any_stemmer.o grundform.o syslog.o ircfiles.o irfileio.o irfiles.o        \
irtfiles.o irkeywords.o html_entities.o stemmer.o sockets.o transprt.o    \
wmessage.o wprot.o wutil.o zprot.o zutil.o ztype1.o soundex.o docid.o     \
list.o lock.o udping.o ir.o irretrvl.o stoplist.o irsearch.o synonym.o    \
trie.o field_index.o field_search.o ui.o sersrch.o irhash.o hash.o        \
irinv.o weight.o boolean_op.o field_l.o field_y.o query_y.o query_l.o

all:: $(OBJS)

query_l.o: query_y.h

server: query_l.c

query_l.c: query_l.l
	$(LEX) $(JLFLAGS) query_l.l
	$(SED) -e 's/yy\(.\)/query\1/g' < lex.yy.c > query_l.c
	$(RM) lex.yy.c

local_realclean::
	$(RM) query_l.c

server: query_y.c

query_y.c: query_y.y
	$(YACC) $(JYFLAGS) query_y.y
	$(SED) -e 's/yy\(.\)/query\1/g' < y.tab.c > query_y.c
	$(SED) -e 's/yy\(.\)/query\1/g' < y.tab.h > query_y.h
	$(RM) y.tab.c y.tab.h

local_realclean::
	$(RM) query_y.c

query_y.h: query_y.c
	@if test -f y.tab.h; then \
	echo "	$(SED) -e 's/yy\(.\)/query\1/g' < y.tab.h > query_y.h"; \
	$(SED) -e 's/yy\(.\)/query\1/g' < y.tab.h > query_y.h; \
	echo "	$(RM) y.tab.h"; \
	$(RM) y.tab.h; \
	elif test -f query_y.h; then \
	echo "	$(CP) query_y.h query_y.ht"; \
	$(CP) query_y.h query_y.ht; \
	echo "	$(SED) -e 's/yy\(.\)/query\1/g' < query_y.ht > query_y.h"; \
	$(SED) -e 's/yy\(.\)/query\1/g' < query_y.ht > query_y.h; \
	echo "	$(RM) query_y.ht"; \
	$(RM) query_y.ht; \
	else \
	exit 0; \
	fi

local_realclean::
	$(RM) query_y.h

field_l.o: field_y.h

indexer: field_l.c

field_l.c: field_l.l
	$(LEX) $(JLFLAGS) field_l.l
	$(SED) -e 's/yy\(.\)/field\1/g' < lex.yy.c > field_l.c
	$(RM) lex.yy.c

local_realclean::
	$(RM) field_l.c

indexer: field_y.c

field_y.c: field_y.y
	$(YACC) $(JYFLAGS) field_y.y
	$(SED) -e 's/yy\(.\)/field\1/g' < y.tab.c > field_y.c
	$(SED) -e 's/yy\(.\)/field\1/g' < y.tab.h > field_y.h
	$(RM) y.tab.c y.tab.h

local_realclean::
	$(RM) field_y.c

field_y.h: field_y.c
	@if test -f y.tab.h; then \
	echo "	$(SED) -e 's/yy\(.\)/field\1/g' < y.tab.h > field_y.h"; \
	$(SED) -e 's/yy\(.\)/field\1/g' < y.tab.h > field_y.h; \
	echo "	$(RM) y.tab.h"; \
	$(RM) y.tab.h; \
	elif test -f field_y.h; then \
	echo "	$(CP) field_y.h field_y.ht"; \
	$(CP) field_y.h field_y.ht; \
	echo "	$(SED) -e 's/yy\(.\)/field\1/g' < field_y.ht > field_y.h"; \
	$(SED) -e 's/yy\(.\)/field\1/g' < field_y.ht > field_y.h; \
	echo "	$(RM) field_y.ht"; \
	$(RM) field_y.ht; \
	else \
	exit 0; \
	fi

local_realclean::
	$(RM) field_y.h

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

test:: test_query

test_query: query_y.c
	$(CC) -o $@ query_y.c -DTEST_QUERY $(CFLAGS) $(LDFLAGS)

########################################################################
# Common rules for all Makefiles -- do not edit

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

