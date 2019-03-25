	/* 
    minir.y

    flex minir.l
    bison minir.y
    g++ minir.tab.c -o parser
    ./parser < inputFileName
    
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "SymbolTable.h"
#include <stack>
#include <queue>
stack <SYMBOL_TABLE> scopeStack;
int line_num = 1;
int temp;
int temp2;
int temp3;
int temp4;
int temp5;
queue<int> num_param;

bool rightnum = 0;
bool isEpsilon = false;


#define ARITH_OP 10
#define REL_OP 9
#define LOG_OP 8

bool arithCompatible(const int theType);
bool whileCompatible(const int theType);
void printTokenInfo(const char* token_type, const char* lexeme);

void printRule(const char *, const char *);

void beginScope();
void endScope();
TYPE_INFO findEntryInAnyScope(const string theName);
int get_num_param();
int yyerror(const char *s) 
{
    printf("Line %d: %s\n", line_num, s);
    exit(1);
}

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}

%token T_IDENT T_INTCONST T_FLOATCONST T_UNKNOWN T_STRCONST 
%token T_IF T_ELSE
%token T_WHILE T_FUNCTION T_FOR T_IN T_NEXT T_BREAK 
%token T_TRUE T_FALSE T_QUIT
%token T_PRINT T_CAT T_READ T_LPAREN T_RPAREN T_LBRACE 
%token T_RBRACE T_LBRACKET
%token T_RBRACKET T_SEMICOLON T_COMMA T_ADD T_SUB 
%token T_MULT T_DIV T_MOD
%token T_POW T_LT T_LE T_GT T_GE T_EQ T_NE T_NOT T_AND 
%token T_OR T_ASSIGN T_LIST
%type <text> T_IDENT
/*
 *  To eliminate ambiguity in if/else
 */
 %type <typeInfo> N_CONST N_IF_EXPR N_EXPR
 %type <typeInfo> N_WHILE_EXPR N_FOR_EXPR
 %type <typeInfo> N_COMPOUND_EXPR N_ARITHLOGIC_EXPR
 %type <typeInfo> N_ASSIGNMENT_EXPR  N_OUTPUT_EXPR
 %type <typeInfo> N_INPUT_EXPR N_LIST_EXPR N_FUNCTION_DEF
 %type <typeInfo> N_FUNCTION_CALL N_EXPR_LIST N_QUIT_EXPR
 %type <typeInfo> N_CONST_LIST N_SIMPLE_ARITHLOGIC
 %type <typeInfo> N_TERM N_ADD_OP_LIST N_ADD_OP N_REL_OP
 %type <typeInfo> N_FACTOR N_MULT_OP_LIST N_MULT_OP N_VAR N_INDEX
 %type <typeInfo> N_SINGLE_ELEMENT N_ENTIRE_VAR
%nonassoc   T_RPAREN 
%nonassoc   T_ELSE
%union
{
  char* text;
  TYPE_INFO typeInfo;
}

%start N_START

%%

N_START         : N_EXPR
                {
             
		    endScope();	
                    printf("\n---- Completed parsing ----\n\n");
                    return 0;
                }
                ;
