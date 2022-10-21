%{
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #include<string.h>
    #include "stdlib.h"
    int lines = 0;
    // global variables
%}
letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
%%
"int"|"float"|"char" { printf("TYPE %s\n", yytext); }
"struct" { printf("STRUCT %s\n", yytext); }
"if" { printf("IF %s\n", yytext); }
"else" { printf("ELSE %s\n", yytext); }
"while" { printf("WHILE %s\n", yytext); }
"return" { printf("RETURN %s\n", yytext); }
"." { printf("DOT %s\n", yytext); }
";" { printf("SEMI %s\n", yytext); }
"," { printf("COMMA %s\n", yytext); }
"<=" { printf("LE %s\n", yytext); }
"<" { printf("LT %s\n", yytext); }
">=" { printf("GE %s\n", yytext); }
">" { printf("GT %s\n", yytext); }
"!=" { printf("NE %s\n", yytext); }
"==" { printf("EQ %s\n", yytext); }
"=" { printf("ASSIGN %s\n", yytext); }
"+" { printf("PLUS %s\n", yytext); }
"-" { printf("MINUS %s\n", yytext); }
"*" { printf("MUL %s\n", yytext); }
"/" { printf("DIV %s\n", yytext); }
"&&" { printf("AND %s\n", yytext); }
"||" { printf("OR %s\n", yytext); }
"!" { printf("NOT %s\n", yytext); }
"(" { printf("LP %s\n", yytext); }
")" { printf("RP %s\n", yytext); }
"[" { printf("LB %s\n", yytext); }
"]" { printf("RB %s\n", yytext); }
"{" { printf("LC %s\n", yytext); }
"}" { printf("RC %s\n", yytext); }

{digit}{digit}*"\."{digit}{digit}* { printf("FLOAT %s\n", yytext); }
{digit}*|("0x"|"0X")({digit}|"a"|"b"|"c"|"d"|"e"|"f")({digit}|"a"|"b"|"c"|"d"|"e"|"f")* {
	if(strlen(yytext) != 1 && yytext[0] == '0' && yytext[1] != 'x' && yytext[1] != 'X'){
		printf("%s\n","Invalid Int");
	}
	else if(strlen(yytext) > 3 && yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X')&&yytext[2] == '0'){
		printf("%s\n", "Invalid int");		
	}else printf("INT %s\n", yytext);}
{letter_}({letter_}|{digit})* {printf("ID %s\n", yytext);} 
\'{letter}\' {printf("CHAR %s\n", yytext);}
\n {lines++;}
[\t\r ]+ { /* does nothing when seeing white spaces except new line */ }
. { printf("Error type A at Line %d: Unknown characters %s\n",
lines, yytext); }
<<EOF>> {yyterminate();}

%%
int main(int argc, char **argv){
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
        yylex();
        return EXIT_OK;
    } else{
        fputs("Too many arguments! Expected: 2.\n", stderr);
        return EXIT_FAIL;
    }
}
