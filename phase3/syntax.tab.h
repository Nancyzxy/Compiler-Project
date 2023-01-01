/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    CHAR = 260,                    /* CHAR  */
    ID = 261,                      /* ID  */
    TYPE = 262,                    /* TYPE  */
    INCLUSION = 263,               /* INCLUSION  */
    DEFINE = 264,                  /* DEFINE  */
    STRUCT = 265,                  /* STRUCT  */
    IF = 266,                      /* IF  */
    WHILE = 267,                   /* WHILE  */
    RETURN = 268,                  /* RETURN  */
    SEMI = 269,                    /* SEMI  */
    COMMA = 270,                   /* COMMA  */
    FOR = 271,                     /* FOR  */
    READ = 272,                    /* READ  */
    WRITE = 273,                   /* WRITE  */
    LOWER_ELSE = 274,              /* LOWER_ELSE  */
    ELSE = 275,                    /* ELSE  */
    ASSIGN = 276,                  /* ASSIGN  */
    OR = 277,                      /* OR  */
    AND = 278,                     /* AND  */
    NE = 279,                      /* NE  */
    EQ = 280,                      /* EQ  */
    LT = 281,                      /* LT  */
    LE = 282,                      /* LE  */
    GT = 283,                      /* GT  */
    GE = 284,                      /* GE  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    MUL = 287,                     /* MUL  */
    DIV = 288,                     /* DIV  */
    NOT = 289,                     /* NOT  */
    LP = 290,                      /* LP  */
    RP = 291,                      /* RP  */
    LB = 292,                      /* LB  */
    RB = 293,                      /* RB  */
    LC = 294,                      /* LC  */
    RC = 295,                      /* RC  */
    DOT = 296,                     /* DOT  */
    FAULT = 297                    /* FAULT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "syntax.y"

    node* treeNode;
    int int_value;
    float float_value;
    char* string_value;

#line 113 "syntax.tab.h"

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
