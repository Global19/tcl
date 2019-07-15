/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         TclDateparse
#define yylex           TclDatelex
#define yyerror         TclDateerror
#define yydebug         TclDatedebug
#define yynerrs         TclDatenerrs


/* Copy the first part of user declarations.  */


/*
 * tclDate.c --
 *
 *	This file is generated from a yacc grammar defined in the file
 *	tclGetDate.y. It should not be edited directly.
 *
 * Copyright (c) 1992-1995 Karl Lehenbauer and Mark Diekhans.
 * Copyright (c) 1995-1997 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 */
#include "tclInt.h"

/*
 * Bison generates several labels that happen to be unused. MS Visual C++
 * doesn't like that, and complains. Tell it to shut up.
 */

#ifdef _MSC_VER
#pragma warning( disable : 4102 )
#endif /* _MSC_VER */

#if 0
#define YYDEBUG 1
#endif

/*
 * yyparse will accept a 'struct DateInfo' as its parameter; that's where the
 * parsed fields will be returned.
 */

#include "tclDate.h"

#define YYMALLOC	ckalloc
#define YYFREE(x)	(ckfree((void*) (x)))

#define EPOCH		1970
#define START_OF_TIME	1902
#define END_OF_TIME	2037

/*
 * The offset of tm_year of struct tm returned by localtime, gmtime, etc.
 * Posix requires 1900.
 */

#define TM_YEAR_BASE	1900

#define HOUR(x)		((int) (60 * x))
#define SECSPERDAY	(24L * 60L * 60L)
#define IsLeapYear(x)	((x % 4 == 0) && (x % 100 != 0 || x % 400 == 0))

#define yyIncrFlags(f)				\
    do {					\
	info->errFlags |= (info->flags & (f));	\
	if (info->errFlags) { YYABORT; }	\
	info->flags |= (f);			\
    } while (0);

/*
 * An entry in the lexical lookup table.
 */

typedef struct _TABLE {
    const char *name;
    int type;
    time_t value;
} TABLE;

/*
 * Daylight-savings mode: on, off, or not yet known.
 */

typedef enum _DSTMODE {
    DSTon, DSToff, DSTmaybe
} DSTMODE;




# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int TclDatedebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tAGO = 258,
    tDAY = 259,
    tDAYZONE = 260,
    tID = 261,
    tMERIDIAN = 262,
    tMONTH = 263,
    tMONTH_UNIT = 264,
    tSTARDATE = 265,
    tSEC_UNIT = 266,
    tUNUMBER = 267,
    tZONE = 268,
    tZONEwO4 = 269,
    tZONEwO2 = 270,
    tEPOCH = 271,
    tDST = 272,
    tISOBASE = 273,
    tDAY_UNIT = 274,
    tNEXT = 275,
    SP = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


    time_t Number;
    enum _MERIDIAN Meridian;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int TclDateparse (DateInfo* info);



/* Copy the second part of user declarations.  */



/*
 * Prototypes of internal functions.
 */

static int		LookupWord(YYSTYPE* yylvalPtr, char *buff);
 static void		TclDateerror(YYLTYPE* location,
				     DateInfo* info, const char *s);
 static int		TclDatelex(YYSTYPE* yylvalPtr, YYLTYPE* location,
				   DateInfo* info);
MODULE_SCOPE int	yyparse(DateInfo*);




#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,    23,    25,    26,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   168,   169,   172,   175,   178,   181,   184,
     187,   190,   193,   197,   200,   206,   212,   220,   224,   228,
     232,   236,   240,   246,   247,   250,   254,   258,   262,   266,
     270,   276,   280,   285,   290,   295,   300,   304,   309,   313,
     318,   325,   329,   335,   344,   352,   360,   369,   379,   393,
     398,   401,   404,   407,   410,   413,   416,   421,   424,   429,
     433,   437,   443,   446,   451,   469,   472
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAGO", "tDAY", "tDAYZONE", "tID",
  "tMERIDIAN", "tMONTH", "tMONTH_UNIT", "tSTARDATE", "tSEC_UNIT",
  "tUNUMBER", "tZONE", "tZONEwO4", "tZONEwO2", "tEPOCH", "tDST",
  "tISOBASE", "tDAY_UNIT", "tNEXT", "SP", "':'", "','", "'/'", "'-'",
  "'.'", "'+'", "$accept", "spec", "item", "time", "zone", "comma", "day",
  "date", "ordMonth", "iso", "trek", "relspec", "relunits", "sign", "unit",
  "INTNUM", "number", "o_merid", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    58,    44,    47,    45,    46,    43
};
# endif

