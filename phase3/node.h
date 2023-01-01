#ifndef NODE_H_HEADER_
#define NODE_H_HEADER_
#include "symtab.h"
typedef struct node 
{
    char * name;
    char * attribute;
    int lineNo;
    int isEmpty;
    struct node* child;
    struct node* next;
    int lvalue; // only use with expression, when the expression is a lvalue;
    Type* type;
} node;
#endif