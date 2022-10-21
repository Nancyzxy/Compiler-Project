#ifndef NODE_H_HEADER_
#define NODE_H_HEADER_
typedef struct node 
{
    char * name;
    char * attribute;
    int lineNo;
    int isNon;
    struct node* child;
    struct node* next;
} node;
#endif