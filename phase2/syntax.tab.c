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
#line 1 "syntax.y" /* yacc.c:339  */

    #include "lex.yy.c"
    #include "node.h"
    #include <stdarg.h>
    #include <stdio.h>
    #include <string.h>
    #include"symtab.c"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    int flag = 0;
    symtab* root;
    node* insert(char* parent,int count,...);
    void yyerror(const char*);
    node* alloNodeI(int a,char * Name);
    node* alloNodeF(float a,char * Name);
    node* alloNodeC(char* a,char * Name);
    void printTree(node* root,int blank);
    int compareType(Type* type1, Type* type2);
    int confirmReturnType(node* root,char * returnType);
    int confirmArgsType(node* root,ParaList* parameters);

#line 88 "syntax.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    ID = 261,
    TYPE = 262,
    INCLUSION = 263,
    DEFINE = 264,
    STRUCT = 265,
    IF = 266,
    WHILE = 267,
    RETURN = 268,
    SEMI = 269,
    COMMA = 270,
    FOR = 271,
    LOWER_ELSE = 272,
    ELSE = 273,
    ASSIGN = 274,
    OR = 275,
    AND = 276,
    NE = 277,
    EQ = 278,
    LT = 279,
    LE = 280,
    GT = 281,
    GE = 282,
    PLUS = 283,
    MINUS = 284,
    MUL = 285,
    DIV = 286,
    NOT = 287,
    LP = 288,
    RP = 289,
    LB = 290,
    RB = 291,
    LC = 292,
    RC = 293,
    DOT = 294,
    FAULT = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "syntax.y" /* yacc.c:355  */

    node* treeNode;
    int int_value;
    float float_value;
    char* string_value;

