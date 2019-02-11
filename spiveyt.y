%{
/* 
Definitions of constants, variables, & function prototypes go here 
*/


int numLines = 0;

void printTokenInfo(const char* tokenType, char* lexeme);

%}
#include <stdio.h>

int numLines = 1; 

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
%token  T_IDENT T_INTCONST T_UNKNOWN T_FLOATCONST T_IF
%token T_ELSE T_WHILE T_FUNCTION T_FOR T_IN T_NEXT
%token T_BREAK T_TRUE T_FALSE T_QUIT T_PRINT T_CAT
$token T_READ T_LIST T_STRCONST T_ADD T_SUB T_MULT
%token T_DIV T_MOD T_POWER T_LT T_GT T_LE T_GE T_EQ
%token T_NE T_NOT T_AND T_OR T_ASSIGN T_SEMICOLON
%token T_COMMA T_LPAREN T_RPAREN T_LBRACE T_RBRACE
%token T_LBRACKET T_RBRACKET T_COMMENT T_POUND

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
N_EXPR		: T_INTCONST
			{
			printRule("EXPR", "INTCONST");
			}
                | T_IDENT
                {
			printRule("EXPR", "IDENT");
			}
                | T_FOO N_IDENT_LIST N_INTCONST_LIST
                {
			printRule("EXPR", 
				    "foo IDENT_LIST INTCONST_LIST");
			}
			;
N_IDENT_LIST   	: /* lambda */
			{
			printRule("IDENT_LIST", "lambda");
			}
                | N_IDENT_LIST T_IDENT
			{
			printRule("IDENT_LIST", "IDENT_LIST IDENT");
			}
			;
N_INTCONST_LIST : T_INTCONST
			{
			printRule("INTCONST_LIST", "INTCONST");
			}
                | N_INTCONST_LIST T_INTCONST
			{
			printRule("INTCONST_LIST",
                          "INTCONST_LIST INTCONST");
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
