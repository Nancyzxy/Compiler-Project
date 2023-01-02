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
    #include <stdlib.h>
    #include <string.h>
    #include"symtab.c"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    int flag = 0;
    int cnt1=0;
    int cnt2=0;
    int line = 0;
    int count1 = 1;
    int count2 = 1;
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
    char* new_place();
    char* new_label();
    char* translate_stmt(node* stmtList);
    char* translate_Exp(node* Exp, char* place);
    char* translate_Args(node* Args, int* arglist);

#line 99 "syntax.tab.c" /* yacc.c:339  */

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
    READ = 272,
    WRITE = 273,
    LOWER_ELSE = 274,
    ELSE = 275,
    ASSIGN = 276,
    OR = 277,
    AND = 278,
    NE = 279,
    EQ = 280,
    LT = 281,
    LE = 282,
    GT = 283,
    GE = 284,
    PLUS = 285,
    MINUS = 286,
    MUL = 287,
    DIV = 288,
    NOT = 289,
    LP = 290,
    RP = 291,
    LB = 292,
    RB = 293,
    LC = 294,
    RC = 295,
    DOT = 296,
    FAULT = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "syntax.y" /* yacc.c:355  */

    node* treeNode;
    int int_value;
    float float_value;
    char* string_value;

#line 189 "syntax.tab.c" /* yacc.c:355  */
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

#line 220 "syntax.tab.c" /* yacc.c:358  */

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
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    66,    67,    69,    70,    73,    74,    77,
     175,   260,   326,   327,   331,   332,   335,   344,   348,   349,
     350,   351,   354,   355,   356,   359,   360,   363,   384,   385,
     388,   389,   392,   394,   395,   397,   398,   399,   400,   401,
     402,   406,   407,   410,   537,   540,   541,   544,   545,   549,
     557,   564,   571,   578,   585,   592,   599,   606,   613,   620,
     627,   634,   641,   645,   649,   653,   670,   684,   713,   736,
     742,   747,   752,   757,   758,   759,   760,   761,   763,   764
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "INCLUSION", "DEFINE", "STRUCT", "IF", "WHILE", "RETURN", "SEMI",
  "COMMA", "FOR", "READ", "WRITE", "LOWER_ELSE", "ELSE", "ASSIGN", "OR",
  "AND", "NE", "EQ", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "MUL", "DIV",
  "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "DOT", "FAULT", "$accept",
  "Program", "Headers", "Header", "ExtDefList", "ExtDef", "ExtDecList",
  "Specifier", "StructSpecifier", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -59,     1,   108,   -59,   -59,   -59,   -59,    14,   -59,   -59,
      58,    66,   -59,    30,   -59,    -4,   -59,    26,    60,    -8,
      37,    58,    74,   -59,   -59,    22,    13,    58,   -59,    22,
      39,    58,   -59,   -59,    22,    41,    67,   -59,   -59,    49,
      50,   145,   -12,    12,    76,   -59,   -59,    70,   -59,    58,
     -59,   -59,   -59,   -59,   -59,    85,    87,    88,   185,    89,
     104,   106,   185,   185,   185,   139,   -59,    23,   145,    72,
     185,   -59,   -59,    22,   -59,   164,   185,   185,   105,   185,
     107,   185,   460,    48,   274,   -59,   -59,   -59,   -59,   -59,
     -59,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   138,   185,   406,   -59,   -59,
     252,    31,   296,   318,   -59,   -59,   207,   -59,   340,   -59,
     406,   426,   445,   181,   181,   458,   458,   458,   458,   460,
     460,    48,    48,   362,   -59,    29,   185,   -59,   -59,   145,
     145,   185,   -59,   -59,   -59,   -59,   125,   -59,   229,   145,
     185,   -59,   384,   145,   -59
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
       0,     0,     0,     0,     0,     0,    33,     0,    31,     0,
       0,    44,    43,     0,    25,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,    75,    29,    28,    30,    40,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    46,    66,
      79,     0,     0,     0,    38,    34,     0,    73,     0,    62,
      49,    51,    50,    56,    57,    52,    53,    54,    55,    58,
      59,    60,    61,     0,    68,     0,     0,    76,    65,     0,
       0,     0,    74,    67,    77,    78,    35,    37,     0,     0,
       0,    36,     0,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,   -59,   142,   -59,   128,     0,   -59,   -26,
     -59,   110,   -59,   134,    92,   -28,   -16,   -59,    82,   -59,
     -58,    28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    10,    18,    29,    12,    19,
      20,    35,    36,    66,    67,    68,    30,    31,    43,    44,
      69,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,     3,    11,    42,    82,    83,    84,    25,    47,    70,
      11,    41,   107,    71,    39,    46,    40,   110,   112,   113,
      13,   116,    34,   118,    86,    26,    72,    23,    37,    26,
     144,    22,   137,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    42,   135,    34,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    87,    17,     4,   104,   138,     7,    21,
     105,   106,    15,    89,    24,    32,    27,    48,   110,    45,
      16,     4,    49,   148,     7,   104,    90,    50,    51,   105,
     106,    73,   152,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   114,    26,    17,   104,
      33,   146,   147,   105,   106,     4,     5,     6,     7,   115,
      75,   151,    76,    77,    79,   154,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    80,
      85,    81,   104,   117,   134,   149,   105,   106,    52,    53,
      54,    55,    14,    38,    28,   108,    56,    57,    58,    74,
      88,    59,    60,    61,   145,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,     0,    62,     0,     0,    63,
      64,    60,    61,     0,    27,     0,     0,    65,    52,    53,
      54,    55,     0,     0,     0,    62,     0,     0,    63,    64,
     109,     0,    60,    61,     0,     0,    65,    96,    97,    98,
      99,   100,   101,   102,   103,     0,    62,     0,   104,    63,
      64,   141,   105,   106,     0,     0,     0,    65,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,   150,   104,     0,     0,     0,   105,   106,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   136,     0,     0,
     105,   106,     0,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
       0,     0,     0,   105,   106,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     119,   104,     0,     0,     0,   105,   106,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   139,   104,     0,     0,     0,   105,   106,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,   140,   104,     0,     0,     0,   105,
     106,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,   142,   104,     0,     0,
       0,   105,   106,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     143,     0,     0,   105,   106,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     153,   104,     0,     0,     0,   105,   106,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,     0,     0,     0,   105,   106,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,     0,     0,     0,   105,   106,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,     0,     0,     0,   105,   106,   100,   101,
     102,   103,   102,   103,     0,   104,     0,   104,     0,   105,
     106,   105,   106
};

