/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or query_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with query or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

#include "cutil.h"
#include <stdio.h>
#include <ctype.h>
#define maybe_downcase(A) (A)

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


# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int querydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum querytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WORD = 258,                    /* WORD  */
    PHONIX = 259,                  /* PHONIX  */
    SOUNDEX = 260,                 /* SOUNDEX  */
    ASSIGN = 261,                  /* ASSIGN  */
    FLOAT = 262,                   /* FLOAT  */
    OR = 263,                      /* OR  */
    AND = 264,                     /* AND  */
    NOT = 265,                     /* NOT  */
    PROX_ORDERED = 266,            /* PROX_ORDERED  */
    PROX_UNORDERED = 267,          /* PROX_UNORDERED  */
    PROX_ATLEAST = 268             /* PROX_ATLEAST  */
  };
  typedef enum querytokentype querytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define WORD 258
#define PHONIX 259
#define SOUNDEX 260
#define ASSIGN 261
#define FLOAT 262
#define OR 263
#define AND 264
#define NOT 265
#define PROX_ORDERED 266
#define PROX_UNORDERED 267
#define PROX_ATLEAST 268

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

   int  ival;
   char *sval;
   


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE querylval;


int queryparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum querysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WORD = 3,                       /* WORD  */
  YYSYMBOL_PHONIX = 4,                     /* PHONIX  */
  YYSYMBOL_SOUNDEX = 5,                    /* SOUNDEX  */
  YYSYMBOL_ASSIGN = 6,                     /* ASSIGN  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_NOT = 10,                       /* NOT  */
  YYSYMBOL_PROX_ORDERED = 11,              /* PROX_ORDERED  */
  YYSYMBOL_PROX_UNORDERED = 12,            /* PROX_UNORDERED  */
  YYSYMBOL_PROX_ATLEAST = 13,              /* PROX_ATLEAST  */
  YYSYMBOL_14_ = 14,                       /* '('  */
  YYSYMBOL_15_ = 15,                       /* ')'  */
  YYSYMBOL_16_ = 16,                       /* '='  */
  YYSYMBOL_17_ = 17,                       /* '<'  */
  YYSYMBOL_18_ = 18,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 19,                  /* $accept  */
  YYSYMBOL_query = 20,                     /* query  */
  YYSYMBOL_or = 21,                        /* or  */
  YYSYMBOL_and = 22,                       /* and  */
  YYSYMBOL_expression = 23,                /* expression  */
  YYSYMBOL_term = 24,                      /* term  */
  YYSYMBOL_factor = 25,                    /* factor  */
  YYSYMBOL_unit = 26,                      /* unit  */
  YYSYMBOL_27_1 = 27,                      /* $@1  */
  YYSYMBOL_28_2 = 28,                      /* $@2  */
  YYSYMBOL_29_3 = 29,                      /* $@3  */
  YYSYMBOL_relop = 30,                     /* relop  */
  YYSYMBOL_phonsound = 31,                 /* phonsound  */
  YYSYMBOL_s_expression = 32,              /* s_expression  */
  YYSYMBOL_s_term = 33,                    /* s_term  */
  YYSYMBOL_s_factor = 34,                  /* s_factor  */
  YYSYMBOL_s_unit = 35,                    /* s_unit  */
  YYSYMBOL_a_unit = 36,                    /* a_unit  */
  YYSYMBOL_w_unit = 37                     /* w_unit  */
};
typedef enum querysymbol_kind_t querysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ querytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t querytype_int8;
#else
typedef signed char querytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ querytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t querytype_int16;
#else
typedef short querytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ querytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t querytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char querytype_uint8;
#else
typedef short querytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ querytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t querytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short querytype_uint16;
#else
typedef int querytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef querytype_int8 query_state_t;

/* State numbers in computations.  */
typedef int query_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about querylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined queryoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined queryoverflow */

