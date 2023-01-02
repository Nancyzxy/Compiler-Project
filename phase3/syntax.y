%{
    #include "lex.yy.c"
    #include "node.h"
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include"symtab.c"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    int flag = 0;
    int cnt1=0;
    int cnt2=0;
    int line = 0;
    int count1 = 1;
    int count2 = 1;
    symtab* root;
    node* insert(char* parent,int count,...);
    void yyerror(const char*);
    node* alloNodeI(int a,char * Name);
    node* alloNodeF(float a,char * Name);
    node* alloNodeC(char* a,char * Name);
    void printTree(node* root,int blank);
    int compareType(Type* type1, Type* type2);
    int confirmReturnType(node* root,char * returnType);
    int confirmArgsType(node* root,ParaList* parameters);
    char* new_place();
    char* new_label();
    char* translate_cond_Exp(node* Exp, char* lb1, char* lb2);
    char* translate_stmt(node* stmt);
    char* translate_Exp(node* Exp, char* place);
    char* translate_Args(node* Args, int* arglist);
    char* translate_def(node* def);
%}

%union{
    node* treeNode;
    int int_value;
    float float_value;
    char* string_value;
}
%token<int_value> INT 
%token<string_value>FLOAT 
%token<string_value>CHAR ID TYPE INCLUSION DEFINE
%token<treeNode> STRUCT IF WHILE RETURN SEMI COMMA FOR READ WRITE
%type <treeNode> Args Exp Dec DecList Def DefList Stmt StmtList CompSt ParamDec VarList FunDec VarDec StructSpecifier Specifier ExtDecList ExtDef ExtDefList Program Header Headers
%nonassoc<treeNode> LOWER_ELSE
%nonassoc<treeNode> ELSE

%right<treeNode> ASSIGN
%left<treeNode> OR
%left<treeNode> AND
%left<treeNode> NE EQ
%left<treeNode> LT LE GT GE
%left<treeNode> PLUS MINUS
%left<treeNode> MUL DIV
%right<treeNode> NOT
%left<treeNode> LP RP LB RB LC RC DOT
%left<string_value> FAULT
%%

Program : Headers ExtDefList {
    $$ = insert("Program",2,$1,$2);
    @$ = @1;$$->lineNo=(@1).first_line;
    // if(flag ==0){printTree($$,0);}
    };

