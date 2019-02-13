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
			printRule("IF_EXPR", "IF_EXPR IF");
			}
                | N_WHILE_EXPR
                {
			printRule("N_WHILE_EXPR", "WHILE_EXPR WHILE");
			}
                | N_FOR_EXPR
                {
			printRule("EXPR", 
				    "foo IDENT_LIST INTCONST_LIST");
			}
		| N_COMPOUND_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| N_ARITHLOGIC_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| N_ASSIGNMENT_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| N_OUTPUT_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| N_INPUT_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}			
		| N_LIST_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}			
		| N_FUNCTION_DEF
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}			
		| N_FUNCTION_CALL
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}			
		| N_QUIT_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;			
N_CONST		: T_INTCONST
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}			
		| T_STRCONST
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| T_FLOATCONST
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| T_TRUE
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| T_FALSE
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}	
			;
N_COMPOUND_EXPR	: T_LBRACKET N_EXPR N_EXPR_LIST T_RBRACKET
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;
N_EXPR_LIST	: T_SEMICOLON N_EXPR N_EXPR_LIST
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| /*epsilon*/
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;
N_IF_EXPR	: T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;
		| T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR T_ELSE N_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
N_WHILE_EXPR	: T_WHILE T_LPAREN N_EXPR T_RPAREN N_LOOP_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;
N_FOR_EXPR	: T_FOR T_LPAREN T_IDENT T_IN N_EXPR T_RPAREN N_LOOP_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;
N_LOOP_EXPR	: N_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| N_BREAK_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
		| N_NEXT_EXPR
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;			
N_BREAK_EXPR	: T_BREAK
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}
			;
N_NEXT_EXPR	: T_NEXT
		{
			printRule("COMMPOUND", "COMPOUND EXPR");
			}	
			;
N_LIST_EXPR   	: T_LIST T_LPAREN N_CONST_LIST T_RPAREN
			{
			printRule("IDENT_LIST", "epsilon");
			}
			;
N_CONST_LIST	: N_CONST T_COMMA N_CONST_LIST
		{
			printRule("IDENT_LIST", "IDENT_LIST IDENT");
			}
		| N_CONST
		{
			printRule("IDENT_LIST", "IDENT_LIST IDENT");
			}		
			;
N_ASSIGNMENT_EXPR : T_IDENT N_INDEX T_ASSIGN N_EXPR
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;
N_INDEX		: T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
			{
			printRule("INTCONST_LIST",
                          "INTCONST_LIST INTCONST");
			}
		| /*EPSILON*/	
			{
			printRule("INTCONST_LIST",
                          "INTCONST_LIST INTCONST");
			}		
			;
N_QUIT_EXPR 	: T_QUIT T_LPAREN T_RPAREN
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_OUTPUT_EXPR 	: T_PRINT T_LPAREN N_EXPR T_RPAREN
			{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | T_CAT T_LPAREN N_EXPR T_RPAREN
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_INPUT_EXPR 	: T_READ T_LPAREN N_VAR T_RPAREN
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_FUNCTION_DEF 	: T_FUNCTION T_LPAREN N_PARAM_LIST T_RPAREN N_COMPOUND_EXPR
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;
N_PARAM_LIST 	: N_PARAMS
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | N_NO_PARAMS
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_NO_PARAMS 	: /*EPSILON*/
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_PARAMS 	: T_IDENT
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | T_IDENT T_COMMA N_PARAMS
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;		
N_FUNCTION_CALL : T_IDENT T_LPAREN N_ARG_LIST T_RPAREN
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_ARG_LIST 	: N_ARGS
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | N_NO_ARGS
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_NO_ARGS 	: /*EPSILON*/
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;
N_ARGS		: N_EXPR
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | N_EXPR T_COMMA N_ARGS
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_ARITHLOGIC_EXPR	: N_SIMPLE_ARITHLOGIC
			{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | N_SIMPLE_ARITHLOGIC N_REL_OP N_SIMPLE_ARITHLOGIC
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;			
N_SIMPLE_ARITHLOGIC 	: N_TERM N_ADD_OP_LIST
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_ADD_OP_LIST	: N_ADD_OP N_TERM N_ADD_OP_LIST
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | /*EPSILON*/
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_TERM	 	: N_FACTOR N_MULT_OP_LIST
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;
N_MULT_OP_LIST	: N_MULT_OP N_FACTOR N_MULT_OP_LIST
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | /*EPSILON*/
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_FACTOR	: N_VAR
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | N_CONST
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_LPAREN N_EXPR T_RPAREN
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_NOT N_FACTOR
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_ADD_OP	: T_ADD
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | T_SUB
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_OR
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_MULT_OP	: T_MULT
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | T_DIV
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_AND
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_MOD
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_POW
			{
			printRule("INTCONST_LIST", "INTCONST");
			}			
			;	
N_REL_OP	: T_LT
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | T_GT
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_LE
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_GE
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_EQ
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
		 | T_NE
			{
			printRule("INTCONST_LIST", "INTCONST");
			}				
			;	
N_VAR		: N_ENTIRE_VAR
		{
			printRule("INTCONST_LIST", "INTCONST");
			}		
		 | N_SINGLE_ELEMENT
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
			;	
N_SINGLE_ELEMENT	: T_IDENT T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
			{
			printRule("INTCONST_LIST", "INTCONST");
			}		
			;	
N_ENTIRE_VAR	: T_IDENT
			{
			printRule("INTCONST_LIST", "INTCONST");
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
