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
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
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
#line 1 "syntax.y"

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
    char* translate_cond_Exp(node* Exp, char* lb1, char* lb2);
    char* translate_stmt(node* stmt);
    char* translate_Exp(node* Exp, char* place);
    char* translate_Args(node* Args, int* arglist);
    char* translate_def(node* def);

#line 106 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_INCLUSION = 8,                  /* INCLUSION  */
  YYSYMBOL_DEFINE = 9,                     /* DEFINE  */
  YYSYMBOL_STRUCT = 10,                    /* STRUCT  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_SEMI = 14,                      /* SEMI  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_WRITE = 18,                     /* WRITE  */
  YYSYMBOL_LOWER_ELSE = 19,                /* LOWER_ELSE  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_MUL = 32,                       /* MUL  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_LP = 35,                        /* LP  */
  YYSYMBOL_RP = 36,                        /* RP  */
  YYSYMBOL_LB = 37,                        /* LB  */
  YYSYMBOL_RB = 38,                        /* RB  */
  YYSYMBOL_LC = 39,                        /* LC  */
  YYSYMBOL_RC = 40,                        /* RC  */
  YYSYMBOL_DOT = 41,                       /* DOT  */
  YYSYMBOL_FAULT = 42,                     /* FAULT  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_Program = 44,                   /* Program  */
  YYSYMBOL_Headers = 45,                   /* Headers  */
  YYSYMBOL_Header = 46,                    /* Header  */
  YYSYMBOL_ExtDefList = 47,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 48,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 49,                /* ExtDecList  */
  YYSYMBOL_Specifier = 50,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 51,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 52,                    /* VarDec  */
  YYSYMBOL_FunDec = 53,                    /* FunDec  */
  YYSYMBOL_VarList = 54,                   /* VarList  */
  YYSYMBOL_ParamDec = 55,                  /* ParamDec  */
  YYSYMBOL_CompSt = 56,                    /* CompSt  */
  YYSYMBOL_StmtList = 57,                  /* StmtList  */
  YYSYMBOL_Stmt = 58,                      /* Stmt  */
  YYSYMBOL_DefList = 59,                   /* DefList  */
  YYSYMBOL_Def = 60,                       /* Def  */
  YYSYMBOL_DecList = 61,                   /* DecList  */
  YYSYMBOL_Dec = 62,                       /* Dec  */
  YYSYMBOL_Exp = 63,                       /* Exp  */
  YYSYMBOL_Args = 64                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
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
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
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
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
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
          YYPTRDIFF_T yyi;                      \
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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    68,    69,    71,    72,    75,    76,    79,
     181,   269,   284,   285,   289,   290,   293,   302,   306,   307,
     308,   309,   312,   370,   389,   392,   393,   396,   418,   419,
     422,   423,   426,   428,   429,   431,   432,   433,   434,   435,
     436,   440,   441,   446,   580,   583,   584,   587,   588,   592,
     600,   607,   614,   621,   628,   635,   642,   649,   656,   663,
     670,   677,   684,   688,   692,   696,   713,   727,   756,   779,
     785,   790,   795,   800,   801,   802,   803,   804,   806,   807
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "ID", "TYPE", "INCLUSION", "DEFINE", "STRUCT", "IF", "WHILE", "RETURN",
  "SEMI", "COMMA", "FOR", "READ", "WRITE", "LOWER_ELSE", "ELSE", "ASSIGN",
  "OR", "AND", "NE", "EQ", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "MUL",
  "DIV", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "DOT", "FAULT",
  "$accept", "Program", "Headers", "Header", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
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
static const yytype_int8 yydefact[] =
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
       0,     1,     2,     8,     9,    10,    18,    29,    12,    19,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: Headers ExtDefList  */
#line 62 "syntax.y"
                             {
    (yyval.treeNode) = insert("Program",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));
    (yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
    // if(flag ==0){printTree($$,0);}
    }
#line 1444 "syntax.tab.c"
    break;

  case 3: /* Headers: Headers Header  */
