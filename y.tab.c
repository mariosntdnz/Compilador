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
#line 1 "sintatica.y" /* yacc.c:339  */

#include <iostream>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <map>
#include <vector>

#define YYSTYPE atributos
#define bool_true  1
#define bool_false 0	
#define empilha_loop      pilha_loop.push_back(++contLoopLabel);++controle_loop
#define desempilha_loop   pilha_loop.pop_back();
#define empilha_escopo    map<string,Att_Var> Tab_simbol;pilha_escopo.push_back(Tab_simbol);maxEscopo++;numEscopo++
#define desempilha_escopo pilha_escopo.pop_back();numEscopo--
#define ARITMETICA_CONV 	 1
#define RELACIONAL_CONV 	 2
#define RELACIONAL_CONV_COMP 3
#define LOGICA_CONV 		 4
#define MAX_BUFFER			 1500 
#define	GLOBAL  			 0
using namespace std;

struct atributos
{
	string label;
	string nome;
	string traducao;
	string tipo;
	string label_size_str;
	string label_size_str_realloc;
	string label_len;
};

struct att_variavel
{
	int declarada = 0;
	int valor_att = 0;
	string tipo = "";
	int tam_str = 0;
	int str_init = 0;
	string label = "";
	string nome = "";
};
typedef struct att_variavel Att_Var;

struct att_func
{
	string nome;
	string label;
	int escopo = -2;
	string tipo;
	vector<string> tipo_params;
	vector<string> vars_params;
	string label_return = "";
};
typedef struct att_func Att_Func;
//map<string,Att_Var> Tabela_simbol;
map<string,string> Tabela_temps;
vector<map<string,Att_Var>> pilha_escopo;
map<string,Att_Func> funcs_info; 
map<string,string> declaraVars;
vector<int>	      pilha_loop;	
string FUNCS = ""; 
int contforNAOuser = 0;
int contLabel = 0, ErroDeCompila = 0, LinhaAtual = 1, contif = 0,contLoopLabel = -1;
int numLoop = 0,numEscopo = -1,att_ou_declara = 1,maxEscopo = -1,controle_loop = -1;
string declaraAtual;

int yylex(void);
void yyerror(string);
string declaraVariaveis(void);
string initID(string id);
struct atributos initExpressao(struct atributos,struct atributos,string, int);
Att_Var find_tabela(vector<map<string,Att_Var>>);
string getVar(string label, int escopo);
int getLenFromLabel(string);
//int getEscopo(string var);
string genLabel(void);
string getVar(string label, int escopo);
string getVarFromLabel(string nome);
string tipoImplicito(struct atributos, struct atributos, int);
string tipoImplicitoAritmetica(struct atributos $1, struct atributos $2);
string tipoImplicitoRelacional(struct atributos $1, struct atributos $2,int tipo_conv);
int getEscopo(string label);
string tipoImplicitoLogico(struct atributos $1, struct atributos $2);
int isNumeric(string tipo);