N_EXPR          : N_IF_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_WHILE_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_FOR_EXPR
                {	
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_COMPOUND_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_ARITHLOGIC_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_ASSIGNMENT_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_OUTPUT_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_INPUT_EXPR
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_LIST_EXPR
                {

		    $$.type = $1.type;
			temp2 = LIST;
			if(temp2 == LIST && temp3 == INT)
			{
				if(temp4 != UNDEFINED && line_num != 1)
				{
					yyerror("Arg 1 cannot be function or null or list or string");
                              	}
				
			}
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_FUNCTION_DEF
                {
		    $$.type = FUNCTION;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_FUNCTION_CALL
                {
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_QUIT_EXPR
                {
                    $$.type = $1.type;
                    $$.numParams = $1.numParams;
                    $$.returnType = NOT_APPLICABLE;
                    exit(1);
                }
                ;

N_CONST         : T_INTCONST
                {
		    $$.type = INT;
			temp3 = INT;
			temp4 = INT;
           
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_STRCONST
                {
        
		    $$.type = STR;
			temp2 = STR;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_FLOATCONST
                {
		    $$.type = FLOAT;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_TRUE
                {
		    $$.type = BOOL;
                   temp3 = BOOL;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_FALSE
                {
		    $$.type = BOOL;
                    temp3 = BOOL;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                ;

N_ARITHLOGIC_EXPR : N_SIMPLE_ARITHLOGIC
                {

                  if(!arithCompatible($1.type))
                  {
                    yyerror("error Arg 1 cannot be function");
                  }
                  $$.type = $1.type;
                  $$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | N_SIMPLE_ARITHLOGIC N_REL_OP
                  N_SIMPLE_ARITHLOGIC
                {

                  if($1.type == FUNCTION)
                  {
                    yyerror("2 error Arg 1 cannot be function");
                  }
                  else if($1.type == NULL_TYPE)
                  {
                    yyerror("Arg 1 cannot be null");
                  }
                  else if($1.type == STR)
                  {
                    yyerror("Arg 1 cannot be string");
                  }
                  else if($1.type == LIST)
                  {
                    yyerror("Arg 1 cannot be list");
                  }
                  if($3.type == FUNCTION)
                  {
                    yyerror("Arg 2 cannot be function");
                  }
                  else if($3.type == NULL_TYPE)
                  {
                    yyerror("Arg 2 cannot be null");
                  }
                  else if($3.type == STR)
                  {
                    yyerror("Arg 2 cannot be string");
                  }
                  else if($3.type == LIST)
                  {
                    yyerror("Arg 2 cannot be list");
                  }
                  
                  if($2.type == ARITH_OP)
                  {
                    if($1.type != FLOAT && $3.type != FLOAT)
                    {
			$$.type = INT;
			$$.numParams = $1.numParams + $3.numParams;
			$$.returnType = INT;

                    }
                    else if($3.type == FLOAT || $1.type == FLOAT)
                    {
			$$.type = FLOAT;
			$$.numParams = $1.numParams + $3.numParams;
			$$.returnType = FLOAT;
                    }
                    else
                    {
      
                    }
                  }
                  else if($2.type == REL_OP || $2.type == LOG_OP)
                  {
			$$.type == BOOL;
			$$.numParams = $1.numParams + $3.numParams;
			$$.returnType = BOOL;

                  }
                }
                ;

N_SIMPLE_ARITHLOGIC : N_TERM N_ADD_OP_LIST
                {
                    if($1.type == FLOAT || $2.type == FLOAT)
                    {
                      	$$.type = FLOAT;
			$$.numParams = $1.numParams + $2.numParams;
			$$.returnType = FLOAT;
                    }
                    else
                    {
                      	$$.type = INT;
			$$.numParams = $1.numParams + $2.numParams;
			$$.returnType = INT;
                    }

                }
                ;

N_ADD_OP_LIST	: N_ADD_OP N_TERM N_ADD_OP_LIST
                {
 
                  if($1.type != LOG_OP)
                  {
			if($2.type == FLOAT || $3.type == FLOAT)
			{
				$$.type = FLOAT;
				$$.numParams = $3.numParams + $2.numParams;
				$$.returnType = FLOAT;
			}
			else if($2.type == INT && $3.type == INT)
			{
		           	$$.type = INT;
				$$.numParams = $3.numParams + $2.numParams;
				$$.returnType = INT;

			}
                  }
                  else if($1.type == LOG_OP)
                  {
			
		           	$$.type = BOOL;
				$$.numParams = $3.numParams + $2.numParams;
				$$.returnType = BOOL;
                  }
                }
                | /* epsilon */
                {

                            
		           	$$.type = EPSILON;
				$$.numParams = NOT_APPLICABLE;
				$$.returnType = NOT_APPLICABLE;
                }
                ;

N_TERM		: N_FACTOR N_MULT_OP_LIST
                {

                    if($2.type != EPSILON)
                    {
			if($1.type == FLOAT || $2.type == FLOAT)
			{
				$$.type = FLOAT;
				$$.numParams = $1.numParams + $2.numParams;
				$$.returnType = FLOAT;
			}
			else if($1.type == INT || $1.type == BOOL)
			{
				$$.type = INT;
				$$.numParams = $1.numParams + $2.numParams;
				$$.returnType = INT;
			}
			else if($1.type == STR || temp2 == STR)
			{
				if($1.type == STR && temp2 != STR)
				{
					$$.type = STR;
				}
				else
				{
					yyerror("Arg 1 must be integer or float or bool");
				}
			}
			else if($1.type == LIST && temp3 == INT)
			{
				yyerror("Arg 1 must be integer or float or bool");
			}
			else if($1.type == LIST)
			{
				if(temp3 == BOOL)
				{

				yyerror("Arg 1 must be integer or float or bool");
				}
				yyerror("Arg 1 cannot be list");
			}
			
                    }
                    else if($2.type == EPSILON)
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
			}
                  
                }
                ;

N_MULT_OP_LIST	: N_MULT_OP N_FACTOR N_MULT_OP_LIST
                {
                    if($1.type == ARITH_OP)
                    {
			if($2.type == FLOAT || $3.type == FLOAT)
			{
				$$.type = FLOAT;
				$$.numParams = $1.numParams + $2.numParams;
				$$.returnType = FLOAT;
			}
			else
			{
				
				$$.type = INT;
				$$.numParams = $1.numParams + $2.numParams;
				$$.returnType = INT;
			}                                                                                                                                                                           
                    }
                    if($1.type == LOG_OP)
                    {

				$$.type = BOOL;
				$$.numParams = $1.numParams + $2.numParams;
				$$.returnType = BOOL;
                    }
                }
                | /* epsilon */
                {

		           	$$.type == EPSILON;
				$$.numParams = NOT_APPLICABLE;
				$$.returnType = NOT_APPLICABLE;
                }
                ;

N_FACTOR		: N_VAR
                {
			$$.type = $1.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | N_CONST
                {
			$$.type = $1.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | T_LPAREN N_EXPR T_RPAREN
                {
			$$.type = $2.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | T_NOT N_FACTOR
                {

			$$.type = $2.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                ;

N_COMPOUND_EXPR : T_LBRACE N_EXPR N_EXPR_LIST T_RBRACE
                {

			      $$.type = $2.type;
                              $$.numParams = $2.numParams;
                              $$.returnType = NOT_APPLICABLE;
                      
		}
                ;

N_EXPR_LIST     : T_SEMICOLON N_EXPR N_EXPR_LIST
                {
		    $$.type = $2.type;
                    $$.numParams = $2.numParams;
                    $$.returnType = NOT_APPLICABLE;
                }
                | /* epsilon */
                {
		    $$.type = EPSILON;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                ;

N_IF_EXPR       : T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR
                {
                
                }
                | T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR T_ELSE
                  N_EXPR
                {
               
                }
                ;

N_WHILE_EXPR    : T_WHILE T_LPAREN N_EXPR T_RPAREN N_EXPR
                {

				TYPE_INFO trial = scopeStack.top().findEntry("temp");
				if(trial.type == FUNCTION || $3.type == NULL_TYPE || $3.type == LIST || $3.type == STR || $3.type == INT_OR_STR_OR_BOOL_OR_FLOAT)
				{

					yyerror("while Arg 1 cannot be function or null or list or str");
				}

			        $$.type = $5.type;
                                cout << $$.type << endl;
			      	$$.numParams = $5.numParams;
				$$.returnType = NOT_APPLICABLE;
                              
                }
                ;

N_FOR_EXPR      : T_FOR T_LPAREN T_IDENT 
                {


		T_IN N_EXPR T_RPAREN N_EXPR
		{
		
		}
                ;
/* don't need these anymore but keeping them just in case
N_LOOP_EXPR     : N_EXPR
                {
                /    printRule("LOOP_EXPR", "EXPR");
                }
                | N_BREAK_EXPR
                {
                    printRule("LOOP_EXPR", "BREAK_EXPR");
                }
                | N_NEXT_EXPR
                {
                    printRule("LOOP_EXPR", "NEXT_EXPR");
                }
                ;

N_BREAK_EXPR    : T_BREAK
                {
                    printRule("BREAK_EXPR", "BREAK");
                }
                ;

N_NEXT_EXPR     : T_NEXT
                {
                   printRule("NEXT_EXPR", "NEXT");
                }
                ;
*/
N_LIST_EXPR     : T_LIST T_LPAREN N_CONST_LIST T_RPAREN
                {
			      $$.type = LIST;
                              $$.numParams = NOT_APPLICABLE;
                              $$.returnType = LIST;

                }
                ;

N_CONST_LIST    : N_CONST T_COMMA N_CONST_LIST
                {

                }
                | N_CONST
                {
   
                }
                ;

N_ASSIGNMENT_EXPR : T_IDENT N_INDEX// T_ASSIGN N_EXPR
                {

                
			TYPE_INFO trial = findEntryInAnyScope(string($1));
			temp4 = UNDEFINED;
			if(trial.type == UNDEFINED)
			{

                        scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), UNDEFINED));
				
                    	}
                    if($2.type != EPSILON && temp != LIST)
                    {
                       yyerror("Arg 1 must be list");
                    }
                    else if(temp2 == LIST )
                    {

			}
                    isEpsilon = true;
		}
		T_ASSIGN N_EXPR
		{
                    if(isEpsilon = true)
                    {
			scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1),$5.type));
			temp = $5.type;
			$$.type = $5.type;
			isEpsilon = true;
                    }		  
		}
		;

N_INDEX :       T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
			    {
  
	/*		$$.type = $3.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = $3.type;
	*/		    }
			    | /* epsilon */
                {

			$$.type = EPSILON;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = EPSILON;
                }
                ;

N_QUIT_EXPR     : T_QUIT T_LPAREN T_RPAREN
                {
                    printRule("QUIT_EXPR", "QUIT()");
                      $$.type = NULL_TYPE;
        		   exit(1);
                }
                ;

N_OUTPUT_EXPR   : T_PRINT T_LPAREN N_EXPR T_RPAREN
                {

                	
			if(($3.type == FUNCTION) || ($3.type == NULL_TYPE))
			{
				yyerror("Arg 1 cannot be function or null");
			}
			$$.type = $3.type;
			$$.numParams = $3.numParams;
			$$.returnType = $3.returnType;
			
		}
                | T_CAT T_LPAREN N_EXPR T_RPAREN
                {

                        TYPE_INFO trial = scopeStack.top().findEntry("temp2");
			if($3.type == FUNCTION || $3.type == NULL_TYPE)
			{
				if(temp4 != UNDEFINED && temp2 != STR)
				{	
					yyerror("Arg 1 cannot be function or null");
                		}
				else
				{

					yyerror("Arg 1 must be integer or float or bool");
				}                
			} 
			else if(temp2 == STR && $3.type == STR)
			{
				yyerror("Arg 1 must be integer or float or bool");

			}
			else if(temp4 == UNDEFINED && temp2 == STR)
                        {
				if(temp5 != NOT_APPLICABLE)
				{	
					yyerror("Arg 1 must be integer or float or bool");
				}
				else
				{

					yyerror("Arg 1 cannot be function or null");
				}
			}
			else if(temp3 == BOOL)
			{

				
			}
			else if(temp5 == NOT_APPLICABLE)
			{
				yyerror("Arg 1 cannot be function or null");
			}
                        else
			{
                                yyerror("Arg 1 cannot be function or null or list or string");
			}
                }
                ;

N_INPUT_EXPR    : T_READ T_LPAREN N_VAR T_RPAREN
                {
   
                }
                ;

N_FUNCTION_DEF  : T_FUNCTION
                {
		
		    beginScope();
		    			
                }
		T_LPAREN N_PARAM_LIST T_RPAREN N_COMPOUND_EXPR
		{

		  	$$.type = FUNCTION;
			$$.numParams = NOT_APPLICABLE;
		//	$$.returnType = FUNCTION;
		  endScope();
		}
                ;

N_PARAM_LIST    : N_PARAMS
                {

                }
                | N_NO_PARAMS
                {

                }
                ;

N_NO_PARAMS     : /* epsilon */
                {

                }
                ;

N_PARAMS        : T_IDENT
                {

                   if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), INT)))  
                  	{
                      yyerror("Multiply defined identifier\n");
                    	}
		}
                | T_IDENT T_COMMA N_PARAMS
                {

                   if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), INT)))  
		         {
                      yyerror("Multiply defined identifier\n");
                    }
                }
                ;

N_FUNCTION_CALL : T_IDENT T_LPAREN N_ARG_LIST T_RPAREN
                {

                   if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), FUNCTION)))  
		    {
                      yyerror("functin call Undefined identifier");
		    }	
		}
                ;