#line 176 "syntax.tab.c" /* yacc.c:355  */
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


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 207 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   475

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    55,    56,    58,    59,    62,    63,    66,
      67,    68,   117,   118,   122,   123,   126,   135,   139,   140,
     141,   142,   145,   146,   147,   150,   151,   154,   176,   177,
     180,   181,   184,   185,   186,   189,   190,   191,   192,   193,
     194,   198,   199,   202,   232,   235,   236,   239,   240,   244,
     252,   259,   266,   273,   280,   287,   294,   301,   308,   315,
     322,   329,   336,   340,   344,   348,   358,   366,   374,   377,
     383,   388,   393,   398,   399,   400,   402,   403
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "INCLUSION", "DEFINE", "STRUCT", "IF", "WHILE", "RETURN", "SEMI",
  "COMMA", "FOR", "LOWER_ELSE", "ELSE", "ASSIGN", "OR", "AND", "NE", "EQ",
  "LT", "LE", "GT", "GE", "PLUS", "MINUS", "MUL", "DIV", "NOT", "LP", "RP",
  "LB", "RB", "LC", "RC", "DOT", "FAULT", "$accept", "Program", "Headers",
  "Header", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -76,    11,   132,   -76,   -76,   -76,   -76,     8,   -76,   -76,
      66,    60,   -76,    15,   -76,    12,   -76,    62,    64,    -7,
      43,    66,    50,   -76,   -76,     7,    19,    66,   -76,     7,
      26,    66,   -76,   -76,     7,    49,    86,   -76,   -76,    46,
      72,   167,    27,     4,    88,   -76,   -76,    75,   -76,    66,
     -76,   -76,   -76,   -76,   -76,    78,    82,    83,   181,    99,
     181,   181,   181,   130,   -76,     5,   167,    67,   181,   -76,
     -76,     7,   -76,    21,   181,   181,    98,   181,    74,    30,
     269,   -76,   -76,   -76,   -76,   -76,   -76,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   128,   181,   379,   -76,   -76,   247,    22,   291,   313,
     -76,   -76,   203,   -76,   379,   399,   418,   435,   435,   162,
     162,   162,   162,    74,    74,    30,    30,   335,   -76,   129,
     181,   -76,   -76,   167,   167,   181,   -76,   -76,   -76,   117,
     -76,   225,   167,   181,   -76,   357,   167,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     8,     1,    14,     5,     6,     0,     3,     2,
       8,     0,    15,    17,     7,    18,    10,     0,     0,    12,
       0,    42,     0,    20,     9,     0,     0,    42,    11,     0,
       0,    42,    24,    23,     0,     0,    26,    18,    13,     0,
       0,    31,    47,     0,    45,    16,    41,    27,    22,     0,
      21,    19,    70,    71,    72,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,    31,     0,     0,    44,
      43,     0,    25,     0,     0,     0,     0,     0,    63,    64,
       0,    73,    29,    28,    30,    40,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    46,    66,    77,     0,     0,     0,
      38,    34,     0,    62,    49,    51,    50,    56,    57,    52,
      53,    54,    55,    58,    59,    60,    61,     0,    68,     0,
       0,    74,    65,     0,     0,     0,    67,    75,    76,    35,
      37,     0,     0,     0,    36,     0,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   -76,   126,   -76,   118,    -1,   -76,   -22,
     -76,    95,   -76,   125,    80,   -75,    48,   -76,    76,   -76,
     -58,    31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    10,    18,    29,    12,    19,
      20,    35,    36,    64,    65,    66,    30,    31,    43,    44,
      67,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    11,    78,    79,    80,    69,    82,    42,    25,    11,
     103,     3,    47,    37,    13,   106,   108,   109,    70,   112,
      39,    34,    40,   131,    52,    53,    54,    55,    26,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    83,   129,    22,    68,    17,    34,    42,
      60,    32,    21,    61,    62,   105,   132,     4,   139,   140,
       7,    63,    26,    23,    45,   100,    15,   144,    85,   101,
     102,   147,   106,     4,    16,    41,     7,   141,    24,    46,
      27,    86,    50,    48,    33,   145,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   110,
      17,    49,   100,    71,    98,    99,   101,   102,    51,   100,
      26,    73,   111,   101,   102,    74,    75,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     137,    81,    77,   100,   128,   142,    14,   101,   102,     4,
       5,     6,     7,    38,    72,    28,    84,   104,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   138,     0,     0,   100,     0,     0,     0,   101,   102,
      52,    53,    54,    55,     0,     0,     0,     0,    56,    57,
      58,     0,     0,    59,    52,    53,    54,    55,     0,     0,
      96,    97,    98,    99,     0,     0,    60,   100,     0,    61,
      62,   101,   102,     0,    27,     0,     0,    63,     0,     0,
      60,     0,     0,    61,    62,     0,     0,   135,     0,     0,
       0,    63,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,   100,   143,
       0,     0,   101,   102,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,     0,   130,     0,   101,   102,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,   100,     0,     0,     0,   101,   102,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,   113,   100,     0,     0,     0,   101,   102,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,   133,   100,     0,     0,     0,
     101,   102,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,   134,   100,     0,
       0,     0,   101,   102,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,   136,     0,     0,   101,   102,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   146,   100,     0,     0,     0,   101,   102,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,   100,     0,     0,     0,   101,   102,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,   100,     0,     0,     0,   101,   102,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,   100,     0,     0,     0,   101,   102,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     100,     0,     0,     0,   101,   102
};

