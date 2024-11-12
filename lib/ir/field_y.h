/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or field_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int fielddebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum fieldtokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WORD = 258,                    /* WORD  */
    REGEXP = 259,                  /* REGEXP  */
    FIELD = 260,                   /* FIELD  */
    END = 261,                     /* END  */
    LAYOUT = 262,                  /* LAYOUT  */
    STEMMING = 263,                /* STEMMING  */
    ISOUNDEX = 264,                /* ISOUNDEX  */
    IPHONIX = 265,                 /* IPHONIX  */
    NUMERIC = 266,                 /* NUMERIC  */
    ITEXT = 267,                   /* ITEXT  */
    LOCAL = 268,                   /* LOCAL  */
    GLOBAL = 269,                  /* GLOBAL  */
    BOTH = 270,                    /* BOTH  */
    INT = 271,                     /* INT  */
    IGNORE = 272,                  /* IGNORE  */
    RECORD_END = 273,              /* RECORD_END  */
    HEADLINE = 274,                /* HEADLINE  */
    DATE = 275,                    /* DATE  */
    DAY = 276,                     /* DAY  */
    MONTH = 277,                   /* MONTH  */
    YEAR = 278,                    /* YEAR  */
    STRING = 279,                  /* STRING  */
    DESCRIPTION = 280              /* DESCRIPTION  */
  };
  typedef enum fieldtokentype fieldtoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define WORD 258
#define REGEXP 259
#define FIELD 260
#define END 261
#define LAYOUT 262
#define STEMMING 263
#define ISOUNDEX 264
#define IPHONIX 265
#define NUMERIC 266
#define ITEXT 267
#define LOCAL 268
#define GLOBAL 269
#define BOTH 270
#define INT 271
#define IGNORE 272
#define RECORD_END 273
#define HEADLINE 274
#define DATE 275
#define DAY 276
#define MONTH 277
#define YEAR 278
#define STRING 279
#define DESCRIPTION 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

   int  ival;
   char *sval;
   char cval;
   DateDescription date;
   


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE fieldlval;


int fieldparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
