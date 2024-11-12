/*                               -*- Mode: C -*- 
 * $Basename: query_l.l $
 * $Revision: 1.12.1.4 $
 * Author          : Ulrich Pfeifer
 * Created On      : Tue Feb 15 16:03:22 1994
 * Last Modified By: Ulrich Pfeifer
 * Last Modified On: Mon May  5 17:27:47 1997
 * Language        : C
 * Update Count    : 110
 * Status          : Unknown, Use with caution!
 * 
 * (C) Copyright 1997, Universität Dortmund, all rights reserved.
 * 
 */

%{

#include "query_y.h"
#include "cutil.h"

#undef  ECHO
#define ECHO 
extern char* yybuf;

int prox_type;
int prox_value;
#ifdef PROXIMITY
static int recognize_proxy = 1;
#else /* PROXIMITY */
static int recognize_proxy = 0;
#endif /* PROXIMITY */

#ifdef FLEX_SCANNER
int yylineno = 0;
#define YY_SKIP_YYWRAP
#undef yywrap
#define yywrap() (1)

#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
                  { \
                  int c = *(yybuf++); \
                  if (c=='\n') yylineno++; \
                  result = (c == '\0') ? YY_NULL : (buf[0] = c, 1); \
                  }
#else /* not FLEX_SCANNER */
#undef input
#define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):*(yybuf++))==10?(yylineno++,yytchar):yytchar)=='\0'?0:yytchar)
#endif /* not FLEX_SCANNER */
/* The '/' in WORD is necessary for very odd cases, when '/' is legal char and
   is followed by numbers in the query. Dont know if this is important enough
   to exclude '/' from beeing part of a word.
*/
#ifdef SPRINGER
/* remove '-' following a digit */
char *isbn(s)
char *s;
{
  register int d = 0;
  register char *o = s;
  register char *r = s;

  while (*s) {
    if ((*s == '-') && d) {
      /* remove '-' */
      d  = 0;
    } else if (isdigit(*s)) {
      d = 1;
      *o = *s;
      o++;
    } else {
      d  = 0;
      *o = *s;
      o++;
    }
    s++;
  }
  *o = '\0';
  return(r);
}
#else
#define isbn(A) (A)
#endif
%}
WORD  [^ \t\n=()<>/]+
%x NUMBER QWEIGHT

%%

"and"|"AND"|"And" { ECHO; return(AND); }
"or"|"OR"|"Or"    { ECHO; return(OR); }
"not"|"NOT"|"Not" { ECHO; return(NOT); }
"phonix"          { ECHO; return(PHONIX);}
"soundex"         { ECHO; return(SOUNDEX);}

[pP][rR][eE]"/"/[0-9] {
                    if (!recognize_proxy) REJECT;
                    ECHO;
                    BEGIN NUMBER;
                    prox_value = 1;   /* default value of 1 */
                    prox_type  = PROX_ORDERED;
                  }
[wW]"/"/[0-9]     {
                    if (!recognize_proxy) REJECT;
                    ECHO;
                    BEGIN NUMBER;
                    prox_value = 1;   /* default value of 1 */
                    prox_type  = PROX_UNORDERED;
                  }
atleast/[0-9]+    {
                    if (!recognize_proxy) REJECT;
                    ECHO;
                    BEGIN NUMBER;
                    prox_value = 2;   /* default value of 2 */
                    prox_type  = PROX_ATLEAST;
                  }
<NUMBER>[0-9]+    { ECHO; prox_value = atoi(yytext); }
<NUMBER>")"       {
                    BEGIN INITIAL;	/* end of number, consume this char */
                    yylval.ival = prox_value;
                    return(prox_type);
                  }
<NUMBER>.         {
                    unput(yytext[0]);	/* not a number, put it back */
                    BEGIN INITIAL;
                    yylval.ival = prox_value;
                    return(prox_type);
                  }
"<*"              { ECHO; BEGIN QWEIGHT; return(ASSIGN); }
<QWEIGHT>[0-9]+(\.[0-9]+)? { 
                    ECHO; BEGIN 0; yylval.sval = s_strdup(yytext); 
                    return (FLOAT); }
[()=<>]           { ECHO; return(yytext[0]); }
[ \t\n]           { ECHO; }
{WORD}            { char *a = yytext;
                    ECHO; 
                    /* fprintf(stderr, "word?: %s\n", a); */ 
                    while (*a && (isalnum(*a) || *a == '*' || *a == '.' || *a == '-' ||  *a == '+')) {
                        a++;
                    }
                    if (*a) {
                        if (a == yytext) {
                            /* No char accepted */
                            /* fprintf(stderr, "unput: %c %s %d\n", *a, a, 1);*/
                            REJECT;
                        } else {
                            char *s = a;
                            char ch = *a;
                            /*
                            fprintf(stderr, "unput: %c %s %d\n", *a, a, 
                                    strlen(a));
                                    */
                            *a = '\0';
                            yylval.sval = s_strdup(isbn(yytext)); 
                            *a = ch;
                            yyless(strlen(yylval.sval));
                            return(WORD);
                        }
                    } else {
                        /* fprintf(stderr, "word!: %s\n", a, yytext); */
                        yylval.sval = s_strdup(isbn(yytext)); 
                        return(WORD);
                    }
                  }
\'[^']*\'         { 
                    if (recognize_proxy) REJECT;
                    yytext[0] = '"'; yytext[yyleng-1] = '"';
	            ECHO; yylval.sval = s_strdup(yytext); return(WORD);}
\"[^"]*\"         { 
                    if (recognize_proxy) REJECT;
                    ECHO; yylval.sval = s_strdup(yytext); return(WORD);}
%%