N_ARG_LIST      : N_ARGS
                {
          
                }
                | N_NO_ARGS
                {

                }
                ;

N_NO_ARGS       : /* epsilon */
                {
         
                }
                ;

N_ARGS          : N_EXPR
                {
   
                }
                | N_EXPR T_COMMA N_ARGS
                {
            
                }
                ;

N_ADD_OP	     : T_ADD
                {

			$$.type = ARITH_OP;
                }
                | T_SUB
                {
            
			$$.type = ARITH_OP;
                }
                | T_OR
                {
         
			$$.type = LOG_OP;
                }
                ;

N_MULT_OP      : T_MULT
                {
			$$.type = ARITH_OP;
                }
                | T_DIV
                {

			$$.type = ARITH_OP;
                }
                | T_AND
                {
           
			$$.type = LOG_OP;
                }
                | T_MOD
                {

			$$.type = ARITH_OP;
                }
                | T_POW
                {
    
		    $$.type = ARITH_OP;
                }
                ;

N_REL_OP        : T_LT
                {
		 $$.type = REL_OP;
                }
                | T_GT
                {
                
		$$.type = REL_OP;
                }
                | T_LE
                {
             
		 $$.type = REL_OP;
                }
                | T_GE
                {
            
		  $$.type = REL_OP;
                }
                | T_EQ
                {
                 
		  $$.type = REL_OP;
                }
                | T_NE
                {
         
		 $$.type = REL_OP;
                }
                ;