#line 68 "syntax.y"
                         {(yyval.treeNode) = insert("Headers",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1450 "syntax.tab.c"
    break;

  case 4: /* Headers: %empty  */
#line 69 "syntax.y"
      {(yyval.treeNode) = insert("Headers",0);}
#line 1456 "syntax.tab.c"
    break;

  case 5: /* Header: INCLUSION  */
#line 71 "syntax.y"
                   {(yyval.treeNode)=insert("Header",1,alloNodeC((yyvsp[0].string_value),"INCLUSION"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1462 "syntax.tab.c"
    break;

  case 6: /* Header: DEFINE  */
#line 72 "syntax.y"
             {(yyval.treeNode)=insert("Header",1,alloNodeC((yyvsp[0].string_value),"DEFINE"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1468 "syntax.tab.c"
    break;

  case 7: /* ExtDefList: ExtDef ExtDefList  */
#line 75 "syntax.y"
                              { (yyval.treeNode) = insert("ExtDefList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1474 "syntax.tab.c"
    break;

  case 8: /* ExtDefList: %empty  */
#line 76 "syntax.y"
            {(yyval.treeNode) = insert("ExtDefList",0);}
#line 1480 "syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier ExtDecList SEMI  */
#line 79 "syntax.y"
                                   {(yyval.treeNode) = insert("ExtDef",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    node* pointer = (yyvsp[-1].treeNode)->child; // VarDec
                while(1){
                    if(strcmp(pointer->child->name, "ID") == 0){
                        if(symtab_lookup(root, pointer->child->attribute)->a != -1){
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
                                val->t = -1;
                                symtab_insert(root, pointer->child->attribute, *val);
                            }else{//插入结构体的声明
                                // printf("1");
                                struct Info *info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = (yyvsp[-2].treeNode)->child->child->next->attribute; //结构体名字
                                type->category = STRUCTURE;
                                info->type = type;
                                info->a = 3;
                                info->t = -1;
                                symtab_insert(root, pointer->child->attribute, *info);
                            }
                        }
                }else{
                        //VarDec LB INT RB
                        node *pp = pointer->child; //VarDeC或者ID
                        // printf("%s\n", pp->attribute);
                            if(strcmp(pp->child->name, "ID") == 0){//一维数组
                                if(symtab_lookup(root, pp->child->attribute)->a != -1){//是否重复ID
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
                                    val->t = -1;
                                    symtab_insert(root, pp->child->attribute, *val);
                                }    
                            }else {//二维数组
                                node *pid = pp->child; //ID
                                if(symtab_lookup(root, pid->child->attribute)->a != -1){//是否重复ID
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
                                    val->t = -1;
                                    symtab_insert(root, pp->child->child->attribute, *val);
                                }
                                
                            }
                }
                if(pointer->next==NULL) break;
                pointer = pointer->next->next->child; //到下一个VarDec
                }
}
#line 1587 "syntax.tab.c"
    break;

  case 10: /* ExtDef: Specifier SEMI  */
#line 181 "syntax.y"
                       {(yyval.treeNode) = insert("ExtDef",2,(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line; 
      //specifier->structspecifier->STRUCT ID LC DefList RC
            if(symtab_lookup(root, (yyvsp[-1].treeNode)->child->child->next->attribute)->a ==3){
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
                                    info0->t = -1;
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
                                        info1->t = -1;
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
                                info->t = -1;
                                // printf("%s\n",info->type->name);
                                symtab_insert(root, (yyvsp[-1].treeNode)->child->child->next->attribute, *info);
            }  
      }
#line 1680 "syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier FunDec CompSt  */
#line 269 "syntax.y"
                                {(yyval.treeNode) = insert("ExtDef",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
                node* defList = (yyvsp[0].treeNode)->child->next;
                while(defList->child != NULL){
                    printf("%s",translate_def(defList->child));
                    defList = defList->child->next;
                }
                node* stmtList = (yyvsp[0].treeNode)->child->next->next;
                while(stmtList->child != NULL){
                    printf("%s",translate_stmt(stmtList->child));
                    stmtList = stmtList->child->next;
                }
                 
      }
#line 1698 "syntax.tab.c"
    break;

  case 12: /* ExtDecList: VarDec  */
#line 284 "syntax.y"
                   {(yyval.treeNode) = insert("ExtDecList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1704 "syntax.tab.c"
    break;

  case 13: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 285 "syntax.y"
                                    {(yyval.treeNode) = insert("ExtDecList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1710 "syntax.tab.c"
    break;

  case 14: /* Specifier: TYPE  */
#line 289 "syntax.y"
                {(yyval.treeNode) = insert("Specifier",1,alloNodeC((yyvsp[0].string_value),"TYPE"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1716 "syntax.tab.c"
    break;

  case 15: /* Specifier: StructSpecifier  */
#line 290 "syntax.y"
                           {(yyval.treeNode) = insert("Specifier",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1722 "syntax.tab.c"
    break;

  case 16: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 293 "syntax.y"
                                         {
                (yyval.treeNode) = insert("StructSpecifier",5,
                alloNodeC("struct","STRUCT"),
                alloNodeC((yyvsp[-3].string_value),"ID"),
                alloNodeC("{","LC"),
                (yyvsp[-1].treeNode),
                alloNodeC("}","RC")
                );
                (yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1736 "syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT ID  */
#line 302 "syntax.y"
                           {(yyval.treeNode) = insert("StructSpecifier",2,alloNodeC("struct","STRUCT"),alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1742 "syntax.tab.c"
    break;

  case 18: /* VarDec: ID  */
#line 306 "syntax.y"
           {(yyval.treeNode) = insert("VarDec",1,alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1748 "syntax.tab.c"
    break;

  case 19: /* VarDec: VarDec LB INT RB  */
#line 307 "syntax.y"
                         {(yyval.treeNode) = insert("VarDec",4,(yyvsp[-3].treeNode),alloNodeC("[","LB"),alloNodeI((yyvsp[-1].int_value),"INT"),alloNodeC("]","RB"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 1754 "syntax.tab.c"
    break;

  case 20: /* VarDec: FAULT error  */
#line 308 "syntax.y"
                    {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-1])).first_line,(yyvsp[-1].string_value));}
#line 1760 "syntax.tab.c"
    break;

  case 21: /* VarDec: VarDec LB error RB  */
#line 309 "syntax.y"
                           {flag=1; printf("Error type B at Line %d: Wrong type of index\n",((yylsp[-3])).first_line);}
#line 1766 "syntax.tab.c"
    break;

  case 22: /* FunDec: ID LP VarList RP  */
#line 312 "syntax.y"
                         {(yyval.treeNode) = insert("FunDec",4,alloNodeC((yyvsp[-3].string_value),"ID"),alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;
    if(symtab_lookup(root, (yyval.treeNode)->child->attribute)->a != -1){printf("Error type 4 at Line %d: redefine function: %s\n",((yylsp[-3])).first_line,(yyval.treeNode)->child->attribute);}
            else{
              struct Info *val = malloc(sizeof(Info));
              struct Type *returnType = malloc(sizeof(Type));
              returnType->name= "int";
              returnType->category = PRIMITIVE;//todo
              struct ParaList *paralist;
              val->type = NULL;
              if((yyval.treeNode)->child->next->next->next != NULL){
                    node* cur = (yyval.treeNode)->child->next->next->child;
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
                val->t = -1;
                symtab_insert(root, (yyval.treeNode)->child->attribute, *val);
                printf("FUNCTION %s :\n", (yyval.treeNode)->child->attribute);
                node* varList = (yyval.treeNode)->child->next->next;
                char* place = new_place();
                Info *id = symtab_lookup(root, varList->child->child->next->child->attribute);
                id->t = count1 - 1;
                printf("PARAM %s\n", place);
                while(varList->child->next != NULL){
                    place = new_place();
                    printf("PARAM %s\n", place);
                    varList = varList->child->next->next;
                    Info *id1 = symtab_lookup(root, varList->child->child->next->child->attribute);
                    id1->t = count1 - 1;
                }
                
                
            }  

       
      }
#line 1828 "syntax.tab.c"
    break;

  case 23: /* FunDec: ID LP RP  */
#line 370 "syntax.y"
                 {(yyval.treeNode) = insert("FunDec",3,alloNodeC((yyvsp[-2].string_value),"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
            if(symtab_lookup(root, (yyval.treeNode)->child->attribute)->a != -1){printf("Error type 4 at Line %d: redefine function: %s\n",((yylsp[-2])).first_line,(yyval.treeNode)->child->attribute);}
            else{
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
                val->t = -1;
                symtab_insert(root, (yyval.treeNode)->child->attribute, *val);
                printf("FUNCTION %s :\n", (yyval.treeNode)->child->attribute);
                 
      }
      }
#line 1852 "syntax.tab.c"
    break;

  case 24: /* FunDec: ID LP error  */
#line 389 "syntax.y"
                    {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",((yylsp[-1])).first_line);}
#line 1858 "syntax.tab.c"
    break;

  case 25: /* VarList: ParamDec COMMA VarList  */
#line 392 "syntax.y"
                                {(yyval.treeNode) = insert("VarList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 1864 "syntax.tab.c"
    break;

  case 26: /* VarList: ParamDec  */
#line 393 "syntax.y"
                  {(yyval.treeNode) = insert("VarList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1870 "syntax.tab.c"
    break;

  case 27: /* ParamDec: Specifier VarDec  */
#line 396 "syntax.y"
                           {(yyval.treeNode) = insert("ParamDec",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
                if(strcmp((yyvsp[0].treeNode)->child->name, "ID") == 0){
                    if(symtab_lookup(root, (yyvsp[0].treeNode)->child->attribute)->a != -1){
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
                                val->t = -1;
                                symtab_insert(root, (yyvsp[0].treeNode)->child->attribute, *val);
                            }
                    }
                }
 }
#line 1894 "syntax.tab.c"
    break;

  case 28: /* CompSt: LC DefList StmtList RC  */
#line 418 "syntax.y"
                               {(yyval.treeNode) = insert("CompSt",4,alloNodeC("{","LC"),(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC("}","RC"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1900 "syntax.tab.c"
    break;

  case 29: /* CompSt: LC DefList StmtList error  */
#line 419 "syntax.y"
                                  {flag=1; printf("Error type B at Line %d: Missing specifier\n",((yylsp[-1])).first_line);}
#line 1906 "syntax.tab.c"
    break;

  case 30: /* StmtList: Stmt StmtList  */
#line 422 "syntax.y"
                         {(yyval.treeNode) = insert("StmtList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1912 "syntax.tab.c"
    break;

  case 31: /* StmtList: %empty  */
#line 423 "syntax.y"
            {(yyval.treeNode) = insert("StmtList",0);}
#line 1918 "syntax.tab.c"
    break;

  case 32: /* Stmt: Exp SEMI  */
#line 426 "syntax.y"
               {(yyval.treeNode) = insert("Stmt",2,(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
}
#line 1925 "syntax.tab.c"
    break;

  case 33: /* Stmt: CompSt  */
#line 428 "syntax.y"
             {(yyval.treeNode) = insert("Stmt",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 1931 "syntax.tab.c"
    break;

  case 34: /* Stmt: RETURN Exp SEMI  */
#line 429 "syntax.y"
                      {(yyvsp[-2].treeNode) =alloNodeC("return","RETURN"); (yyvsp[-2].treeNode)->lineNo=((yylsp[-2])).first_line; (yyval.treeNode) = insert("Stmt",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    }
#line 1938 "syntax.tab.c"
    break;

  case 35: /* Stmt: IF LP Exp RP Stmt  */
#line 431 "syntax.y"
                                         {(yyval.treeNode) = insert("Stmt",5,alloNodeC("if","IF"),alloNodeC("(","LP"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1944 "syntax.tab.c"
    break;

  case 36: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 432 "syntax.y"
                                  {(yyval.treeNode) = insert("Stmt",7,alloNodeC("if","IF"),alloNodeC("(","LP"),(yyvsp[-4].treeNode),alloNodeC(")","RP"),(yyvsp[-2].treeNode),alloNodeC("else","ELSE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-6]);(yyval.treeNode)->lineNo=((yylsp[-6])).first_line;}
#line 1950 "syntax.tab.c"
    break;

  case 37: /* Stmt: WHILE LP Exp RP Stmt  */
#line 433 "syntax.y"
                           {(yyval.treeNode) = insert("Stmt",5,alloNodeC("while","WHILE"),alloNodeC("(","LP"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-4]);(yyval.treeNode)->lineNo=((yylsp[-4])).first_line;}
#line 1956 "syntax.tab.c"
    break;

  case 38: /* Stmt: RETURN Exp error  */
#line 434 "syntax.y"
                       {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line); }
#line 1962 "syntax.tab.c"
    break;

  case 39: /* Stmt: FOR LP Exp SEMI Exp SEMI Exp RP Stmt  */
#line 435 "syntax.y"
                                           {(yyval.treeNode) = insert("Stmt",9,alloNodeC("for","FOR"),alloNodeC("(","LP"),(yyvsp[-6].treeNode),alloNodeC(";","SEMI"),(yyvsp[-4].treeNode),alloNodeC(";","SEMI"),(yyvsp[-2].treeNode),alloNodeC(")","RP"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-8]);(yyval.treeNode)->lineNo=((yylsp[-8])).first_line;}
#line 1968 "syntax.tab.c"
    break;

  case 40: /* Stmt: Exp error  */
#line 436 "syntax.y"
                {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line); }
#line 1974 "syntax.tab.c"
    break;

  case 41: /* DefList: Def DefList  */
#line 440 "syntax.y"
                     {(yyval.treeNode) = insert("DefList",2,(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;}
#line 1980 "syntax.tab.c"
    break;

  case 42: /* DefList: %empty  */
#line 441 "syntax.y"
                                {(yyval.treeNode) = insert("DefList",0);
       
       }
#line 1988 "syntax.tab.c"
    break;

  case 43: /* Def: Specifier DecList SEMI  */
#line 446 "syntax.y"
                            {(yyval.treeNode) = insert("Def",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),alloNodeC(";","SEMI"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
                node* pointer = (yyvsp[-1].treeNode)->child;
                while(1){
                    if(strcmp(pointer->child->child->name, "ID") == 0){
                        if(symtab_lookup(root, pointer->child->child->attribute)->a != -1){
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
                                val->t = -1;
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
                                info->t = -1;
                                symtab_insert(root, pointer->child->child->attribute, *info);
                            }
                        }
                }else{
                    //数组
                    
                    //首先判断是否为二维
                    if(pointer->child->child->child->next != NULL){
                        //二维
                        // printf("%s\n",pointer->child->child->child->child->attribute);
                        if(symtab_lookup(root, pointer->child->child->child->child->attribute)->a != -1){//ExtDecList->VarDec->VarDec->ID
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
                            val->t = -1;
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
                        if(symtab_lookup(root, pointer->child->child->child->attribute)->a != -1){//ExtDecList->VarDec->VarDec->ID
                            printf("Error type 3 at Line %d: redefine variable: %s \n", ((yylsp[-2])).first_line,pointer->child->child->child->attribute);
                        }else{
                            struct Info *val = malloc(sizeof(Info));
                            struct Type *typehead = malloc(sizeof(Type));
                            struct Array *arr = malloc(sizeof(Array));
                            arr->size =atoi(pointer->child->child->next->next->attribute); //int size
                            arr->size_col = -1;
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
                            val->t = -1;
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
#line 2127 "syntax.tab.c"
    break;

  case 44: /* Def: Specifier DecList error  */
#line 580 "syntax.y"
                            {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",((yylsp[-1])).first_line);}
#line 2133 "syntax.tab.c"
    break;

  case 45: /* DecList: Dec  */
#line 583 "syntax.y"
             {(yyval.treeNode) = insert("DecList",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2139 "syntax.tab.c"
    break;

  case 46: /* DecList: Dec COMMA DecList  */
#line 584 "syntax.y"
                           {(yyval.treeNode) = insert("DecList",3,(yyvsp[-2].treeNode),alloNodeC(",","COMMA"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2145 "syntax.tab.c"
    break;

  case 47: /* Dec: VarDec  */
#line 587 "syntax.y"
            {(yyval.treeNode)=insert("Dec",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2151 "syntax.tab.c"
    break;

  case 48: /* Dec: VarDec ASSIGN Exp  */
#line 588 "syntax.y"
                       {(yyval.treeNode)=insert("Dec",3,(yyvsp[-2].treeNode),alloNodeC("=","ASSIGN"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2157 "syntax.tab.c"
    break;

  case 49: /* Exp: Exp ASSIGN Exp  */
#line 592 "syntax.y"
                    {(yyvsp[-1].treeNode) = alloNodeC("=","ASSIGN");(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type, (yyvsp[0].treeNode)->type) == 0){
                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", ((yylsp[-2])).first_line);
        }
        if((yyvsp[-2].treeNode)->lvalue==0){
            printf("Error type 6 at Line %d: left side in assignment is rvalue\n",((yylsp[-2])).first_line);
        }
}
#line 2170 "syntax.tab.c"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 600 "syntax.y"
                 {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("&&","AND"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2182 "syntax.tab.c"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 607 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("||","OR"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2194 "syntax.tab.c"
    break;

  case 52: /* Exp: Exp LT Exp  */
#line 614 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("<","LT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2206 "syntax.tab.c"
    break;

  case 53: /* Exp: Exp LE Exp  */
#line 621 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("<=","LE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2218 "syntax.tab.c"
    break;

  case 54: /* Exp: Exp GT Exp  */
#line 628 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(">","GT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2230 "syntax.tab.c"
    break;

  case 55: /* Exp: Exp GE Exp  */
#line 635 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(">=","GE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2242 "syntax.tab.c"
    break;

  case 56: /* Exp: Exp NE Exp  */
#line 642 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("!=","NE"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2254 "syntax.tab.c"
    break;

  case 57: /* Exp: Exp EQ Exp  */
#line 649 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("==","EQ"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2266 "syntax.tab.c"
    break;

  case 58: /* Exp: Exp PLUS Exp  */
#line 656 "syntax.y"
                  {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("+","PLUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2278 "syntax.tab.c"
    break;

  case 59: /* Exp: Exp MINUS Exp  */
#line 663 "syntax.y"
                   {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("-","MINUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
    }
#line 2290 "syntax.tab.c"
    break;

  case 60: /* Exp: Exp MUL Exp  */
#line 670 "syntax.y"
                 {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("*","MUL"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
    if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2302 "syntax.tab.c"
    break;

  case 61: /* Exp: Exp DIV Exp  */
#line 677 "syntax.y"
                 {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC("/","DIV"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
   if(compareType((yyvsp[-2].treeNode)->type,(yyvsp[0].treeNode)->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",((yylsp[-2])).first_line);
        }
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-2].treeNode)->type; 
   }
#line 2314 "syntax.tab.c"
    break;

  case 62: /* Exp: LP Exp RP  */
#line 684 "syntax.y"
               {(yyval.treeNode)=insert("Exp",3,alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[-1].treeNode)->type; 
   }
#line 2323 "syntax.tab.c"
    break;

  case 63: /* Exp: MINUS Exp  */
#line 688 "syntax.y"
               {(yyval.treeNode)=insert("Exp",2,alloNodeC("-","MINUS"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[0].treeNode)->type; //todo
   }
#line 2332 "syntax.tab.c"
    break;

  case 64: /* Exp: NOT Exp  */
#line 692 "syntax.y"
             {(yyval.treeNode)=insert("Exp",2,alloNodeC("!","NOT"),(yyvsp[0].treeNode));(yyloc) = (yylsp[-1]);(yyval.treeNode)->lineNo=((yylsp[-1])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type = (yyvsp[0].treeNode)->type;
   }
#line 2341 "syntax.tab.c"
    break;

  case 65: /* Exp: ID LP Args RP  */
#line 696 "syntax.y"
                   {(yyval.treeNode)=insert("Exp",4,alloNodeC((yyvsp[-3].string_value),"ID"),alloNodeC("(","LP"),(yyvsp[-1].treeNode),alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;
        Info* val =symtab_lookup(root,(yyval.treeNode)->child->attribute);
        if(val->a!=-1){
            if(val->a == 2){
                if(confirmArgsType((yyvsp[-1].treeNode),val->paraList)==0){
                    if(cnt2==cnt1){
                        printf("Error type 9 at Line %d: invalid argument type for compare\n",((yylsp[-3])).first_line);
                    }
                    else printf("Error type 9 at Line %d: invalid argument number for compare, expect %d, got %d\n",((yylsp[-3])).first_line,cnt2,cnt1);
                } (yyval.treeNode)->type = val->return_type;
            }else {
                (yyval.treeNode)->type = val->type;
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n", ((yylsp[-3])).first_line, (yyvsp[-3].string_value));
            }
        }else printf("Error type 2 at Line %d: undefined function: %s\n", ((yylsp[-3])).first_line,(yyvsp[-3].string_value));
        
   }
#line 2363 "syntax.tab.c"
    break;

  case 66: /* Exp: ID LP RP  */
#line 713 "syntax.y"
              {(yyval.treeNode)=insert("Exp",3,alloNodeC((yyvsp[-2].string_value),"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;
        Info* val = symtab_lookup(root,(yyval.treeNode)->child->attribute);
        if(val->a!=-1){
            if(val->a==2){
                if(val->paraList!=NULL){
                    printf("Error type 9 at Line %d: a function's arguments mismatch the declared parameters",((yylsp[-2])).first_line);
                }else (yyval.treeNode)->type = val->return_type;
            }else {
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n", ((yylsp[-2])).first_line, (yyvsp[-2].string_value));
            }
        }
        else {
            printf("Error type 2 at Line %d : function %s is used without definition\n", ((yylsp[-2])).first_line,(yyvsp[-2].string_value));}
   }
#line 2382 "syntax.tab.c"
    break;

  case 67: /* Exp: Exp LB Exp RB  */
#line 727 "syntax.y"
                   {(yyval.treeNode)=insert("Exp",4,(yyvsp[-3].treeNode),alloNodeC("[","LB"),(yyvsp[-1].treeNode),alloNodeC("]","RB"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line; (yyval.treeNode)->lvalue=1;
        Info* val;
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
        if(val->type->category != ARRAY)
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
#line 2416 "syntax.tab.c"
    break;

  case 68: /* Exp: Exp DOT ID  */
#line 756 "syntax.y"
                {(yyval.treeNode)=insert("Exp",3,(yyvsp[-2].treeNode),alloNodeC(".","DOT"),alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;(yyval.treeNode)->lvalue=1;
        //struct的类属性
         if((yyvsp[-2].treeNode)->type->category != STRUCTURE){
             printf("Error type 13 at Line %d: accessing with non-struct variable\n", ((yylsp[-2])).first_line);
         }else{
         char *struct_name = (yyvsp[-2].treeNode)->type->name;
            // printf("%s\n",struct_name); 
            struct Info* info = symtab_lookup(root, struct_name);
            struct FieldList *ele = info->type->structure;
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
        (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->next->next->attribute)->type; 
   }
#line 2444 "syntax.tab.c"
    break;

  case 69: /* Exp: ID  */
#line 779 "syntax.y"
        {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"ID"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line; (yyval.treeNode)->lvalue=1;
        (yyval.treeNode)->type = symtab_lookup(root,(yyval.treeNode)->child->attribute)->type;
        if(symtab_lookup(root, (yyval.treeNode)->child->attribute)->a == -1){
            printf("Error type 1 at Line %d: undefined variable: %s\n", ((yylsp[0])).first_line,(yyvsp[0].string_value));
        }
   }
#line 2455 "syntax.tab.c"
    break;

  case 70: /* Exp: INT  */
#line 785 "syntax.y"
         {(yyval.treeNode)=insert("Exp",1,alloNodeI((yyvsp[0].int_value),"INT"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "int";
        (yyval.treeNode)->type -> category = PRIMITIVE;
   }
#line 2465 "syntax.tab.c"
    break;

  case 71: /* Exp: FLOAT  */
#line 790 "syntax.y"
           {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"FLOAT"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "float";
        (yyval.treeNode)->type -> category = PRIMITIVE;
   }
#line 2475 "syntax.tab.c"
    break;

  case 72: /* Exp: CHAR  */
#line 795 "syntax.y"
          {(yyval.treeNode)=insert("Exp",1,alloNodeC((yyvsp[0].string_value),"CHAR"));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;
        (yyval.treeNode)->type = malloc(sizeof(Type));
        (yyval.treeNode)->type->name = "char";
        (yyval.treeNode)->type-> category = PRIMITIVE;
   }
#line 2485 "syntax.tab.c"
    break;

  case 73: /* Exp: READ LP RP  */
#line 800 "syntax.y"
               {(yyval.treeNode)=insert("Exp",3,alloNodeC("read","READ"),alloNodeC("(","LP"),alloNodeC(")","RP"));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2491 "syntax.tab.c"
    break;

  case 74: /* Exp: WRITE LP Exp RP  */
#line 801 "syntax.y"
                    {(yyval.treeNode)=insert("Exp",4, alloNodeC("write","WRITE"), alloNodeC("(", "LP"), (yyvsp[-1].treeNode), alloNodeC(")","RP"));(yyloc) = (yylsp[-3]);(yyval.treeNode)->lineNo=((yylsp[-3])).first_line;}
#line 2497 "syntax.tab.c"
    break;

  case 75: /* Exp: FAULT error  */
#line 802 "syntax.y"
                 {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-1])).first_line,(yyvsp[-1].string_value));}
#line 2503 "syntax.tab.c"
    break;

  case 76: /* Exp: ID LP Args error  */
#line 803 "syntax.y"
                      {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",((yylsp[-1])).first_line);}
#line 2509 "syntax.tab.c"
    break;

  case 77: /* Exp: Exp FAULT Exp error  */
#line 804 "syntax.y"
                        {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",((yylsp[-2])).first_line,(yyvsp[-2].string_value));}
#line 2515 "syntax.tab.c"
    break;

  case 78: /* Args: Exp COMMA Args  */
#line 806 "syntax.y"
                     {(yyvsp[-1].treeNode)= alloNodeC(",","COMMA"); (yyval.treeNode) = insert("Args",3,(yyvsp[-2].treeNode),(yyvsp[-1].treeNode),(yyvsp[0].treeNode));(yyloc) = (yylsp[-2]);(yyval.treeNode)->lineNo=((yylsp[-2])).first_line;}
#line 2521 "syntax.tab.c"
    break;

  case 79: /* Args: Exp  */
#line 807 "syntax.y"
          {(yyval.treeNode) = insert("Args",1,(yyvsp[0].treeNode));(yyloc) = (yylsp[0]);(yyval.treeNode)->lineNo=((yylsp[0])).first_line;}
#line 2527 "syntax.tab.c"
    break;


#line 2531 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 810 "syntax.y"

void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d\n", s, yylineno);
}
char* translate_def(node* def){
    node* decList = def->child->next;
    char* code = malloc(1024);
    if(strcasecmp(def->child->child->name, "type") == 0){
        while(decList->child->next != NULL){//有comma
            node* dec = decList->child;
            if(dec->child->next == NULL){//assign
                node* varDec = dec->child;
                if(strcasecmp(varDec->child->name, "vardec") == 0){//array
                    while(strcasecmp(varDec->child->name, "vardec") == 0){
                        varDec = varDec->child; //找到array name
                    }
                    Info* arr = symtab_lookup(root, varDec->child->attribute);
                    int size = 0;
                    if(arr->type->array->size_col == -1){
                        size = arr->type->array->size * 4;
                    }
                    else {
                       size = arr->type->array->size * arr->type->array->size_col * 4; 
                    }
                    char* tp = new_place();
                    arr->t = count1 - 1;
                    sprintf(code, "%sDEC %s %d\n", code, tp, size);
                }else{
                    //int n
                    Info* val = symtab_lookup(root,varDec->child->attribute);
                    char* tp = new_place();
                    val->t = count1-1;
                }
            }
            else{
                Info* id = symtab_lookup(root, dec->child->child->attribute);
                char* tp = new_place();
                id->t = count1-1;
                tp = new_place();
                char* code1 = translate_Exp(dec->child->next->next, tp);
                char* code2 = malloc(64);
                sprintf(code2, "t%d := %s\n", id->t, tp);
                sprintf(code, "%s%s%s",code,code1,code2);
            }
            decList = decList->child->next->next;
        }
        node* dec = decList->child;
        if(dec->child->next == NULL){
            node* varDec = dec->child;
            if(strcasecmp(varDec->child->name, "vardec") == 0){
                while(strcasecmp(varDec->child->name, "vardec") == 0){
                    varDec = varDec->child;
                }
                Info* arr = symtab_lookup(root, varDec->child->attribute);
                int size = 0;
                if(arr->type->array->size_col == -1){
                    size = arr->type->array->size * 4;
                }
                else {
                    size = arr->type->array->size * arr->type->array->size_col * 4; 
                }
                char* tp = new_place();
                arr->t = count1 - 1;
                char* buff = malloc(1024);
                sprintf(code, "%sDEC %s %d\n", code, tp, size);
            }else{
                Info* val = symtab_lookup(root,varDec->child->attribute);
                char* tp = new_place();
                val->t = count1-1;
            }
        }else{
            Info* id = symtab_lookup(root, dec->child->child->attribute);
            char* tp = new_place();
            id->t = count1-1;
            tp = new_place();
            char* code1 = translate_Exp(dec->child->next->next, tp);
            char* code2 = malloc(64);
            sprintf(code2, "t%d := %s\n", id->t, tp);
            sprintf(code, "%s%s%s",code,code1,code2);
        }
        }
    else{
        return NULL;
    }
    return code;
}
char* translate_cond_Exp(node* Exp, char* lb1, char* lb2){
    if(strcasecmp(Exp->child->name, "LP")==0){
        //LP Exp RP
        return translate_cond_Exp(Exp->child->next,lb1,lb2);
    }
    if(strcasecmp(Exp->child->next->name, "AND") == 0){
        char* lb = new_label();
        char* code1 = translate_cond_Exp(Exp->child, lb, lb2);
        char* code2 = translate_cond_Exp(Exp->child->next->next, lb1, lb2);
        char* code3 = malloc(1024);
        sprintf(code3,"%sLABEL %s :\n%s",code1,lb,code2);
        return code3;
    }
    if(strcasecmp(Exp->child->next->name, "OR") == 0){
        char* lb = new_label();
        char* code1 = translate_cond_Exp(Exp->child, lb1, lb);
        char* code2 = translate_cond_Exp(Exp->child->next->next, lb1, lb2);
        char* code3 = malloc(1024);
        sprintf(code3,"%sLABEL %s :\n%s",code1,lb,code2);
        return code3;
    }
    if(strcasecmp(Exp->child->next->name, "LT") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s < %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "LE") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s <= %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "GT") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s > %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "GE") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s >= %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "EQ") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s == %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "NE") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s != %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->name, "NOT") == 0){
        return translate_cond_Exp(Exp->child->next,lb2,lb1);

    }
}

char* translate_stmt(node* stmt){
    if(strcasecmp(stmt->child->name, "Exp") == 0){
        char* tp = new_place();
        char* buff = malloc(1024);
        sprintf(buff,"%s",translate_Exp(stmt->child, tp));
        return buff;
    }
    if(strcasecmp(stmt->child->name, "Compst") == 0){
        char* code1 = malloc(1024);
        node* defList = stmt->child->child->next;
        while(defList->child != NULL){
            sprintf(code1,"%s%s", code1, translate_def(defList->child));
            defList = defList->child->next;
        }
        char* code2 = malloc(1024);
        node* stmtList = stmt->child->child->next->next;
        while(stmtList->child != NULL){
            sprintf(code2,"%s%s",code2,translate_stmt(stmtList->child));
            stmtList = stmtList->child->next;
        }
        sprintf(code2, "%s%s", code1, code2);
        return code2;
    }
    if(strcasecmp(stmt->child->name, "IF") == 0){
        if(stmt->child->next->next->next->next->next!=NULL){
        //IF LP Exp RP Stmt ELSE Stmt
            char* lb1 = new_label();
            char* lb2 = new_label();
            char* lb3 = new_label();
            char* code1 = translate_cond_Exp(stmt->child->next->next, lb1, lb2);
            char* code2 = translate_stmt(stmt->child->next->next->next->next);
            char* code3 = translate_stmt(stmt->child->next->next->next->next->next->next);
            char* code4 = malloc(1024);
            sprintf(code4,"%sLABEL %s :\n%sGOTO %s\nLABEL %s :\n%sLABEL %s :\n",code1,lb1,code2,lb3,lb2,code3,lb3);
            return code4;
        }
        else{
        //IF LP Exp RP Stmt
            char* lb1 = new_label();
            char* lb2 = new_label();
            char* code1 = translate_cond_Exp(stmt->child->next->next, lb1, lb2);
            char* code2 = translate_stmt(stmt->child->next->next->next->next);
            char* code3 = malloc(1024);
            sprintf(code3,"%sLABEL %s :\n%sLABEL %s :\n",code1,lb1,code2,lb2);
            return code3;
        }
        return NULL;  
    }
    if(strcasecmp(stmt->child->name, "WHILE") == 0){
        //WHILE LP Exp RP Stmt
        char* lb1 = new_label();
        char* lb2 = new_label();
        char* lb3 = new_label();
        char* code1 = translate_cond_Exp(stmt->child->next->next,lb2,lb3);
        char* code2 = translate_stmt(stmt->child->next->next->next->next);
        char* code3 = malloc(1024);
        sprintf(code3,"LABEL %s :\n%sLABEL %s :\n%sGOTO %s\nLABEL %s :\n",lb1,code1,lb2,code2,lb1,lb3);
        return code3;
    }
    if(strcasecmp(stmt->child->name, "RETURN") == 0){
        char* tp = new_place();
        char* buff = malloc(1024);
        sprintf(buff,"%sRETURN %s\n",translate_Exp(stmt->child->next, tp),tp);
        return buff;
    }
}

char* translate_Exp(node* Exp, char* place){
    if(strcasecmp(Exp->child->name, "LP")==0){
        //LP Exp RP
        return translate_Exp(Exp->child->next,place);
    }
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
        if(Exp->child->next == NULL){
            Info* id = symtab_lookup(root, Exp->child->attribute);
            char* buff = malloc(1024);
            if(id->t == -1){
                id->t = count1 - 1;  
            }sprintf(buff, "%s := t%d\n", place, id->t);
            return buff;
        }
        if(strcasecmp(Exp->child->next->next->name, "RP") == 0){
            Info* function = symtab_lookup(root, Exp->child->attribute);
            char* buff = malloc(32);
            sprintf(buff, "%s := CALL %s\n", place, Exp->child->attribute);
            return buff;
        }
        if(strcasecmp(Exp->child->next->next->name, "args") == 0){
            Info* function = symtab_lookup(root, Exp->child->attribute);
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


    if(strcasecmp(Exp->child->name, "int") == 0){
        char* buff = malloc(32);
        sprintf(buff, "%s := #%s\n", place, Exp->child->attribute);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "assign") == 0){
        if(strcasecmp(Exp->child->child->name,"ID")==0){
            Info* exp1 = symtab_lookup(root, Exp->child->child->attribute);
            char *buff = malloc(1024); //ID
            char* tp = new_place();
            char* code1 = translate_Exp(Exp->child->next->next, tp);
            char* code2 = malloc(64);
            sprintf(code2, "t%d := %s\n", exp1->t, tp);
            sprintf(buff, "%s%s",code1,code2);
            return buff;
        }
        if(strcasecmp(Exp->child->child->next->name,"LB")==0){
            char *buff = malloc(1024); 
            char* tp = new_place();
            char* code0 = translate_Exp(Exp->child, tp);
            char* tp1 = new_place();
            char* code1 = translate_Exp(Exp->child->next->next, tp1);
            char *code2 = malloc(1024); //ID
            sprintf(code2, "%s := %s\n", tp, tp1);
            sprintf(buff, "%s%s%s",code0,code1,code2);
            return buff;
            // return "null";
        }
    
    }
    if(strcasecmp(Exp->child->next->name, "plus") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s + %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "minus") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s - %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "mul") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s * %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "div") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s / %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->name, "minus") == 0){
        char *tp = new_place();
        char *code1 = translate_Exp(Exp->child->next, tp);
        char *code2 = malloc(64);
        sprintf(code2, "%s := #0 - %s\n", place, tp);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s", code1, code2);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "LB") == 0){
        char* code = malloc(1024);
        char* tp1 = new_place();
        char* code1 = translate_Exp(Exp->child->next->next, tp1);
        char* tp2 = new_place();
        sprintf(code, "%s%s := %s * #4\n",code1, tp2, tp1);
        char* tp3;
        char* code2 = malloc(1024);
        // while(strcasecmp(Exp->child->child->name, "ID") != 0){
        //     Exp = Exp->child;
        //     tp3 = new_place();
        //     code2 = translate_Exp(Exp->child->next->next, tp3);
        //     sprintf(code, "%s%s%s := %s * %s\n", code, code2, tp2, tp2, tp3);
        // }
        Info* arr = symtab_lookup(root, Exp->child->child->attribute);
        char* tp4 = new_place();
        sprintf(code, "%s%s := &t%d + %s\n", code, tp4, arr->t, tp2);
        sprintf(code, "%s%s := *%s\n", code, place, tp4);
        return code;
        // return "null";
    }
    return "NULL";
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
    char* buff = malloc(32);
    sprintf(buff,"label%d",count2);
    count2++;
    return buff;
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
