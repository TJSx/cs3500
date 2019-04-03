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
#line 11 "spiveyt.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include "SymbolTable.h"
using namespace std;

#define ARITHMETIC_OP   1
#define LOGICAL_OP      2
#define RELATIONAL_OP   3
#define INDEX_PROD      4
#define NOT_INDEX_PROD  5

#define ERR_CANNOT_BE_FUNCT_NULL_LIST_OR_STR	0
#define ERR_CANNOT_BE_FUNCT					1 
#define ERR_CANNOT_BE_FUNCT_OR_NULL			2
#define ERR_CANNOT_BE_LIST					3 
#define ERR_MUST_BE_LIST					4
#define ERR_MUST_BE_FUNCT					5
#define ERR_MUST_BE_INTEGER					6
#define ERR_MUST_BE_INT_FLOAT_OR_BOOL			7
#define ERR_TOO_FEW_PARAMS					8
#define ERR_TOO_MANY_PARAMS					9
#define ERR_MULTIPLY_DEFINED_IDENT			10
#define ERR_UNDEFINED_IDENT					11
#define ERR_ERROR						12

const int NUM_ERR_MESSAGES = 13;  // should be ERR_ERROR + 1

const string ERR_MSG[NUM_ERR_MESSAGES] = {
"cannot be function or null or list or string",
"cannot be function",
"cannot be function or null",
"cannot be list",
"must be list",
"must be function",
"must be integer",
"must be integer or float or bool",
"Too few parameters in function call",
"Too many parameters in function call",
"Multiply defined identifier",
"Undefined identifier",
"<undefined error>"
};

// constant to suppress token printing
const bool suppressTokenOutput = true;

int line_num = 1;
int numExprs = 0;

stack<SYMBOL_TABLE> scopeStack; // stack of scope hashtables

bool isIntOrFloatOrBoolCompatible(const int theType);
bool isIntCompatible(const int theType);
bool isBoolCompatible(const int theType);
bool isFloatCompatible(const int theType);
bool isInvalidOperandType(const int theType);

void beginScope();
void endScope();
void cleanUp();
TYPE_INFO findEntryInAnyScope(const string the_name);

void semanticError(const int argNum, const int errNum);

void printTokenInfo(const char* token_type, const char* lexeme);

void printRule(const char *, const char *);

int yyerror(const char *s) 
{
    printf("Line %d: %s\n", line_num, s);
    cleanUp();
    exit(1);
}

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}


#line 154 "spiveyt.tab.c" /* yacc.c:339  */

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
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IDENT = 258,
    T_INTCONST = 259,
    T_FLOATCONST = 260,
    T_UNKNOWN = 261,
    T_STRCONST = 262,
    T_IF = 263,
    T_ELSE = 264,
    T_WHILE = 265,
    T_FUNCTION = 266,
    T_FOR = 267,
    T_IN = 268,
    T_NEXT = 269,
    T_BREAK = 270,
    T_TRUE = 271,
    T_FALSE = 272,
    T_QUIT = 273,
    T_PRINT = 274,
    T_CAT = 275,
    T_READ = 276,
    T_LPAREN = 277,
    T_RPAREN = 278,
    T_LBRACE = 279,
    T_RBRACE = 280,
    T_LBRACKET = 281,
    T_RBRACKET = 282,
    T_SEMICOLON = 283,
    T_COMMA = 284,
    T_ADD = 285,
    T_SUB = 286,
    T_MULT = 287,
    T_DIV = 288,
    T_MOD = 289,
    T_POW = 290,
    T_LT = 291,
    T_LE = 292,
    T_GT = 293,
    T_GE = 294,
    T_EQ = 295,
    T_NE = 296,
    T_NOT = 297,
    T_AND = 298,
    T_OR = 299,
    T_ASSIGN = 300,
    T_LIST = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 98 "spiveyt.y" /* yacc.c:355  */

    char* text;
    int num;
    bool flag;
    TYPE_INFO typeInfo;

