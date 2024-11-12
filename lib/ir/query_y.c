
/*  A Bison parser, made from query_y.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	WORD	258
#define	PHONIX	259
#define	SOUNDEX	260
#define	ASSIGN	261
#define	FLOAT	262
#define	OR	263
#define	AND	264
#define	NOT	265
#define	PROX_ORDERED	266
#define	PROX_UNORDERED	267
#define	PROX_ATLEAST	268


#include "cutil.h"
#include <stdio.h>
#include <ctype.h>
#define maybe_downcase(A) (A)

#define YYSTYPE querystype
#define strcatXC(A,B)  strcatCC((A),(B)),free(A)
#define strcatCX(A,B)  strcatCC((A),(B)),free(B)
#define strcatXX(A,B)  strcatCC((A),(B)),free(A),free(B)
#define strcatXXC(A,B,C) strcatCCC((A),(B),(C)),free(A),free(B)
#define strcatXCC(A,B,C) strcatCCC((A),(B),(C)),free(A)
#define strcatCCX(A,B,C) strcatCCC((A),(B),(C)),free(C)
#define strcatXXX(A,B,C) strcatCCC((A),(B),(C)),free(A),free(B),free(C)
#define strcatCXX(A,B,C) strcatCCC((A),(B),(C)),free(B),free(C)
#define strcatXCX(A,B,C) strcatCCC((A),(B),(C)),free(A),free(C)
#define strcatCCXX(A,B,C,D) strcatCCCC((A),(B),(C),(D)),free(C),free(D)
#define strcatCXCX(A,B,C,D) strcatCCCC((A),(B),(C),(D)),free(B),free(D)
#define strcatXCXX(A,B,C,D) strcatCCCC((A),(B),(C),(D)),free(A),free(C),free(D)
#define strcatXXCX(A,B,C,D) strcatCCCC((A),(B),(C),(D)),free(A),free(B),free(D)
#define strcatXXCC(A,B,C,D) strcatCCCC((A),(B),(C),(D)),free(A),free(B)

extern int querylineno;
extern char querytext[];
#ifdef YYBISON
int querydebug;
#else
extern int querydebug;
#endif
static int queryverbose = 0;
static int queryboolean = 0;
static int numeric_field = 0;
static int global_dct_exists = 0;
char *current_field;
char *querybuf;
char *queryresultstring;
#define MAX_NUM_FIELDS 100
char *field_name_array[MAX_NUM_FIELDS];
static long fields_found_this_query = 0;

extern long number_of_operands; /* defined in field_search.c */
/* char** field_name_array = NULL; */

static char * strcatCC _AP((char *w, char *wl));
static char * strcatCCC _AP((char *w, char *wl, char *op));
static char * strcatCCCC _AP((char *w, char *wl, char *op1, char *op2));

typedef union {
   int  ival;
   char *sval;
   } YYSTYPE;

#ifndef YYLTYPE
typedef
  struct queryltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  queryltype;

#define YYLTYPE queryltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		63
#define	YYFLAG		-32768
#define	YYNTBASE	19

#define YYTRANSLATE(x) ((unsigned)(x) <= 268 ? querytranslate[x] : 37)

static const char querytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    14,
    15,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    17,
    16,    18,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG != 0
static const short queryprhs[] = {     0,
     0,     2,     3,     5,     7,     9,    11,    15,    17,    21,
    23,    27,    31,    34,    36,    40,    41,    48,    49,    54,
    55,    60,    63,    65,    67,    69,    71,    73,    77,    79,
    83,    85,    89,    93,    96,    98,   102,   104,   107,   109
};

static const short queryrhs[] = {    22,
     0,     0,     8,     0,     9,     0,    10,     0,    23,     0,
    22,    20,    23,     0,    24,     0,    23,    21,    24,     0,
    25,     0,    25,    11,    25,     0,    25,    12,    25,     0,
    13,    25,     0,    36,     0,    14,    22,    15,     0,     0,
     3,    16,    26,    14,    31,    15,     0,     0,     3,    16,
    27,    36,     0,     0,     3,    29,    28,    36,     0,    16,
    16,     0,    17,     0,    18,     0,     4,     0,     5,     0,
    32,     0,    31,    20,    32,     0,    33,     0,    32,    21,
    33,     0,    34,     0,    34,    11,    34,     0,    34,    12,
    34,     0,    13,    34,     0,    36,     0,    14,    31,    15,
     0,     3,     0,    30,     3,     0,    35,     0,    35,     6,
     7,     0
};

