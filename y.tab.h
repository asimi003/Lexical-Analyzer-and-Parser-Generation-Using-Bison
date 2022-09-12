/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 28 "miniL.y" /* yacc.c:1909  */

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

#line 119 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
