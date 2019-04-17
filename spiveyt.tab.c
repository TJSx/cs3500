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
#include <string.h>
#include <iostream>
#include <string>
#include <stack>
#include "SymbolTable.h"
#include <math.h>
#include <cmath>
using namespace std;

#define ARITHMETIC_OP   1
#define LOGICAL_OP      2
#define RELATIONAL_OP   3
#define MOD 4
#define DIV 5
#define MUL 6
#define ADD 7
#define SUB 8
#define POW 9
#define LESS   10
#define GREATER   11
#define LEQ   12
#define GEQ   13
#define NEQ   14
#define EQL   15
#define OR   16
#define AND  17



#define ERR_CANNOT_BE_FUNCT_NULL_LIST_OR_STR	0
#define ERR_CANNOT_BE_FUNCT					1
#define ERR_CANNOT_BE_FUNCT_OR_NULL			2
#define ERR_CANNOT_BE_FUNCT_OR_NULL_OR_LIST		3
#define ERR_CANNOT_BE_LIST					4
#define ERR_MUST_BE_LIST					5
#define ERR_MUST_BE_FUNCT					6
#define ERR_MUST_BE_INTEGER					7
#define ERR_MUST_BE_INT_FLOAT_OR_BOOL			8
#define ERR_TOO_FEW_PARAMS					9
#define ERR_TOO_MANY_PARAMS					10
#define ERR_NON_INT_FUNCT_PARAM				11
#define ERR_MULTIPLY_DEFINED_IDENT			12
#define ERR_UNDEFINED_IDENT					13
#define ERR_ERROR						14

const int NUM_ERR_MESSAGES = 15;  // should be ERR_ERROR + 1

const string ERR_MSG[NUM_ERR_MESSAGES] = {
"cannot be function or null or list or string",
"cannot be function",
"cannot be function or null",
"cannot be function or null or list",
"cannot be list",
"must be list",
"must be function",
"must be integer",
"must be integer or float or bool",
"Too few parameters in function call",
"Too many parameters in function call",
"Function parameters must be integer",
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
bool isListCompatible(const int theType);
bool isInvalidOperandType(const int theType);
bool isArith(const int theType);
bool isRel(const int theType);
bool isLog(const int theType);
void beginScope();
void endScope();
void cleanUp();
void printValue(TYPE_INFO type_info);
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


#line 179 "spiveyt.tab.c" /* yacc.c:339  */

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
#line 124 "spiveyt.y" /* yacc.c:355  */

    char* text;
    int num;
    bool flag;
    TYPE_INFO typeInfo;

#line 270 "spiveyt.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 287 "spiveyt.tab.c" /* yacc.c:358  */

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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

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
       0,   170,   170,   179,   188,   198,   208,   245,   259,   296,
     334,   344,   353,   363,   373,   386,   395,   404,   413,   422,
     433,   504,   579,   589,   612,   647,   667,   679,   678,   701,
     728,   700,   742,   755,   770,   789,   788,  1003,  1013,  1019,
    1030,  1078,  1095,  1130,  1137,  1129,  1152,  1156,  1163,  1168,
    1187,  1207,  1228,  1234,  1243,  1248,  1258,  1257,  1271,  1289,
    1365,  1511,  1671,  1681,  1868,  2063,  2074,  2128,  2136,  2171,
    2194,  2199,  2204,  2211,  2217,  2222,  2227,  2232,  2239,  2244,
    2249,  2254,  2259,  2264,  2271,  2283,  2297,  2334
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
  "N_EXPR_LIST", "N_IF_EXPR", "N_COND_IF", "N_THEN_EXPR", "N_WHILE_EXPR",
  "$@1", "N_FOR_EXPR", "$@2", "$@3", "N_LIST_EXPR", "N_CONST_LIST",
  "N_ASSIGNMENT_EXPR", "@4", "N_INDEX", "N_QUIT_EXPR", "N_OUTPUT_EXPR",
  "N_INPUT_EXPR", "N_FUNCTION_DEF", "$@5", "@6", "N_PARAM_LIST",
  "N_NO_PARAMS", "N_PARAMS", "N_FUNCTION_CALL", "N_ARG_LIST", "N_NO_ARGS",
  "N_ARGS", "$@7", "N_ARITHLOGIC_EXPR", "N_SIMPLE_ARITHLOGIC",
  "N_ADD_OP_LIST", "N_TERM", "N_MULT_OP_LIST", "N_FACTOR", "N_ADD_OP",
  "N_MULT_OP", "N_REL_OP", "N_VAR", "N_SINGLE_ELEMENT", "N_ENTIRE_VAR", YY_NULLPTR
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

#define YYPACT_NINF -56

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -19,   -56,   -56,   -56,   -12,    -8,   -56,     2,   -56,
     -56,     8,    10,    11,    14,     1,     1,    24,    15,    38,
     -56,   -56,   -56,   -56,    16,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,    36,     4,    35,   -56,   -56,
     -56,     1,    25,   -56,     1,     1,    20,    51,    33,     1,
       1,    34,    37,    31,    45,   -56,    48,   -56,     1,   -56,
     -56,   -56,   -56,   -56,   -56,    24,   -56,   -56,   -56,   -56,
      24,   -56,   -56,   -56,   -56,   -56,   -56,    24,    32,    56,
     -56,   -56,     1,    39,   -56,   -56,    77,   -56,   -56,    58,
      60,   -56,   -56,     1,    61,    59,    62,    64,   -56,    79,
     -56,     4,    35,    63,   -56,    67,     1,    66,    68,   -56,
     -56,   -56,    82,   -56,   -56,    31,   -56,     1,    48,   -56,
       1,   -56,   -56,     1,    69,   -56,     1,    77,    75,     1,
     -56,    72,   -56,   -56,   -56,    55,   -56,   -56,    78,   -56,
      74,   -56,    80,   -56,     1,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    87,    15,    17,    16,     0,     0,    43,     0,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    67,     6,     3,     0,     4,     5,    11,     8,    14,
       9,    10,    12,    13,     7,    58,    62,    65,    66,    85,
      84,    54,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    87,    69,     0,     1,     0,    78,
      80,    79,    81,    82,    83,     0,    70,    71,    72,    60,
       0,    73,    74,    76,    77,    75,    63,     0,    55,     0,
      53,    52,     0,     0,    25,    27,    48,    29,    39,     0,
       0,    42,    68,     0,     0,     0,    34,     0,    26,    23,
      59,    62,    65,     0,    51,     0,     0,     0,    49,    44,
      47,    46,     0,    40,    41,    22,    20,     0,     0,    32,
       0,    61,    64,     0,     0,    36,     0,     0,     0,     0,
      21,     0,    33,    24,    57,    86,    28,    50,     0,    30,
       0,    45,     0,    86,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,     0,   -55,   -48,   -11,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -13,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -20,   -56,   -56,
     -56,   -14,   -56,   -56,    43,     9,    41,    12,   -15,   -56,
     -56,   -56,   -56,   -56,   -56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    78,    21,    22,    94,    23,    24,    99,    25,
     107,    26,   112,   142,    27,    97,    28,    83,    43,    29,
      30,    31,    32,    46,   128,   109,   110,   111,    33,    79,
      80,    81,   103,    34,    35,    69,    36,    76,    37,    70,
      77,    65,    38,    39,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    96,    55,    41,     1,     2,     3,    42,     4,     5,
      44,     6,     7,     8,    45,    52,    53,     9,    10,    11,
      12,    13,    14,    15,    47,    16,   -38,    54,     2,     3,
      48,     4,    49,    50,    66,    67,    51,    56,    57,    58,
       9,    10,    86,    17,    84,    85,    15,    18,    68,    89,
      90,    82,     2,     3,    87,     4,    88,    91,    98,    93,
      92,   -56,   102,    96,     9,    10,    17,    71,    72,    73,
      74,    95,    59,    60,    61,    62,    63,    64,    75,   104,
     108,   113,   105,   114,   106,   117,   116,   119,   120,   126,
     141,   118,   123,   115,   124,   129,   135,   127,   138,   140,
     -37,   143,    16,   144,   130,   132,   125,   137,   100,   134,
     121,   101,     0,     0,   122,     0,     0,   131,     0,     0,
     133,     0,     0,     0,     0,     0,   136,     0,     0,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145
};