#define YYPACT_NINF -17

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-17)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -17,    48,   -17,    -9,   -17,    34,   -17,    19,   -17,    -2,
      30,   -10,   -10,   -17,     8,   -17,     0,    72,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,    52,
      18,   -17,    16,   -17,    49,   -17,    -9,   -17,   -17,    25,
     -17,   -17,    59,    60,    62,    -5,   -17,    19,    19,    20,
     -17,    31,   -17,   -17,    70,   -17,    16,   -17,   -17,    75,
      32,    16,   -17,   -17,    77,    81,   -17,     6,    71,    69,
      73,   -17,   -17,    74,   -17,    78,   -17,   -17,   -17,   -17,
      97,    16,   -17,   -17,   -17,   -17,    90,   -17,    91,    92,
      93,    94,    95,   -17,   -17,   101,   -17,   -17,   -17,    87,
      88,   -17,    99,   100,   -17,   -17
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    25,    19,     0,    61,     0,    59,    62,
      18,     0,     0,    39,    33,    60,     0,     0,    57,    58,
       3,     5,     6,     9,     7,     8,    11,    12,    10,    50,
       0,    56,    64,    13,    23,    26,    36,    62,    63,     0,
      27,    14,    38,     0,     0,     0,    17,     0,     0,     0,
      44,     0,    30,    41,    62,    54,     0,     4,    49,    62,
       0,    22,    53,    24,     0,     0,    40,    65,    31,     0,
       0,    20,    21,     0,    43,     0,    47,    42,    55,    29,
      62,     0,    52,    37,    48,    66,     0,    15,     0,     0,
       0,     0,     0,    28,    51,    65,    32,    34,    35,     0,
       0,    16,     0,     0,    46,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,    96,   -17,   -17,    79,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,    22,   -16,    -6,   -17,    21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    20,    21,    22,    35,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    39,    40,    69,    52,    41,    42,    70,    53,     6,
      56,     8,    54,    85,    34,    18,    62,    19,    38,    15,
      43,    49,    44,    45,    61,     6,    50,     8,    86,    51,
      59,    37,    73,    47,    48,    15,    38,    38,    74,    60,
      78,    71,    72,    75,    80,    82,    36,    46,     2,    76,
      38,    65,     3,     4,    81,    58,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    94,    14,    15,    16,    17,
      63,    66,    67,    18,    68,    19,     3,     4,    77,    79,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    83,
      14,    15,    16,    84,    89,    88,    91,    18,    90,    19,
      92,    93,    95,    96,    97,    98,    99,   100,    85,   102,
     103,   104,   105,    57,     0,    64,   101
};

