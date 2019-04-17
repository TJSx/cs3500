#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H
#include <stdio.h>
#include <string.h>
using namespace std;


// type code declarations
#define UNDEFINED  -1
#define NULL_TYPE   0
#define NOT_APPLICABLE -1
#define INT         2
#define STR         4
#define BOOL        8
#define FLOAT       16
#define LIST        32
#define FUNCTION    64

#define INT_OR_STR        6
#define INT_OR_BOOL       10
#define INT_OR_FLOAT      18
#define STR_OR_BOOL       12
#define STR_OR_FLOAT      20
#define BOOL_OR_FLOAT     24
#define LIST_OR_INT       34
#define LIST_OR_STR       36
#define LIST_OR_BOOL      40
#define LIST_OR_FLOAT     48

#define INT_OR_STR_OR_BOOL        14
#define INT_OR_STR_OR_FLOAT       22
#define INT_OR_BOOL_OR_FLOAT      26
#define STR_OR_BOOL_OR_FLOAT      28
#define LIST_OR_INT_OR_STR        38
#define LIST_OR_INT_OR_BOOL       42
#define LIST_OR_INT_OR_FLOAT      50
#define LIST_OR_STR_OR_BOOL       44
#define LIST_OR_STR_OR_FLOAT      52
#define LIST_OR_BOOL_OR_FLOAT     56

#define INT_OR_STR_OR_FLOAT_OR_BOOL     30
#define LIST_OR_FLOAT_OR_BOOL_OR_STR    60
#define LIST_OR_BOOL_OR_STR_OR_INT      46
#define LIST_OR_FLOAT_OR_STR_OR_INT     54
#define INT_OR_BOOL_OR_FLOAT_OR_LIST    58

#define INT_OR_BOOL_OR_STR_OR_FLOAT_OR_LIST    62

typedef struct Trial Trial;

struct Trial
{
  int type;
  int val_int;
  float val_float;
  bool val_bool;
  char val_string[256];
  int length;
  Trial* tlist;
};
typedef struct {
  int type;         // one of the above type codes
  int numParams;    // # of parameters if function type
  int returnType;   // return type if function
  int val_int;
  float val_float;
  bool val_bool;
  char val_string[256];
  Trial* tlist;
  bool is_index;
  bool is_null;
  bool is_param;
  int opType;
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
                     const TYPE_INFO theType)
  {
    name = theName;
    
    typeInfo.type = theType.type;
    typeInfo.numParams = theType.numParams;
    typeInfo.returnType = theType.returnType;
    typeInfo.is_param = theType.is_param;
    param_check = theType.is_param;
    typeInfo.val_int = theType.val_int;
    typeInfo.val_float = theType.val_float;
    typeInfo.val_bool = theType.val_bool;
    typeInfo.is_null = theType.is_null;

    typeInfo.tlist = new Trial;
    Trial *temp = theType.tlist;
    Trial *new_temp = typeInfo.tlist;
    while(temp!=NULL)
    {
      new_temp->type = temp->type;
      new_temp->val_bool = temp->val_bool;
      new_temp->val_int = temp->val_int;
      new_temp->val_float = temp->val_float;
      strcpy(new_temp->val_string, temp->val_string);
      new_temp->length = temp->length;

      temp = temp->tlist;
      if(temp!=NULL)
      {
        new_temp->tlist = NULL;
      }
      else
      {
        new_temp->tlist = NULL;

      }
      new_temp = new_temp->tlist;
    }
  }

  // Accessors
  string getName() const { return name; }
  TYPE_INFO getTypeInfo() const { return typeInfo; }
  bool getParam() const { return param_check ;}
};

#endif  // SYMBOL_TABLE_ENTRY_H
