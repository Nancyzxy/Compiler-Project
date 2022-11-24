#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 32
#define VAL_T Info

typedef struct Type
{
    char name[32];
    enum
    {
        PRIMITIVE,
        ARRAY,
        STRUCTURE
    } category;
    union
    {
        enum
        {
            Int,
            Float,
            Char
        } primitive;
        struct Array *array;
        struct FieldList *structure;
    };
} Type;

typedef struct Array
{
    struct Type *base;
    int size;
} Array;

typedef struct FieldList
{
    char name[32];
    struct Type *type;
    struct FieldList *next;
} FieldList;

typedef struct Info
{
    Type type;
    Type return_type;
    Type *parameter;
} Info;

/* symbol table entry, only used internally */
typedef struct entry
{
    char key[KEY_LEN + 1];
    VAL_T value;
} entry;

/*
 * symbol table type, binary tree impl
 */
struct _node
{
    entry entry;
    struct _node *left, *right;
};

typedef struct _node symtab;

void entry_init(entry *self, char *key, VAL_T value);

// init a single symbol table
symtab *symtab_init();

// insert a key-value pair to the table
// if insert success, return 1, otherwise 0
int symtab_insert(symtab *, char *, VAL_T);

// lookup the value of a specific key
// return -1 if not found
VAL_T symtab_lookup(symtab *, char *);

// remove a key-value pair from the table
// if remove success, return 1, otherwise 0
int symtab_remove(symtab *, char *);

#endif /* SYMTAB_H */
