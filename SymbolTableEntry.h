#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define UNDEFINED  -1
#define FUNCTION 0
#define INT 1
#define STR 2
#define FLOAT 3
#define LIST 4
#define BOOL 6
#define NULL_TYPE 5
#define INT_OR_STR_OR_BOOL_OR_FLOAT -5
#define EPSILON -3
#define NOT_APPLICABLE -2

typedef struct
{
  int type;
  int numParams;
  int returnType;
}TYPE_INFO;

class SYMBOL_TABLE_ENTRY
{
private:
  // Member variables
  TYPE_INFO type_struct;
  string name;

public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) 
  { 
	  name = ""; 
    type_struct.type = NOT_APPLICABLE; 
    type_struct.numParams = NOT_APPLICABLE;
    type_struct.returnType = NOT_APPLICABLE;
}

  SYMBOL_TABLE_ENTRY(const string theName, const int theType, const int numParams, const int returnType)
  {
    name = theName;
   // typeCode = theType;
    type_struct.type = NOT_APPLICABLE; 
    type_struct.numParams = NOT_APPLICABLE;
    type_struct.returnType = NOT_APPLICABLE;
  }

  // Accessors
  int getNumParams() const {return type_struct.numParams;}
  int getReturnType() const{return type_struct.returnType;}
  int getTheType() const {return type_struct.type;}
  
  string getName() const { return name; }
  TYPE_INFO getTypeStruct() const { return type_struct; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
