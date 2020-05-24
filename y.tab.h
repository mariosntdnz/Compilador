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
    TK_MAIN = 258,
    TK_ID = 259,
    TK_FIM = 260,
    TK_ERROR = 261,
    TK_NUM = 262,
    TK_VARNUM = 263,
    TK_FLOAT = 264,
    TK_VARFLOAT = 265,
    TK_VARBOOL = 266,
    TK_BOOL = 267,
    TK_VARCHAR = 268,
    TK_CHAR = 269,
    TK_FUNCNONE = 270,
    TK_ATTFUNC = 271,
    TK_RETURN = 272,
    TK_NONE = 273,
    TK_MAIOR_EQ = 274,
    TK_MENOR_EQ = 275,
    TK_IGUAL2 = 276,
    TK_DIFERENTE = 277,
    TK_AND = 278,
    TK_OR = 279,
    TK_NOT = 280,
    TK_EXP = 281,
    TK_OPCOMPOSTO = 282,
    TK_OPUNARIO = 283,
    TK_NOLOCAL = 284,
    TK_GLOBAL = 285,
    TK_ENDFUNC = 286,
    TK_FUNC = 287,
    TK_STRCAT = 288,
    TK_INITFUNC = 289,
    TK_SEPARA_PRINT = 290,
    TK_VARSTR = 291,
    TK_STRING = 292,
    TK_WHILE = 293,
    TK_FOR = 294,
    TK_STEP = 295,
    TK_IF = 296,
    TK_ELIF = 297,
    TK_ELSE = 298,
    TK_SWITCH = 299,
    TK_CASE = 300,
    TK_DEFAULT = 301,
    TK_INIT_BLOCO_DEC = 302,
    TK_END_BLOCO_DEC = 303,
    TK_DO = 304,
    TK_ENDLOOP = 305,
    TK_THEN = 306,
    TK_ENDIF = 307,
    TK_RANGE = 308,
    TK_BREAK = 309,
    TK_CONTINUE = 310,
    TK_READ = 311,
    TK_PRINT = 312,
    TK_DOWHILE = 313
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_ID 259
#define TK_FIM 260
#define TK_ERROR 261
#define TK_NUM 262
#define TK_VARNUM 263
#define TK_FLOAT 264
#define TK_VARFLOAT 265
#define TK_VARBOOL 266
#define TK_BOOL 267
#define TK_VARCHAR 268
#define TK_CHAR 269
#define TK_FUNCNONE 270
#define TK_ATTFUNC 271
#define TK_RETURN 272
#define TK_NONE 273
#define TK_MAIOR_EQ 274
#define TK_MENOR_EQ 275
#define TK_IGUAL2 276
#define TK_DIFERENTE 277
#define TK_AND 278
#define TK_OR 279
#define TK_NOT 280
#define TK_EXP 281
#define TK_OPCOMPOSTO 282
#define TK_OPUNARIO 283
#define TK_NOLOCAL 284
#define TK_GLOBAL 285
#define TK_ENDFUNC 286
#define TK_FUNC 287
#define TK_STRCAT 288
#define TK_INITFUNC 289
#define TK_SEPARA_PRINT 290
#define TK_VARSTR 291
#define TK_STRING 292
#define TK_WHILE 293
#define TK_FOR 294
#define TK_STEP 295
#define TK_IF 296
#define TK_ELIF 297
#define TK_ELSE 298
#define TK_SWITCH 299
#define TK_CASE 300
#define TK_DEFAULT 301
#define TK_INIT_BLOCO_DEC 302
#define TK_END_BLOCO_DEC 303
#define TK_DO 304
#define TK_ENDLOOP 305
#define TK_THEN 306
#define TK_ENDIF 307
#define TK_RANGE 308
#define TK_BREAK 309
#define TK_CONTINUE 310
#define TK_READ 311
#define TK_PRINT 312
#define TK_DOWHILE 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
