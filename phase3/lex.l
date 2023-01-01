%{
	#include "node.h"
	#include "stdlib.h"
    #include <string.h>
    #include "syntax.tab.h"
	#define YY_USER_ACTION  yylloc.first_line = yylineno; 
	int hexToDec(char * hex);
%}

%option yylineno
letter [a-zA-Z]
letter_ {letter}|_
digit [0-9]
hex {digit}|"a"|"b"|"c"|"d"|"e"|"f"|"A"|"B"|"C"|"D"|"E"|"F"
%%
"int"|"float"|"char" { yylval.string_value = strdup(yytext); return TYPE; }
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
"read" {return READ;}
"write" {return WRITE;}
"for" {return FOR;}
"//"[^\n]*\n { printf("single-line comment %s\n",yytext);}
"/*"([^*]|\*+[^/*])*"*/" { printf("multi-line comment %s\n",yytext);}
#include[ ]+((<.*>)|(".*")) {return INCLUSION;}
#define[ ]+.+[ ]+.+  {return DEFINE;}


{digit}{digit}*"\."{digit}{digit}* {yylval.string_value = strdup(yytext); return FLOAT;}
{letter_}({letter_}|{digit})* {yylval.string_value = strdup(yytext);return ID;} 

{digit}*|("0x"|"0X"){hex}{hex}* {
	if(strlen(yytext) != 1 && yytext[0] == '0' && yytext[1] != 'x' && yytext[1] != 'X'){
		yylval.string_value =strdup(yytext); return FAULT;
	}
	else if(strlen(yytext) > 3 && yytext[0] == '0' && (yytext[1] == 'x' || yytext[1] == 'X')&& yytext[2] == '0'){
		yylval.string_value =strdup(yytext); return FAULT;
	} 
	else {
		yylval.int_value = hexToDec(yytext);
		return INT;
	}
}
{digit}({letter_}|{digit})* {yylval.string_value =strdup(yytext); return FAULT;}

"\n" {}
[\t\r ]+ {}

(\'.*\') {
 if(yytext[1] != '\\' && strlen(yytext) > 3){
  yylval.string_value =strdup(yytext); return FAULT;
 }
 else if(yytext[1] != '\\' && yytext[1] >= 32 && yytext[1] <= 126) {
  yylval.string_value =strdup(yytext); return CHAR;
 }
 else if(yytext[1] == '\\' && (strlen(yytext) !=6)){
  yylval.string_value =strdup(yytext); return FAULT;
 }
 else if(yytext[1] == '\\' && (yytext[2] == 'x' || yytext[2] == 'X')){
  int index = 3;
  int ifValid = 1;
  while(index <= strlen(yytext) - 2){
       if(!(yytext[index] >= '0' && yytext[index] <= '9' || yytext[index] >= 'a' && yytext[index] <= 'f' || yytext[index] >= 'A' && yytext[index] <= 'F')){
   ifValid = 0;
   break;
   }
       index++;   
  }
  if(ifValid){
   yylval.string_value =strdup(yytext); return CHAR;  
  }
  else{
   yylval.string_value =strdup(yytext); return FAULT; 
  }
 }
 
 else{
  yylval.string_value =strdup(yytext); return FAULT;
 }
 }


. {yylval.string_value =strdup(yytext); return FAULT;}
%%

int hexToDec(char * hex){
	char * p = hex+1;
	if(p&&(*p=='x'||*p=='X')){
		int sum= strtol(hex, NULL, 16);
		return sum;
	}
	else return atoi(hex);
}