static const yytype_int16 yycheck[] =
{
       0,    56,    17,    22,     3,     4,     5,    26,     7,     8,
      22,    10,    11,    12,    22,    15,    16,    16,    17,    18,
      19,    20,    21,    22,    22,    24,    45,     3,     4,     5,
      22,     7,    22,    22,    30,    31,    22,    22,     0,    23,
      16,    17,    22,    42,    44,    45,    22,    46,    44,    49,
      50,    26,     4,     5,     3,     7,    23,    23,    58,    28,
      23,    29,    77,   118,    16,    17,    42,    32,    33,    34,
      35,    26,    36,    37,    38,    39,    40,    41,    43,    23,
       3,    23,    82,    23,    45,    26,    25,    23,     9,    23,
     138,    29,    29,    93,    27,    13,    27,    29,    23,    27,
      45,    27,    24,    23,   115,   118,   106,   127,    65,   123,
     101,    70,    -1,    -1,   102,    -1,    -1,   117,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    10,    11,    12,    16,
      17,    18,    19,    20,    21,    22,    24,    42,    46,    48,
      49,    50,    51,    53,    54,    56,    58,    61,    63,    66,
      67,    68,    69,    75,    80,    81,    83,    85,    89,    90,
      91,    22,    26,    65,    22,    22,    70,    22,    22,    22,
      22,    22,    49,    49,     3,    85,    22,     0,    23,    36,
      37,    38,    39,    40,    41,    88,    30,    31,    44,    82,
      86,    32,    33,    34,    35,    43,    84,    87,    49,    76,
      77,    78,    26,    64,    49,    49,    22,     3,    23,    49,
      49,    23,    23,    28,    52,    26,    50,    62,    49,    55,
      81,    83,    85,    79,    23,    49,    45,    57,     3,    72,
      73,    74,    59,    23,    23,    49,    25,    26,    29,    23,
       9,    82,    84,    29,    27,    49,    23,    29,    71,    13,
      52,    49,    62,    49,    78,    27,    49,    74,    23,    49,
      27,    51,    60,    27,    23,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    50,    50,    50,
      51,    52,    52,    53,    53,    54,    55,    57,    56,    59,
      60,    58,    61,    62,    62,    64,    63,    65,    65,    66,
      67,    67,    68,    70,    71,    69,    72,    72,    73,    74,
      74,    75,    76,    76,    77,    78,    79,    78,    80,    80,
      81,    82,    82,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     0,     3,     5,     3,     1,     0,     6,     0,
       0,     9,     4,     3,     1,     0,     5,     5,     0,     3,
       4,     4,     3,     0,     0,     7,     1,     1,     0,     1,
       3,     4,     1,     1,     0,     1,     0,     4,     1,     3,
       2,     3,     0,     2,     3,     0,     1,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     1
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
#line 171 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("START", "EXPR");
                    printf("\n---- Completed parsing ----\n");
                    printf("\nValue of the expression is: ");
                    printValue((yyvsp[0].typeInfo));
                    return 0;
                }
#line 1483 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 180 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "IF_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;

                }
#line 1496 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 189 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "WHILE_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;


                }
#line 1510 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 199 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "FOR_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;


                    }
#line 1524 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "COMPOUND_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;




                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }

                    }
#line 1565 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 246 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "ARITHLOGIC_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;

                    }
#line 1583 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 260 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "ASSIGNMENT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;




                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }

                    }
#line 1624 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 297 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "OUTPUT_EXPR");

                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;

                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
                    }
#line 1666 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 335 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "INPUT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;


                }
#line 1680 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 345 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "LIST_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;

                    }
#line 1693 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 354 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "FUNCTION_DEF");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;


                    }
#line 1707 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 364 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "FUNCTION_CALL");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;


                    }
#line 1721 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 374 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR", "QUIT_EXPR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;


                    exit(1);
                }
#line 1736 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 387 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "INTCONST");
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).val_int = atoi((yyvsp[0].text));
                }
#line 1749 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 396 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "STRCONST");
                    (yyval.typeInfo).type = STR;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].text));
                }
#line 1762 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 405 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "FLOATCONST");
                    (yyval.typeInfo).type = FLOAT;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).val_float = atof((yyvsp[0].text));
                }
#line 1775 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 414 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "TRUE");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).val_bool = true;
                }
#line 1788 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 423 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST", "FALSE");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).val_bool = false;
                }
#line 1801 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 434 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("COMPOUND_EXPR",
                              "{ EXPR EXPR_LIST }");
			    if ((yyvsp[-1].typeInfo).type == NOT_APPLICABLE)
			    {
                    (yyval.typeInfo).type = (yyvsp[-2].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-2].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-2].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-2].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[-2].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-2].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-2].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-2].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-2].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-2].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;

                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
			    }
			    else
			    {
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;

                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
			    }
                }
#line 1874 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 505 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR_LIST", "; EXPR EXPR_LIST");
			    if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
			    {
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;




                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
			    }
			    else
			    {
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;
                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {

                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;




                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
			    }
                }
#line 1952 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 579 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("EXPR_LIST", "epsilon");
                    (yyval.typeInfo).type = NOT_APPLICABLE;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).is_null = true;
                }
#line 1965 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 590 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("IF_EXPR", "IF ( EXPR ) EXPR");

                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    if((yyvsp[-2].typeInfo).val_bool || (yyvsp[-2].typeInfo).val_int != 0 || (yyvsp[-2].typeInfo).val_float != 0)
					{
                        (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                        (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                        (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                        (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                        (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                        strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                        (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;
                    }
					else
					{
                        (yyval.typeInfo).type = NULL_TYPE;
                        (yyval.typeInfo).is_null = true;
                    }
			}
#line 1992 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 613 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("IF_EXPR",
                              "IF ( EXPR ) EXPR ELSE EXPR");
                    if((yyvsp[0].typeInfo).type == FUNCTION)
                     semanticError(3, ERR_CANNOT_BE_FUNCT);
                    (yyval.typeInfo).type = (yyvsp[-2].typeInfo).type ^ (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = (yyvsp[-2].typeInfo).is_param || (yyvsp[0].typeInfo).is_param;

                    if((yyvsp[-4].typeInfo).val_bool || (yyvsp[-4].typeInfo).val_int != 0 || (yyvsp[-4].typeInfo).val_float != 0)
					{
                        (yyval.typeInfo).type = (yyvsp[-2].typeInfo).type;
                        (yyval.typeInfo).is_param = (yyvsp[-2].typeInfo).is_param;
                        (yyval.typeInfo).val_bool = (yyvsp[-2].typeInfo).val_bool;
                        (yyval.typeInfo).val_int = (yyvsp[-2].typeInfo).val_int;
                        (yyval.typeInfo).val_float = (yyvsp[-2].typeInfo).val_float;
                        strcpy((yyval.typeInfo).val_string, (yyvsp[-2].typeInfo).val_string);
                        (yyval.typeInfo).is_null= (yyvsp[-2].typeInfo).is_null;
                    }
					else
					{
                        (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                        (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                        (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                        (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                        (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                        strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                        (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;

                    }
                }
#line 2029 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 648 "spiveyt.y" /* yacc.c:1646  */
    {
                    if(((yyvsp[0].typeInfo).type == FUNCTION)
                       || ((yyvsp[0].typeInfo).type == LIST)
                       || ((yyvsp[0].typeInfo).type == NULL_TYPE)
                       || ((yyvsp[0].typeInfo).type == STR))
					   {
                    printValue((yyvsp[0].typeInfo));
                     semanticError(1,
                       ERR_CANNOT_BE_FUNCT_NULL_LIST_OR_STR);
					   }

                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;
			}
#line 2051 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 668 "spiveyt.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].typeInfo).type == FUNCTION)
                     semanticError(2, ERR_CANNOT_BE_FUNCT);
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
			}
#line 2064 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 679 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("WHILE_EXPR",
                              "WHILE ( EXPR ) EXPR");
                    if(((yyvsp[0].typeInfo).type == FUNCTION)
                       || ((yyvsp[0].typeInfo).type == LIST)
                       || ((yyvsp[0].typeInfo).type == NULL_TYPE)
                       || ((yyvsp[0].typeInfo).type == STR))
                     semanticError(1,
                       ERR_CANNOT_BE_FUNCT_NULL_LIST_OR_STR);
                }
#line 2079 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 690 "spiveyt.y" /* yacc.c:1646  */
    {
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;

                    (yyval.typeInfo).is_null = true;
                }
#line 2092 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 701 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FOR_EXPR",
                              "FOR ( IDENT IN EXPR ) EXPR");
                    string lexeme = string((yyvsp[0].text));
                    TYPE_INFO exprTypeInfo =
                      scopeStack.top().findEntry(lexeme);
                    if(exprTypeInfo.type == UNDEFINED)
                    {
                        if(!suppressTokenOutput)
                            printf("___Adding %s to symbol"
                                   " table\n", (yyvsp[0].text));
                        scopeStack.top().addEntry(
                            SYMBOL_TABLE_ENTRY(lexeme,
                            {INT_OR_STR_OR_FLOAT_OR_BOOL,
				       NOT_APPLICABLE, NOT_APPLICABLE,
					 false}));
			   }
			   else
			   {
			    if((exprTypeInfo.type == FUNCTION) ||
                       (exprTypeInfo.type == NULL_TYPE) ||
                       (exprTypeInfo.type == LIST))
				semanticError(1,
 				 ERR_CANNOT_BE_FUNCT_OR_NULL_OR_LIST);
			   }
                }
#line 2123 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 728 "spiveyt.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].typeInfo).type != LIST)
				semanticError(2, ERR_MUST_BE_LIST);
			}
#line 2132 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 733 "spiveyt.y" /* yacc.c:1646  */
    {
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).is_null = true;
			}
#line 2144 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 743 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("LIST_EXPR",
                              "LIST ( CONST_LIST )");
                    (yyval.typeInfo).type = LIST;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).tlist = (yyvsp[-1].typeInfo).tlist;

                }
