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

Program : ExtDefList;

ExtDefList: ExtDefList ExtDef
          | 
          ;

ExtDef:  Specifier ExtDecList SEMI
      | Specifier SEMI
      | Specifier FunDec CompSt
      ;

ExtDecList: VarDec
          | VarDec COMMA ExtDecList
          ;

/* specifier */
Specifier: TYPE
         | StructSpecifier
         ;

StructSpecifier: STRUCT ID LC DefList RC
               | STRUCT ID
               ;

/* declarator */
VarDec: ID
      | VarDec LB INT RB
      ;

FunDec: ID LP VarList RP
      | ID LP RP
      ;

VarList: ParamDec COMMA VarList
       | ParamDec
       ;

ParamDec: Specifier VarDec
        ;


/* statement */
CompSt: LC DefList StmtList RC
      ;

StmtList: Stmt StmtList
        |  
        ;

Stmt: Exp SEMI
    | CompSt
    | RETURN Exp SEMI
    | IF LP Exp RP Stmt %prec LOWER_ELSE
    | IF LP Exp RP Stmt ELSE Stmt
    | WHILE LP Exp RP Stmt
    ;

/* local definition */
DefList: Def DefList
       |    /*empty terminal*/
       ;

Def: Specifier DecList SEMI
   ;

DecList: Dec
       | Dec COMMA DecList
       ;

Dec: VarDec
   | VarDec ASSIGN Exp
   ;

/* Expression */
Exp: Exp ASSIGN Exp
   | Exp AND Exp
   | Exp OR Exp
   | Exp LT Exp
   | Exp LE Exp
   | Exp GT Exp
   | Exp GE Exp
   | Exp NE Exp
   | Exp EQ Exp
   | Exp PLUS Exp
   | Exp MINUS Exp
   | Exp MUL Exp
   | Exp DIV Exp
   | LP Exp RP
   | MINUS Exp
   | NOT Exp
   | ID LP Args RP
   | ID LP RP
   | Exp LB Exp RB
   | Exp DOT ID
   | ID
   | INT
   | FLOAT
   | CHAR
   ;

Args: Exp COMMA Args
    | Exp
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d\n", s, yylineno);
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