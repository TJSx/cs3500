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
#line 1 "spiveyt.y" /* yacc.c:339  */

/* 
Definitions of constants, variables, & function prototypes go here 
*/



#include <stdio.h>

int numLines = 0;
void printRule(const char *, const char *);
int yyerror(const char *s);
void printTokenInfo(const char* tokenType, const char* lexeme);

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}


#line 89 "spiveyt.tab.c" /* yacc.c:339  */

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
    T_UNKNOWN = 260,
    T_FLOATCONST = 261,
    T_IF = 262,
    T_WHILE = 263,
    T_FUNCTION = 264,
    T_FOR = 265,
    T_IN = 266,
    T_NEXT = 267,
    T_BREAK = 268,
    T_TRUE = 269,
    T_FALSE = 270,
    T_QUIT = 271,
    T_PRINT = 272,
    T_CAT = 273,
    T_READ = 274,
    T_LIST = 275,
    T_STRCONST = 276,
    T_ADD = 277,
    T_SUB = 278,
    T_MULT = 279,
    T_DIV = 280,
    T_MOD = 281,
    T_POW = 282,
    T_LT = 283,
    T_GT = 284,
    T_LE = 285,
    T_GE = 286,
    T_EQ = 287,
    T_NE = 288,
    T_NOT = 289,
    T_AND = 290,
    T_OR = 291,
    T_ASSIGN = 292,
    T_SEMICOLON = 293,
    T_COMMA = 294,
    T_LPAREN = 295,
    T_LBRACE = 296,
    T_RBRACE = 297,
    T_LBRACKET = 298,
    T_RBRACKET = 299,
    T_COMMENT = 300,
    T_POUND = 301,
    T_RPAREN = 302,
    T_ELSE = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 186 "spiveyt.tab.c" /* yacc.c:358  */

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
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    48,    52,    56,    61,    65,    69,    73,
      77,    81,    85,    89,    93,    98,   102,   106,   110,   114,
     119,   124,   129,   133,   138,   142,   147,   152,   156,   160,
     165,   170,   175,   180,   184,   189,   194,   200,   205,   210,
     214,   219,   224,   229,   233,   239,   243,   247,   252,   257,
     261,   267,   271,   275,   280,   284,   289,   294,   299,   303,
     308,   313,   317,   321,   325,   329,   334,   338,   342,   347,
     351,   355,   359,   363,   368,   372,   376,   380,   384,   388,
     393,   397,   402,   407
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENT", "T_INTCONST", "T_UNKNOWN",
  "T_FLOATCONST", "T_IF", "T_WHILE", "T_FUNCTION", "T_FOR", "T_IN",
  "T_NEXT", "T_BREAK", "T_TRUE", "T_FALSE", "T_QUIT", "T_PRINT", "T_CAT",
  "T_READ", "T_LIST", "T_STRCONST", "T_ADD", "T_SUB", "T_MULT", "T_DIV",
  "T_MOD", "T_POW", "T_LT", "T_GT", "T_LE", "T_GE", "T_EQ", "T_NE",
  "T_NOT", "T_AND", "T_OR", "T_ASSIGN", "T_SEMICOLON", "T_COMMA",
  "T_LPAREN", "T_LBRACE", "T_RBRACE", "T_LBRACKET", "T_RBRACKET",
  "T_COMMENT", "T_POUND", "T_RPAREN", "T_ELSE", "$accept", "N_START",
  "N_EXPR", "N_CONST", "N_COMPOUND_EXPR", "N_EXPR_LIST", "N_IF_EXPR",
  "N_WHILE_EXPR", "N_FOR_EXPR", "N_LOOP_EXPR", "N_BREAK_EXPR",
  "N_NEXT_EXPR", "N_LIST_EXPR", "N_CONST_LIST", "N_ASSIGNMENT_EXPR",
  "N_INDEX", "N_QUIT_EXPR", "N_OUTPUT_EXPR", "N_INPUT_EXPR",
  "N_FUNCTION_DEF", "N_PARAM_LIST", "N_NO_PARAMS", "N_PARAMS",
  "N_FUNCTION_CALL", "N_ARG_LIST", "N_NO_ARGS", "N_ARGS",
  "N_ARITHLOGIC_EXPR", "N_SIMPLE_ARITHLOGIC", "N_ADD_OP_LIST", "N_TERM",
  "N_MULT_OP_LIST", "N_FACTOR", "N_ADD_OP", "N_MULT_OP", "N_REL_OP",
  "N_VAR", "N_SINGLE_ELEMENT", "N_ENTIRE_VAR", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      68,   -28,   -51,   -51,   -30,   -29,   -27,   -24,   -51,   -51,
     -13,    -2,    -1,     1,     2,   -51,   109,    68,    68,    40,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,    62,   -15,   -21,   -51,   -51,   -51,
      68,     3,     8,    68,    68,    44,    50,     4,    68,    68,
      54,    48,    15,   -51,    13,    68,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   109,   -51,   -51,   -51,   -51,   109,   -51,
     -51,   -51,   -51,   -51,   -51,   109,    26,    19,   -51,   -51,
      68,    68,    20,    21,    31,    32,   -51,   -51,    85,   -51,
      51,    52,    53,    34,    56,    58,   -51,    68,    60,   -51,
     -15,   -21,    68,   -51,    61,   -51,    68,    16,    44,    66,
      68,   -51,   -51,   -51,    48,   -51,    68,   -51,   -51,   -51,
     -51,   -51,    70,    69,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,    71,   -51,    75,    83,    68,    16,    77,   -51,
     -51,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    15,    17,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       2,    63,     6,     3,     4,     5,    11,     8,    14,     9,
      10,    12,    13,     7,    54,    58,    61,    62,    81,    80,
      51,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,    83,    65,     0,    22,     1,    74,    75,    76,
      77,    78,    79,     0,    66,    67,    68,    56,     0,    69,
      70,    72,    73,    71,    59,     0,    52,     0,    50,    49,
       0,     0,     0,     0,    46,     0,    44,    43,     0,    38,
       0,     0,     0,    34,     0,     0,    64,    22,     0,    55,
      58,    61,     0,    48,     0,    35,     0,     0,     0,     0,
       0,    39,    40,    41,     0,    32,     0,    21,    20,    57,
      60,    53,     0,    23,    31,    30,    27,    25,    28,    29,
      47,    42,     0,    33,     0,    82,     0,     0,     0,    24,
      26,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,     0,   -50,    17,    25,   -51,   -51,   -51,   -12,
     -51,   -51,   -51,    14,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,    23,   -51,   -51,   -51,    27,   -51,    64,    33,
      67,    37,   -14,   -51,   -51,   -51,    82,   -51,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    76,    21,    22,    98,    23,    24,    25,   127,
     128,   129,    26,    94,    27,    42,    28,    29,    30,    31,
      85,    86,    87,    32,    77,    78,    79,    33,    34,    67,
      35,    74,    36,    68,    75,    63,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    93,    53,    69,    70,    71,    72,    64,    65,   -37,
      43,    44,    40,    45,    73,    41,    46,    54,    55,     1,
       2,    66,     3,     4,     5,     6,     7,    47,   124,   125,
       8,     9,    10,    11,    12,    13,    14,    15,    48,    49,
      56,    50,    51,    82,    83,    81,    80,    84,    90,    91,
      16,    89,     2,    88,     3,    97,    17,    52,    95,    18,
      96,   101,     8,     9,    93,   102,   103,   106,   107,    15,
     108,     1,     2,   114,     3,     4,     5,     6,     7,   109,
     104,   105,     8,     9,    10,    11,    12,    13,    14,    15,
      57,    58,    59,    60,    61,    62,   110,    97,   111,   112,
     113,   116,    16,   115,   118,   122,   123,   126,    17,    18,
     132,    18,    52,     2,   135,     3,   134,   136,   137,   138,
     -36,   141,   117,     8,     9,   140,   131,    99,   133,   121,
      15,   130,    92,   119,     0,   100,   139,   126,   120,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,    17
};

