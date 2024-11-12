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
   especially those whose name start with YY_ or field_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with field or YY, to avoid
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
#include "futil.h"
#include "field_index.h"
#include "field.h"

#define MAX_REGEXP 100
extern FILE* fieldin;
extern int fieldlineno;
extern char fieldtext[];
#ifdef YYBISON
int fielddebug;
#else /* not YYBISON */
extern int fielddebug;
#endif /* not YYBISON */
extern fields_struct** index_fields;
extern nidx_table* Ntable;   /* defined in field_index.c */
extern ltable* Ltable;       /* defined in field_index.c */

static long* field_id_set = NULL;
static long gfield_id = 0;
static long gregexp_pos = 0;
static long index_pos = 0;
static long number_of_fields_inserted = 0;
static long number_of_index_fields = 0;
static long number_of_indextypes = 0;
static long number_of_headlines = 0;
static long number_of_regexp = 0;
static long offset = 0;
static int is_headline = 0;
static int regexp_not_empty = 0;
static int fieldlist_not_empty = 0;
static int options_not_empty = 0;
static int indexspecs_not_empty = 0;
static int index_kind = 0;
static int layout_specified = 0;
static boolean global_dct_exists = false;
static boolean index_kind_both = false;
/* ------------------------------------------------------------- */

static char** regexp_set = NULL;    /* contains regexp */

static void clear_regexp _AP((long number_of_elements));
static void make_ntable _AP((long *pos));
static void make_index_fields _AP((long number_of_elements));
static void put_end_tag_ftable _AP((long field_id, 
                                    long regexp_pos));
static void put_index_fields _AP((char* field_name, 
                                  char* field_description, 
                                  long field_id,
long regexp_pos,
long index_pos,
boolean field_exists));
static void put_numeric_ftable _AP((long n_index_pos,
                                    int n_len,
                                    long field_id));
static void put_headline _AP((long begin_tag_pos,
                              long end_tag_pos,
                              long hline_begin_tag_pos,
                              long n_len,
                              long n_offset,
                              long number_of_elements));
static long Maxhealine = 0;
static long Nheadline = 0;
static void put_record_end_Ltable _AP((long regexp_pos));
static void put_hdate_ltable _AP((long begin_tag_pos,
                                  DateDescription *date_desc,
                                  long date_begin_tag_pos));
static long Maxregexp = 0;

static long insert_regexp _AP((char* regexp,
                               long number_of_elements,
                               long* regexp_pos));
static long create_index_fields _AP((FILE* stream));
static void put_indextypes _AP((char* itype,
                                int i_kind,
                                long field_id,
                                long ipos));
static void put_tags_in_gdb _AP((long field_id,
				 long begin_tag_pos,
				 long end_tag_pos, long index_pos,
				 boolean *both,
				 long *number_of_index_fields));


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
/* Symbol kind.  */
enum fieldsymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WORD = 3,                       /* WORD  */
  YYSYMBOL_REGEXP = 4,                     /* REGEXP  */
  YYSYMBOL_FIELD = 5,                      /* FIELD  */
  YYSYMBOL_END = 6,                        /* END  */
  YYSYMBOL_LAYOUT = 7,                     /* LAYOUT  */
  YYSYMBOL_STEMMING = 8,                   /* STEMMING  */
  YYSYMBOL_ISOUNDEX = 9,                   /* ISOUNDEX  */
  YYSYMBOL_IPHONIX = 10,                   /* IPHONIX  */
  YYSYMBOL_NUMERIC = 11,                   /* NUMERIC  */
  YYSYMBOL_ITEXT = 12,                     /* ITEXT  */
  YYSYMBOL_LOCAL = 13,                     /* LOCAL  */
  YYSYMBOL_GLOBAL = 14,                    /* GLOBAL  */
  YYSYMBOL_BOTH = 15,                      /* BOTH  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_IGNORE = 17,                    /* IGNORE  */
  YYSYMBOL_RECORD_END = 18,                /* RECORD_END  */
  YYSYMBOL_HEADLINE = 19,                  /* HEADLINE  */
  YYSYMBOL_DATE = 20,                      /* DATE  */
  YYSYMBOL_DAY = 21,                       /* DAY  */
  YYSYMBOL_MONTH = 22,                     /* MONTH  */
  YYSYMBOL_YEAR = 23,                      /* YEAR  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_DESCRIPTION = 25,               /* DESCRIPTION  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_docspec = 27,                   /* docspec  */
  YYSYMBOL_parseformat = 28,               /* parseformat  */
  YYSYMBOL_format = 29,                    /* format  */
  YYSYMBOL_record = 30,                    /* record  */
  YYSYMBOL_layout = 31,                    /* layout  */
  YYSYMBOL_end = 32,                       /* end  */
  YYSYMBOL_layoutspecs = 33,               /* layoutspecs  */
  YYSYMBOL_layoutspec = 34,                /* layoutspec  */
  YYSYMBOL_speclist = 35,                  /* speclist  */
  YYSYMBOL_spec = 36,                      /* spec  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_38_2 = 38,                      /* $@2  */
  YYSYMBOL_options = 39,                   /* options  */
  YYSYMBOL_option = 40,                    /* option  */
  YYSYMBOL_regexp = 41,                    /* regexp  */
  YYSYMBOL_indexspecs = 42,                /* indexspecs  */
  YYSYMBOL_indexspec = 43,                 /* indexspec  */
  YYSYMBOL_indextype = 44,                 /* indextype  */
  YYSYMBOL_dicts = 45,                     /* dicts  */
  YYSYMBOL_date_spec = 46,                 /* date_spec  */
  YYSYMBOL_date = 47,                      /* date  */
  YYSYMBOL_monthspec = 48,                 /* monthspec  */
  YYSYMBOL_descr = 49,                     /* descr  */
  YYSYMBOL_fieldlist = 50                  /* fieldlist  */
};
typedef enum fieldsymbol_kind_t fieldsymbol_kind_t;




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
typedef __INT_LEAST8_TYPE__ fieldtype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t fieldtype_int8;
#else
typedef signed char fieldtype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ fieldtype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t fieldtype_int16;
#else
typedef short fieldtype_int16;
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
typedef __UINT_LEAST8_TYPE__ fieldtype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t fieldtype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char fieldtype_uint8;
#else
typedef short fieldtype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ fieldtype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t fieldtype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short fieldtype_uint16;
#else
typedef int fieldtype_uint16;
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
typedef fieldtype_int8 field_state_t;

/* State numbers in computations.  */
typedef int field_state_fast_t;

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

/* Suppress an incorrect diagnostic about fieldlval being uninitialized.  */
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

#if !defined fieldoverflow

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
#endif /* !defined fieldoverflow */