#line 160 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 327 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

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
      65,    66,    63,    61,    68,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
      59,    69,    60,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   120,   128,   133,   138,   143,   147,   151,
     155,   159,   163,   167,   171,   175,   179,   183,   189,   206,
     224,   231,   238,   266,   294,   308,   321,   325,   329,   334,
     338,   346,   350,   355,   358,   362,   366,   371,   374,   387,
     400,   464,   469,   492,   497,   502,   507,   512,   517,   522,
     529,   568,   677,   710,   738,   764,   770,   772,   780,   815,
     827,   831,   843,   890,   894,   900,   906,   912,   918,   922,
     926,   930,   934,   983,   990,   994,   998,  1004,  1008,  1012,
    1016,  1020,  1024,  1028,  1035,  1045,  1052,  1058,  1064,  1070,
    1076,  1098,  1110,  1131,  1145
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_ID", "TK_FIM", "TK_ERROR",
  "TK_NUM", "TK_VARNUM", "TK_FLOAT", "TK_VARFLOAT", "TK_VARBOOL",
  "TK_BOOL", "TK_VARCHAR", "TK_CHAR", "TK_FUNCNONE", "TK_ATTFUNC",
  "TK_RETURN", "TK_NONE", "TK_MAIOR_EQ", "TK_MENOR_EQ", "TK_IGUAL2",
  "TK_DIFERENTE", "TK_AND", "TK_OR", "TK_NOT", "TK_EXP", "TK_OPCOMPOSTO",
  "TK_OPUNARIO", "TK_NOLOCAL", "TK_GLOBAL", "TK_ENDFUNC", "TK_FUNC",
  "TK_STRCAT", "TK_INITFUNC", "TK_SEPARA_PRINT", "TK_VARSTR", "TK_STRING",
  "TK_WHILE", "TK_FOR", "TK_STEP", "TK_IF", "TK_ELIF", "TK_ELSE",
  "TK_SWITCH", "TK_CASE", "TK_DEFAULT", "TK_INIT_BLOCO_DEC",
  "TK_END_BLOCO_DEC", "TK_DO", "TK_ENDLOOP", "TK_THEN", "TK_ENDIF",
  "TK_RANGE", "TK_BREAK", "TK_CONTINUE", "TK_READ", "TK_PRINT",
  "TK_DOWHILE", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "';'", "','", "'='", "$accept", "S", "AUXSTART", "COMANDOS", "COMANDO",
  "BREAK", "CONTINUE", "IF", "FOR", "DECLARATEMPFOR", "FORARG1S",
  "FORARG1", "FORARG2S", "FORARG2", "FORARG3S", "FORARG3", "WHILE",
  "DOWHILE", "DECLARACAO", "MULT_ID", "VARTIPO", "ATRIBUICAO", "CHAMAFUNC",
  "ARGES", "ARGE", "DECLARAFUNC", "ARGSFUNCS", "ARGFUNC", "CONCAT",
  "PRINT", "ARGPRINTS", "ARGPRINT", "E", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    60,
      62,    43,    45,    42,    47,    40,    41,    59,    44,    61
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
     -59,    10,   266,   -59,   -23,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   338,    16,    24,   131,   -35,
     -59,   -59,   338,    -3,   338,   -31,   -30,   -29,   338,   338,
     -59,   266,   -28,   -24,   -59,   -59,   -59,   -59,   -22,    -1,
     -17,   -59,   -59,   -59,   -59,   367,   338,   -59,   338,   304,
     -27,   -12,   102,    -7,   -59,    33,    37,   449,   -59,    11,
      49,   463,    52,    53,   338,   509,   385,   -59,   -59,   -59,
     -59,   -25,   338,    -5,   -59,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   -59,   517,
       0,   226,    -4,   517,    58,     8,     4,   266,   -21,    26,
       6,   -59,    72,   -59,    41,   266,    30,    31,   -58,    32,
     517,   266,   -59,   338,   433,    72,     7,     7,     7,     7,
     102,   525,   -59,     7,     7,    -9,    -9,    51,    51,   -59,
     338,   -59,    35,    36,   131,   338,    48,   338,    11,    92,
     -41,   -59,   -59,    38,    69,   338,    57,   517,   -59,    -5,
     204,   -59,   -59,    94,    42,   357,   -59,    44,    45,   517,
     -59,   -26,   266,   -59,   -59,    43,   -59,   -59,   -59,   111,
      83,   338,   114,   338,   112,   266,    74,   113,    61,   266,
     441,    64,    63,   -59,   -59,    85,    87,   -59,    77,   131,
     -59,   118,    78,   100,   114,   266,   -59,    84,   134,   338,
     -59,   266,   -59,   104,   -59,   148,   376,   105,   -59,   131,
     125,   -59,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     5,     1,    94,    86,    44,    87,    45,    47,
      88,    46,    89,    49,    85,     0,     0,     0,     0,     0,
      48,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     5,     0,     0,    10,    11,    12,    13,     0,     0,
       0,    84,     9,    17,    16,     0,     0,    53,    56,     0,
      94,     0,    76,    93,    91,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    14,    15,
       8,    43,     0,    40,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    52,
       0,     0,     0,    50,     0,     0,     0,     5,     0,     0,
      27,    28,     0,    29,     0,     5,     0,     0,     0,    66,
      67,     5,    73,     0,     0,     0,    79,    80,    81,    82,
      74,    75,    72,    77,    78,    68,    69,    70,    71,    54,
       0,    55,     0,     0,    60,     0,     0,    33,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    42,    83,    41,
      56,    51,    92,     0,     0,     0,    38,     0,    31,    32,
      26,     0,     5,    20,    63,     0,    65,    39,    57,     0,
       0,     0,    37,    33,     0,     5,     0,     0,     0,     5,
       0,     0,    35,    36,    30,     0,     0,    21,     0,     0,
      59,     0,     0,     0,    37,     5,    22,     0,     0,     0,
      62,     5,    34,     0,    64,     0,     0,     0,    23,    60,
       0,    24,    61,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,     9,   -59,   -59,   -59,   -59,   -59,   -59,
      19,   -59,   -15,   -59,   -19,   -59,   -59,   -59,   -46,    54,
      -2,   -47,   -59,    18,   -59,   -59,   -50,   -59,   -59,   -59,
      25,   -59,     3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    30,    31,    32,    33,    34,    35,    60,
      99,   100,   157,   158,   181,   182,    36,    37,    38,    73,
      51,    40,    41,    90,   131,    42,   154,   190,    43,    44,
     108,   109,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    58,   162,    71,    46,    47,    46,    47,   143,   144,
       3,   163,   103,   101,   174,    98,    55,    81,    52,     6,
      53,     8,     9,   175,    11,    57,    13,    61,    54,    39,
      56,    65,    66,    81,    62,    63,    64,    95,    48,    68,
      67,    96,    48,    69,   113,    70,    49,    20,    49,    89,
      74,    91,    93,    72,    86,    87,   104,   102,    94,   106,
     107,   132,    59,   115,    72,   133,   129,   110,    84,    85,
      86,    87,   135,   134,   138,   114,    71,    81,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   103,   101,   137,   139,    39,   141,   142,   156,   161,
     145,   151,   152,    39,   165,   164,   136,   167,   170,    39,
     169,   172,   177,   173,   140,   178,   147,   179,    98,   185,
     146,    75,    76,    77,    78,   183,   187,   188,    81,   189,
     193,   194,   153,   150,   195,   199,   102,   196,   155,     6,
     159,     8,     9,   197,    11,   200,    13,   183,   110,   201,
     205,   204,   209,    91,   208,   211,   213,   160,   184,   212,
      39,    82,    83,    84,    85,    86,    87,    20,   168,   149,
     166,   176,     0,    39,   180,   202,   159,    39,     0,     0,
       0,     0,     0,     0,   186,     0,     0,   198,   191,     0,
       0,     0,     0,    39,     0,     0,     0,     0,     0,    39,
       0,     0,   206,     0,   203,     0,     0,   153,    50,     0,
     207,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    75,    76,    77,    78,    79,    80,    15,
      81,     0,     0,    16,    17,     0,     0,     0,     0,     0,
      20,    21,     0,     0,     0,    75,    76,    77,    78,    79,
      80,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    29,
       4,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    82,    83,    84,    85,    86,
      87,    15,     0,     0,   130,    16,    17,     0,    18,    19,
       0,     0,    20,    21,    22,    23,     0,    24,    50,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      25,    26,    14,    27,    28,     0,     0,     0,     0,    15,
       0,    29,     0,    16,    17,     0,     0,     0,     0,     0,
      20,    21,    50,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,    14,     0,     0,     0,
      92,     0,     0,    15,     0,     0,     0,    16,    17,    29,
       0,     0,     0,     0,    20,    21,    75,    76,    77,    78,
      79,    80,     0,    81,     0,     0,    75,    76,    77,    78,
      79,    80,     0,    81,     0,    75,    76,    77,    78,    79,
      80,     0,    81,    29,    75,    76,    77,    78,    79,    80,
       0,    81,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,     0,     0,     0,   171,    82,    83,    84,    85,
      86,    87,     0,     0,    88,    82,    83,    84,    85,    86,
      87,     0,     0,   210,    82,    83,    84,    85,    86,    87,
       0,   112,    75,    76,    77,    78,    79,    80,     0,    81,
      75,    76,    77,    78,    79,    80,     0,    81,    75,    76,
      77,    78,    79,    80,     0,    81,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,     0,    81,
       0,     0,    82,    83,    84,    85,    86,    87,    97,   148,
      82,    83,    84,    85,    86,    87,     0,   192,    82,    83,
      84,    85,    86,    87,   105,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    75,    76,
      77,    78,    79,    80,     0,    81,    75,    76,    77,    78,
      79,    80,     0,    81,    75,    76,    77,    78,    79,     0,
       0,    81,     0,     0,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,     0,     0,    82,    83,    84,    85,
      86,    87,     0,     0,    82,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
       2,     4,    43,     4,    27,    28,    27,    28,    66,    67,
       0,    52,    59,    59,    40,     4,    18,    26,    15,     8,
       4,    10,    11,    49,    13,    22,    15,    24,     4,    31,
      65,    28,    29,    26,    65,    65,    65,     4,    65,    67,
      31,     4,    65,    67,    69,    67,    69,    36,    69,    46,
      67,    48,    49,    65,    63,    64,     7,    59,    65,     7,
       7,    65,    65,    68,    65,     7,    66,    64,    61,    62,
      63,    64,    68,    65,    68,    72,     4,    26,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   138,   138,    67,    53,    97,    66,    66,    50,     7,
      68,    66,    66,   105,    35,    67,    97,    50,    66,   111,
      16,    67,    69,    68,   105,     4,   113,    34,     4,     7,
     111,    19,    20,    21,    22,   172,    52,    14,    26,    68,
      66,    68,   134,   130,    49,    17,   138,    50,   135,     8,
     137,    10,    11,    66,    13,    67,    15,   194,   145,    49,
      16,    67,     4,   150,    50,    50,    31,   138,   173,   209,
     162,    59,    60,    61,    62,    63,    64,    36,   150,   115,
     145,   162,    -1,   175,   171,   194,   173,   179,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,    -1,   189,   179,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   201,
      -1,    -1,   199,    -1,   195,    -1,    -1,   209,     4,    -1,
     201,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
       4,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    59,    60,    61,    62,    63,
      64,    25,    -1,    -1,    68,    29,    30,    -1,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    41,     4,    -1,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      54,    55,    18,    57,    58,    -1,    -1,    -1,    -1,    25,
      -1,    65,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      36,    37,     4,    -1,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      56,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    65,
      -1,    -1,    -1,    -1,    36,    37,    19,    20,    21,    22,
      23,    24,    -1,    26,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    65,    19,    20,    21,    22,    23,    24,
      -1,    26,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    59,    60,    61,    62,
      63,    64,    -1,    -1,    67,    59,    60,    61,    62,    63,
      64,    -1,    -1,    67,    59,    60,    61,    62,    63,    64,
      -1,    66,    19,    20,    21,    22,    23,    24,    -1,    26,
      19,    20,    21,    22,    23,    24,    -1,    26,    19,    20,
      21,    22,    23,    24,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      -1,    -1,    59,    60,    61,    62,    63,    64,    49,    66,
      59,    60,    61,    62,    63,    64,    -1,    66,    59,    60,
      61,    62,    63,    64,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    19,    20,
      21,    22,    23,    24,    -1,    26,    19,    20,    21,    22,
      23,    24,    -1,    26,    19,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    -1,    59,    60,    61,    62,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    72,     0,     4,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    18,    25,    29,    30,    32,    33,
      36,    37,    38,    39,    41,    54,    55,    57,    58,    65,
      73,    74,    75,    76,    77,    78,    86,    87,    88,    90,
      91,    92,    95,    98,    99,   102,    27,    28,    65,    69,
       4,    90,   102,     4,     4,    90,    65,   102,     4,    65,
      79,   102,    65,    65,    65,   102,   102,    73,    67,    67,
      67,     4,    65,    89,    67,    19,    20,    21,    22,    23,
      24,    26,    59,    60,    61,    62,    63,    64,    67,   102,
      93,   102,    56,   102,    65,     4,     4,    49,     4,    80,
      81,    88,    90,    91,     7,    51,     7,     7,   100,   101,
     102,    49,    66,    69,   102,    68,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,    66,
      68,    94,    65,     7,    65,    68,    73,    67,    68,    53,
      73,    66,    66,    66,    67,    68,    73,   102,    66,    89,
     102,    66,    66,    90,    96,   102,    50,    82,    83,   102,
      80,     7,    43,    52,    67,    35,   100,    50,    93,    16,
      66,    68,    67,    68,    40,    49,    73,    69,     4,    34,
     102,    84,    85,    91,    82,     7,    73,    52,    14,    68,
      97,    73,    66,    66,    68,    49,    50,    66,    90,    17,
      67,    49,    84,    73,    67,    16,   102,    73,    50,     4,
      67,    50,    96,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      77,    77,    78,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    87,
      88,    89,    89,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    92,    93,    93,    94,    95,    96,
      96,    97,    98,    99,    99,   100,   100,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     4,     4,
       5,     7,     8,    10,    11,     1,     3,     1,     1,     1,
       3,     1,     1,     0,     3,     1,     1,     0,     5,     5,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     3,     2,     4,     2,     0,     3,    12,     4,
       0,     5,     9,     5,     9,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     2,     1
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
#line 115 "sintatica.y" /* yacc.c:1646  */
    {
				if(ErroDeCompila) exit(0);
				cout << "/*Compilador MEC*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n#include<math.h>\n#define True 1\n#define False 0\n#define NONE 0\n#define MAXSTR 1500\n" << declaraVariaveis() << FUNCS << "int main(void)\n{\n" << (yyvsp[0]).traducao << "\treturn 0;\n}" << endl; 
			}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 120 "sintatica.y" /* yacc.c:1646  */
    {empilha_escopo;}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;

			}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 144 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 152 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 168 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 176 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 180 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 190 "sintatica.y" /* yacc.c:1646  */
    {
				int loop = 0,num = atoi((yyvsp[-1]).traducao.c_str());

				if(controle_loop == -1)     yyerror("Não há loop para ser quebrado");

				if(num - 1 > controle_loop  && controle_loop > -1)yyerror("Você tentou quebrar mais loops do que existem");
				else if(num == 0)								  yyerror("Impossivel quebrar 0 loops, tente um numero valido");
				else if(num < 0)								  loop = 1;

				loop = loop == 1 ? 0:num - controle_loop + 1;

				(yyval).traducao = "\tgoto fimloop" + 
				std::to_string(pilha_loop[loop]) + ";\n";

			}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 207 "sintatica.y" /* yacc.c:1646  */
    {
				int loop = 0,num = atoi((yyvsp[-1]).traducao.c_str());

				if(controle_loop == -1)     					  yyerror("Não há loop para ser pulado");

				if(num - 1 > controle_loop && controle_loop > -1) yyerror("Você tentou pular mais loops do que existem");
				else if(num == 0)								  yyerror("Impossivel pular 0 loops, tente um numero valido");
				else if(num < 0)								  loop = 1;

				loop = loop == 1 ? 0:num - controle_loop + 1;

				(yyval).traducao = "\tgoto labelcontinue" + 
				std::to_string(pilha_loop[loop]) + ";\n";

			}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 225 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-3]).traducao + "\t" + (yyvsp[-3]).label + "=" + "!" + (yyvsp[-3]).label + 
				      ";\n\t" + "if(" + (yyvsp[-3]).label + ") goto fimif" + std::to_string(contif) +";"+
				      "\n" + (yyvsp[-1]).traducao + "\n\t fimif" + std::to_string(contif) + ":\n";      
		   	contif++;
		   }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 232 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-5]).traducao + "\t" + (yyvsp[-5]).label + "=" + "!" + (yyvsp[-5]).label + 
				      "\n\t" + "if(" + (yyvsp[-5]).label + ") goto else" + std::to_string(contif) +";"+
				      "\n" + (yyvsp[-3]).traducao +"\t"+"goto fimif"+ std::to_string(contif) + ";\n\t" +"else"+std::to_string(contif) +":\n"+ (yyvsp[-1]).traducao + "\tfimif" + std::to_string(contif) + ":\n"; 
		   	contif++;
		   }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 239 "sintatica.y" /* yacc.c:1646  */
    {

			string operador = (atoi((yyvsp[-5]).traducao.c_str()) < atoi((yyvsp[-3]).traducao.c_str())) ?  "<":">";
			string operador2 = (atoi((yyvsp[-5]).traducao.c_str()) < atoi((yyvsp[-3]).traducao.c_str())) ?  "+":"-";
			string label1 = genLabel();
			string label2 = genLabel();
			string label3 = genLabel();
			string label4 = genLabel();
			Tabela_temps[label1] = "int" ; 
			Tabela_temps[label2] = "int" ; 
			Tabela_temps[label3] = "int" ; 
			Tabela_temps[label4] = "int" ;
			 
			(yyval).traducao = "\n\t" + label1 + "=" + (yyvsp[-5]).traducao +";\n\t" + 
					       label2 + "=" + (yyvsp[-3]).traducao + ";\n\t" + 
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
						label3 + "=" + "!" + label3 + ";\n\t" +
						(yyvsp[-6]).traducao + "=" + (yyvsp[-5]).traducao + ";\n\t" +
					 "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " +
					  "if(" + label3 + ") goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n"+
					   (yyvsp[-1]).traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
					   + "\t" + (yyvsp[-6]).traducao + "=" + (yyvsp[-6]).traducao + operador2 + "1;\n\t" +
					   		label1 + "=" + (yyvsp[-6]).traducao + ";\n\t" +
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
					label3 + "=" + "!" + label3 + ";\n\tgoto iniloop" + std::to_string(pilha_loop[controle_loop])+					+ ";\n\tfimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n";	
			--controle_loop;
		}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 267 "sintatica.y" /* yacc.c:1646  */
    {
			string operador = (atoi((yyvsp[-7]).traducao.c_str()) < atoi((yyvsp[-5]).traducao.c_str())) ?  "<":">";
			string operador2 = (atoi((yyvsp[-3]).traducao.c_str()) > 0) ?  "+":"";
			string label1 = genLabel();
			string label2 = genLabel();
			string label3 = genLabel();
			string label4 = genLabel();
			Tabela_temps[label1] = "int" ; 
			Tabela_temps[label2] = "int" ; 
			Tabela_temps[label3] = "int" ; 
			Tabela_temps[label4] = "int" ;
			 
			(yyval).traducao = "\n\t" + label1 + "=" + (yyvsp[-7]).traducao +";\n\t" + 
					       label2 + "=" + (yyvsp[-5]).traducao + ";\n\t" + 
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
						label3 + "=" + "!" + label3 + ";\n\t" +
						(yyvsp[-8]).traducao + "=" + (yyvsp[-7]).traducao + ";\n\t" +
					 "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " +
				 "if(" + label3 + ") goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n"+ 
			(yyvsp[-1]).traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" 
			+ "\t" + (yyvsp[-8]).traducao + "=" + (yyvsp[-8]).traducao + operador2 + (yyvsp[-3]).traducao +";\n\t" +
							label1 + "=" + (yyvsp[-8]).traducao + ";\n\t"+
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
					label3 + "=" + "!" + label3 + ";\n\tgoto iniloop" + std::to_string(pilha_loop[controle_loop])+					";\n\tfimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n";	
			
			--controle_loop;
		}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 295 "sintatica.y" /* yacc.c:1646  */
    {
			string label1 = genLabel();
			Tabela_temps[label1] = "int" ; 
			(yyval).traducao = (yyvsp[-8]).traducao + (yyvsp[-6]).traducao + "\t" + label1 + "= !" + (yyvsp[-6]).label + ";\n\t" + "iniloop" 				  + std::to_string(pilha_loop[controle_loop]) + ":" + 
				     + "if(" + label1 + ") goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n"
				     + (yyvsp[-1]).traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
				     (yyvsp[-4]).traducao +  (yyvsp[-6]).traducao + "\t" +label1 + "= !" + (yyvsp[-6]).label + ";\n\t"	
					+ "goto iniloop" + std::to_string(pilha_loop[controle_loop]) + 
					";\n\t" + "fimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n";
			--controle_loop;
		}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 309 "sintatica.y" /* yacc.c:1646  */
    {
					pilha_escopo[numEscopo][(yyvsp[0]).nome].tipo = "int";
					pilha_escopo[numEscopo][(yyvsp[0]).nome].declarada = 1;
					pilha_escopo[numEscopo][(yyvsp[0]).nome].valor_att = 1;
					pilha_escopo[numEscopo][(yyvsp[0]).nome].nome = (yyvsp[0]).nome;
					pilha_escopo[numEscopo][(yyvsp[0]).nome].label = genLabel();

					(yyval).traducao = pilha_escopo[numEscopo][(yyvsp[0]).nome].label;

					declaraVars[pilha_escopo[numEscopo][(yyvsp[0]).nome].label] = pilha_escopo[numEscopo][(yyvsp[0]).nome].tipo;
				}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 322 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
		}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;	
		}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 330 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;
		}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 335 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;
		}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 339 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).label    = genLabel();
			Tabela_temps[(yyval).label] = "bool"; 
			(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\t" + 
			(yyval).label + " = " + (yyvsp[-2]).label + " " + "&&" + " " + (yyvsp[0]).label + ";\n";
			
		}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 347 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;	
		}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 351 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;
		}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 355 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = "";
		}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 359 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[-1]).traducao;
		}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 363 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;	
		}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 367 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = (yyvsp[0]).traducao;
		}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 371 "sintatica.y" /* yacc.c:1646  */
    {
			(yyval).traducao = "";
		}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 375 "sintatica.y" /* yacc.c:1646  */
    {
			string label1 = genLabel();
			Tabela_temps[label1] = "bool";
			
			(yyval).traducao = (yyvsp[-3]).traducao + "\t" + label1 + "= !" + (yyvsp[-3]).label + ";\n\t" +
						  "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " + "if(" + label1 + ")" + "goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t"+
						  (yyvsp[-1]).traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
						  (yyvsp[-3]).traducao + "\t" + label1 + "= !" + (yyvsp[-3]).label + ";\n\t" + "goto iniloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t" +
						  "fimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n" ;
			--controle_loop;
		}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 388 "sintatica.y" /* yacc.c:1646  */
    {
			string label1 = genLabel();
			Tabela_temps[label1] = "bool";

			(yyval).traducao = label1 + "= 0" + ";\n\t" +
						  "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " + "if(" + label1 + ")" + "goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t"+
						  (yyvsp[-1]).traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
						  (yyvsp[-3]).traducao + "\t" + label1 + "= !" + (yyvsp[-3]).label + ";\n\t" + "goto iniloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t" +
						  "fimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n" ;
			--controle_loop;
		}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 401 "sintatica.y" /* yacc.c:1646  */
    {
				string aux = (yyvsp[0]).traducao,var,translate = "";
				vector<string> vars,aux2;
				replace(aux.begin(),aux.end(),';',',');
				aux.erase(remove(aux.begin(),aux.end(),' '),aux.end());
				aux.erase(remove(aux.begin(),aux.end(),'\t'),aux.end());
				aux.erase(remove(aux.begin(),aux.end(),'\n'),aux.end());
				boost::split(vars,aux,boost::is_any_of(","));
				for(int i = 0; i < vars.size(); i++){

					if(strchr(vars[i].c_str(),'=')){
						//continue;
						boost::split(aux2,vars[i],boost::is_any_of("="));
						var = getVar(aux2[0],numEscopo);
						
						//if(var.empty()) continue;
						if((yyvsp[-1]).tipo != pilha_escopo[numEscopo][var].tipo && !var.empty()){
							if(isNumeric((yyvsp[-1]).tipo) && isNumeric(pilha_escopo[numEscopo][var].tipo))
								translate += "\t" + aux2[0] + "=" + "(" + (yyvsp[-1]).tipo + ")" + aux2[1] + ";\n";
							else
								yyerror("Tipo diferente da declaração e cast não permitido ");
						}

						translate += "\t" + vars[i] + ";\n";
					}
					else{
						string aux_str = var;
						var = vars[i];
						//var = getVar(vars[i],numEscopo);
						//cout << "vaaaar  " + vars[i] + std::to_string(numEscopo) + "\n"; 
						if((yyvsp[-1]).tipo == "string"){
							if(!strncmp(vars[i].c_str(),"strcpy(",7)){
								vars[i] = vars[i] + " , " + vars[i+1];
								translate += "\t" + vars[i] + ";\n";
								i++;
								continue;
							}
						}
						
					}
					if(var.empty()) continue;

					/*if(pilha_escopo[numEscopo][var].tipo != $1.tipo && pilha_escopo[numEscopo][var].tipo != ""){
						yyerror("Tipo da declaração da variavel " + var + " diferente do tipo atribuido ");
					}	*/

					pilha_escopo[numEscopo][var].tipo = (yyvsp[-1]).tipo;

					if(pilha_escopo[numEscopo][var].declarada){
							yyerror("Variavel '" + var + "' já declarada");
					}
					else{
							pilha_escopo[numEscopo][var].nome = var;
							if(pilha_escopo[numEscopo][var].label == "") {
								pilha_escopo[numEscopo][var].label = genLabel();
							}
							pilha_escopo[numEscopo][var].declarada = 1;
							declaraVars[pilha_escopo[numEscopo][var].label] = pilha_escopo[numEscopo][var].tipo = (yyvsp[-1]).tipo;
					}
				}
				(yyval).traducao = translate;
			}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 465 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + "," + (yyvsp[0]).traducao;
			}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 470 "sintatica.y" /* yacc.c:1646  */
    {
				string cast;
				int escopo = numEscopo;

				pilha_escopo[numEscopo][(yyvsp[-2]).nome].nome = (yyvsp[-2]).nome;
				pilha_escopo[numEscopo][(yyvsp[-2]).nome].valor_att = 1;
				pilha_escopo[numEscopo][(yyvsp[-2]).nome].label = genLabel();
				//pilha_escopo[numEscopo][$1.nome].declarada = 1;
				(yyvsp[-2]).label   = pilha_escopo[numEscopo][(yyvsp[-2]).nome].label;
				pilha_escopo[numEscopo][(yyvsp[-2]).nome].tipo = (yyvsp[0]).tipo;
				declaraVars[pilha_escopo[numEscopo][(yyvsp[-2]).nome].label] = pilha_escopo[numEscopo][(yyvsp[-2]).nome].tipo;
				
				if((yyvsp[0]).tipo == "string") pilha_escopo[numEscopo][(yyvsp[-2]).nome].str_init = 1;
				pilha_escopo[escopo][(yyvsp[-2]).nome].valor_att = 1;
				if((yyvsp[0]).tipo != "string") (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + (yyvsp[0]).label + ";\n";
				else{
						(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + "(char*) malloc(" + (yyvsp[0]).label_size_str + ");\n"+
						"\t" + "strcpy(" + (yyvsp[-2]).label + " , " + (yyvsp[0]).label + ");\n";
						string label_size = pilha_escopo[escopo][(yyvsp[-2]).nome].label + "_size";
						Tabela_temps[label_size] = "int";
				}		
			}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 493 "sintatica.y" /* yacc.c:1646  */
    {	
				(yyval).traducao = (yyvsp[0]).nome;
			}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 498 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "int";
				(yyval).tipo = "int";
			}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 503 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "float";
				(yyval).tipo = "float";
			}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 508 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "char";
				(yyval).tipo = "char";
			}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 513 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "int";
				(yyval).tipo = "bool";
			}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 518 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "char*";
				(yyval).tipo = "string";
			}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 523 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "void";
				(yyval).tipo = "none";
			}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 530 "sintatica.y" /* yacc.c:1646  */
    {	
				string cast;
				int escopo = getEscopo((yyvsp[-2]).nome);
				string label_size = pilha_escopo[escopo][(yyvsp[-2]).nome].label + "_size";

				if(escopo != -1){
					(yyvsp[-2]).label   = pilha_escopo[escopo][(yyvsp[-2]).nome].label;
					pilha_escopo[escopo][(yyvsp[-2]).nome].valor_att = 1;
					if(pilha_escopo[escopo][(yyvsp[-2]).nome].tipo != (yyvsp[0]).tipo && pilha_escopo[escopo][(yyvsp[-2]).nome].tipo != ""){
						if(isNumeric(pilha_escopo[escopo][(yyvsp[-2]).nome].tipo) && 
						   isNumeric(Tabela_temps[(yyvsp[0]).label])){
							cast = "(" + pilha_escopo[escopo][(yyvsp[-2]).nome].tipo + ") ";
						}
						else yyerror("Tipo diferente da declaração e cast não permitido ");
					}	
					else cast = "";
					//if($1.tipo == "") pilha_escopo[escopo][$1.nome].tipo = $3.tipo;
					pilha_escopo[escopo][(yyvsp[-2]).nome].valor_att = 1;
					if((yyvsp[0]).tipo != "string") (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + cast + (yyvsp[0]).label + ";\n";
					else {
							string aux_aloca;

							if(pilha_escopo[escopo][(yyvsp[-2]).nome].str_init == 0){
								aux_aloca = "(char*) malloc(" + (yyvsp[0]).label_size_str + ");\n";
							}
							else{
							 	pilha_escopo[escopo][(yyvsp[-2]).nome].str_init = 1;
							 	aux_aloca = "(char*) realloc(" + (yyvsp[-2]).label + "," + (yyvsp[0]).label_size_str_realloc +");\n";
							}
							(yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).label + " = " + aux_aloca +
										"\t" + "strcpy(" + (yyvsp[-2]).label + " , " + (yyvsp[0]).label + ");\n";
							Tabela_temps[label_size] = "int";
						}
				}
				else{
					yyerror("Variavel '" + (yyvsp[-2]).nome + "' não declarada");
				}
			}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 569 "sintatica.y" /* yacc.c:1646  */
    {
				int escopo = getEscopo((yyvsp[-4]).nome);

				string label1,label2,label3,label4,label5,label6,label7,label8,label9,label10,float_ou_int,cast;

				if(pilha_escopo[escopo][(yyvsp[-4]).nome].tipo == "int" || pilha_escopo[escopo][(yyvsp[-4]).nome].tipo == "float")
					float_ou_int = pilha_escopo[escopo][(yyvsp[-4]).nome].tipo == "int" ? "!":"";
				
				label1 = genLabel();
				label2 = genLabel();
				label3 = genLabel();
				label4 = genLabel();
				label5 = genLabel();
				label6 = genLabel();
				label7 = genLabel();
				label8 = genLabel();
				label9 = genLabel();
				label10 = genLabel();

				cast = float_ou_int == "" ? "":"(int)";

				Tabela_temps[label1] = "int";
				

				if(escopo != -1){
					pilha_escopo[escopo][(yyvsp[-4]).nome].valor_att = 1;
					string label_size = pilha_escopo[escopo][(yyvsp[-4]).nome].label + "_size";
					Tabela_temps[label_size] = "int";
					Tabela_temps[label1] = "string";
					Tabela_temps[label2] = "char";
					Tabela_temps[label3] = "int";
					Tabela_temps[label4] = "char";
					Tabela_temps[label5] = "int";
					Tabela_temps[label6] = "int";
					Tabela_temps[label7] = "int";
					Tabela_temps[label8] = "int";
					Tabela_temps[label9] = "int";
					Tabela_temps[label10] = "int";

					if(pilha_escopo[escopo][(yyvsp[-4]).nome].tipo == "string"){

						string aux_aloca;

						(yyval).traducao = "\t" + label1 + " = " + "(char*) malloc(MAXSTR);\n";

						if(pilha_escopo[escopo][(yyvsp[-4]).nome].str_init == 0){
							aux_aloca = pilha_escopo[escopo][(yyvsp[-4]).nome].label + " = " + "(char*) malloc(MAXSTR);\n";
						}
						else{
							 pilha_escopo[escopo][(yyvsp[-4]).nome].str_init = 1;
							 aux_aloca = pilha_escopo[escopo][(yyvsp[-4]).nome].label + " = " + "(char*) realloc(" "," +"MAXSTR);\n";
						}
						(yyval).traducao += "\tstd::cin >> " + label1 + ";\n"
									+ "\t" + label2 + " = '\\0'" + ";\n"
									+ "\t" + label3 + " = 0" + ";\n"
									+ "\t" + "inifi" + std::to_string(contif) + ": " + label4 + " = " + label1 + "[" + label3 + "]" + ";\n"
									+ "\t" + label5 + " = " + label4 + "==" + label2 + ";\n"
									+ "\t" + "if(" + label5 + ") goto fimif" + std::to_string(contif)+";\n"
									+ "\t" + label6 + " = 1" + ";\n"
									+ "\t" + label3 + " = " + label3 + "+" +  label6 + ";\n"
									+ "\t" + "goto inifi" + std::to_string(contif) + ";\n"
									+ "\t" + "fimif" + std::to_string(contif) + ":\n"
									+ "\t" + label3 + " = " + label3 + "+" +  label6 + ";\n"
									+ "\t" + label7 + " = " + "sizeof(char)" + ";\n"
									+ "\t" + label8 + " = " + label3 + ";\n" 
									+ "\t" + label_size + " = " + label8 + ";\n"
									+ "\t" + label9 + " = " + label7 + " * "+ label8 + ";\n"
									+ "\t" + label10 + " = " + label9 + ";\n"
									+ "\t" + (pilha_escopo[escopo][(yyvsp[-4]).nome].str_init == 0 ? 
											 (pilha_escopo[escopo][(yyvsp[-4]).nome].label + " = " + "(char*) malloc(" + label10 + ");\n" ):
											 (pilha_escopo[escopo][(yyvsp[-4]).nome].label + " = " + "(char*) realloc(" + pilha_escopo[escopo][(yyvsp[-4]).nome].label + "," + label10 + ");\n"))
									+ "\t" + "strcpy(" + pilha_escopo[escopo][(yyvsp[-4]).nome].label + "," + label1 + ");\n"
									+ "\t" + "free(" + label1 + ");\n";


					}
					else if(pilha_escopo[escopo][(yyvsp[-4]).nome].tipo == "char"){
						(yyval).traducao = "\tstd::cin >> " + pilha_escopo[escopo][(yyvsp[-4]).nome].label + ";\n\t"
									+ label1 + "=" + "std::cin.fail()" + ";\n\t" 
									+ label1 + "=" + " !" + label1 + ";\n\t"
									+ "if(" + label1 +") goto fimif" + std::to_string(contif)+";\n\t\t"
									+ "std::cout << \"Erro de leitura, verifique o tipo declarado e tipo inserido\";\n" + "\n\t\t"
									+ "exit(0);\n\t"
									+ "fimif" + std::to_string(contif) + ":\n\t";
					}
					else{

						Tabela_temps[label2] = "int";
						Tabela_temps[label3] = "int";
						Tabela_temps[label4] = "float";
						(yyval).traducao = "\tstd::cin >> " + label4 + ";\n\t"
									+ label1 + "=" + "std::cin.fail()" + ";\n\t" 
									+ label1 + "=" + " !" + label1 + ";\n\t"
									+ label2 + "=" + label4 + "!=" + "(int) " + label4 +";\n\t" 
									+ label3 + "=" + float_ou_int + label2 + ";\n\t"
									+ label3 + "=" + label3 + "&&" + label1  + ";\n\t"
									+ "if(" + label3 +") goto fimif" + std::to_string(contif)+";\n\t\t"
									+ "std::cout << \"Erro de leitura, verifique o tipo declarado e tipo inserido\";\n" + "\n\t\t"
									+ "exit(0);\n\t"
									+ "fimif" + std::to_string(contif) + ":\n\t"
									+ pilha_escopo[escopo][(yyvsp[-4]).nome].label + "=" +  cast + label4 + ";\n";
					}
						contif++;
				}
				else{
					yyerror("Variavel '" + (yyvsp[-4]).nome + "' não declarada");
				}

			}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 678 "sintatica.y" /* yacc.c:1646  */
    {
				string label1,label2;
				string cast;

				int escopo = getEscopo((yyvsp[-2]).nome);

				label1 = genLabel();
				label2 = genLabel();
				Tabela_temps[label1] = pilha_escopo[escopo][(yyvsp[-2]).nome].tipo;
				Tabela_temps[label2] = pilha_escopo[escopo][(yyvsp[-2]).nome].tipo;

				if(!pilha_escopo[escopo][(yyvsp[-2]).nome].valor_att) yyerror("A variavel '" + (yyvsp[-2]).nome + "' não possui valor atribuido e por isso não pode ser (de/in)crementada");

				if(escopo != -1){
					(yyvsp[-2]).label   = pilha_escopo[escopo][(yyvsp[-2]).nome].label;
					if(pilha_escopo[escopo][(yyvsp[-2]).nome].tipo != (yyvsp[0]).tipo && pilha_escopo[escopo][(yyvsp[-2]).nome].tipo != ""){
						if(isNumeric(pilha_escopo[escopo][(yyvsp[-2]).nome].tipo) && 
						   isNumeric(Tabela_temps[(yyvsp[0]).label])){
							cast = "(" + pilha_escopo[escopo][(yyvsp[-2]).nome].tipo + ") ";
						}
						else yyerror("Tipo diferente da declaração e cast não permitido ");
					}	
					else cast = "";

					(yyval).traducao = (yyvsp[0]).traducao + "\t" + label1 + " = " + cast + (yyvsp[0]).label + ";\n"
								+ "\t" + label2   + " = " + (yyvsp[-2]).label + (yyvsp[-1]).traducao + label1 + ";\n"
								+ "\t" + (yyvsp[-2]).label + " = " + label2 + ";\n";
				}
				else{
					yyerror("Variavel '" + (yyvsp[-2]).nome + "' não declarada");
				}

			}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 711 "sintatica.y" /* yacc.c:1646  */
    {
				string label1,label2;

				int escopo = getEscopo((yyvsp[-1]).nome);

				label1 = genLabel();
				label2 = genLabel();
				Tabela_temps[label1] = pilha_escopo[escopo][(yyvsp[-1]).nome].tipo;
				Tabela_temps[label2] = pilha_escopo[escopo][(yyvsp[-1]).nome].tipo;
				
				if(!pilha_escopo[escopo][(yyvsp[-1]).nome].valor_att) yyerror("A variavel '" + (yyvsp[-1]).nome + "' não possui valor atribuido e por isso não pode ser (de/in)crementada");
				
				if(escopo != -1){
					(yyvsp[-1]).label   = pilha_escopo[escopo][(yyvsp[-1]).nome].label;
					if(!isNumeric(pilha_escopo[escopo][(yyvsp[-1]).nome].tipo) ){
						yyerror("Operador unário definido somente para numeros ");
					}
					(yyval).traducao = "\t" + label1 + " = " + ((yyvsp[-1]).tipo == "int" ? "1":"1.0") + ";\n"
								+ "\t" + label2 + " = " + (yyvsp[-1]).label + (yyvsp[0]).traducao + label1 + ";\n"
								+ "\t" + (yyvsp[-1]).label + " = " + label2 + ";\n";
				}
				else{
					yyerror("Variavel '" + (yyvsp[-1]).nome + "' não declarada");
				}
			}
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 739 "sintatica.y" /* yacc.c:1646  */
    {
			  	int error = 0;
			  	string aux = (yyvsp[-1]).tipo;
			  	vector<string> params,param_aux;
				string args = "";
				boost::split(params,aux,boost::is_any_of(","));

			  	if(funcs_info.find((yyvsp[-3]).nome) == funcs_info.end()){
			  		yyerror("Esta função não está definida");
			  	}

			  	for (int i = 0; i < params.size() ; i++)
			  	{
					if(funcs_info[(yyvsp[-1]).nome].tipo_params[i] != params[i]){
						yyerror("Tipo do parâmetro passado diferente do definido");
						error = 1;
					}

			  	}
			  	if(!error){
				  	(yyval).traducao = (yyvsp[-1]).traducao + "\t" + funcs_info[(yyvsp[-3]).nome].label + "(" + (yyvsp[-1]).label + ");\n";
				  	(yyval).tipo = funcs_info[(yyvsp[-3]).nome].tipo;
				  	(yyval).nome = (yyvsp[-3]).nome;
				}
			  }
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 765 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[-1]).label + "," + (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[-1]).tipo + "," + (yyvsp[0]).tipo;
			}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 770 "sintatica.y" /* yacc.c:1646  */
    {(yyval).traducao = "";}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 773 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).label = (yyvsp[-1]).label;
				(yyval).tipo = (yyvsp[-1]).tipo;
			}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 781 "sintatica.y" /* yacc.c:1646  */
    {
			  	if(funcs_info.find((yyvsp[-9]).nome) != funcs_info.end()){
			  		yyerror("Esta função já está definida");
			  	}
			  	else if((yyvsp[-10]).tipo != (yyvsp[-2]).tipo && (yyvsp[-10]).tipo != "none"){
			  		yyerror("Tipo de retorno diferente da declaração");
			  		(yyval).tipo = "invalid";
			  	}
			  	else{

				  	funcs_info[(yyvsp[-9]).nome].tipo = (yyvsp[-10]).tipo;
				  	funcs_info[(yyvsp[-9]).nome].nome = (yyvsp[-9]).nome;
				  	funcs_info[(yyvsp[-9]).nome].label = genLabel() + "_func";
				  	funcs_info[(yyvsp[-9]).nome].label_return = (yyvsp[-2]).label;
				  	string aux = (yyvsp[-7]).traducao;
					vector<string> params,param_aux;
					string args = "";
					boost::split(params,aux,boost::is_any_of(","));
					for(int i = 0; i < params.size() ; i++){
						boost::split(param_aux,params[i],boost::is_any_of(":"));
						args += param_aux[0] + " " + param_aux[1] + (i + 1 == params.size() ? "":",");
						funcs_info[(yyvsp[-9]).nome].tipo_params.push_back((param_aux[0] == "char*" ? "string":param_aux[0] == "bool" ? "int":param_aux[0]));
						funcs_info[(yyvsp[-9]).nome].vars_params.push_back(param_aux[1]);
					}

					FUNCS += (yyvsp[-10]).traducao + " " + funcs_info[(yyvsp[-9]).nome].label + "(" + args +"){\n"
					+		(yyvsp[-4]).traducao + (yyvsp[-2]).traducao +"\treturn " + ((yyvsp[-10]).tipo != "none" ? (yyvsp[-2]).label:"") + ";\n}\n";
				  	
				  	(yyval).traducao = "";

				}
			  }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 816 "sintatica.y" /* yacc.c:1646  */
    {
					
					string nome  = (yyvsp[-1]).nome;
					pilha_escopo[numEscopo][nome].nome  	= nome;
					pilha_escopo[numEscopo][nome].label 	= genLabel();
					pilha_escopo[numEscopo][nome].declarada = 1;
					pilha_escopo[numEscopo][nome].tipo 		= (yyvsp[-3]).tipo;
					
					(yyval).traducao = (yyvsp[-3]).traducao + ":" + pilha_escopo[numEscopo][nome].label + (yyvsp[0]).traducao;
				}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 827 "sintatica.y" /* yacc.c:1646  */
    {
					(yyval).traducao = "";
				}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 832 "sintatica.y" /* yacc.c:1646  */
    {
					string nome  = (yyvsp[-1]).nome;
					pilha_escopo[numEscopo][nome].nome  	= nome;
					pilha_escopo[numEscopo][nome].label 	= genLabel();
					pilha_escopo[numEscopo][nome].declarada = 1;
					pilha_escopo[numEscopo][nome].tipo 		= (yyvsp[-3]).tipo;
					
					
					(yyval).traducao = "," + (yyvsp[-3]).traducao + ":" + pilha_escopo[numEscopo][nome].label;
				}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 844 "sintatica.y" /* yacc.c:1646  */
    {
					int escopo1 = (yyvsp[-4]).traducao == "" ? getEscopo((yyvsp[-4]).nome):-2;
					int escopo2 = (yyvsp[-2]).traducao == "" ? getEscopo((yyvsp[-2]).nome):-2;
					
					if((yyvsp[-4]).tipo != "string" || (yyvsp[-2]).tipo != "string"){
						yyerror("Operação permitida somente para strings");
					}
					if((((yyvsp[-4]).traducao == "" && !pilha_escopo[escopo1][(yyvsp[-4]).nome].valor_att)
					|| ((yyvsp[-2]).traducao == "" && !pilha_escopo[escopo1][(yyvsp[-2]).nome].valor_att))
						&& (escopo1 != -2 && escopo2 != -2)
					){
						yyerror("Impossivel concatenar string com variaveis não inicializadas");
					}
					if(getEscopo((yyvsp[-6]).nome) == -1){
						yyerror("Varivel '" + (yyvsp[-6]).nome + "' não declarada");
					}
					else if(pilha_escopo[getEscopo((yyvsp[-6]).nome)][(yyvsp[-6]).nome].tipo != "string"){
						yyerror("Operação permitida apenas entre strings");
					}
					else{
						string tamanho1 = (yyvsp[-4]).traducao == "" ? pilha_escopo[getEscopo((yyvsp[-4]).nome)][(yyvsp[-4]).nome].label + "_size":(yyvsp[-4]).label_len ;
						string tamanho2 = (yyvsp[-2]).traducao == "" ? pilha_escopo[getEscopo((yyvsp[-2]).nome)][(yyvsp[-2]).nome].label + "_size":(yyvsp[-2]).label_len ;
						int escopo = getEscopo((yyvsp[-6]).nome);
						string label_size = pilha_escopo[escopo][(yyvsp[-6]).nome].label + "_size";
						string label_size2 = genLabel();
						Tabela_temps[label_size2] = "int";
						Tabela_temps[label_size] = "int";
						string m_or_r;
						
						if(!pilha_escopo[escopo][(yyvsp[-6]).nome].valor_att){
								m_or_r = pilha_escopo[escopo][(yyvsp[-6]).nome].label + " = " + "(char*) malloc(" + label_size2 + ");\n";
						}
						else{
								 m_or_r = "(char*) realloc(" + pilha_escopo[escopo][(yyvsp[-6]).nome].label + 
								 			"," + label_size2 + ");\n" ;
						} 
						(yyval).traducao = (yyvsp[-4]).traducao + (yyvsp[-2]).traducao + 
						"\t" + label_size + " = " + tamanho1 + " + " + tamanho2 + ";\n"
					+	"\t" + label_size2 + " = " + "sizeof(char) * " + label_size + ";\n"
					+   "\t" + m_or_r
					+	"\t" + "strcat(" + pilha_escopo[escopo][(yyvsp[-6]).nome].label + "," + ((yyvsp[-4]).traducao == "" ? pilha_escopo[getEscopo((yyvsp[-4]).nome)][(yyvsp[-4]).nome].label:(yyvsp[-4]).label) + ");\n"
					+   "\t" + "strcat(" + pilha_escopo[escopo][(yyvsp[-6]).nome].label + "," + ((yyvsp[-2]).traducao == "" ? pilha_escopo[getEscopo((yyvsp[-2]).nome)][(yyvsp[-2]).nome].label:(yyvsp[-2]).label) + ");\n";

					}
				}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 891 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + "\tstd::cout << std::endl ;\n";
			}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 895 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-6]).traducao + "\tstd::cout << " + (yyvsp[-2]).traducao + " ;\n";
			}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 901 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao;
				(yyval).traducao += "\tstd::cout<<" + (yyvsp[-2]).label + ";\n";
				(yyval).traducao += (yyvsp[0]).traducao;
			}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 907 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao ;
				(yyval).traducao += "\tstd::cout<<" + (yyvsp[0]).label + ";\n"; 
			}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 913 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				if((yyvsp[0]).label == "none") yyerror("Você tentou imprimir algo do tipo None e isso não é possivel");
			}
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 919 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"+",ARITMETICA_CONV);
			}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 923 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"-",ARITMETICA_CONV);
			}
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 927 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"*",ARITMETICA_CONV);
			}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 931 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"/",ARITMETICA_CONV);
			}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 935 "sintatica.y" /* yacc.c:1646  */
    {
				if(!isNumeric((yyvsp[-2]).tipo) || !isNumeric((yyvsp[-1]).tipo)){
					yyerror("Operação permitida somente com numeros");
				}
				else if((yyvsp[0]).tipo != "int"){
					yyerror("Somente expoentes inteiros");
				}
				else{

					(yyval).label = genLabel();
					string label1 = genLabel();
					string label2 = genLabel();
					string label3 = genLabel();
					string label4 = genLabel();
					string label5 = genLabel();
					string label6 = genLabel();
					string label7 = genLabel();
					string label8 = genLabel();
					Tabela_temps[(yyval).label] = (yyvsp[-2]).tipo == "int" ? "int":"float";
					Tabela_temps[label7] = (yyvsp[-2]).tipo == "int" ? "int":"float";
					Tabela_temps[label1] =  "int";
					Tabela_temps[label2] =  "int";
					Tabela_temps[label3] =  "int";
					Tabela_temps[label4] =  "int";
					Tabela_temps[label5] =  "int"; 
					Tabela_temps[label6] =  "int";
					Tabela_temps[label8] =  "int";

					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + 
							   "\t" + label1 + " = " + "1;\n\t"
							   		+ label8 + " = " + "1;\n\t"
									+ label7 + " = " + (yyvsp[-2]).label + ";\n\t"
									+ label2 + " = " + label1 + " < " + (yyvsp[0]).label + ";\n\t"
									+ label3 + " = " + "!" + label2 + ";\n\t"
					+ "iniforNuser" + std::to_string(contforNAOuser) + ": if(" + label3 + ") goto fimforNuser" + std::to_string(contforNAOuser) + ";\n\t" 
									+ label5 + " = " + label7 + " * " + (yyvsp[-2]).label+ ";\n\t"
									+ label7 + " = " + label5 + ";\n\t"
									+ label8 + " = " + label7 + ";\n\t"
									+ label6   + " = " + "1;\n\t"
									+ label1 + " = " + label1 + " + " + label6 + ";\n\t"
									+ label2 + " = " + label1 + " < " + (yyvsp[0]).label + ";\n\t"
									+ label3 + " = " + "!" + label2 + ";\n\t"
									+ "goto iniforNuser" + std::to_string(contforNAOuser) + ";\n\t"
									+ "fimforNuser" + std::to_string(contforNAOuser) + ":\n"
					"\t" + (yyval).label + " = " + label8 + ";\n";
					++contforNAOuser;
				}
			}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 984 "sintatica.y" /* yacc.c:1646  */
    { 
				(yyval).label = (yyvsp[-1]).label;
				(yyval).tipo = (yyvsp[-1]).tipo;
				Tabela_temps[(yyval).label] = (yyvsp[-1]).tipo ; 
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 991 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"&&",LOGICA_CONV);
			}
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 995 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"||",LOGICA_CONV);
			}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 999 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label    = genLabel();
				Tabela_temps[(yyval).label] = (yyvsp[0]).tipo ; 
				(yyval).traducao = "\t" + (yyval).label + " = !" + (yyvsp[-1]).traducao + ";\n";
			}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1005 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"<",RELACIONAL_CONV);
			}
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1009 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),">",RELACIONAL_CONV);
			}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1013 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),">=",RELACIONAL_CONV);
			}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1017 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"<=",RELACIONAL_CONV);
			}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1021 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"==",RELACIONAL_CONV_COMP);
			}
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1025 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval) = initExpressao((yyvsp[-2]),(yyvsp[0]),"!=",RELACIONAL_CONV_COMP);
			}