Headers : Headers Header {$$ = insert("Headers",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;}
    | {$$ = insert("Headers",0);}
    ;
Header : INCLUSION {$$=insert("Header",1,alloNodeC($1,"INCLUSION"));@$ = @1;$$->lineNo=(@1).first_line;}
    | DEFINE {$$=insert("Header",1,alloNodeC($1,"DEFINE"));@$ = @1;$$->lineNo=(@1).first_line;}
    ;

ExtDefList: ExtDef ExtDefList { $$ = insert("ExtDefList",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;}
          | {$$ = insert("ExtDefList",0);}
          ;

ExtDef:  Specifier ExtDecList SEMI {$$ = insert("ExtDef",3,$1,$2,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;
    node* pointer = $2->child; // VarDec
                while(1){
                    if(strcmp(pointer->child->name, "ID") == 0){
                        if(symtab_lookup(root, pointer->child->attribute)->a != -1){
                        printf("Error type 3 at Line %d: redefine variable: %s\n", (@1).first_line,pointer->child->attribute);
                        }
                        else{
                            //todo
                            if(strcasecmp($1->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = $1->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->return_type = NULL;
                                val->paraList = NULL;
                                val->a = 0;
                                val->t = -1;
                                symtab_insert(root, pointer->child->attribute, *val);
                            }else{//插入结构体的声明
                                // printf("1");
                                struct Info *info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = $1->child->child->next->attribute; //结构体名字
                                type->category = STRUCTURE;
                                info->type = type;
                                info->a = 3;
                                info->t = -1;
                                symtab_insert(root, pointer->child->attribute, *info);
                            }
                        }
                }else{
                        //VarDec LB INT RB
                        node *pp = pointer->child; //VarDeC或者ID
                        // printf("%s\n", pp->attribute);
                            if(strcmp(pp->child->name, "ID") == 0){//一维数组
                                if(symtab_lookup(root, pp->child->attribute)->a != -1){//是否重复ID
                                    printf("Error type 3 at Line %d: redefine variable: %s 111\n", (@1).first_line,pp->child->attribute);
                                }else{
                                    struct Info *val = malloc(sizeof(Info));
                                    struct Type *typehead = malloc(sizeof(Type));
                                    struct Array *arr = malloc(sizeof(Array));
                                    arr->size = atoi(pp->next->next->attribute); //int值
                                    if(strcasecmp($1->child->name, "type") == 0){
                                        typehead->name = $1->child->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->name = $1->child->attribute;
                                    }
                                    else{//结构体数组
                                        typehead->name = $1->child->child->next->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->category = STRUCTURE;
                                        arr->base->name = $1->child->child->next->attribute;
                                    }
                                    typehead->category = ARRAY;
                                    typehead->array = arr;
                                    val->a = 1; 
                                    val->type = typehead;
                                    val->return_type = NULL;
                                    val->paraList = NULL;
                                    val->t = -1;
                                    symtab_insert(root, pp->child->attribute, *val);
                                }    
                            }else {//二维数组
                                node *pid = pp->child; //ID
                                if(symtab_lookup(root, pid->child->attribute)->a != -1){//是否重复ID
                                    printf("Error type 3 at Line %d: redefine variable: %s\n", (@1).first_line,pp->child->child->attribute);
                                }else{
                                    //一维结构
                                    struct Info *val = malloc(sizeof(Info));
                                    struct Type *typehead = malloc(sizeof(Type));
                                    struct Array *arr = malloc(sizeof(Array));
                                    arr->size_col = atoi(pp->next->next->attribute); //int 列值
                                    arr->size = atoi(pp->child->next->next->attribute);//行值
                                    if(strcasecmp($1->child->name, "type") == 0){
                                        typehead->name = $1->child->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->name = $1->child->attribute;
                                    }
                                    else{//结构体数组
                                        typehead->name = $1->child->child->next->attribute;
                                        arr->base = malloc(sizeof(Type));
                                        arr->base->category = STRUCTURE;
                                        arr->base->name = $1->child->child->next->attribute;
                                    }
                                    typehead->category = ARRAY;
                                    typehead->array = arr;
                                    val->a = 1; 
                                    val->type = typehead;
                                    val->return_type = NULL;
                                    val->paraList = NULL;
                                    val->t = -1;
                                    symtab_insert(root, pp->child->child->attribute, *val);
                                }
                                
                            }
                }
                if(pointer->next==NULL) break;
                pointer = pointer->next->next->child; //到下一个VarDec
                }
}
      | Specifier SEMI {$$ = insert("ExtDef",2,$1,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line; 
      //specifier->structspecifier->STRUCT ID LC DefList RC
            if(symtab_lookup(root, $1->child->child->next->attribute)->a ==3){
                printf("Error type 15 at Line %d: redefine struct: %s\n",(@1).first_line,$1->child->child->next->attribute);
            }
            //DefList->def->DecList->Dec->VarDec->ID | VarDec LB INT RB 
            //插入结构体
            else{
                                struct Info* info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                info->a = 3;
                                type->category = STRUCTURE;
                                type->name = $1->child->child->next->attribute; //struct名字
                                // printf("%s\n",type->name);
                                struct FieldList *struct_element;
                                if($1->child->child->next->next != NULL){//存在DefList
                                    node *cur = $1->child->child->next->next->next; //DefList
                                    // printf("%s\n",cur->name);
                                    struct_element = malloc(sizeof(FieldList));
                                    struct Type *struct_type = malloc(sizeof(Type));
                                    struct_type->name = cur->child->child->child->attribute;//struct中元素的类型
                                    // printf("%s\n", cur->child->child->next->name);//DecList
                                    if(cur->child->child->next->child->child->child->next != NULL){//struct中的数组名字,假设是一维数组
                                        node *vardec = cur->child->child->next->child->child->child;
                                        if(vardec->child->next != NULL){
                                            //结构体中二维数组
                                            struct_element->name = vardec->child->child->attribute;
                                            // printf("%s\n",struct_element->name);
                                        }else{
                                            struct_element->name = vardec->child->attribute;
                                            // printf("%s\n",struct_element->name);
                                        }
                                        struct_type->category = ARRAY;
                                    }else {
                                        struct_element->name = cur->child->child->next->child->child->child->attribute;
                                        struct_type->category = PRIMITIVE;
                                    }
                                    // printf("%s\n",struct_element->name); // id名字
                                    struct_element->type = struct_type;
                                    struct Info* info0 = malloc(sizeof(Info));
                                    info->type = struct_type;
                                    info0->t = -1;
                                    symtab_insert(root,struct_element->name,*info0);
                                    struct_element->next = NULL;
                                    type->structure = struct_element;
                                    // printf("%s\n",type->structure->name);
                                    struct FieldList *curField = struct_element;
                                    while(!cur->child->next->isEmpty){
                                        cur = cur->child->next;
                                        // printf("%s\n",cur->name); // DefList
                                        // printf("%s\n",cur->child->name);
                                        struct Type *element_type = malloc(sizeof(Type));
                                        element_type->name =  cur->child->child->child->attribute;
                                        // printf("%s\n", element_type->name);
                                        struct FieldList *field = malloc(sizeof(FieldList));
                                        if(cur->child->child->next->child->child->child->next != NULL){//struct中的数组名字,假设是一维数组
                                            node *var = cur->child->child->next->child->child->child;
                                            if(var->child->next != NULL){
                                                field->name = var->child->child->attribute;
                                            }else {
                                                field->name = var->child->attribute;
                                            }
                                            element_type->category = ARRAY;
                                        }else {
                                            field->name = cur->child->child->next->child->child->child->attribute;
                                            element_type->category = PRIMITIVE;
                                        }
                                        // printf("%s\n",field->name);
                                        field->next = NULL;
                                        field->type = element_type;
                                        struct Info* info1 = malloc(sizeof(Info));
                                        info->type = element_type;
                                        info1->t = -1;
                                        symtab_insert(root,field->name,*info1);
                                        curField->next = field;
                                        // printf("1: %s\n", curField->name);
                                        curField = curField->next; 
                                        // printf("2: %s\n", curField->name);
                                    }
                                }else {
                                    struct_element = NULL;
                                }
                                info->type = type;
                                info->t = -1;
                                // printf("%s\n",info->type->name);
                                symtab_insert(root, $1->child->child->next->attribute, *info);
            }  
      }
      | Specifier FunDec CompSt {$$ = insert("ExtDef",3,$1,$2,$3);@$ = @1;$$->lineNo=(@1).first_line;
                node* defList = $3->child->next;
                while(defList->child != NULL){
                    printf("%s",translate_def(defList->child));
                    defList = defList->child->next;
                }
                node* stmtList = $3->child->next->next;
                while(stmtList->child != NULL){
                    printf("%s",translate_stmt(stmtList->child));
                    stmtList = stmtList->child->next;
                }
                 
      }
      ;

ExtDecList: VarDec {$$ = insert("ExtDecList",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
          | VarDec COMMA ExtDecList {$$ = insert("ExtDecList",3,$1,alloNodeC(",","COMMA"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
          ;

/* specifier */
Specifier: TYPE {$$ = insert("Specifier",1,alloNodeC($1,"TYPE"));@$ = @1;$$->lineNo=(@1).first_line;}
         | StructSpecifier {$$ = insert("Specifier",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
         ;

StructSpecifier: STRUCT ID LC DefList RC {
                $$ = insert("StructSpecifier",5,
                alloNodeC("struct","STRUCT"),
                alloNodeC($2,"ID"),
                alloNodeC("{","LC"),
                $4,
                alloNodeC("}","RC")
                );
                @$ = @1;$$->lineNo=(@1).first_line;}
               | STRUCT ID {$$ = insert("StructSpecifier",2,alloNodeC("struct","STRUCT"),alloNodeC($2,"ID"));@$ = @1;$$->lineNo=(@1).first_line;}
               ;

/* declarator */
VarDec: ID {$$ = insert("VarDec",1,alloNodeC($1,"ID"));@$ = @1;$$->lineNo=(@1).first_line;}
      | VarDec LB INT RB {$$ = insert("VarDec",4,$1,alloNodeC("[","LB"),alloNodeI($3,"INT"),alloNodeC("]","RB"));@$ = @1;$$->lineNo=(@1).first_line;}
      | FAULT error {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",(@1).first_line,$1);}
      | VarDec LB error RB {flag=1; printf("Error type B at Line %d: Wrong type of index\n",(@1).first_line);}
      ;

FunDec: ID LP VarList RP {$$ = insert("FunDec",4,alloNodeC($1,"ID"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;
    if(symtab_lookup(root, $$->child->attribute)->a != -1){printf("Error type 4 at Line %d: redefine function: %s\n",(@1).first_line,$$->child->attribute);}
            else{
              struct Info *val = malloc(sizeof(Info));
              struct Type *returnType = malloc(sizeof(Type));
              returnType->name= "int";
              returnType->category = PRIMITIVE;//todo
              struct ParaList *paralist;
              val->type = NULL;
              if($$->child->next->next->next != NULL){
                    node* cur = $$->child->next->next->child;
                    struct Type *para = malloc(sizeof(Type));
                    para->name = cur->child->child->attribute;
                    para->category = PRIMITIVE;//todo
                    paralist = malloc(sizeof(ParaList));
                    paralist->type = para;
                    paralist->next = NULL;
                    struct ParaList *curpara = paralist;
                    while(cur->next != NULL){
                        cur = cur->next->next->child;
                        struct Type* paraType = malloc(sizeof(Type));
                        paraType->name = cur->child->child->attribute;
                        paraType->category = PRIMITIVE;
                        struct ParaList *nextPara = malloc(sizeof(ParaList));
                        nextPara->type = paraType;
                        nextPara->next = NULL;
                        curpara->next = nextPara;
                        curpara = curpara->next;
                    }
                }
                else{
                    paralist = NULL;
                }
                val->a = 2;
                val->return_type = returnType;
                val->paraList = paralist;
                val->t = -1;
                symtab_insert(root, $$->child->attribute, *val);
                printf("FUNCTION %s :\n", $$->child->attribute);
                node* varList = $$->child->next->next;
                char* place = new_place();
                Info *id = symtab_lookup(root, varList->child->child->next->child->attribute);
                id->t = count1 - 1;
                printf("PARAM %s\n", place);
                while(varList->child->next != NULL){
                    place = new_place();
                    printf("PARAM %s\n", place);
                    varList = varList->child->next->next;
                    Info *id1 = symtab_lookup(root, varList->child->child->next->child->attribute);
                    id1->t = count1 - 1;
                }
                
                
            }  

       
      }
      ;
      | ID LP RP {$$ = insert("FunDec",3,alloNodeC($1,"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;
            if(symtab_lookup(root, $$->child->attribute)->a != -1){printf("Error type 4 at Line %d: redefine function: %s\n",(@1).first_line,$$->child->attribute);}
            else{
              struct Info *val = malloc(sizeof(Info));
              struct Type *returnType = malloc(sizeof(Type));
              returnType->name= "int";
              returnType->category = PRIMITIVE;//todo
              struct ParaList *paralist;
              val->type = NULL;
              paralist = NULL;  
                val->a = 2;
                val->return_type = returnType;
                val->paraList = paralist;
                val->t = -1;
                symtab_insert(root, $$->child->attribute, *val);
                printf("FUNCTION %s :\n", $$->child->attribute);
                 
      }
      }
      | ID LP error {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(@2).first_line);}
      ;

VarList: ParamDec COMMA VarList {$$ = insert("VarList",3,$1,alloNodeC(",","COMMA"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
       | ParamDec {$$ = insert("VarList",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
       ;

ParamDec: Specifier VarDec {$$ = insert("ParamDec",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;
                if(strcmp($2->child->name, "ID") == 0){
                    if(symtab_lookup(root, $2->child->attribute)->a != -1){
                    printf("Error type 3 at Line %d: redefine variable: %s\n", (@1).first_line,$2->child->attribute);
                    }
                    else{
                            if(strcmp($1->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = $1->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->a = 0;
                                val->t = -1;
                                symtab_insert(root, $2->child->attribute, *val);
                            }
                    }
                }
 };
        

/* statement */
CompSt: LC DefList StmtList RC {$$ = insert("CompSt",4,alloNodeC("{","LC"),$2,$3,alloNodeC("}","RC"));@$ = @1;$$->lineNo=(@4).first_line;}
      | LC DefList StmtList error {flag=1; printf("Error type B at Line %d: Missing specifier\n",(@3).first_line);}
      ;

StmtList: Stmt StmtList  {$$ = insert("StmtList",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;}
        |   {$$ = insert("StmtList",0);}
        ;

Stmt: Exp SEMI {$$ = insert("Stmt",2,$1,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;
}
    | CompSt {$$ = insert("Stmt",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
    | RETURN Exp SEMI {$1 =alloNodeC("return","RETURN"); $1->lineNo=(@1).first_line; $$ = insert("Stmt",3,$1,$2,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;
    }
    | IF LP Exp RP Stmt %prec LOWER_ELSE {$$ = insert("Stmt",5,alloNodeC("if","IF"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"),$5);@$ = @1;$$->lineNo=(@1).first_line;}
    | IF LP Exp RP Stmt ELSE Stmt {$$ = insert("Stmt",7,alloNodeC("if","IF"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"),$5,alloNodeC("else","ELSE"),$7);@$ = @1;$$->lineNo=(@1).first_line;}
    | WHILE LP Exp RP Stmt {$$ = insert("Stmt",5,alloNodeC("while","WHILE"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"),$5);@$ = @1;$$->lineNo=(@1).first_line;}
    | RETURN Exp error {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",(@2).first_line); }
    | FOR LP Exp SEMI Exp SEMI Exp RP Stmt {$$ = insert("Stmt",9,alloNodeC("for","FOR"),alloNodeC("(","LP"),$3,alloNodeC(";","SEMI"),$5,alloNodeC(";","SEMI"),$7,alloNodeC(")","RP"),$9);@$ = @1;$$->lineNo=(@1).first_line;}
    | Exp error {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",(@1).first_line); }
    ;

/* local definition */
DefList: Def DefList {$$ = insert("DefList",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;}
       |    /*empty terminal*/  {$$ = insert("DefList",0);
       
       }
       ;

Def: Specifier DecList SEMI {$$ = insert("Def",3,$1,$2,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;
                node* pointer = $2->child;
                while(1){
                    if(strcmp(pointer->child->child->name, "ID") == 0){
                        if(symtab_lookup(root, pointer->child->child->attribute)->a != -1){
                        printf("Error type 3 at Line %d: redefine variable: %s\n", (@1).first_line,pointer->child->child->attribute);
                        }
                        else{
                            //todo
                            if(strcasecmp($1->child->name, "TYPE") == 0){
                                struct Info *val = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = $1->child->attribute;
                                type->category = PRIMITIVE;
                                val->type = type;
                                val->return_type = NULL;
                                val->paraList = NULL;
                                val->a = 0;
                                val->t = -1;
                                symtab_insert(root, pointer->child->child->attribute, *val);
                                Type *baseval = type;
                                Type *cmpVal;
                                if(pointer->child->next != NULL){
                                    cmpVal = pointer->child->next->next->type;
                                    if(compareType(baseval, cmpVal) == 0){
                                        printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                                    }
                                }
                            }else{//插入结构体的声明
                            //DecList->Dec->VarDec->ID
                                // printf("1");
                                struct Info *info = malloc(sizeof(Info));
                                struct Type *type = malloc(sizeof(Type));
                                type->name = $1->child->child->next->attribute; //结构体名字
                                type->category = STRUCTURE;
                                info->type = type;
                                info->a = 3;
                                info->t = -1;
                                symtab_insert(root, pointer->child->child->attribute, *info);
                            }
                        }
                }else{
                    //数组
                    
                    //首先判断是否为二维
                    if(pointer->child->child->child->next != NULL){
                        //二维
                        // printf("%s\n",pointer->child->child->child->child->attribute);
                        if(symtab_lookup(root, pointer->child->child->child->child->attribute)->a != -1){//ExtDecList->VarDec->VarDec->ID
                            printf("Error type 3 at Line %d: redefine variable: %s\n", (@1).first_line,pointer->child->child->child->child->attribute);
                        }else{
                            struct Info *val = malloc(sizeof(Info));
                            struct Type *typehead = malloc(sizeof(Type));
                            struct Array *arr = malloc(sizeof(Array));
                            arr->size_col =atoi(pointer->child->child->next->next->attribute); //int col size
                            arr->size = atoi(pointer->child->child->child->next->next->attribute);
                            if(strcasecmp($1->child->name, "type") == 0){
                                typehead->name = $1->child->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->name = $1->child->attribute;
                            }
                            else{
                                typehead->name = $1->child->child->next->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->category = STRUCTURE;
                                arr->base->name = $1->child->child->next->attribute;
                            }
                        // type类型
                            typehead->category = ARRAY;
                            typehead->array = arr;
                            val->a = 1; 
                            val->type = typehead;
                            val->return_type = NULL;
                            val->paraList = NULL;
                            val->t = -1;
                            symtab_insert(root, pointer->child->child->child->child->attribute, *val);
                            Type *baseval = typehead;
                            Type *cmpVal;
                            if(pointer->child->next != NULL){
                                cmpVal = pointer->child->next->next->type;
                                if(compareType(baseval, cmpVal) == 0){
                                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                                }
                            }
                            

                        }
                    }else{//一维
                        if(symtab_lookup(root, pointer->child->child->child->attribute)->a != -1){//ExtDecList->VarDec->VarDec->ID
                            printf("Error type 3 at Line %d: redefine variable: %s \n", (@1).first_line,pointer->child->child->child->attribute);
                        }else{
                            struct Info *val = malloc(sizeof(Info));
                            struct Type *typehead = malloc(sizeof(Type));
                            struct Array *arr = malloc(sizeof(Array));
                            arr->size =atoi(pointer->child->child->next->next->attribute); //int size
                            arr->size_col = -1;
                            if(strcasecmp($1->child->name, "type") == 0){
                                typehead->name = $1->child->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->name = $1->child->attribute;
                            }
                            else{
                                typehead->name = $1->child->child->next->attribute;
                                arr->base = malloc(sizeof(Type));
                                arr->base->category = STRUCTURE;
                                arr->base->name = $1->child->child->next->attribute;
                            }
                        // type类型
                            typehead->category = ARRAY;
                            typehead->array = arr;
                            val->a = 1; 
                            val->type = typehead;
                            val->return_type = NULL;
                            val->paraList = NULL;
                            val->t = -1;
                            symtab_insert(root, pointer->child->child->child->attribute, *val);
                            Type *baseval = typehead;
                            Type *cmpVal;
                            if(pointer->child->next != NULL){
                                cmpVal = pointer->child->next->next->type;
                                if(compareType(baseval, cmpVal) == 0){
                                    printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                                }
                            }
                    }
                        
                    }
                    
                }
                if(pointer->next==NULL) break;
                pointer = pointer->next->next->child;
                }
                
}
    |Specifier DecList error{flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",(@2).first_line);}
   ;

DecList: Dec {$$ = insert("DecList",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
       | Dec COMMA DecList {$$ = insert("DecList",3,$1,alloNodeC(",","COMMA"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
       ;

Dec: VarDec {$$=insert("Dec",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
   | VarDec ASSIGN Exp {$$=insert("Dec",3,$1,alloNodeC("=","ASSIGN"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   ;

/* Expression */
Exp: Exp ASSIGN Exp {$2 = alloNodeC("=","ASSIGN");$$=insert("Exp",3,$1,$2,$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type, $3->type) == 0){
                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
        }
        if($1->lvalue==0){
            printf("Error type 6 at Line %d: left side in assignment is rvalue\n",(@1).first_line);
        }
}
   | Exp AND Exp {$$=insert("Exp",3,$1,alloNodeC("&&","AND"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp OR Exp {$$=insert("Exp",3,$1,alloNodeC("||","OR"),$3);@$ = @1;$$->lineNo=(@1).first_line;
    if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
    }
   | Exp LT Exp {$$=insert("Exp",3,$1,alloNodeC("<","LT"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp LE Exp {$$=insert("Exp",3,$1,alloNodeC("<=","LE"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
    }
   | Exp GT Exp {$$=insert("Exp",3,$1,alloNodeC(">","GT"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
    }
   | Exp GE Exp {$$=insert("Exp",3,$1,alloNodeC(">=","GE"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp NE Exp {$$=insert("Exp",3,$1,alloNodeC("!=","NE"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp EQ Exp {$$=insert("Exp",3,$1,alloNodeC("==","EQ"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp PLUS Exp {$$=insert("Exp",3,$1,alloNodeC("+","PLUS"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp MINUS Exp {$$=insert("Exp",3,$1,alloNodeC("-","MINUS"),$3);@$ = @1;$$->lineNo=(@1).first_line;
        if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
    }
   | Exp MUL Exp {$$=insert("Exp",3,$1,alloNodeC("*","MUL"),$3);@$ = @1;$$->lineNo=(@1).first_line;
    if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | Exp DIV Exp {$$=insert("Exp",3,$1,alloNodeC("/","DIV"),$3);@$ = @1;$$->lineNo=(@1).first_line;
   if(compareType($1->type,$3->type)==0){
            printf("Error type 7 at Line %d: binary operation on non-number variables\n",(@1).first_line);
        }
        $$->type = malloc(sizeof(Type));
        $$->type = $1->type; 
   }
   | LP Exp RP {$$=insert("Exp",3,alloNodeC("(","LP"),$2,alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;
        $$->type = malloc(sizeof(Type));
        $$->type = $2->type; 
   }
   | MINUS Exp {$$=insert("Exp",2,alloNodeC("-","MINUS"),$2);@$ = @1;$$->lineNo=(@1).first_line;
        $$->type = malloc(sizeof(Type));
        $$->type = $2->type; //todo
   }
   | NOT Exp {$$=insert("Exp",2,alloNodeC("!","NOT"),$2);@$ = @1;$$->lineNo=(@1).first_line;
        $$->type = malloc(sizeof(Type));
        $$->type = $2->type;
   }
   | ID LP Args RP {$$=insert("Exp",4,alloNodeC($1,"ID"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;
        Info* val =symtab_lookup(root,$$->child->attribute);
        if(val->a!=-1){
            if(val->a == 2){
                if(confirmArgsType($3,val->paraList)==0){
                    if(cnt2==cnt1){
                        printf("Error type 9 at Line %d: invalid argument type for compare\n",(@1).first_line);
                    }
                    else printf("Error type 9 at Line %d: invalid argument number for compare, expect %d, got %d\n",(@1).first_line,cnt2,cnt1);
                } $$->type = val->return_type;
            }else {
                $$->type = val->type;
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n", (@1).first_line, $1);
            }
        }else printf("Error type 2 at Line %d: undefined function: %s\n", (@1).first_line,$1);
        
   }
   | ID LP RP {$$=insert("Exp",3,alloNodeC($1,"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;
        Info* val = symtab_lookup(root,$$->child->attribute);
        if(val->a!=-1){
            if(val->a==2){
                if(val->paraList!=NULL){
                    printf("Error type 9 at Line %d: a function's arguments mismatch the declared parameters",(@1).first_line);
                }else $$->type = val->return_type;
            }else {
                printf("Error type 11 at Line %d: invoking non-function variable: %s\n", (@1).first_line, $1);
            }
        }
        else {
            printf("Error type 2 at Line %d : function %s is used without definition\n", (@1).first_line,$1);}
   }
   | Exp LB Exp RB {$$=insert("Exp",4,$1,alloNodeC("[","LB"),$3,alloNodeC("]","RB"));@$ = @1;$$->lineNo=(@1).first_line; $$->lvalue=1;
        Info* val;
        if(strcasecmp($1->child->name, "exp") == 0){
            if($1->child->child != NULL){
                //二维数组
                // printf("%s\n",$1->child->child->attribute);
                val = symtab_lookup(root, $1->child->child->attribute);
            }else{
                val = symtab_lookup(root,$1->child->next->next->attribute);
            }
        }
        else{
            val = symtab_lookup(root,$1->child->attribute);
        } 
        if(val->type->category != ARRAY)
        {
            printf("Error type 10 at Line %d: indexing on non-array variable\n", (@1).first_line);
        }   
        else{
            if(strcasecmp($3->type->name,"int")!=0){
                printf("Error type 12 at Line %d: indexing by non-integer\n", (@1).first_line);
            }
            if($1->child->child != NULL){
                $$->type = $1->child->type->array->base;
            }else{
                $$->type = $1->type->array->base; 
            }
        }
   }
   | Exp DOT ID {$$=insert("Exp",3,$1,alloNodeC(".","DOT"),alloNodeC($3,"ID"));@$ = @1;$$->lineNo=(@1).first_line;$$->lvalue=1;
        //struct的类属性
         if($1->type->category != STRUCTURE){
             printf("Error type 13 at Line %d: accessing with non-struct variable\n", (@1).first_line);
         }else{
         char *struct_name = $1->type->name;
            // printf("%s\n",struct_name); 
            struct Info* info = symtab_lookup(root, struct_name);
            struct FieldList *ele = info->type->structure;
            int f = 0;
            while(ele != NULL){
            if(strcmp(ele->name,$$->child->next->next->attribute) == 0){
                f = 1;
                break;
            }
            ele = ele->next;
            }
            if(f == 0){
                printf("Error type 14 at Line %d: no such member: %s\n",(@1).first_line, $$->child->next->next->attribute);
            }
        } 
        $$->type = symtab_lookup(root,$$->child->next->next->attribute)->type; 
   }
   | ID {$$=insert("Exp",1,alloNodeC($1,"ID"));@$ = @1;$$->lineNo=(@1).first_line; $$->lvalue=1;
        $$->type = symtab_lookup(root,$$->child->attribute)->type;
        if(symtab_lookup(root, $$->child->attribute)->a == -1){
            printf("Error type 1 at Line %d: undefined variable: %s\n", (@1).first_line,$1);
        }
   }
   | INT {$$=insert("Exp",1,alloNodeI($1,"INT"));@$ = @1;$$->lineNo=(@1).first_line;
        $$->type = malloc(sizeof(Type));
        $$->type->name = "int";
        $$->type -> category = PRIMITIVE;
   }
   | FLOAT {$$=insert("Exp",1,alloNodeC($1,"FLOAT"));@$ = @1;$$->lineNo=(@1).first_line;
        $$->type = malloc(sizeof(Type));
        $$->type->name = "float";
        $$->type -> category = PRIMITIVE;
   }
   | CHAR {$$=insert("Exp",1,alloNodeC($1,"CHAR"));@$ = @1;$$->lineNo=(@1).first_line;
        $$->type = malloc(sizeof(Type));
        $$->type->name = "char";
        $$->type-> category = PRIMITIVE;
   }
   | READ LP RP{$$=insert("Exp",3,alloNodeC("read","READ"),alloNodeC("(","LP"),alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;}
   | WRITE LP Exp RP{$$=insert("Exp",4, alloNodeC("write","WRITE"), alloNodeC("(", "LP"), $3, alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;}
   | FAULT error {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",(@1).first_line,$1);}
   | ID LP Args error {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(@3).first_line);}
   | Exp FAULT Exp error{flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",(@2).first_line,$2);};

Args: Exp COMMA Args {$2= alloNodeC(",","COMMA"); $$ = insert("Args",3,$1,$2,$3);@$ = @1;$$->lineNo=(@1).first_line;}
    | Exp {$$ = insert("Args",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d\n", s, yylineno);
}
char* translate_def(node* def){
    node* decList = def->child->next;
    char* code = malloc(1024);
    if(strcasecmp(def->child->child->name, "type") == 0){
        while(decList->child->next != NULL){//有comma
            node* dec = decList->child;
            if(dec->child->next == NULL){//assign
                node* varDec = dec->child;
                if(strcasecmp(varDec->child->name, "vardec") == 0){//array
                    while(strcasecmp(varDec->child->name, "vardec") == 0){
                        varDec = varDec->child; //找到array name
                    }
                    Info* arr = symtab_lookup(root, varDec->child->attribute);
                    int size = 0;
                    if(arr->type->array->size_col == -1){
                        size = arr->type->array->size * 4;
                    }
                    else {
                       size = arr->type->array->size * arr->type->array->size_col * 4; 
                    }
                    char* tp = new_place();
                    arr->t = count1 - 1;
                    sprintf(code, "%sDEC %s %d\n", code, tp, size);
                }else{
                    //int n
                    Info* val = symtab_lookup(root,varDec->child->attribute);
                    char* tp = new_place();
                    val->t = count1-1;
                }
            }
            else{
                Info* id = symtab_lookup(root, dec->child->child->attribute);
                char* tp = new_place();
                id->t = count1-1;
                tp = new_place();
                char* code1 = translate_Exp(dec->child->next->next, tp);
                char* code2 = malloc(64);
                sprintf(code2, "t%d := %s\n", id->t, tp);
                sprintf(code, "%s%s%s",code,code1,code2);
            }
            decList = decList->child->next->next;
        }
        node* dec = decList->child;
        if(dec->child->next == NULL){
            node* varDec = dec->child;
            if(strcasecmp(varDec->child->name, "vardec") == 0){
                while(strcasecmp(varDec->child->name, "vardec") == 0){
                    varDec = varDec->child;
                }
                Info* arr = symtab_lookup(root, varDec->child->attribute);
                int size = 0;
                if(arr->type->array->size_col == -1){
                    size = arr->type->array->size * 4;
                }
                else {
                    size = arr->type->array->size * arr->type->array->size_col * 4; 
                }
                char* tp = new_place();
                arr->t = count1 - 1;
                char* buff = malloc(1024);
                sprintf(code, "%sDEC %s %d\n", code, tp, size);
            }else{
                Info* val = symtab_lookup(root,varDec->child->attribute);
                char* tp = new_place();
                val->t = count1-1;
            }
        }else{
            Info* id = symtab_lookup(root, dec->child->child->attribute);
            char* tp = new_place();
            id->t = count1-1;
            tp = new_place();
            char* code1 = translate_Exp(dec->child->next->next, tp);
            char* code2 = malloc(64);
            sprintf(code2, "t%d := %s\n", id->t, tp);
            sprintf(code, "%s%s%s",code,code1,code2);
        }
        }
    else{
        return NULL;
    }
    return code;
}
char* translate_cond_Exp(node* Exp, char* lb1, char* lb2){
    if(strcasecmp(Exp->child->name, "LP")==0){
        //LP Exp RP
        return translate_cond_Exp(Exp->child->next,lb1,lb2);
    }
    if(strcasecmp(Exp->child->next->name, "AND") == 0){
        char* lb = new_label();
        char* code1 = translate_cond_Exp(Exp->child, lb, lb2);
        char* code2 = translate_cond_Exp(Exp->child->next->next, lb1, lb2);
        char* code3 = malloc(1024);
        sprintf(code3,"%sLABEL %s :\n%s",code1,lb,code2);
        return code3;
    }
    if(strcasecmp(Exp->child->next->name, "OR") == 0){
        char* lb = new_label();
        char* code1 = translate_cond_Exp(Exp->child, lb1, lb);
        char* code2 = translate_cond_Exp(Exp->child->next->next, lb1, lb2);
        char* code3 = malloc(1024);
        sprintf(code3,"%sLABEL %s :\n%s",code1,lb,code2);
        return code3;
    }
    if(strcasecmp(Exp->child->next->name, "LT") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s < %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "LE") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s <= %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "GT") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s > %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "GE") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s >= %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "EQ") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s == %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->next->name, "NE") == 0){
        char* t1 = new_place();
        char* t2 = new_place();
        char* code1 = translate_Exp(Exp->child,t1);
        char* code2 = translate_Exp(Exp->child->next->next,t2);
        char* code3 = malloc(1024);
        sprintf(code3,"IF %s != %s GOTO %s\nGOTO %s\n",t1,t2,lb1,lb2);
        char* code4 = malloc(1024);
        sprintf(code4,"%s%s%s",code1,code2,code3);
        return code4;
    }
    if(strcasecmp(Exp->child->name, "NOT") == 0){
        return translate_cond_Exp(Exp->child->next,lb2,lb1);

    }
}

char* translate_stmt(node* stmt){
    if(strcasecmp(stmt->child->name, "Exp") == 0){
        char* tp = new_place();
        char* buff = malloc(1024);
        sprintf(buff,"%s",translate_Exp(stmt->child, tp));
        return buff;
    }
    if(strcasecmp(stmt->child->name, "Compst") == 0){
        char* code1 = malloc(1024);
        node* defList = stmt->child->child->next;
        while(defList->child != NULL){
            sprintf(code1,"%s%s", code1, translate_def(defList->child));
            defList = defList->child->next;
        }
        char* code2 = malloc(1024);
        node* stmtList = stmt->child->child->next->next;
        while(stmtList->child != NULL){
            sprintf(code2,"%s%s",code2,translate_stmt(stmtList->child));
            stmtList = stmtList->child->next;
        }
        sprintf(code2, "%s%s", code1, code2);
        return code2;
    }
    if(strcasecmp(stmt->child->name, "IF") == 0){
        if(stmt->child->next->next->next->next->next!=NULL){
        //IF LP Exp RP Stmt ELSE Stmt
            char* lb1 = new_label();
            char* lb2 = new_label();
            char* lb3 = new_label();
            char* code1 = translate_cond_Exp(stmt->child->next->next, lb1, lb2);
            char* code2 = translate_stmt(stmt->child->next->next->next->next);
            char* code3 = translate_stmt(stmt->child->next->next->next->next->next->next);
            char* code4 = malloc(1024);
            sprintf(code4,"%sLABEL %s :\n%sGOTO %s\nLABEL %s :\n%sLABEL %s :\n",code1,lb1,code2,lb3,lb2,code3,lb3);
            return code4;
        }
        else{
        //IF LP Exp RP Stmt
            char* lb1 = new_label();
            char* lb2 = new_label();
            char* code1 = translate_cond_Exp(stmt->child->next->next, lb1, lb2);
            char* code2 = translate_stmt(stmt->child->next->next->next->next);
            char* code3 = malloc(1024);
            sprintf(code3,"%sLABEL %s :\n%sLABEL %s :\n",code1,lb1,code2,lb2);
            return code3;
        }
        return NULL;  
    }
    if(strcasecmp(stmt->child->name, "WHILE") == 0){
        //WHILE LP Exp RP Stmt
        char* lb1 = new_label();
        char* lb2 = new_label();
        char* lb3 = new_label();
        char* code1 = translate_cond_Exp(stmt->child->next->next,lb2,lb3);
        char* code2 = translate_stmt(stmt->child->next->next->next->next);
        char* code3 = malloc(1024);
        sprintf(code3,"LABEL %s :\n%sLABEL %s :\n%sGOTO %s\nLABEL %s :\n",lb1,code1,lb2,code2,lb1,lb3);
        return code3;
    }
    if(strcasecmp(stmt->child->name, "RETURN") == 0){
        char* tp = new_place();
        char* buff = malloc(1024);
        sprintf(buff,"%sRETURN %s\n",translate_Exp(stmt->child->next, tp),tp);
        return buff;
    }
}

char* translate_Exp(node* Exp, char* place){
    if(strcasecmp(Exp->child->name, "LP")==0){
        //LP Exp RP
        return translate_Exp(Exp->child->next,place);
    }
    if(strcasecmp(Exp->child->name, "read")==0){
        char* buff = malloc(1024);
        sprintf(buff, "READ %s\n", place);
        return buff;
    }
    if(strcasecmp(Exp->child->name, "write")==0){;
        char* place = new_place();
        char* buff = malloc(1024);
        sprintf(buff, "%sWRITE %s\n", translate_Exp(Exp->child->next->next, place), place);
        return buff;
    }
    if(strcasecmp(Exp->child->name, "id") == 0){
        if(Exp->child->next == NULL){
            Info* id = symtab_lookup(root, Exp->child->attribute);
            char* buff = malloc(1024);
            if(id->t == -1){
                id->t = count1 - 1;  
            }sprintf(buff, "%s := t%d\n", place, id->t);
            return buff;
        }
        if(strcasecmp(Exp->child->next->next->name, "RP") == 0){
            Info* function = symtab_lookup(root, Exp->child->attribute);
            char* buff = malloc(1024);
            sprintf(buff, "%s := CALL %s\n", place, Exp->child->attribute);
            return buff;
        }
        if(strcasecmp(Exp->child->next->next->name, "args") == 0){
            int* arglist = malloc(sizeof(int)*10);
            char* code1 = translate_Args(Exp->child->next->next, arglist);
            char* code2 = malloc(1024);
            for(int i = 9; i >= 0; i--){
                if(arglist[i] != 0){
                    sprintf(code2, "%sARG t%d\n", code2, arglist[i]);
                }
            }
            char* buff = malloc(1024);
            sprintf(buff, "%s%s%s := CALL %s\n", code1, code2, place,Exp->child->attribute);
            return buff;
        }
    }


    if(strcasecmp(Exp->child->name, "int") == 0){
        char* buff = malloc(1024);
        sprintf(buff, "%s := #%s\n", place, Exp->child->attribute);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "assign") == 0){
        if(strcasecmp(Exp->child->child->name,"ID")==0){
            Info* exp1 = symtab_lookup(root, Exp->child->child->attribute);
            char *buff = malloc(1024); //ID
            char* tp = new_place();
            char* code1 = translate_Exp(Exp->child->next->next, tp);
            char* code2 = malloc(64);
            sprintf(code2, "t%d := %s\n", exp1->t, tp);
            sprintf(buff, "%s%s",code1,code2);
            return buff;
        }
        if(strcasecmp(Exp->child->child->next->name,"LB")==0){
            char *buff = malloc(1024); 
            char* tp = new_place();
            char* code0 = translate_Exp(Exp->child, tp);
            char* tp1 = new_place();
            char* code1 = translate_Exp(Exp->child->next->next, tp1);
            char *code2 = malloc(1024); //ID
            sprintf(code2, "%s := %s\n", tp, tp1);
            sprintf(buff, "%s%s%s",code0,code1,code2);
            return buff;
            // return "null";
        }
    
    }
    if(strcasecmp(Exp->child->next->name, "plus") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s + %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "minus") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s - %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "mul") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s * %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "div") == 0){
        char *t1 = new_place();
        char *t2 = new_place();
        char *code1 = translate_Exp(Exp->child, t1);
        char *code2 = translate_Exp(Exp->child->next->next, t2);
        char *code3 = malloc(64);
        sprintf(code3, "%s := %s / %s\n", place, t1, t2);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s%s", code1, code2, code3);
        return buff;
    }
    if(strcasecmp(Exp->child->name, "minus") == 0){
        char *tp = new_place();
        char *code1 = translate_Exp(Exp->child->next, tp);
        char *code2 = malloc(64);
        sprintf(code2, "%s := #0 - %s\n", place, tp);
        char *buff = malloc(1024);
        sprintf(buff, "%s%s", code1, code2);
        return buff;
    }
    if(strcasecmp(Exp->child->next->name, "LB") == 0){
        char* code = malloc(1024);
        char* tp1 = new_place();
        char* code1 = translate_Exp(Exp->child->next->next, tp1);
        char* tp2 = new_place();
        sprintf(code, "%s%s := %s * #4\n",code1, tp2, tp1);
        char* tp3;
        char* code2 = malloc(1024);
        // while(strcasecmp(Exp->child->child->name, "ID") != 0){
        //     Exp = Exp->child;
        //     tp3 = new_place();
        //     code2 = translate_Exp(Exp->child->next->next, tp3);
        //     sprintf(code, "%s%s%s := %s * %s\n", code, code2, tp2, tp2, tp3);
        // }
        Info* arr = symtab_lookup(root, Exp->child->child->attribute);
        char* tp4 = new_place();
        sprintf(code, "%s%s := &t%d + %s\n", code, tp4, arr->t, tp2);
        sprintf(code, "%s%s := *%s\n", code, place, tp4);
        return code;
        // return "null";
    }
    return "NULL";
}

char* translate_Args(node* Args, int* arglist){
    if(Args->child->next == NULL){
        char* tp = new_place();
        char* code = translate_Exp(Args->child, tp);
        for(int i = 0; i < 10; i++){
            if(arglist[i] == 0){
                arglist[i] = atoi(tp+1);
                break;
            }
        }
        return code;
    }
    else{
        char* tp = new_place();
        char* code1 = translate_Exp(Args->child, tp);
        for(int i = 0; i < 10; i++){
            if(arglist[i] == 0){
                arglist[i] = atoi(tp+1);
                break;
            }
        }
        char* code2 = translate_Args(Args->child->next->next, arglist);
        char* buff = malloc(64);
        sprintf(buff, "%s%s", code1, code2);
        return buff;
    }
    
}
char* new_place(){
    char* buff = malloc(1024);
    sprintf(buff,"t%d",count1);
    count1++;
    return buff;
}


char* new_label(){
    char* buff = malloc(1024);
    sprintf(buff,"label%d",count2);
    count2++;
    return buff;
}

int confirmReturnType(node* root,char * returnType){
    int re = 1;
    if(root->child!=NULL){
        node* p = root->child;
        while(p!=NULL){
            if(strcasecmp(p->name,"return")==0) {
                line = p->lineNo;
                if(p->next->type){
                    re = re & !strcasecmp(p->next->type->name,returnType);
                }
                if(re==0){
                     return 0;
                }
            }
            re = re & confirmReturnType(p,returnType);
            if(re==0) return 0;
            p = p->next;
        }
    }
    return re;

}
int confirmArgsType(node* root,ParaList* parameters){
    cnt1=0;
    cnt2=0;
    int re =1;
    node * r;
    r = root;
    while(r->child!=NULL){
        cnt1 = cnt1 + 1;
        if(r->child->next==NULL) break;
        r = r->child->next-> next;
    }
    ParaList* p = parameters;
    while(p!=NULL){
        p = p->next;
        cnt2 = cnt2 + 1;
    }
    p= parameters;
    if(parameters==NULL) return 0;
    while(root->child!=NULL&&p!=NULL){
        re = re & compareType(root->child->type,p->type);
        if(re==0) {
            return 0;
        }
        p = p->next;
        if(root->child->next==NULL) break;
        root = root->child->next-> next;
    }
    if(p==NULL&&root->child->next!=NULL){
        return 0;
    }
    if(root->child->next==NULL && p!=NULL) {
        return 0;
    }
    return re;
}

int compareType(Type* type1, Type* type2) {
    if(!type1||!type2){
        return 1;
    }
    if(type1->category != type2->category){
        return 0;
    }
    if(type1->category == PRIMITIVE||STRUCTURE){
        return !strcasecmp(type1->name, type2->name);
    }
    else{
        if(type1->array->size!=type2->array->size){
            return 0;
        }else return compareType(type1->array->base,type2->array->base);
    }
}

void printTree(node* root, int blank){
    if (root->child==NULL)
    {   
        if(root->attribute){
            printf("%*s%s: %s\n",blank,"",root->name,root->attribute);
        }else{
            printf("%*s%s\n",blank,"",root->name);
        }
        return;
    }else{
        printf("%*s%s (%d)\n",blank,"",root->name,root->lineNo);
        node *p= root->child;
        while(p!=NULL){
            if(!p->isEmpty){
               printTree(p,blank+2);
            }
            p=p->next;
        }
    }
}

node* alloNodeI(int a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->attribute = malloc(sizeof(char)*10);
    p->lvalue = 0;
    sprintf(p->attribute,"%d",a);
    return p;
}
node* alloNodeF(float a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->attribute = malloc(sizeof(char)*10);
    p->lvalue = 0;
    sprintf(p->attribute,"%f",a);
    return p;
}
node* alloNodeC(char* a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->lvalue = 0;
    if(Name=="INT"||Name=="FLOAT"||Name=="CHAR"||Name=="ID"||Name=="TYPE")
        p->attribute=a;
    return p;
}

node* insert(char * parent,int count, ...){
    node *p = malloc(sizeof(node));
    p->name = parent;
    if (count==0){
        p->isEmpty = 1;
        return p;
    }
    va_list args;
    va_start(args, count);

    node * start = va_arg(args,node*);
    node * prev = start;
    for(int i=0;i<count-1;i++) {
        node * n=va_arg(args, node*);
        prev->next=n;
        prev = n;
    }
    prev->next==NULL;
    p->child = start;
    va_end(args);
    return p;
}

int main(int argc, char **argv) {
    char *file_path;
    freopen("out.txt","w",stdout);
    root =  symtab_init();
    struct Info *val = malloc(sizeof(Info));
    struct Type *returnType = malloc(sizeof(Type));
    returnType->name= "int";
    returnType->category = PRIMITIVE;//todo
    struct ParaList *paralist;
    val->type = NULL;
    paralist = NULL;
    val->a = 2;
    val->return_type = returnType;
    val->paraList = paralist;
    symtab_insert(root, "read", *val);

    struct Info *val1 = malloc(sizeof(Info));
    struct Type *returnType1 = malloc(sizeof(Type));
    returnType1->name= "int";
    returnType1->category = PRIMITIVE;//todo
    ParaList *paralist1;
    val1->type = NULL;

    struct Type *para = malloc(sizeof(Type));
    para->name = "int";
    para->category = PRIMITIVE;//todo
    paralist1 = malloc(sizeof(ParaList));
    paralist1->type = para;
    paralist1->next = NULL;
    
    val1->a = 2;
    val1->return_type = returnType1;
    val1->paraList = paralist1;
    symtab_insert(root, "write", *val1);


    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        // yydebug = 1;
        yyparse();
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
    }
}