#line 245 "spiveyt.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 262 "spiveyt.tab.c" /* yacc.c:358  */

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   148,   155,   162,   169,   176,   183,   190,
     197,   204,   211,   218,   225,   235,   242,   249,   256,   264,
     273,   283,   291,   296,   300,   309,   308,   327,   335,   345,
     350,   357,   356,   421,   428,   434,   443,   455,   469,   476,
     475,   492,   496,   503,   508,   528,   547,   554,   558,   565,
     570,   574,   580,   588,   606,   640,   666,   674,   708,   736,
     744,   751,   758,   765,   774,   779,   784,   791,   796,   801,
     806,   811,   818,   823,   828,   833,   838,   843,   850,   857,
     866,   883
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENT", "T_INTCONST", "T_FLOATCONST",
  "T_UNKNOWN", "T_STRCONST", "T_IF", "T_ELSE", "T_WHILE", "T_FUNCTION",
  "T_FOR", "T_IN", "T_NEXT", "T_BREAK", "T_TRUE", "T_FALSE", "T_QUIT",
  "T_PRINT", "T_CAT", "T_READ", "T_LPAREN", "T_RPAREN", "T_LBRACE",
  "T_RBRACE", "T_LBRACKET", "T_RBRACKET", "T_SEMICOLON", "T_COMMA",
  "T_ADD", "T_SUB", "T_MULT", "T_DIV", "T_MOD", "T_POW", "T_LT", "T_LE",
  "T_GT", "T_GE", "T_EQ", "T_NE", "T_NOT", "T_AND", "T_OR", "T_ASSIGN",
  "T_LIST", "$accept", "N_START", "N_EXPR", "N_CONST", "N_COMPOUND_EXPR",
  "N_EXPR_LIST", "N_IF_EXPR", "N_WHILE_EXPR", "$@1", "N_FOR_EXPR",
  "N_LIST_EXPR", "N_CONST_LIST", "N_ASSIGNMENT_EXPR", "@2", "N_INDEX",
  "N_QUIT_EXPR", "N_OUTPUT_EXPR", "N_INPUT_EXPR", "N_FUNCTION_DEF", "$@3",
  "N_PARAM_LIST", "N_NO_PARAMS", "N_PARAMS", "N_FUNCTION_CALL",
  "N_ARG_LIST", "N_NO_ARGS", "N_ARGS", "N_ARITHLOGIC_EXPR",
  "N_SIMPLE_ARITHLOGIC", "N_ADD_OP_LIST", "N_TERM", "N_MULT_OP_LIST",
  "N_FACTOR", "N_ADD_OP", "N_MULT_OP", "N_REL_OP", "N_VAR",
  "N_SINGLE_ELEMENT", "N_ENTIRE_VAR", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -17,   -55,   -55,   -55,   -16,   -14,   -55,    -8,   -55,
     -55,     2,     7,     8,    16,    15,    15,    47,    18,    41,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,    34,   -27,   -22,   -55,   -55,   -55,
      15,   -19,   -55,    15,    15,    20,    42,    23,    15,    15,
      44,    30,    31,    39,   -55,    51,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,    47,   -55,   -55,   -55,   -55,    47,   -55,
     -55,   -55,   -55,   -55,   -55,    47,    37,    53,   -55,   -55,
      15,    32,    55,   -55,    76,    68,   -55,    59,    60,    61,
     -55,    15,    62,    64,    56,    63,   -55,   -27,   -22,    15,
     -55,    65,    15,    15,    70,    66,    71,   -55,   -55,    15,
     -55,   -55,   -55,    31,   -55,    15,    51,   -55,   -55,   -55,
     -55,    69,   -55,    79,    15,    76,    73,    75,   -55,    72,
     -55,    67,    15,   -55,   -55,   -55,    15,    74,   -55,   -55,
     -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    81,    15,    17,    16,     0,     0,    39,     0,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    61,     6,     3,     4,     5,    11,     8,    14,     9,
      10,    12,    13,     7,    52,    56,    59,    60,    79,    78,
      49,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    81,    63,     0,     1,    72,    74,    73,
      75,    76,    77,     0,    64,    65,    66,    54,     0,    67,
      68,    70,    71,    69,    57,     0,    50,     0,    48,    47,
       0,     0,     0,    25,    43,     0,    35,     0,     0,     0,
      62,     0,     0,     0,    30,     0,    53,    56,    59,     0,
      46,     0,     0,     0,     0,    44,     0,    42,    41,     0,
      36,    37,    38,    22,    20,     0,     0,    28,    55,    58,
      51,     0,    32,    23,     0,     0,     0,     0,    21,     0,
      29,    80,     0,    26,    45,    40,     0,     0,    24,    27,
      80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,     0,   -54,   -26,    -9,   -55,   -55,   -55,   -55,
     -55,   -11,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -18,   -55,   -55,   -55,     9,   -55,    43,    13,
      45,    19,   -15,   -55,   -55,   -55,    77,   -55,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    76,    21,    22,    92,    23,    24,   104,    25,
      26,    95,    27,    81,    42,    28,    29,    30,    31,    45,
     106,   107,   108,    32,    77,    78,    79,    33,    34,    67,
      35,    74,    36,    68,    75,    63,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    94,    54,    64,    65,    40,    43,    80,    44,    41,
      69,    70,    71,    72,    46,    51,    52,    66,     1,     2,
       3,    73,     4,     5,    47,     6,     7,     8,   -34,    48,
      49,     9,    10,    11,    12,    13,    14,    15,    50,    16,
      55,    56,    84,    82,    83,    85,    86,    53,    87,    88,
      53,     2,     3,    90,     4,     2,     3,    17,     4,    91,
      98,    18,    94,     9,    10,    93,    99,     9,    10,    15,
      57,    58,    59,    60,    61,    62,   100,   102,   103,   105,
     101,   109,   110,   111,   112,   116,   117,   114,   132,    17,
     115,   113,   121,   124,   126,   125,   131,    16,   136,   137,
     135,   140,   122,   123,   128,   130,    96,   134,   120,   127,
     118,     0,   -33,    97,     0,   129,     0,   119,     0,     0,
       0,     0,     0,     0,   133,     0,     0,    89,     0,     0,
       0,     0,   138,     0,     0,     0,   139
};

