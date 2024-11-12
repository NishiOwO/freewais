############################ -*- Mode: Makefile -*- ###########################
## $Basename: Imakefile.SH $
## $Revision: 1.4 $
## Author          : Jonny Goldman
## Created On      : Wed Mar  9 10:59:20 1994
## Last Modified By: Ulrich Pfeifer
## Last Modified On: Wed May  7 16:21:28 1997
## Language        : Makefile
## Update Count    : 1
## Status          : Unknown, Use with caution!
## 
## (C) Copyright 1997, Ulrich Pfeifer, all rights reserved.
## 
###############################################################################

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
: This forces SH files to create target in same directory as SH file.
: This is so that make depend always knows where to find SH derivatives.
case "$0" in
*/*) cd `expr X$0 : 'X\(.*\)/'` ;;
esac
echo "Extracting x/Imakefile (with variable substitutions)"
: This section of the file will have variable substitutions done on it.
: Move anything that needs config subs from !NO!SUBS! section to !GROK!THIS!.
: Protect any dollar signs and backticks that you do not want interpreted
: by putting a backslash in front.  You may delete these comments.
$spitshell >Imakefile <<!GROK!THIS!
BINDIR=$binexp
PRIVLIB=$installprivlib
PREFIX=$prefix
INSTALL=$install
CC=$cc
MCFLAGS=-I\$(TOP)/lib/ir $mccflags $embed_cflags
LOCAL_LDFLAGS=-L\$(TOP)/lib -lwais $socketlib -lm $embed_ldopts
!GROK!THIS!
: In the following dollars and backticks do not need the extra backslash.
$spitshell >>Imakefile <<'!NO!SUBS!'

   EXTRA_INCLUDES = $(MCFLAGS)
          VERSION = 0.86
              TOP = ..
           SRCDIR = $(TOP)/x
           SUPDIR = $(TOP)/ir
            UIDIR = $(TOP)/ui
       DEPWAISLIB = $(TOP)/lib/libwais.a
  LOCAL_LIBRARIES = $(WAISLIB) $(LOCAL_LDFLAGS) $(XAWLIB) $(XTOOLLIB) $(XMULIB) $(XLIB)
         INCLUDES = -I$(SRCDIR) -I$(SUPDIR) -I$(UIDIR) -I/usr/openwin/include
    EXTRA_DEFINES = -DUSE_ALTFONT $(CHARFLAGS) 
             TOBJ = xwais.o display.o tcommands.o scommands.o 
             QOBJ = xwaisq.o qdisplay.o text.o qcommands.o filereq.o \
	            scommands.o catalog.o myAsciiSink.o myAsciiSrc.o \
	            $(TOP)/ui/question.o $(TOP)/ui/document.o        \
	            $(TOP)/ui/wais-ui.o
             OBJS = MyList.o util.o Viewport.o $(TOP)/ui/source.o
       XWAIS_OBJS = $(TOBJ) $(OBJS) $(ISOOBJS) 
      XWAISQ_OBJS = $(QOBJ) $(OBJS) $(ISOOBJS) 
          SYSLIBS = -lm -lc
            XWAIS = xwais
           XWAISQ = xwaisq
             SRCS = MyList.c Viewport.c catalog.c display.c filereq.c \
	            myAsciiSink.c myAsciiSrc.c qcommands.c qdisplay.c \
	            scommands.c tcommands.c text.c util.c xwais.c xwaisq.c 
      XAPPLOADDIR = $(PRIVLIB)/X11/app-defaults

PROGRAMS = $(XWAIS) $(XWAISQ) Xwais.ad

AllTarget($(PROGRAMS))

NormalProgramTarget($(XWAIS),$(XWAIS_OBJS),$(WAISLIB),$(LOCAL_LIBRARIES),$(SYSLIBS))
NormalProgramTarget($(XWAISQ),$(XWAISQ_OBJS),$(WAISLIB),$(LOCAL_LIBRARIES),$(SYSLIBS))

InstallAppDefaults(Xwais)
InstallNonExec(XwaisHELP,$(PRIVLIB))
InstallNonExec(XwaisqHELP,$(PRIVLIB))
InstallProgram($(XWAIS), $(BINDIR))
InstallProgram($(XWAISQ), $(BINDIR))

CppFileTarget(Xwais.ad,Xwais.raw,-DINSTALLROOT=$(PREFIX) -DBINDIR=$(BINDIR) -DXAPPLOADDIR=$(XAPPLOADDIR),Xwais.raw)

$(TOP)/ui/question.o $(TOP)/ui/document.o $(TOP)/ui/wais-ui.o $(TOP)/ui/source.o:
	cd ../ui; $(MAKE) $@ 

$(WAISLIB):
	cd $(TOP)/lib; $(MAKE)

clean::
	$(RM) Xwais Xwais.ad Makefile.bak *%

veryclean:: clean
	$(RM) xwais xwaisq

Makefile:: Imakefile

Imakefile: Imakefile.SH
	sh Imakefile.SH

DependTarget()

!NO!SUBS!
chmod 755 Imakefile
$eunicefix Imakefile
