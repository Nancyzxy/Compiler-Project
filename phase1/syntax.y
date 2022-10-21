%{
    #include "lex.yy.c"
    #include "node.h"
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    void yyerror(const char*);
%}
%union{
    node treeNode;
    int int_value;
    float float_value;
    char* string_value;
}
%token<int_value> INT 
%token<float_value>FLOAT 
%token<char*>CHAR ID
%token TYPE STRUCT IF WHILE RETURN SEMI COMMA
%type <treeNode> Args Exp Dec DecList Def DefList Stmt StmtList CompSt ParamDec VarList FunDec VarDec StructSpecifier Specifier ExtDecList ExtDef ExtDefList Program
%nonassoc LOWER_ELSE
%nonassoc ELSE

%right ASSIGN
%left OR
%left AND
%left NE EQ
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV
%right NOT
%left LP RP LB RB LC RC DOT    
%%

Program : ExtDefList { 
    struct node n;
    $$ = n;
    };

ExtDefList: ExtDefList ExtDef {struct node n; $$ = n;}
          | {struct node n; $$ = n;}
          ;

ExtDef:  Specifier ExtDecList SEMI {struct node n; $$ = n;}
      | Specifier SEMI {struct node n; $$ = n;}
      | Specifier FunDec CompSt {struct node n; $$ = n;}
      ;

ExtDecList: VarDec {struct node n; $$ = n;}
          | VarDec COMMA ExtDecList {struct node n; $$ = n;}
          ;

/* specifier */
Specifier: TYPE {struct node n; $$ = n;}
         | StructSpecifier {struct node n; $$ = n;}
         ;

StructSpecifier: STRUCT ID LC DefList RC {struct node n; $$ = n;}
               | STRUCT ID {struct node n; $$ = n;}
               ;

/* declarator */
VarDec: ID {struct node n; $$ = n;}
      | VarDec LB INT RB {struct node n; $$ = n;}
      ;

FunDec: ID LP VarList RP {struct node n; $$ = n;}
      | ID LP RP {struct node n; $$ = n;}
      ;

VarList: ParamDec COMMA VarList {struct node n; $$ = n;}
       | ParamDec {struct node n; $$ = n;}
       ;

ParamDec: Specifier VarDec {struct node n; $$ = n;}
        ;


/* statement */
CompSt: LC DefList StmtList RC {struct node n; $$ = n;}
      ;

StmtList: Stmt StmtList  {struct node n; $$ = n;}
        |   {struct node n; $$ = n;}
        ;

Stmt: Exp SEMI {struct node n; $$ = n;}
    | CompSt {struct node n; $$ = n;}
    | RETURN Exp SEMI {struct node n; $$ = n;}
    | IF LP Exp RP Stmt %prec LOWER_ELSE {struct node n; $$ = n;}
    | IF LP Exp RP Stmt ELSE Stmt {struct node n; $$ = n;}
    | WHILE LP Exp RP Stmt {struct node n; $$ = n;}
    ;

/* local definition */
DefList: Def DefList {struct node n; $$ = n;}
       |    /*empty terminal*/  {struct node n; $$ = n;}
       ;

Def: Specifier DecList SEMI {struct node n; $$ = n;}
   ;

DecList: Dec {struct node n; $$ = n;}
       | Dec COMMA DecList {struct node n; $$ = n;}
       ;

Dec: VarDec {struct node n; $$ = n;}
   | VarDec ASSIGN Exp {struct node n; $$ = n;}
   ;

/* Expression */
Exp: Exp ASSIGN Exp {struct node n; $$ = n;}
   | Exp AND Exp {struct node n; $$ = n;}
   | Exp OR Exp {struct node n; $$ = n;}
   | Exp LT Exp {struct node n; $$ = n;}
   | Exp LE Exp {struct node n; $$ = n;}
   | Exp GT Exp {struct node n; $$ = n;}
   | Exp GE Exp {struct node n; $$ = n;}
   | Exp NE Exp {struct node n; $$ = n;}
   | Exp EQ Exp {struct node n; $$ = n;}
   | Exp PLUS Exp {struct node n; $$ = n;}
   | Exp MINUS Exp {struct node n; $$ = n;}
   | Exp MUL Exp {struct node n; $$ = n;}
   | Exp DIV Exp {struct node n; $$ = n;}
   | LP Exp RP {struct node n; $$ = n;}
   | MINUS Exp {struct node n; $$ = n;}
   | NOT Exp {struct node n; $$ = n;}
   | ID LP Args RP {struct node n; $$ = n;}
   | ID LP RP {struct node n; $$ = n;}
   | Exp LB Exp RB {struct node n; $$ = n;}
   | Exp DOT ID {struct node n; $$ = n;}
   | ID {struct node n; $$ = n;}
   | INT {struct node n; $$ = n;}
   | FLOAT {struct node n; $$ = n;}
   | CHAR {struct node n; $$ = n;}
   ;

Args: Exp COMMA Args {struct node n; $$ = n;}
    | Exp {struct node n; n.name = "Args" $$ = n;}
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d\n", s, yylineno);
}
void inset(node* parent, node* child, ...){

}
int main(int argc, char **argv) {
    char *file_path;
    if(argc < 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if(argc == 2){
        file_path = argv[1];
        if(!(yyin = fopen(file_path, "r"))){
            perror(argv[1]);
            return EXIT_FAIL;
        }
        yydebug = 1;
        yyparse();
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
    }
}