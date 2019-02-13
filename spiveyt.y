%{
/* 
Definitions of constants, variables, & function prototypes go here 
*/



#include <stdio.h>

int numLines = 0;
void printRule(const char *, const char *);
int yyerror(const char *s);
void printTokenInfo(const char* tokenType, const char* lexeme);

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}

/* Token declarations */
%token T_IDENT T_INTCONST T_UNKNOWN T_FLOATCONST T_IF
%token T_WHILE T_FUNCTION T_FOR T_IN T_NEXT
%token T_BREAK T_TRUE T_FALSE T_QUIT T_PRINT T_CAT
%token T_READ T_LIST T_STRCONST T_ADD T_SUB T_MULT
%token T_DIV T_MOD T_POW T_LT T_GT T_LE T_GE T_EQ
%token T_NE T_NOT T_AND T_OR T_ASSIGN T_SEMICOLON
%token T_COMMA T_LPAREN T_LBRACE T_RBRACE
%token T_LBRACKET T_RBRACKET T_COMMENT T_POUND
%nonassoc T_RPAREN
%nonassoc T_ELSE
/* Starting point */
%start		N_START

/* Translation rules */
%%
N_START		: N_EXPR
			{
			printRule("START", "EXPR");
			printf("\n---- Completed parsing ----\n\n");
			return 0;
			}
			;