static const yytype_int8 yycheck[] =
{
      16,     7,     4,     8,     4,     7,     8,    12,     8,     9,
      16,    11,    12,     7,    23,    25,    32,    27,    18,    19,
      22,    13,    24,    25,    30,     9,    18,    11,    22,    21,
      12,    12,    12,    11,    12,    19,    18,    18,    18,    21,
      56,    47,    48,    12,    12,    61,    12,    17,     0,    18,
      18,    26,     4,     5,    60,     3,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    81,    18,    19,    20,    21,
      21,    12,    12,    25,    12,    27,     4,     5,     8,     4,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    12,
      18,    19,    20,    12,    25,    24,    22,    25,    25,    27,
      22,     4,    12,    12,    12,    12,    12,    12,     7,    22,
      22,    12,    12,    17,    -1,    36,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,     0,     4,     5,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    18,    19,    20,    21,    25,    27,
      30,    31,    32,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    23,    33,    12,    12,    18,    43,
       4,     7,     8,    22,    24,    25,    17,    41,    41,    13,
      18,    21,     4,     8,    12,    42,    43,    30,     3,    12,
      21,    43,    42,    21,    33,    26,    12,    12,    12,     8,
      12,    43,    43,    12,    18,    12,    18,     8,    42,     4,
      12,    43,    42,    12,    12,     7,    22,    45,    24,    25,
      25,    22,    22,     4,    42,    12,    12,    12,    12,    12,
      12,    45,    22,    22,    12,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    29,    29,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    31,    31,    31,    32,    32,    32,
      32,    32,    32,    33,    33,    34,    34,    34,    34,    34,
      34,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    36,    36,    37,    37,    37,    37,    37,    38,    39,
      39,    40,    40,    40,    40,    40,    40,    41,    41,    42,
      42,    42,    43,    43,    44,    45,    45
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     6,     2,     1,     1,
       3,     3,     2,     1,     2,     1,     2,     2,     4,     3,
       2,     3,     5,     1,     5,     5,     2,     4,     2,     1,
       3,     2,     3,     3,     2,     7,     7,     3,     4,     2,
       1,     4,     3,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, info, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, info); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, DateInfo* info)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (info);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, DateInfo* info)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, info);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, DateInfo* info)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , info);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, info); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, DateInfo* info)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (info);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (DateInfo* info)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, info);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

    {
	    yyIncrFlags(CLF_TIME);
	}

    break;

  case 6:

    {
	    yyIncrFlags(CLF_ZONE);
	}

    break;

  case 7:

    {
	    yyIncrFlags(CLF_HAVEDATE);
	}

    break;

  case 8:

    {
	    yyIncrFlags(CLF_ORDINALMONTH);
	}

    break;

  case 9:

    {
	    yyIncrFlags(CLF_DAYOFWEEK);
	}

    break;

  case 10:

    {
	    info->flags |= CLF_RELCONV;
	}

    break;

  case 11:

    {
	    yyIncrFlags(CLF_TIME|CLF_HAVEDATE);
	}

    break;

  case 12:

    {
	    yyIncrFlags(CLF_TIME|CLF_HAVEDATE);
	    info->flags |= CLF_RELCONV;
	}

    break;

  case 14:

    {
	    yyHour = (yyvsp[-1].Number);
	    yyMinutes = 0;
	    yySeconds = 0;
	    yyMeridian = (yyvsp[0].Meridian);
	}

    break;

  case 15:

    {
	    yyHour = (yyvsp[-3].Number);
	    yyMinutes = (yyvsp[-1].Number);
	    yySeconds = 0;
	    yyMeridian = (yyvsp[0].Meridian);
	}

    break;

  case 16:

    {
	    yyHour = (yyvsp[-5].Number);
	    yyMinutes = (yyvsp[-3].Number);
	    yySeconds = (yyvsp[-1].Number);
	    yyMeridian = (yyvsp[0].Meridian);
	}

    break;

  case 17:

    {
	    yyTimezone = (yyvsp[-1].Number);
	    yyDSTmode = DSTon;
	}

    break;

  case 18:

    {
	    yyTimezone = (yyvsp[0].Number);
	    yyDSTmode = DSToff;
	}

    break;

  case 19:

    {
	    yyTimezone = (yyvsp[0].Number);
	    yyDSTmode = DSTon;
	}

    break;

  case 20:

    { /* GMT+0100, GMT-1000, etc. */
	    yyTimezone = (yyvsp[-2].Number) - (yyvsp[-1].Number)*((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
	    yyDSTmode = DSToff;
	}

    break;

  case 21:

    { /* GMT+1, GMT-10, etc. */
	    yyTimezone = (yyvsp[-2].Number) - (yyvsp[-1].Number)*((yyvsp[0].Number) * 60);
	    yyDSTmode = DSToff;
	}

    break;

  case 22:

    { /* +0100, -0100 */
	    yyTimezone = -(yyvsp[-1].Number)*((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
	    yyDSTmode = DSToff;
	}

    break;

  case 25:

    {
	    yyDayOrdinal = 1;
	    yyDayOfWeek = (yyvsp[0].Number);
	}

    break;

  case 26:

    {
	    yyDayOrdinal = 1;
	    yyDayOfWeek = (yyvsp[-1].Number);
	}

    break;

  case 27:

    {
	    yyDayOrdinal = (yyvsp[-1].Number);
	    yyDayOfWeek = (yyvsp[0].Number);
	}

    break;

  case 28:

    {
	    yyDayOrdinal = (yyvsp[-3].Number) * (yyvsp[-1].Number);
	    yyDayOfWeek = (yyvsp[0].Number);
	}

    break;

  case 29:

    {
	    yyDayOrdinal = (yyvsp[-2].Number) * (yyvsp[-1].Number);
	    yyDayOfWeek = (yyvsp[0].Number);
	}

    break;

  case 30:

    {
	    yyDayOrdinal = 2;
	    yyDayOfWeek = (yyvsp[0].Number);
	}

    break;

  case 31:

    {
	    yyMonth = (yyvsp[-2].Number);
	    yyDay = (yyvsp[0].Number);
	}

    break;

  case 32:

    {
	    yyMonth = (yyvsp[-4].Number);
	    yyDay = (yyvsp[-2].Number);
	    yyYear = (yyvsp[0].Number);
	}

    break;

  case 33:

    {
	    yyYear = (yyvsp[0].Number) / 10000;
	    yyMonth = ((yyvsp[0].Number) % 10000)/100;
	    yyDay = (yyvsp[0].Number) % 100;
	}

    break;

  case 34:

    {
	    yyDay = (yyvsp[-4].Number);
	    yyMonth = (yyvsp[-2].Number);
	    yyYear = (yyvsp[0].Number);
	}

    break;

  case 35:

    {
	    yyMonth = (yyvsp[-2].Number);
	    yyDay = (yyvsp[0].Number);
	    yyYear = (yyvsp[-4].Number);
	}

    break;

  case 36:

    {
	    yyMonth = (yyvsp[-1].Number);
	    yyDay = (yyvsp[0].Number);
	}

    break;

  case 37:

    {
	    yyMonth = (yyvsp[-3].Number);
	    yyDay = (yyvsp[-2].Number);
	    yyYear = (yyvsp[0].Number);
	}

    break;

  case 38:

    {
	    yyMonth = (yyvsp[0].Number);
	    yyDay = (yyvsp[-1].Number);
	}

    break;

  case 39:

    {
	    yyMonth = 1;
	    yyDay = 1;
	    yyYear = EPOCH;
	}

    break;

  case 40:

    {
	    yyMonth = (yyvsp[-1].Number);
	    yyDay = (yyvsp[-2].Number);
	    yyYear = (yyvsp[0].Number);
	}

    break;

  case 41:

    {
	    yyMonthOrdinalIncr = 1;
	    yyMonthOrdinal = (yyvsp[0].Number);
	}

    break;

  case 42:

    {
	    yyMonthOrdinalIncr = (yyvsp[-1].Number);
	    yyMonthOrdinal = (yyvsp[0].Number);
	}

    break;

  case 43:

    {
	    if ((yyvsp[-1].Number) != HOUR( 7)) YYABORT; /* T */
	    yyYear = (yyvsp[-2].Number) / 10000;
	    yyMonth = ((yyvsp[-2].Number) % 10000)/100;
	    yyDay = (yyvsp[-2].Number) % 100;
	    yyHour = (yyvsp[0].Number) / 10000;
	    yyMinutes = ((yyvsp[0].Number) % 10000)/100;
	    yySeconds = (yyvsp[0].Number) % 100;
	}

    break;

  case 44:

    {
	    yyYear = (yyvsp[-1].Number) / 10000;
	    yyMonth = ((yyvsp[-1].Number) % 10000)/100;
	    yyDay = (yyvsp[-1].Number) % 100;
	    yyHour = (yyvsp[0].Number) / 10000;
	    yyMinutes = ((yyvsp[0].Number) % 10000)/100;
	    yySeconds = (yyvsp[0].Number) % 100;
	}

    break;

  case 45:

    {
	    yyYear = (yyvsp[-6].Number) / 10000;
	    yyMonth = ((yyvsp[-6].Number) % 10000)/100;
	    yyDay = (yyvsp[-6].Number) % 100;
	    yyHour = (yyvsp[-4].Number);
	    yyMinutes = (yyvsp[-2].Number);
	    yySeconds = (yyvsp[0].Number);
	}

    break;

  case 46:

    {
	    if ((yyvsp[-5].Number) != HOUR( 7)) YYABORT; /* T */
	    yyYear = (yyvsp[-6].Number) / 10000;
	    yyMonth = ((yyvsp[-6].Number) % 10000)/100;
	    yyDay = (yyvsp[-6].Number) % 100;
	    yyHour = (yyvsp[-4].Number);
	    yyMinutes = (yyvsp[-2].Number);
	    yySeconds = (yyvsp[0].Number);
	}

    break;

  case 47:

    {
	    yyYear = (yyvsp[-2].Number) / 10000;
	    yyMonth = ((yyvsp[-2].Number) % 10000)/100;
	    yyDay = (yyvsp[-2].Number) % 100;
	    yyHour = (yyvsp[0].Number) / 10000;
	    yyMinutes = ((yyvsp[0].Number) % 10000)/100;
	    yySeconds = (yyvsp[0].Number) % 100;
	}

    break;

  case 48:

    {
	    /*
	     * Offset computed year by -377 so that the returned years will be
	     * in a range accessible with a 32 bit clock seconds value.
	     */

	    yyYear = (yyvsp[-2].Number)/1000 + 2323 - 377;
	    yyDay  = 1;
	    yyMonth = 1;
	    yyRelDay += (((yyvsp[-2].Number)%1000)*(365 + IsLeapYear(yyYear)))/1000;
	    yyRelSeconds += (yyvsp[0].Number) * 144 * 60;
	}

    break;

  case 49:

    {
	    yyRelSeconds *= -1;
	    yyRelMonth *= -1;
	    yyRelDay *= -1;
	}

    break;

  case 51:

    {
	    *yyRelPointer += (yyvsp[-3].Number) * (yyvsp[-1].Number) * (yyvsp[0].Number);
	}

    break;

  case 52:

    {
	    *yyRelPointer += (yyvsp[-2].Number) * (yyvsp[-1].Number) * (yyvsp[0].Number);
	}

    break;

  case 53:

    {
	    *yyRelPointer += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}

    break;

  case 54:

    {
	    *yyRelPointer += (yyvsp[0].Number);
	}

    break;

  case 55:

    {
	    *yyRelPointer += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}

    break;

  case 56:

    {
	    *yyRelPointer += (yyvsp[0].Number);
	}

    break;

  case 57:

    {
	    (yyval.Number) = -1;
	}

    break;

  case 58:

    {
	    (yyval.Number) =  1;
	}

    break;

  case 59:

    {
	    (yyval.Number) = (yyvsp[0].Number);
	    yyRelPointer = &yyRelSeconds;
	}

    break;

  case 60:

    {
	    (yyval.Number) = (yyvsp[0].Number);
	    yyRelPointer = &yyRelDay;
	}

    break;

  case 61:

    {
	    (yyval.Number) = (yyvsp[0].Number);
	    yyRelPointer = &yyRelMonth;
	}

    break;

  case 62:

    {
	    (yyval.Number) = (yyvsp[0].Number);
	}

    break;

  case 63:

    {
	    (yyval.Number) = (yyvsp[0].Number);
	}

    break;

  case 64:

    {
	    if ((info->flags & (CLF_TIME|CLF_HAVEDATE|CLF_RELCONV)) == (CLF_TIME|CLF_HAVEDATE)) {
		yyYear = (yyvsp[0].Number);
	    } else {
		yyIncrFlags(CLF_TIME);
		if (yyDigitCount <= 2) {
		    yyHour = (yyvsp[0].Number);
		    yyMinutes = 0;
		} else {
		    yyHour = (yyvsp[0].Number) / 100;
		    yyMinutes = (yyvsp[0].Number) % 100;
		}
		yySeconds = 0;
		yyMeridian = MER24;
	    }
	}

    break;

  case 65:

    {
	    (yyval.Meridian) = MER24;
	}

    break;

  case 66:

    {
	    (yyval.Meridian) = (yyvsp[0].Meridian);
	}

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, info, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, info, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, info);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, info);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, info, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, info);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, info);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}