#if (! defined queryoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union queryalloc
{
  query_state_t queryss_alloc;
  YYSTYPE queryvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union queryalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (query_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T querynewbytes;                                         \
        YYCOPY (&queryptr->Stack_alloc, Stack, querysize);                    \
        Stack = &queryptr->Stack_alloc;                                    \
        querynewbytes = querystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        queryptr += querynewbytes / YYSIZEOF (*queryptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T queryi;                      \
          for (queryi = 0; queryi < (Count); queryi++)   \
            (Dst)[queryi] = (Src)[queryi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   70

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   268


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by querylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (querysymbol_kind_t, querytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by querylex.  */
static const querytype_int8 querytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      14,    15,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,    16,    18,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const querytype_int16 queryrline[] =
{
       0,    88,    88,    97,    98,   101,   102,   105,   109,   120,
     124,   131,   135,   142,   149,   158,   168,   172,   172,   179,
     179,   190,   190,   222,   223,   224,   226,   227,   229,   233,
     244,   248,   255,   259,   266,   273,   282,   293,   298,   303,
     317,   318
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (querysymbol_kind_t, querystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *querysymbol_name (querysymbol_kind_t querysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const querytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "WORD", "PHONIX",
  "SOUNDEX", "ASSIGN", "FLOAT", "OR", "AND", "NOT", "PROX_ORDERED",
  "PROX_UNORDERED", "PROX_ATLEAST", "'('", "')'", "'='", "'<'", "'>'",
  "$accept", "query", "or", "and", "expression", "term", "factor", "unit",
  "$@1", "$@2", "$@3", "relop", "phonsound", "s_expression", "s_term",
  "s_factor", "s_unit", "a_unit", "w_unit", YY_NULLPTR
};

static const char *
querysymbol_name (querysymbol_kind_t querysymbol)
{
  return querytname[querysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define querypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define querytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const querytype_int8 querypact[] =
{
       6,    39,   -43,   -43,    28,     6,    21,    40,     7,   -43,
      50,     4,    43,   -43,   -11,   -43,   -43,   -43,   -43,    29,
     -43,   -43,     6,   -43,   -43,     6,    28,    28,   -43,    44,
     -43,    51,    55,    55,   -43,     7,   -43,   -43,   -43,   -43,
      25,   -43,   -43,   -43,    31,    25,    35,     7,   -43,    52,
     -43,   -43,    38,   -43,    25,    25,    31,    31,   -43,     7,
     -43,   -43,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const querytype_int8 querydefact[] =
{
       0,    38,    26,    27,     0,     0,     0,     3,     7,     9,
      11,     0,    40,    15,    19,    24,    25,    21,    14,     3,
       1,     4,     0,     5,     6,     0,     0,     0,    39,     0,
      23,     0,     0,     0,    16,     8,    10,    12,    13,    41,
       0,    38,    20,    22,     0,     0,     3,    28,    30,    32,
      36,    35,     3,    18,     0,     0,     0,     0,    37,    29,
      31,    33,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const querytype_int8 querypgoto[] =
{
     -43,   -43,    -5,   -41,    47,    32,    41,     0,   -43,   -43,
     -43,   -43,   -43,    22,    14,    15,   -42,   -43,   -32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const querytype_int8 querydefgoto[] =
{
       0,     6,    22,    25,     7,     8,     9,    10,    31,    32,
      33,    17,    11,    46,    47,    48,    49,    12,    13
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const querytype_int8 querytable[] =
{
      42,    43,    51,   -17,    18,    30,    55,    28,    50,     1,
       2,     3,    50,    50,    61,    62,    23,    24,    55,     4,
       5,    20,    50,    50,    50,    50,    37,    38,    41,     2,
       3,     1,     2,     3,    41,     2,     3,    21,    44,    45,
      -2,    54,     5,    21,    34,    45,    21,    54,    21,    29,
      53,    39,    19,    58,    35,    14,    15,    16,    41,     2,
       3,    26,    27,    56,    57,    40,    36,    52,    59,     0,
      60
};

static const querytype_int8 querycheck[] =
{
      32,    33,    44,    14,     4,    16,    47,     3,    40,     3,
       4,     5,    44,    45,    56,    57,     9,    10,    59,    13,
      14,     0,    54,    55,    56,    57,    26,    27,     3,     4,
       5,     3,     4,     5,     3,     4,     5,     8,    13,    14,
       0,    46,    14,     8,    15,    14,     8,    52,     8,     6,
      15,     7,     5,    15,    22,    16,    17,    18,     3,     4,
       5,    11,    12,    11,    12,    14,    25,    45,    54,    -1,
      55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const querytype_int8 querystos[] =
{
       0,     3,     4,     5,    13,    14,    20,    23,    24,    25,
      26,    31,    36,    37,    16,    17,    18,    30,    26,    23,
       0,     8,    21,     9,    10,    22,    11,    12,     3,     6,
      16,    27,    28,    29,    15,    24,    25,    26,    26,     7,
      14,     3,    37,    37,    13,    14,    32,    33,    34,    35,
      37,    35,    32,    15,    21,    22,    11,    12,    15,    33,
      34,    35,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const querytype_int8 queryr1[] =
{
       0,    19,    20,    21,    21,    22,    22,    23,    23,    24,
      24,    25,    25,    25,    25,    26,    26,    27,    26,    28,
      26,    29,    26,    30,    30,    30,    31,    31,    32,    32,
      33,    33,    34,    34,    34,    34,    35,    35,    36,    36,
      37,    37
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const querytype_int8 queryr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     2,     1,     3,     0,     6,     0,
       4,     0,     4,     2,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     3,     2,     1,     3,     1,     2,
       1,     3
};


enum { YYENOMEM = -2 };

#define queryerrok         (queryerrstatus = 0)
#define queryclearin       (querychar = YYEMPTY)

#define YYACCEPT        goto queryacceptlab
#define YYABORT         goto queryabortlab
#define YYERROR         goto queryerrorlab
#define YYNOMEM         goto queryexhaustedlab


#define YYRECOVERING()  (!!queryerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (querychar == YYEMPTY)                                        \
      {                                                           \
        querychar = (Token);                                         \
        querylval = (Value);                                         \
        YYPOPSTACK (querylen);                                       \
        querystate = *queryssp;                                         \
        goto querybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        queryerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (querydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (querydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      query_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
query_symbol_value_print (FILE *queryo,
                       querysymbol_kind_t querykind, YYSTYPE const * const queryvaluep)
{
  FILE *queryoutput = queryo;
  YY_USE (queryoutput);
  if (!queryvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (querykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
query_symbol_print (FILE *queryo,
                 querysymbol_kind_t querykind, YYSTYPE const * const queryvaluep)
{
  YYFPRINTF (queryo, "%s %s (",
             querykind < YYNTOKENS ? "token" : "nterm", querysymbol_name (querykind));

  query_symbol_value_print (queryo, querykind, queryvaluep);
  YYFPRINTF (queryo, ")");
}

/*------------------------------------------------------------------.
| query_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
query_stack_print (query_state_t *querybottom, query_state_t *querytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; querybottom <= querytop; querybottom++)
    {
      int querybot = *querybottom;
      YYFPRINTF (stderr, " %d", querybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (querydebug)                                                  \
    query_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
query_reduce_print (query_state_t *queryssp, YYSTYPE *queryvsp,
                 int queryrule)
{
  int querylno = queryrline[queryrule];
  int querynrhs = queryr2[queryrule];
  int queryi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             queryrule - 1, querylno);
  /* The symbols being reduced.  */
  for (queryi = 0; queryi < querynrhs; queryi++)
    {
      YYFPRINTF (stderr, "   $%d = ", queryi + 1);
      query_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+queryssp[queryi + 1 - querynrhs]),
                       &queryvsp[(queryi + 1) - (querynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (querydebug)                          \
    query_reduce_print (queryssp, queryvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int querydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
querydestruct (const char *querymsg,
            querysymbol_kind_t querykind, YYSTYPE *queryvaluep)
{
  YY_USE (queryvaluep);
  if (!querymsg)
    querymsg = "Deleting";
  YY_SYMBOL_PRINT (querymsg, querykind, queryvaluep, querylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (querykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int querychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE querylval;
/* Number of syntax errors so far.  */
int querynerrs;




/*----------.
| queryparse.  |
`----------*/

int
queryparse (void)
{
    query_state_fast_t querystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int queryerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow queryoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T querystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    query_state_t queryssa[YYINITDEPTH];
    query_state_t *queryss = queryssa;
    query_state_t *queryssp = queryss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE queryvsa[YYINITDEPTH];
    YYSTYPE *queryvs = queryvsa;
    YYSTYPE *queryvsp = queryvs;

  int queryn;
  /* The return value of queryparse.  */
  int queryresult;
  /* Lookahead symbol kind.  */
  querysymbol_kind_t querytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE queryval;



#define YYPOPSTACK(N)   (queryvsp -= (N), queryssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int querylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  querychar = YYEMPTY; /* Cause a token to be read.  */

  goto querysetstate;


/*------------------------------------------------------------.
| querynewstate -- push a new state, which is found in querystate.  |
`------------------------------------------------------------*/
querynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  queryssp++;


/*--------------------------------------------------------------------.
| querysetstate -- set current state (the top of the stack) to querystate.  |
`--------------------------------------------------------------------*/
querysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", querystate));
  YY_ASSERT (0 <= querystate && querystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *queryssp = YY_CAST (query_state_t, querystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (queryss, queryssp);

  if (queryss + querystacksize - 1 <= queryssp)
#if !defined queryoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T querysize = queryssp - queryss + 1;

# if defined queryoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        query_state_t *queryss1 = queryss;
        YYSTYPE *queryvs1 = queryvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if queryoverflow is a macro.  */
        queryoverflow (YY_("memory exhausted"),
                    &queryss1, querysize * YYSIZEOF (*queryssp),
                    &queryvs1, querysize * YYSIZEOF (*queryvsp),
                    &querystacksize);
        queryss = queryss1;
        queryvs = queryvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= querystacksize)
        YYNOMEM;
      querystacksize *= 2;
      if (YYMAXDEPTH < querystacksize)
        querystacksize = YYMAXDEPTH;

      {
        query_state_t *queryss1 = queryss;
        union queryalloc *queryptr =
          YY_CAST (union queryalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (querystacksize))));
        if (! queryptr)
          YYNOMEM;
        YYSTACK_RELOCATE (queryss_alloc, queryss);
        YYSTACK_RELOCATE (queryvs_alloc, queryvs);
#  undef YYSTACK_RELOCATE
        if (queryss1 != queryssa)
          YYSTACK_FREE (queryss1);
      }
# endif

      queryssp = queryss + querysize - 1;
      queryvsp = queryvs + querysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, querystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (queryss + querystacksize - 1 <= queryssp)
        YYABORT;
    }
#endif /* !defined queryoverflow && !defined YYSTACK_RELOCATE */


  if (querystate == YYFINAL)
    YYACCEPT;

  goto querybackup;


/*-----------.
| querybackup.  |
`-----------*/
querybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  queryn = querypact[querystate];
  if (querypact_value_is_default (queryn))
    goto querydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (querychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      querychar = querylex ();
    }

  if (querychar <= YYEOF)
    {
      querychar = YYEOF;
      querytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (querychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      querychar = YYUNDEF;
      querytoken = YYSYMBOL_YYerror;
      goto queryerrlab1;
    }
  else
    {
      querytoken = YYTRANSLATE (querychar);
      YY_SYMBOL_PRINT ("Next token is", querytoken, &querylval, &querylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  queryn += querytoken;
  if (queryn < 0 || YYLAST < queryn || querycheck[queryn] != querytoken)
    goto querydefault;
  queryn = querytable[queryn];
  if (queryn <= 0)
    {
      if (querytable_value_is_error (queryn))
        goto queryerrlab;
      queryn = -queryn;
      goto queryreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (queryerrstatus)
    queryerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", querytoken, &querylval, &querylloc);
  querystate = queryn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++queryvsp = querylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  querychar = YYEMPTY;
  goto querynewstate;


/*-----------------------------------------------------------.
| querydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
querydefault:
  queryn = querydefact[querystate];
  if (queryn == 0)
    goto queryerrlab;
  goto queryreduce;


/*-----------------------------.
| queryreduce -- do a reduction.  |
`-----------------------------*/
queryreduce:
  /* queryn is the number of a rule to reduce with.  */
  querylen = queryr2[queryn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  queryval = queryvsp[1-querylen];


  YY_REDUCE_PRINT (queryn);
  switch (queryn)
    {
  case 2: /* query: expression  */
{
  queryresultstring = (queryvsp[0].sval);    /* who calls free ? (up) */
#ifdef YYDEBUG
  if (querydebug) fprintf(stderr,"query->%s<-\n",queryresultstring);
#endif
}
    break;

  case 3: /* or: %empty  */
                           {(queryval.sval)="";}
    break;

  case 4: /* or: OR  */
                     {(queryval.sval)=(queryvsp[0].sval);}
    break;

  case 5: /* and: AND  */
                      { (queryval.sval) = "and"; }
    break;

  case 6: /* and: NOT  */
                      { (queryval.sval) = "not"; }
    break;

  case 7: /* expression: term  */
                {
                  (queryval.sval) = (queryvsp[0].sval);
                }
    break;

  case 8: /* expression: expression or term  */
                {
                  if (queryboolean) {
                    ++number_of_operands;
                    (queryval.sval) = strcatXXC((queryvsp[-2].sval), (queryvsp[0].sval), "or");
                  } else {
                    (queryval.sval) = strcatXX((queryvsp[-2].sval), (queryvsp[0].sval));
                  }
                }
    break;

  case 9: /* term: factor  */
                {
                  (queryval.sval) = (queryvsp[0].sval);
                }
    break;

  case 10: /* term: term and factor  */
                {
                  ++number_of_operands;
                  (queryval.sval) = strcatXXC((queryvsp[-2].sval), (queryvsp[0].sval), (queryvsp[-1].sval));
                }
    break;

  case 11: /* factor: unit  */
                {
                  (queryval.sval) = (queryvsp[0].sval);
                }
    break;

  case 12: /* factor: unit PROX_ORDERED unit  */
                {
                  char num[80];
                  sprintf(num, "%d", (queryvsp[-1].ival));
                  ++number_of_operands;
                  (queryval.sval) = strcatXXCC((queryvsp[-2].sval), (queryvsp[0].sval), "proxordered", num);
                }
    break;

  case 13: /* factor: unit PROX_UNORDERED unit  */
                {
                  char num[80];
                  sprintf(num, "%d", (queryvsp[-1].ival));
                  ++number_of_operands;
                  (queryval.sval) = strcatXXCC((queryvsp[-2].sval), (queryvsp[0].sval), "proxunordered", num);
                }
    break;

  case 14: /* factor: PROX_ATLEAST unit  */
                {
                  char num[80];
                  sprintf(num, "%d", (queryvsp[-1].ival));
                  ++number_of_operands;
                  (queryval.sval) = strcatXCC((queryvsp[0].sval), "proxatleast", num);
                }
    break;

  case 15: /* unit: w_unit  */
                {
                  maybe_downcase((queryvsp[0].sval));
                  if (queryverbose) {
                    (queryval.sval) = strcatCCX("text", "=", (queryvsp[0].sval));
                    global_dct_exists = 1;
                  } else {
                    (queryval.sval) = (queryvsp[0].sval);
                  }
                }
    break;

  case 16: /* unit: '(' expression ')'  */
                {
                  (queryval.sval) = (queryvsp[-1].sval);
                }
    break;

  case 17: /* $@1: %empty  */
                           {current_field = (queryvsp[-1].sval);numeric_field = 0;}
    break;

  case 18: /* unit: WORD '=' $@1 '(' s_expression ')'  */
                {
                  insert_field(current_field);
                  (queryval.sval) = (queryvsp[-1].sval);
                  free(current_field);
                }
    break;

  case 19: /* $@2: %empty  */
                           {current_field = (queryvsp[-1].sval);numeric_field = 0;}
    break;

  case 20: /* unit: WORD '=' $@2 w_unit  */
                {
                  maybe_downcase((queryvsp[0].sval));
                  if (queryverbose) {
                    insert_field(current_field);
                    (queryval.sval) = strcatXCX(current_field, "=", (queryvsp[0].sval));
                  } else {
                    (queryval.sval) = (queryvsp[0].sval);
                    free(current_field);
                  }
                }
    break;

  case 21: /* $@3: %empty  */
                             {current_field = (queryvsp[-1].sval);numeric_field = 1;}
    break;

  case 22: /* unit: WORD relop $@3 w_unit  */
                {
                  maybe_downcase((queryvsp[0].sval));
                  if (queryverbose) {
                    /* was soll hier eigentlich passieren ?
                       "py == 1990" => "py=" in die feldliste
                                       "py == 1990"
                       "py < 1990"  => "py" in die feldliste
                                       "py < 1990"
                       "py > 1990"  => "py" in die feldliste
                                       "py > 1990"
                    */
                    if(!strcmp((queryvsp[-2].sval), ">")) {
                      insert_field_p(current_field, ">");
                    }
                    else if(!strcmp((queryvsp[-2].sval), "<")) {
                      insert_field_p(current_field, "<");
                    }
                    else if(!strcmp((queryvsp[-2].sval), "==")) {
                      insert_field_p(current_field, "=");
                    }
                    else insert_field(current_field);
                    /* up: relop is static, so do not free it !! */
                    (queryval.sval) = strcatXCX(current_field, (queryvsp[-2].sval), (queryvsp[0].sval));
                  } else {
                    (queryval.sval) = (queryvsp[0].sval);
                    free(current_field);
                  }
                  /* up do no free current_field twice */
                }
    break;

  case 23: /* relop: '=' '='  */
                          { (queryval.sval) = "=="; }
    break;

  case 24: /* relop: '<'  */
                          { (queryval.sval) = "<"; }
    break;

  case 25: /* relop: '>'  */
                          { (queryval.sval) = ">"; }
    break;

  case 26: /* phonsound: PHONIX  */
                          { (queryval.ival) = PHONIX;}
    break;

  case 27: /* phonsound: SOUNDEX  */
                          { (queryval.ival) = SOUNDEX;}
    break;

  case 28: /* s_expression: s_term  */
                {
                  (queryval.sval) = (queryvsp[0].sval)   ;
                }
    break;

  case 29: /* s_expression: s_expression or s_term  */
                {
                  if (queryboolean) {
                    ++number_of_operands;
                    (queryval.sval) = strcatXXC((queryvsp[-2].sval), (queryvsp[0].sval), "or");
                  } else {
                    (queryval.sval) = strcatXX((queryvsp[-2].sval), (queryvsp[0].sval));
                  }
                }
    break;

  case 30: /* s_term: s_factor  */
                {
                  (queryval.sval) = (queryvsp[0].sval);
                }
    break;

  case 31: /* s_term: s_term and s_factor  */
                {
                  ++number_of_operands;
                  (queryval.sval) = strcatXXC((queryvsp[-2].sval), (queryvsp[0].sval), (queryvsp[-1].sval));
                }
    break;

  case 32: /* s_factor: s_unit  */
                {
                  (queryval.sval) = (queryvsp[0].sval);
                }
    break;

  case 33: /* s_factor: s_unit PROX_ORDERED s_unit  */
                {
                  char num[80];
                  sprintf(num, "%d", (queryvsp[-1].ival));
                  ++number_of_operands;
                  (queryval.sval) = strcatXXCC((queryvsp[-2].sval), (queryvsp[0].sval), "proxordered", num);
                }
    break;

  case 34: /* s_factor: s_unit PROX_UNORDERED s_unit  */
                {
                  char num[80];
                  sprintf(num, "%d", (queryvsp[-1].ival));
                  ++number_of_operands;
                  (queryval.sval) = strcatXXCC((queryvsp[-2].sval), (queryvsp[0].sval), "proxunordered", num);
                }
    break;

  case 35: /* s_factor: PROX_ATLEAST s_unit  */
                {
                  char num[80];
                  sprintf(num, "%d", (queryvsp[-1].ival));
                  ++number_of_operands;
                  (queryval.sval) = strcatXCC((queryvsp[0].sval), "proxatleast", num);
                }
    break;

  case 36: /* s_unit: w_unit  */
                {
                  maybe_downcase((queryvsp[0].sval));
                  if (queryverbose) {
                    if(numeric_field) 
                      (queryval.sval) = strcatCCX(current_field, "==", (queryvsp[0].sval));
                    else (queryval.sval) = strcatCCX(current_field, "=", (queryvsp[0].sval));
                  } else {
                    (queryval.sval) = (queryvsp[0].sval);
                  }
                }
    break;

  case 37: /* s_unit: '(' s_expression ')'  */
                {
                  (queryval.sval) = (queryvsp[-1].sval);
                }
    break;

  case 38: /* a_unit: WORD  */
                {
                    maybe_downcase((queryvsp[0].sval));
                    (queryval.sval) = (queryvsp[0].sval);
                }
    break;

  case 39: /* a_unit: phonsound WORD  */
                {
                  static char Key[80];

                  maybe_downcase((queryvsp[0].sval));
                  if ((queryvsp[-1].ival) == PHONIX) {
                      Phonix((queryvsp[0].sval),Key);
                  } else {
                      Soundex((queryvsp[0].sval),Key); /* !!! (UP) */
                  }
                  s_free((queryvsp[0].sval));
                  (queryval.sval) = strdup(Key);
                }
    break;

  case 40: /* w_unit: a_unit  */
                         { (queryval.sval)  = (queryvsp[0].sval); }
    break;

  case 41: /* w_unit: a_unit ASSIGN FLOAT  */
                {
                  char *tmp;

                  tmp = strcatCXX("<-", (queryvsp[0].sval), (queryvsp[-2].sval));
                  (queryval.sval) = tmp;
                }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter querychar, and that requires
     that querytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of querytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering querychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (querysymbol_kind_t, queryr1[queryn]), &queryval, &queryloc);

  YYPOPSTACK (querylen);
  querylen = 0;

  *++queryvsp = queryval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int querylhs = queryr1[queryn] - YYNTOKENS;
    const int queryi = querypgoto[querylhs] + *queryssp;
    querystate = (0 <= queryi && queryi <= YYLAST && querycheck[queryi] == *queryssp
               ? querytable[queryi]
               : querydefgoto[querylhs]);
  }

  goto querynewstate;


/*--------------------------------------.
| queryerrlab -- here on detecting error.  |
`--------------------------------------*/
queryerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  querytoken = querychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (querychar);
  /* If not already recovering from an error, report this error.  */
  if (!queryerrstatus)
    {
      ++querynerrs;
      queryerror (YY_("syntax error"));
    }

  if (queryerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (querychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (querychar == YYEOF)
            YYABORT;
        }
      else
        {
          querydestruct ("Error: discarding",
                      querytoken, &querylval);
          querychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto queryerrlab1;


/*---------------------------------------------------.
| queryerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
queryerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label queryerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++querynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (querylen);
  querylen = 0;
  YY_STACK_PRINT (queryss, queryssp);
  querystate = *queryssp;
  goto queryerrlab1;


/*-------------------------------------------------------------.
| queryerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
queryerrlab1:
  queryerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      queryn = querypact[querystate];
      if (!querypact_value_is_default (queryn))
        {
          queryn += YYSYMBOL_YYerror;
          if (0 <= queryn && queryn <= YYLAST && querycheck[queryn] == YYSYMBOL_YYerror)
            {
              queryn = querytable[queryn];
              if (0 < queryn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (queryssp == queryss)
        YYABORT;


      querydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (querystate), queryvsp);
      YYPOPSTACK (1);
      querystate = *queryssp;
      YY_STACK_PRINT (queryss, queryssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++queryvsp = querylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (queryn), queryvsp, querylsp);

  querystate = queryn;
  goto querynewstate;


/*-------------------------------------.
| queryacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
queryacceptlab:
  queryresult = 0;
  goto queryreturnlab;


/*-----------------------------------.
| queryabortlab -- YYABORT comes here.  |
`-----------------------------------*/
queryabortlab:
  queryresult = 1;
  goto queryreturnlab;


/*-----------------------------------------------------------.
| queryexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
queryexhaustedlab:
  queryerror (YY_("memory exhausted"));
  queryresult = 2;
  goto queryreturnlab;


/*----------------------------------------------------------.
| queryreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
queryreturnlab:
  if (querychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      querytoken = YYTRANSLATE (querychar);
      querydestruct ("Cleanup: discarding lookahead",
                  querytoken, &querylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (querylen);
  YY_STACK_PRINT (queryss, queryssp);
  while (queryssp != queryss)
    {
      querydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*queryssp), queryvsp);
      YYPOPSTACK (1);
    }
#ifndef queryoverflow
  if (queryss != queryssa)
    YYSTACK_FREE (queryss);
#endif

  return queryresult;
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
