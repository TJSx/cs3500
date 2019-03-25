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
  TYPE_INFO typeInfo;
  string name;

public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) 
  { 
	  name = ""; 
    typeInfo.type = UNDEFINED; 
}

  SYMBOL_TABLE_ENTRY(const string theName, int const theType) 
  {
    name = theName;
  	updatetype(typeInfo, theType);
   //   typeInfo.type = theType;
}
  void updatetype(TYPE_INFO& thenew, int const theold)
  {
	thenew.type = theold;
  }
  // Accessors
  TYPE_INFO getTheType() const {return typeInfo;}
  string getName() const { return name; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
