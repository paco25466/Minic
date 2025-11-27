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

#ifndef YY_YY_LEXICO_TAB_H_INCLUDED
# define YY_YY_LEXICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "lexico.y"

    #include "listaCodigo.h"
    #include "listaSimbolos.h"

#line 54 "lexico.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    READ = 258,                    /* READ  */
    VAR = 259,                     /* VAR  */
    CONST = 260,                   /* CONST  */
    INT = 261,                     /* INT  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    PRINT = 265,                   /* PRINT  */
    LPAREN = 266,                  /* LPAREN  */
    RPAREN = 267,                  /* RPAREN  */
    SEMICOLON = 268,               /* SEMICOLON  */
    COMMA = 269,                   /* COMMA  */
    ASSIGNOP = 270,                /* ASSIGNOP  */
    LCORCH = 271,                  /* LCORCH  */
    RCORCH = 272,                  /* RCORCH  */
    INTERR = 273,                  /* INTERR  */
    DOSPUNT = 274,                 /* DOSPUNT  */
    PLUSOP = 275,                  /* PLUSOP  */
    MINUSOP = 276,                 /* MINUSOP  */
    DIV = 277,                     /* DIV  */
    POR = 278,                     /* POR  */
    DO = 279,                      /* DO  */
    MENOR = 280,                   /* MENOR  */
    MAYOR = 281,                   /* MAYOR  */
    MENORIGUAL = 282,              /* MENORIGUAL  */
    MAYORIGUAL = 283,              /* MAYORIGUAL  */
    IGUAL = 284,                   /* IGUAL  */
    DISTINTO = 285,                /* DISTINTO  */
    NUM = 286,                     /* NUM  */
    ID = 287,                      /* ID  */
    STRING = 288,                  /* STRING  */
    UMINUS = 289                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 125 "lexico.y"

    ListaC lc; 
    char *c;

#line 110 "lexico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LEXICO_TAB_H_INCLUDED  */