N_EXPR		: N_IF_EXPR
			{
			printRule("EXPR", "I");
			}
                | N_WHILE_EXPR
                {
			printRule("EXPR", "WHILE");
			}
                | N_FOR_EXPR
                {
			printRule("EXPR", "FOR");
			}
		| N_COMPOUND_EXPR
		{
			printRule("EXPR", "COMPOUND");
			}
		| N_ARITHLOGIC_EXPR
		{
			printRule("EXPR", "ARITHLOGIC");
			}
		| N_ASSIGNMENT_EXPR
		{
			printRule("EXPR", "ASSIGNMENT");
			}
		| N_OUTPUT_EXPR
		{
			printRule("EXPR", "OUTPUT");
			}
		| N_INPUT_EXPR
		{
			printRule("EXPR", "INPUT");
			}			
		| N_LIST_EXPR
		{
			printRule("EXPR", "LIST);
			}			
		| N_FUNCTION_DEF
		{
			printRule("EXPR", "FUNCTION");
			}			
		| N_FUNCTION_CALL
		{
			printRule("EXPR", "FUNCTION CALL");
			}			
		| N_QUIT_EXPR
		{
			printRule("EXPR", "QUIT");
			}
			;			
N_CONST		: T_INTCONST
		{
			printRule("CONST", "INTCONST");
			}			
		| T_STRCONST
		{
			printRule("CONST", "STRCONST");
			}
		| T_FLOATCONST
		{
			printRule("CONST", "FLOATCONST");
			}
		| T_TRUE
		{
			printRule("CONST", "TRUE");
			}
		| T_FALSE
		{
			printRule("CONST", "FALSE");
			}	
			;
N_COMPOUND_EXPR	: T_LBRACKET N_EXPR N_EXPR_LIST T_RBRACKET
		{
			printRule("COMPOUND_EXPR", "LBRACKET EXPR EXPR_LIST RBRACKET ");
			}
			;
N_EXPR_LIST	: T_SEMICOLON N_EXPR N_EXPR_LIST
		{
			printRule("EXPR_LIST", "SEMICOLON EXPR EXPR_LIST");
			}
		| /*epsilon*/
		{
			printRule("EXPR_LIST", "EPSILON");
			}
			;
N_IF_EXPR	: T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR
		{
			printRule("IF_EXPR", "IF LPAREN EXPR RPAREN EXPR");
			}
			;
		| T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR T_ELSE N_EXPR
		{
			printRule("IF_EXPR", "IF LPAREN EXPR RPAREN EXP ELSE EXPR");
			}
N_WHILE_EXPR	: T_WHILE T_LPAREN N_EXPR T_RPAREN N_LOOP_EXPR
		{
			printRule("WHILE", "WHILE LPAREN EXPR RPAREN LOOP_EXPR");
			}
			;
N_FOR_EXPR	: T_FOR T_LPAREN T_IDENT T_IN N_EXPR T_RPAREN N_LOOP_EXPR
		{
			printRule("FOR_EXPR", "FOR LPAREN IDENT IN EXPR RPAREN LOOP");
			}
			;
N_LOOP_EXPR	: N_EXPR
		{
			printRule("LOOP_EXPR", "EXPR");
			}
		| N_BREAK_EXPR
		{
			printRule("LOOP_EXPR", "BREAK");
			}
		| N_NEXT_EXPR
		{
			printRule("LOOP_EXPR", "NEXT");
			}
			;			
N_BREAK_EXPR	: T_BREAK
		{
			printRule("LOOP_EXPR", "BREAK");
			}
			;
N_NEXT_EXPR	: T_NEXT
		{
			printRule("NEXT_EXPR", "NEXT");
			}	
			;
N_LIST_EXPR   	: T_LIST T_LPAREN N_CONST_LIST T_RPAREN
			{
			printRule("LIST_EXPR", "LIST LPAREN CONST_LIST RPAREN");
			}
			;
N_CONST_LIST	: N_CONST T_COMMA N_CONST_LIST
		{
			printRule("CONST_lIST", "CONST COMMA CONST_LIST");
			}
		| N_CONST
		{
			printRule("CONST_LIST", "CONST");
			}		
			;
N_ASSIGNMENT_EXPR : T_IDENT N_INDEX T_ASSIGN N_EXPR
			{
			printRule("ASSIGNMENT_EXPR", "IDENT INDEX ASSIGN EXPR");
			}
			;
N_INDEX		: T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
			{
			printRule("INDEX", "LBRACKET LBRACKET EXPR RBRACKET RBRACKET");
			}
		| /*EPSILON*/	
			{
			printRule("INDEX",
                          "EPSILON");
			}		
			;
N_QUIT_EXPR 	: T_QUIT T_LPAREN T_RPAREN
			{
			printRule("QUIT_EXPR", "QUIT LPAREN RPAREN");
			}
			;	
N_OUTPUT_EXPR 	: T_PRINT T_LPAREN N_EXPR T_RPAREN
			{
			printRule("OUTPUT_EXPR", "PRINT LPAREN EXPR RPAREN");
			}		
		 | T_CAT T_LPAREN N_EXPR T_RPAREN
			{
			printRule("OUTPUT_EXPR", "CAT LPAREN EXPR RPAREN");
			}
			;	
N_INPUT_EXPR 	: T_READ T_LPAREN N_VAR T_RPAREN
			{
			printRule("INPUT_EXPR", "READ LPAREN VAR RPAREN");
			}
			;	
N_FUNCTION_DEF 	: T_FUNCTION T_LPAREN N_PARAM_LIST T_RPAREN N_COMPOUND_EXPR
			{
			printRule("FUNCTION_DEF", "FUNCTION LPAREN PARAM_LIST RPAREN COMPOUND_EXPR");
			}
			;
N_PARAM_LIST 	: N_PARAMS
		{
			printRule("PARAM_LIST", "PARAMS");
			}		
		 | N_NO_PARAMS
			{
			printRule("PARAM_LIST", "NO_PARAMS");
			}
			;	
N_NO_PARAMS 	: /*EPSILON*/
			{
			printRule("NO_PARAMS", "EPSILON");
			}
			;	
N_PARAMS 	: T_IDENT
		{
			printRule("PARAMS", "IDENT");
			}		
		 | T_IDENT T_COMMA N_PARAMS
			{
			printRule("PARAMS", "IDENT COMMA PARAMS");
			}
			;		
N_FUNCTION_CALL : T_IDENT T_LPAREN N_ARG_LIST T_RPAREN
			{
			printRule("FUNCTION_CALL", "IDENT LPAREN ARG_LIST RPAREN");
			}
			;	
N_ARG_LIST 	: N_ARGS
		{
			printRule("ARG_LIST", "ARGS");
			}		
		 | N_NO_ARGS
			{
			printRule("ARG_LIST", "NO_ARGS");
			}
			;	
N_NO_ARGS 	: /*EPSILON*/
			{
			printRule("NO_ARGS", "EPSILON");
			}
			;
N_ARGS		: N_EXPR
		{
			printRule("ARGS", "EXPR");
			}		
		 | N_EXPR T_COMMA N_ARGS
			{
			printRule("ARGS", "EXPR COMMA ARGS");
			}
			;	
N_ARITHLOGIC_EXPR	: N_SIMPLE_ARITHLOGIC
			{
			printRule("ARITHLOGIC_EXPR", "SIMPLE_ARITHLOGIC");
			}		
		 | N_SIMPLE_ARITHLOGIC N_REL_OP N_SIMPLE_ARITHLOGIC
			{
			printRule("ARITHLOGIC_EXPR", "SIMPLE_ARITHLOGIC REL_OP SIMPLE_ARITHLOGIC");
			}
			;			
N_SIMPLE_ARITHLOGIC 	: N_TERM N_ADD_OP_LIST
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_ADD_OP_LIST	: N_ADD_OP N_TERM N_ADD_OP_LIST
		{
			printRule("ADD_OP_LIST", "ADD_OP TERM ADD_OP_LIST");
			}		
		 | /*EPSILON*/
			{
			printRule("ADD_OP_LIST", "EPSILON");
			}
			;	
N_TERM	 	: N_FACTOR N_MULT_OP_LIST
			{
			printRule("TERM", "FACTOR MULT_OP_LIST");
			}
			;
N_MULT_OP_LIST	: N_MULT_OP N_FACTOR N_MULT_OP_LIST
		{
			printRule("MULT_OP_LIST", "MULT_OP FACTOR MULT_OP_LIST");
			}		
		 | /*EPSILON*/
			{
			printRule("MULT_OP_LIST", "EPSILON");
			}
			;	
N_FACTOR	: N_VAR
		{
			printRule("FACTOR", "VAR");
			}		
		 | N_CONST
			{
			printRule("FACTOR", "CONST");
			}
		 | T_LPAREN N_EXPR T_RPAREN
			{
			printRule("FACTOR", "LPAREN EXPR RPAREN");
			}
		 | T_NOT N_FACTOR
			{
			printRule("FACTOR", "FACTOR");
			}
			;	
N_ADD_OP	: T_ADD
		{
			printRule("ADD_OP", "ADD");
			}		
		 | T_SUB
			{
			printRule("ADD_OP", "SUB");
			}
		 | T_OR
			{
			printRule("ADD_OP", "OR");
			}
			;	
N_MULT_OP	: T_MULT
		{
			printRule("MULT_OP", "MULT");
			}		
		 | T_DIV
			{
			printRule("MULT_OP", "DIV");
			}
		 | T_AND
			{
			printRule("MULT_OP", "AND");
			}
		 | T_MOD
			{
			printRule("MULT_OP", "MOD");
			}
		 | T_POW
			{
			printRule("MULT_OP", "POW");
			}			
			;	
N_REL_OP	: T_LT
		{
			printRule("REL_OP", "LT");
			}		
		 | T_GT
			{
			printRule("REL_OP", "GT");
			}
		 | T_LE
			{
			printRule("REL_OP", "LE");
			}
		 | T_GE
			{
			printRule("REL_OP", "GE");
			}
		 | T_EQ
			{
			printRule("REL_OP", "EQ");
			}
		 | T_NE
			{
			printRule("REL_OP", "NE");
			}				
			;	
N_VAR		: N_ENTIRE_VAR
		{
			printRule("VAR", "ENTIRE_VAR");
			}		
		 | N_SINGLE_ELEMENT
			{
			printRule("VAR", "SINGLE_ELEMENT");
			}
			;	
N_SINGLE_ELEMENT	: T_IDENT T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
			{
			printRule("SINGLE_ELEMENT", "IDENT LBRACKET LBRACKET EXPR RBRACKET RBRACKET");
			}		
			;	
N_ENTIRE_VAR	: T_IDENT
			{
			printRule("ENTIRE_VAR", "IDENT");
			}		
			;			
%%

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs) 
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s) 
{
  printf("%s\n", s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme) 
{
  printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

int main() 
{
  do 
  {
	yyparse();
  } while (!feof(yyin));

  printf("%d lines processed\n", numLines);
  return(0);
}