#line 2828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1029 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				(yyval).tipo = (yyvsp[-3]).traducao;
				Tabela_temps[(yyval).label] = (yyval).tipo;
				(yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyval).label + " = (" + (yyvsp[-3]).traducao + ") " + (yyvsp[-1]).label + ";\n";
			}
#line 2839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1036 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				if((yyvsp[0]).tipo != "none" && (yyvsp[0]).tipo != "invalid"){
					(yyval).label = genLabel();
					Tabela_temps[(yyval).label] = (yyvsp[0]).tipo;
					(yyval).traducao += "\t" + (yyval).label + " = " + funcs_info[(yyvsp[0]).nome].label_return + ";\n";
				}
				else{(yyval).label = "none";}
			}
#line 2853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1046 "sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).label = genLabel();
				Tabela_temps[(yyval).label] = "int";
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1053 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label    = genLabel();
				Tabela_temps[(yyval).label] = (yyval).tipo ; 
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1059 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label    = genLabel();
				Tabela_temps[(yyval).label] = (yyval).tipo;
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1065 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label    = genLabel();
				Tabela_temps[(yyval).label] = (yyval).tipo;
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1071 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label    = genLabel();
				Tabela_temps[(yyval).label] = (yyval).tipo;
				(yyval).traducao = "\t" + (yyval).label + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1077 "sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = genLabel();
				string label1 = genLabel();
				string label2 = genLabel() + "_size";
				string label3 = genLabel();
				string label4 = genLabel();
				Tabela_temps[label1] = "int";
				Tabela_temps[label2] = "int";
				Tabela_temps[label3] = "int";
				Tabela_temps[label4] = "int";
				Tabela_temps[(yyval).label] = (yyval).tipo;
				(yyval).label_size_str = label4;
				(yyval).label_size_str_realloc = label4;
				(yyval).label_len = label2;
				(yyval).traducao = "\t" + label1 + " = " + "sizeof(char)" + ";\n"+
										 	"\t" + label2 + " = " + std::to_string((yyvsp[0]).traducao.size()) + ";\n" + 
										 	"\t" + label3 + " = " + label1 + " * "+ label2 + ";\n"+
										 	"\t" + label4 + " = " + label3 + ";\n";
				(yyval).traducao += "\t" + (yyval).label + " = " + "(char*) " + "malloc(" + label4 + " );\n" +  
				"\t" + "strcpy(" + (yyval).label + ", " + "\"" + (yyvsp[0]).traducao + "\"" + ");\n";
			}
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1099 "sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_escopo[GLOBAL][(yyvsp[0]).nome].declarada == 0) 
						yyerror(
							"Variavel '"
							+ (yyvsp[-1]).nome
							+ "'" + " não está declarada no escopo global"
							);
				(yyval).traducao = "";
				(yyval).label = pilha_escopo[GLOBAL][(yyvsp[0]).nome].label;
				(yyval).nome  = pilha_escopo[GLOBAL][(yyvsp[0]).nome].nome;
			}
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1111 "sintatica.y" /* yacc.c:1646  */
    {
				int escopo = -1;
				
				if(atoi((yyvsp[-1]).traducao.c_str()) < 0 ) yyerror("Não é permitido numero negativo como parâmetro ");
				else escopo = numEscopo - atoi((yyvsp[-1]).traducao.c_str());
				
				if(escopo < 0 ) yyerror("Impossivel acessar mais escopos do que existem, tente um numero menor ");
				//cout << $2.nome << " ainda cria\n";
				if(pilha_escopo[escopo][(yyvsp[-3]).nome].declarada == 0) 
						yyerror(
							"Variavel '"
							+ (yyvsp[-3]).nome
							+ "'" + " não foi declarada" + "no escopo passado como parâmetro"
							);
				if(escopo >= 0){
					(yyval).traducao = "";
					(yyval).label = pilha_escopo[escopo][(yyvsp[-3]).nome].label;
					(yyval).nome  = pilha_escopo[escopo][(yyvsp[-3]).nome].nome;
				}
			}
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1132 "sintatica.y" /* yacc.c:1646  */
    {
				int escopo;
				for(escopo = numEscopo - 1; escopo >= 0 ; escopo--){
					if((pilha_escopo[escopo]).find((yyvsp[0]).nome) != (pilha_escopo[escopo]).end()) break;
				}

				if(escopo >= 0){
					(yyval).traducao = "";
					(yyval).label = pilha_escopo[escopo][(yyvsp[0]).nome].label;
					(yyval).nome  = pilha_escopo[escopo][(yyvsp[0]).nome].nome;
				}
				else yyerror("Variavel '" + (yyvsp[0]).nome + "' não foi declarada fora do escopo atual");
			}