#endif

#if YYDEBUG != 0
static const short queryrline[] = { 0,
    89,    98,    99,   102,   103,   106,   110,   121,   125,   132,
   136,   143,   150,   159,   169,   173,   174,   180,   181,   191,
   193,   223,   224,   225,   227,   228,   230,   234,   245,   249,
   256,   260,   267,   274,   283,   294,   299,   304,   318,   319
};

static const char * const querytname[] = {   "$","error","$undefined.","WORD","PHONIX",
"SOUNDEX","ASSIGN","FLOAT","OR","AND","NOT","PROX_ORDERED","PROX_UNORDERED",
"PROX_ATLEAST","'('","')'","'='","'<'","'>'","query","or","and","expression",
"term","factor","unit","@1","@2","@3","relop","phonsound","s_expression","s_term",
"s_factor","s_unit","a_unit","w_unit",""
};
#endif

static const short queryr1[] = {     0,
    19,    20,    20,    21,    21,    22,    22,    23,    23,    24,
    24,    24,    24,    25,    25,    26,    25,    27,    25,    28,
    25,    29,    29,    29,    30,    30,    31,    31,    32,    32,
    33,    33,    33,    33,    34,    34,    35,    35,    36,    36
};

static const short queryr2[] = {     0,
     1,     0,     1,     1,     1,     1,     3,     1,     3,     1,
     3,     3,     2,     1,     3,     0,     6,     0,     4,     0,
     4,     2,     1,     1,     1,     1,     1,     3,     1,     3,
     1,     3,     3,     2,     1,     3,     1,     2,     1,     3
};

static const short querydefact[] = {     0,
    37,    25,    26,     0,     0,     2,     6,     8,    10,     0,
    39,    14,    18,    23,    24,    20,    13,     2,     3,     0,
     4,     5,     0,     0,     0,    38,     0,    22,     0,     0,
     0,    15,     7,     9,    11,    12,    40,     0,    37,    19,
    21,     0,     0,     2,    27,    29,    31,    35,    34,     2,
    17,     0,     0,     0,     0,    36,    28,    30,    32,    33,
     0,     0,     0
};

static const short querydefgoto[] = {    61,
    20,    23,     6,     7,     8,     9,    29,    30,    31,    16,
    10,    44,    45,    46,    47,    11,    12
};

static const short querypact[] = {     6,
    39,-32768,-32768,    28,     6,    40,     8,-32768,    50,     4,
    15,-32768,   -11,-32768,-32768,-32768,-32768,    29,-32768,     6,
-32768,-32768,     6,    28,    28,-32768,    42,-32768,    37,    55,
    55,-32768,     8,-32768,-32768,-32768,-32768,    25,-32768,-32768,
-32768,    31,    25,    35,     8,-32768,    52,-32768,-32768,    38,
-32768,    25,    25,    31,    31,-32768,     8,-32768,-32768,-32768,
    54,    65,-32768
};

static const short querypgoto[] = {-32768,
    -3,   -41,    47,    46,    44,     2,-32768,-32768,-32768,-32768,
-32768,    26,    16,    17,   -40,-32768,   -30
};


#define	YYLAST		70


static const short querytable[] = {    40,
    41,    49,   -16,    53,    28,    17,    26,    48,     1,     2,
     3,    48,    48,    59,    60,    53,    21,    22,     4,     5,
    27,    48,    48,    48,    48,    35,    36,    39,     2,     3,
     1,     2,     3,    39,     2,     3,    19,    42,    43,    -1,
    52,     5,    19,    32,    43,    19,    52,    19,    37,    51,
    38,    18,    56,    62,    13,    14,    15,    39,     2,     3,
    24,    25,    54,    55,    63,    33,    34,    57,    50,    58
};