#line 2159 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 756 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("CONST_LIST",
                              "CONST, CONST_LIST");
                    Trial *filler = NULL;
                    filler = new Trial;
                    filler->type = (yyvsp[-2].typeInfo).type;
                    filler->val_bool = (yyvsp[-2].typeInfo).val_bool;
                    filler->val_int = (yyvsp[-2].typeInfo).val_int;
                    filler->val_float = (yyvsp[-2].typeInfo).val_float;
                    strcpy(filler->val_string, (yyvsp[-2].typeInfo).val_string);
                    filler->tlist = (yyvsp[0].typeInfo).tlist;
                    filler->length = (yyvsp[0].typeInfo).tlist->length+1;
                    (yyval.typeInfo).tlist = filler;
                }
#line 2178 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 771 "spiveyt.y" /* yacc.c:1646  */
    {
                    Trial *filler = NULL;
                    filler = new Trial;

                    filler->type = (yyvsp[0].typeInfo).type;
                    filler->val_bool = (yyvsp[0].typeInfo).val_bool;
                    filler->val_int = (yyvsp[0].typeInfo).val_int;
                    filler->val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy(filler->val_string, (yyvsp[0].typeInfo).val_string);
                    filler->tlist = NULL;
                    filler->length = 1;
                    (yyval.typeInfo).tlist = filler;

                    printRule("CONST_LIST", "CONST");
                }
#line 2198 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 789 "spiveyt.y" /* yacc.c:1646  */
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
                             NOT_APPLICABLE, false}));
                      // set flag that ident didn't already
                        // exist
                         (yyval.flag) = false;
                    }
                    else
			   {
                     // set flag that ident already existed
				(yyval.flag) = true;
                    }
                }
#line 2234 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 821 "spiveyt.y" /* yacc.c:1646  */
    {
                    string lexeme = string((yyvsp[-4].text));
                    TYPE_INFO exprTypeInfo =
                        scopeStack.top().findEntry(lexeme);
                    if(((yyvsp[-3].typeInfo).is_index) &&
				 (!isListCompatible(
                          exprTypeInfo.type)))
				semanticError(1, ERR_MUST_BE_LIST);
			    if ((yyvsp[-2].flag))  // ident already existed
                    {
				if (exprTypeInfo.is_param && !isIntCompatible((yyvsp[0].typeInfo).type))
                     semanticError(1, ERR_MUST_BE_INTEGER);

                  if(!(yyvsp[-3].typeInfo).is_index)
                  {
                    TYPE_INFO type_info;
                    type_info.type = (yyvsp[0].typeInfo).type;
                    type_info.numParams = (yyvsp[0].typeInfo).numParams;
                    type_info.returnType = (yyvsp[0].typeInfo).returnType;
                    type_info.is_param = (yyvsp[0].typeInfo).is_param;
                    type_info.val_bool = (yyvsp[0].typeInfo).val_bool;
                    type_info.val_int = (yyvsp[0].typeInfo).val_int;
                    type_info.val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy(type_info.val_string, (yyvsp[0].typeInfo).val_string);
                    type_info.is_null= (yyvsp[0].typeInfo).is_null;

                    type_info.tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = type_info.tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }

                    scopeStack.top().changeEntry(
                         SYMBOL_TABLE_ENTRY(lexeme,
                           type_info));
                  }
                  else
                  {
                        if((yyvsp[-3].typeInfo).val_int<1 || (yyvsp[-3].typeInfo).val_int>exprTypeInfo.tlist->length)
                        {
                            yyerror("Subscript out of bounds");
                        }

                    //printValue(exprTypeInfo);

                    TYPE_INFO type_info;
                    type_info.type = exprTypeInfo.type;
                    type_info.numParams = exprTypeInfo.numParams;
                    type_info.returnType = exprTypeInfo.returnType;
                    type_info.is_param = exprTypeInfo.is_param;
                    type_info.val_bool = exprTypeInfo.val_bool;
                    type_info.val_int = exprTypeInfo.val_int;
                    type_info.val_float = exprTypeInfo.val_float;
                    strcpy(type_info.val_string, exprTypeInfo.val_string);
                    type_info.is_null= exprTypeInfo.is_null;

                    type_info.tlist = new Trial;
                    Trial *temp = exprTypeInfo.tlist;
                    Trial *newT = type_info.tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }

                    int count = (yyvsp[-3].typeInfo).val_int;
                    Trial* node = type_info.tlist;
                    while(count > 1)
                    {
                        node = node->tlist;
                        count -= 1;
                    }
                    node->type = (yyvsp[0].typeInfo).type;
                    node->val_bool = (yyvsp[0].typeInfo).val_bool;
                    node->val_int = (yyvsp[0].typeInfo).val_int;
                    node->val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy(node->val_string, (yyvsp[0].typeInfo).val_string);
                    scopeStack.top().changeEntry(
                         SYMBOL_TABLE_ENTRY(lexeme,
                           type_info));
                    exprTypeInfo =
                        scopeStack.top().findEntry(lexeme);

                  }


                }
                else
                {

                        TYPE_INFO type_info;
                        type_info.type = (yyvsp[0].typeInfo).type;
                        type_info.numParams = (yyvsp[0].typeInfo).numParams;
                        type_info.returnType = (yyvsp[0].typeInfo).returnType;
                        type_info.is_param = (yyvsp[0].typeInfo).is_param;
                        type_info.val_bool = (yyvsp[0].typeInfo).val_bool;
                        type_info.val_int = (yyvsp[0].typeInfo).val_int;
                        type_info.val_float = (yyvsp[0].typeInfo).val_float;
                        strcpy(type_info.val_string, (yyvsp[0].typeInfo).val_string);
                        type_info.is_null= (yyvsp[0].typeInfo).is_null;

                        type_info.tlist = new Trial;
                        Trial *temp = (yyvsp[0].typeInfo).tlist;
                        Trial *newT = type_info.tlist;
                        while(temp!=NULL)
                        {
                            newT->type = temp->type;
                            newT->val_bool = temp->val_bool;
                            newT->val_int = temp->val_int;
                            newT->val_float = temp->val_float;
                            strcpy(newT->val_string, temp->val_string);
                            newT->length = temp->length;
                            temp = temp->tlist;
                            if(temp!=NULL)
                                newT->tlist = new Trial;
                            else
                                newT->tlist = NULL;
                            newT = newT->tlist;
                        }

                      scopeStack.top().changeEntry(
                            SYMBOL_TABLE_ENTRY(lexeme,
                            type_info));
                    }
			    if (((yyvsp[-3].typeInfo).is_index) &&
			        ((yyvsp[0].typeInfo).type == LIST))
				semanticError(1, ERR_CANNOT_BE_LIST);
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
                }