/*
 * Month and day table.
 */

static const TABLE MonthDayTable[] = {
    { "january",	tMONTH,	 1 },
    { "february",	tMONTH,	 2 },
    { "march",		tMONTH,	 3 },
    { "april",		tMONTH,	 4 },
    { "may",		tMONTH,	 5 },
    { "june",		tMONTH,	 6 },
    { "july",		tMONTH,	 7 },
    { "august",		tMONTH,	 8 },
    { "september",	tMONTH,	 9 },
    { "sept",		tMONTH,	 9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL, 0, 0 }
};

/*
 * Time units table.
 */

static const TABLE UnitsTable[] = {
    { "year",		tMONTH_UNIT,	12 },
    { "month",		tMONTH_UNIT,	 1 },
    { "fortnight",	tDAY_UNIT,	14 },
    { "week",		tDAY_UNIT,	 7 },
    { "day",		tDAY_UNIT,	 1 },
    { "hour",		tSEC_UNIT, 60 * 60 },
    { "minute",		tSEC_UNIT,	60 },
    { "min",		tSEC_UNIT,	60 },
    { "second",		tSEC_UNIT,	 1 },
    { "sec",		tSEC_UNIT,	 1 },
    { NULL, 0, 0 }
};

/*
 * Assorted relative-time words.
 */