#line 2989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1146 "sintatica.y" /* yacc.c:1646  */
    {
				int escopo = getEscopo((yyvsp[0]).nome);
				if(escopo == -1 || pilha_escopo[escopo][(yyvsp[0]).nome].declarada == 0) 
						yyerror(
							"Variavel '"
							+ (yyvsp[0]).nome
							+ "'" + "não foi declarada"
							);
				else{
					(yyval).traducao = "";
					(yyval).label = pilha_escopo[escopo][(yyvsp[0]).nome].label;
					(yyval).nome  = pilha_escopo[escopo][(yyvsp[0]).nome].nome;
				}

			}
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3013 "y.tab.c" /* yacc.c:1646  */
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
#line 1164 "sintatica.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yydebug = 0;
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << " " << "Linha [" + std::to_string(LinhaAtual) + "]"<< endl;
	ErroDeCompila = 1;
}

string genLabel(void)
{
	return "m_e_c" + std::to_string(contLabel++);
}

int getLenFromLabel(string label)
{
int aux;
	for(map<string,string>::iterator i = declaraVars.begin(); i !=declaraVars.end(); ++i){
		if(i->first == label){
			aux = getEscopo(getVarFromLabel(i->first));
			return pilha_escopo[aux][getVar(label,aux)].tam_str;
		}
	}
	cout << "sai nessa porra ";
	return -1;
}

