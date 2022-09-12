/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "miniL.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <set>
#include <map>

using std::string;
using std::set;
using std::map;

int yylex(void);
void yyerror( const char* msg );
int numTemps, numLabels = 0;
string newTemp();
string newLabel();
extern int currLine;
extern int currPos;
FILE* yyin;
bool hasMain = false;

map<string, string> varTemp;
map<string, int> arrSize;
set<string> definedFns;
set<string> KEYWORDS { "FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "INTEGER", "ARRAY", "ENUM", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE", "FALSE", "RETURN", "BEGINBODY", "ENDBODY", "SUB", "PLUS", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN" };

#line 93 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGIN_PARAMS = 259,
    END_PARAMS = 260,
    BEGIN_LOCALS = 261,
    END_LOCALS = 262,
    INTEGER = 263,
    ARRAY = 264,
    ENUM = 265,
    OF = 266,
    IF = 267,
    THEN = 268,
    ENDIF = 269,
    ELSE = 270,
    WHILE = 271,
    DO = 272,
    BEGINLOOP = 273,
    ENDLOOP = 274,
    CONTINUE = 275,
    READ = 276,
    WRITE = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    TRUE = 281,
    FALSE = 282,
    RETURN = 283,
    BEGINBODY = 284,
    ENDBODY = 285,
    SUB = 286,
    PLUS = 287,
    MULT = 288,
    DIV = 289,
    MOD = 290,
    EQ = 291,
    NEQ = 292,
    LT = 293,
    GT = 294,
    LTE = 295,
    GTE = 296,
    SEMICOLON = 297,
    COLON = 298,
    COMMA = 299,
    L_PAREN = 300,
    R_PAREN = 301,
    L_SQUARE_BRACKET = 302,
    R_SQUARE_BRACKET = 303,
    ASSIGN = 304,
    IDENT = 305,
    NUMBER = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "miniL.y" /* yacc.c:355  */

    int ival;
    char* sval;
    struct S {
        char* code;
    } statement;
    struct E {
        char* place;
        char* code;
        bool isArr;
    } expression;

#line 198 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    66,    71,    74,   106,   110,   118,   164,
     195,   200,   205,   214,   226,   230,   239,   254,   267,   270,
     273,   276,   279,   282,   285,   293,   294,   297,   298,   301,
     302,   305,   306,   307,   308,   311,   312,   313,   314,   315,
     316,   319,   335,   356,   370,   385,   390,   402,   416,   421,
     433,   445,   459,   460,   478,   483,   489,   494,   503,   521,
     524,   525
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "INTEGER", "ARRAY", "ENUM", "OF", "IF",
  "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP", "ENDLOOP",
  "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE", "FALSE",
  "RETURN", "BEGINBODY", "ENDBODY", "SUB", "PLUS", "MULT", "DIV", "MOD",
  "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA",
  "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN",
  "IDENT", "NUMBER", "$accept", "start", "functions", "function",
  "declarations", "declaration", "identifiers", "ident", "statements",
  "statement", "bool_expr", "relation_and_expr", "relation_expr",
  "relation_sub", "comp", "var", "var_list", "expression",
  "multiplicative_expr", "term", "expressions", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -36,    32,   -50,     7,   -50,    -8,   -50,   -50,    48,
     -36,    58,    24,    28,    31,    74,   -36,    19,   -36,   -36,
     -50,   -50,    37,    43,   -50,    85,    44,   -36,    71,    51,
      68,    69,   105,   -50,    14,    14,    99,   -50,   -36,   -36,
       5,    75,    93,    92,    86,   128,    56,   -50,   -50,    70,
      14,   -50,    -3,   124,   114,   116,   -50,   -50,    89,   -24,
      98,   122,    69,    97,   -50,   -50,     5,   -50,     5,   -50,
      69,     5,   -50,   -50,     5,   -50,   -50,    96,    72,   -26,
      69,    14,    14,   -50,   -50,   -50,   -50,   -50,   -50,     5,
       5,     5,     5,     5,     5,    69,   125,   -36,   100,    95,
     -50,   -50,   101,   -50,   -50,   -50,   104,   103,    63,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   126,   134,   -50,
     -50,   -50,     5,   -50,   -50,    69,   -50,    14,   -50,   137,
     -50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,    13,     0,     1,     4,     0,
       6,     0,     0,     0,    11,     0,     6,     0,     0,     6,
       7,     8,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,    23,     0,     0,
       0,    41,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    54,    41,     0,    25,    27,    29,    52,     0,    45,
      48,     0,     0,    43,    21,    22,     0,    24,     0,     5,
      14,     0,     9,    30,     0,    55,    53,     0,     0,     0,
       0,     0,     0,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     0,    34,    56,    59,    60,     0,     0,    26,
      28,    31,    47,    46,    49,    50,    51,     0,     0,    44,
      42,    57,     0,    58,    17,     0,    19,     0,    61,     0,
      20,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   148,   -50,   -13,   -50,    40,    -1,   -49,   -50,
     -34,    73,   -50,   107,   -50,   -27,   -37,   -17,    10,   -50,
      34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    12,    13,    52,    42,    43,
      53,    54,    55,    56,    89,    57,    64,    58,    59,    60,
     107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    61,    65,    20,    44,    49,    25,    90,    91,    14,
       1,    63,    63,    96,     5,    14,    77,    14,    14,    66,
     105,   100,    76,    67,     5,    51,    14,    21,    22,    23,
      41,   108,     7,    78,     9,    44,    49,    41,    41,    46,
      47,    48,    79,    44,    68,    49,   117,   109,    41,    98,
      66,    99,    10,    44,   101,     5,    51,   102,    24,    50,
     119,    41,   106,    15,     5,    51,    16,    30,    44,    41,
      63,    17,   111,   112,   113,    18,   129,   124,   125,    41,
      19,    34,    47,    48,    26,    35,    36,    49,    27,    37,
      38,    39,    28,   130,    41,    29,    41,    40,    44,    32,
      31,    50,   114,   115,   116,   106,     5,    51,    83,    84,
      85,    86,    87,    88,    33,    74,    45,    62,   104,     5,
       5,    75,    68,    69,    41,    83,    84,    85,    86,    87,
      88,    92,    93,    94,    70,    71,    72,    80,    81,    82,
      95,    97,   103,   120,   118,   126,   104,   121,   122,   123,
     127,   131,     8,    73,     0,   110,   128
};