static const yytype_int16 yycheck[] =
{
      58,     0,     2,    29,    62,    63,    64,    15,    34,    21,
      10,    27,    70,     1,     1,    31,     3,    75,    76,    77,
       6,    79,    22,    81,     1,    37,    14,     1,     6,    37,
       1,    35,     1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    73,   106,    49,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    40,    42,     7,    37,    36,    10,    39,
      41,    42,     6,     1,    14,     1,    39,    36,   136,    40,
      14,     7,    15,   141,    10,    37,    14,    38,    38,    41,
      42,    15,   150,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     1,    37,    42,    37,
      36,   139,   140,    41,    42,     7,     8,     9,    10,    14,
      35,   149,    35,    35,    35,   153,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    35,
       1,    35,    37,    36,     6,    20,    41,    42,     3,     4,
       5,     6,    10,    25,    20,    73,    11,    12,    13,    49,
      68,    16,    17,    18,   136,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    17,    18,    -1,    39,    -1,    -1,    42,     3,     4,
       5,     6,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      36,    -1,    17,    18,    -1,    -1,    42,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    31,    -1,    37,    34,
      35,    14,    41,    42,    -1,    -1,    -1,    42,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    14,    37,    -1,    -1,    -1,    41,    42,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    15,    -1,    -1,
      41,    42,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    41,    42,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    41,    42,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    41,
      42,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    41,    42,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    -1,    -1,    41,    42,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    41,    42,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    41,    42,    30,    31,
      32,    33,    32,    33,    -1,    37,    -1,    37,    -1,    41,
      42,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     7,     8,     9,    10,    46,    47,
      48,    50,    51,     6,    47,     6,    14,    42,    49,    52,
      53,    39,    35,     1,    14,    15,    37,    39,    56,    50,
      59,    60,     1,    36,    50,    54,    55,     6,    49,     1,
       3,    59,    52,    61,    62,    40,    59,    52,    36,    15,
      38,    38,     3,     4,     5,     6,    11,    12,    13,    16,
      17,    18,    31,    34,    35,    42,    56,    57,    58,    63,
      21,     1,    14,    15,    54,    35,    35,    35,    63,    35,
      35,    35,    63,    63,    63,     1,     1,    40,    57,     1,
      14,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    37,    41,    42,    63,    61,    36,
      63,    64,    63,    63,     1,    14,    63,    36,    63,    36,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,     6,    63,    15,     1,    36,    36,
      36,    14,    36,    38,     1,    64,    58,    58,    63,    20,
      14,    58,    63,    36,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64
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
       1,     1,     1,     3,     4,     2,     4,     4,     3,     1
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
#line 60 "syntax.y" /* yacc.c:1646  */
    {
    (yyval.treeNode) = insert("Program",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));
    (yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
    // if(flag ==0){printTree($$,0);}
    }
#line 1569 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Headers",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1575 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Headers",0);}
#line 1581 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Header",1,alloNodeC((yyvsp[0].string_value),"INCLUSION"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1587 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Header",1,alloNodeC((yyvsp[0].string_value),"DEFINE"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1593 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "syntax.y" /* yacc.c:1646  */
    { (yyval.treeNode) = insert("ExtDefList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1599 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDefList",0);}
#line 1605 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 77 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDef",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    node* pointer = (yyvsp[-1].treeNode)->child; // VarDec
                while(1){
                    if(strcmp(pointer->child->name, "ID") == 0){
                        if(symtab_lookup(root, pointer->child->attribute).a != -1){
                        printf("Error type 3 at Line %d: redefine variable: %s\n", ((yylsp[-2])).first_line,pointer->child->attribute);
                        }
                        else{
                            //todo
                            if(strcasecmp((yyvsp[-2].treeNode)->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-2].treeNode)->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->return_type = NULL;
                                val->paraList = NULL;
                                val->a = 0;
                                symtab_insert(root, pointer->child->attribute, *val);
                            }else{//插入结构体的声明
                                // printf("1");
                                struct Info *info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-2].treeNode)->child->child->next->attribute; //结构体名字
                                type->category = STRUCTURE;
                                info->type = type;
                                info->a = 3;
                                symtab_insert(root, pointer->child->attribute, *info);
                            }
                        }
                }else{
                        //VarDec LB INT RB
                        node *pp = pointer->child; //VarDeC或者ID
                        // printf("%s\n", pp->attribute);
                            if(strcmp(pp->child->name, "ID") == 0){//一维数组
                                if(symtab_lookup(root, pp->child->attribute).a != -1){//是否重复ID
                                    printf("Error type 3 at Line %d: redefine variable: %s 111\n", ((yylsp[-2])).first_line,pp->child->attribute);
                                }else{
                                    struct Info *val = malloc(sizeof(Info));
                                    struct Type *typehead = malloc(sizeof(Type));
                                    struct Array *arr = malloc(sizeof(Array));
                                    arr->size = atoi(pp->next->next->attribute); //int值
                                    if(strcasecmp((yyvsp[-2].treeNode)->child->name, "type") == 0){
                                        typehead->name = (yyvsp[-2].treeNode)->child->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->name = (yyvsp[-2].treeNode)->child->attribute;
                                    }
                                    else{//结构体数组
                                        typehead->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->category = STRUCTURE;
                                        arr->base->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                                    }
                                    typehead->category = ARRAY;
                                    typehead->array = arr;
                                    val->a = 1; 
                                    val->type = typehead;
                                    val->return_type = NULL;
                                    val->paraList = NULL;
                                    symtab_insert(root, pp->child->attribute, *val);
                                }    
                            }else {//二维数组
                                node *pid = pp->child; //ID
                                if(symtab_lookup(root, pid->child->attribute).a != -1){//是否重复ID
                                    printf("Error type 3 at Line %d: redefine variable: %s\n", ((yylsp[-2])).first_line,pp->child->child->attribute);
                                }else{
                                    //一维结构
                                    struct Info *val = malloc(sizeof(Info));
                                    struct Type *typehead = malloc(sizeof(Type));
                                    struct Array *arr = malloc(sizeof(Array));
                                    arr->size_col = atoi(pp->next->next->attribute); //int 列值
                                    arr->size = atoi(pp->child->next->next->attribute);//行值
                                    if(strcasecmp((yyvsp[-2].treeNode)->child->name, "type") == 0){
                                        typehead->name = (yyvsp[-2].treeNode)->child->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->name = (yyvsp[-2].treeNode)->child->attribute;
                                    }
                                    else{//结构体数组
                                        typehead->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->category = STRUCTURE;
                                        arr->base->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                                    }
                                    typehead->category = ARRAY;
                                    typehead->array = arr;
                                    val->a = 1; 
                                    val->type = typehead;
                                    val->return_type = NULL;
                                    val->paraList = NULL;
                                    symtab_insert(root, pp->child->child->attribute, *val);
                                }
                                
                            }
                }
                if(pointer->next==NULL) break;
                pointer = pointer->next->next->child; //到下一个VarDec
                }
}
#line 1708 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDef",2,(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line; 
      //specifier->structspecifier->STRUCT ID LC DefList RC
            if(symtab_lookup(root, (yyvsp[-1].treeNode)->child->child->next->attribute).a ==3){
                printf("Error type 15 at Line %d: redefine struct: %s\n",((yylsp[-1])).first_line,(yyvsp[-1].treeNode)->child->child->next->attribute);
            }
            //DefList->def->DecList->Dec->VarDec->ID | VarDec LB INT RB 
            //插入结构体
            else{
                                struct Info* info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                info->a = 3;
                                type->category = STRUCTURE;
                                type->name = (yyvsp[-1].treeNode)->child->child->next->attribute; //struct名字
                                // printf("%s\n",type->name);
                                struct FieldList *struct_element;
                                if((yyvsp[-1].treeNode)->child->child->next->next != NULL){//存在DefList
                                    node *cur = (yyvsp[-1].treeNode)->child->child->next->next->next; //DefList
                                    // printf("%s\n",cur->name);
                                    struct_element = malloc(sizeof(FieldList));
                                    struct Type *struct_type = malloc(sizeof(Type));
                                    struct_type->name = cur->child->child->child->attribute;//struct中元素的类型
                                    // printf("%s\n", cur->child->child->next->name);//DecList
                                    if(cur->child->child->next->child->child->child->next != NULL){//struct中的数组名字,假设是一维数组
                                        node *vardec = cur->child->child->next->child->child->child;
                                        if(vardec->child->next != NULL){
                                            //结构体中二维数组
                                            struct_element->name = vardec->child->child->attribute;
                                            // printf("%s\n",struct_element->name);
                                        }else{
                                            struct_element->name = vardec->child->attribute;
                                            // printf("%s\n",struct_element->name);
                                        }
                                        struct_type->category = ARRAY;
                                    }else {
                                        struct_element->name = cur->child->child->next->child->child->child->attribute;
                                        struct_type->category = PRIMITIVE;
                                    }
                                    // printf("%s\n",struct_element->name); // id名字
                                    struct_element->type = struct_type;
                                    struct Info* info0 = malloc(sizeof(Info));
                                    info->type = struct_type;
                                    symtab_insert(root,struct_element->name,*info0);
                                    struct_element->next = NULL;
                                    type->structure = struct_element;
                                    // printf("%s\n",type->structure->name);
                                    struct FieldList *curField = struct_element;
                                    while(!cur->child->next->isEmpty){
                                        cur = cur->child->next;
                                        // printf("%s\n",cur->name); // DefList
                                        // printf("%s\n",cur->child->name);
                                        struct Type *element_type = malloc(sizeof(Type));
                                        element_type->name =  cur->child->child->child->attribute;
                                        // printf("%s\n", element_type->name);
                                        struct FieldList *field = malloc(sizeof(FieldList));
                                        if(cur->child->child->next->child->child->child->next != NULL){//struct中的数组名字,假设是一维数组
                                            node *var = cur->child->child->next->child->child->child;
                                            if(var->child->next != NULL){
                                                field->name = var->child->child->attribute;
                                            }else {
                                                field->name = var->child->attribute;
                                            }
                                            element_type->category = ARRAY;
                                        }else {
                                            field->name = cur->child->child->next->child->child->child->attribute;
                                            element_type->category = PRIMITIVE;
                                        }
                                        // printf("%s\n",field->name);
                                        field->next = NULL;
                                        field->type = element_type;
                                        struct Info* info1 = malloc(sizeof(Info));
                                        info->type = element_type;
                                        symtab_insert(root,field->name,*info1);
                                        curField->next = field;
                                        // printf("1: %s\n", curField->name);
                                        curField = curField->next; 
                                        // printf("2: %s\n", curField->name);
                                    }
                                }else {
                                    struct_element = NULL;
                                }
                                info->type = type;
                                // printf("%s\n",info->type->name);
                                symtab_insert(root, (yyvsp[-1].treeNode)->child->child->next->attribute, *info);
            }  
      }