#line 2419 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1005 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("INDEX", " [[ EXPR ]]");
                    (yyval.typeInfo).is_index = true;
                    (yyval.typeInfo).type = INT;
                    (yyval.typeInfo).val_int = (yyvsp[-2].typeInfo).val_int;

			}
#line 2431 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1013 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("INDEX", " epsilon");
			    (yyval.typeInfo).is_index = false;
                }
#line 2440 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1020 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("QUIT_EXPR", "QUIT()");
                    (yyval.typeInfo).type = NULL_TYPE;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).is_null = true;
                }
#line 2453 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1031 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("OUTPUT_EXPR",
                              "PRINT ( EXPR )");
                    if(((yyvsp[-1].typeInfo).type == FUNCTION) ||
                      ((yyvsp[-1].typeInfo).type == NULL_TYPE))
				semanticError(1,
				 ERR_CANNOT_BE_FUNCT_OR_NULL);


                 printValue((yyvsp[-1].typeInfo));
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }



                }
#line 2505 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1079 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("OUTPUT_EXPR",
                              "CAT ( EXPR )");
                    if(((yyvsp[-1].typeInfo).type == FUNCTION) ||
                       ((yyvsp[-1].typeInfo).type == NULL_TYPE))
				semanticError(1,
				 ERR_CANNOT_BE_FUNCT_OR_NULL);
                    printValue((yyvsp[-1].typeInfo));
                    (yyval.typeInfo).type = NULL_TYPE;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                    (yyval.typeInfo).is_null=true;
                }
#line 2524 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1096 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("INPUT_EXPR", "READ ( )");
                    string buffer;
                    getline(std::cin, buffer);
                    if(buffer[0]=='+' || buffer[0]=='-' || isdigit(buffer[0]))
                    {
                        (yyval.typeInfo).type = INT;
                        (yyval.typeInfo).val_int = stoi(buffer);
                        for(int i=1;i<buffer.length();i++)
                        {
                            if(buffer[i] == '.')
                            {
                                (yyval.typeInfo).type = FLOAT;
                                (yyval.typeInfo).val_float = stof(buffer);
                                break;
                            }
                        }


                    }
					else
					{
                        (yyval.typeInfo).type = STR;
                        strcpy((yyval.typeInfo).val_string, buffer.c_str());
                    }
                    //printf("%d %f %s", $$.val_int, $$.val_float, $$.val_string);
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;

                    }
#line 2560 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1130 "spiveyt.y" /* yacc.c:1646  */
    {
			    printRule("FUNCTION_DEF",
                              "FUNCTION ( PARAM_LIST )"
                              " COMPOUND_EXPR");
                	    beginScope();
                }
#line 2571 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1137 "spiveyt.y" /* yacc.c:1646  */
    {
			    (yyval.num) = scopeStack.top().getNumEntries();
   		     }
#line 2579 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1141 "spiveyt.y" /* yacc.c:1646  */
    {
                    endScope();
                    if((yyvsp[0].typeInfo).type == FUNCTION)
				semanticError(2, ERR_CANNOT_BE_FUNCT);
                    (yyval.typeInfo).type = FUNCTION;
                    (yyval.typeInfo).numParams = (yyvsp[-2].num);
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).is_param = false;
                }
#line 2593 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1153 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAM_LIST", "PARAMS");
                }
#line 2601 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1157 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAM_LIST", "NO PARAMS");
                }
#line 2609 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1163 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("NO_PARAMS", "epsilon");
                }
#line 2617 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1169 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAMS", "IDENT");
                    string lexeme = string((yyvsp[0].text));
                    if(!suppressTokenOutput)
                      printf("___Adding %s to symbol table\n",
                             (yyvsp[0].text));
                    // assuming params are ints
                    TYPE_INFO exprTypeInfo =
                     {INT, NOT_APPLICABLE, NOT_APPLICABLE,
                      true};
                    bool success =
                     scopeStack.top().
                      addEntry(SYMBOL_TABLE_ENTRY
                        (lexeme, exprTypeInfo));
                    if(!success)
				semanticError(0,
				 ERR_MULTIPLY_DEFINED_IDENT);
                }
#line 2640 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1188 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("PARAMS", "IDENT, PARAMS");
                    string lexeme = string((yyvsp[-2].text));
                    if(!suppressTokenOutput)
                     printf("___Adding %s to symbol table\n",
                           (yyvsp[-2].text));
                    // assuming params are ints
                    TYPE_INFO exprTypeInfo =
                     {INT, NOT_APPLICABLE, NOT_APPLICABLE,
				true};
                    bool success =
                     scopeStack.top().addEntry(
                      SYMBOL_TABLE_ENTRY(lexeme, exprTypeInfo));
                    if(!success)
				semanticError(0,
				 ERR_MULTIPLY_DEFINED_IDENT);
                }
#line 2662 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1208 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FUNCTION_CALL", "IDENT"
                              " ( ARG_LIST )");
                    TYPE_INFO exprTypeInfo =
                     findEntryInAnyScope(string((yyvsp[-3].text)));
                    if (exprTypeInfo.type == UNDEFINED)
                      semanticError(0, ERR_UNDEFINED_IDENT);
                    if(exprTypeInfo.type != FUNCTION)
				semanticError(1, ERR_MUST_BE_FUNCT);
                    if((yyvsp[-1].num) > exprTypeInfo.numParams)
				semanticError(0, ERR_TOO_MANY_PARAMS);
                    if((yyvsp[-1].num) < exprTypeInfo.numParams)
				semanticError(0, ERR_TOO_FEW_PARAMS);
                    (yyval.typeInfo).type = exprTypeInfo.returnType;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                }
#line 2685 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1229 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARG_LIST", "ARGS");
                    (yyval.num) = (yyvsp[0].num);
                    numExprs = 0;
                }
#line 2695 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1235 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARG_LIST", "NO_ARGS");
                    numExprs = 0;
                    (yyval.num) = numExprs;
                }
#line 2705 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1243 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("NO_ARGS", "epsilon");
                }
#line 2713 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1249 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARGS", "EXPR");
                    numExprs++;
                    if(!isIntCompatible((yyvsp[0].typeInfo).type))
				semanticError(0,
				              ERR_NON_INT_FUNCT_PARAM);
			    (yyval.num) = numExprs;
                }
#line 2726 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1258 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARGS", "EXPR, ARGS");
                    numExprs++;
                    if(!isIntCompatible((yyvsp[0].typeInfo).type))
				semanticError(0,
				              ERR_NON_INT_FUNCT_PARAM);
                }
#line 2738 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1266 "spiveyt.y" /* yacc.c:1646  */
    {
			    (yyval.num) = numExprs;
			}
#line 2746 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1272 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ARITHLOGIC_EXPR",
                              "SIMPLE_ARITHLOGIC");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;

                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;



                }
#line 2768 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1291 "spiveyt.y" /* yacc.c:1646  */
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

                    //printf("in expression %f and %f\n", $1.val_float, $3.val_float);
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;

                    if((yyvsp[-2].typeInfo).type == BOOL && (yyvsp[-2].typeInfo).val_bool)
					{
                        (yyvsp[-2].typeInfo).val_float = 1;
                    }
					else if((yyvsp[-2].typeInfo).type == BOOL && !((yyvsp[-2].typeInfo).val_bool))
					{
                        (yyvsp[-2].typeInfo).val_float = 0;
                    }
                    if((yyvsp[0].typeInfo).type == BOOL && (yyvsp[0].typeInfo).val_bool)
					{
                        (yyvsp[0].typeInfo).val_float = 1;
                    }else if((yyvsp[0].typeInfo).type == BOOL && !((yyvsp[0].typeInfo).val_bool))
					{
                        (yyvsp[0].typeInfo).val_float = 0;
                    }
                    if((yyvsp[-2].typeInfo).type == INT)
					{
                        (yyvsp[-2].typeInfo).val_float = (yyvsp[-2].typeInfo).val_int;
                    }
                    if((yyvsp[0].typeInfo).type == INT)
					{
                        (yyvsp[0].typeInfo).val_float = (yyvsp[0].typeInfo).val_int;
                    }
                    if((yyvsp[-1].num) == EQL)
					{
                        (yyval.typeInfo).val_bool = ((yyvsp[-2].typeInfo).val_float == (yyvsp[0].typeInfo).val_float);
                    }
					else if((yyvsp[-1].num) == NEQ){

                        (yyval.typeInfo).val_bool = ((yyvsp[-2].typeInfo).val_float != (yyvsp[0].typeInfo).val_float);
                    }
					else if((yyvsp[-1].num) == GEQ)
					{
                        (yyval.typeInfo).val_bool = ((yyvsp[-2].typeInfo).val_float >= (yyvsp[0].typeInfo).val_float);
                    }
					else if((yyvsp[-1].num) == LEQ)
					{
                        (yyval.typeInfo).val_bool = ((yyvsp[-2].typeInfo).val_float <= (yyvsp[0].typeInfo).val_float);
                    }
					else if((yyvsp[-1].num) == LESS)
					{
                        (yyval.typeInfo).val_bool = ((yyvsp[-2].typeInfo).val_float < (yyvsp[0].typeInfo).val_float);
                    }
					else if((yyvsp[-1].num) == GREATER)
					{
                        (yyval.typeInfo).val_bool = ((yyvsp[-2].typeInfo).val_float > (yyvsp[0].typeInfo).val_float);
                    }



                    (yyval.typeInfo).val_int = (yyvsp[-2].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-2].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-2].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-2].typeInfo).is_null;
                }