static const yytype_int16 yycheck[] =
{
       0,    55,    17,    30,    31,    22,    22,    26,    22,    26,
      32,    33,    34,    35,    22,    15,    16,    44,     3,     4,
       5,    43,     7,     8,    22,    10,    11,    12,    45,    22,
      22,    16,    17,    18,    19,    20,    21,    22,    22,    24,
      22,     0,    22,    43,    44,     3,    23,     3,    48,    49,
       3,     4,     5,    23,     7,     4,     5,    42,     7,    28,
      75,    46,   116,    16,    17,    26,    29,    16,    17,    22,
      36,    37,    38,    39,    40,    41,    23,    45,    23,     3,
      80,    13,    23,    23,    23,    29,    23,    25,     9,    42,
      26,    91,    27,    23,    23,    29,    27,    24,    23,    27,
     126,    27,   102,   103,   113,   116,    63,   125,    99,   109,
      97,    -1,    45,    68,    -1,   115,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    50,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,   136
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    10,    11,    12,    16,
      17,    18,    19,    20,    21,    22,    24,    42,    46,    48,
      49,    50,    51,    53,    54,    56,    57,    59,    62,    63,
      64,    65,    70,    74,    75,    77,    79,    83,    84,    85,
      22,    26,    61,    22,    22,    66,    22,    22,    22,    22,
      22,    49,    49,     3,    79,    22,     0,    36,    37,    38,
      39,    40,    41,    82,    30,    31,    44,    76,    80,    32,
      33,    34,    35,    43,    78,    81,    49,    71,    72,    73,
      26,    60,    49,    49,    22,     3,    23,    49,    49,    83,
      23,    28,    52,    26,    50,    58,    75,    77,    79,    29,
      23,    49,    45,    23,    55,     3,    67,    68,    69,    13,
      23,    23,    23,    49,    25,    26,    29,    23,    76,    78,
      73,    27,    49,    49,    23,    29,    23,    49,    52,    49,
      58,    27,     9,    49,    69,    51,    23,    27,    49,    49,
      27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    50,    50,    50,
      51,    52,    52,    53,    53,    55,    54,    56,    57,    58,
      58,    60,    59,    61,    61,    62,    63,    63,    64,    66,
      65,    67,    67,    68,    69,    69,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    76,    76,    77,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    83,    83,
      84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     0,     5,     7,     0,     6,     7,     4,     3,
       1,     0,     5,     5,     0,     3,     4,     4,     4,     0,
       6,     1,     1,     0,     1,     3,     4,     1,     1,     0,
       1,     3,     1,     3,     2,     3,     0,     2,     3,     0,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1
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
        case 2:
#line 142 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("START", "EXPR");
                    printf("\n---- Completed parsing ----\n\n");
                    return 0;
                }
