%{
#include <io.h>
#include <string.h>
#include "syntaxtable.h"
#include "lex.h"

class CGrammarNode;

#include "Grammar.h"

#define isatty _isatty

extern int lineno = 1;

extern "C" int yywrap(void);

void IgnoreLine();

void HandleIdentifer();
void HandleString();
void HandleInteger();

%}

DIGIT		[0-9]
LETTER		[a-zA-z_]
STRING		\"[^\"]*\"
WHITESPACE	[\t ]+
IDENTIFIER	{LETTER}({LETTER}|{DIGIT})*
INTEGER		{DIGIT}+
%%
		
"if"				{return IF;}
"else"				{return ELSE;}
"("					{return OPEN_PARAM;}
")"					{return CLOSE_PARAM;}
"{"					{return OPEN_STMT;}
"}"					{return CLOSE_STMT;}
"<"					{return LT;}
">"					{return GT;}
"=="				{return EQ;}
"="					{return ASSIGN;}
"+"					{return PLUS;}
"-"					{return MINUS;}
"#"					{IgnoreLine();}
";"					{return END_STMT;}
","					{return COMMA;}
"\n"				{lineno++;}
{INTEGER}			{HandleInteger();return INT;}
{IDENTIFIER}		{HandleIdentifer(); return ID;}
{STRING}			{HandleString(); return STR;}
{WHITESPACE}		{}
.					{throw "Parse Lex Error";/*return ERROR_TOKEN;*/}

%%
void HandleIdentifer()
{
	yylval.strVal = new char[strlen(yytext) + 1];
	memset(yylval.strVal, 0x0, strlen(yytext) + 1);
	strcpy(yylval.strVal, yytext);
}

void HandleString()
{
	yylval.strVal = new char[strlen(yytext) + 1 - 2];
	memset(yylval.strVal, 0x0, strlen(yytext) + 1 - 2);
	memcpy(yylval.strVal, yytext + 1, strlen(yytext) - 2);
}

void HandleInteger()
{
	yylval.intVal = strtol(yytext, NULL, 10); 
}

void IgnoreLine()
{
	char c;
	while((c = yyinput()) != 0 && c != '\n');
	lineno++;
}

int yywrap(void)
{
	return 1;
}