#line 1798 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 260 "syntax.y" /* yacc.c:1646  */
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
                printf("FUNCTION %s\n", (yyvsp[-1].treeNode)->child->attribute);
                if(strcasecmp((yyvsp[-1].treeNode)->child->next->next->name,"RP") != 0){
                    node* varList = (yyvsp[-1].treeNode)->child->next->next;
                    char* place = new_place();
                    printf("PARAM %s\n", place);
                    while(varList->child->next != NULL){
                        place = new_place();
                        printf("PARAM %s\n", place);
                        varList = varList->child->next->next;
                    }
                }
                node* stmtList = (yyvsp[0].treeNode)->child->next->next;
                while(stmtList->child != NULL){
                    translate_stmt(stmtList);
                    stmtList = stmtList->child->next;
                }
                
            }  
    //    /******/
       char * returnType;
       if(strcasecmp((yyval.treeNode)->child->child->name,"TYPE")==0){
        returnType = (yyval.treeNode)->child->child->attribute;
       } else returnType = (yyval.treeNode)->child->child->child->next->attribute;
        if(confirmReturnType((yyvsp[0].treeNode),returnType)==0){
            printf("Error type 8 at Line %d: incompatiable return type\n",line);
        }
      }
#line 1867 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 326 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDecList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1873 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 327 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ExtDecList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1879 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 331 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Specifier",1,alloNodeC((yyvsp[0].string_value),"TYPE"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1885 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 332 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Specifier",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1891 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 335 "syntax.y" /* yacc.c:1646  */
    {
                (yyval.treeNode) = insert("StructSpecifier",5,
                alloNodeC("struct","STRUCT"),
                alloNodeC((yyvsp[-3].string_value),"ID"),
                alloNodeC("{","LC"),
                (yyvsp[-1].treeNode),
                alloNodeC("}","RC")
                );
                (yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1905 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 344 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("StructSpecifier",2,alloNodeC("struct","STRUCT"),alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1911 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 348 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarDec",1,alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1917 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 349 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarDec",4,(yyvsp[-3].treeNode),alloNodeC("[","LB"),alloNodeI((yyvsp[-1].int_value),"INT"),alloNodeC("]","RB"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 1923 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 350 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-1])).first_line,(yyvsp[-1].string_value));}