static const yytype_int16 yycheck[] =
{
       0,    51,    16,    24,    25,    26,    27,    22,    23,    37,
      40,    40,    40,    40,    35,    43,    40,    17,    18,     3,
       4,    36,     6,     7,     8,     9,    10,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    40,    40,
       0,    40,    40,    43,    44,    37,    43,     3,    48,    49,
      34,    47,     4,     3,     6,    55,    40,     3,    43,    43,
      47,    75,    14,    15,   114,    39,    47,    47,    47,    21,
      39,     3,     4,    39,     6,     7,     8,     9,    10,    47,
      80,    81,    14,    15,    16,    17,    18,    19,    20,    21,
      28,    29,    30,    31,    32,    33,    11,    97,    47,    47,
      47,    43,    34,    47,    44,    44,   106,   107,    40,    43,
     110,    43,     3,     4,    44,     6,   116,    48,    47,    44,
      37,    44,    97,    14,    15,   137,   109,    63,   114,   102,
      21,   108,    50,   100,    -1,    68,   136,   137,   101,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    14,    15,
      16,    17,    18,    19,    20,    21,    34,    40,    43,    50,
      51,    52,    53,    55,    56,    57,    61,    63,    65,    66,
      67,    68,    72,    76,    77,    79,    81,    85,    86,    87,
      40,    43,    64,    40,    40,    40,    40,    40,    40,    40,
      40,    40,     3,    81,    51,    51,     0,    28,    29,    30,
      31,    32,    33,    84,    22,    23,    36,    78,    82,    24,
      25,    26,    27,    35,    80,    83,    51,    73,    74,    75,
      43,    37,    51,    51,     3,    69,    70,    71,     3,    47,
      51,    51,    85,    52,    62,    43,    47,    51,    54,    77,
      79,    81,    39,    47,    51,    51,    47,    47,    39,    47,
      11,    47,    47,    47,    39,    47,    43,    54,    44,    78,
      80,    75,    44,    51,    12,    13,    51,    58,    59,    60,
      71,    53,    51,    62,    51,    44,    48,    47,    44,    51,
      58,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      53,    54,    54,    55,    55,    56,    57,    58,    58,    58,
      59,    60,    61,    62,    62,    63,    64,    64,    65,    66,
      66,    67,    68,    69,    69,    70,    71,    71,    72,    73,
      73,    74,    75,    75,    76,    76,    77,    78,    78,    79,
      80,    80,    81,    81,    81,    81,    82,    82,    82,    83,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     0,     5,     7,     5,     7,     1,     1,     1,
       1,     1,     4,     3,     1,     4,     5,     0,     3,     4,
       4,     4,     5,     1,     1,     0,     1,     3,     4,     1,
       1,     0,     1,     3,     1,     3,     2,     3,     0,     2,
       3,     0,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     6,     1
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
#line 41 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("START", "EXPR");
			printf("\n---- Completed parsing ----\n\n");
			return 0;
			}