#line 1452 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 149 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "IF_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1463 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 156 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "WHILE_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1474 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 163 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "FOR_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1485 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 170 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "COMPOUND_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1496 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 177 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "ARITHLOGIC_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1507 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 184 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "ASSIGNMENT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1518 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 191 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "OUTPUT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1529 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 198 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "INPUT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1540 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 205 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "LIST_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1551 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 212 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "FUNCTION_DEF");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1562 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 219 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "FUNCTION_CALL");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1573 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 226 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "QUIT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    exit(1);
                }
#line 1585 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 236 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "INTCONST");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 1596 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 243 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "STRCONST");
                    (yyval.typeInfo).type = STR;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 1607 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "FLOATCONST");
                    (yyval.typeInfo).type = FLOAT;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 1618 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 257 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "TRUE");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;

                }
#line 1630 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 265 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "FALSE");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 1641 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 274 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("COMPOUND_EXPR",
                              "{ EXPR EXPR_LIST }");
                    (yyval.typeInfo).type = (yyvsp[-2].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-2].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-2].typeInfo).returnType;
                }
#line 1653 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 284 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR_LIST", "; EXPR EXPR_LIST");
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                }
#line 1664 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 291 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR_LIST", "epsilon");
                }
#line 1672 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 297 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("IF_EXPR", "IF ( EXPR ) EXPR");
                }
#line 1680 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 302 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("IF_EXPR", 
                              "IF ( EXPR ) EXPR ELSE EXPR");
		     }
#line 1689 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 309 "spiveyt.y" /* yacc.c:1646  */
    {
                    if(((yyvsp[0].typeInfo).type == FUNCTION) 
				  || ((yyvsp[0].typeInfo).type == LIST)
                       || ((yyvsp[0].typeInfo).type == NULL_TYPE) 
                       || ((yyvsp[0].typeInfo).type == STR)) 
                     semanticError(1,
                       ERR_CANNOT_BE_FUNCT_NULL_LIST_OR_STR);
                }
#line 1702 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 318 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("WHILE_EXPR",
                              "WHILE ( EXPR ) EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1714 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 329 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FOR_EXPR", 
                              "FOR ( IDENT IN EXPR ) EXPR");
                }
#line 1723 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 336 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("LIST_EXPR", 
                              "LIST ( CONST_LIST )");
                    (yyval.typeInfo).type = LIST;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 1735 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 346 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST_LIST", 
                              "CONST, CONST_LIST");
                }
#line 1744 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 351 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST_LIST", "CONST");
                }
#line 1752 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 357 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ASSIGNMENT_EXPR", 
                              "IDENT INDEX ASSIGN EXPR");
                    string lexeme = string((yyvsp[-1].text));
                    TYPE_INFO exprTypeInfo =
                        scopeStack.top().findEntry(lexeme);
                    if(exprTypeInfo.type == UNDEFINED) 
			    {
                      if(!suppressTokenOutput)
                        printf("___Adding %s to symbol table\n", 
                               (yyvsp[-1].text));
                      // add in as N/A type until the
                      // N_EXPR can be processed below to 
                      // get the correct type
                      scopeStack.top().addEntry(
                            SYMBOL_TABLE_ENTRY(lexeme,
                            {NOT_APPLICABLE, NOT_APPLICABLE,
                             NOT_APPLICABLE}, false));
			      (yyval.flag) = false;
                    }
                    else 
			    {
                     // set flag that ident already existed
				(yyval.flag) = true;
                    }
                }