#line 1929 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 351 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Wrong type of index\n",((yylsp[-3])).first_line);}
#line 1935 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 354 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("FunDec",4,alloNodeC((yyvsp[-3].string_value),"ID"),alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 1941 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 355 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("FunDec",3,alloNodeC((yyvsp[-2].string_value),"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1947 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 356 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",((yylsp[-1])).first_line);}
#line 1953 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 359 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1959 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 360 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("VarList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1965 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 363 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("ParamDec",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
                if(strcmp((yyvsp[0].treeNode)->child->name, "ID") == 0){
                    if(symtab_lookup(root, (yyvsp[0].treeNode)->child->attribute).a != -1){
                    printf("Error type 3 at Line %d: redefine variable: %s\n", ((yylsp[-1])).first_line,(yyvsp[0].treeNode)->child->attribute);
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
                    }
                }
 }
#line 1988 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 384 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("CompSt",4,alloNodeC("{","LC"),(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC("}","RC"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1994 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 385 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing specifier\n",((yylsp[-1])).first_line);}
#line 2000 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 388 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("StmtList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 2006 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 389 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("StmtList",0);}
#line 2012 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 392 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",2,(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
}
#line 2019 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 394 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2025 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 395 "syntax.y" /* yacc.c:1646  */
    {(yyvsp[-2].treeNode) =alloNodeC("return","RETURN"); (yyvsp[-2].treeNode)->lineNo=((yylsp[-2])).first_line; (yyval.treeNode) = insert("Stmt",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    }
#line 2032 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 397 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",5,alloNodeC("if","IF"),alloNodeC("(","LP"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 2038 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 398 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",7,alloNodeC("if","IF"),alloNodeC("(","LP"),(yyvsp[-4].treeNode),alloNodeC(")","RP"),(yyvsp[-2].treeNode),alloNodeC("else","ELSE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-6]);(yyval.treeNode)->lineNo=((yylsp[-6])).first_line;}
#line 2044 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 399 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",5,alloNodeC("while","WHILE"),alloNodeC("(","LP"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 2050 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 400 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line); }
#line 2056 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 401 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Stmt",9,alloNodeC("for","FOR"),alloNodeC("(","LP"),(yyvsp[-6].treeNode),alloNodeC(";","SEMI"),(yyvsp[-4].treeNode),alloNodeC(";","SEMI"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-8]);(yyval.treeNode)->lineNo=((yylsp[-8])).first_line;}
#line 2062 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 402 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line); }
#line 2068 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 406 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DefList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 2074 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 407 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DefList",0);}
#line 2080 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 410 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Def",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
                node* pointer = (yyvsp[-1].treeNode)->child;
                while(1){
                    if(strcmp(pointer->child->child->name, "ID") == 0){
                        if(symtab_lookup(root, pointer->child->child->attribute).a != -1){
                        printf("Error type 3 at Line %d: redefine variable: %s\n", ((yylsp[-2])).first_line,pointer->child->child->attribute);
                        }
                        else{
                            //todo
                            if(strcasecmp((yyvsp[-2].treeNode)->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-2].treeNode)->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->return_type = NULL;
                                val->paraList = NULL;
                                val->a = 0;
                                symtab_insert(root, pointer->child->child->attribute, *val);
                                Type *baseval = type;
                                Type *cmpVal;
                                if(pointer->child->next != NULL){
                                    cmpVal = pointer->child->next->next->type;
                                    if(compareType(baseval, cmpVal) == 0){
                                        printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
                                    }
                                }
                            }else{//插入结构体的声明
                            //DecList->Dec->VarDec->ID
                                // printf("1");
                                struct Info *info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-2].treeNode)->child->child->next->attribute; //结构体名字
                                type->category = STRUCTURE;
                                info->type = type;
                                info->a = 3;
                                symtab_insert(root, pointer->child->child->attribute, *info);
                            }
                        }
                }else{
                    //数组
                    
                    //首先判断是否为二维
                    if(pointer->child->child->child->next != NULL){
                        //二维
                        // printf("%s\n",pointer->child->child->child->child->attribute);
                        if(symtab_lookup(root, pointer->child->child->child->child->attribute).a != -1){//ExtDecList->VarDec->VarDec->ID
                            printf("Error type 3 at Line %d: redefine variable: %s\n", ((yylsp[-2])).first_line,pointer->child->child->child->child->attribute);
                        }else{
                            struct Info *val = malloc(sizeof(Info));
                            struct Type *typehead = malloc(sizeof(Type));
                            struct Array *arr = malloc(sizeof(Array));
                            arr->size_col =atoi(pointer->child->child->next->next->attribute); //int col size
                            arr->size = atoi(pointer->child->child->child->next->next->attribute);
                            if(strcasecmp((yyvsp[-2].treeNode)->child->name, "type") == 0){
                                typehead->name = (yyvsp[-2].treeNode)->child->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->name = (yyvsp[-2].treeNode)->child->attribute;
                            }
                            else{
                                typehead->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->category = STRUCTURE;
                                arr->base->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                            }
                        // type类型
                            typehead->category = ARRAY;
                            typehead->array = arr;
                            val->a = 1; 
                            val->type = typehead;
                            val->return_type = NULL;
                            val->paraList = NULL;
                            symtab_insert(root, pointer->child->child->child->child->attribute, *val);
                            Type *baseval = typehead;
                            Type *cmpVal;
                            if(pointer->child->next != NULL){
                                cmpVal = pointer->child->next->next->type;
                                if(compareType(baseval, cmpVal) == 0){
                                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
                                }
                            }
                        }
                    }else{//一维
                        if(symtab_lookup(root, pointer->child->child->child->attribute).a != -1){//ExtDecList->VarDec->VarDec->ID
                            printf("Error type 3 at Line %d: redefine variable: %s \n", ((yylsp[-2])).first_line,pointer->child->child->child->attribute);
                        }else{
                            struct Info *val = malloc(sizeof(Info));
                            struct Type *typehead = malloc(sizeof(Type));
                            struct Array *arr = malloc(sizeof(Array));
                            arr->size =atoi(pointer->child->child->next->next->attribute); //int size
                            if(strcasecmp((yyvsp[-2].treeNode)->child->name, "type") == 0){
                                typehead->name = (yyvsp[-2].treeNode)->child->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->name = (yyvsp[-2].treeNode)->child->attribute;
                            }
                            else{
                                typehead->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->category = STRUCTURE;
                                arr->base->name = (yyvsp[-2].treeNode)->child->child->next->attribute;
                            }
                        // type类型
                            typehead->category = ARRAY;
                            typehead->array = arr;
                            val->a = 1; 
                            val->type = typehead;
                            val->return_type = NULL;
                            val->paraList = NULL;
                            symtab_insert(root, pointer->child->child->child->attribute, *val);
                            Type *baseval = typehead;
                            Type *cmpVal;
                            if(pointer->child->next != NULL){
                                cmpVal = pointer->child->next->next->type;
                                if(compareType(baseval, cmpVal) == 0){
                                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
                                }
                            }
                    }
                        
                    }
                    
                }
                if(pointer->next==NULL) break;
                pointer = pointer->next->next->child;
                }
                
}
#line 2212 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 537 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line);}
#line 2218 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 540 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DecList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2224 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 541 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("DecList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2230 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 544 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Dec",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2236 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 545 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Dec",3,(yyvsp[-2].treeNode),alloNodeC("=","ASSIGN"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2242 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 549 "syntax.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode) = alloNodeC("=","ASSIGN");(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type, (yyvsp[0].treeNode)->type) == 0){
                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
        }
        if((yyvsp[-2].treeNode)->lvalue==0){
            printf("Error type 6 at Line %d: left side in assignment is rvalue\n",((yylsp[-2])).first_line);
        }
}
#line 2255 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 557 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("&&","AND"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2267 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 564 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("||","OR"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2279 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 571 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("<","LT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2291 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 578 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("<=","LE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2303 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 585 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(">","GT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2315 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 592 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(">=","GE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2327 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 599 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("!=","NE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2339 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 606 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("==","EQ"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2351 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 613 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("+","PLUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2363 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 620 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("-","MINUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2375 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 627 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("*","MUL"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2387 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 634 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("/","DIV"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
   if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2399 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 641 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-1].treeNode)->type; 
   }
