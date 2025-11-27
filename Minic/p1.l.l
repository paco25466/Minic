%{
#include "lexico.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

extern int lexical_errors_count; 
int max_ancho();
int max_largo();


void error();
%}
digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
string              \"([^"\n\\]|\\.)*\"
panico              [^a-zA-Z0-9(){},;\;=+\-*/?\n\t\r<>!] 

%option yylineno
%X COMENT
%%


{string}                                   { yylval.c = strdup(yytext); return STRING; }
read                                        return READ;
var                                         return VAR;
const                                       return CONST;
int                                         return INT;
if                                          return IF; 
else                                        return ELSE; 
while                                       return WHILE;      
print                                       return PRINT; 
do                                          return DO;
({letra}|_)({letra}|{digito}|_)*            {if (max_ancho()) {yylval.c=strdup(yytext);} else {printf("Error lexico en la linea %d: El ID: %s tiene mas de 32 caracteres\n", yylineno, yytext); lexical_errors_count++;}  return ID;}
{entero}                                    {if (max_largo()) {yylval.c=strdup(yytext); } else {printf("Error lexico en la linea %d: Numero: %s fuera del rango admitido\n", yylineno, yytext); lexical_errors_count++;} return NUM;}
"("                                         return LPAREN;		
")"                                         return RPAREN;
";"                                         return SEMICOLON;
","                                         return COMMA;
"="                                         return ASSIGNOP;
"+"                                         return PLUSOP;
"-"                                         return MINUSOP;
"/"                                         return DIV;
"*"                                         return POR; 
"{"                                         return LCORCH;
"}"                                         return RCORCH;
"?"                                         return INTERR;
":"                                         return DOSPUNT;
"<"                                         return MENOR;
">"                                         return MAYOR;
"<="                                         return MENORIGUAL;
">="                                         return MAYORIGUAL;
"=="                                         return IGUAL;
"!="                                         return DISTINTO;



"/*"                                        BEGIN COMENT;
<COMENT>[*]+[/]                             BEGIN 0;
<COMENT>[^*]*                               ;
<COMENT>[*]+[^/*]*                          ;
[ \n\t\r]+                                  ;
"//"(.*)[\n]                                ;

{panico}+                                    { printf("\nError lexico, simbolo no reconocido %s en la linea %d\n", yytext, yylineno); lexical_errors_count++; }

%%



int max_ancho() {
    if (yyleng>32)
        return 0;
    return 1;
}
int max_largo() {
    if (atoll(yytext) > 4294967296)
        return 0;
    return 1;
}