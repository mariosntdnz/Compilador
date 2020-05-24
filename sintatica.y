%{
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

%}

%token TK_MAIN TK_ID 
%token TK_FIM TK_ERROR
%token TK_NUM TK_VARNUM TK_FLOAT TK_VARFLOAT TK_VARBOOL TK_BOOL TK_VARCHAR TK_CHAR TK_FUNCNONE TK_ATTFUNC TK_RETURN TK_NONE
%token TK_MAIOR_EQ TK_MENOR_EQ TK_IGUAL2 TK_DIFERENTE TK_AND TK_OR TK_NOT TK_EXP TK_OPCOMPOSTO TK_OPUNARIO TK_NOLOCAL TK_GLOBAL TK_ENDFUNC TK_FUNC TK_STRCAT TK_INITFUNC
%token TK_SEPARA_PRINT TK_VARSTR TK_STRING TK_WHILE TK_FOR TK_STEP TK_IF TK_ELIF TK_ELSE TK_SWITCH TK_CASE TK_DEFAULT TK_INIT_BLOCO_DEC TK_END_BLOCO_DEC TK_DO TK_ENDLOOP TK_THEN TK_ENDIF TK_RANGE TK_BREAK TK_CONTINUE TK_READ TK_PRINT TK_DOWHILE

%start S

%left TK_OR
%left TK_AND
%left TK_NOT
%left '<' '>' TK_MAIOR_EQ TK_MENOR_EQ TK_IGUAL2 TK_DIFERENTE
%left '+' '-'
%left '*' '/'
%left TK_EXP
%left '(' ')'

%%

S 			: AUXSTART COMANDOS
			{
				if(ErroDeCompila) exit(0);
				cout << "/*Compilador MEC*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n#include<math.h>\n#define True 1\n#define False 0\n#define NONE 0\n#define MAXSTR 1500\n" << declaraVariaveis() << FUNCS << "int main(void)\n{\n" << $2.traducao << "\treturn 0;\n}" << endl; 
			}
			;
AUXSTART :  {empilha_escopo;}

