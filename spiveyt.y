%{
/* 
Definitions of constants, variables, & function prototypes go here 
*/

#define T_IDENT     		1
#define T_INTCONST  		2
#define T_UNKNOWN   		3
#define T_FLOATCONST       	4
#define T_IF				5
#define T_ELSE				6
#define T_WHILE				7
#define T_FUNCTION			8
#define T_FOR				9
#define T_IN				10
#define T_NEXT				11
#define T_BREAK				12
#define T_TRUE				13
#define T_FALSE				14
#define T_QUIT				15
#define T_PRINT				16
#define T_CAT				17
#define T_READ				18
#define T_LIST				19
#define T_STRCONST			20
#define T_ADD				21
#define T_SUB				22
#define T_MULT				23
#define T_DIV				24
#define T_MOD				25
#define T_POWER				26
#define T_LT				27
#define T_GT				28
#define T_LE				29
#define T_GE				30
#define T_EQ				31
#define T_NE				32
#define T_NOT				33
#define T_AND				34
#define T_OR				35
#define T_ASSIGN			36
#define T_SEMICOLON			37
#define T_COMMA				38
#define T_LPAREN			39
#define T_RPAREN			40
#define T_LBRACE			41
#define T_RBRACE			42
#define T_LBRACKET			43
#define T_RBRACKET			44
#define T_COMMENT			45
#define T_POUND				46

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
%token  T_IDENT T_INTCONST T_UNKNOWN T_FOO

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