int getEscopo(string nome)
{
	for(int j = numEscopo; j >= 0 ; j--){
		if((pilha_escopo[j]).find(nome) != (pilha_escopo[j]).end()) return j;
	}
	return -1;
}

string getVar(string label, int escopo)
{
	for(map<string,Att_Var>::iterator i = pilha_escopo[escopo].begin(); i != pilha_escopo[escopo].end(); ++i){
		if(i->second.label == label){
			return i->first;
		}
	}
	return "";
}

string getVarFromLabel(string nome){
	for(int j = numEscopo; j >= 0; j--){
		for(map<string,Att_Var>::iterator i = pilha_escopo[j].begin(); i != pilha_escopo[j].end(); ++i){
			if(i->second.label == nome){
				return i->first;
			}
		}
	}
	return "";
}

string declaraVariaveis(void)
{
string s = "";
int tam_buffer;
	for(map<string,string>::iterator i = Tabela_temps.begin(); i != Tabela_temps.end(); ++i){
		string aux = i->second == "bool" ? "int":i->second == "string" ? "char*":i->second;
		s = s + aux + " " + i->first + ";\n";	
	}
	for(map<string,string>::iterator i =declaraVars.begin(); i !=declaraVars.end(); ++i){
		if(i->first == "") continue;
		string aux = i->second == "bool" ? "int":i->second == "string" ? "char*":i->second;
		s = s + aux + " " + i->first + ";\n" ;
	}

	s += "\n";

	return s;
	
}