/*BLOCO		:       '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;
*/
COMANDOS	: COMANDO COMANDOS 
	 		{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			{
				$$.traducao = $1.traducao;

			}
			| ATRIBUICAO ';'
			{
				$$.traducao = $1.traducao;
			}
			| DECLARACAO ';'
			{
				$$.traducao = $1.traducao;
			}
			| DECLARAFUNC 
			{
				$$.traducao = $1.traducao;
			}
			|IF
			{
				$$.traducao = $1.traducao;
			}
			|FOR
			{
				$$.traducao = $1.traducao;
			}
			|WHILE
			{
				$$.traducao = $1.traducao;
			} 
			|DOWHILE
			{
				$$.traducao = $1.traducao;
			}
			|BREAK ';'
			{
				$$.traducao = $1.traducao;
			}
			|CONTINUE ';'
			{
				$$.traducao = $1.traducao;
			}
			| PRINT
			{
				$$.traducao = $1.traducao;
			}
			|CONCAT
			{
				$$.traducao = $1.traducao;
			}
			;

BREAK : 	TK_BREAK '(' TK_NUM ')' 
			{
				int loop = 0,num = atoi($3.traducao.c_str());

				if(controle_loop == -1)     yyerror("Não há loop para ser quebrado");

				if(num - 1 > controle_loop  && controle_loop > -1)yyerror("Você tentou quebrar mais loops do que existem");
				else if(num == 0)								  yyerror("Impossivel quebrar 0 loops, tente um numero valido");
				else if(num < 0)								  loop = 1;

				loop = loop == 1 ? 0:num - controle_loop + 1;

				$$.traducao = "\tgoto fimloop" + 
				std::to_string(pilha_loop[loop]) + ";\n";

			}
			;
CONTINUE : 	TK_CONTINUE '(' TK_NUM ')' 
			{
				int loop = 0,num = atoi($3.traducao.c_str());

				if(controle_loop == -1)     					  yyerror("Não há loop para ser pulado");

				if(num - 1 > controle_loop && controle_loop > -1) yyerror("Você tentou pular mais loops do que existem");
				else if(num == 0)								  yyerror("Impossivel pular 0 loops, tente um numero valido");
				else if(num < 0)								  loop = 1;

				loop = loop == 1 ? 0:num - controle_loop + 1;

				$$.traducao = "\tgoto labelcontinue" + 
				std::to_string(pilha_loop[loop]) + ";\n";

			}
			;

IF : 		   TK_IF E TK_THEN COMANDOS TK_ENDIF 
		   {
			$$.traducao = $2.traducao + "\t" + $2.label + "=" + "!" + $2.label + 
				      ";\n\t" + "if(" + $2.label + ") goto fimif" + std::to_string(contif) +";"+
				      "\n" + $4.traducao + "\n\t fimif" + std::to_string(contif) + ":\n";      
		   	contif++;
		   }
		   | TK_IF E TK_THEN COMANDOS TK_ELSE COMANDOS TK_ENDIF
		   {
			$$.traducao = $2.traducao + "\t" + $2.label + "=" + "!" + $2.label + 
				      "\n\t" + "if(" + $2.label + ") goto else" + std::to_string(contif) +";"+
				      "\n" + $4.traducao +"\t"+"goto fimif"+ std::to_string(contif) + ";\n\t" +"else"+std::to_string(contif) +":\n"+ $6.traducao + "\tfimif" + std::to_string(contif) + ":\n"; 
		   	contif++;
		   };
FOR : 		 TK_FOR DECLARATEMPFOR TK_NUM TK_RANGE TK_NUM TK_DO COMANDOS TK_ENDLOOP
    		{

			string operador = (atoi($3.traducao.c_str()) < atoi($5.traducao.c_str())) ?  "<":">";
			string operador2 = (atoi($3.traducao.c_str()) < atoi($5.traducao.c_str())) ?  "+":"-";
			string label1 = genLabel();
			string label2 = genLabel();
			string label3 = genLabel();
			string label4 = genLabel();
			Tabela_temps[label1] = "int" ; 
			Tabela_temps[label2] = "int" ; 
			Tabela_temps[label3] = "int" ; 
			Tabela_temps[label4] = "int" ;
			 
			$$.traducao = "\n\t" + label1 + "=" + $3.traducao +";\n\t" + 
					       label2 + "=" + $5.traducao + ";\n\t" + 
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
						label3 + "=" + "!" + label3 + ";\n\t" +
						$2.traducao + "=" + $3.traducao + ";\n\t" +
					 "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " +
					  "if(" + label3 + ") goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n"+
					   $7.traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
					   + "\t" + $2.traducao + "=" + $2.traducao + operador2 + "1;\n\t" +
					   		label1 + "=" + $2.traducao + ";\n\t" +
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
					label3 + "=" + "!" + label3 + ";\n\tgoto iniloop" + std::to_string(pilha_loop[controle_loop])+					+ ";\n\tfimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n";	
			--controle_loop;
		}
		|TK_FOR DECLARATEMPFOR TK_NUM TK_RANGE TK_NUM TK_STEP TK_NUM TK_DO COMANDOS TK_ENDLOOP
		{
			string operador = (atoi($3.traducao.c_str()) < atoi($5.traducao.c_str())) ?  "<":">";
			string operador2 = (atoi($7.traducao.c_str()) > 0) ?  "+":"";
			string label1 = genLabel();
			string label2 = genLabel();
			string label3 = genLabel();
			string label4 = genLabel();
			Tabela_temps[label1] = "int" ; 
			Tabela_temps[label2] = "int" ; 
			Tabela_temps[label3] = "int" ; 
			Tabela_temps[label4] = "int" ;
			 
			$$.traducao = "\n\t" + label1 + "=" + $3.traducao +";\n\t" + 
					       label2 + "=" + $5.traducao + ";\n\t" + 
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
						label3 + "=" + "!" + label3 + ";\n\t" +
						$2.traducao + "=" + $3.traducao + ";\n\t" +
					 "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " +
				 "if(" + label3 + ") goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n"+ 
			$9.traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" 
			+ "\t" + $2.traducao + "=" + $2.traducao + operador2 + $7.traducao +";\n\t" +
							label1 + "=" + $2.traducao + ";\n\t"+
					       label3 + "=" + label1 + operador + label2 + ";\n\t"+
					label3 + "=" + "!" + label3 + ";\n\tgoto iniloop" + std::to_string(pilha_loop[controle_loop])+					";\n\tfimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n";	
			
			--controle_loop;
		}
		|TK_FOR '(' FORARG1S ';' FORARG2S ';' FORARG3S ')' TK_DO COMANDOS TK_ENDLOOP
		{
			string label1 = genLabel();
			Tabela_temps[label1] = "int" ; 
			$$.traducao = $3.traducao + $5.traducao + "\t" + label1 + "= !" + $5.label + ";\n\t" + "iniloop" 				  + std::to_string(pilha_loop[controle_loop]) + ":" + 
				     + "if(" + label1 + ") goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n"
				     + $10.traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
				     $7.traducao +  $5.traducao + "\t" +label1 + "= !" + $5.label + ";\n\t"	
					+ "goto iniloop" + std::to_string(pilha_loop[controle_loop]) + 
					";\n\t" + "fimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n";
			--controle_loop;
		}

		;
DECLARATEMPFOR : TK_ID
				{
					pilha_escopo[numEscopo][$1.nome].tipo = "int";
					pilha_escopo[numEscopo][$1.nome].declarada = 1;
					pilha_escopo[numEscopo][$1.nome].valor_att = 1;
					pilha_escopo[numEscopo][$1.nome].nome = $1.nome;
					pilha_escopo[numEscopo][$1.nome].label = genLabel();

					$$.traducao = pilha_escopo[numEscopo][$1.nome].label;

					declaraVars[pilha_escopo[numEscopo][$1.nome].label] = pilha_escopo[numEscopo][$1.nome].tipo;
				}

FORARG1S :      FORARG1 ',' FORARG1S
	 	{
			$$.traducao = $1.traducao + $3.traducao;
		}
		|FORARG1
		{
			$$.traducao = $1.traducao;	
		}
FORARG1  :      DECLARACAO
	 	{
			$$.traducao = $1.traducao;
		}
	 	|
		ATRIBUICAO
		{
			$$.traducao = $1.traducao;
		};
FORARG2S :      FORARG2 ',' FORARG2S
	 	{
			$$.label    = genLabel();
			Tabela_temps[$$.label] = "bool"; 
			$$.traducao = $1.traducao + $3.traducao + "\t" + 
			$$.label + " = " + $1.label + " " + "&&" + " " + $3.label + ";\n";
			
		}
		|FORARG2
		{
			$$.traducao = $1.traducao;	
		}
FORARG2  :      E
	 	{
			$$.traducao = $1.traducao;
		}
	 	|
		{
			$$.traducao = "";
		};
FORARG3S :      FORARG3 ',' FORARG3S
	 	{
			$$.traducao = $1.traducao + $2.traducao;
		}
		|FORARG3
		{
			$$.traducao = $1.traducao;	
		}
FORARG3  :      ATRIBUICAO
	 	{
			$$.traducao = $1.traducao;
		}
	 	|
		{
			$$.traducao = "";
		};
WHILE   : TK_WHILE  E  TK_DO COMANDOS TK_ENDLOOP
		{
			string label1 = genLabel();
			Tabela_temps[label1] = "bool";
			
			$$.traducao = $2.traducao + "\t" + label1 + "= !" + $2.label + ";\n\t" +
						  "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " + "if(" + label1 + ")" + "goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t"+
						  $4.traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
						  $2.traducao + "\t" + label1 + "= !" + $2.label + ";\n\t" + "goto iniloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t" +
						  "fimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n" ;
			--controle_loop;
		};

DOWHILE : TK_DOWHILE  E  TK_DO COMANDOS TK_ENDLOOP
		{
			string label1 = genLabel();
			Tabela_temps[label1] = "bool";

			$$.traducao = label1 + "= 0" + ";\n\t" +
						  "iniloop" + std::to_string(pilha_loop[controle_loop]) + ": " + "if(" + label1 + ")" + "goto fimloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t"+
						  $4.traducao + "\tlabelcontinue"+ std::to_string(pilha_loop[controle_loop]) + ":\n" +
						  $2.traducao + "\t" + label1 + "= !" + $2.label + ";\n\t" + "goto iniloop" + std::to_string(pilha_loop[controle_loop]) + ";\n\t" +
						  "fimloop" + std::to_string(pilha_loop[controle_loop]) + ":\n" ;
			--controle_loop;
		};

DECLARACAO	: VARTIPO MULT_ID 
	   		{
				string aux = $2.traducao,var,translate = "";
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
						if($1.tipo != pilha_escopo[numEscopo][var].tipo && !var.empty()){
							if(isNumeric($1.tipo) && isNumeric(pilha_escopo[numEscopo][var].tipo))
								translate += "\t" + aux2[0] + "=" + "(" + $1.tipo + ")" + aux2[1] + ";\n";
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
						if($1.tipo == "string"){
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

					pilha_escopo[numEscopo][var].tipo = $1.tipo;

					if(pilha_escopo[numEscopo][var].declarada){
							yyerror("Variavel '" + var + "' já declarada");
					}
					else{
							pilha_escopo[numEscopo][var].nome = var;
							if(pilha_escopo[numEscopo][var].label == "") {
								pilha_escopo[numEscopo][var].label = genLabel();
							}
							pilha_escopo[numEscopo][var].declarada = 1;
							declaraVars[pilha_escopo[numEscopo][var].label] = pilha_escopo[numEscopo][var].tipo = $1.tipo;
					}
				}
				$$.traducao = translate;
			};

MULT_ID		: MULT_ID ',' MULT_ID
	 		{
				$$.traducao = $1.traducao + "," + $3.traducao;
			}
			|
			TK_ID '=' E 
			{
				string cast;
				int escopo = numEscopo;

				pilha_escopo[numEscopo][$1.nome].nome = $1.nome;
				pilha_escopo[numEscopo][$1.nome].valor_att = 1;
				pilha_escopo[numEscopo][$1.nome].label = genLabel();
				//pilha_escopo[numEscopo][$1.nome].declarada = 1;
				$1.label   = pilha_escopo[numEscopo][$1.nome].label;
				pilha_escopo[numEscopo][$1.nome].tipo = $3.tipo;
				declaraVars[pilha_escopo[numEscopo][$1.nome].label] = pilha_escopo[numEscopo][$1.nome].tipo;
				
				if($3.tipo == "string") pilha_escopo[numEscopo][$1.nome].str_init = 1;
				pilha_escopo[escopo][$1.nome].valor_att = 1;
				if($3.tipo != "string") $$.traducao = $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
				else{
						$$.traducao = $3.traducao + "\t" + $1.label + " = " + "(char*) malloc(" + $3.label_size_str + ");\n"+
						"\t" + "strcpy(" + $1.label + " , " + $3.label + ");\n";
						string label_size = pilha_escopo[escopo][$1.nome].label + "_size";
						Tabela_temps[label_size] = "int";
				}		
			}
			|TK_ID
			{	
				$$.traducao = $1.nome;
			};

VARTIPO     :TK_VARNUM
			{
				$$.traducao = "int";
				$$.tipo = "int";
			}
			|TK_VARFLOAT 
			{
				$$.traducao = "float";
				$$.tipo = "float";
			}
			|TK_VARCHAR
			{
				$$.traducao = "char";
				$$.tipo = "char";
			}
			|TK_VARBOOL
			{
				$$.traducao = "int";
				$$.tipo = "bool";
			}
			|TK_VARSTR
			{
				$$.traducao = "char*";
				$$.tipo = "string";
			}
			|TK_FUNCNONE
			{
				$$.traducao = "void";
				$$.tipo = "none";
			}
			;

ATRIBUICAO 	: TK_ID '=' E
			{	
				string cast;
				int escopo = getEscopo($1.nome);
				string label_size = pilha_escopo[escopo][$1.nome].label + "_size";

				if(escopo != -1){
					$1.label   = pilha_escopo[escopo][$1.nome].label;
					pilha_escopo[escopo][$1.nome].valor_att = 1;
					if(pilha_escopo[escopo][$1.nome].tipo != $3.tipo && pilha_escopo[escopo][$1.nome].tipo != ""){
						if(isNumeric(pilha_escopo[escopo][$1.nome].tipo) && 
						   isNumeric(Tabela_temps[$3.label])){
							cast = "(" + pilha_escopo[escopo][$1.nome].tipo + ") ";
						}
						else yyerror("Tipo diferente da declaração e cast não permitido ");
					}	
					else cast = "";
					//if($1.tipo == "") pilha_escopo[escopo][$1.nome].tipo = $3.tipo;
					pilha_escopo[escopo][$1.nome].valor_att = 1;
					if($3.tipo != "string") $$.traducao = $3.traducao + "\t" + $1.label + " = " + cast + $3.label + ";\n";
					else {
							string aux_aloca;

							if(pilha_escopo[escopo][$1.nome].str_init == 0){
								aux_aloca = "(char*) malloc(" + $3.label_size_str + ");\n";
							}
							else{
							 	pilha_escopo[escopo][$1.nome].str_init = 1;
							 	aux_aloca = "(char*) realloc(" + $1.label + "," + $3.label_size_str_realloc +");\n";
							}
							$$.traducao = $3.traducao + "\t" + $1.label + " = " + aux_aloca +
										"\t" + "strcpy(" + $1.label + " , " + $3.label + ");\n";
							Tabela_temps[label_size] = "int";
						}
				}
				else{
					yyerror("Variavel '" + $1.nome + "' não declarada");
				}
			}
			| TK_ID '=' TK_READ '(' ')'
			{
				int escopo = getEscopo($1.nome);

				string label1,label2,label3,label4,label5,label6,label7,label8,label9,label10,float_ou_int,cast;

				if(pilha_escopo[escopo][$1.nome].tipo == "int" || pilha_escopo[escopo][$1.nome].tipo == "float")
					float_ou_int = pilha_escopo[escopo][$1.nome].tipo == "int" ? "!":"";
				
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
					pilha_escopo[escopo][$1.nome].valor_att = 1;
					string label_size = pilha_escopo[escopo][$1.nome].label + "_size";
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

					if(pilha_escopo[escopo][$1.nome].tipo == "string"){

						string aux_aloca;

						$$.traducao = "\t" + label1 + " = " + "(char*) malloc(MAXSTR);\n";

						if(pilha_escopo[escopo][$1.nome].str_init == 0){
							aux_aloca = pilha_escopo[escopo][$1.nome].label + " = " + "(char*) malloc(MAXSTR);\n";
						}
						else{
							 pilha_escopo[escopo][$1.nome].str_init = 1;
							 aux_aloca = pilha_escopo[escopo][$1.nome].label + " = " + "(char*) realloc(" "," +"MAXSTR);\n";
						}
						$$.traducao += "\tstd::cin >> " + label1 + ";\n"
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
									+ "\t" + (pilha_escopo[escopo][$1.nome].str_init == 0 ? 
											 (pilha_escopo[escopo][$1.nome].label + " = " + "(char*) malloc(" + label10 + ");\n" ):
											 (pilha_escopo[escopo][$1.nome].label + " = " + "(char*) realloc(" + pilha_escopo[escopo][$1.nome].label + "," + label10 + ");\n"))
									+ "\t" + "strcpy(" + pilha_escopo[escopo][$1.nome].label + "," + label1 + ");\n"
									+ "\t" + "free(" + label1 + ");\n";


					}
					else if(pilha_escopo[escopo][$1.nome].tipo == "char"){
						$$.traducao = "\tstd::cin >> " + pilha_escopo[escopo][$1.nome].label + ";\n\t"
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
						$$.traducao = "\tstd::cin >> " + label4 + ";\n\t"
									+ label1 + "=" + "std::cin.fail()" + ";\n\t" 
									+ label1 + "=" + " !" + label1 + ";\n\t"
									+ label2 + "=" + label4 + "!=" + "(int) " + label4 +";\n\t" 
									+ label3 + "=" + float_ou_int + label2 + ";\n\t"
									+ label3 + "=" + label3 + "&&" + label1  + ";\n\t"
									+ "if(" + label3 +") goto fimif" + std::to_string(contif)+";\n\t\t"
									+ "std::cout << \"Erro de leitura, verifique o tipo declarado e tipo inserido\";\n" + "\n\t\t"
									+ "exit(0);\n\t"
									+ "fimif" + std::to_string(contif) + ":\n\t"
									+ pilha_escopo[escopo][$1.nome].label + "=" +  cast + label4 + ";\n";
					}
						contif++;
				}
				else{
					yyerror("Variavel '" + $1.nome + "' não declarada");
				}

			}|TK_ID TK_OPCOMPOSTO E 
			{
				string label1,label2;
				string cast;

				int escopo = getEscopo($1.nome);

				label1 = genLabel();
				label2 = genLabel();
				Tabela_temps[label1] = pilha_escopo[escopo][$1.nome].tipo;
				Tabela_temps[label2] = pilha_escopo[escopo][$1.nome].tipo;

				if(!pilha_escopo[escopo][$1.nome].valor_att) yyerror("A variavel '" + $1.nome + "' não possui valor atribuido e por isso não pode ser (de/in)crementada");

				if(escopo != -1){
					$1.label   = pilha_escopo[escopo][$1.nome].label;
					if(pilha_escopo[escopo][$1.nome].tipo != $3.tipo && pilha_escopo[escopo][$1.nome].tipo != ""){
						if(isNumeric(pilha_escopo[escopo][$1.nome].tipo) && 
						   isNumeric(Tabela_temps[$3.label])){
							cast = "(" + pilha_escopo[escopo][$1.nome].tipo + ") ";
						}
						else yyerror("Tipo diferente da declaração e cast não permitido ");
					}	
					else cast = "";

					$$.traducao = $3.traducao + "\t" + label1 + " = " + cast + $3.label + ";\n"
								+ "\t" + label2   + " = " + $1.label + $2.traducao + label1 + ";\n"
								+ "\t" + $1.label + " = " + label2 + ";\n";
				}
				else{
					yyerror("Variavel '" + $1.nome + "' não declarada");
				}

			}|TK_ID TK_OPUNARIO 
			{
				string label1,label2;

				int escopo = getEscopo($1.nome);

				label1 = genLabel();
				label2 = genLabel();
				Tabela_temps[label1] = pilha_escopo[escopo][$1.nome].tipo;
				Tabela_temps[label2] = pilha_escopo[escopo][$1.nome].tipo;
				
				if(!pilha_escopo[escopo][$1.nome].valor_att) yyerror("A variavel '" + $1.nome + "' não possui valor atribuido e por isso não pode ser (de/in)crementada");
				
				if(escopo != -1){
					$1.label   = pilha_escopo[escopo][$1.nome].label;
					if(!isNumeric(pilha_escopo[escopo][$1.nome].tipo) ){
						yyerror("Operador unário definido somente para numeros ");
					}
					$$.traducao = "\t" + label1 + " = " + ($1.tipo == "int" ? "1":"1.0") + ";\n"
								+ "\t" + label2 + " = " + $1.label + $2.traducao + label1 + ";\n"
								+ "\t" + $1.label + " = " + label2 + ";\n";
				}
				else{
					yyerror("Variavel '" + $1.nome + "' não declarada");
				}
			}
			;

CHAMAFUNC   : TK_ID '(' ARGES ')'
			  {
			  	int error = 0;
			  	string aux = $3.tipo;
			  	vector<string> params,param_aux;
				string args = "";
				boost::split(params,aux,boost::is_any_of(","));

			  	if(funcs_info.find($1.nome) == funcs_info.end()){
			  		yyerror("Esta função não está definida");
			  	}

			  	for (int i = 0; i < params.size() ; i++)
			  	{
					if(funcs_info[$3.nome].tipo_params[i] != params[i]){
						yyerror("Tipo do parâmetro passado diferente do definido");
						error = 1;
					}

			  	}
			  	if(!error){
				  	$$.traducao = $3.traducao + "\t" + funcs_info[$1.nome].label + "(" + $3.label + ");\n";
				  	$$.tipo = funcs_info[$1.nome].tipo;
				  	$$.nome = $1.nome;
				}
			  };
ARGES		: E ARGE
			{
				$$.traducao = $1.traducao + $2.traducao;
				$$.label = $1.label + "," + $2.label;
				$$.tipo = $1.tipo + "," + $2.tipo;
			}
			|{$$.traducao = "";}
			;
ARGE 		: ',' E ARGES
			{
				$$.traducao = $2.traducao;
				$$.label = $2.label;
				$$.tipo = $2.tipo;
			}
			;

DECLARAFUNC : TK_FUNC VARTIPO TK_ID '(' ARGSFUNCS ')' TK_INITFUNC COMANDOS TK_RETURN E ';' TK_ENDFUNC
			  {
			  	if(funcs_info.find($3.nome) != funcs_info.end()){
			  		yyerror("Esta função já está definida");
			  	}
			  	else if($2.tipo != $10.tipo && $2.tipo != "none"){
			  		yyerror("Tipo de retorno diferente da declaração");
			  		$$.tipo = "invalid";
			  	}
			  	else{

				  	funcs_info[$3.nome].tipo = $2.tipo;
				  	funcs_info[$3.nome].nome = $3.nome;
				  	funcs_info[$3.nome].label = genLabel() + "_func";
				  	funcs_info[$3.nome].label_return = $10.label;
				  	string aux = $5.traducao;
					vector<string> params,param_aux;
					string args = "";
					boost::split(params,aux,boost::is_any_of(","));
					for(int i = 0; i < params.size() ; i++){
						boost::split(param_aux,params[i],boost::is_any_of(":"));
						args += param_aux[0] + " " + param_aux[1] + (i + 1 == params.size() ? "":",");
						funcs_info[$3.nome].tipo_params.push_back((param_aux[0] == "char*" ? "string":param_aux[0] == "bool" ? "int":param_aux[0]));
						funcs_info[$3.nome].vars_params.push_back(param_aux[1]);
					}

					FUNCS += $2.traducao + " " + funcs_info[$3.nome].label + "(" + args +"){\n"
					+		$8.traducao + $10.traducao +"\treturn " + ($2.tipo != "none" ? $10.label:"") + ";\n}\n";
				  	
				  	$$.traducao = "";

				}
			  }
			  ;

ARGSFUNCS    : 	VARTIPO TK_ATTFUNC TK_ID ARGFUNC
				{
					
					string nome  = $3.nome;
					pilha_escopo[numEscopo][nome].nome  	= nome;
					pilha_escopo[numEscopo][nome].label 	= genLabel();
					pilha_escopo[numEscopo][nome].declarada = 1;
					pilha_escopo[numEscopo][nome].tipo 		= $1.tipo;
					
					$$.traducao = $1.traducao + ":" + pilha_escopo[numEscopo][nome].label + $4.traducao;
				}
				|
				{
					$$.traducao = "";
				};

ARGFUNC    	  :	',' VARTIPO TK_ATTFUNC TK_ID ARGSFUNCS
				{
					string nome  = $4.nome;
					pilha_escopo[numEscopo][nome].nome  	= nome;
					pilha_escopo[numEscopo][nome].label 	= genLabel();
					pilha_escopo[numEscopo][nome].declarada = 1;
					pilha_escopo[numEscopo][nome].tipo 		= $2.tipo;
					
					
					$$.traducao = "," + $2.traducao + ":" + pilha_escopo[numEscopo][nome].label;
				};

CONCAT		:	TK_STRCAT '(' TK_ID ',' E ',' E ')' ';'
				{
					int escopo1 = $5.traducao == "" ? getEscopo($5.nome):-2;
					int escopo2 = $7.traducao == "" ? getEscopo($7.nome):-2;
					
					if($5.tipo != "string" || $7.tipo != "string"){
						yyerror("Operação permitida somente para strings");
					}
					if((($5.traducao == "" && !pilha_escopo[escopo1][$5.nome].valor_att)
					|| ($7.traducao == "" && !pilha_escopo[escopo1][$7.nome].valor_att))
						&& (escopo1 != -2 && escopo2 != -2)
					){
						yyerror("Impossivel concatenar string com variaveis não inicializadas");
					}
					if(getEscopo($3.nome) == -1){
						yyerror("Varivel '" + $3.nome + "' não declarada");
					}
					else if(pilha_escopo[getEscopo($3.nome)][$3.nome].tipo != "string"){
						yyerror("Operação permitida apenas entre strings");
					}
					else{
						string tamanho1 = $5.traducao == "" ? pilha_escopo[getEscopo($5.nome)][$5.nome].label + "_size":$5.label_len ;
						string tamanho2 = $7.traducao == "" ? pilha_escopo[getEscopo($7.nome)][$7.nome].label + "_size":$7.label_len ;
						int escopo = getEscopo($3.nome);
						string label_size = pilha_escopo[escopo][$3.nome].label + "_size";
						string label_size2 = genLabel();
						Tabela_temps[label_size2] = "int";
						Tabela_temps[label_size] = "int";
						string m_or_r;
						
						if(!pilha_escopo[escopo][$3.nome].valor_att){
								m_or_r = pilha_escopo[escopo][$3.nome].label + " = " + "(char*) malloc(" + label_size2 + ");\n";
						}
						else{
								 m_or_r = "(char*) realloc(" + pilha_escopo[escopo][$3.nome].label + 
								 			"," + label_size2 + ");\n" ;
						} 
						$$.traducao = $5.traducao + $7.traducao + 
						"\t" + label_size + " = " + tamanho1 + " + " + tamanho2 + ";\n"
					+	"\t" + label_size2 + " = " + "sizeof(char) * " + label_size + ";\n"
					+   "\t" + m_or_r
					+	"\t" + "strcat(" + pilha_escopo[escopo][$3.nome].label + "," + ($5.traducao == "" ? pilha_escopo[getEscopo($5.nome)][$5.nome].label:$5.label) + ");\n"
					+   "\t" + "strcat(" + pilha_escopo[escopo][$3.nome].label + "," + ($7.traducao == "" ? pilha_escopo[getEscopo($7.nome)][$7.nome].label:$7.label) + ");\n";

					}
				};

PRINT 		: TK_PRINT '(' ARGPRINTS ')' ';'
			{
				$$.traducao = $3.traducao + "\tstd::cout << std::endl ;\n";
			}
			| TK_PRINT '(' ARGPRINTS ';' TK_SEPARA_PRINT '=' TK_CHAR ')' ';'
			{
				$$.traducao = $3.traducao + "\tstd::cout << " + $7.traducao + " ;\n";
			}
			;

ARGPRINTS   : ARGPRINT ',' ARGPRINTS
			{
				$$.traducao = $1.traducao;
				$$.traducao += "\tstd::cout<<" + $1.label + ";\n";
				$$.traducao += $3.traducao;
			}
			| ARGPRINT
			{
				$$.traducao = $1.traducao ;
				$$.traducao += "\tstd::cout<<" + $1.label + ";\n"; 
			}
			;
ARGPRINT    : E
			{
				$$.traducao = $1.traducao;
				if($1.label == "none") yyerror("Você tentou imprimir algo do tipo None e isso não é possivel");
			}

E 			: E '+' E
			{
				$$ = initExpressao($1,$3,"+",ARITMETICA_CONV);
			}
			| E '-' E
			{
				$$ = initExpressao($1,$3,"-",ARITMETICA_CONV);
			}
			| E '*' E
			{
				$$ = initExpressao($1,$3,"*",ARITMETICA_CONV);
			}
			| E '/' E
			{
				$$ = initExpressao($1,$3,"/",ARITMETICA_CONV);
			}
			| E TK_EXP E
			{
				if(!isNumeric($1.tipo) || !isNumeric($2.tipo)){
					yyerror("Operação permitida somente com numeros");
				}
				else if($3.tipo != "int"){
					yyerror("Somente expoentes inteiros");
				}
				else{

					$$.label = genLabel();
					string label1 = genLabel();
					string label2 = genLabel();
					string label3 = genLabel();
					string label4 = genLabel();
					string label5 = genLabel();
					string label6 = genLabel();
					string label7 = genLabel();
					string label8 = genLabel();
					Tabela_temps[$$.label] = $1.tipo == "int" ? "int":"float";
					Tabela_temps[label7] = $1.tipo == "int" ? "int":"float";
					Tabela_temps[label1] =  "int";
					Tabela_temps[label2] =  "int";
					Tabela_temps[label3] =  "int";
					Tabela_temps[label4] =  "int";
					Tabela_temps[label5] =  "int"; 
					Tabela_temps[label6] =  "int";
					Tabela_temps[label8] =  "int";

					$$.traducao = $1.traducao + $3.traducao + 
							   "\t" + label1 + " = " + "1;\n\t"
							   		+ label8 + " = " + "1;\n\t"
									+ label7 + " = " + $1.label + ";\n\t"
									+ label2 + " = " + label1 + " < " + $3.label + ";\n\t"
									+ label3 + " = " + "!" + label2 + ";\n\t"
					+ "iniforNuser" + std::to_string(contforNAOuser) + ": if(" + label3 + ") goto fimforNuser" + std::to_string(contforNAOuser) + ";\n\t" 
									+ label5 + " = " + label7 + " * " + $1.label+ ";\n\t"
									+ label7 + " = " + label5 + ";\n\t"
									+ label8 + " = " + label7 + ";\n\t"
									+ label6   + " = " + "1;\n\t"
									+ label1 + " = " + label1 + " + " + label6 + ";\n\t"
									+ label2 + " = " + label1 + " < " + $3.label + ";\n\t"
									+ label3 + " = " + "!" + label2 + ";\n\t"
									+ "goto iniforNuser" + std::to_string(contforNAOuser) + ";\n\t"
									+ "fimforNuser" + std::to_string(contforNAOuser) + ":\n"
					"\t" + $$.label + " = " + label8 + ";\n";
					++contforNAOuser;
				}
			}
			| '(' E ')'
			{ 
				$$.label = $2.label;
				$$.tipo = $2.tipo;
				Tabela_temps[$$.label] = $2.tipo ; 
				$$.traducao = $2.traducao;
			}
			| E TK_AND E
			{
				$$ = initExpressao($1,$3,"&&",LOGICA_CONV);
			}
			| E TK_OR E
			{
				$$ = initExpressao($1,$3,"||",LOGICA_CONV);
			}
			| TK_NOT E
			{
				$$.label    = genLabel();
				Tabela_temps[$$.label] = $2.tipo ; 
				$$.traducao = "\t" + $$.label + " = !" + $1.traducao + ";\n";
			}
			| E '<' E
			{
				$$ = initExpressao($1,$3,"<",RELACIONAL_CONV);
			}
			| E '>' E
			{
				$$ = initExpressao($1,$3,">",RELACIONAL_CONV);
			}
			| E TK_MAIOR_EQ E
			{
				$$ = initExpressao($1,$3,">=",RELACIONAL_CONV);
			}
			| E TK_MENOR_EQ E
			{
				$$ = initExpressao($1,$3,"<=",RELACIONAL_CONV);
			}
			| E TK_IGUAL2 E
			{
				$$ = initExpressao($1,$3,"==",RELACIONAL_CONV_COMP);
			}
			| E TK_DIFERENTE E
			{
				$$ = initExpressao($1,$3,"!=",RELACIONAL_CONV_COMP);
			}
			| VARTIPO '(' E ')'
			{
				$$.label = genLabel();
				$$.tipo = $1.traducao;
				Tabela_temps[$$.label] = $$.tipo;
				$$.traducao = $3.traducao + "\t" + $$.label + " = (" + $1.traducao + ") " + $3.label + ";\n";
			}
			|CHAMAFUNC
			{
				$$.traducao = $1.traducao;
				if($1.tipo != "none" && $1.tipo != "invalid"){
					$$.label = genLabel();
					Tabela_temps[$$.label] = $1.tipo;
					$$.traducao += "\t" + $$.label + " = " + funcs_info[$1.nome].label_return + ";\n";
				}
				else{$$.label = "none";}
			}
			|TK_NONE
			{
				
				$$.label = genLabel();
				Tabela_temps[$$.label] = "int";
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}
			| TK_NUM
			{
				$$.label    = genLabel();
				Tabela_temps[$$.label] = $$.tipo ; 
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}
			|TK_FLOAT
			{
				$$.label    = genLabel();
				Tabela_temps[$$.label] = $$.tipo;
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}
			|TK_BOOL
			{
				$$.label    = genLabel();
				Tabela_temps[$$.label] = $$.tipo;
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}
			|TK_CHAR
			{
				$$.label    = genLabel();
				Tabela_temps[$$.label] = $$.tipo;
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}
			|TK_STRING
			{
				$$.label = genLabel();
				string label1 = genLabel();
				string label2 = genLabel() + "_size";
				string label3 = genLabel();
				string label4 = genLabel();
				Tabela_temps[label1] = "int";
				Tabela_temps[label2] = "int";
				Tabela_temps[label3] = "int";
				Tabela_temps[label4] = "int";
				Tabela_temps[$$.label] = $$.tipo;
				$$.label_size_str = label4;
				$$.label_size_str_realloc = label4;
				$$.label_len = label2;
				$$.traducao = "\t" + label1 + " = " + "sizeof(char)" + ";\n"+
										 	"\t" + label2 + " = " + std::to_string($1.traducao.size()) + ";\n" + 
										 	"\t" + label3 + " = " + label1 + " * "+ label2 + ";\n"+
										 	"\t" + label4 + " = " + label3 + ";\n";
				$$.traducao += "\t" + $$.label + " = " + "(char*) " + "malloc(" + label4 + " );\n" +  
				"\t" + "strcpy(" + $$.label + ", " + "\"" + $1.traducao + "\"" + ");\n";
			}
			|TK_GLOBAL TK_ID
			{
				if(pilha_escopo[GLOBAL][$2.nome].declarada == 0) 
						yyerror(
							"Variavel '"
							+ $1.nome
							+ "'" + " não está declarada no escopo global"
							);
				$$.traducao = "";
				$$.label = pilha_escopo[GLOBAL][$2.nome].label;
				$$.nome  = pilha_escopo[GLOBAL][$2.nome].nome;
			}
			|TK_NOLOCAL TK_ID '(' TK_NUM ')'
			{
				int escopo = -1;
				
				if(atoi($4.traducao.c_str()) < 0 ) yyerror("Não é permitido numero negativo como parâmetro ");
				else escopo = numEscopo - atoi($4.traducao.c_str());
				
				if(escopo < 0 ) yyerror("Impossivel acessar mais escopos do que existem, tente um numero menor ");
				//cout << $2.nome << " ainda cria\n";
				if(pilha_escopo[escopo][$2.nome].declarada == 0) 
						yyerror(
							"Variavel '"
							+ $2.nome
							+ "'" + " não foi declarada" + "no escopo passado como parâmetro"
							);
				if(escopo >= 0){
					$$.traducao = "";
					$$.label = pilha_escopo[escopo][$2.nome].label;
					$$.nome  = pilha_escopo[escopo][$2.nome].nome;
				}
			}
			|TK_NOLOCAL TK_ID
			{
				int escopo;
				for(escopo = numEscopo - 1; escopo >= 0 ; escopo--){
					if((pilha_escopo[escopo]).find($2.nome) != (pilha_escopo[escopo]).end()) break;
				}

				if(escopo >= 0){
					$$.traducao = "";
					$$.label = pilha_escopo[escopo][$2.nome].label;
					$$.nome  = pilha_escopo[escopo][$2.nome].nome;
				}
				else yyerror("Variavel '" + $2.nome + "' não foi declarada fora do escopo atual");
			}
			| TK_ID
			{
				int escopo = getEscopo($1.nome);
				if(escopo == -1 || pilha_escopo[escopo][$1.nome].declarada == 0) 
						yyerror(
							"Variavel '"
							+ $1.nome
							+ "'" + "não foi declarada"
							);
				else{
					$$.traducao = "";
					$$.label = pilha_escopo[escopo][$1.nome].label;
					$$.nome  = pilha_escopo[escopo][$1.nome].nome;
				}

			}
			;


%%

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