#line 2845 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1366 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("SIMPLE_ARITHLOGIC",
                              "TERM ADD_OP_LIST");
			    if ((yyvsp[0].typeInfo).type != NOT_APPLICABLE)
			    {
                    //printf("it 1 is optype logical %d", $2.opType);
                      if(isInvalidOperandType((yyvsp[-1].typeInfo).type))
                        semanticError(1,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                      if(isInvalidOperandType((yyvsp[0].typeInfo).type))
                        semanticError(2,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                                     if((yyvsp[0].typeInfo).type==BOOL)
									 {
                                        if((yyvsp[0].typeInfo).val_bool)
										{
                                            (yyvsp[0].typeInfo).val_int = 1;
                                            (yyvsp[0].typeInfo).val_float = 1;
                                        }
										else
										{
                                            (yyvsp[0].typeInfo).val_int = 0;
                                            (yyvsp[0].typeInfo).val_float = 0;
                                        }
                                    }
                                    if((yyvsp[-1].typeInfo).type==BOOL)
									{
                                        if((yyvsp[-1].typeInfo).val_bool)
										{
                                            (yyvsp[-1].typeInfo).val_int = 1;
                                            (yyvsp[-1].typeInfo).val_float = 1;
                                        }
										else
										{

                                            (yyvsp[-1].typeInfo).val_int = 0;
                                            (yyvsp[-1].typeInfo).val_float = 0;
                                        }
                                    }
                if(isLog((yyvsp[0].typeInfo).opType)){
                    //printf("it 2 is optype logical %d", $2.opType);
                    (yyval.typeInfo).type = BOOL;
                    if(((yyvsp[-1].typeInfo).type == FLOAT and (yyvsp[-1].typeInfo).val_float == 0)
                        || ((yyvsp[-1].typeInfo).type == INT and (yyvsp[-1].typeInfo).val_int == 0))
						{
                            (yyvsp[-1].typeInfo).val_bool = false;
                        }
						else
						{
                            (yyvsp[-1].typeInfo).val_bool = true;
                        }
                    if(((yyvsp[0].typeInfo).type == FLOAT and (yyvsp[0].typeInfo).val_float == 0)
                        || ((yyvsp[0].typeInfo).type == INT and (yyvsp[0].typeInfo).val_int == 0))
						{
                            (yyvsp[0].typeInfo).val_bool = false;
                        }
						else
						{
                            (yyvsp[0].typeInfo).val_bool = true;
                        }
                    if((yyvsp[0].typeInfo).opType == AND)
					{
                        (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool && (yyvsp[0].typeInfo).val_bool;
                      }
					  else if((yyvsp[0].typeInfo).opType == OR)
					  {
                        (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool || (yyvsp[0].typeInfo).val_bool;
                     }
                 }
				else if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
				         isIntCompatible((yyvsp[0].typeInfo).type))
                            {



                                    (yyval.typeInfo).type = INT;
                                    if((yyvsp[0].typeInfo).opType == ADD)
									{
                                        (yyval.typeInfo).val_int=(yyvsp[-1].typeInfo).val_int+(yyvsp[0].typeInfo).val_int;
                                    }
									else if((yyvsp[0].typeInfo).opType == SUB){

                                        (yyval.typeInfo).val_int=(yyvsp[-1].typeInfo).val_int-(yyvsp[0].typeInfo).val_int;
                                    }
                            }
				else{
                        (yyval.typeInfo).type = FLOAT;
                        if((yyvsp[-1].typeInfo).type == INT)
						{
                            (yyvsp[-1].typeInfo).val_float = (float)(yyvsp[-1].typeInfo).val_int;
                        }
                        if((yyvsp[0].typeInfo).type == INT)
						{
                            (yyvsp[0].typeInfo).val_float = (float)(yyvsp[0].typeInfo).val_int;
                        }
                        if((yyvsp[0].typeInfo).opType == ADD)
						{
                            (yyval.typeInfo).val_float=(yyvsp[-1].typeInfo).val_float+(yyvsp[0].typeInfo).val_float;
                        }else if((yyvsp[0].typeInfo).opType == SUB)
						{
                            (yyval.typeInfo).val_float=(yyvsp[-1].typeInfo).val_float-(yyvsp[0].typeInfo).val_float;
                        }
                }

				(yyval.typeInfo).numParams = NOT_APPLICABLE;
				(yyval.typeInfo).returnType = NOT_APPLICABLE;
                     	(yyval.typeInfo).is_param = false;
			    }
                    else
			    {
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;

                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
			    }
                (yyval.typeInfo).opType = (yyvsp[0].typeInfo).opType;
                }
#line 2993 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1512 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP_LIST",
                              "ADD_OP TERM ADD_OP_LIST");
			    int argWithErr =
				((yyvsp[0].typeInfo).type == NOT_APPLICABLE)? 2: 1;
                    if(isInvalidOperandType((yyvsp[-1].typeInfo).type))                                          				semanticError(argWithErr,
				    ERR_MUST_BE_INT_FLOAT_OR_BOOL);
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                (yyval.typeInfo).opType = (yyvsp[-2].num);

			    if (isLog((yyvsp[0].typeInfo).opType))
                {

                    (yyval.typeInfo).type = BOOL;
                    if(((yyvsp[0].typeInfo).type == FLOAT and (yyvsp[0].typeInfo).val_float == 0)
                        || ((yyvsp[0].typeInfo).type == INT and (yyvsp[0].typeInfo).val_int == 0))
						{
                            (yyvsp[0].typeInfo).val_bool = false;
                        }
						else
						{
                            (yyvsp[0].typeInfo).val_bool = true;
                        }
                    if(((yyvsp[-1].typeInfo).type == FLOAT and (yyvsp[-1].typeInfo).val_float == 0)
                        || ((yyvsp[-1].typeInfo).type == INT and (yyvsp[-1].typeInfo).val_int == 0))
						{
                            (yyvsp[-1].typeInfo).val_bool = false;
                        }
						else
						{
                            (yyvsp[-1].typeInfo).val_bool = true;
                        }
                    if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
                    {
                        (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    }
					else
					{

                        if((yyvsp[0].typeInfo).opType == AND)
						{
                            (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool && (yyvsp[-1].typeInfo).val_bool;
                          }
						  else if((yyvsp[0].typeInfo).opType == OR)
						  {
                            (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool || (yyvsp[-1].typeInfo).val_bool;
                         }
                    }
                }
                else
			    {

				if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
                {
                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                    (yyval.typeInfo).opType = (yyvsp[-2].num);
                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
				}
                else
				{

                                     if((yyvsp[-1].typeInfo).type==BOOL)
									 {
                                        if((yyvsp[-1].typeInfo).val_bool)
										{
                                            (yyvsp[-1].typeInfo).val_int = 1;
                                            (yyvsp[-1].typeInfo).val_float = 1;
                                        }
										else
										{
                                            (yyvsp[-1].typeInfo).val_int = 0;
                                            (yyvsp[-1].typeInfo).val_float = 0;
                                        }
                                    }
                                    if((yyvsp[0].typeInfo).type==BOOL)
									{
                                        if((yyvsp[0].typeInfo).val_bool)
										{
                                            (yyvsp[0].typeInfo).val_int = 1;
                                            (yyvsp[0].typeInfo).val_float = 1;
                                        }
										else
										{
                                            (yyvsp[0].typeInfo).val_int = 0;
                                            (yyvsp[0].typeInfo).val_float = 0;
                                        }
                                    }
                    if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
                             isIntCompatible((yyvsp[0].typeInfo).type))
                                {

                                    (yyval.typeInfo).type = INT;
                                    if((yyvsp[0].typeInfo).opType == ADD)
									{
                                        (yyval.typeInfo).val_int=(yyvsp[-1].typeInfo).val_int+(yyvsp[0].typeInfo).val_int;
                                    }
									else if((yyvsp[0].typeInfo).opType == SUB)
									{
                                        (yyval.typeInfo).val_int=(yyvsp[-1].typeInfo).val_int-(yyvsp[0].typeInfo).val_int;
                                    }
                                }
                    else
					{
                        (yyval.typeInfo).type = FLOAT;
                        if((yyvsp[-1].typeInfo).type == INT)
						{
                            (yyvsp[-1].typeInfo).val_float = (float)(yyvsp[-1].typeInfo).val_int;
                        }
                        if((yyvsp[0].typeInfo).type == INT)
						{
                            (yyvsp[0].typeInfo).val_float = (float)(yyvsp[0].typeInfo).val_int;
                        }
                        if((yyvsp[0].typeInfo).opType == ADD)
						{
                            (yyval.typeInfo).val_float=(yyvsp[-1].typeInfo).val_float+(yyvsp[0].typeInfo).val_float;
                        }
						else if((yyvsp[0].typeInfo).opType == SUB)
						{
                            (yyval.typeInfo).val_float=(yyvsp[-1].typeInfo).val_float-(yyvsp[0].typeInfo).val_float;
                        }
                    }
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                    (yyval.typeInfo).opType = (yyvsp[-2].num);

				}
                    }
                }
#line 3156 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1671 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP_LIST", "epsilon");
			    (yyval.typeInfo).type = NOT_APPLICABLE;
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
			    (yyval.typeInfo).is_param = false;

                }
#line 3169 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1682 "spiveyt.y" /* yacc.c:1646  */
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
                    	(yyval.typeInfo).is_param = false;
				if (isLog((yyvsp[0].typeInfo).opType))
				{
                  (yyval.typeInfo).type = BOOL;

                        if(((yyvsp[-1].typeInfo).type == FLOAT and (yyvsp[-1].typeInfo).val_float == 0)
                        || ((yyvsp[-1].typeInfo).type == INT and (yyvsp[-1].typeInfo).val_int == 0))
						{
                            (yyvsp[-1].typeInfo).val_bool = false;
                        }
						else if(((yyvsp[-1].typeInfo).type == FLOAT and (yyvsp[-1].typeInfo).val_float != 0)
                        || ((yyvsp[-1].typeInfo).type == INT and (yyvsp[-1].typeInfo).val_int != 0))
						{
                            (yyvsp[-1].typeInfo).val_bool = true;
                        }
                    if(((yyvsp[0].typeInfo).type == FLOAT and (yyvsp[0].typeInfo).val_float == 0)
                        || ((yyvsp[0].typeInfo).type == INT and (yyvsp[0].typeInfo).val_int == 0))
						{
                            (yyvsp[0].typeInfo).val_bool = false;
                        }
						else if(((yyvsp[0].typeInfo).type == FLOAT and (yyvsp[0].typeInfo).val_float != 0)
                        || ((yyvsp[0].typeInfo).type == INT and (yyvsp[0].typeInfo).val_int != 0))
						{
                            (yyvsp[0].typeInfo).val_bool = true;
                        }

                  if((yyvsp[0].typeInfo).opType == AND)
				  {
                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool && (yyvsp[0].typeInfo).val_bool;
                  }else if((yyvsp[0].typeInfo).opType == OR)
				  {
                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool || (yyvsp[0].typeInfo).val_bool;
                  }
                }
				else
				{

                                     if((yyvsp[0].typeInfo).type==BOOL)
									 {
                                        if((yyvsp[0].typeInfo).val_bool)
										{
                                            (yyvsp[0].typeInfo).val_int = 1;
                                            (yyvsp[0].typeInfo).val_float = 1;
                                        }
										else
										{
                                            (yyvsp[0].typeInfo).val_int = 0;
                                            (yyvsp[0].typeInfo).val_float = 0;
                                        }
                                    }
                                    if((yyvsp[-1].typeInfo).type==BOOL)
									{
                                        if((yyvsp[-1].typeInfo).val_bool)
										{
                                            (yyvsp[-1].typeInfo).val_int = 1;
                                            (yyvsp[-1].typeInfo).val_float = 1;
                                        }
										else
										{
                                            (yyvsp[-1].typeInfo).val_int = 0;
                                            (yyvsp[-1].typeInfo).val_float = 0;
                                        }
                                    }
				  if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
				      isIntCompatible((yyvsp[0].typeInfo).type))
                      {

				    (yyval.typeInfo).type = INT;
                    if((yyvsp[0].typeInfo).opType == MUL)
					{
                        (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int * (yyvsp[0].typeInfo).val_int;
                    }
					else if((yyvsp[0].typeInfo).opType == DIV)
					{

                        if((yyvsp[0].typeInfo).val_int == 0)
						{
                            yyerror("Attempted division by zero");
                        }
						else
						{
                            (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int / (yyvsp[0].typeInfo).val_int;
                        }
                    }else if((yyvsp[0].typeInfo).opType == MOD)
					{
                        (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int % (yyvsp[0].typeInfo).val_int;
                    }
					else if((yyvsp[0].typeInfo).opType == POW)
					{

                        (yyval.typeInfo).val_int = pow((yyvsp[-1].typeInfo).val_int,(yyvsp[0].typeInfo).val_int);
                    }
                       }
                       else
					   {
                    (yyval.typeInfo).type = FLOAT;
                    if((yyvsp[-1].typeInfo).type == INT)
					{
                        (yyvsp[-1].typeInfo).val_float = (float)(yyvsp[-1].typeInfo).val_int;
                    }
                    if((yyvsp[0].typeInfo).type == INT)
					{
                        (yyvsp[0].typeInfo).val_float = (float)(yyvsp[0].typeInfo).val_int;
                    }
                    if((yyvsp[0].typeInfo).opType == MUL)
					{
                        (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float * (yyvsp[0].typeInfo).val_float;
                    }
					else if((yyvsp[0].typeInfo).opType == DIV)
					{
                        if((yyvsp[0].typeInfo).val_float == 0)
						{
                            yyerror("Attempted division by zero");
                        }
						else
						{
                            (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float / (yyvsp[0].typeInfo).val_float;
                        }
                    }else if((yyvsp[0].typeInfo).opType == MOD)
					{
                        (yyval.typeInfo).val_float = fmod((yyvsp[-1].typeInfo).val_float, (yyvsp[0].typeInfo).val_float);
                    }
					else if((yyvsp[0].typeInfo).opType == POW)
					{
                        (yyval.typeInfo).val_float = pow((yyvsp[-1].typeInfo).val_float,(yyvsp[0].typeInfo).val_float);
                    }
				}
                }
			    }
                    else
			    {

                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;

                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;

                    if((yyval.typeInfo).type == INT)
					{
                        (yyval.typeInfo).val_float = (float)(yyval.typeInfo).val_int;
                    }

                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
			    }
                (yyval.typeInfo).opType = (yyvsp[0].typeInfo).opType;
                }
#line 3358 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1869 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP_LIST",
                              "MULT_OP FACTOR MULT_OP_LIST");
			    int argWithErr =
				((yyvsp[0].typeInfo).type == NOT_APPLICABLE)? 2: 1;
                    if(isInvalidOperandType((yyvsp[-1].typeInfo).type))                    				semanticError(argWithErr,
				  ERR_MUST_BE_INT_FLOAT_OR_BOOL);
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
			    (yyval.typeInfo).is_param = false;
                (yyval.typeInfo).opType = (yyvsp[-2].num);
			    if (isLog((yyvsp[0].typeInfo).opType))
                {
                    (yyval.typeInfo).type = BOOL;
                    if(((yyvsp[0].typeInfo).type == FLOAT and (yyvsp[0].typeInfo).val_float == 0)
                        || ((yyvsp[0].typeInfo).type == INT and (yyvsp[0].typeInfo).val_int == 0))
						{
                            (yyvsp[0].typeInfo).val_bool = false;
                        }
						else
						{
                            (yyvsp[0].typeInfo).val_bool = true;
                        }
                    if(((yyvsp[-1].typeInfo).type == FLOAT and (yyvsp[-1].typeInfo).val_float == 0)
                        || ((yyvsp[-1].typeInfo).type == INT and (yyvsp[-1].typeInfo).val_int == 0)){

                            (yyvsp[-1].typeInfo).val_bool = false;
                        }
						else
						{
                            (yyvsp[-1].typeInfo).val_bool = true;
                        }
                    if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
                    {
                        (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    }
					else
					{

                        if((yyvsp[0].typeInfo).opType == AND){

                            (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool && (yyvsp[-1].typeInfo).val_bool;
                          }
						  else if((yyvsp[0].typeInfo).opType == OR){
                            (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool || (yyvsp[-1].typeInfo).val_bool;
                         }
                    }
                }
                else
			    {
                    if ((yyvsp[0].typeInfo).type == NOT_APPLICABLE)
					{

                        (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                        (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                        (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                        (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;
                        (yyval.typeInfo).opType = (yyvsp[-2].num);
                        (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                        (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                        (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                        strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                        (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;

                        if((yyval.typeInfo).type == INT)
						{
                            (yyval.typeInfo).val_float = (float)(yyval.typeInfo).val_int;
                        }
                        (yyval.typeInfo).tlist = new Trial;
                        Trial *temp = (yyvsp[-1].typeInfo).tlist;
                        Trial *newT = (yyval.typeInfo).tlist;
                        while(temp!=NULL)
                        {
                            newT->type = temp->type;
                            newT->val_bool = temp->val_bool;
                            newT->val_int = temp->val_int;
                            newT->val_float = temp->val_float;
                            strcpy(newT->val_string, temp->val_string);
                            newT->length = temp->length;
                            temp = temp->tlist;
                            if(temp!=NULL)
                                newT->tlist = new Trial;
                            else
                                newT->tlist = NULL;
                            newT = newT->tlist;
                        }
                    }
                    else
                    {

                          if(isInvalidOperandType((yyvsp[0].typeInfo).type))                    				  semanticError(argWithErr,
                        ERR_MUST_BE_INT_FLOAT_OR_BOOL);
                      if (isLog((yyvsp[-2].num)))
                      (yyval.typeInfo).type = BOOL;
                      else
                      {
                                         if((yyvsp[-1].typeInfo).type==BOOL)
										 {
                                            if((yyvsp[-1].typeInfo).val_bool)
											{
                                                (yyvsp[-1].typeInfo).val_int = 1;
                                                (yyvsp[-1].typeInfo).val_float = 1;
                                            }
											else
											{
                                                (yyvsp[-1].typeInfo).val_int = 0;
                                                (yyvsp[-1].typeInfo).val_float = 0;
                                            }
                                        }
                                        if((yyvsp[0].typeInfo).type==BOOL)
										{
                                            if((yyvsp[0].typeInfo).val_bool)
											{
                                                (yyvsp[0].typeInfo).val_int = 1;
                                                (yyvsp[0].typeInfo).val_float = 1;
                                            }
											else
											{
                                                (yyvsp[0].typeInfo).val_int = 0;
                                                (yyvsp[0].typeInfo).val_float = 0;
                                            }
                                        }
                      if (isIntCompatible((yyvsp[-1].typeInfo).type) &&
                          isIntCompatible((yyvsp[0].typeInfo).type))
                          {

                        (yyval.typeInfo).type = INT;
                        if((yyvsp[0].typeInfo).opType == MUL)
						{
                            (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int * (yyvsp[0].typeInfo).val_int;
                        }
						else if((yyvsp[0].typeInfo).opType == DIV)
						{
                            if((yyvsp[0].typeInfo).val_int == 0)
							{
                                yyerror("Attempted division by zero");
                            }
							else
							{
                                (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int / (yyvsp[0].typeInfo).val_int;
                            }
                        }
						else if((yyvsp[0].typeInfo).opType == MOD)
						{
                            (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int % (yyvsp[0].typeInfo).val_int;
                        }
						else if((yyvsp[0].typeInfo).opType == POW)
						{
                            (yyval.typeInfo).val_int = pow((yyvsp[-1].typeInfo).val_int,(yyvsp[0].typeInfo).val_int);
                        }

                        }
                      else
					  {
                        (yyval.typeInfo).type = FLOAT;
                        if((yyvsp[-1].typeInfo).type == INT)
						{
                            (yyvsp[-1].typeInfo).val_float = (float)(yyvsp[-1].typeInfo).val_int;
                        }
                        if((yyvsp[0].typeInfo).type == INT)
						{
                            (yyvsp[0].typeInfo).val_float = (float)(yyvsp[0].typeInfo).val_int;
                        }
                        if((yyvsp[0].typeInfo).opType == MUL)
						{
                            (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float * (yyvsp[0].typeInfo).val_float;
                        }
						else if((yyvsp[0].typeInfo).opType == DIV)
						{
                            if((yyvsp[0].typeInfo).val_float == 0)
							{
                                yyerror("Attempted division by zero");
                            }
							else
							{
                                (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float / (yyvsp[0].typeInfo).val_float;
                            }
                        }
						else if((yyvsp[0].typeInfo).opType == MOD)
						{
                            (yyval.typeInfo).val_float = fmod((yyvsp[-1].typeInfo).val_float, (yyvsp[0].typeInfo).val_float);
                        }
						if((yyvsp[0].typeInfo).opType == POW)
						{
                            (yyval.typeInfo).val_float = pow((yyvsp[-1].typeInfo).val_float,(yyvsp[0].typeInfo).val_float);
                        }
                        }
                      }
                      (yyval.typeInfo).opType = (yyvsp[-2].num);
                        }
                    }

                }
#line 3556 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2063 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP_LIST", "epsilon");
			    (yyval.typeInfo).type = NOT_APPLICABLE;
			    (yyval.typeInfo).numParams = NOT_APPLICABLE;
			    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;


                }
#line 3570 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 2075 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "VAR");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;

                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;

                    if((yyvsp[0].typeInfo).type == INT)
					{
                        (yyval.typeInfo).val_float = (float)(yyvsp[0].typeInfo).val_int;
                    }

                    if((yyvsp[0].typeInfo).type==BOOL)
					{
                        if((yyvsp[0].typeInfo).val_bool)
						{
                            (yyvsp[0].typeInfo).val_int = 1;
                            (yyvsp[0].typeInfo).val_float = 1;
                        }
						else
						{
                            (yyvsp[0].typeInfo).val_int = 0;
                            (yyvsp[0].typeInfo).val_float = 0;
                        }
                    }

                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[0].typeInfo).is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[0].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
                }
#line 3628 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2129 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "CONST");
                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                }
#line 3640 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2137 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "( EXPR )");

                    (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[-1].typeInfo).is_param;

                    (yyval.typeInfo).val_bool = (yyvsp[-1].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[-1].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[-1].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[-1].typeInfo).val_string);
                    (yyval.typeInfo).is_null= (yyvsp[-1].typeInfo).is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = (yyvsp[-1].typeInfo).tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }
                }
#line 3679 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 2172 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("FACTOR", "! FACTOR");
                    (yyval.typeInfo).type = BOOL;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    if((yyvsp[0].typeInfo).type == BOOL)
					{
                        (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool?false:true;
                    }
					else if((yyvsp[0].typeInfo).type == INT)
					{
                        (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_int!=0?false:true;
                    }
					else if((yyvsp[0].typeInfo).type == FLOAT)
					{
                        (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_float==0?true:false;
                    }

                }
#line 3704 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2195 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP", "+");
                    (yyval.num) = ADD;
                }
#line 3713 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 2200 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP", "-");
                    (yyval.num) = SUB;
                }
#line 3722 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 2205 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ADD_OP", "|");
                    (yyval.num) = OR;
                }
#line 3731 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 2212 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "*");
                    (yyval.num) = MUL;

                }
#line 3741 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 2218 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "/");
                    (yyval.num) = DIV;
                }
#line 3750 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 2223 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "&");
                    (yyval.num) = AND;
                }
#line 3759 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 2228 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "\%\%");
                    (yyval.num) = MOD;
                }
#line 3768 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 2233 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("MULT_OP", "^");
                    (yyval.num) = POW;
                }
#line 3777 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 2240 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "<");
                    (yyval.num) = LESS;
                }
#line 3786 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 2245 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", ">");
                    (yyval.num) = GREATER;
                }
#line 3795 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 2250 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "<=");
                    (yyval.num) = LEQ;
                }
#line 3804 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 2255 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", ">=");
                    (yyval.num) = GEQ;
                }