#line 2408 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 645 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",2,alloNodeC("-","MINUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[0].treeNode)->type; //todo
   }
#line 2417 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 649 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",2,alloNodeC("!","NOT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[0].treeNode)->type;
   }
#line 2426 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 653 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",4,alloNodeC((yyvsp[-3].string_value),"ID"),alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;
        Info val =symtab_lookup(root,(yyval.treeNode)->child->attribute);
        if(val.a!=-1){
            if(val.a == 2){
                if(confirmArgsType((yyvsp[-1].treeNode),val.paraList)==0){
                    if(cnt2==cnt1){
                        printf("Error type 9 at Line %d: invalid argument type for compare\n",((yylsp[-3])).first_line);
                    }
                    else printf("Error type 9 at Line %d: invalid argument number for compare, expect %d, got %d\n",((yylsp[-3])).first_line,cnt2,cnt1);
                } (yyval.treeNode)->type = val.return_type;
            }else {
                (yyval.treeNode)->type = val.type;
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n", ((yylsp[-3])).first_line, (yyvsp[-3].string_value));
            }
        }else printf("Error type 2 at Line %d: undefined function: %s\n", ((yylsp[-3])).first_line,(yyvsp[-3].string_value));
        
   }
#line 2448 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 670 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,alloNodeC((yyvsp[-2].string_value),"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        Info val = symtab_lookup(root,(yyval.treeNode)->child->attribute);
        if(val.a!=-1){
            if(val.a==2){
                if(val.paraList!=NULL){
                    printf("Error type 9 at Line %d: a function's arguments mismatch the declared parameters",((yylsp[-2])).first_line);
                }else (yyval.treeNode)->type = val.return_type;
            }else {
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n", ((yylsp[-2])).first_line, (yyvsp[-2].string_value));
            }
        }
        else {
            printf("Error type 2 at Line %d : function %s is used without definition\n", ((yylsp[-2])).first_line,(yyvsp[-2].string_value));}
   }
