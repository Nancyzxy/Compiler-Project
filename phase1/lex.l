%{
    #include "syntax.tab.h"
    #include "stdlib.h"
    #include <string.h>
    int lines = 0;
%}

letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]

%%
"int"|"float"|"char" { return TYPE; }
"struct" { return STRUCT; }
"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE; }
"return" { return RETURN; }
"." { return DOT; }
";" { return SEMI; }
"," { return COMMA; }
"<=" { return LE; }
"<" { return LT; }
">=" { return GE; }
">" { return GT; }
"!=" { return NE; }
"==" { return EQ; }
"=" { return ASSIGN; }
"+" { return PLUS; }
"-" { return MINUS; }
"*" { return MUL; }
"/" { return DIV; }
"&&" { return AND; }
"||" { return OR; }
"!" { return NOT; }
"(" { return LP; }
")" { return RP; }
"[" { return LB; }
"]" { return RB; }
"{" { return LC; }
"}" { return RC; }

{digit}{digit}*"\."{digit}{digit}* {return FLOAT;}
{digit}*|("0x"|"0X")({digit}|"a"|"b"|"c"|"d"|"e"|"f")({digit}|"a"|"b"|"c"|"d"|"e"|"f")* {
	if(strlen(yytext) != 1 && yytext[0] == '0' && yytext[1] != 'x' && yytext[1] != 'X'){
		printf("%s\n","Invalid Int");
	}
	else if(strlen(yytext) > 3 && yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X')&& yytext[2] == '0'){
		printf("%s\n", "Invalid int");		
	}else return INT;}
{letter_}({letter_}|{digit})* {printf("ID %s\n", yytext);return ID;} 
\'{letter}\' {return CHAR;}
\n {lines++;}
[\t\r ]+ {}
<<EOF>> {yyterminate();}
%%