static const TABLE OtherTable[] = {
    { "tomorrow",	tDAY_UNIT,	1 },
    { "yesterday",	tDAY_UNIT,	-1 },
    { "today",		tDAY_UNIT,	0 },
    { "now",		tSEC_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tSEC_UNIT,	0 },
    { "next",		tNEXT,		1 },
#if 0
    { "first",		tUNUMBER,	1 },
    { "second",		tUNUMBER,	2 },
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
#endif
    { "ago",		tAGO,		1 },
    { "epoch",		tEPOCH,		0 },
    { "stardate",	tSTARDATE,	0 },
    { NULL, 0, 0 }
};

/*
 * The timezone table. (Note: This table was modified to not use any floating
 * point constants to work around an SGI compiler bug).
 */

static const TABLE TimezoneTable[] = {
    { "gmt",	tZONE,	   HOUR( 0) },	    /* Greenwich Mean */
    { "ut",	tZONE,	   HOUR( 0) },	    /* Universal (Coordinated) */
    { "utc",	tZONE,	   HOUR( 0) },
    { "uct",	tZONE,	   HOUR( 0) },	    /* Universal Coordinated Time */
    { "wet",	tZONE,	   HOUR( 0) },	    /* Western European */
    { "bst",	tDAYZONE,  HOUR( 0) },	    /* British Summer */
    { "wat",	tZONE,	   HOUR( 1) },	    /* West Africa */
    { "at",	tZONE,	   HOUR( 2) },	    /* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,	   HOUR( 3) },	    /* Brazil Standard */
    { "gst",	tZONE,	   HOUR( 3) },	    /* Greenland Standard */
#endif
    { "nft",	tZONE,	   HOUR( 7/2) },    /* Newfoundland */
    { "nst",	tZONE,	   HOUR( 7/2) },    /* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR( 7/2) },    /* Newfoundland Daylight */
    { "ast",	tZONE,	   HOUR( 4) },	    /* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR( 4) },	    /* Atlantic Daylight */
    { "est",	tZONE,	   HOUR( 5) },	    /* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR( 5) },	    /* Eastern Daylight */
    { "cst",	tZONE,	   HOUR( 6) },	    /* Central Standard */
    { "cdt",	tDAYZONE,  HOUR( 6) },	    /* Central Daylight */
    { "mst",	tZONE,	   HOUR( 7) },	    /* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR( 7) },	    /* Mountain Daylight */
    { "pst",	tZONE,	   HOUR( 8) },	    /* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR( 8) },	    /* Pacific Daylight */
    { "yst",	tZONE,	   HOUR( 9) },	    /* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR( 9) },	    /* Yukon Daylight */
    { "akst",	tZONE,	   HOUR( 9) },	    /* Alaska Standard */
    { "akdt",	tDAYZONE,  HOUR( 9) },	    /* Alaska Daylight */
    { "hst",	tZONE,	   HOUR(10) },	    /* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR(10) },	    /* Hawaii Daylight */
    { "cat",	tZONE,	   HOUR(10) },	    /* Central Alaska */
    { "ahst",	tZONE,	   HOUR(10) },	    /* Alaska-Hawaii Standard */
    { "nt",	tZONE,	   HOUR(11) },	    /* Nome */
    { "idlw",	tZONE,	   HOUR(12) },	    /* International Date Line West */
    { "cet",	tZONE,	  -HOUR( 1) },	    /* Central European */
    { "cest",	tDAYZONE, -HOUR( 1) },	    /* Central European Summer */
    { "met",	tZONE,	  -HOUR( 1) },	    /* Middle European */
    { "mewt",	tZONE,	  -HOUR( 1) },	    /* Middle European Winter */
    { "mest",	tDAYZONE, -HOUR( 1) },	    /* Middle European Summer */
    { "swt",	tZONE,	  -HOUR( 1) },	    /* Swedish Winter */
    { "sst",	tDAYZONE, -HOUR( 1) },	    /* Swedish Summer */
    { "fwt",	tZONE,	  -HOUR( 1) },	    /* French Winter */
    { "fst",	tDAYZONE, -HOUR( 1) },	    /* French Summer */
    { "eet",	tZONE,	  -HOUR( 2) },	    /* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,	  -HOUR( 3) },	    /* Baghdad, USSR Zone 2 */
    { "it",	tZONE,	  -HOUR( 7/2) },    /* Iran */
    { "zp4",	tZONE,	  -HOUR( 4) },	    /* USSR Zone 3 */
    { "zp5",	tZONE,	  -HOUR( 5) },	    /* USSR Zone 4 */
    { "ist",	tZONE,	  -HOUR(11/2) },    /* Indian Standard */
    { "zp6",	tZONE,	  -HOUR( 6) },	    /* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Stanard, nad SST is
     * also Swedish Summer. */
    { "nst",	tZONE,	  -HOUR(13/2) },    /* North Sumatra */
    { "sst",	tZONE,	  -HOUR( 7) },	    /* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,	  -HOUR( 7) },	    /* West Australian Standard */
    { "wadt",	tDAYZONE, -HOUR( 7) },	    /* West Australian Daylight */
    { "jt",	tZONE,	  -HOUR(15/2) },    /* Java (3pm in Cronusland!) */
    { "cct",	tZONE,	  -HOUR( 8) },	    /* China Coast, USSR Zone 7 */
    { "jst",	tZONE,	  -HOUR( 9) },	    /* Japan Standard, USSR Zone 8 */
    { "jdt",	tDAYZONE, -HOUR( 9) },	    /* Japan Daylight */
    { "kst",	tZONE,	  -HOUR( 9) },	    /* Korea Standard */
    { "kdt",	tDAYZONE, -HOUR( 9) },	    /* Korea Daylight */
    { "cast",	tZONE,	  -HOUR(19/2) },    /* Central Australian Standard */
    { "cadt",	tDAYZONE, -HOUR(19/2) },    /* Central Australian Daylight */
    { "east",	tZONE,	  -HOUR(10) },	    /* Eastern Australian Standard */
    { "eadt",	tDAYZONE, -HOUR(10) },	    /* Eastern Australian Daylight */
    { "gst",	tZONE,	  -HOUR(10) },	    /* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,	  -HOUR(12) },	    /* New Zealand */
    { "nzst",	tZONE,	  -HOUR(12) },	    /* New Zealand Standard */
    { "nzdt",	tDAYZONE, -HOUR(12) },	    /* New Zealand Daylight */
    { "idle",	tZONE,	  -HOUR(12) },	    /* International Date Line East */
    /* ADDED BY Marco Nijdam */
    { "dst",	tDST,	  HOUR( 0) },	    /* DST on (hour is ignored) */
    /* End ADDED */
    { NULL, 0, 0 }
};

