%option noyywrap
%{
#include<stdio.h>
%}
digit [0-9]
hex_digit [0-9a-fA-F]
exp [eE]
alpha [a-zA-Z]

%%
{digit}+       { printf("Integer Constant : %s\n", yytext); }
0[0-7]*        { printf("Octal constant: %s\n", yytext); } 
0[xX]{hex_digit}+ { printf("Hexadecimal constant: %s\n", yytext); }
{digit}+\.{digit}+([+-]?{digit}+)? { printf("Floating point constant: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9]* { printf("Valid identifier: %s\n", yytext); }
[?=\-0-9]?[0-9]*\.[0-9]+([eE][+-]?[0-9]+)? { printf("Exponential Constant: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("Invalid identifier: %s\n", yytext); }
.|\n            { /* Ignore other characters */ }

%%

int main(){
    yylex();
    return 0;
}