#line 3813 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 2260 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "==");
                    (yyval.num) = EQL;
                }
#line 3822 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 2265 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("REL_OP", "!=");
                    (yyval.num) = NEQ;
                }
#line 3831 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 2272 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("VAR", "ENTIRE_VAR");
                    (yyval.typeInfo).type == (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                }
#line 3847 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2284 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("VAR", "SINGLE_ELEMENT");
                    (yyval.typeInfo).type == (yyvsp[0].typeInfo).type;
                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                    (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                    (yyval.typeInfo).is_param = (yyvsp[0].typeInfo).is_param;
                    (yyval.typeInfo).val_bool = (yyvsp[0].typeInfo).val_bool;
                    (yyval.typeInfo).val_int = (yyvsp[0].typeInfo).val_int;
                    (yyval.typeInfo).val_float = (yyvsp[0].typeInfo).val_float;
                    strcpy((yyval.typeInfo).val_string, (yyvsp[0].typeInfo).val_string);
                }
#line 3863 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2299 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("SINGLE_ELEMENT", "IDENT"
                              " [[ EXPR ]]");
                    TYPE_INFO exprTypeInfo =
                      findEntryInAnyScope((yyvsp[-5].text));
                    if(exprTypeInfo.type == UNDEFINED)
				semanticError(0, ERR_UNDEFINED_IDENT);
                    if(!isListCompatible(exprTypeInfo.type))
				semanticError(1, ERR_MUST_BE_LIST);

                    if((yyvsp[-2].typeInfo).val_int<1 || (yyvsp[-2].typeInfo).val_int>exprTypeInfo.tlist->length)
                        {
                            yyerror("Subscript out of bounds");
                        }

                    int count = (yyvsp[-2].typeInfo).val_int;
                    Trial* node = exprTypeInfo.tlist;
                    while(count > 1)
                    {
                        node = node->tlist;
                        count -= 1;
                    }
                    (yyval.typeInfo).type = node->type;
                    (yyval.typeInfo).val_bool = node->val_bool;
                    (yyval.typeInfo).val_int = node->val_int;
                    (yyval.typeInfo).val_float = node->val_float;
                    strcpy((yyval.typeInfo).val_string, node->val_string);


                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                    (yyval.typeInfo).is_param = false;
                }