/*
 * Military timezone table.
 */

static const TABLE MilitaryTable[] = {
    { "a",	tZONE,	-HOUR( 1) },
    { "b",	tZONE,	-HOUR( 2) },
    { "c",	tZONE,	-HOUR( 3) },
    { "d",	tZONE,	-HOUR( 4) },
    { "e",	tZONE,	-HOUR( 5) },
    { "f",	tZONE,	-HOUR( 6) },
    { "g",	tZONE,	-HOUR( 7) },
    { "h",	tZONE,	-HOUR( 8) },
    { "i",	tZONE,	-HOUR( 9) },
    { "k",	tZONE,	-HOUR(10) },
    { "l",	tZONE,	-HOUR(11) },
    { "m",	tZONE,	-HOUR(12) },
    { "n",	tZONE,	HOUR(  1) },
    { "o",	tZONE,	HOUR(  2) },
    { "p",	tZONE,	HOUR(  3) },
    { "q",	tZONE,	HOUR(  4) },
    { "r",	tZONE,	HOUR(  5) },
    { "s",	tZONE,	HOUR(  6) },
    { "t",	tZONE,	HOUR(  7) },
    { "u",	tZONE,	HOUR(  8) },
    { "v",	tZONE,	HOUR(  9) },
    { "w",	tZONE,	HOUR( 10) },
    { "x",	tZONE,	HOUR( 11) },
    { "y",	tZONE,	HOUR( 12) },
    { "z",	tZONE,	HOUR( 0) },
    { NULL, 0, 0 }
};

static inline const char *
bypassSpaces(
    register const char *s)
{
    while (TclIsSpaceProc(*s)) {
	s++;
    }
    return s;
}

/*
 * Dump error messages in the bit bucket.
 */