string tipoImplicito(struct atributos $1, struct atributos $2, int TIPO_COMPARACAO)
{
	switch(TIPO_COMPARACAO){
		case ARITMETICA_CONV:
			return tipoImplicitoAritmetica($1,$2);
		case RELACIONAL_CONV:
			return tipoImplicitoRelacional($1,$2,RELACIONAL_CONV);
		case RELACIONAL_CONV_COMP:
			return tipoImplicitoRelacional($1,$2,RELACIONAL_CONV_COMP);
		case LOGICA_CONV:
			return tipoImplicitoLogico($1,$2);
	}
	
	return "";
}

string tipoImplicitoAritmetica(struct atributos $1, struct atributos $2)
{
	if(!isNumeric($1.tipo) || !isNumeric($2.tipo)){
		yyerror("Operação aritmetica não permitida entre os tipos "
			+ $1.tipo + " e " + $2.tipo
			);
		return "";
	}
	if($1.tipo == $2.tipo) return $1.tipo;
	else return "float";	
}

string tipoImplicitoRelacional(struct atributos $1, struct atributos $2, int tipo_conv)
{
	int rel = ((!isNumeric($1.tipo) || !isNumeric($2.tipo)) 
		&& tipo_conv == RELACIONAL_CONV);
	if( rel || 
		(($1.tipo != $2.tipo && (!isNumeric($1.tipo) || !isNumeric($2.tipo))) && tipo_conv == RELACIONAL_CONV_COMP)){
		yyerror("Operação relacional não permitida entre os tipos "
			+ $1.tipo + " e " + $2.tipo
			);
		return "";
	}

	return "bool";
}