static const yytype_int16 yycheck[] =
{
      58,     2,    60,    61,    62,     1,     1,    29,    15,    10,
      68,     0,    34,     6,     6,    73,    74,    75,    14,    77,
       1,    22,     3,     1,     3,     4,     5,     6,    35,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    38,   102,    33,    19,    40,    49,    71,
      29,     1,    37,    32,    33,    34,    34,     7,   133,   134,
      10,    40,    35,     1,    38,    35,     6,   142,     1,    39,
      40,   146,   130,     7,    14,    27,    10,   135,    14,    31,
      37,    14,    36,    34,    34,   143,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     1,
      40,    15,    35,    15,    30,    31,    39,    40,    36,    35,
      35,    33,    14,    39,    40,    33,    33,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       1,     1,    33,    35,     6,    18,    10,    39,    40,     7,
       8,     9,    10,    25,    49,    20,    66,    71,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   130,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    11,    12,
      13,    -1,    -1,    16,     3,     4,     5,     6,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    29,    35,    -1,    32,
      33,    39,    40,    -1,    37,    -1,    -1,    40,    -1,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,    14,    -1,    -1,
      -1,    40,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,    14,
      -1,    -1,    39,    40,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    -1,    15,    -1,    39,    40,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    39,    40,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    39,    40,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      39,    40,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    39,    40,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    -1,    -1,    39,    40,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    39,    40,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     7,     8,     9,    10,    44,    45,
      46,    48,    49,     6,    45,     6,    14,    40,    47,    50,
      51,    37,    33,     1,    14,    15,    35,    37,    54,    48,
      57,    58,     1,    34,    48,    52,    53,     6,    47,     1,
       3,    57,    50,    59,    60,    38,    57,    50,    34,    15,
      36,    36,     3,     4,     5,     6,    11,    12,    13,    16,
      29,    32,    33,    40,    54,    55,    56,    61,    19,     1,
      14,    15,    52,    33,    33,    33,    61,    33,    61,    61,
      61,     1,     1,    38,    55,     1,    14,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      35,    39,    40,    61,    59,    34,    61,    62,    61,    61,
       1,    14,    61,    34,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,     6,    61,
      15,     1,    34,    34,    34,    14,    36,     1,    62,    56,
      56,    61,    18,    14,    56,    61,    34,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     2,     0,     3,
       2,     3,     1,     3,     1,     1,     5,     2,     1,     4,
       2,     4,     4,     3,     3,     3,     1,     2,     4,     4,
       2,     0,     2,     1,     3,     5,     7,     5,     3,     9,
       2,     2,     0,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     1,     2,     4,     4,     3,     1
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
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 49 "syntax.y" /* yacc.c:1646  */
    {
    (yyval.treeNode) = insert("Program",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));
    (yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
    // if(flag ==0){printTree($$,0);}
    }
#line 1546 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Headers",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1552 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Headers",0);}
#line 1558 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Header",1,alloNodeC((yyvsp[0].string_value),"INCLUSION"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1564 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Header",1,alloNodeC((yyvsp[0].string_value),"DEFINE"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1570 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 62 "syntax.y" /* yacc.c:1646  */
    { (yyval.treeNode) = insert("ExtDefList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1576 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDefList",0);}
#line 1582 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDef",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1588 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDef",2,(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1594 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDef",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
            if(symtab_lookup(root, (yyvsp[-1].treeNode)->child->attribute).a != -1){printf("Error type 4 at Line %d: redefine function: %s\n",((yylsp[-2])).first_line,(yyvsp[-1].treeNode)->child->attribute);}
            else{
              struct Info *val = malloc(sizeof(Info));
              struct Type *returnType = malloc(sizeof(Type));
              returnType->name= (yyvsp[-2].treeNode)->child->attribute;
              returnType->category = PRIMITIVE;//todo
              struct ParaList *paralist;
              val->type = NULL;
              if((yyvsp[-1].treeNode)->child->next->next->next != NULL){
                    node* cur = (yyvsp[-1].treeNode)->child->next->next->child;
                    struct Type *para = malloc(sizeof(Type));
                    para->name = cur->child->child->attribute;
                    para->category = PRIMITIVE;//todo
                    paralist = malloc(sizeof(ParaList));
                    paralist->type = para;
                    paralist->next = NULL;
                    struct ParaList *curpara = paralist;
                    while(cur->next != NULL){
                        cur = cur->next->next->child;
                        struct Type* paraType = malloc(sizeof(Type));
                        paraType->name = cur->child->child->attribute;
                        paraType->category = PRIMITIVE;
                        struct ParaList *nextPara = malloc(sizeof(ParaList));
                        nextPara->type = paraType;
                        nextPara->next = NULL;
                        curpara->next = nextPara;
                        curpara = curpara->next;
                    }
                }
                else{
                    paralist = NULL;
                }
                val->a = 2;
                val->return_type = returnType;
                val->paraList = paralist;
                symtab_insert(root, (yyvsp[-1].treeNode)->child->attribute, *val); 
            }  
    //    /******/
       char * returnType;
       if(strcasecmp((yyval.treeNode)->child->child->name,"TYPE")==0){
        returnType = (yyval.treeNode)->child->child->attribute;
       } else returnType = (yyval.treeNode)->child->child->child->next->attribute;
        if(confirmReturnType((yyvsp[0].treeNode),returnType)==0){
            printf("Error Type 8 at Line %d: a function's return value type mismatches the declared type\n",((yylsp[-2])).first_line);
        }
      }