N_VAR           : N_ENTIRE_VAR
                {

			$$.type = $1.type;
		}
                | N_SINGLE_ELEMENT
                {
    
			$$.type = $1.type;
                }
                ;

N_SINGLE_ELEMENT : T_IDENT T_LBRACKET T_LBRACKET N_EXPR
                   T_RBRACKET T_RBRACKET
  
                    TYPE_INFO check = findEntryInAnyScope(string($1));
                    if(check.type == UNDEFINED && temp == UNDEFINED)  
		    {
  
                	yyerror("single element Undefined identifier");
		    }	
			$$.type = INT_OR_STR_OR_BOOL_OR_FLOAT;
                }
                ;

N_ENTIRE_VAR    : T_IDENT
                {
   
                    TYPE_INFO check = findEntryInAnyScope(string($1));

                    if(temp == FUNCTION && check.type != INT)
                    {
			if(temp2 != INT)
			{
				if(temp3 != BOOL && temp5 != NOT_APPLICABLE)
				{

                      			yyerror("Arg 1 cannot be function or null or list or function");
                                }
				else if(temp5 == NOT_APPLICABLE)
				{
					if(temp3 == BOOL)
					{
						yyerror("Arg 2 must be integer or float or bool");
					}
					else if(temp4 != INT)
					{
						yyerror("Arg 1 cannot be function or null");
					}
				}
				else
				{

					yyerror("Arg 2 must be integer or float or bool");
				}
			}
			else if(temp2 == INT)
			{
				yyerror("Arg 1 must be interger or float or bool");
			}
                    }
                    else if(temp == INT)
                    {
			$$.type = INT_OR_STR_OR_BOOL_OR_FLOAT;
                    }
                    else if(temp != UNDEFINED && temp != FUNCTION && temp !=STR && temp!= FLOAT)
                    {
			
                        yyerror("Arg 1 cannot be function or null");
                    }		
				$$.type = INT_OR_STR_OR_BOOL_OR_FLOAT;
	
                }
                ;