#line 1783 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 384 "spiveyt.y" /* yacc.c:1646  */
    {
                    string lexeme = string((yyvsp[-4].text));
                    TYPE_INFO exprTypeInfo = 
                        scopeStack.top().findEntry(lexeme);
                    if(((yyvsp[-3].num) == INDEX_PROD) && 
                       (exprTypeInfo.type != LIST)) 
				semanticError(1, ERR_MUST_BE_LIST);
			    /*
			    Note:
			    Can check whether ident already
			    existed by seeing if $<flag>3 == true.
			    This might be useful in HW 4b.
			    */
                    if(exprTypeInfo.is_param == true)
                    {
			scopeStack.top().changeEntry(SYMBOL_TABLE_ENTRY(lexeme,
                                        {INT, (yyvsp[0].typeInfo).numParams, INT}, true));
			    if (((yyvsp[-3].num) == INDEX_PROD) && 
			        ((yyvsp[0].typeInfo).type == LIST))
				semanticError(1, ERR_CANNOT_BE_LIST);
                    }
                    else
                    {
                    scopeStack.top().changeEntry(
                         SYMBOL_TABLE_ENTRY(lexeme,
                           {(yyvsp[0].typeInfo).type, (yyvsp[0].typeInfo).numParams,
                            (yyvsp[0].typeInfo).returnType}, false));
			    if (((yyvsp[-3].num) == INDEX_PROD) && 
			        ((yyvsp[0].typeInfo).type == LIST))
				semanticError(1, ERR_CANNOT_BE_LIST);
                 	}   
	            (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 1823 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 423 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("INDEX", " [[ EXPR ]]");
                    (yyval.num) = INDEX_PROD;
			}
#line 1832 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 428 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("INDEX", " epsilon");
			    (yyval.num) = NOT_INDEX_PROD;
                }
#line 1841 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 435 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("QUIT_EXPR", "QUIT()");
                    (yyval.typeInfo).type = NULL_TYPE;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 1852 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 444 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("OUTPUT_EXPR", 
                              "PRINT ( EXPR )");
                    if(((yyvsp[-1].typeInfo).type == FUNCTION) || 
                      ((yyvsp[-1].typeInfo).type == NULL_TYPE)) 
				semanticError(1,
				 ERR_CANNOT_BE_FUNCT_OR_NULL);
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                }
#line 1868 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 456 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("OUTPUT_EXPR", 
                              "CAT ( EXPR )");
                    if(((yyvsp[-1].typeInfo).type == FUNCTION) || 
                       ((yyvsp[-1].typeInfo).type == NULL_TYPE)) 
				semanticError(1,
				 ERR_CANNOT_BE_FUNCT_OR_NULL);
                    (yyval.typeInfo).type = NULL_TYPE;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                }
#line 1884 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 470 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("INPUT_EXPR", "READ ( VAR )");
                }
#line 1892 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 476 "spiveyt.y" /* yacc.c:1646  */
    {
			    printRule("FUNCTION_DEF",
                              "FUNCTION ( PARAM_LIST )"
                              " COMPOUND_EXPR");
                	    beginScope();
                }
#line 1903 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 484 "spiveyt.y" /* yacc.c:1646  */
    {
                    (yyval.typeInfo).type = FUNCTION;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
			    endScope();
                }
#line 1914 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 493 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAM_LIST", "PARAMS");
                }
#line 1922 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 497 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAM_LIST", "NO PARAMS");
                }
#line 1930 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 503 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("NO_PARAMS", "epsilon");
                }
#line 1938 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 509 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAMS", "IDENT");
                    string lexeme = string((yyvsp[0].text));
                    if(!suppressTokenOutput)
                      printf("___Adding %s to symbol table\n",
                             (yyvsp[0].text));
                    // assuming params are ints
                    TYPE_INFO exprTypeInfo = 
                     {INT, NOT_APPLICABLE, NOT_APPLICABLE};
                    bool success = 
                     scopeStack.top().
                      addEntry(SYMBOL_TABLE_ENTRY
                        (lexeme, exprTypeInfo, true));
                    if(!success) 
                    {
				semanticError(0,
				 ERR_MULTIPLY_DEFINED_IDENT);
                    }
                }
#line 1962 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 529 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAMS", "IDENT, PARAMS");
                    string lexeme = string((yyvsp[-2].text));
                    if(!suppressTokenOutput)
                     printf("___Adding %s to symbol table\n",
                           (yyvsp[-2].text));
                    // assuming params are ints 
                    TYPE_INFO exprTypeInfo = 
                     {INT, NOT_APPLICABLE, NOT_APPLICABLE};
                    bool success =
                     scopeStack.top().addEntry(
                      SYMBOL_TABLE_ENTRY(lexeme, exprTypeInfo, true));
                    if(!success) 
				semanticError(0,
				 ERR_MULTIPLY_DEFINED_IDENT);
                }