#line 1646 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDecList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1652 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDecList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1658 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Specifier",1,alloNodeC((yyvsp[0].string_value),"TYPE"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1664 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Specifier",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1670 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "syntax.y" /* yacc.c:1646  */
    {
                (yyval.treeNode) = insert("StructSpecifier",5,
                alloNodeC("struct","STRUCT"),
                alloNodeC((yyvsp[-3].string_value),"ID"),
                alloNodeC("{","LC"),
                (yyvsp[-1].treeNode),
                alloNodeC("}","RC")
                );
                (yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1684 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 135 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("StructSpecifier",2,alloNodeC("struct","STRUCT"),alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1690 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarDec",1,alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1696 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarDec",4,(yyvsp[-3].treeNode),alloNodeC("[","LB"),alloNodeI((yyvsp[-1].int_value),"INT"),alloNodeC("]","RB"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 1702 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 141 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-1])).first_line,(yyvsp[-1].string_value));}
#line 1708 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Wrong type of index\n",((yylsp[-3])).first_line);}
#line 1714 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("FunDec",4,alloNodeC((yyvsp[-3].string_value),"ID"),alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 1720 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("FunDec",3,alloNodeC((yyvsp[-2].string_value),"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1726 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",((yylsp[-1])).first_line);}
#line 1732 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1738 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1744 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ParamDec",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
                if(strcmp((yyvsp[0].treeNode)->child->name, "ID") == 0){
                    if(symtab_lookup(root, (yyvsp[0].treeNode)->child->attribute).a != -1){
                    printf("Error Type 3 at Line %d: redefine variable: %s\n", ((yylsp[-1])).first_line,(yyvsp[0].treeNode)->child->attribute);
                    }
                    else{
                            if(strcmp((yyvsp[-1].treeNode)->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-1].treeNode)->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->a = 0;
                                symtab_insert(root, (yyvsp[0].treeNode)->child->attribute, *val);
                            }
                            // hello 结构体插在这里哦！
                    }
                }
 }
#line 1768 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 176 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("CompSt",4,alloNodeC("{","LC"),(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC("}","RC"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1774 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing specifier\n",((yylsp[-1])).first_line);}
#line 1780 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("StmtList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1786 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 181 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("StmtList",0);}
#line 1792 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",2,(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1798 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1804 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 186 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",3,alloNodeC("return","RETURN"),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        //$$->type = $2->type;
    }
#line 1812 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 189 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",5,alloNodeC("if","IF"),alloNodeC("(","LP"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1818 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 190 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",7,alloNodeC("if","IF"),alloNodeC("(","LP"),(yyvsp[-4].treeNode),alloNodeC(")","RP"),(yyvsp[-2].treeNode),alloNodeC("else","ELSE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-6]);(yyval.treeNode)->lineNo=((yylsp[-6])).first_line;}
#line 1824 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 191 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",5,alloNodeC("while","WHILE"),alloNodeC("(","LP"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1830 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 192 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line); }
#line 1836 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 193 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",9,alloNodeC("for","FOR"),alloNodeC("(","LP"),(yyvsp[-6].treeNode),alloNodeC(";","SEMI"),(yyvsp[-4].treeNode),alloNodeC(";","SEMI"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-8]);(yyval.treeNode)->lineNo=((yylsp[-8])).first_line;}
#line 1842 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 194 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line); }
#line 1848 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DefList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1854 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DefList",0);}
#line 1860 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Def",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
                if(strcmp((yyvsp[-1].treeNode)->child->child->child->name, "ID") == 0){
                        if(symtab_lookup(root, (yyvsp[-1].treeNode)->child->child->child->attribute).a != -1){
                        printf("Error Type 3 at Line %d: redefine variable: %s\n", ((yylsp[-2])).first_line,(yyvsp[-1].treeNode)->child->child->child->attribute);
                        }
                        else{
                            //todo
                            if(strcasecmp((yyvsp[-2].treeNode)->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-2].treeNode)->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->a = 0;
                                symtab_insert(root, (yyvsp[-1].treeNode)->child->child->child->attribute, *val);
                                Type *baseval = type;
                                Type *cmpVal;
                                if((yyvsp[-1].treeNode)->child->child->next != NULL){
                                    cmpVal = (yyvsp[-1].treeNode)->child->child->next->next->type;
                                    if(compareType(baseval, cmpVal) == 0){
                                        printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
                                    }
                     }
                }
        }
        }



}
#line 1895 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 232 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line);}
#line 1901 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 235 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DecList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1907 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 236 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DecList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1913 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 239 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Dec",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1919 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 240 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Dec",3,(yyvsp[-2].treeNode),alloNodeC("=","ASSIGN"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1925 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 244 "syntax.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode) = alloNodeC("=","ASSIGN");(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type, (yyvsp[0].treeNode)->type) == 0){
                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
        }
        if((yyvsp[-2].treeNode)->lvalue==0){
            printf("Error type 6 at Line %d: rvalue appears on the left-hand side of the assignment operator \n",((yylsp[-2])).first_line);
        }
}
#line 1938 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 252 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("&&","AND"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 1950 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 259 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("||","OR"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 1962 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 266 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("<","LT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 1974 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 273 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("<=","LE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 1986 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 280 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(">","GT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 1998 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 287 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(">=","GE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2010 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 294 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("!=","NE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2022 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 301 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("==","EQ"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2034 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 308 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("+","PLUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2046 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 315 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("-","MINUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2058 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 322 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("*","MUL"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2070 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 329 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("/","DIV"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
   if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error Type 7 at Line %d: unmatching operands\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2082 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 336 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-1].treeNode)->type; 
   }