%%

#include "lex.yy.c"
extern FILE *yyin;

int get_num_param()
{
	int size = scopeStack.top().getHashTable().size();
	return size;
}

void printTokenInfo(const char* token_type, const char* lexeme)
{
  //  printf("TOKEN: %s \t\t LEXEME: %s\n", token_type, lexeme);
}

void printRule(const char *lhs, const char *rhs)
{
  //  printf("%s -> %s\n", lhs, rhs);
    return;
}
bool arithCompatible(const int theType) 
{
  return((theType == INT) || (theType == FLOAT) ||
         (theType == BOOL) || 
         (theType == INT_OR_STR_OR_BOOL_OR_FLOAT));
}
bool whileCompatible(const int theType) 
{
  return((theType == INT) || (theType == FLOAT) ||
         (theType == BOOL) || 
         (theType == INT_OR_STR_OR_BOOL_OR_FLOAT)
	 || (theType == EPSILON));
}
void beginScope()
{
  scopeStack.push(SYMBOL_TABLE());
//  printf("\n___Entering new scope... \n\n");
}

void endScope()
{
  scopeStack.pop();
//  printf("\n___Exiting scope...\n\n");
}

TYPE_INFO findEntryInAnyScope(const string theName)
{
  TYPE_INFO info = {UNDEFINED};
  if (scopeStack.empty( )) return(info);
  info = scopeStack.top().findEntry(theName);
  if (info.type != UNDEFINED)
    return(info);
  else { // check in "next higher" scope
	   SYMBOL_TABLE symbolTable = scopeStack.top( );
	   scopeStack.pop( );
	   info = findEntryInAnyScope(theName);
	   scopeStack.push(symbolTable); // restore the stack
	   return(info);
  }
}
int main() 
{
    beginScope();
    do {
        yyparse();
    } while (!feof(yyin));
  
    return 0;
}