static const yytype_int8 yycheck[] =
{
       1,    35,    39,    16,    31,    31,    19,    31,    32,    10,
       3,    38,    39,    62,    50,    16,    50,    18,    19,    45,
      46,    70,    49,    40,    50,    51,    27,     8,     9,    10,
      31,    80,     0,    50,    42,    62,    31,    38,    39,    25,
      26,    27,    45,    70,    47,    31,    95,    81,    49,    66,
      45,    68,     4,    80,    71,    50,    51,    74,    18,    45,
      97,    62,    79,     5,    50,    51,    42,    27,    95,    70,
      97,    43,    89,    90,    91,    44,   125,    14,    15,    80,
       6,    12,    26,    27,    47,    16,    17,    31,    45,    20,
      21,    22,     7,   127,    95,    51,    97,    28,   125,    48,
      29,    45,    92,    93,    94,   122,    50,    51,    36,    37,
      38,    39,    40,    41,    46,    45,    11,    18,    46,    50,
      50,    51,    47,    30,   125,    36,    37,    38,    39,    40,
      41,    33,    34,    35,    42,    49,     8,    13,    24,    23,
      18,    44,    46,    48,    19,    19,    46,    46,    44,    46,
      16,    14,     4,    46,    -1,    82,   122
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,    55,    50,    59,     0,    54,    42,
       4,    56,    57,    58,    59,     5,    42,    43,    44,     6,
      56,     8,     9,    10,    58,    56,    47,    45,     7,    51,
      58,    29,    48,    46,    12,    16,    17,    20,    21,    22,
      28,    59,    60,    61,    67,    11,    25,    26,    27,    31,
      45,    51,    59,    62,    63,    64,    65,    67,    69,    70,
      71,    62,    18,    67,    68,    68,    45,    69,    47,    30,
      42,    49,     8,    65,    45,    51,    67,    62,    69,    45,
      13,    24,    23,    36,    37,    38,    39,    40,    41,    66,
      31,    32,    33,    34,    35,    18,    60,    44,    69,    69,
      60,    69,    69,    46,    46,    46,    69,    72,    60,    62,
      63,    69,    69,    69,    70,    70,    70,    60,    19,    68,
      48,    46,    44,    46,    14,    15,    19,    16,    72,    60,
      62,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    12,     0,     3,     3,     8,
       6,     1,     3,     1,     2,     3,     3,     5,     7,     5,
       6,     2,     2,     1,     2,     1,     3,     1,     3,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     2,     3,     4,     4,     3,
       1,     3
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 66 "miniL.y" /* yacc.c:1646  */
    { 
        if( !hasMain ){
            printf( "No main function declared\n" );
        } 
    }
#line 1395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "miniL.y" /* yacc.c:1646  */
    { }
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "miniL.y" /* yacc.c:1646  */
    {
        string temp = "func ";
        string s = (yyvsp[-10].expression).place;
        temp.append( s ).append( "\n" );

        if( s == "main" ){
                hasMain = true;
        }

        string declares = (yyvsp[-7].expression).code;
        int nDecs = 0;
        while( declares.find(".") != string::npos ) {
            int pos = declares.find( "." );
            declares.replace( pos, 1, "=" );
            string part = ", $" + std::to_string( nDecs ) + "\n";
            nDecs++;
            declares.replace( declares.find( "\n", pos ), 1, part );
        }

        temp.append( declares ).append( (yyvsp[-4].expression).code );

        string statements = (yyvsp[-1].statement).code;
        if( statements.find( "continue" ) != string::npos ){
            printf( "ERROR: Continue outside loop in function %s\n", (yyvsp[-10].expression).place);
        }

        //add the states to string
        temp.append( statements ).append( "endfunc\n\n" );
        printf( temp.c_str() );
    }
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "miniL.y" /* yacc.c:1646  */
    { 
        (yyval.expression).code = strdup( "" );
        (yyval.expression).place = strdup( "" );
    }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "miniL.y" /* yacc.c:1646  */
    { 
        string temp;
        temp.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
        (yyval.expression).code = strdup( temp.c_str() );
        (yyval.expression).place = strdup( "" );
    }
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "miniL.y" /* yacc.c:1646  */
    { 
        int left = 0;
        int right = 0;
        string parse( (yyvsp[-2].expression).place );
        string temp;
        bool isDone = false;
        while( !isDone ){
            right = parse.find( "|", left ); //find other possible idents
            temp.append( ". " ); //add the `. k`
            if( right == string::npos ){ //only one ident 
                string ident = parse.substr( left, right );
                //check it isnt a keyword
                if( KEYWORDS.find( ident ) != KEYWORDS.end() ){
                    printf( "Identifier $s is a resevered keyword.\n", ident.c_str() );
                }
                //check it hasnt been defined as a function or a variable
                if( definedFns.find( ident ) != definedFns.end() || varTemp.find( ident ) != varTemp.end() ){
                    printf( "Identifier $s is already declared.\n", ident.c_str() );
                } else {
                    varTemp[ident] = ident;
                    arrSize[ident] = 1;
                }
                temp.append( ident );
                isDone = true;
            } else { //there are more idents on the same line
                string ident = parse.substr( left, right - left );

                if( KEYWORDS.find( ident ) != KEYWORDS.end() ){
                    printf( "Identifier $s is a resevered keyword.\n", ident.c_str() );
                }

                if( definedFns.find( ident ) != definedFns.end() || varTemp.find( ident ) != varTemp.end() ){
                    printf( "Identifier $s is already declared.\n", ident.c_str() );
                } else {
                    varTemp[ident] = ident;
                    arrSize[ident] = 1;
                }
                temp.append( ident );
                left = right + 1;
            }
            temp.append( "\n" );
        }
        (yyval.expression).code = strdup( temp.c_str() );
        string s = "";
        (yyval.expression).place = strdup( "" );
}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 164 "miniL.y" /* yacc.c:1646  */
    { 
    //TODO not finished
    //printf( "declaration -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF NUMBER\n"); 
    int left = 0;
    int right = 0;
    string parse( (yyvsp[-7].expression).place );
    string temp;
    bool isDone = false;
    while( !isDone ){
        right = parse.find( "|", left );
        temp.append( ".[] ");
        if( right == string::npos ){ //only one ident 
            string ident = parse.substr( left, right );
            //check it isnt a keyword
            if( KEYWORDS.find( ident ) != KEYWORDS.end() ){
                printf( "Identifier $s is a resevered keyword.\n", ident.c_str() );
            }
            //check it hasnt been defined as a function or a variable
            if( definedFns.find( ident ) != definedFns.end() || varTemp.find( ident ) != varTemp.end() ){
                printf( "Identifier $s is already declared.\n", ident.c_str() );
            } else {
                varTemp[ident] = ident;
                arrSize[ident] = 1;
            }
            temp.append( ident );
            isDone = true;
        } else {

        }
    }
}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 195 "miniL.y" /* yacc.c:1646  */
    { 
    printf( "declaration -> identifiers COLON ENUM L_PAREN identifiers R_PAREN\n"); 
}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 200 "miniL.y" /* yacc.c:1646  */
    { 
    // printf( "identifiers -> ident\n"); 
    (yyval.expression).place = strdup( (yyvsp[0].expression).place );
    (yyval.expression).code = strdup( "" );
}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 205 "miniL.y" /* yacc.c:1646  */
    { 
    //printf( "identifiers -> ident COMMA identifiers\n"); 
    string s;
    s.append( (yyvsp[-2].expression).place ).append( "|" ).append( (yyvsp[0].expression).place );
    (yyval.expression).place = strdup( s.c_str() );
    (yyval.expression).code = strdup( "" );
}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 214 "miniL.y" /* yacc.c:1646  */
    { 
    if( definedFns.find( (yyvsp[0].sval) ) != definedFns.end() ){
        printf( "function %s is declared already.\n", (yyvsp[0].sval) );
    } else {
        definedFns.insert( (yyvsp[0].sval) );
    }
    (yyval.expression).place = strdup( (yyvsp[0].sval) );
    (yyval.expression).code = strdup( "" );
    // printf( "ident -> IDENT %s\n", $1 ); 
}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 226 "miniL.y" /* yacc.c:1646  */
    { 
    //printf( "statements -> ε\n"); 
    (yyval.statement).code = strdup( (yyvsp[-1].statement).code );
}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 230 "miniL.y" /* yacc.c:1646  */
    { 
    //printf( "statements -> statement SEMICOLON statements\n"); 
    string temp;
    temp.append( (yyvsp[-2].statement).code );
    temp.append( (yyvsp[0].statement).code );
    (yyval.statement).code = strdup( temp.c_str() );
}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "miniL.y" /* yacc.c:1646  */
    { 
    //printf( "statement -> var ASSIGN expression\n"); 
    string temp;
    temp.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
    string middle = (yyvsp[0].expression).place;
    if((yyvsp[-2].expression).isArr && (yyvsp[0].expression).isArr ){
        temp += "[]= ";
    } else if ( (yyvsp[-2].expression).isArr ){
        temp += "[]= ";
    } else {
        temp += "= ";
    }
    temp.append( (yyvsp[-2].expression).place ).append( ", " ).append( middle ).append( "\n" );
    (yyval.statement).code = strdup( temp.c_str() );
}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 254 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "statement -> IF bool_expr THEN statements ENDIF\n"); 
    string ifStart = newLabel();
    string after = newLabel();
    string t;
    //?:= label, predicate	if predicate is true (1) goto label
    t.append( (yyvsp[-3].expression).code );
    //true block
    t.append( "?:=" ).append( ifStart ).append( ", " ).append( (yyvsp[-3].expression).place ).append( "\n" );
    //else //:= label
    t.append( ":= " ).append( after ).append( "\n" );
    //TODO come back too
}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 267 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "statement -> IF bool_expr THEN statements ELSE statements ENDIF\n"); 
}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 270 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "statement -> WHILE bool_expr BEGINLOOP statements ENDLOOP\n"); 
}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 273 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr\n"); 
}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 276 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "statement -> READ var_list\n"); 
}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 279 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "statement -> WRITE var_list\n"); 
}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 282 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "statement -> CONTINUE\n"); 
}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 285 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "statement -> RETURN expression\n"); 
    string temp;
    temp.append( (yyvsp[0].expression).code ).append( "ret " ).append( (yyvsp[0].expression).place ).append( "\n" );
    (yyval.statement).code = strdup( temp.c_str() );
}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "miniL.y" /* yacc.c:1646  */
    { printf( "bool_expr -> relation_and_expr\n"); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "miniL.y" /* yacc.c:1646  */
    { printf( "bool_expr -> relation_and_expr OR bool_expr\n"); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 297 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_and_expr -> relation_expr\n"); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 298 "miniL.y" /* yacc.c:1646  */
    { printf( "bool_expr -> relation_expr AND relation_and_expr\n"); }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 301 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_expr -> relation_sub\n"); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 302 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_expr _> NOT relation_sub\n"); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 305 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_sub -> expression comp expression\n"); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 306 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_sub -> TRUE\n"); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 307 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_sub -> FALSE\n"); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 308 "miniL.y" /* yacc.c:1646  */
    { printf( "relation_sub -> L_PAREN bool_expr R_PAREN\n"); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 311 "miniL.y" /* yacc.c:1646  */
    { printf( "comp -> EQ\n"); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 312 "miniL.y" /* yacc.c:1646  */
    { printf( "comp -> NEQ\n"); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 313 "miniL.y" /* yacc.c:1646  */
    { printf( "comp -> LT\n"); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 314 "miniL.y" /* yacc.c:1646  */
    { printf( "comp -> GT\n"); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 315 "miniL.y" /* yacc.c:1646  */
    { printf( "comp -> LTE"); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 316 "miniL.y" /* yacc.c:1646  */
    { printf( "comp -> GTE\n"); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 319 "miniL.y" /* yacc.c:1646  */
    { 
    if( DEBUG_OUTPUT ) { printf( "var -> ident\n" );} 
    string id = (yyvsp[0].expression).place;
    //check undeclared vars check1
    if( definedFns.find( id) == definedFns.end() && varTemp.find( id ) == varTemp.end() ){ //was not found
        string s = "Using an undeclared variable " + (yyvsp[0].expression).place;
        yyerror( s.c_str() );
    }
    else if( arrSize[id] > 1 ){ //check if array check6
        string s = "Identifier did not provide index for array identifer " + id;
        yyerror( s.c_str() );
    }
    (yyval.expression).place = strdup( id.c_str() );
    (yyval.expression).code = strdup( "" )
    (yyval.expression).arr = false;
}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 335 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( " var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n" ); 
    string id = (yyvsp[-3].expression).place;
    //check undeclared vars check1
    if( definedFns.find( id) == definedFns.end() && varTemp.find( id ) == varTemp.end() ){ //was not found
        string s = "Using an undeclared variable " + (yyvsp[-3].expression).place;
        yyerror( s.c_str() );
    }
    else if( arrSize.find( id ) == arrSize.end() ){ //check if array check6
        string s = "Identifier is not an array identifer " + id;
        yyerror( s.c_str() );
    }
    string t;
    t.append( (yyvsp[-3].expression).place ).append( ", " ).append( (yyvsp[-1].expression).place );
    (yyval.expression).code = strdup( (yyvsp[-1].expression).code );
    (yyval.expression).place = strdup( t.c_str() );
    (yyval.expression).arr = true;
}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 356 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "var_list -> var\n" );
    string t;
    if( (yyvsp[0].expression).arr ){
        t.append( ".[]| ");
    }
    else {
        t.append( ".| " );
    }
    t.append( (yyvsp[0].expression).place ).append( "\n" );

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( "" );
}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 370 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "var_list -> var COMMA var_list\n" ); 
    string t;
    if( (yyvsp[-2].expression).arr ){
        t.append( ".[]| ");
    }
    else {
        t.append( ".| " );
    }
    t.append( (yyvsp[-2].expression).place ).append( "\n" ).append( (yyvsp[0].expression).code );

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( "" );
}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 385 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT ) printf( "expression -> multiplicative_expr\n"); 
    (yyval.expression).code = strdup( (yyvsp[0].expression).code );
    (yyval.expression).place = strdup( (yyvsp[0].expression).place );
}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 390 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "expression -> multiplicative_expr PLUS expression\n");
    string t;
    string dest = newTemp();

    t.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
    t.append( ". " + dst + "\n" );
    t.append( "+ " + dst + ", " ).append( (yyvsp[-2].expression).place ).append( ", " ).append( (yyvsp[0].expression).place ).append( "\n");

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( dst.c_str() );
}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 402 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "expression -> multiplicative_expr SUB expression\n");
    string t;
    string dest = newTemp();

    t.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
    t.append( ". " + dst + "\n" );
    t.append( "- " + dst + ", " ).append( (yyvsp[-2].expression).place ).append( ", " ).append( (yyvsp[0].expression).place ).append( "\n");

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( dst.c_str() );
}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 416 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "multiplicative_expr -> term\n"); 
    (yyval.expression).code = strdup( (yyvsp[0].expression).code );
    (yyval.expression).place = strdup( (yyval.expression).place );
}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 421 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "multiplicative_expr -> term MULT multiplicative_expr\n"); 
    string t;
    string dest = newTemp();

    t.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
    t.append( ". " + dst + "\n" );
    t.append( "* " + dst + ", " ).append( (yyvsp[-2].expression).place ).append( ", " ).append( (yyvsp[0].expression).place ).append( "\n");

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( dst.c_str() );
}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 433 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT ) printf( "multiplicative_expr -> term DIV multiplicative_expr\n"); 
    string t;
    string dest = newTemp();

    t.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
    t.append( ". " + dst + "\n" );
    t.append( "/ " + dst + ", " ).append( (yyvsp[-2].expression).place ).append( ", " ).append( (yyvsp[0].expression).place ).append( "\n");

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( dst.c_str() );
}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 445 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT ) printf( "multiplicative_expr -> term MOD multiplicative_expr\n");
    string t;
    string dest = newTemp();

    t.append( (yyvsp[-2].expression).code ).append( (yyvsp[0].expression).code );
    t.append( ". " + dst + "\n" );
    t.append( "% " + dst + ", " ).append( (yyvsp[-2].expression).place ).append( ", " ).append( (yyvsp[0].expression).place ).append( "\n");

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( dst.c_str() );
}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 459 "miniL.y" /* yacc.c:1646  */
    { printf( "term -> var\n" ); }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 460 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "term -> SUB var\n" ); 
    string dst = newTemp();
    string t;

    t.append( (yyvsp[0].expression).code ).append( ". " + dst + "\n");
    if( (yyvsp[0].expression).arr ){
        t.append( "=[] " + dst + ", ").append( (yyvsp[0].expression).place).append( "\n" );
    }
    else {
        t.append( "= " + dst + ", " ).append( (yyvsp[0].expression).place ).append( "\n" );
    }
    t.append( "* ").append((yyval.expression).place ).append( ", -1\n");

    (yyval.expression).code = strdup( t.c_str() );
    (yyval.expression).place = strdup( (yyvsp[0].expression).place );
    (yyval.expression).arr = false;
}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 478 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "term -> NUMBER\n" ); 
    (yyval.expression).code = strdup( "" );
    (yyval.expression).place = strdup( std::to_string( (yyvsp[0].ival) ).c_str() );
}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 483 "miniL.y" /* yacc.c:1646  */
    {
    if(DEBUG_OUTPUT) printf( "term -> SUB NUMBER\n" ); 
    string s = "-" + std::to_string( (yyvsp[0].ival) );
    (yyval.expression).code = strdup( "" );
    (yyval.expression).place = strdup( s.c_str() );
}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 489 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "term -> L_PAREN expression R_PAREN\n" ); 
    (yyval.expression).code = strdup( (yyvsp[-1].expression).code );
    (yyval.expression).place = strdup( (yyvsp[-1].expression).place );
}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 494 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT ) printf( "term -> SUB L_PAREN expression R_PAREN\n" ); 
    string t;
    t.append( (yyvsp[-1].expression).code ).append( "* ").append((yyvsp[-1].expression).place).append( ", ").append( (yyvsp[-1].expression).place)
    t.append( ", -1\n" );

    (yyval.expression).code( t.c_str() );
    (yyval.expression).place( (yyvsp[-1].expression).place );
}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 503 "miniL.y" /* yacc.c:1646  */
    {
    if( DEBUG_OUTPUT) printf( "term -> ident L_PAREN expressions R_PAREN\n" ); 
    string t;
    //check undeclared fn
    if( definedFns.find( (yyvsp[-3].expression).place ) == definedFns.end() ) {
        string s = "Using an undeclared function " + (yyvsp[-3].expression).place;
        yyerror( s.c_str() );
    }

    string dst = newTemp();
    //. __temp__11
    //call fibonacci, __temp__11
    t.append( (yyvsp[-1].expression).code );
    t.append( ". " + dst + "\n" )
    t.append( "call " ).append((yyvsp[-3].expression).place ).append( ", " + dst + "\n" );

    (yyval.expression).code = strdup( t.c_str );
}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 521 "miniL.y" /* yacc.c:1646  */
    { printf( "term -> ident L_PAREN R_PAREN\n" ); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 524 "miniL.y" /* yacc.c:1646  */
    { printf( "expressions -> expression\n"); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 525 "miniL.y" /* yacc.c:1646  */
    { printf( "expression COMMA expressions\n"); }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2108 "y.tab.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 528 "miniL.y" /* yacc.c:1906  */


int main( int argc, char **argv ){
        if( argc > 1 ) {
                yyin = fopen( argv[1], "r" );
                if( yyin == NULL ) printf( "error opening file" );
        }
        yyparse();
        return 0;
}

string newTemp(){
    string temp = "_t" + to_string( numTemps );
    numTemps++;
}

string newLabel(){
    string temp = "_l" + to_string( numLabels );
    numLabels++;
}

void yyerror( const char* msg ){
    printf( "** line %d, position %d: %s\n", currLine, currPos, msg );
}