#line 2091 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 340 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",2,alloNodeC("-","MINUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[0].treeNode)->type; //todo
   }
#line 2100 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 344 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",2,alloNodeC("!","NOT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[0].treeNode)->type;
   }
#line 2109 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 348 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",4,alloNodeC((yyvsp[-3].string_value),"ID"),alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;
        Info val =symtab_lookup(root,(yyval.treeNode)->child->attribute);
        if(val.a!=-1){
            if(confirmArgsType((yyvsp[-1].treeNode),val.paraList)==0){
                printf("Error Type 9 at Line %d: a function's arguments mismatch the declared parameters",((yylsp[-3])).first_line);
            }
            (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->attribute).return_type;
        }else printf("Error Type 2 at Line %d: undefined function: %s\n", ((yylsp[-3])).first_line,(yyvsp[-3].string_value));
        
   }
#line 2124 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 358 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,alloNodeC((yyvsp[-2].string_value),"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        
        if(symtab_lookup(root,(yyval.treeNode)->child->attribute).paraList!=NULL){
            printf("Error Type 9 at Line %d: a function's arguments mismatch the declared parameters",((yylsp[-2])).first_line);
        };
        (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->attribute).type;
        if(symtab_lookup(root, (yyvsp[-2].string_value)).a == -1){printf("Error Type 2 at Line %d : function %s is used without definition\n", ((yylsp[-2])).first_line,(yyvsp[-2].string_value));}
   }
#line 2137 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 366 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",4,(yyvsp[-3].treeNode),alloNodeC("[","LB"),(yyvsp[-1].treeNode),alloNodeC("]","RB"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line; (yyval.treeNode)->lvalue=1;
        // Info val = symtab_lookup(root,$1->child->attribute);
        // if(val.type->category != ARRAY)
        // {
        //     printf("Error Type 10 at Line %d: applying indexing operator ([...]) on non-array type variables", (@1).first_line);
        // }
        // $$->type = $1->type->array->base; //跟数组有关
   }
#line 2150 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 374 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(".","DOT"),alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;(yyval.treeNode)->lvalue=1;
        // $$->type = symtab_lookup(root,$$->child->next->next->attribute).type; //跟structure
   }
#line 2158 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 377 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line; (yyval.treeNode)->lvalue=1;
        (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->attribute).type;
        if(symtab_lookup(root, (yyval.treeNode)->child->attribute).a == -1){
            printf("Error Type 1 at Line %d: undefined variable: %s\n", ((yylsp[0])).first_line,(yyvsp[0].string_value));
        }
   }
#line 2169 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 383 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeI((yyvsp[0].int_value),"INT"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "int";
        (yyval.treeNode)->type -> category = PRIMITIVE;
   }
