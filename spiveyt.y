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
int gnum_params = 0;
queue<int> num_param;

bool isLet = false;
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
bool findEntryInAnyScope(const string theName);
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
 %type <typeInfo> N_CONST N_IF_EXPR
 %type <typeInfo> N_WHILE_EXPR N_FOR_EXPR
 %type <typeInfo> N_COMPOUND_EXPR N_ARITHLOGIC_EXPR
 %type <typeInfo> N_ASSIGNMENT_EXPR N_EXPR N_OUTPUT_EXPR
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
                  //  printRule("START", "EXPR");
		    endScope();	
                    printf("\n---- Completed parsing ----\n\n");
                    return 0;
                }
                ;
N_EXPR          : N_IF_EXPR
                {
                    cout << "nexpr nifexpr" << endl;
                    cout << $1.type << endl;
                    printRule("EXPR", "IF_EXPR");
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_WHILE_EXPR
                {
                    cout << "nexpr while" << endl;
			cout << $1.type << endl;
                    printRule("EXPR", "WHILE_EXPR");
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_FOR_EXPR
                {	

                    cout << $1.type << endl;
                    printRule("EXPR", "FOR_EXPR");
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_COMPOUND_EXPR
                {
		cout << $1.type << endl;
                   printRule("EXPR", "COMPOUND_EXPR");
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_ARITHLOGIC_EXPR
                {
		cout << $1.type << endl;
                    printRule("EXPR", "ARITHLOGIC_EXPR");
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_ASSIGNMENT_EXPR
                {
                    printRule("EXPR", "ASSIGNMENT_EXPR");
		cout << $1.type << endl;
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_OUTPUT_EXPR
                {
		cout << $1.type << endl;
                   printRule("EXPR", "OUTPUT_EXPR");
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_INPUT_EXPR
                {
                   printRule("EXPR", "INPUT_EXPR");
		cout << $1.type << endl;
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_LIST_EXPR
                {
                   printRule("EXPR", "LIST_EXPR");
		cout << $1.type << endl;
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_FUNCTION_DEF
                {
                   printRule("EXPR", "FUNCTION_DEF");
		    $$.type = FUNCTION;
		cout << $1.type << endl;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_FUNCTION_CALL
                {
                   printRule("EXPR", "FUNCTION_CALL");
		cout << $1.type << endl;
		    $$.type = $1.type;
                    $$.numParams = $1.numParams;
		    $$.returnType = NOT_APPLICABLE;
                }
                | N_QUIT_EXPR
                {
                   printRule("EXPR", "QUIT_EXPR");
		cout << $1.type << endl;
                    $$.type = $1.type;
                    $$.numParams = $1.numParams;
                    $$.returnType = NOT_APPLICABLE;
                    exit(1);
                }
                ;

N_CONST         : T_INTCONST
                {
                   printRule("CONST", "INTCONST");
		    $$.type = INT;

                    cout << $$.type << endl;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_STRCONST
                {
                    printRule("CONST", "STRCONST");
		    $$.type = STR;
                    cout << $$.type << endl;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_FLOATCONST
                {
                    printRule("CONST", "FLOATCONST");
		    $$.type = FLOAT;
                    cout << $$.type << endl;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_TRUE
                {
                 printRule("CONST", "TRUE");
		    $$.type = BOOL;
                    cout << $$.type << endl;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                | T_FALSE
                {
                  printRule("CONST", "FALSE");
		    $$.type = BOOL;
                    cout << $$.type << endl;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                ;

N_ARITHLOGIC_EXPR : N_SIMPLE_ARITHLOGIC
                {
                   printRule("ARITHLOGIC_EXPR", 
                             "SIMPLE_ARITHLOGIC");
                  if(!arithCompatible($1.type))
                  {
                    yyerror(" arith error Arg 1 cannot be function");
                  }
                  $$.type = $1.type;
                  $$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | N_SIMPLE_ARITHLOGIC N_REL_OP
                  N_SIMPLE_ARITHLOGIC
                {
                    printRule("ARITHLOGIC_EXPR", 
                              "SIMPLE_ARITHLOGIC REL_OP "
                              "SIMPLE_ARITHLOGIC");
                  if($1.type == FUNCTION)
                  {
                    yyerror("arith 2 error Arg 1 cannot be function");
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
                    	cout << "test" << endl;  
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
                    printRule("SIMPLE_ARITHLOGIC", 
                              "TERM ADD_OP_LIST");
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
                   printRule("ADD_OP_LIST", 
                              "ADD_OP TERM ADD_OP_LIST");
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
                 //  printRule("ADD_OP_LIST", "epsilon");
                            
		           	$$.type = EPSILON;
				$$.numParams = NOT_APPLICABLE;
				$$.returnType = NOT_APPLICABLE;
                }
                ;

N_TERM		: N_FACTOR N_MULT_OP_LIST
                {
                   printRule("TERM", 
                              "FACTOR MULT_OP_LIST");
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
                    printRule("MULT_OP_LIST", 
                              "MULT_OP FACTOR MULT_OP_LIST");
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
                    printRule("MULT_OP_LIST", "epsilon");

		           	$$.type == EPSILON;
				$$.numParams = NOT_APPLICABLE;
				$$.returnType = NOT_APPLICABLE;
                }
                ;

N_FACTOR		: N_VAR
                {
                   printRule("FACTOR", "VAR");
			$$.type = $1.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | N_CONST
                {
                   printRule("FACTOR", "CONST");
			$$.type = $1.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | T_LPAREN N_EXPR T_RPAREN
                {
                   printRule("FACTOR", "( EXPR )");
			$$.type = $2.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                | T_NOT N_FACTOR
                {
                  printRule("FACTOR", "! FACTOR");
			$$.type = $2.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
                }
                ;

N_COMPOUND_EXPR : T_LBRACE N_EXPR N_EXPR_LIST T_RBRACE
                {
                    printRule("COMPOUND_EXPR",
                              "{ EXPR EXPR_LIST }");
			      $$.type = $2.type;
		                    cout << $$.type << endl;
                              $$.numParams = $2.numParams;
                              $$.returnType = NOT_APPLICABLE;
                      
		}
                ;

N_EXPR_LIST     : T_SEMICOLON N_EXPR N_EXPR_LIST
                {
                    printRule("EXPR_LIST", "; EXPR EXPR_LIST");
		    $$.type = $2.type;
		                    cout << $$.type << endl;
                    $$.numParams = $2.numParams;
                    $$.returnType = NOT_APPLICABLE;
                }
                | /* epsilon */
                {
                    printRule("EXPR_LIST", "epsilon");
		    $$.type = EPSILON;
                    $$.numParams = NOT_APPLICABLE;
                    $$.returnType = NOT_APPLICABLE;
                }
                ;

N_IF_EXPR       : T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR
                {
                    printRule("IF_EXPR", "IF ( EXPR ) EXPR");
                }
                | T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR T_ELSE
                  N_EXPR
                {
                   printRule("IF_EXPR", "IF ( EXPR ) EXPR ELSE EXPR");
                }
                ;

N_WHILE_EXPR    : T_WHILE T_LPAREN N_EXPR T_RPAREN N_EXPR
                {
                    printRule("WHILE_EXPR", 
                              "WHILE ( EXPR ) "
                              "LOOP_EXPR");
				cout << "the fuck is going on" << endl;
				cout << $3.type << endl;
				cout << $5.type << endl;
			      if(!whileCompatible($3.type))
			      {
				yyerror("while error Arg 1 cannot be function or null or list or string");
			      }
			        $$.type = $5.type;
				cout << "while function is: " << endl;
                                cout << $$.type << endl;
			      	$$.numParams = $5.numParams;
				$$.returnType = NOT_APPLICABLE;
                              
                }
                ;

N_FOR_EXPR      : T_FOR T_LPAREN T_IDENT 
                {
                    printRule("FOR_EXPR", 
                              "FOR ( IDENT IN EXPR ) "
                              "LOOP_EXPR");
                    bool found = scopeStack.top().findEntry($3);
                    if(!found)
                    {
                   // printf("___Adding %s to symbol table\n", $3);

//                      scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY($3, UNDEFINED));
                    }
                }
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
                    printRule("LIST_EXPR", 
                              "LIST ( CONST_LIST )");
			      $$.type = LIST;
                              $$.numParams = NOT_APPLICABLE;
                              $$.returnType = LIST;

                }
                ;

N_CONST_LIST    : N_CONST T_COMMA N_CONST_LIST
                {
                    printRule("CONST_LIST", 
                              "CONST, CONST_LIST");
                }
                | N_CONST
                {
                    printRule("CONST_LIST", "CONST");
                }
                ;

N_ASSIGNMENT_EXPR : T_IDENT N_INDEX
                {
                    printRule("ASSIGNMENT_EXPR", 
                              "IDENT INDEX ASSIGN EXPR");
                    if(!scopeStack.top().findEntry((string($1))))
                    {
			cout << "adding to stack" << endl;
			cout << string($1) << endl;
			scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), FUNCTION));
                    }

                    if($2.type != EPSILON)
                    {
			//isEpsilon;
                       yyerror("dudk you");
                    }
                    else
                    {
			isEpsilon = true;
                    }
                }
		T_ASSIGN N_EXPR
		{
		  
		  if(!isEpsilon)
		  {
		    yyerror("ASSIGN ERROR Arg 1 cannot be list");
		  }
                  else
                  {	
                      
			printf("check\n");
			$$.type = FUNCTION;
			$$.numParams = $2.numParams;
			$$.returnType = $2.returnType;
                  }
		}
		;

N_INDEX :       T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
			    {
                    printRule("INDEX", " [[ EXPR ]]");
	/*		$$.type = $3.type;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = $3.type;
	*/		    }
			    | /* epsilon */
                {
                    printRule("INDEX", " epsilon");
			$$.type = EPSILON;
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = EPSILON;
                }
                ;

N_QUIT_EXPR     : T_QUIT T_LPAREN T_RPAREN
                {
                    printRule("QUIT_EXPR", "QUIT()");
                      $$.type = NULLTYPE;
        		   exit(1);
                }
                ;

N_OUTPUT_EXPR   : T_PRINT T_LPAREN N_EXPR T_RPAREN
                {
                    printRule("OUTPUT_EXPR", 
                              "PRINT ( EXPR )");
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
                   printRule("OUTPUT_EXPR", 
                              "CAT ( EXPR )");
                }
                ;

N_INPUT_EXPR    : T_READ T_LPAREN N_VAR T_RPAREN
                {
                    printRule("INPUT_EXPR", "READ ( VAR )");
                }
                ;

N_FUNCTION_DEF  : T_FUNCTION
                {
		
		    beginScope();
		    			
                }
		T_LPAREN N_PARAM_LIST T_RPAREN N_COMPOUND_EXPR
		{
                  
                   printRule("FUNCTION_DEF",
                              "FUNCTION ( PARAM_LIST )"
                              " COMPOUND_EXPR");
		  	$$.type = FUNCTION;
			$$.numParams = NOT_APPLICABLE;
		//	$$.returnType = FUNCTION;
		  endScope();
		}
                ;

N_PARAM_LIST    : N_PARAMS
                {
                    printRule("PARAM_LIST", "PARAMS");
                }
                | N_NO_PARAMS
                {
                   printRule("PARAM_LIST", "NO PARAMS");
                }
                ;

N_NO_PARAMS     : /* epsilon */
                {
                   printRule("NO_PARAMS", "epsilon");
                }
                ;

N_PARAMS        : T_IDENT
                {
                    printRule("PARAMS", "IDENT");
                    printf("___Adding %s to symbol table\n", $1);
                   if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), UNDEFINED)))  
                  	{
                      yyerror("Multiply defined identifier\n");
                    	}
		}
                | T_IDENT T_COMMA N_PARAMS
                {
                    printRule("PARAMS", "IDENT, PARAMS");
                   printf("___Adding %s to symbol table\n", $1);
                   if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), UNDEFINED)))  
		         {
                      yyerror("Multiply defined identifier\n");
                    }
                }
                ;

N_FUNCTION_CALL : T_IDENT T_LPAREN N_ARG_LIST T_RPAREN
                {
                    printRule("FUNCTION_CALL", "IDENT"
                              " ( ARG_LIST )");
                   if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), FUNCTION)))  
		    {
                      yyerror("Undefined identifier");
		    }	
		}
                ;

N_ARG_LIST      : N_ARGS
                {
                   printRule("ARG_LIST", "ARGS");
                }
                | N_NO_ARGS
                {
                   printRule("ARG_LIST", "NO_ARGS");
                }
                ;

N_NO_ARGS       : /* epsilon */
                {
                    printRule("NO_ARGS", "epsilon");
                }
                ;

N_ARGS          : N_EXPR
                {
                   printRule("ARGS", "EXPR");
                }
                | N_EXPR T_COMMA N_ARGS
                {
                    printRule("ARGS", "EXPR, ARGS");
                }
                ;

N_ADD_OP	     : T_ADD
                {
                    printRule("ADD_OP", "+");
			$$.type = ARITH_OP;
                }
                | T_SUB
                {
                    printRule("ADD_OP", "-");
			$$.type = ARITH_OP;
                }
                | T_OR
                {
                    printRule("ADD_OP", "|");
			$$.type = LOG_OP;
                }
                ;

N_MULT_OP      : T_MULT
                {
                    printRule("MULT_OP", "*");
			$$.type = ARITH_OP;
                }
                | T_DIV
                {
                    printRule("MULT_OP", "/");
			$$.type = ARITH_OP;
                }
                | T_AND
                {
                    printRule("MULT_OP", "&");
			$$.type = LOG_OP;
                }
                | T_MOD
                {
                   printRule("MULT_OP", "\%\%");
			$$.type = ARITH_OP;
                }
                | T_POW
                {
                    printRule("MULT_OP", "^");
			$$.type = ARITH_OP;
                }
                ;

N_REL_OP        : T_LT
                {
                    printRule("REL_OP", "<");
		 $$.type = REL_OP;
                }
                | T_GT
                {
                    printRule("REL_OP", ">");
		$$.type = REL_OP;
                }
                | T_LE
                {
                    printRule("REL_OP", "<=");
		 $$.type = REL_OP;
                }
                | T_GE
                {
                    printRule("REL_OP", ">=");
		  $$.type = REL_OP;
                }
                | T_EQ
                {
                    printRule("REL_OP", "==");
		  $$.type = REL_OP;
                }
                | T_NE
                {
                   printRule("REL_OP", "!=");
		 $$.type = REL_OP;
                }
                ;

N_VAR           : N_ENTIRE_VAR
                {
                    printRule("VAR", "ENTIRE_VAR");
                	$$.type = $1.type;
		}
                | N_SINGLE_ELEMENT
                {
                   printRule("VAR", "SINGLE_ELEMENT");
			$$.type = $1.type;
                }
                ;

N_SINGLE_ELEMENT : T_IDENT T_LBRACKET T_LBRACKET N_EXPR
                   T_RBRACKET T_RBRACKET
                {
                    printRule("SINGLE_ELEMENT", "IDENT"
                              " [[ EXPR ]]");
                    bool check = findEntryInAnyScope(string($1));
                    if(!check)  
		    {
			cout << "single" << endl;      
                yyerror("Undefined identifier");
		    }	
			$$.type = INT_OR_STR_OR_BOOL_OR_FLOAT;
                }
                ;

N_ENTIRE_VAR    : T_IDENT
                {
                    printRule("ENTIRE_VAR", "IDENT");
  //                  bool found = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($1), $4.type,$4.numParams,$4.returnType)
			string ident = string($1);
			cout << ident << endl;
		//	TYPE_INFO exprt= findEntryInAnyScope(ident);
                    
                    if(!findEntryInAnyScope(string($1)))
                    {
			cout << "entrie" << endl;
			cout << string($1) << endl;
                      yyerror("Undefined identifier\n");
                    }
			$$.type = FUNCTION;
				
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
    printf("TOKEN: %s \t\t LEXEME: %s\n", token_type, lexeme);
}

void printRule(const char *lhs, const char *rhs)
{
    printf("%s -> %s\n", lhs, rhs);
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
