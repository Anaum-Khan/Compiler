%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

extern void yyerror(const char *s);
%}

%option yylineno

DIGIT       [0-9]
IDENT       [a-zA-Z_][a-zA-Z0-9_]*
INTEGER     {DIGIT}+
DOUBLE      {DIGIT}+\.{DIGIT}+

%%

"let"           { return LET; }
"var"           { return VAR; }
"Int"           { yylval.str = strdup(yytext); return TYPE; }
"Double"        { yylval.str = strdup(yytext); return TYPE; }
"Bool"          { yylval.str = strdup(yytext); return TYPE; }
"Character"     { yylval.str = strdup(yytext); return TYPE; }
"String"        { yylval.str = strdup(yytext); return TYPE; }
"Void"          { yylval.str = strdup(yytext); return TYPE; }
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"in"            { return IN; }
"while"         { return WHILE; }
"repeat"        { return REPEAT; }
"func"          { return FUNC; }
"struct"        { return STRUCT; }
"return"        { return RETURN; }
"print"         { return PRINT; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"true"          { yylval.ival = 1; return BOOLEAN_LITERAL; }
"false"         { yylval.ival = 0; return BOOLEAN_LITERAL; }

"->"            { return ARROW; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LE; }
">="            { return GE; }
"<"             { return LT; }
">"             { return GT; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"="             { return ASSIGN; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }

":"             { return ':'; }
";"             { return ';'; }
","             { return ','; }
"."             { return '.'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
"["             { return '['; }
"]"             { return ']'; }

{DOUBLE}        { yylval.fval = atof(yytext); return DOUBLE_LITERAL; }
{INTEGER}       { yylval.ival = atoi(yytext); return INT_LITERAL; }
\"([^\\\"]|\\.)*\"   { yylval.str = strdup(yytext); return STRING_LITERAL; }
\'([^\\\']|\\.)\'    { yylval.str = strdup(yytext); return CHARACTER_LITERAL; }
{IDENT}         { yylval.str = strdup(yytext); return IDENTIFIER; }

[ \t\r\n]+      ;

.               { printf("Unknown character: %s\n", yytext); exit(1); }

%%

int yywrap() { 
    return 1; 
}