#line 2467 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 684 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",4,(yyvsp[-3].treeNode),alloNodeC("[","LB"),(yyvsp[-1].treeNode),alloNodeC("]","RB"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line; (yyval.treeNode)->lvalue=1;
        Info val;
        if(strcasecmp((yyvsp[-3].treeNode)->child->name, "exp") == 0){
            if((yyvsp[-3].treeNode)->child->child != NULL){
                //二维数组
                // printf("%s\n",$1->child->child->attribute);
                val = symtab_lookup(root, (yyvsp[-3].treeNode)->child->child->attribute);
            }else{
                val = symtab_lookup(root,(yyvsp[-3].treeNode)->child->next->next->attribute);
            }
        }
        else{
            val = symtab_lookup(root,(yyvsp[-3].treeNode)->child->attribute);
        } 
        if(val.type->category != ARRAY)
        {
            printf("Error type 10 at Line %d: indexing on non-array variable\n", ((yylsp[-3])).first_line);
        }   
        else{
            if(strcasecmp((yyvsp[-1].treeNode)->type->name,"int")!=0){
                printf("Error type 12 at Line %d: indexing by non-integer\n", ((yylsp[-3])).first_line);
            }
            if((yyvsp[-3].treeNode)->child->child != NULL){
                (yyval.treeNode)->type = (yyvsp[-3].treeNode)->child->type->array->base;
            }else{
                (yyval.treeNode)->type = (yyvsp[-3].treeNode)->type->array->base; 
            }
        }
   }