#line 2179 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 388 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"FLOAT"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "float";
        (yyval.treeNode)->type -> category = PRIMITIVE;
   }
#line 2189 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 393 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"CHAR"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "char";
        (yyval.treeNode)->type-> category = PRIMITIVE;
   }
#line 2199 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 398 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-1])).first_line,(yyvsp[-1].string_value));}
#line 2205 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 399 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",((yylsp[-1])).first_line);}
#line 2211 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 400 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-2])).first_line,(yyvsp[-2].string_value));}
#line 2217 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 402 "syntax.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode)= alloNodeC(",","COMMA"); (yyval.treeNode) = insert("Args",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2223 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 403 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Args",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2229 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2233 "syntax.tab.c" /* yacc.c:1646  */
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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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
                  yystos[yystate], yyvsp, yylsp);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 406 "syntax.y" /* yacc.c:1906  */

void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d\n", s, yylineno);
}
int confirmReturnType(node* root,char * returnType){
    int re = 1;
    if(root->child!=NULL){
        node* p = root->child;
        while(p!=NULL){
            if(strcasecmp(p->name,"return")==0) {
                re = re & !strcasecmp(p->next->type->name,returnType);
                if(re==0){
                     return 0;
                }
            }
            re = re & confirmReturnType(p,returnType);
            if(re==0) return 0;
            p = p->next;
        }
    }
    return re;

}
int confirmArgsType(node* root,ParaList* parameters){
    ParaList * p= parameters;
    int re =1;
    if(parameters==NULL) return 0;
    while(root->child!=NULL&&p!=NULL){
        re = re & compareType(root->child->type,p->type);
        if(re==0) {
            return 0;
        }
        p = p->next;
        if(root->child->next==NULL) break;
        root = root->child->next-> next;
    }
    if(p==NULL&&root->child->next!=NULL){
        return 0;
    }
    if(root->child->next==NULL && p!=NULL) {
        return 0;
    }
    return re;
}

int compareType(Type* type1, Type* type2) {
    if(!type1||!type2){
        return 1;
    }
    if(type1->category != type2->category){
        return 0;
    }
    if(type1->category == PRIMITIVE||STRUCTURE){
        return !strcasecmp(type1->name, type2->name);
    }
    else{
        if(type1->array->size!=type2->array->size){
            return 0;
        }else return compareType(type1->array->base,type2->array->base);
    }
}

void printTree(node* root, int blank){
    if (root->child==NULL)
    {   
        if(root->attribute){
            printf("%*s%s: %s\n",blank,"",root->name,root->attribute);
        }else{
            printf("%*s%s\n",blank,"",root->name);
        }
        return;
    }else{
        printf("%*s%s (%d)\n",blank,"",root->name,root->lineNo);
        node *p= root->child;
        while(p!=NULL){
            if(!p->isEmpty){
               printTree(p,blank+2);
            }
            p=p->next;
        }
    }
}

node* alloNodeI(int a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->attribute = malloc(sizeof(char)*10);
    p->lvalue = 0;
    sprintf(p->attribute,"%d",a);
    return p;
}
node* alloNodeF(float a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->attribute = malloc(sizeof(char)*10);
    p->lvalue = 0;
    sprintf(p->attribute,"%f",a);
    return p;
}
node* alloNodeC(char* a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->lvalue = 0;
    if(Name=="INT"||Name=="FLOAT"||Name=="CHAR"||Name=="ID"||Name=="TYPE")
        p->attribute=a;
    return p;
}

node* insert(char * parent,int count, ...){
    node *p = malloc(sizeof(node));
    p->name = parent;
    if (count==0){
        p->isEmpty = 1;
        return p;
    }
    va_list args;
    va_start(args, count);

    node * start = va_arg(args,node*);
    node * prev = start;
    for(int i=0;i<count-1;i++) {
        node * n=va_arg(args, node*);
        prev->next=n;
        prev = n;
    }
    prev->next==NULL;
    p->child = start;
    va_end(args);
    return p;
}

int main(int argc, char **argv) {
    char *file_path;
    freopen("out.txt","w",stdout);
    root =  symtab_init();
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        // yydebug = 1;
        yyparse();
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
    }
}
