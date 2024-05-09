/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    PROGRAM = 258,
    ARRAY = 259,
    IF = 260,
    THEN = 261,
    ELSE = 262,
    CASE = 263,
    OF = 264,
    END = 265,
    ASSIGN = 266,
    _BEGIN = 267,
    WHILE = 268,
    DO = 269,
    REPEAT = 270,
    UNTIL = 271,
    FOR = 272,
    TO = 273,
    DOWNTO = 274,
    BREAK = 275,
    CONTINUE = 276,
    VAR = 277,
    LOGICALNOT = 278,
    NEWLINE = 279,
    WITH = 280,
    WRITE = 281,
    WRITELN = 282,
    READ = 283,
    FLOAT = 284,
    INT = 285,
    STRING = 286,
    ID = 287,
    RELATIONAL_OP = 288,
    ADD_OP = 289,
    MUL_OP = 290,
    TYPE = 291,
    BUILTIN_FUNCTION = 292,
    COMMENT = 293
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ARRAY 259
#define IF 260
#define THEN 261
#define ELSE 262
#define CASE 263
#define OF 264
#define END 265
#define ASSIGN 266
#define _BEGIN 267
#define WHILE 268
#define DO 269
#define REPEAT 270
#define UNTIL 271
#define FOR 272
#define TO 273
#define DOWNTO 274
#define BREAK 275
#define CONTINUE 276
#define VAR 277
#define LOGICALNOT 278
#define NEWLINE 279
#define WITH 280
#define WRITE 281
#define WRITELN 282
#define READ 283
#define FLOAT 284
#define INT 285
#define STRING 286
#define ID 287
#define RELATIONAL_OP 288
#define ADD_OP 289
#define MUL_OP 290
#define TYPE 291
#define BUILTIN_FUNCTION 292
#define COMMENT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "B103040012.y"

    int 	intVal;
    char    charVal;
    float 	floatVal;
    char*   stringVal;

#line 140 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