#line 2501 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 713 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(".","DOT"),alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;(yyval.treeNode)->lvalue=1;
        //struct的类属性
         if((yyvsp[-2].treeNode)->type->category != STRUCTURE){
             printf("Error type 13 at Line %d: accessing with non-struct variable\n", ((yylsp[-2])).first_line);
         }else{
         char *struct_name = (yyvsp[-2].treeNode)->type->name;
            // printf("%s\n",struct_name); 
            struct Info info = symtab_lookup(root, struct_name);
            struct FieldList *ele = info.type->structure;
            int f = 0;
            while(ele != NULL){
            if(strcmp(ele->name,(yyval.treeNode)->child->next->next->attribute) == 0){
                f = 1;
                break;
            }
            ele = ele->next;
            }
            if(f == 0){
                printf("Error type 14 at Line %d: no such member: %s\n",((yylsp[-2])).first_line, (yyval.treeNode)->child->next->next->attribute);
            }
        } 
        (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->next->next->attribute).type; 
   }
#line 2529 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 736 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line; (yyval.treeNode)->lvalue=1;
        (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->attribute).type;
        if(symtab_lookup(root, (yyval.treeNode)->child->attribute).a == -1){
            printf("Error type 1 at Line %d: undefined variable: %s\n", ((yylsp[0])).first_line,(yyvsp[0].string_value));
        }
   }
#line 2540 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 742 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeI((yyvsp[0].int_value),"INT"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "int";
        (yyval.treeNode)->type -> category = PRIMITIVE;
   }
#line 2550 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 747 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"FLOAT"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "float";
        (yyval.treeNode)->type -> category = PRIMITIVE;
   }
#line 2560 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 752 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"CHAR"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "char";
        (yyval.treeNode)->type-> category = PRIMITIVE;
   }
#line 2570 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 757 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",3,alloNodeC("read","READ"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2576 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 758 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode)=insert("Exp",4, alloNodeC("write","WRITE"), alloNodeC("(", "LP"), (yyvsp[-1].treeNode), alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 2582 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 759 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-1])).first_line,(yyvsp[-1].string_value));}
#line 2588 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 760 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",((yylsp[-1])).first_line);}
#line 2594 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 761 "syntax.y" /* yacc.c:1646  */
    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-2])).first_line,(yyvsp[-2].string_value));}
