%{
#include <string>

%}

ESPACO [ ]
DIGITO -?[0-9]
LETRA [A-Za-z_]
DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
BOOL "True"|"False"
ESCAPE \\(t|n)
CHAR \'({LETRA}|{NUM}|{ESCAPE}|{ESPACO})\'
ID {LETRA}({LETRA}|{NUM})*

%x SINGLE_STRING

%%

\"                          BEGIN(SINGLE_STRING);
<SINGLE_STRING>{
  \n                        yyerror("Faltam aspas para terminar depois da nova linha");
  <<EOF>>                   yyerror("Faltam aspas para terminar depois de EOF");
  ([^\\\"]|\\.)*            {yylval.traducao = yytext; yylval.tipo = "string";return TK_STRING;}
  \"                        BEGIN(INITIAL);
  .                         ;
}


"\n"		{LinhaAtual += 1;}

{DELIM} 	{}

"#".*		{}
"/*"([^*]|\*+[^*/])*\*+"/"  {}

"main"		{empilha_escopo;return TK_MAIN;}

"read"		{return TK_READ;}
"print"     {return TK_PRINT;}

"separated" {return TK_SEPARA_PRINT;}
"strconcat"	{return TK_STRCAT;}

"while"		{empilha_escopo;empilha_loop;return TK_WHILE;}
"for"		{empilha_escopo;empilha_loop;return TK_FOR;}
"dowhile"   {empilha_escopo;empilha_loop;return TK_DOWHILE;}
".."		{return TK_RANGE;}
"step"		{return TK_STEP;}
"switch"	{return TK_SWITCH;}
"case"		{return TK_CASE;}
"default"	{return TK_DEFAULT;}

"then"		{return TK_THEN;}
"endif"		{desempilha_escopo;return TK_ENDIF;}

"do"		{return TK_DO;}
"endloop"	{desempilha_loop;desempilha_escopo; return TK_ENDLOOP;}

"break"		{return TK_BREAK;}
"continue"	{return TK_CONTINUE;}

"def"		{empilha_escopo;return TK_FUNC;}
"initfunc"	{return TK_INITFUNC;}
"return"	{return TK_RETURN;}
"endfunc"   {desempilha_escopo;return TK_ENDFUNC;}

"if"		{empilha_escopo;return TK_IF;}
"else"		{desempilha_escopo;empilha_escopo;return TK_ELSE;}

"int"   	{return TK_VARNUM;}
"float" 	{return TK_VARFLOAT;}
"char"		{return TK_VARCHAR;}
"bool"		{return TK_VARBOOL;}
"string"    {return TK_VARSTR;} 
"none"		{return TK_FUNCNONE;}
"NONE"  	{yylval.traducao = "0"; return TK_NONE;}

[(){}[\];,]	{ return *yytext; }

[+\-*/=<>]	{ return *yytext; }
"**"		{ return TK_EXP; }
">=" 		{ return TK_MAIOR_EQ; }
"<="		{ return TK_MENOR_EQ; }
"=="		{ return TK_IGUAL2;}
"!="		{ return TK_DIFERENTE;}

"+="		{ yylval.traducao = "+"; return TK_OPCOMPOSTO;}
"-="		{ yylval.traducao = "-"; return TK_OPCOMPOSTO;}
"*="		{ yylval.traducao = "*"; return TK_OPCOMPOSTO;}
"/="		{ yylval.traducao = "/"; return TK_OPCOMPOSTO;}

"++"		{yylval.traducao = "+";return TK_OPUNARIO;}
"--"		{yylval.traducao = "-";return TK_OPUNARIO;}

":" 		{return TK_ATTFUNC;}

"nonLocal"  {return TK_NOLOCAL;}
"GLOBAL"	{return TK_GLOBAL;}

"and"		{ return TK_AND;}
"or"		{ return TK_OR;}
"not"       { return TK_NOT;}

{NUM}		{yylval.traducao = yytext; yylval.tipo = "int";  return TK_NUM;}
{CHAR}		{yylval.traducao = yytext; yylval.tipo = "char"; return TK_CHAR;}
{BOOL}		{yylval.traducao = yytext; yylval.tipo = "bool"; return TK_BOOL;}
{REAL}		{yylval.traducao = yytext; yylval.tipo = "float";return TK_FLOAT;}
{ID}		{yylval.nome     = yytext; return TK_ID; }
.			{ *yytext; }

%%
