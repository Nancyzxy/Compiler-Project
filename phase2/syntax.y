%{
    #include "lex.yy.c"
    #include "node.h"
    #include <stdarg.h>
    #include <stdio.h>
    #include <string.h>
    #include"symtab_bt.c"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    int flag = 0;
    symtab* root;
    node* insert(char* parent,int count,...);
    void yyerror(const char*);
    node* alloNodeI(int a,char * Name);
    node* alloNodeF(float a,char * Name);
    node* alloNodeC(char* a,char * Name);
    void printTree(node* root,int blank);
    int valType(char * type);
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
%token<treeNode> STRUCT IF WHILE RETURN SEMI COMMA FOR
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
    if(flag ==0){printTree($$,0);}
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

ExtDef:  Specifier ExtDecList SEMI {$$ = insert("ExtDef",3,$1,$2,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;}
      | Specifier SEMI {$$ = insert("ExtDef",2,$1,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;}
      | Specifier FunDec CompSt {$$ = insert("ExtDef",3,$1,$2,$3);@$ = @1;$$->lineNo=(@1).first_line;
            if(symtab_lookup(root, $2->child->attribute) != -1){
                printf("Error type 4 at Line %d: redefine function: %s\n",(@1).first_line,$2->child->attribute);
            }
            else{
              symtab_insert(root, $2->child->attribute, valType(($1->child->attribute)));  
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

FunDec: ID LP VarList RP {$$ = insert("FunDec",4,alloNodeC($1,"ID"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;}
      | ID LP RP {$$ = insert("FunDec",3,alloNodeC($1,"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;}
      | ID LP error {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(@2).first_line);}
      ;

VarList: ParamDec COMMA VarList {$$ = insert("VarList",3,$1,alloNodeC(",","COMMA"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
       | ParamDec {$$ = insert("VarList",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
       ;

ParamDec: Specifier VarDec {$$ = insert("ParamDec",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line; 
                if( symtab_lookup(root, $2->child->attribute) != -1){
                printf("Error Type 3 at Line %d: redefine variable: %s", (@1).first_line,$2->child->attribute);
                }
                else{
                        if(strcmp($1->child->name, "TYPE") == 0){
                            symtab_insert(root, $2->child->attribute, valType(($1->child->attribute)));
                        }
                        
                }
};
        


/* statement */
CompSt: LC DefList StmtList RC {$$ = insert("CompSt",4,alloNodeC("{","LC"),$2,$3,alloNodeC("}","RC"));@$ = @1;$$->lineNo=(@1).first_line;}
      | LC DefList StmtList error {flag=1; printf("Error type B at Line %d: Missing specifier\n",(@3).first_line);}
      ;

StmtList: Stmt StmtList  {$$ = insert("StmtList",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;}
        |   {$$ = insert("StmtList",0);}
        ;

Stmt: Exp SEMI {$$ = insert("Stmt",2,$1,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;}
    | CompSt {$$ = insert("Stmt",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
    | RETURN Exp SEMI {$$ = insert("Stmt",3,alloNodeC("return","RETURN"),$2,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;}
    | IF LP Exp RP Stmt %prec LOWER_ELSE {$$ = insert("Stmt",5,alloNodeC("if","IF"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"),$5);@$ = @1;$$->lineNo=(@1).first_line;}
    | IF LP Exp RP Stmt ELSE Stmt {$$ = insert("Stmt",7,alloNodeC("if","IF"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"),$5,alloNodeC("else","ELSE"),$7);@$ = @1;$$->lineNo=(@1).first_line;}
    | WHILE LP Exp RP Stmt {$$ = insert("Stmt",5,alloNodeC("while","WHILE"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"),$5);@$ = @1;$$->lineNo=(@1).first_line;}
    | RETURN Exp error {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",(@2).first_line); }
    | FOR LP Exp SEMI Exp SEMI Exp RP Stmt {$$ = insert("Stmt",9,alloNodeC("for","FOR"),alloNodeC("(","LP"),$3,alloNodeC(";","SEMI"),$5,alloNodeC(";","SEMI"),$7,alloNodeC(")","RP"),$9);@$ = @1;$$->lineNo=(@1).first_line;}
    | Exp error {flag=1; printf("Error type B at Line %d: Missing semicolon ';'\n",(@1).first_line); }
    ;

/* local definition */
DefList: Def DefList {$$ = insert("DefList",2,$1,$2);@$ = @1;$$->lineNo=(@1).first_line;}
       |    /*empty terminal*/  {$$ = insert("DefList",0);}
       ;

Def: Specifier DecList SEMI {$$ = insert("Def",3,$1,$2,alloNodeC(";","SEMI"));@$ = @1;$$->lineNo=(@1).first_line;
        if(strcmp($2->child->child->child->name, "ID") == 0){
            if(symtab_lookup(root, $2->child->child->child->attribute) != -1){
            printf("Error Type 3 at Line %d: redefine variable: %s\n", (@1).first_line,$2->child->child->child->attribute);
            }
            else{
                if(strcmp($1->child->name, "TYPE") == 0){
                    symtab_insert(root, $2->child->child->child->attribute, valType(($1->child->attribute)));
                    int val = valType(($1->child->attribute));
                    int cmpVal = 0;
                    if($2->child->child->next != NULL){
                        if(strcmp($2->child->child->next->next->child->name,"Exp") == 0){
                            if(strcmp($2->child->child->next->next->child->child->name, "ID") == 0){
                            cmpVal = symtab_lookup(root, $2->child->child->next->next->child->child->attribute);
                            if(val != cmpVal){
                                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                            }
                        }
                        }
                        
                        else{
                            cmpVal = valType($2->child->child->next->next->child->name);
                            if(val != cmpVal){
                                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                            }
                        }

                    
                }
                }
            
        }
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
        if(strcmp($1->child->name, "ID") == 0){
            int val = symtab_lookup(root, $1->child->attribute);
            int cmpVal = 0;
            if(strcmp($3->child->name, "Exp") == 0){
                if(strcmp($3->child->child->name, "ID") != 0){
                    if(strcmp($3->child->child->name,"float") == 0 || strcmp($3->child->child->name,"int") == 0 || strcmp($3->child->child->name,"char") == 0 ){
                        cmpVal = symtab_lookup(root, $3->child->child->attribute);
                        if(val != cmpVal){
                                printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                        }
                    }
                }
                else{
                    cmpVal = symtab_lookup(root, $3->child->child->attribute);
                    if(val != cmpVal){
                            printf("Error type 5 at Line %d: unmatching type on both sides of assignment\n", (@1).first_line);
                    }
                }
            }
            
        }
        
}
   | Exp AND Exp {$$=insert("Exp",3,$1,alloNodeC("&&","AND"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp OR Exp {$$=insert("Exp",3,$1,alloNodeC("||","OR"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp LT Exp {$$=insert("Exp",3,$1,alloNodeC("<","LT"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp LE Exp {$$=insert("Exp",3,$1,alloNodeC("<=","LE"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp GT Exp {$$=insert("Exp",3,$1,alloNodeC(">","GT"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp GE Exp {$$=insert("Exp",3,$1,alloNodeC(">=","GE"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp NE Exp {$$=insert("Exp",3,$1,alloNodeC("!=","NE"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp EQ Exp {$$=insert("Exp",3,$1,alloNodeC("==","EQ"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp PLUS Exp {$$=insert("Exp",3,$1,alloNodeC("+","PLUS"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp MINUS Exp {$$=insert("Exp",3,$1,alloNodeC("-","MINUS"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp MUL Exp {$$=insert("Exp",3,$1,alloNodeC("*","MUL"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp DIV Exp {$$=insert("Exp",3,$1,alloNodeC("/","DIV"),$3);@$ = @1;$$->lineNo=(@1).first_line;}
   | LP Exp RP {$$=insert("Exp",3,alloNodeC("(","LP"),$2,alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;}
   | MINUS Exp {$$=insert("Exp",2,alloNodeC("-","MINUS"),$2);@$ = @1;$$->lineNo=(@1).first_line;}
   | NOT Exp {$$=insert("Exp",2,alloNodeC("!","NOT"),$2);@$ = @1;$$->lineNo=(@1).first_line;}
   | ID LP Args RP {$$=insert("Exp",4,alloNodeC($1,"ID"),alloNodeC("(","LP"),$3,alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line;if(symtab_lookup(root, $1) == -1){printf("Error Type 2 at Line %d: undefined function: %s\n", (@1).first_line,$1);}}
   | ID LP RP {$$=insert("Exp",3,alloNodeC($1,"ID"),alloNodeC("(","LP"),alloNodeC(")","RP"));@$ = @1;$$->lineNo=(@1).first_line; if(symtab_lookup(root, $1) == -1){printf("Error Type  2 at Line %d :  function %s is used without definition", (@1).first_line,$1);}}
   | Exp LB Exp RB {$$=insert("Exp",4,$1,alloNodeC("[","LB"),$3,alloNodeC("]","RB"));@$ = @1;$$->lineNo=(@1).first_line;}
   | Exp DOT ID {$$=insert("Exp",3,$1,alloNodeC(".","DOT"),alloNodeC($3,"ID"));@$ = @1;$$->lineNo=(@1).first_line;}
   | ID {$$=insert("Exp",1,alloNodeC($1,"ID"));@$ = @1;$$->lineNo=(@1).first_line; if(symtab_lookup(root, $1) == -1){printf("Error Type 1 at Line %d: undefined variable: %s\n", (@1).first_line,$1);} }
   | INT {$$=insert("Exp",1,alloNodeI($1,"INT"));@$ = @1;$$->lineNo=(@1).first_line;}
   | FLOAT {$$=insert("Exp",1,alloNodeC($1,"FLOAT"));@$ = @1;$$->lineNo=(@1).first_line;}
   | CHAR {$$=insert("Exp",1,alloNodeC($1,"CHAR"));@$ = @1;$$->lineNo=(@1).first_line;}
   | FAULT error {flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",(@1).first_line,$1);}
   | ID LP Args error {flag=1; printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(@3).first_line);}
   | Exp FAULT Exp error{flag=1; printf("Error type A at Line %d: unknown lexeme %s\n",(@2).first_line,$2);};

Args: Exp COMMA Args {$2= alloNodeC(",","COMMA"); $$ = insert("Args",3,$1,$2,$3);@$ = @1;$$->lineNo=(@1).first_line;}
    | Exp {$$ = insert("Args",1,$1);@$ = @1;$$->lineNo=(@1).first_line;}
    ;

%%
void yyerror(const char *s) {
    //fprintf(stderr, "%s at line %d\n", s, yylineno);
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
    sprintf(p->attribute,"%d",a);
    return p;
}
node* alloNodeF(float a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
    p->attribute = malloc(sizeof(char)*10);
    sprintf(p->attribute,"%f",a);
    return p;
}
node* alloNodeC(char* a,char * Name){
    node *p = malloc(sizeof(node));
    p->name = Name;
    p->child = NULL;
    p->isEmpty = 0;
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

int valType(char * type){
    if(strcmp(type, "INT") == 0 || strcmp(type, "int") == 0){
        return 1;
    }
    if(strcmp(type,"FLOAT") == 0 || strcmp(type,"float") == 0){
        return 2;
    }
    if(strcmp(type, "CHAR") == 0 || strcmp(type, "char") == 0){
        return 3;
    }
    return 0;
}
int main(int argc, char **argv) {
    char *file_path;
    freopen("out.txt","w",stdout);
    root =  symtab_init();
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