#line 2600 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 763 "syntax.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode)= alloNodeC(",","COMMA"); (yyval.treeNode) = insert("Args",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2606 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 764 "syntax.y" /* yacc.c:1646  */
    {(yyval.treeNode) = insert("Args",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2612 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2616 "syntax.tab.c" /* yacc.c:1646  */
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
#line 767 "syntax.y" /* yacc.c:1906  */

void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d\n", s, yylineno);
}

char* translate_stmt(node* stmtList){
    if(strcasecmp(stmtList->child->child->name, "Exp") == 0){
        char* tp = new_place();
        printf("%s",translate_Exp(stmtList->child->child, tp));
    }
    if(strcasecmp(stmtList->child->child->name, "IF") == 0){
        char* lb1 = new_label();
        char* lb2 = new_label();
        
    }
    if(strcasecmp(stmtList->child->child->name, "WHILE") == 0){

    }
    if(strcasecmp(stmtList->child->child->name, "RETURN") == 0){
        char* tp = new_place();
        printf("%s",translate_Exp(stmtList->child->child->next, tp));
        printf("RETURN %s\n", tp);
    }
}

char* translate_Exp(node* Exp, char* place){
    if(strcasecmp(Exp->child->name, "read")==0){
        char* buff = malloc(32);
        sprintf(buff, "READ %s\n", place);
        return buff;
    }
    if(strcasecmp(Exp->child->name, "write")==0){;
        char* place = new_place();
        char* buff = malloc(32);
        sprintf(buff, "%sWRITE %s\n", translate_Exp(Exp->child->next->next, place), place);
        return buff;
    }
    if(strcasecmp(Exp->child->name, "id") == 0){
        if(strcasecmp(Exp->child->next->next->name, "RP") == 0){
            Info function = symtab_lookup(root, Exp->child->attribute);
            char* buff = malloc(32);
            sprintf(buff, "%s := CALL %s\n", place, Exp->child->attribute);
            return buff;
        }
        if(strcasecmp(Exp->child->next->next->name, "args") == 0){
            Info function = symtab_lookup(root, Exp->child->attribute);
            int arglist[10] = {0};
            char* code1 = translate_Args(Exp->child->next->next, arglist);
            //char* code1 = "hh";
            char* code2 = malloc(64);
            for(int i = 0; i < 10; i++){
                if(arglist[i] != 0){
                    sprintf(code2, "%sARG t%d\n", code2, arglist[i]);
                }
            }
            char* buff = malloc(64);
            sprintf(buff, "%s%s%s := CALL %s\n", code1, code2, place,Exp->child->attribute);
            return buff;
        }
    }
    return NULL;
}

char* translate_Args(node* Args, int* arglist){
    if(Args->child->next == NULL){
        char* tp = new_place();
        char* code = translate_Exp(Args->child, tp);
        for(int i = 0; i < 10; i++){
            if(arglist[i] == 0){
                arglist[i] = count1 - 1;
                break;
            }
        }
        return code;
    }
    else{
        char* tp = new_place();
        char* code1 = translate_Exp(Args->child, tp);
        for(int i = 0; i < 10; i++){
            if(arglist[i] == 0){
                arglist[i] = count1 - 1;
                break;
            }
        }
        char* code2 = translate_Args(Args->child->next->next, arglist);
        char* buff = malloc(64);
        sprintf(buff, "%s%s", code1, code2);
        return buff;
    }
    
}
char* new_place(){
    char* buff = malloc(32);
    sprintf(buff,"t%d",count1);
    count1++;
    return buff;
}


char* new_label(){
    char buff[10] = {0};
    sprintf(buff,"%d",count2);
    count2++;
    return strcat(buff, "lable");
}

int confirmReturnType(node* root,char * returnType){
    int re = 1;
    if(root->child!=NULL){
        node* p = root->child;
        while(p!=NULL){
            if(strcasecmp(p->name,"return")==0) {
                line = p->lineNo;
                if(p->next->type){
                    re = re & !strcasecmp(p->next->type->name,returnType);
                }
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
    cnt1=0;
    cnt2=0;
    int re =1;
    node * r;
    r = root;
    while(r->child!=NULL){
        cnt1 = cnt1 + 1;
        if(r->child->next==NULL) break;
        r = r->child->next-> next;
    }
    ParaList* p = parameters;
    while(p!=NULL){
        p = p->next;
        cnt2 = cnt2 + 1;
    }
    p= parameters;
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
    struct Info *val = malloc(sizeof(Info));
    struct Type *returnType = malloc(sizeof(Type));
    returnType->name= "int";
    returnType->category = PRIMITIVE;//todo
    struct ParaList *paralist;
    val->type = NULL;
    paralist = NULL;
    val->a = 2;
    val->return_type = returnType;
    val->paraList = paralist;
    symtab_insert(root, "read", *val);

    struct Info *val1 = malloc(sizeof(Info));
    struct Type *returnType1 = malloc(sizeof(Type));
    returnType1->name= "int";
    returnType1->category = PRIMITIVE;//todo
    ParaList *paralist1;
    val1->type = NULL;

    struct Type *para = malloc(sizeof(Type));
    para->name = "int";
    para->category = PRIMITIVE;//todo
    paralist1 = malloc(sizeof(ParaList));
    paralist1->type = para;
    paralist1->next = NULL;
    
    val1->a = 2;
    val1->return_type = returnType1;
    val1->paraList = paralist1;
    symtab_insert(root, "write", *val1);


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
