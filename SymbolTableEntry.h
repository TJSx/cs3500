#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;


// type code declarations
#define UNDEFINED  -1
#define NULL_TYPE   0
#define INT         2
#define STR         4
#define BOOL        8
#define FLOAT       16
#define LIST        32
#define FUNCTION    64
#define INT_OR_BOOL 10
#define INT_OR_FLOAT_OR_BOOL 11
#define INT_OR_STR_OR_FLOAT 15
#define INT_OR_STR_OR_FLOAT_OR_BOOL     30
#define EPSILON 99
#define NOT_APPLICABLE  -1

typedef struct {
  int type;         // one of the above type codes
  int numParams;    // # of parameters if function type
  int returnType;   // return type if function
  bool is_param;
} TYPE_INFO;

class SYMBOL_TABLE_ENTRY
{
private:
  // Member variables
  string name;
  bool param_check;
  TYPE_INFO typeInfo;

public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) {
    name = "";
    typeInfo.type = UNDEFINED;
    typeInfo.numParams = UNDEFINED;
    typeInfo.returnType = UNDEFINED;
    typeInfo.is_param = false;
  }

  SYMBOL_TABLE_ENTRY(const string theName, 
                     const TYPE_INFO theType, const bool param)
  {
    name = theName;
    param_check = param;
    typeInfo.type = theType.type;
    typeInfo.numParams = theType.numParams;
    typeInfo.returnType = theType.returnType;
    typeInfo.is_param = param;	
  }

  // Accessors
  string getName() const { return name; }
  TYPE_INFO getTypeInfo() const { return typeInfo; }
  bool getParam() const { return param_check;}
};

#endif  // SYMBOL_TABLE_ENTRY_H