static const short querycheck[] = {    30,
    31,    42,    14,    45,    16,     4,     3,    38,     3,     4,
     5,    42,    43,    54,    55,    57,     9,    10,    13,    14,
     6,    52,    53,    54,    55,    24,    25,     3,     4,     5,
     3,     4,     5,     3,     4,     5,     8,    13,    14,     0,
    44,    14,     8,    15,    14,     8,    50,     8,     7,    15,
    14,     5,    15,     0,    16,    17,    18,     3,     4,     5,
    11,    12,    11,    12,     0,    20,    23,    52,    43,    53
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */


/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define queryerrok		(queryerrstatus = 0)
#define queryclearin	(querychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto queryerrlab1
/* Like YYERROR except do call queryerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto queryerrlab
#define YYRECOVERING()  (!!queryerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (querychar == YYEMPTY && querylen == 1)				\
    { querychar = (token), querylval = (value);			\
      querychar1 = YYTRANSLATE (querychar);				\
      YYPOPSTACK;						\
      goto querybackup;						\
    }								\
  else								\
    { queryerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		querylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		querylex(&querylval, &querylloc, YYLEX_PARAM)
#else
#define YYLEX		querylex(&querylval, &querylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		querylex(&querylval, YYLEX_PARAM)
#else
#define YYLEX		querylex(&querylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	querychar;			/*  the lookahead symbol		*/
YYSTYPE	querylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE querylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int querynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int querydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int queryparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __query_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__query_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__query_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into queryparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
queryparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int querystate;
  register int queryn;
  register short *queryssp;
  register YYSTYPE *queryvsp;
  int queryerrstatus;	/*  number of tokens to shift before error messages enabled */
  int querychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	queryssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE queryvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *queryss = queryssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *queryvs = queryvsa;	/*  to allow queryoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE querylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *queryls = querylsa;
  YYLTYPE *querylsp;

#define YYPOPSTACK   (queryvsp--, queryssp--, querylsp--)
#else
#define YYPOPSTACK   (queryvsp--, queryssp--)
#endif

  int querystacksize = YYINITDEPTH;

#ifdef YYPURE
  int querychar;
  YYSTYPE querylval;
  int querynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE querylloc;
#endif
#endif

  YYSTYPE queryval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int querylen;

#if YYDEBUG != 0
  if (querydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  querystate = 0;
  queryerrstatus = 0;
  querynerrs = 0;
  querychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  queryssp = queryss - 1;
  queryvsp = queryvs;
#ifdef YYLSP_NEEDED
  querylsp = queryls;
#endif

/* Push a new state, which is found in  querystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
querynewstate:

  *++queryssp = querystate;

  if (queryssp >= queryss + querystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *queryvs1 = queryvs;
      short *queryss1 = queryss;
#ifdef YYLSP_NEEDED
      YYLTYPE *queryls1 = queryls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = queryssp - queryss + 1;

#ifdef queryoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if queryoverflow is a macro.  */
      queryoverflow("parser stack overflow",
		 &queryss1, size * sizeof (*queryssp),
		 &queryvs1, size * sizeof (*queryvsp),
		 &queryls1, size * sizeof (*querylsp),
		 &querystacksize);
#else
      queryoverflow("parser stack overflow",
		 &queryss1, size * sizeof (*queryssp),
		 &queryvs1, size * sizeof (*queryvsp),
		 &querystacksize);
#endif

      queryss = queryss1; queryvs = queryvs1;
#ifdef YYLSP_NEEDED
      queryls = queryls1;
#endif
#else /* no queryoverflow */
      /* Extend the stack our own way.  */
      if (querystacksize >= YYMAXDEPTH)
	{
	  queryerror("parser stack overflow");
	  return 2;
	}
      querystacksize *= 2;
      if (querystacksize > YYMAXDEPTH)
	querystacksize = YYMAXDEPTH;
      queryss = (short *) alloca (querystacksize * sizeof (*queryssp));
      __query_memcpy ((char *)queryss1, (char *)queryss, size * sizeof (*queryssp));
      queryvs = (YYSTYPE *) alloca (querystacksize * sizeof (*queryvsp));
      __query_memcpy ((char *)queryvs1, (char *)queryvs, size * sizeof (*queryvsp));
#ifdef YYLSP_NEEDED
      queryls = (YYLTYPE *) alloca (querystacksize * sizeof (*querylsp));
      __query_memcpy ((char *)queryls1, (char *)queryls, size * sizeof (*querylsp));
#endif
#endif /* no queryoverflow */

      queryssp = queryss + size - 1;
      queryvsp = queryvs + size - 1;
#ifdef YYLSP_NEEDED
      querylsp = queryls + size - 1;
#endif

#if YYDEBUG != 0
      if (querydebug)
	fprintf(stderr, "Stack size increased to %d\n", querystacksize);
#endif

      if (queryssp >= queryss + querystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (querydebug)
    fprintf(stderr, "Entering state %d\n", querystate);
#endif

  goto querybackup;
 querybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* queryresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  queryn = querypact[querystate];
  if (queryn == YYFLAG)
    goto querydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* querychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (querychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (querydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      querychar = YYLEX;
    }

  /* Convert token to internal form (in querychar1) for indexing tables with */

  if (querychar <= 0)		/* This means end of input. */
    {
      querychar1 = 0;
      querychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (querydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      querychar1 = YYTRANSLATE(querychar);

#if YYDEBUG != 0
      if (querydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", querychar, querytname[querychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, querychar, querylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  queryn += querychar1;
  if (queryn < 0 || queryn > YYLAST || querycheck[queryn] != querychar1)
    goto querydefault;

  queryn = querytable[queryn];

  /* queryn is what to do for this token type in this state.
     Negative => reduce, -queryn is rule number.
     Positive => shift, queryn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (queryn < 0)
    {
      if (queryn == YYFLAG)
	goto queryerrlab;
      queryn = -queryn;
      goto queryreduce;
    }
  else if (queryn == 0)
    goto queryerrlab;

  if (queryn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (querydebug)
    fprintf(stderr, "Shifting token %d (%s), ", querychar, querytname[querychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (querychar != YYEOF)
    querychar = YYEMPTY;

  *++queryvsp = querylval;
#ifdef YYLSP_NEEDED
  *++querylsp = querylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (queryerrstatus) queryerrstatus--;

  querystate = queryn;
  goto querynewstate;

/* Do the default action for the current state.  */
querydefault:

  queryn = querydefact[querystate];
  if (queryn == 0)
    goto queryerrlab;

/* Do a reduction.  queryn is the number of a rule to reduce with.  */
queryreduce:
  querylen = queryr2[queryn];
  if (querylen > 0)
    queryval = queryvsp[1-querylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (querydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       queryn, queryrline[queryn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = queryprhs[queryn]; queryrhs[i] > 0; i++)
	fprintf (stderr, "%s ", querytname[queryrhs[i]]);
      fprintf (stderr, " -> %s\n", querytname[queryr1[queryn]]);
    }
#endif


  switch (queryn) {

case 1:
{
  queryresultstring = queryvsp[0].sval;    /* who calls free ? (up) */
#ifdef YYDEBUG
  if (querydebug) fprintf(stderr,"query->%s<-\n",queryresultstring);
#endif
;
    break;}
case 2:
{queryval.sval="";;
    break;}
case 3:
{queryval.sval=queryvsp[0].sval;;
    break;}
case 4:
{ queryval.sval = "and"; ;
    break;}
case 5:
{ queryval.sval = "not"; ;
    break;}
case 6:
{
                  queryval.sval = queryvsp[0].sval;
                ;
    break;}
case 7:
{
                  if (queryboolean) {
                    ++number_of_operands;
                    queryval.sval = strcatXXC(queryvsp[-2].sval, queryvsp[0].sval, "or");
                  } else {
                    queryval.sval = strcatXX(queryvsp[-2].sval, queryvsp[0].sval);
                  }
                ;
    break;}
case 8:
{
                  queryval.sval = queryvsp[0].sval;
                ;
    break;}
case 9:
{
                  ++number_of_operands;
                  queryval.sval = strcatXXC(queryvsp[-2].sval, queryvsp[0].sval, queryvsp[-1].sval);
                ;
    break;}
case 10:
{
                  queryval.sval = queryvsp[0].sval;
                ;
    break;}
case 11:
{
                  char num[80];
                  sprintf(num, "%d", queryvsp[-1].ival);
                  ++number_of_operands;
                  queryval.sval = strcatXXCC(queryvsp[-2].sval, queryvsp[0].sval, "proxordered", num);
                ;
    break;}
case 12:
{
                  char num[80];
                  sprintf(num, "%d", queryvsp[-1].ival);
                  ++number_of_operands;
                  queryval.sval = strcatXXCC(queryvsp[-2].sval, queryvsp[0].sval, "proxunordered", num);
                ;
    break;}
case 13:
{
                  char num[80];
                  sprintf(num, "%d", queryvsp[-1].ival);
                  ++number_of_operands;
                  queryval.sval = strcatXCC(queryvsp[0].sval, "proxatleast", num);
                ;
    break;}
case 14:
{
                  maybe_downcase(queryvsp[0].sval);
                  if (queryverbose) {
                    queryval.sval = strcatCCX("text", "=", queryvsp[0].sval);
                    global_dct_exists = 1;
                  } else {
                    queryval.sval = queryvsp[0].sval;
                  }
                ;
    break;}
case 15:
{
                  queryval.sval = queryvsp[-1].sval;
                ;
    break;}
case 16:
{current_field = queryvsp[-1].sval;numeric_field = 0;;
    break;}
case 17:
{
                  insert_field(current_field);
                  queryval.sval = queryvsp[-1].sval;
                  free(current_field);
                ;
    break;}
case 18:
{current_field = queryvsp[-1].sval;numeric_field = 0;;
    break;}
case 19:
{
                  maybe_downcase(queryvsp[0].sval);
                  if (queryverbose) {
                    insert_field(current_field);
                    queryval.sval = strcatXCX(current_field, "=", queryvsp[0].sval);
                  } else {
                    queryval.sval = queryvsp[0].sval;
                    free(current_field);
                  }
                ;
    break;}
case 20:
{current_field = queryvsp[-1].sval;numeric_field = 1;;
    break;}
case 21:
{
                  maybe_downcase(queryvsp[0].sval);
                  if (queryverbose) {
                    /* was soll hier eigentlich passieren ?
                       "py == 1990" => "py=" in die feldliste
                                       "py == 1990"
                       "py < 1990"  => "py" in die feldliste
                                       "py < 1990"
                       "py > 1990"  => "py" in die feldliste
                                       "py > 1990"
                    */
                    if(!strcmp(queryvsp[-2].sval, ">")) {
                      insert_field_p(current_field, ">");
                    }
                    else if(!strcmp(queryvsp[-2].sval, "<")) {
                      insert_field_p(current_field, "<");
                    }
                    else if(!strcmp(queryvsp[-2].sval, "==")) {
                      insert_field_p(current_field, "=");
                    }
                    else insert_field(current_field);
                    /* up: relop is static, so do not free it !! */
                    queryval.sval = strcatXCX(current_field, queryvsp[-2].sval, queryvsp[0].sval);
                  } else {
                    queryval.sval = queryvsp[0].sval;
                    free(current_field);
                  }
                  /* up do no free current_field twice */
                ;
    break;}
case 22:
{ queryval.sval = "=="; ;
    break;}
case 23:
{ queryval.sval = "<"; ;
    break;}
case 24:
{ queryval.sval = ">"; ;
    break;}
case 25:
{ queryval.ival = PHONIX;;
    break;}
case 26:
{ queryval.ival = SOUNDEX;;
    break;}
case 27:
{
                  queryval.sval = queryvsp[0].sval   ;
                ;
    break;}
case 28:
{
                  if (queryboolean) {
                    ++number_of_operands;
                    queryval.sval = strcatXXC(queryvsp[-2].sval, queryvsp[0].sval, "or");
                  } else {
                    queryval.sval = strcatXX(queryvsp[-2].sval, queryvsp[0].sval);
                  }
                ;
    break;}
case 29:
{
                  queryval.sval = queryvsp[0].sval;
                ;
    break;}
case 30:
{
                  ++number_of_operands;
                  queryval.sval = strcatXXC(queryvsp[-2].sval, queryvsp[0].sval, queryvsp[-1].sval);
                ;
    break;}
case 31:
{
                  queryval.sval = queryvsp[0].sval;
                ;
    break;}
case 32:
{
                  char num[80];
                  sprintf(num, "%d", queryvsp[-1].ival);
                  ++number_of_operands;
                  queryval.sval = strcatXXCC(queryvsp[-2].sval, queryvsp[0].sval, "proxordered", num);
                ;
    break;}
case 33:
{
                  char num[80];
                  sprintf(num, "%d", queryvsp[-1].ival);
                  ++number_of_operands;
                  queryval.sval = strcatXXCC(queryvsp[-2].sval, queryvsp[0].sval, "proxunordered", num);
                ;
    break;}
case 34:
{
                  char num[80];
                  sprintf(num, "%d", queryvsp[-1].ival);
                  ++number_of_operands;
                  queryval.sval = strcatXCC(queryvsp[0].sval, "proxatleast", num);
                ;
    break;}
case 35:
{
                  maybe_downcase(queryvsp[0].sval);
                  if (queryverbose) {
                    if(numeric_field) 
                      queryval.sval = strcatCCX(current_field, "==", queryvsp[0].sval);
                    else queryval.sval = strcatCCX(current_field, "=", queryvsp[0].sval);
                  } else {
                    queryval.sval = queryvsp[0].sval;
                  }
                ;
    break;}
case 36:
{
                  queryval.sval = queryvsp[-1].sval;
                ;
    break;}
case 37:
{
                    maybe_downcase(queryvsp[0].sval);
                    queryval.sval = queryvsp[0].sval;
                ;
    break;}
case 38:
{
                  static char Key[80];

                  maybe_downcase(queryvsp[0].sval);
                  if (queryvsp[-1].ival == PHONIX) {
                      Phonix(queryvsp[0].sval,Key);
                  } else {
                      Soundex(queryvsp[0].sval,Key); /* !!! (UP) */
                  }
                  s_free(queryvsp[0].sval);
                  queryval.sval = strdup(Key);
                ;
    break;}
case 39:
{ queryval.sval  = queryvsp[0].sval; ;
    break;}
case 40:
{
                  char *tmp;

                  tmp = strcatCXX("<-", queryvsp[0].sval, queryvsp[-2].sval);
                  queryval.sval = tmp;
                ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */


  queryvsp -= querylen;
  queryssp -= querylen;
#ifdef YYLSP_NEEDED
  querylsp -= querylen;
#endif

#if YYDEBUG != 0
  if (querydebug)
    {
      short *ssp1 = queryss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != queryssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++queryvsp = queryval;

#ifdef YYLSP_NEEDED
  querylsp++;
  if (querylen == 0)
    {
      querylsp->first_line = querylloc.first_line;
      querylsp->first_column = querylloc.first_column;
      querylsp->last_line = (querylsp-1)->last_line;
      querylsp->last_column = (querylsp-1)->last_column;
      querylsp->text = 0;
    }
  else
    {
      querylsp->last_line = (querylsp+querylen-1)->last_line;
      querylsp->last_column = (querylsp+querylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  queryn = queryr1[queryn];

  querystate = querypgoto[queryn - YYNTBASE] + *queryssp;
  if (querystate >= 0 && querystate <= YYLAST && querycheck[querystate] == *queryssp)
    querystate = querytable[querystate];
  else
    querystate = querydefgoto[queryn - YYNTBASE];

  goto querynewstate;

queryerrlab:   /* here on detecting error */

  if (! queryerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++querynerrs;

#ifdef YYERROR_VERBOSE
      queryn = querypact[querystate];

      if (queryn > YYFLAG && queryn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -queryn if nec to avoid negative indexes in querycheck.  */
	  for (x = (queryn < 0 ? -queryn : 0);
	       x < (sizeof(querytname) / sizeof(char *)); x++)
	    if (querycheck[x + queryn] == x)
	      size += strlen(querytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (queryn < 0 ? -queryn : 0);
		       x < (sizeof(querytname) / sizeof(char *)); x++)
		    if (querycheck[x + queryn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, querytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      queryerror(msg);
	      free(msg);
	    }
	  else
	    queryerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	queryerror("parse error");
    }

  goto queryerrlab1;
queryerrlab1:   /* here on error raised explicitly by an action */

  if (queryerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (querychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (querydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", querychar, querytname[querychar1]);
#endif

      querychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  queryerrstatus = 3;		/* Each real token shifted decrements this */

  goto queryerrhandle;

queryerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  queryn = querydefact[querystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (queryn) goto querydefault;
#endif

queryerrpop:   /* pop the current state because it cannot handle the error token */

  if (queryssp == queryss) YYABORT;
  queryvsp--;
  querystate = *--queryssp;
#ifdef YYLSP_NEEDED
  querylsp--;
#endif

#if YYDEBUG != 0
  if (querydebug)
    {
      short *ssp1 = queryss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != queryssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

queryerrhandle:

  queryn = querypact[querystate];
  if (queryn == YYFLAG)
    goto queryerrdefault;

  queryn += YYTERROR;
  if (queryn < 0 || queryn > YYLAST || querycheck[queryn] != YYTERROR)
    goto queryerrdefault;

  queryn = querytable[queryn];
  if (queryn < 0)
    {
      if (queryn == YYFLAG)
	goto queryerrpop;
      queryn = -queryn;
      goto queryreduce;
    }
  else if (queryn == 0)
    goto queryerrpop;

  if (queryn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (querydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++queryvsp = querylval;
#ifdef YYLSP_NEEDED
  *++querylsp = querylloc;
#endif

  querystate = queryn;
  goto querynewstate;
}


#if 0
void maybe_downcase(s)
char *s;
{
#ifdef NOPAIRS
    if (*s != '"')
        if (*s != '\'')
            while (*s) *s = tolower(*s),s++;
#endif
}
#endif
queryerror(s)
char *s;
{
   waislog(WLOG_HIGH, WLOG_ERROR, "line %d: %s at or near string \"%s\"\n",
           querylineno, s, querytext);
}

querywrap()
{
   return(1);
}

static char *strcatCC(w, wl)
char *w, *wl;
{
   char *wln;
   int len;

   len = strlen(w) + strlen(wl) + 2;
   wln = (char *)malloc(len);

   wln = strcpy(wln, w);
   if (strncmp(w, "prox", 4) ||
   (strstr(w, "ordered") == NULL && strstr(w, "atleast") == NULL))
     wln = strcat(wln, " ");
   wln = strcat(wln, wl);

   return(wln);
}

static char *strcatCCC(w, wl, op)
char *w, *wl, *op;
{
   char *wln;
   int len;

   len = strlen(w) + strlen(wl) + strlen(op) + 3;
   wln = (char *)malloc(len);

   wln = strcpy(wln, w);
   if ((*wl == '=') || (*wl == '<') || (*wl == '>')) {
     /* no blank */
   } else {
     wln = strcat(wln, " ");
   }
   wln = strcat(wln, wl);
   if (strncmp(wl, "prox", 4) ||
   (strstr(wl, "ordered") == NULL && strstr(wl, "atleast") == NULL))
     wln = strcat(wln, " ");
   wln = strcat(wln, op);

   return(wln);
}

static char *strcatCCCC(w, wl, op1, op2)
char *w, *wl, *op1, *op2;
{
   char *wln;
   int len;

   len = strlen(w) + strlen(wl) + strlen(op1) + strlen(op2) + 3;
   wln = (char *)malloc(len);

   wln = strcpy(wln, w);
   if ((*wl == '=') || (*wl == '<') || (*wl == '>')) {
     /* no blank */
   } else {
     wln = strcat(wln, " ");
   }
   wln = strcat(wln, wl);
   wln = strcat(wln, " ");      
   wln = strcat(wln, op1);
   if (strncmp(op1, "prox", 4) ||
   (strstr(op1, "ordered") == NULL && strstr(op1, "atleast") == NULL))
     wln = strcat(wln, " ");
   wln = strcat(wln, op2);

   return(wln);
}

int is_duplicate_field(field_name)
     char* field_name;
{
  long i = 0;
  long len = strlen(field_name);

  for (i=0;i<fields_found_this_query;i++)
    if (!strncmp(field_name, field_name_array[i], len))
      return(1); /* it is duplicate */

  return(0); /* not duplicate and field_name can inserted. */
}

int insert_field_p(field_name,c)
     char* field_name;
     char* c;
{
  char field_name_p[MAX_WORD_LENGTH+1]; 
  field_name_p[MAX_WORD_LENGTH]='\0'; /*  changed by 
                                       Vladislav Malyshkin malyshki@cs.wmich.edu
                                       on April 7, 1996 */
  strncpy(field_name_p,field_name,MAX_WORD_LENGTH);
  strncat(field_name_p,c,MAX_WORD_LENGTH);
  return(insert_field(field_name_p));
}

int insert_field(field_name)
     char* field_name;
{
  long i = 0;
  long len = strlen(field_name);

  if (fields_found_this_query > MAX_NUM_FIELDS) {
    /* overflow: should be handled with realloc ? */
    return(-1);
  }
  if (!is_duplicate_field(field_name)) {
      /* dont know why not use strdup (up)?
         field_name_array[fields_found_this_query] = strdup(field_name); 
         */
    field_name_array[fields_found_this_query] =
      (char*)malloc((size_t)((MAX_WORD_LENGTH + 1) * sizeof(char)));
    /* warn if malloc failed !! (up)*/
    strncpy(field_name_array[fields_found_this_query],field_name,MAX_WORD_LENGTH);
    fields_found_this_query++;
  }
  return(0);
}


char* analyse_string(string, number_of_fields, global_dictionary_exists)
     char* string;
     long* number_of_fields;
     int* global_dictionary_exists;
{
  int result;

  fields_found_this_query = 0;
  queryverbose = 0;
  numeric_field = 0;
  querydebug = 0;
  querybuf   = string;

  if (strchr(string,'=')) 
    queryverbose++;
  else  if (strchr(string,'>')) 
    queryverbose++;
  else if (strchr(string,'<')) queryverbose++;

  queryboolean = queryverbose || (strstr(string," and ") || strstr(string," or ")||
         strstr(string," not ") || strstr(string,"(w") ||
         strstr(string,"w/") || strstr(string,"(n") || strstr(string,"pre/"));


  if (!queryparse()) {
    field_name_array[fields_found_this_query] = NULL;
#ifdef YYDEBUG
    if (querydebug) {
      int i;
      fprintf(stderr,"Found %d fields\n", fields_found_this_query);
      for (i=0;i<fields_found_this_query;i++) {
        fprintf(stderr,"feld %d %s\n", i, 
                (field_name_array[i]==NULL)?"(nil)":field_name_array[i]);
      }
      sleep(2);
    }
#endif
    *number_of_fields = fields_found_this_query;
    *global_dictionary_exists = global_dct_exists;
    global_dct_exists = 0;
    return(queryresultstring);
  } else {
    *number_of_fields = 0;
    field_name_array[0] = NULL;
    return(NULL);
  }
}


#ifdef TEST_QUERY
long number_of_operands = 0;

int main _AP((int argc, char *argv[]));

main(argc,argv)
int argc;
char *argv[];
{
  long dummy;
  char *ptr;

  if (argc == 1) {
    char s[80];
    fprintf(stderr, ">");
    gets(s);
    while (s != NULL && *s)   {
      ptr = analyse_string(s, &dummy, &dummy);
      printf("%s => %s\n> ", s, (ptr == NULL) ? "unparseable" : ptr);
      gets(s);
    }
  } else {
    if (argc != 2) {
      fprintf(stderr, "USAGE: %s <query>\n", argv[0]);
      exit(1);
    }
    ptr = analyse_string(argv[1], &dummy, &dummy);
    printf("%s => %s\n> ", argv[1], (ptr == NULL) ? "unparseable" : ptr);
  }
  exit(0);
}
#endif
