/*                               -*- Mode: C -*- 
 * grundform.c -- 
 * ITIID           : $ITI$ $Header $__Header$
 * Author          : Ulrich Pfeifer
 * Created On      : Fri May  3 09:34:24 1996
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Fri Mar  7 16:56:49 1997
 * Language        : C
 * Update Count    : 50
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1996, Universität Dortmund, all rights reserved.
 * 
 */
#include "../config.h"
#ifdef _config_h_
#undef _config_h_
#endif
#ifndef EMBED
/* Dummy function if we don't embed */
char* grundform(word)
char *word;
{
  return(word);
}

char* stammform(word)
char *word;
{
  return(word);
}

void exit_perl(){}
#else /* EMBED */

#undef EMBED
#ifdef VOIDUSED
#undef VOIDUSED
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <EXTERN.h>
#include <perl.h>

#ifdef __cplusplus
}
#  ifndef EXTERN_C
#    define EXTERN_C extern "C"
#  endif
#else
#  ifndef EXTERN_C
#    define EXTERN_C extern
#  endif
#endif
#ifdef warn
#undef warn
#endif
#include "../defaults.h"        /* need MAX_WORD_LENGTH */

EXTERN_C void xs_init _((void));

EXTERN_C void boot_DynaLoader _((CV* cv));

EXTERN_C void
xs_init()
{
  char *file = __FILE__;

  {
    /* DynaLoader is a special case */
    newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file);
  }
}

static PerlInterpreter *my_perl;  /***    The Perl interpreter    ***/

static char*
call_reduce _((char* func, char *word));
static char*
call_reduce (func, word)
char* func;
char *word;
{
  dSP ;
  int count ;
  char *result;
  SV   *stem;
  STRLEN len;

  ENTER ;
  SAVETMPS;

  PUSHMARK(sp) ;
  XPUSHs(sv_2mortal(newSVpv(word, strlen(word))));
  XPUSHs(sv_2mortal(newSViv(1)));
  PUTBACK ;

  count = perl_call_pv(func, G_SCALAR);

  SPAGAIN ;

  if (count != 1)
    croak("Big trouble\n") ;

  result = POPp;
  len = na;
  if (len > MAX_WORD_LENGTH) {
    len = MAX_WORD_LENGTH;
  }
  (void) strncpy(word, result, len);
  word[len] = '\0';
  PUTBACK ;
  FREETMPS ;
  LEAVE ;
  return(word);
}

int perl_eval _((char *string));
int perl_eval(string)
char *string;
{
  SV* sv = sv_newmortal();
  sv_setpv(sv, string);
  perl_eval_sv(sv, G_DISCARD);
}

/*
   gcc -I/usr/local/ls6/perl/lib/sun4-sunos/5.002/CORE grundform.c -c
   gcc -o grundform grundform.o `perl -MDevel::embed -e ldopts`
*/

int my_perl_inited   = 0;
static
int my_module_loaded = 0;

void init_perl _((char **env));
void init_perl(env)
char **env;
{
  /*
  char *embedding[] = { "", "-MText::German" };
  */
  static char *embedding[] = { "", "-e", "sub _eval_ { eval $_[0] }" };
  my_perl = perl_alloc();
  perl_construct( my_perl );

  perl_parse(my_perl, NULL, 3, embedding, env);
  my_perl_inited = 1;
}


void exit_perl ()
{
  if (my_perl_inited && my_perl) {
    perl_destruct(my_perl);
    perl_free(my_perl);
    my_perl_inited   = 0;
    my_module_loaded = 0;
  }
}

void load_module ()
{
  /* perl_eval("use Text::German;"); */
  perl_require_pv("Text/German.pm");
  my_module_loaded = 1;
}

char* grundform _((char *word));
char* grundform(word)
char *word;
{
  if (!my_perl_inited)   init_perl(NULL);
  if (!my_module_loaded) load_module();
  return(call_reduce("Text::German::cache_reduce", word));
}

char* stammform _((char *word));
char* stammform(word)
char *word;
{
  if (!my_perl_inited)   init_perl(NULL);
  if (!my_module_loaded) load_module();
  return (call_reduce("Text::German::stem", word));
}

#ifdef TEST
main _((int argc, char **argv, char **env));
main (argc, argv, env)
int argc;
char **argv;
char **env;
{
  int i;

  if (argc < 1) {
    fprintf(stderr, "usage: %s <word> ...\n", argv[0]);
  }

  for (i=1;i<argc;i++) {
    char buf[255];
    strncpy(buf, argv[i], 254);
    (void) fprintf(stderr, "Text::German::reduce('%s') = ", argv[i]);
    grundform(buf);
    (void) fprintf(stderr, "%s Text::German::stem(%s) = ", buf, argv[i]);
    stammform(buf);
    (void) fprintf(stderr, "%s \n", buf);
  }
  exit_perl ();
}
#endif
 
#endif /* EMBED */