#line 3901 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2335 "spiveyt.y" /* yacc.c:1646  */
    {
                    printRule("ENTIRE_VAR", "IDENT");
                    TYPE_INFO exprTypeInfo =
                      findEntryInAnyScope(string((yyvsp[0].text)));
                    if(exprTypeInfo.type == UNDEFINED)
                      semanticError(0, ERR_UNDEFINED_IDENT);
                    (yyval.typeInfo).type = exprTypeInfo.type;
                    (yyval.typeInfo).numParams = exprTypeInfo.numParams;
                    (yyval.typeInfo).returnType = exprTypeInfo.returnType;
                    (yyval.typeInfo).is_param = exprTypeInfo.is_param;

                    (yyval.typeInfo).val_bool = exprTypeInfo.val_bool;
                    (yyval.typeInfo).val_int = exprTypeInfo.val_int;
                    (yyval.typeInfo).val_float = exprTypeInfo.val_float;
                    strcpy((yyval.typeInfo).val_string, exprTypeInfo.val_string);
                    (yyval.typeInfo).is_null= exprTypeInfo.is_null;


                    (yyval.typeInfo).tlist = new Trial;
                    Trial *temp = exprTypeInfo.tlist;
                    Trial *newT = (yyval.typeInfo).tlist;
                    while(temp!=NULL)
                    {
                        newT->type = temp->type;
                        newT->val_bool = temp->val_bool;
                        newT->val_int = temp->val_int;
                        newT->val_float = temp->val_float;
                        strcpy(newT->val_string, temp->val_string);
                        newT->length = temp->length;
                        temp = temp->tlist;
                        if(temp!=NULL)
                            newT->tlist = new Trial;
                        else
                            newT->tlist = NULL;
                        newT = newT->tlist;
                    }

                }