#line 1983 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 548 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FUNCTION_CALL", "IDENT"
                              " ( ARG_LIST )");
                }
#line 1992 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 555 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARG_LIST", "ARGS");
                }
#line 2000 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 559 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARG_LIST", "NO_ARGS");
                }
#line 2008 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 565 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("NO_ARGS", "epsilon");
                }
#line 2016 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 571 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARGS", "EXPR");
                }
#line 2024 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 575 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARGS", "EXPR, ARGS");
                }
#line 2032 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 581 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARITHLOGIC_EXPR",
                              "SIMPLE_ARITHLOGIC");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 2044 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 590 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARITHLOGIC_EXPR",
                              "SIMPLE_ARITHLOGIC REL_OP "
                              "SIMPLE_ARITHLOGIC");
                    if(isInvalidOperandType((yyvsp[-2].typeInfo).type))
                    	semanticError(1,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                    if(isInvalidOperandType((yyvsp[0].typeInfo).type)) 
                   	semanticError(2,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                    (yyval.typeInfo).type = BOOL; 
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 2063 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 607 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("SIMPLE_ARITHLOGIC",
                              "TERM ADD_OP_LIST");
			    if ((yyvsp[0].typeInfo).type != NOT_APPLICABLE)
			    {
                      if(isInvalidOperandType((yyvsp[-1].typeInfo).type))
                        semanticError(1,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                      if(isInvalidOperandType((yyvsp[0].typeInfo).type))
                        semanticError(2,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
				if (isBoolCompatible((yyvsp[-1].typeInfo).type) &&
				    isBoolCompatible((yyvsp[0].typeInfo).type))
				  (yyval.typeInfo).type = BOOL;
				else if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
				         isIntCompatible((yyvsp[0].typeInfo).type))
                             (yyval.typeInfo).type = INT;
                     else if (isFloatCompatible((yyvsp[-1].typeInfo).type) ||
				         isFloatCompatible((yyvsp[0].typeInfo).type))
				       (yyval.typeInfo).type = FLOAT;
				else (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
				(yyval.typeInfo).numParams = NOT_APPLICABLE;
				(yyval.typeInfo).returnType = NOT_APPLICABLE;
			    }
                    else 
			    {
				(yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
			    }
                }
#line 2099 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 641 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP_LIST",
                              "ADD_OP TERM ADD_OP_LIST");
			    int argWithErr =
				((yyvsp[0].typeInfo).type == NOT_APPLICABLE)? 2: 1;
                    if(isInvalidOperandType((yyvsp[-1].typeInfo).type))                                          				semanticError(argWithErr,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
			    if ((yyvsp[-2].num) == LOGICAL_OP)
				(yyval.typeInfo).type = BOOL;
			    else
			    {
				if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
				  (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
				else
				{
				  if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
					 isIntCompatible((yyvsp[0].typeInfo).type))
                          (yyval.typeInfo).type = INT;
                       else (yyval.typeInfo).type = FLOAT;
				}
                    }
                }
#line 2128 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 666 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP_LIST", "epsilon");
			    (yyval.typeInfo).type = NOT_APPLICABLE;
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 2139 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 675 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("TERM",
                              "FACTOR MULT_OP_LIST");
			    if ((yyvsp[0].typeInfo).type != NOT_APPLICABLE)
			    {
				if(isInvalidOperandType((yyvsp[-1].typeInfo).type))
                        semanticError(1,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                     	if(isInvalidOperandType((yyvsp[0].typeInfo).type))
                        semanticError(2,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                     	(yyval.typeInfo).numParams = NOT_APPLICABLE;
                     	(yyval.typeInfo).returnType = NOT_APPLICABLE;
				if (isBoolCompatible((yyvsp[-1].typeInfo).type) &&
				    isBoolCompatible((yyvsp[0].typeInfo).type))
				  (yyval.typeInfo).type = BOOL;
				else
				{
				  if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
				      isIntCompatible((yyvsp[0].typeInfo).type))
                            (yyval.typeInfo).type = INT;
                        else (yyval.typeInfo).type = FLOAT;
				}
			    }
                    else 
			    {
				(yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
				(yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
				(yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
			    }
                }
#line 2175 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 709 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP_LIST",
                              "MULT_OP FACTOR MULT_OP_LIST");
			    int argWithErr = 
				((yyvsp[0].typeInfo).type == NOT_APPLICABLE)? 2: 1;
                    if(isInvalidOperandType((yyvsp[-1].typeInfo).type))                    				semanticError(argWithErr,
				  ERR_MUST_BE_INT_FLOAT_OR_BOOL);
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
			    if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
				  (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
			    else
			    {
                      if(isInvalidOperandType((yyvsp[0].typeInfo).type))                    				  semanticError(argWithErr,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
			      if ((yyvsp[-2].num) == LOGICAL_OP)
				  (yyval.typeInfo).type = BOOL;
			      else
			      {
				  if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
				      isIntCompatible((yyvsp[0].typeInfo).type))
				    (yyval.typeInfo).type = INT;
				  else (yyval.typeInfo).type = FLOAT;
			      }
                    }
                }
#line 2206 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 736 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP_LIST", "epsilon");
			    (yyval.typeInfo).type = NOT_APPLICABLE;
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 2217 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 745 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "VAR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 2228 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 752 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "CONST");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 2239 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 759 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "( EXPR )");
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                }
#line 2250 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 766 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "! FACTOR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 2261 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 775 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP", "+");
                    (yyval.num) = ARITHMETIC_OP;
                }
#line 2270 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 780 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP", "-");
                    (yyval.num) = ARITHMETIC_OP;
                }
#line 2279 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 785 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP", "|");
                    (yyval.num) = LOGICAL_OP;
                }
#line 2288 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 792 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "*");
                    (yyval.num) = ARITHMETIC_OP;
                }