#if (! defined fieldoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union fieldalloc
{
  field_state_t fieldss_alloc;
  YYSTYPE fieldvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union fieldalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (field_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T fieldnewbytes;                                         \
        YYCOPY (&fieldptr->Stack_alloc, Stack, fieldsize);                    \
        Stack = &fieldptr->Stack_alloc;                                    \
        fieldnewbytes = fieldstacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        fieldptr += fieldnewbytes / YYSIZEOF (*fieldptr);                        \
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
          YYPTRDIFF_T fieldi;                      \
          for (fieldi = 0; fieldi < (Count); fieldi++)   \
            (Dst)[fieldi] = (Src)[fieldi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   56

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  75

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by fieldlex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (fieldsymbol_kind_t, fieldtranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by fieldlex.  */
static const fieldtype_int8 fieldtranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const fieldtype_int16 fieldrline[] =
{
       0,   114,   114,   114,   116,   118,   120,   129,   130,   135,
     136,   139,   140,   143,   157,   177,   178,   181,   191,   180,
     272,   273,   279,   301,   310,   323,   343,   365,   366,   368,
     369,   375,   395,   396,   397,   399,   410,   421,   437,   451,
     452,   453,   456,   457,   460,   461,   464,   465
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (fieldsymbol_kind_t, fieldstos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *fieldsymbol_name (fieldsymbol_kind_t fieldsymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const fieldtname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "WORD", "REGEXP",
  "FIELD", "END", "LAYOUT", "STEMMING", "ISOUNDEX", "IPHONIX", "NUMERIC",
  "ITEXT", "LOCAL", "GLOBAL", "BOTH", "INT", "IGNORE", "RECORD_END",
  "HEADLINE", "DATE", "DAY", "MONTH", "YEAR", "STRING", "DESCRIPTION",
  "$accept", "docspec", "parseformat", "format", "record", "layout", "end",
  "layoutspecs", "layoutspec", "speclist", "spec", "$@1", "$@2", "options",
  "option", "regexp", "indexspecs", "indexspec", "indextype", "dicts",
  "date_spec", "date", "monthspec", "descr", "fieldlist", YY_NULLPTR
};

static const char *
fieldsymbol_name (fieldsymbol_kind_t fieldsymbol)
{
  return fieldtname[fieldsymbol];
}
#endif

#define YYPACT_NINF (-45)

#define fieldpact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define fieldtable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const fieldtype_int8 fieldpact[] =
{
       3,     8,    26,   -45,   -45,    23,   -45,   -45,     9,    27,
      29,    30,    25,     9,    31,   -45,    27,    32,    33,   -45,
     -45,   -45,    34,   -45,    28,   -14,    34,   -45,   -45,    34,
     -45,    17,   -45,   -14,   -45,    36,   -45,   -45,   -45,   -14,
      18,   -45,   -45,   -45,    36,    -6,   -45,   -45,    34,    34,
      38,    15,    -6,    35,    37,    -3,   -45,   -45,   -45,   -45,
      39,    15,     2,   -45,   -45,   -45,    34,    42,   -45,   -45,
     -45,   -45,   -45,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const fieldtype_int8 fielddefact[] =
{
       0,     0,     0,     2,     3,     7,     6,     1,     0,     4,
       0,     0,     9,    11,     0,     5,    15,     0,     0,    10,
       8,    12,    27,    16,     0,     0,    27,    28,    17,    27,
      39,    42,    41,     0,    13,    46,    14,    43,    40,     0,
      44,    18,    38,    45,    46,    20,    47,    24,    27,    27,
       0,    29,    20,     0,     0,     0,    23,    33,    34,    32,
       0,    29,     0,    21,    22,    25,    27,     0,    30,    36,
      35,    37,    31,    26,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const fieldtype_int8 fieldpgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,   -45,    41,   -45,    40,
     -45,   -45,   -45,    -5,   -45,   -26,   -13,   -45,   -45,   -45,
     -44,   -29,   -45,   -45,     5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const fieldtype_int8 fielddefgoto[] =
{
       0,     2,     3,     4,     5,     9,    20,    12,    13,    15,
      16,    35,    45,    51,    52,    28,    60,    61,    62,    72,
      26,    33,    38,    44,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const fieldtype_int8 fieldtable[] =
{
      34,    25,    47,    36,    39,    48,    56,    30,    31,    32,
      42,    66,     6,    49,    50,    69,    70,    71,    30,    31,
      32,     1,    53,    54,    57,    58,     7,    59,    10,    11,
       8,    19,    14,    17,    18,    22,    24,    25,    27,    40,
      73,    37,    55,    43,    29,    67,    74,    63,    68,    46,
       0,    64,     0,    65,    21,     0,    23
};

static const fieldtype_int8 fieldcheck[] =
{
      26,     4,     8,    29,    33,    11,    50,    21,    22,    23,
      39,    55,     4,    19,    20,    13,    14,    15,    21,    22,
      23,    18,    48,    49,     9,    10,     0,    12,    19,    20,
       7,     6,     5,     4,     4,     4,     4,     4,     4,     3,
      66,    24,     4,    25,    16,     6,     4,    52,    61,    44,
      -1,    16,    -1,    16,    13,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const fieldtype_int8 fieldstos[] =
{
       0,    18,    27,    28,    29,    30,     4,     0,     7,    31,
      19,    20,    33,    34,     5,    35,    36,     4,     4,     6,
      32,    33,     4,    35,     4,     4,    46,     4,    41,    16,
      21,    22,    23,    47,    41,    37,    41,    24,    48,    47,
       3,    50,    47,    25,    49,    38,    50,     8,    11,    19,
      20,    39,    40,    41,    41,     4,    46,     9,    10,    12,
      42,    43,    44,    39,    16,    16,    46,     6,    42,    13,
      14,    15,    45,    41,     4
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const fieldtype_int8 fieldr1[] =
{
       0,    26,    27,    27,    28,    29,    30,    31,    31,    32,
      32,    33,    33,    34,    34,    35,    35,    37,    38,    36,
      39,    39,    40,    40,    40,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    44,    45,    45,    45,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const fieldtype_int8 fieldr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     0,     3,     0,
       1,     1,     2,     4,     5,     1,     2,     0,     0,    10,
       0,     2,     3,     2,     1,     3,     4,     0,     1,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     1,
       2,     1,     0,     1,     0,     1,     0,     3
};


enum { YYENOMEM = -2 };

#define fielderrok         (fielderrstatus = 0)
#define fieldclearin       (fieldchar = YYEMPTY)

#define YYACCEPT        goto fieldacceptlab
#define YYABORT         goto fieldabortlab
#define YYERROR         goto fielderrorlab
#define YYNOMEM         goto fieldexhaustedlab


#define YYRECOVERING()  (!!fielderrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (fieldchar == YYEMPTY)                                        \
      {                                                           \
        fieldchar = (Token);                                         \
        fieldlval = (Value);                                         \
        YYPOPSTACK (fieldlen);                                       \
        fieldstate = *fieldssp;                                         \
        goto fieldbackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        fielderror (YY_("syntax error: cannot back up")); \
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
  if (fielddebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (fielddebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      field_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
field_symbol_value_print (FILE *fieldo,
                       fieldsymbol_kind_t fieldkind, YYSTYPE const * const fieldvaluep)
{
  FILE *fieldoutput = fieldo;
  YY_USE (fieldoutput);
  if (!fieldvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (fieldkind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
field_symbol_print (FILE *fieldo,
                 fieldsymbol_kind_t fieldkind, YYSTYPE const * const fieldvaluep)
{
  YYFPRINTF (fieldo, "%s %s (",
             fieldkind < YYNTOKENS ? "token" : "nterm", fieldsymbol_name (fieldkind));

  field_symbol_value_print (fieldo, fieldkind, fieldvaluep);
  YYFPRINTF (fieldo, ")");
}

/*------------------------------------------------------------------.
| field_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
field_stack_print (field_state_t *fieldbottom, field_state_t *fieldtop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; fieldbottom <= fieldtop; fieldbottom++)
    {
      int fieldbot = *fieldbottom;
      YYFPRINTF (stderr, " %d", fieldbot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (fielddebug)                                                  \
    field_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
field_reduce_print (field_state_t *fieldssp, YYSTYPE *fieldvsp,
                 int fieldrule)
{
  int fieldlno = fieldrline[fieldrule];
  int fieldnrhs = fieldr2[fieldrule];
  int fieldi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             fieldrule - 1, fieldlno);
  /* The symbols being reduced.  */
  for (fieldi = 0; fieldi < fieldnrhs; fieldi++)
    {
      YYFPRINTF (stderr, "   $%d = ", fieldi + 1);
      field_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+fieldssp[fieldi + 1 - fieldnrhs]),
                       &fieldvsp[(fieldi + 1) - (fieldnrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (fielddebug)                          \
    field_reduce_print (fieldssp, fieldvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int fielddebug;
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
fielddestruct (const char *fieldmsg,
            fieldsymbol_kind_t fieldkind, YYSTYPE *fieldvaluep)
{
  YY_USE (fieldvaluep);
  if (!fieldmsg)
    fieldmsg = "Deleting";
  YY_SYMBOL_PRINT (fieldmsg, fieldkind, fieldvaluep, fieldlocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (fieldkind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int fieldchar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE fieldlval;
/* Number of syntax errors so far.  */
int fieldnerrs;




/*----------.
| fieldparse.  |
`----------*/

int
fieldparse (void)
{
    field_state_fast_t fieldstate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int fielderrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow fieldoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T fieldstacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    field_state_t fieldssa[YYINITDEPTH];
    field_state_t *fieldss = fieldssa;
    field_state_t *fieldssp = fieldss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE fieldvsa[YYINITDEPTH];
    YYSTYPE *fieldvs = fieldvsa;
    YYSTYPE *fieldvsp = fieldvs;

  int fieldn;
  /* The return value of fieldparse.  */
  int fieldresult;
  /* Lookahead symbol kind.  */
  fieldsymbol_kind_t fieldtoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE fieldval;



#define YYPOPSTACK(N)   (fieldvsp -= (N), fieldssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int fieldlen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  fieldchar = YYEMPTY; /* Cause a token to be read.  */

  goto fieldsetstate;


/*------------------------------------------------------------.
| fieldnewstate -- push a new state, which is found in fieldstate.  |
`------------------------------------------------------------*/
fieldnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  fieldssp++;


/*--------------------------------------------------------------------.
| fieldsetstate -- set current state (the top of the stack) to fieldstate.  |
`--------------------------------------------------------------------*/
fieldsetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", fieldstate));
  YY_ASSERT (0 <= fieldstate && fieldstate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *fieldssp = YY_CAST (field_state_t, fieldstate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (fieldss, fieldssp);

  if (fieldss + fieldstacksize - 1 <= fieldssp)
#if !defined fieldoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T fieldsize = fieldssp - fieldss + 1;

# if defined fieldoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        field_state_t *fieldss1 = fieldss;
        YYSTYPE *fieldvs1 = fieldvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if fieldoverflow is a macro.  */
        fieldoverflow (YY_("memory exhausted"),
                    &fieldss1, fieldsize * YYSIZEOF (*fieldssp),
                    &fieldvs1, fieldsize * YYSIZEOF (*fieldvsp),
                    &fieldstacksize);
        fieldss = fieldss1;
        fieldvs = fieldvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= fieldstacksize)
        YYNOMEM;
      fieldstacksize *= 2;
      if (YYMAXDEPTH < fieldstacksize)
        fieldstacksize = YYMAXDEPTH;

      {
        field_state_t *fieldss1 = fieldss;
        union fieldalloc *fieldptr =
          YY_CAST (union fieldalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (fieldstacksize))));
        if (! fieldptr)
          YYNOMEM;
        YYSTACK_RELOCATE (fieldss_alloc, fieldss);
        YYSTACK_RELOCATE (fieldvs_alloc, fieldvs);
#  undef YYSTACK_RELOCATE
        if (fieldss1 != fieldssa)
          YYSTACK_FREE (fieldss1);
      }
# endif

      fieldssp = fieldss + fieldsize - 1;
      fieldvsp = fieldvs + fieldsize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, fieldstacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (fieldss + fieldstacksize - 1 <= fieldssp)
        YYABORT;
    }
#endif /* !defined fieldoverflow && !defined YYSTACK_RELOCATE */


  if (fieldstate == YYFINAL)
    YYACCEPT;

  goto fieldbackup;


/*-----------.
| fieldbackup.  |
`-----------*/
fieldbackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  fieldn = fieldpact[fieldstate];
  if (fieldpact_value_is_default (fieldn))
    goto fielddefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (fieldchar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      fieldchar = fieldlex ();
    }

  if (fieldchar <= YYEOF)
    {
      fieldchar = YYEOF;
      fieldtoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (fieldchar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      fieldchar = YYUNDEF;
      fieldtoken = YYSYMBOL_YYerror;
      goto fielderrlab1;
    }
  else
    {
      fieldtoken = YYTRANSLATE (fieldchar);
      YY_SYMBOL_PRINT ("Next token is", fieldtoken, &fieldlval, &fieldlloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  fieldn += fieldtoken;
  if (fieldn < 0 || YYLAST < fieldn || fieldcheck[fieldn] != fieldtoken)
    goto fielddefault;
  fieldn = fieldtable[fieldn];
  if (fieldn <= 0)
    {
      if (fieldtable_value_is_error (fieldn))
        goto fielderrlab;
      fieldn = -fieldn;
      goto fieldreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (fielderrstatus)
    fielderrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", fieldtoken, &fieldlval, &fieldlloc);
  fieldstate = fieldn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++fieldvsp = fieldlval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  fieldchar = YYEMPTY;
  goto fieldnewstate;


/*-----------------------------------------------------------.
| fielddefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
fielddefault:
  fieldn = fielddefact[fieldstate];
  if (fieldn == 0)
    goto fielderrlab;
  goto fieldreduce;


/*-----------------------------.
| fieldreduce -- do a reduction.  |
`-----------------------------*/
fieldreduce:
  /* fieldn is the number of a rule to reduce with.  */
  fieldlen = fieldr2[fieldn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  fieldval = fieldvsp[1-fieldlen];


  YY_REDUCE_PRINT (fieldn);
  switch (fieldn)
    {
  case 6: /* record: RECORD_END REGEXP  */
{
  number_of_regexp += 
      insert_regexp((fieldvsp[0].sval)+1, number_of_regexp, &gregexp_pos);

  s_free((fieldvsp[0].sval));
  put_record_end_Ltable(gregexp_pos);
}
    break;

  case 8: /* layout: LAYOUT layoutspecs end  */
                      {layout_specified = 1;}
    break;

  case 13: /* layoutspec: DATE REGEXP date_spec regexp  */
{
  long begin_tag_pos, date_begin_tag_pos;

  if((fieldvsp[0].sval) != NULL) {
      number_of_regexp += 
          insert_regexp((fieldvsp[0].sval)+1, number_of_regexp, &date_begin_tag_pos);
  } else date_begin_tag_pos = -1;
  number_of_regexp += insert_regexp((fieldvsp[-2].sval)+1,number_of_regexp,&begin_tag_pos);
  /* not all compiler can copy structs :-( */
  put_hdate_ltable(begin_tag_pos, &((fieldvsp[-1].date)), date_begin_tag_pos);
  s_free((fieldvsp[-2].sval));
  if ((fieldvsp[0].sval) != NULL) s_free((fieldvsp[0].sval));
}
    break;

  case 14: /* layoutspec: HEADLINE REGEXP REGEXP INT regexp  */
{
  long hline_begin_tag_pos, begin_tag_pos, end_tag_pos;

  if((fieldvsp[0].sval) != NULL) {
    number_of_regexp += 
        insert_regexp((fieldvsp[0].sval)+1,number_of_regexp,&hline_begin_tag_pos);
  } else hline_begin_tag_pos = -1;
  number_of_regexp += insert_regexp((fieldvsp[-3].sval)+1,number_of_regexp,&begin_tag_pos);
  number_of_regexp += insert_regexp((fieldvsp[-2].sval)+1, number_of_regexp, &end_tag_pos);
  put_headline(begin_tag_pos, end_tag_pos, hline_begin_tag_pos, 
	       (fieldvsp[-1].ival), offset, number_of_headlines);
  offset += (fieldvsp[-1].ival)+1;
  ++number_of_headlines;
  s_free((fieldvsp[-3].sval));
  s_free((fieldvsp[-2].sval));
  if ((fieldvsp[0].sval) != NULL) s_free((fieldvsp[0].sval));
}
    break;

  case 17: /* $@1: %empty  */
{
  /* insert begin_tag */

  number_of_regexp += insert_regexp((fieldvsp[-1].sval)+1, number_of_regexp, &gregexp_pos);
  if((fieldvsp[0].sval) != NULL) {
    number_of_regexp += insert_regexp((fieldvsp[0].sval)+1, number_of_regexp, &index_pos);
  } else 
      index_pos = -1;
}
    break;

  case 18: /* $@2: %empty  */
{
  if(fieldlist_not_empty == 0) {
    if(save_index_fields(NULL, &number_of_index_fields, &gfield_id)) {
      make_index_fields(number_of_index_fields);
      put_index_fields(NULL, NULL, gfield_id, gregexp_pos, index_pos, 0);
    } else 
        put_index_fields(NULL, NULL, gfield_id, gregexp_pos, index_pos, 1);
  }
}
    break;

  case 19: /* spec: FIELD REGEXP regexp $@1 fieldlist $@2 options indexspecs END REGEXP  */
{
  if (!fieldlist_not_empty && !options_not_empty && !indexspecs_not_empty) {
    long            pos;

    make_ntable (&pos);
    number_of_regexp +=
      insert_regexp ((fieldvsp[-8].sval) + 1, number_of_regexp, &gregexp_pos);
    Ntable->begin_tag_pos[pos] = gregexp_pos;
    number_of_regexp +=
      insert_regexp ((fieldvsp[0].sval) + 1, number_of_regexp, &gregexp_pos);
    Ntable->end_tag_pos[pos] = gregexp_pos;
    Ntable->position += 1;
  } else if (!fieldlist_not_empty 
             && !options_not_empty 
             && indexspecs_not_empty) {
    number_of_regexp +=
      insert_regexp ((fieldvsp[0].sval) + 1, number_of_regexp, &gregexp_pos);
    put_end_tag_ftable (gfield_id, gregexp_pos);
    global_dct_exists = true;
    number_of_indextypes = 0;
    fieldlist_not_empty = 0;
    options_not_empty = 0;
    indexspecs_not_empty = 0;
    regexp_not_empty = 0;
  } else {
    long            i, j, k;
    long            field_id;
                    /* save old value of gregexp_pos */
    long            begin_tag_pos = gregexp_pos; 

    number_of_regexp +=
      insert_regexp ((fieldvsp[0].sval) + 1, number_of_regexp, &gregexp_pos);
    if (number_of_fields_inserted > 1) {
      for (i = 0; i < number_of_fields_inserted; i++) {
	field_id = field_id_set[i];
	put_end_tag_ftable (field_id, gregexp_pos);
	if (index_kind_both) {
	  put_tags_in_gdb (field_id, begin_tag_pos, gregexp_pos,
		      index_pos, &index_kind_both, &number_of_index_fields);

	}
      }
      s_free (field_id_set);
    } else {
      put_end_tag_ftable (gfield_id, gregexp_pos);
      if (index_kind_both) {
	put_tags_in_gdb (gfield_id, begin_tag_pos, gregexp_pos,
		      index_pos, &index_kind_both, &number_of_index_fields);

      }
    }
    if (is_headline) {
      put_headline (-1, gregexp_pos, -1, 0, offset, number_of_headlines);
      ++number_of_headlines;
      is_headline = 0;
    }
    number_of_fields_inserted = 0;
    number_of_indextypes = 0;
    fieldlist_not_empty = 0;
    options_not_empty = 0;
    indexspecs_not_empty = 0;
    regexp_not_empty = 0;
  }
  s_free ((fieldvsp[-8].sval));
  s_free ((fieldvsp[0].sval));
  if ((fieldvsp[-7].sval) != NULL)
    s_free ((fieldvsp[-7].sval));
}
    break;

  case 21: /* options: option options  */
{
  options_not_empty = 1;
  (fieldval.sval) = (fieldvsp[0].sval);
}
    break;

  case 22: /* option: NUMERIC regexp INT  */
{
  long            i, field_id;

  if ((fieldvsp[-1].sval) != NULL) {
    number_of_regexp += 
        insert_regexp ((fieldvsp[-1].sval) + 1, number_of_regexp, &index_pos);
  } else
    index_pos = -1;
  if (number_of_fields_inserted > 1) {
    for (i = 0; i < number_of_fields_inserted; i++) {
      field_id = field_id_set[i];
      put_numeric_ftable (index_pos, (fieldvsp[0].ival), field_id);
      save_numeric_index_fields (field_id);
    }
  } else {
    put_numeric_ftable (index_pos, (fieldvsp[0].ival), gfield_id);
    save_numeric_index_fields (gfield_id);
  }
  if ((fieldvsp[-1].sval) != NULL)
    s_free ((fieldvsp[-1].sval));	/* (up) */
}
    break;

  case 23: /* option: DATE date_spec  */
{
    index_fields[gfield_id]->numeric = 1;
    index_fields[gfield_id]->numeric_len = 6; /* indicate date */
    index_fields[gfield_id]->is_date = true;
    memcpy(&(index_fields[gfield_id]->date_desc),
            &((fieldvsp[0].date)), sizeof(index_fields[gfield_id]->date_desc));
    save_numeric_index_fields(gfield_id);
}
    break;

  case 24: /* option: STEMMING  */
{
  long            i;
  long            field_id;

  if (number_of_fields_inserted > 1) {
    for (i = 0; i < number_of_fields_inserted; i++) {
      field_id = field_id_set[i];
      index_fields[field_id]->stemming = (fieldvsp[0].cval);
    }
  } else
    index_fields[gfield_id]->stemming = (fieldvsp[0].cval);
}
    break;

  case 25: /* option: HEADLINE regexp INT  */
{
  long         fpos = index_fields[gfield_id]->number_of_Ftable;
  long         regexp_pos = index_fields[gfield_id]->Ftable[fpos].begin_tag_pos;

  if (layout_specified) {
    fprintf (stderr, "syntax error!\nlayout has been specified\n");
    return (1);
  }
  if ((fieldvsp[-1].sval) != NULL) {
    ++((fieldvsp[-1].sval));
    number_of_regexp += 
        insert_regexp ((fieldvsp[-1].sval), number_of_regexp, &gregexp_pos);
  } else
    gregexp_pos = -1;
  put_headline (regexp_pos, -1, gregexp_pos, (fieldvsp[0].ival), offset,
		number_of_headlines);
  offset += (fieldvsp[0].ival) + 1;
  is_headline = 1;
}
    break;

  case 26: /* option: DATE REGEXP date_spec regexp  */
{
  long            regexp_pos1, regexp_pos2;

  if (layout_specified) {
    fprintf (stderr, "syntax error!\nlayout has been specified\n");
    return (1);
  }
  number_of_regexp += 
      insert_regexp ((fieldvsp[-2].sval) + 1, number_of_regexp, &regexp_pos1);
  if ((fieldvsp[0].sval) != NULL) {
    number_of_regexp +=
      insert_regexp ((fieldvsp[-1].sval) + 1, number_of_regexp, &regexp_pos2);
  } else
    regexp_pos2 = -1;
  /* not all compiler can copy structs :-( */
  put_hdate_ltable (regexp_pos1, &((fieldvsp[-1].date)), regexp_pos2);
  s_free ((fieldvsp[-2].sval));
  if ((fieldvsp[0].sval) != NULL)
    s_free ((fieldvsp[0].sval));
}
    break;

  case 27: /* regexp: %empty  */
                  {(fieldval.sval) = NULL;}
    break;

  case 28: /* regexp: REGEXP  */
                         {(fieldval.sval) =(fieldvsp[0].sval); }
    break;

  case 30: /* indexspecs: indexspec indexspecs  */
{
  indexspecs_not_empty = 1;
  (fieldval.sval) = (fieldvsp[0].sval);
}
    break;

  case 31: /* indexspec: indextype dicts  */
{
  long            i;
  long            field_id;

  /* tung: it's no good style to pass the strings from fieldlex!
     why not use the tokens ? */
  if (number_of_fields_inserted > 1) {
    for (i = 0; i < number_of_fields_inserted; i++) {
      field_id = field_id_set[i];
      put_indextypes ((fieldvsp[-1].sval), index_kind,
		      field_id, number_of_indextypes);
    }
  } else
    put_indextypes ((fieldvsp[-1].sval), index_kind,
		    gfield_id, number_of_indextypes);
  ++number_of_indextypes;
  s_free ((fieldvsp[-1].sval));
}
    break;

  case 35: /* dicts: GLOBAL  */
{
  if (fieldlist_not_empty) {
    fprintf (stderr, 
             "warning: creating fields use variable LOCAL but not GLOBAL!!!\n");
    index_kind = 1;
  } else {
    index_kind = 0;
    global_dct_exists = true;
  }
}
    break;

  case 36: /* dicts: LOCAL  */
{
  if (fieldlist_not_empty == 0) {
    fprintf (stderr, "warning: %s\n",
             "creating global database use variable GLOBAL but not LOCAL!!!");
    index_kind = 0;
    global_dct_exists = true;
  } else {
    index_kind = 1;
  }
}
    break;

  case 37: /* dicts: BOTH  */
{
  if (fieldlist_not_empty == 0) {
    fprintf (stderr, "warning: %s %s\n",
	     "creating global database use variable GLOBAL but not BOTH",
	     "or missing field name!!!");
    index_kind = 0;
    global_dct_exists = true;
  } else {
    index_kind = 2;
    global_dct_exists = true;
    index_kind_both = true;
  }
}
    break;

  case 38: /* date_spec: REGEXP date date date  */
{
    DateDescription date;
    date.sscanf_arg       = strdup((fieldvsp[-3].sval)+1); s_free((fieldvsp[-3].sval));
    date.sscanf_arg[strlen(date.sscanf_arg)-1] = '\0';
    date.order[0]  = tolower((fieldvsp[-2].cval));
    date.order[1]  = tolower((fieldvsp[-1].cval));
    date.order[2]  = tolower((fieldvsp[0].cval));
    date.month_is_string = 
        ((fieldvsp[-2].cval) == 'M') || ((fieldvsp[-1].cval) == 'M') || ((fieldvsp[0].cval) == 'M') ;
    /* not all compiler can copy structs :-( */
    memcpy(&((fieldval.date)), &date, sizeof(date));
}
    break;

  case 39: /* date: DAY  */
                                    {(fieldval.cval) = 'd';}
    break;

  case 40: /* date: MONTH monthspec  */
                                    {(fieldval.cval) = (fieldvsp[0].cval);}
    break;

  case 41: /* date: YEAR  */
                                    {(fieldval.cval) = 'y';}
    break;

  case 42: /* monthspec: %empty  */
                  {(fieldval.cval) = 'm';}
    break;

  case 43: /* monthspec: STRING  */
                         {(fieldval.cval) = 'M';}
    break;

  case 44: /* descr: %empty  */
                  {(fieldval.sval) = NULL;}
    break;

  case 45: /* descr: DESCRIPTION  */
                              {(fieldval.sval) = (fieldvsp[0].sval);}
    break;

  case 47: /* fieldlist: WORD descr fieldlist  */
{
  ++number_of_fields_inserted;
  if (number_of_fields_inserted > 1) {
    if (field_id_set == NULL) {
      field_id_set = (long *) s_malloc ((size_t) (sizeof (long) * 5));

      field_id_set[0] = gfield_id;
    } else {
      if (number_of_fields_inserted >= 5) {
	field_id_set = (long *)
	  s_realloc (field_id_set,
		(size_t) (sizeof (long) * (number_of_fields_inserted + 5)));
      }
    }
  }
  if (save_index_fields ((fieldvsp[-2].sval), &number_of_index_fields, &gfield_id)) {
    make_index_fields (number_of_index_fields);
    put_index_fields ((fieldvsp[-2].sval), (fieldvsp[-1].sval), gfield_id, gregexp_pos, index_pos, 0);
  } else
    put_index_fields ((fieldvsp[-2].sval), (fieldvsp[-1].sval), gfield_id, gregexp_pos, index_pos, 1);
  if (number_of_fields_inserted == 2)
    field_id_set[1] = gfield_id;
  else if (number_of_fields_inserted > 2)
    field_id_set[number_of_fields_inserted - 1] = gfield_id;
  fieldlist_not_empty = 1;
  (fieldval.sval) = (fieldvsp[0].sval);
  s_free ((fieldvsp[-2].sval));
  s_free ((fieldvsp[-1].sval));
}
    break;



      default: break;
    }
  /* User semantic actions sometimes alter fieldchar, and that requires
     that fieldtoken be updated with the new translation.  We take the
     approach of translating immediately before every use of fieldtoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering fieldchar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (fieldsymbol_kind_t, fieldr1[fieldn]), &fieldval, &fieldloc);

  YYPOPSTACK (fieldlen);
  fieldlen = 0;

  *++fieldvsp = fieldval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int fieldlhs = fieldr1[fieldn] - YYNTOKENS;
    const int fieldi = fieldpgoto[fieldlhs] + *fieldssp;
    fieldstate = (0 <= fieldi && fieldi <= YYLAST && fieldcheck[fieldi] == *fieldssp
               ? fieldtable[fieldi]
               : fielddefgoto[fieldlhs]);
  }

  goto fieldnewstate;


/*--------------------------------------.
| fielderrlab -- here on detecting error.  |
`--------------------------------------*/
fielderrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  fieldtoken = fieldchar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (fieldchar);
  /* If not already recovering from an error, report this error.  */
  if (!fielderrstatus)
    {
      ++fieldnerrs;
      fielderror (YY_("syntax error"));
    }

  if (fielderrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (fieldchar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (fieldchar == YYEOF)
            YYABORT;
        }
      else
        {
          fielddestruct ("Error: discarding",
                      fieldtoken, &fieldlval);
          fieldchar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto fielderrlab1;


/*---------------------------------------------------.
| fielderrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
fielderrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label fielderrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++fieldnerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (fieldlen);
  fieldlen = 0;
  YY_STACK_PRINT (fieldss, fieldssp);
  fieldstate = *fieldssp;
  goto fielderrlab1;


/*-------------------------------------------------------------.
| fielderrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
fielderrlab1:
  fielderrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      fieldn = fieldpact[fieldstate];
      if (!fieldpact_value_is_default (fieldn))
        {
          fieldn += YYSYMBOL_YYerror;
          if (0 <= fieldn && fieldn <= YYLAST && fieldcheck[fieldn] == YYSYMBOL_YYerror)
            {
              fieldn = fieldtable[fieldn];
              if (0 < fieldn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (fieldssp == fieldss)
        YYABORT;


      fielddestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (fieldstate), fieldvsp);
      YYPOPSTACK (1);
      fieldstate = *fieldssp;
      YY_STACK_PRINT (fieldss, fieldssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++fieldvsp = fieldlval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (fieldn), fieldvsp, fieldlsp);

  fieldstate = fieldn;
  goto fieldnewstate;


/*-------------------------------------.
| fieldacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
fieldacceptlab:
  fieldresult = 0;
  goto fieldreturnlab;


/*-----------------------------------.
| fieldabortlab -- YYABORT comes here.  |
`-----------------------------------*/
fieldabortlab:
  fieldresult = 1;
  goto fieldreturnlab;


/*-----------------------------------------------------------.
| fieldexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
fieldexhaustedlab:
  fielderror (YY_("memory exhausted"));
  fieldresult = 2;
  goto fieldreturnlab;


/*----------------------------------------------------------.
| fieldreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
fieldreturnlab:
  if (fieldchar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      fieldtoken = YYTRANSLATE (fieldchar);
      fielddestruct ("Cleanup: discarding lookahead",
                  fieldtoken, &fieldlval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (fieldlen);
  YY_STACK_PRINT (fieldss, fieldssp);
  while (fieldssp != fieldss)
    {
      fielddestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*fieldssp), fieldvsp);
      YYPOPSTACK (1);
    }
#ifndef fieldoverflow
  if (fieldss != fieldssa)
    YYSTACK_FREE (fieldss);
#endif

  return fieldresult;
}


extern FILE* fieldin;
extern int fieldlineno;
extern char fieldtext[];
int fielddebug;


fielderror (s)
     char           *s;
{
  fprintf (stderr, "line %d: syntax error at or near string \"%s\"\n",
	   fieldlineno+1, fieldtext);
  fprintf (stderr, "%s\n", s);
}

fieldwrap ()
{
  return (1);
}

static void 
clear_regexp (number_of_elements)
     long            number_of_elements;
{
  long            i;

  for (i = 0; i < number_of_elements; i++)
    s_free (regexp_set[i]);
  s_free (regexp_set);
}

/* ------------------------------------------------------------- */

static void 
make_ntable (pos)
     long           *pos;
{
  if (Ntable == NULL) {
    Ntable = (nidx_table *) s_malloc ((size_t) sizeof (nidx_table));
    Ntable->position = 0;
  }
  *pos = Ntable->position;
  if (Ntable->begin_tag_pos == NULL && Ntable->end_tag_pos == NULL) {
    Ntable->begin_tag_pos = (long *) s_malloc ((size_t) (sizeof (long)));
    Ntable->end_tag_pos = (long *) s_malloc ((size_t) (sizeof (long)));
  } else {
    Ntable->begin_tag_pos =
      (long *) s_realloc (Ntable->begin_tag_pos,
			  (size_t) (sizeof (long) * (Ntable->position + 1)));

    Ntable->end_tag_pos =
      (long *) s_realloc (Ntable->end_tag_pos,
			  (size_t) (sizeof (long) * (Ntable->position + 1)));
  }
}

/* ------------------------------------------------------------- */

static void 
make_index_fields (number_of_elements)
     long            number_of_elements;
{
  long            i;

  if (index_fields == NULL) {
    index_fields = (fields_struct **) s_malloc ((size_t) sizeof (fields_struct *));
    /* (up) initialize it - when you rely on zero filled records */
    bzero (index_fields, (size_t) sizeof (fields_struct *));
  } else {
    index_fields =
      (fields_struct **) s_realloc (index_fields,
				    (size_t) (sizeof (fields_struct *) *
					      number_of_elements));
    /* (up) initialize it - when you rely on zero filled records */
    bzero (&(index_fields[number_of_elements - 1]), (size_t) sizeof (fields_struct *));
  }
  for (i = 0; i < number_of_elements; i++) {
    if (index_fields[i] == NULL) {
      index_fields[i] = (fields_struct *) s_malloc ((size_t) sizeof (fields_struct));
      /* (up) initialize it - when you rely on zero filled records */
      bzero (index_fields[i], (size_t) sizeof (fields_struct));
    }
  }
  return;			/* up: redundant */
}
/* ------------------------------------------------------------- */

static void 
put_end_tag_ftable (field_id, regexp_pos)
     long            field_id;
     long            regexp_pos;
{
  long            fpos = index_fields[field_id]->number_of_Ftable;

  index_fields[field_id]->Ftable[fpos].end_tag_pos = regexp_pos;
  index_fields[field_id]->number_of_Ftable += 1;
}

/* ------------------------------------------------------------- */

static void 
put_indextypes (itype, i_kind, field_id, ipos)
     char           *itype;
     int             i_kind;
     long            field_id;
     long            ipos;
{
  long            len = strlen (itype);
  long            fpos = index_fields[field_id]->number_of_Ftable;

  if (index_fields[field_id]->Ftable[fpos].indextypes == NULL) {
    index_fields[field_id]->Ftable[fpos].indextypes =
      (char **) s_malloc ((size_t) (sizeof (char *) * NUMBER_OF_INDEXTYPES));

    index_fields[field_id]->Ftable[fpos].index_kind =
      (int *) s_malloc ((size_t) (sizeof (int) * NUMBER_OF_INDEXTYPES));
  }
  index_fields[field_id]->Ftable[fpos].indextypes[ipos] =
    (char *) s_malloc ((size_t) (sizeof (char) * (len + 2)));

  s_strncpy (index_fields[field_id]->Ftable[fpos].indextypes[ipos],
	     itype, len + 1);
  index_fields[field_id]->Ftable[fpos].index_kind[ipos] = i_kind;
}

/* ------------------------------------------------------------- */

static void 
put_index_fields (field_name, field_description,
		  field_id, regexp_pos, index_pos, field_exists)
     char           *field_name;
     char           *field_description;
     long            field_id;
     long            regexp_pos;
     long            index_pos;
     boolean         field_exists;
{
  long            fpos, flen;

  if (index_fields[field_id]->Ftable == NULL) {
    index_fields[field_id]->Ftable =
      (ftable *) s_malloc ((size_t) sizeof (ftable));
    fpos = index_fields[field_id]->number_of_Ftable;
  } else {
    index_fields[field_id]->Ftable = (ftable *)
      s_realloc (index_fields[field_id]->Ftable,
		 (size_t) (sizeof (ftable) * (index_fields[field_id]->number_of_Ftable + 1)));
    /* Tung, please: initialize memory if you rely on zero's (up) */
    bzero (index_fields[field_id]->Ftable
	   + index_fields[field_id]->number_of_Ftable,
	   sizeof (ftable));
    fpos = index_fields[field_id]->number_of_Ftable;
  }
  if (field_exists == 0) {
    if (field_name == NULL) {
      index_fields[field_id]->field_name = NULL;
      index_fields[field_id]->n_index_pos = -1;
    } else {
      flen = strlen (field_name);
      index_fields[field_id]->field_name =	/* who frees this ? (up) */
	(char *) s_malloc ((size_t) (sizeof (char) * (flen + 2)));

      s_strncpy (index_fields[field_id]->field_name, field_name, flen + 1);
      if (field_description) {
	if (index_fields[field_id]->field_description)
	  s_free (index_fields[field_id]->field_description);
	index_fields[field_id]->field_description = strdup (field_description);
      }
      index_fields[field_id]->field_id = field_id;
      index_fields[field_id]->n_index_pos = -1;
    }
    index_fields[field_id]->numeric = 0;
  }
  index_fields[field_id]->Ftable[fpos].begin_tag_pos = regexp_pos;
  index_fields[field_id]->Ftable[fpos].index_pos = index_pos;
}
/* ------------------------------------------------------------- */

static void 
put_numeric_ftable (n_index_pos, n_len, field_id)
     long            n_index_pos;
     int             n_len;
     long            field_id;
{
  long            len;

  index_fields[field_id]->numeric = 1;
  if (n_index_pos > -1)
    index_fields[field_id]->n_index_pos = n_index_pos;
  else
    index_fields[field_id]->n_index_pos = -1;
  index_fields[field_id]->numeric_len = n_len;
}

/* ------------------------------------------------------------- */

static void 
put_tags_in_gdb (field_id, begin_tag_pos, end_tag_pos,
		 index_pos, both, number_of_index_fields)
     long            field_id;
     long            begin_tag_pos;
     long            end_tag_pos;
     long            index_pos;
     long           *number_of_index_fields;
     boolean        *both;
{
  long            j, k;
  long            indextypes_number = 0;
  long            field_id_of_gdb;

  *both = false;
  j = index_fields[field_id]->number_of_Ftable - 1;

  for (k = 0; k < NUMBER_OF_INDEXTYPES; k++) {
    if (index_fields[field_id]->Ftable[j].indextypes[k] != NULL) {
      if (index_fields[field_id]->Ftable[j].index_kind[k] == 2) {
	if (save_index_fields (NULL, number_of_index_fields, &field_id_of_gdb)) {
	  make_index_fields (*number_of_index_fields);
	  put_index_fields (NULL, NULL, field_id_of_gdb, begin_tag_pos, index_pos, 0);
	} else
	  put_index_fields (NULL, NULL, field_id_of_gdb, begin_tag_pos, index_pos, 1);
	put_indextypes (index_fields[field_id]->Ftable[j].indextypes[k],
			0, field_id_of_gdb, indextypes_number);
	++indextypes_number;
	*both = true;
      }
    } else
      break;
  }
  if (*both) {
    put_end_tag_ftable (field_id_of_gdb, end_tag_pos);
    *both = false;
  }
}

/* ------------------------------------------------------------- */

static void 
put_headline (begin_tag_pos, end_tag_pos, hline_begin_tag_pos, n_len, n_offset, number_of_elements)
     long            begin_tag_pos;
     long            end_tag_pos;
     long            hline_begin_tag_pos;
     long            n_len;
     long            n_offset;
     long            number_of_elements;
{
  long            i;

  if (Ltable == NULL) {
    Ltable = (ltable *) s_malloc ((size_t) sizeof (ltable));
    Ltable->date_begin_tag_pos = -1;
    Ltable->date_tag_pos = -1;
  }
  if (Ltable->layout == NULL) {
    Maxhealine = Nheadline + 5;
    Ltable->layout =
      (layout_struct *) s_malloc ((size_t) (sizeof (layout_struct) * Maxhealine));
    for (i = 0; i < Maxhealine; i++)
      Ltable->layout[i].hline_begin_tag_pos = -1;
  } else {
    if (end_tag_pos > -1 && Nheadline == Maxhealine) {
      Maxhealine = Nheadline + 5;
      Ltable->layout = (layout_struct *)
	s_realloc (Ltable->layout, (sizeof (layout_struct) * Maxhealine));
      for (i = Nheadline; i < Maxhealine; i++)
	Ltable->layout[i].hline_begin_tag_pos = -1;
    }
  }
  if (end_tag_pos > -1 && begin_tag_pos > -1 && hline_begin_tag_pos > -1) {
    Ltable->layout[number_of_elements].begin_tag_pos = begin_tag_pos;
    Ltable->layout[number_of_elements].end_tag_pos = end_tag_pos;
    Ltable->layout[number_of_elements].hline_begin_tag_pos = hline_begin_tag_pos;
    Ltable->layout[number_of_elements].len = n_len;
    Ltable->layout[number_of_elements].offset = (n_offset == 0) ? 0 : n_offset;
    Ltable->number_of_headlines += 1;
    ++Nheadline;
  } else {
    if (end_tag_pos > -1) {
      Ltable->layout[number_of_elements].end_tag_pos = end_tag_pos;
      Ltable->number_of_headlines += 1;
      ++Nheadline;
    } else {
      if (hline_begin_tag_pos > -1) {
	Ltable->layout[number_of_elements].hline_begin_tag_pos = hline_begin_tag_pos;
      } else
	Ltable->layout[number_of_elements].hline_begin_tag_pos = -1;
      Ltable->layout[number_of_elements].begin_tag_pos = begin_tag_pos;
      Ltable->layout[number_of_elements].len = n_len;
      Ltable->layout[number_of_elements].offset = 
          (n_offset == 0) ? 0 : n_offset;
    }
  }
  return;			/* return(0); (up) */
}
/* ------------------------------------------------------------- */

static void 
put_record_end_Ltable (regexp_pos)
     long            regexp_pos;
{
  if (Ltable == NULL)
    Ltable = (ltable *) s_malloc ((size_t) sizeof (ltable));

  Ltable->date_tag_pos = -1;
  Ltable->date_begin_tag_pos = -1;
  Ltable->field_record_end_pos = regexp_pos;
  return;			/* return(0); (up) */
}

/* ------------------------------------------------------------- */

static void 
put_hdate_ltable (begin_tag_pos, date_desc, date_begin_tag_pos)
     long             begin_tag_pos;
     DateDescription *date_desc;
     long             date_begin_tag_pos;
{
  long            s_len;

  if (Ltable != NULL) {
    if (Ltable->date_desc.sscanf_arg != NULL)
      s_free (Ltable->date_desc.sscanf_arg);
    if (date_begin_tag_pos > -1)
      Ltable->date_begin_tag_pos = date_begin_tag_pos;
    else
      Ltable->date_begin_tag_pos = -1;
    Ltable->date_tag_pos = begin_tag_pos;
    memcpy(&(Ltable->date_desc), date_desc, sizeof(*date_desc));
  }
}

/* ------------------------------------------------------------- */

static long 
insert_regexp (regexp, number_of_elements, regexp_pos)
     char           *regexp;
     long            number_of_elements;
     long           *regexp_pos;
{
  long            i;
  long            len1 = strlen (regexp);
  long            len2;

  if (regexp_set == NULL) {
    Maxregexp = number_of_elements + MAX_REGEXP;
    regexp_set = (char **) s_malloc ((size_t) (sizeof (char *) * Maxregexp));
  } else {
    if (number_of_elements == Maxregexp) {
      Maxregexp = number_of_elements + 10;
      regexp_set = (char **) s_realloc (regexp_set,
				    (size_t) (sizeof (char *) * Maxregexp));
    }
  }
  for (i = 0; i < number_of_elements; i++) {
    len2 = strlen (regexp_set[i]);
    if ((len1 - 1) == len2)
      if (strncmp (regexp, regexp_set[i], len2) == 0) {
	*regexp_pos = i;
	return (0);
      }
  }
  *regexp_pos = number_of_elements;
  regexp_set[number_of_elements] = (char *) s_malloc ((size_t) (sizeof (char) * len1));

  s_strncpy (regexp_set[number_of_elements], regexp, len1);
  return (1);
}

/* ------------------------------------------------------------- */
static long 
create_index_fields (stream)
     FILE           *stream;
{
  fielddebug = 1;
  fieldin = stream;
  number_of_index_fields = 0;
  if (!fieldparse ()) {
    waislog (WLOG_LOW, WLOG_INFO, "Syntax ok\n");
  } else
    return (-1);
  number_of_indextypes = 0;
  return (number_of_index_fields);
}

/* insert all field specification.
   return -1 if error.
 */

#define format_ext ".fmt"

long 
init_add_fields (name, global_dictionary_exists, db)
     char           *name;
     boolean        *global_dictionary_exists;
     database       *db;
{
  FILE           *input_stream = NULL;
  char            file[256];
  long            number_of_fields = 0;

  s_strncpy (file, name, 255);
  s_strncat (file, format_ext, 255, 255);

  if (probe_file (file)) {
    input_stream = s_fopen (file, "r");
  }
  if (NULL == input_stream) {
    waislog (WLOG_HIGH, WLOG_ERROR,
	     "File_description %s does not exist", file);
    return (-1);
  }
  if (-1 == (number_of_fields = create_index_fields (input_stream)))
    return (-1);
  if (-1 == compile_regexp (number_of_regexp, regexp_set)) {
    fprintf (stderr, "compile regexp fails\n");
    clear_regexp (number_of_regexp);
    return (-1);
  }
  clear_regexp (number_of_regexp);
  s_fclose (input_stream);
  *global_dictionary_exists = global_dct_exists;
  db->number_of_fields = number_of_fields;
  db->index_fields = index_fields;
  return (number_of_fields);
}

/* ------------------------------------------------------------- */