#line 3944 "spiveyt.tab.c" /* yacc.c:1646  */
    break;


#line 3948 "spiveyt.tab.c" /* yacc.c:1646  */
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
#line 2375 "spiveyt.y" /* yacc.c:1906  */


#include "lex.yy.c"
extern FILE *yyin;

//  Construct a string as an argument number (argNum, 0
//  if no argument number in message) and message (errNum is
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

// Output type and lexeme.
void printTokenInfo(const char* token_type, const char* lexeme)
{
  if(!suppressTokenOutput)
  {
    printf("TOKEN: %s \t\t LEXEME: %s\n", token_type, lexeme);
  }
}

// Output production info as nonterm on left-hand side (1st
// param) and symbols on right-hand side (2nd param).
void printRule(const char *lhs, const char *rhs)
{
  if(!suppressTokenOutput)
  {
    printf("%s -> %s\n", lhs, rhs);
  }
  return;
}

// Determine whether given type is compatible with INT, FLOAT,
// or BOOL.
bool isIntOrFloatOrBoolCompatible(const int theType)
{
    return(isIntCompatible(theType) ||
           isFloatCompatible(theType) ||
		isBoolCompatible(theType));
}

bool isArith(const int theType)
{
    return theType == ADD ||
        theType == SUB ||
        theType == MUL ||
        theType == DIV ||
        theType == POW ||
        theType == MOD;
}

bool isRel(const int theType)
{
    return theType == EQL ||
        NEQ ||
        LESS ||
        GREATER ||
        LEQ ||
        GEQ;
}

bool isLog(const int theType)
{
    return theType == AND ||
        theType == OR;
}

// Determine whether given type is compatible with INT.
bool isIntCompatible(const int theType)
{
    return(isBoolCompatible(theType) ||
           ((theType & INT) == INT));
}

// Determine whether given type is compatible with BOOL.
bool isBoolCompatible(const int theType)
{
    return((theType & BOOL) == BOOL);
}

// Determine whether given type is compatible with FLOAT.
bool isFloatCompatible(const int theType)
{
    return((theType & FLOAT) == FLOAT);
}

// Determine whether given type is compatible with LIST.
bool isListCompatible(const int theType)
{
    return((theType & LIST) == LIST);
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

void printValue(TYPE_INFO type_info)
{
        if(type_info.type == INT)
        {
            printf("%d\n", type_info.val_int);
        }
		else if(type_info.type == STR)
        {
            printf("%s\n", type_info.val_string);
        }
		else if(type_info.type == FLOAT)
        {
            printf("%6.2f\n", type_info.val_float);
        }
		else if(type_info.type == BOOL)
        {
            printf("%s\n",type_info.val_bool?"TRUE":"FALSE");
        }
		else if(type_info.type == NULL_TYPE)
        {
            printf("%s\n", "NULL");
        }
		else if(type_info.type == LIST){
            printf("%s","(");
            Trial *temp = type_info.tlist;
            while(temp != NULL)
            {
                    if(temp->type == INT)
                    {
                        printf(" %d", temp->val_int);
                    }
					else if(temp->type == STR)
                    {
                        printf(" %s", temp->val_string);
                    }
					else if(temp->type == FLOAT)
                    {
                        printf(" %.2f", temp->val_float);
                    }
					else if(temp->type == BOOL)
                    {
                        printf(" %s",temp->val_bool?"TRUE":"FALSE");
                    }
					else if(temp->type == NULL_TYPE)
                    {
                        printf(" %s", "NULL");
                    }
                    temp = temp->tlist;
            };
            printf("%s\n"," )");
        }
}

// If the_name exists in any SYMBOL_TABLE in scopeStack, return
// its TYPE_INFO; otherwise, return a TYPE_INFO that contains
// type UNDEFINED.
TYPE_INFO findEntryInAnyScope(const string the_name)
{
    TYPE_INFO info = {UNDEFINED, NOT_APPLICABLE, NOT_APPLICABLE};
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

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("You must specify a file in the command line!\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");
    beginScope();
    do
    {
        yyparse();
    } while(!feof(yyin));
    endScope();
    return 0;
}