#line 2297 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 797 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "/");
                    (yyval.num) = ARITHMETIC_OP;
                }
#line 2306 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 802 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "&");
                    (yyval.num) = LOGICAL_OP;
                }
#line 2315 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 807 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "\%\%");
                    (yyval.num) = ARITHMETIC_OP;
                }
#line 2324 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 812 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "^");
                    (yyval.num) = ARITHMETIC_OP;
                }
#line 2333 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 819 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "<");
                    (yyval.num) = RELATIONAL_OP;
                }
#line 2342 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 824 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", ">");
                    (yyval.num) = RELATIONAL_OP;
                }
#line 2351 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 829 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "<=");
                    (yyval.num) = RELATIONAL_OP;
                }
#line 2360 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 834 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", ">=");
                    (yyval.num) = RELATIONAL_OP;
                }
#line 2369 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 839 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "==");
                    (yyval.num) = RELATIONAL_OP;
                }
#line 2378 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 844 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "!=");
                    (yyval.num) = RELATIONAL_OP;
                }
#line 2387 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 851 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("VAR", "ENTIRE_VAR");
                    (yyval.typeInfo).type == (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 2398 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 858 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("VAR", "SINGLE_ELEMENT");
                    (yyval.typeInfo).type == (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                }
#line 2409 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 868 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("SINGLE_ELEMENT", "IDENT"
                              " [[ EXPR ]]");
                    TYPE_INFO exprTypeInfo =
                      findEntryInAnyScope((yyvsp[-5].text));
                    if(exprTypeInfo.type == UNDEFINED) 
				semanticError(0, ERR_UNDEFINED_IDENT);
                    if(exprTypeInfo.type != LIST) 
				semanticError(1, ERR_MUST_BE_LIST);  
			    (yyval.typeInfo).type = INT_OR_STR_OR_FLOAT_OR_BOOL;
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                }
#line 2427 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 884 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ENTIRE_VAR", "IDENT");
                    TYPE_INFO exprTypeInfo = 
                      findEntryInAnyScope(string((yyvsp[0].text)));
                    if(exprTypeInfo.type == UNDEFINED)
                      semanticError(0, ERR_UNDEFINED_IDENT);
                    (yyval.typeInfo).type = exprTypeInfo.type;
                    (yyval.typeInfo).numParams = exprTypeInfo.numParams;
                    (yyval.typeInfo).returnType = exprTypeInfo.returnType;
                }
