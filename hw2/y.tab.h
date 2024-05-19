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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    PROGRAM = 258,                 /* PROGRAM  */
    FUNCTION = 259,                /* FUNCTION  */
    PROCEDURE = 260,               /* PROCEDURE  */
    ARRAY = 261,                   /* ARRAY  */
    IF = 262,                      /* IF  */
    THEN = 263,                    /* THEN  */
    ELSE = 264,                    /* ELSE  */
    CASE = 265,                    /* CASE  */
    OF = 266,                      /* OF  */
    END = 267,                     /* END  */
    ASSIGN = 268,                  /* ASSIGN  */
    _BEGIN = 269,                  /* _BEGIN  */
    WHILE = 270,                   /* WHILE  */
    DO = 271,                      /* DO  */
    REPEAT = 272,                  /* REPEAT  */
    UNTIL = 273,                   /* UNTIL  */
    FOR = 274,                     /* FOR  */
    TO = 275,                      /* TO  */
    DOWNTO = 276,                  /* DOWNTO  */
    BREAK = 277,                   /* BREAK  */
    CONTINUE = 278,                /* CONTINUE  */
    VAR = 279,                     /* VAR  */
    LOGICALNOT = 280,              /* LOGICALNOT  */
    NEWLINE = 281,                 /* NEWLINE  */
    WITH = 282,                    /* WITH  */
    WRITE = 283,                   /* WRITE  */
    WRITELN = 284,                 /* WRITELN  */
    READ = 285,                    /* READ  */
    FLOAT = 286,                   /* FLOAT  */
    INT = 287,                     /* INT  */
    STRING = 288,                  /* STRING  */
    ID = 289,                      /* ID  */
    RELATIONAL_OP = 290,           /* RELATIONAL_OP  */
    ADD_OP = 291,                  /* ADD_OP  */
    MUL_OP = 292,                  /* MUL_OP  */
    TYPE = 293,                    /* TYPE  */
    BUILTIN_FUNCTION = 294,        /* BUILTIN_FUNCTION  */
    COMMENT = 295,                 /* COMMENT  */
    END_OF_FILE = 296              /* END_OF_FILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PROGRAM 258
#define FUNCTION 259
#define PROCEDURE 260
#define ARRAY 261
#define IF 262
#define THEN 263
#define ELSE 264
#define CASE 265
#define OF 266
#define END 267
#define ASSIGN 268
#define _BEGIN 269
#define WHILE 270
#define DO 271
#define REPEAT 272
#define UNTIL 273
#define FOR 274
#define TO 275
#define DOWNTO 276
#define BREAK 277
#define CONTINUE 278
#define VAR 279
#define LOGICALNOT 280
#define NEWLINE 281
#define WITH 282
#define WRITE 283
#define WRITELN 284
#define READ 285
#define FLOAT 286
#define INT 287
#define STRING 288
#define ID 289
#define RELATIONAL_OP 290
#define ADD_OP 291
#define MUL_OP 292
#define TYPE 293
#define BUILTIN_FUNCTION 294
#define COMMENT 295
#define END_OF_FILE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "B103040012.y"

    int 	intVal;
    char    charVal;
    float 	floatVal;
    char*   stringVal;

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