static void
TclDateerror(
    YYLTYPE* location,
    DateInfo* infoPtr,
    const char *s)
{
    Tcl_Obj* t;
    if (!infoPtr->messages) {
	infoPtr->messages = Tcl_NewObj();
    }
    Tcl_AppendToObj(infoPtr->messages, infoPtr->separatrix, -1);
    Tcl_AppendToObj(infoPtr->messages, s, -1);
    Tcl_AppendToObj(infoPtr->messages, " (characters ", -1);
    t = Tcl_NewIntObj(location->first_column);
    Tcl_IncrRefCount(t);
    Tcl_AppendObjToObj(infoPtr->messages, t);
    Tcl_DecrRefCount(t);
    Tcl_AppendToObj(infoPtr->messages, "-", -1);
    t = Tcl_NewIntObj(location->last_column);
    Tcl_IncrRefCount(t);
    Tcl_AppendObjToObj(infoPtr->messages, t);
    Tcl_DecrRefCount(t);
    Tcl_AppendToObj(infoPtr->messages, ")", -1);
    infoPtr->separatrix = "\n";
}

int
ToSeconds(
    int Hours,
    int Minutes,
    int Seconds,
    MERIDIAN Meridian)
{
    if (Minutes < 0 || Minutes > 59 || Seconds < 0 || Seconds > 59) {
	return -1;
    }
    switch (Meridian) {
    case MER24:
	if (Hours < 0 || Hours > 23) {
	    return -1;
	}
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERam:
	if (Hours < 1 || Hours > 12) {
	    return -1;
	}
	return ((Hours % 12) * 60L + Minutes) * 60L + Seconds;
    case MERpm:
	if (Hours < 1 || Hours > 12) {
	    return -1;
	}
	return (((Hours % 12) + 12) * 60L + Minutes) * 60L + Seconds;
    }
    return -1;			/* Should never be reached */
}