#line 2442 "spiveyt.tab.c" /* yacc.c:1646  */
    break;


#line 2446 "spiveyt.tab.c" /* yacc.c:1646  */
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
#line 896 "spiveyt.y" /* yacc.c:1906  */


#include "lex.yy.c"
extern FILE *yyin;

//  Construct a string as an argument number (1st param, 0
//  if no argument number in message) and message (2nd param
//  index position in ERR_MSG[]). Then call yyerror with that
//  string.
void semanticError(const int argNum, const int errNum)
{
  string errorMsg;
  int errNo = errNum;

  if ((errNum < 0) || (errNum > NUM_ERR_MESSAGES-1))
    errNo = ERR_ERROR;
  if (argNum > 0)
    errorMsg = "Arg " + to_string(argNum) + " ";
  else errorMsg = "";
  errorMsg += ERR_MSG[errNo];
  yyerror(errorMsg.c_str());
}

// Output token (1st param) and lexeme (2nd param).
void printTokenInfo(const char* token_type, const char* lexeme)
{
  if(!suppressTokenOutput) 
    printf("TOKEN: %s \t\t LEXEME: %s\n", token_type, lexeme);
}

// Output production info as nonterm on left-hand side (1st
// param) and symbols on right-hand side (2nd param).
void printRule(const char *lhs, const char *rhs)
{
  if(!suppressTokenOutput) 
    printf("%s -> %s\n", lhs, rhs);
}

// Determine whether given type is compatible with INT, FLOAT,
// or BOOL.
bool isIntOrFloatOrBoolCompatible(const int theType)
{
    return((theType == INT) || (theType == FLOAT) ||
		 (theType == BOOL) ||
           (theType == INT_OR_STR_OR_FLOAT_OR_BOOL));
}

// Determine whether given type is compatible with INT.
bool isIntCompatible(const int theType)
{
    return((theType == INT) ||
		(theType == BOOL) ||
           (theType == INT_OR_STR_OR_FLOAT_OR_BOOL));
}

// Determine whether given type is compatible with BOOL.
bool isBoolCompatible(const int theType)
{
    return((theType == BOOL) ||
           (theType == INT_OR_STR_OR_FLOAT_OR_BOOL));
}

// Determine whether given type is compatible with FLOAT.
bool isFloatCompatible(const int theType)
{
    return((theType == FLOAT) ||
           (theType == INT_OR_STR_OR_FLOAT_OR_BOOL));
}

// Determine whether given type is considered an invalid
// operand type.
bool isInvalidOperandType(const int theType)
{
    return((theType == FUNCTION) ||
           (theType == NULL_TYPE) ||
		(theType == LIST) ||
           (theType == STR));
}

// Push a new SYMBOL_TABLE onto scopeStack.
void beginScope() 
{
    scopeStack.push(SYMBOL_TABLE());
    if(!suppressTokenOutput)
        printf("\n___Entering new scope...\n\n");
}

// Pop a SYMBOL_TABLE from scopeStack.
void endScope() 
{
    scopeStack.pop();
    if(!suppressTokenOutput)
        printf("\n___Exiting scope...\n\n");
}

// Pop all SYMBOL_TABLE's from scopeStack.
void cleanUp() 
{
    if (scopeStack.empty())
        return;
    else {
        scopeStack.pop();
        cleanUp();
    }
}

// If the_name exists in any SYMBOL_TABLE in scopeStack, return
// its TYPE_INFO; otherwise, return a TYPE_INFO that contains
// type UNDEFINED.
TYPE_INFO findEntryInAnyScope(const string the_name) 
{
    TYPE_INFO info = {UNDEFINED, NOT_APPLICABLE,
                      NOT_APPLICABLE};
    if (scopeStack.empty()) return(info);
    info = scopeStack.top().findEntry(the_name);
    if (info.type != UNDEFINED)
      return(info);
    else 
    { // check in "next higher" scope
        SYMBOL_TABLE symbolTable = scopeStack.top();
        scopeStack.pop();
        info = findEntryInAnyScope(the_name);
        scopeStack.push(symbolTable); // restore the stack
        return(info);
    }
}

int main() 
{
    beginScope();
    do {
        yyparse();
    } while (!feof(yyin));
    endScope();

    return 0;
}