#line 1379 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 49 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("IF_EXPR", "IF_EXPR IF");
			}
#line 1387 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("N_WHILE_EXPR", "WHILE_EXPR WHILE");
			}
#line 1395 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("EXPR", 
				    "foo IDENT_LIST INTCONST_LIST");
			}
#line 1404 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1412 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1420 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 70 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1428 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1436 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1444 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1452 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 86 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1460 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1468 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1476 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1484 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 103 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1492 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1500 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1508 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1516 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 120 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1524 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 125 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1532 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1540 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 134 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1548 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1556 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 143 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1564 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1572 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1580 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1588 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 161 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1596 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 166 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1604 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 171 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
#line 1612 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("IDENT_LIST", "epsilon");
			}
#line 1620 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 181 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("IDENT_LIST", "IDENT_LIST IDENT");
			}
#line 1628 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 185 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("IDENT_LIST", "IDENT_LIST IDENT");
			}
#line 1636 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 190 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1644 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 195 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST",
                          "INTCONST_LIST INTCONST");
			}
#line 1653 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 200 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST",
                          "INTCONST_LIST INTCONST");
			}
#line 1662 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1670 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 211 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1678 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 215 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1686 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 220 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1694 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 225 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1702 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 230 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1710 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 234 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1718 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 239 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1726 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 244 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1734 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 248 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1742 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 253 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1750 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 258 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1758 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 262 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1766 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 267 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1774 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 272 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1782 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 276 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1790 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 281 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1798 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1806 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1814 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 295 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1822 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 299 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1830 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 304 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1838 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 309 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1846 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 313 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1854 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 318 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1862 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 322 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1870 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 326 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1878 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 330 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1886 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 335 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1894 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 339 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1902 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 343 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1910 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 348 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1918 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 352 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1926 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 356 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1934 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 360 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1942 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 364 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1950 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 369 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1958 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 373 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1966 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 377 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1974 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 381 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1982 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 385 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1990 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 389 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 1998 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 394 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 2006 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 398 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 2014 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 403 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 2022 "spiveyt.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 408 "spiveyt.y" /* yacc.c:1646  */
    {
			printRule("INTCONST_LIST", "INTCONST");
			}
#line 2030 "spiveyt.tab.c" /* yacc.c:1646  */
    break;


#line 2034 "spiveyt.tab.c" /* yacc.c:1646  */
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
#line 412 "spiveyt.y" /* yacc.c:1906  */


#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs) 
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s) 
{
  printf("%s\n", s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme) 
{
  printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

int main() 
{
  do 
  {
	yyparse();
  } while (!feof(yyin));

  printf("%d lines processed\n", numLines);
  return(0);
}