static int
LookupWord(
    YYSTYPE* yylvalPtr,
    char *buff)
{
    register char *p;
    register char *q;
    register const TABLE *tp;
    int i, abbrev;

    /*
     * Make it lowercase.
     */

    Tcl_UtfToLower(buff);

    if (*buff == 'a' && (strcmp(buff, "am") == 0 || strcmp(buff, "a.m.") == 0)) {
	yylvalPtr->Meridian = MERam;
	return tMERIDIAN;
    }
    if (*buff == 'p' && (strcmp(buff, "pm") == 0 || strcmp(buff, "p.m.") == 0)) {
	yylvalPtr->Meridian = MERpm;
	return tMERIDIAN;
    }

    /*
     * See if we have an abbreviation for a month.
     */

    if (strlen(buff) == 3) {
	abbrev = 1;
    } else if (strlen(buff) == 4 && buff[3] == '.') {
	abbrev = 1;
	buff[3] = '\0';
    } else {
	abbrev = 0;
    }

    for (tp = MonthDayTable; tp->name; tp++) {
	if (abbrev) {
	    if (strncmp(buff, tp->name, 3) == 0) {
		yylvalPtr->Number = tp->value;
		return tp->type;
	    }
	} else if (strcmp(buff, tp->name) == 0) {
	    yylvalPtr->Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = TimezoneTable; tp->name; tp++) {
	if (strcmp(buff, tp->name) == 0) {
	    yylvalPtr->Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = UnitsTable; tp->name; tp++) {
	if (strcmp(buff, tp->name) == 0) {
	    yylvalPtr->Number = tp->value;
	    return tp->type;
	}
    }

    /*
     * Strip off any plural and try the units table again.
     */

    i = strlen(buff) - 1;
    if (i > 0 && buff[i] == 's') {
	buff[i] = '\0';
	for (tp = UnitsTable; tp->name; tp++) {
	    if (strcmp(buff, tp->name) == 0) {
		yylvalPtr->Number = tp->value;
		return tp->type;
	    }
	}
    }

    for (tp = OtherTable; tp->name; tp++) {
	if (strcmp(buff, tp->name) == 0) {
	    yylvalPtr->Number = tp->value;
	    return tp->type;
	}
    }

    /*
     * Military timezones.
     */

    if (buff[1] == '\0' && !(*buff & 0x80)
	    && isalpha(UCHAR(*buff))) {			/* INTL: ISO only */
	for (tp = MilitaryTable; tp->name; tp++) {
	    if (strcmp(buff, tp->name) == 0) {
		yylvalPtr->Number = tp->value;
		return tp->type;
	    }
	}
    }

    /*
     * Drop out any periods and try the timezone table again.
     */

    for (i = 0, p = q = buff; *q; q++) {
	if (*q != '.') {
	    *p++ = *q;
	} else {
	    i++;
	}
    }
    *p = '\0';
    if (i) {
	for (tp = TimezoneTable; tp->name; tp++) {
	    if (strcmp(buff, tp->name) == 0) {
		yylvalPtr->Number = tp->value;
		return tp->type;
	    }
	}
    }

    return tID;
}

static int
TclDatelex(
    YYSTYPE* yylvalPtr,
    YYLTYPE* location,
    DateInfo *info)
{
    register char c;
    register char *p;
    char buff[20];
    int Count;

    location->first_column = yyInput - info->dateStart;
    for ( ; ; ) {

	if (isspace(UCHAR(*yyInput))) {
	    yyInput = bypassSpaces(yyInput);
	    /* ignore space at end of text and before some words */
	    c = *yyInput;
	    if (c != '\0' && !isalpha(UCHAR(c))) {
		return SP;
	    }
	}

	if (isdigit(UCHAR(c = *yyInput))) { /* INTL: digit */
	    
	    /*
	     * Convert the string into a number; count the number of digits.
	     */
	    register int num = c - '0';
	    p = (char *)yyInput;
	    while (isdigit(UCHAR(c = *(++p)))) {
		num *= 10;
		num += c - '0';
	    };
	    yylvalPtr->Number = num;
	    yyDigitCount = p - yyInput;
	    yyInput = p;

	    /* ignore spaces after digits (optional) */
	    yyInput = bypassSpaces(yyInput);
	    /*
	     * A number with 6 or more digits is considered an ISO 8601 base.
	     */

	    if (yyDigitCount >= 6) {
		location->last_column = yyInput - info->dateStart - 1;
		return tISOBASE;
	    } else {
		location->last_column = yyInput - info->dateStart - 1;
		return tUNUMBER;
	    }
	}
	if (!(c & 0x80) && isalpha(UCHAR(c))) {		  /* INTL: ISO only. */
	    int ret;
	    for (p = buff; isalpha(UCHAR(c = *yyInput++)) /* INTL: ISO only. */
		     || c == '.'; ) {
		if (p < &buff[sizeof buff - 1]) {
		    *p++ = c;
		}
	    }
	    *p = '\0';
	    yyInput--;
	    location->last_column = yyInput - info->dateStart - 1;
	    ret = LookupWord(yylvalPtr, buff);
	    /* 
	     * lookahead for +/- digit, to differentiate between "GMT+1000 day" and "GMT +1000 day",
	     * bypass spaces after token (but ignore by TZ+OFFS), because should 
	     * recognize next SP token, if TZ only.
	     */
	    if (ret == tZONE || ret == tDAYZONE) {
		c = *yyInput;
		if ((c == '+' || c == '-') && isdigit(UCHAR(*(yyInput+1)))) {
		    if ( !isdigit(UCHAR(*(yyInput+2)))
		      || !isdigit(UCHAR(*(yyInput+3)))) {
			/* GMT+1, GMT-10, etc. */
			return tZONEwO2;
		    }
		    if ( isdigit(UCHAR(*(yyInput+4)))
		      && !isdigit(UCHAR(*(yyInput+5)))) {
			/* GMT+1000, etc. */
			return tZONEwO4;
		    }
		}
	    }
	    yyInput = bypassSpaces(yyInput);
	    return ret;

	}
	if (c != '(') {
	    location->last_column = yyInput - info->dateStart;
	    return *yyInput++;
	}
	Count = 0;
	do {
	    c = *yyInput++;
	    if (c == '\0') {
		location->last_column = yyInput - info->dateStart - 1;
		return c;
	    } else if (c == '(') {
		Count++;
	    } else if (c == ')') {
		Count--;
	    }
	} while (Count > 0);
    }
}

int
TclClockFreeScan(
    Tcl_Interp *interp,		/* Tcl interpreter */
    DateInfo *info)		/* Input and result parameters */
{
    int status;

  #if YYDEBUG
    /* enable debugging if compiled with YYDEBUG */
    yydebug = 1;
  #endif

    /*
     * yyInput = stringToParse;
     *
     * ClockInitDateInfo(info) should be executed to pre-init info;
     */

    yyDSTmode = DSTmaybe;

    info->separatrix = "";

    info->dateStart = yyInput;

    /* ignore spaces at begin */
    yyInput = bypassSpaces(yyInput);

    /* parse */
    status = yyparse(info);
    if (status == 1) {
    	const char *msg = NULL;
	if (info->errFlags & CLF_HAVEDATE) {
	    msg = "more than one date in string";
	} else if (info->errFlags & CLF_TIME) {
	    msg = "more than one time of day in string";
	} else if (info->errFlags & CLF_ZONE) {
	    msg = "more than one time zone in string";
	} else if (info->errFlags & CLF_DAYOFWEEK) {
	    msg = "more than one weekday in string";
	} else if (info->errFlags & CLF_ORDINALMONTH) {
	    msg = "more than one ordinal month in string";
	}
	if (msg) {
	    Tcl_SetObjResult(interp, Tcl_NewStringObj(msg, -1));
	    Tcl_SetErrorCode(interp, "TCL", "VALUE", "DATE", "MULTIPLE", NULL);
	} else {
	    Tcl_SetObjResult(interp,
		info->messages ? info->messages : Tcl_NewObj());
	    info->messages = NULL;
	    Tcl_SetErrorCode(interp, "TCL", "VALUE", "DATE", "PARSE", NULL);
	}
	status = TCL_ERROR;
    } else if (status == 2) {
	Tcl_SetObjResult(interp, Tcl_NewStringObj("memory exhausted", -1));
	Tcl_SetErrorCode(interp, "TCL", "MEMORY", NULL);
	status = TCL_ERROR;
    } else if (status != 0) {
	Tcl_SetObjResult(interp, Tcl_NewStringObj("Unknown status returned "
						  "from date parser. Please "
						  "report this error as a "
						  "bug in Tcl.", -1));
	Tcl_SetErrorCode(interp, "TCL", "BUG", NULL);
	status = TCL_ERROR;
    }
    if (info->messages) {
	Tcl_DecrRefCount(info->messages);
    }
    return status;
}

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 4
 * fill-column: 78
 * End:
 */