string tipoImplicitoLogico(struct atributos $1, struct atributos $2)
{
	if($1.tipo == "char" || $2.tipo == "char" || $1.tipo == "int" || 
	   $1.tipo == "float" || $2.tipo == "int"  || $2.tipo == "float"){
		yyerror("Operação logica não permitida entre os tipos "
			+ $1.tipo + " e " + $2.tipo
			);
		return "";
	}
	return "bool";
}

struct atributos initExpressao(struct atributos $1,struct atributos $3,string op,int TIPO_CONVERSAO)
{
	struct atributos $$;
	$$.label    = genLabel();
	string label1;
	Tabela_temps[$$.label] = tipoImplicito($1,$3,TIPO_CONVERSAO); 
	if($1.tipo == "string" && $3.tipo == "string" ){
		label1 = genLabel();
		Tabela_temps[label1] = "int";
		$$.traducao = $1.traducao + $3.traducao + "\t"
					  + label1 + " = " + "strcmp(" + $1.label + "," + $3.label + ");\n\t"
					  + $$.label + " = " + (op == "!=" ? "":"!") + label1 + ";\n";

	}
	else $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + op + " " + $3.label + ";\n";
	$$.tipo = Tabela_temps[$$.label];

	return $$;
}

int isNumeric(string tipo)
{
	if(tipo == "int" || tipo == "float") return 1;
	else 				     return 0;
}
