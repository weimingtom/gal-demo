%{
#include "parser.h"
#include "lex.h"

#define YYDEBUG 1	      
#define YYERROR_VERBOSE

CSyntaxTable syntaxTable;
std::list<CGrammarNode*> grammarList;

void yyerror(char *msg);
%}

%union
{
	char	*strVal;
	int		intVal;
	CGrammarNode	*nodeVal;
}

%token IF ELSE OPEN_PARAM CLOSE_PARAM OPEN_STMT CLOSE_STMT END_STMT
%token LT GT EQ PLUS MINUS
%token ASSIGN
%token ERROR_TOKEN 
%token <strVal> ID STR
%token <intVal> INT

%type <nodeVal> identifier const_string const_int
%type <nodeVal> statement call_func if_statement else_statement statement_block statement_list
%type <nodeVal> expression assign_expression eq_expression param_list
%type <nodeVal> gt_expression lt_expression minus_expression
%type <nodeVal> plus_expression simple_expression

%expect 1
%%
program
	:program statement									{grammarList.push_back($2);}
	|
	;
	
statement
	:call_func END_STMT									{$$ = $1;}
	|if_statement										{$$ = $1;}
	|assign_expression END_STMT							{$$ = $1;}
	|error END_STMT										{throw "Parse Grammar Error";}
	;
	
statement_block
	:OPEN_STMT statement_list CLOSE_STMT						{$$ = $2;}
	;
	
statement_list
	:statement_list statement							{$$ = new CGrammarNode(STATEMENT_LIST, $1, $2);}
	|statement											{$$ = new CGrammarNode(STATEMENT_LIST, $1);}
	;

call_func
	:identifier OPEN_PARAM param_list CLOSE_PARAM		{$$ = new CGrammarNode(CALL_FUNC, $1, $3);}
	|identifier OPEN_PARAM CLOSE_PARAM					{$$ = new CGrammarNode(CALL_FUNC, $1);}
	;

param_list
	:param_list ',' simple_expression						{$$ = new CGrammarNode(PARAM_LIST, $1, $3);}
	|simple_expression										{$$ = new CGrammarNode(PARAM_LIST, $1);}
	;	

if_statement
	: IF OPEN_PARAM expression CLOSE_PARAM statement_block else_statement
		{
			if ($6 == NULL)
			{
				$$ = new CGrammarNode(IF_NODE, $3, $5);
			}
			else
			{
				$$ = new CGrammarNode(IF_NODE, $3, $5, $6);
			}
		}
	;
	
else_statement
	:ELSE statement_block				{$$ = new CGrammarNode(ELSE_NODE, $2);}
	|									{$$ = NULL;}
	;

expression
	:eq_expression									{$$ = $1;}
	|plus_expression								{$$ = $1;}
	|minus_expression								{$$ = $1;}
	|gt_expression									{$$ = $1;}
	|lt_expression									{$$ = $1;}
	;
	
assign_expression
	:identifier ASSIGN simple_expression			{$$ = new CGrammarNode(ASSIGN_NODE, $1, $3);}
	|identifier ASSIGN plus_expression				{$$ = new CGrammarNode(ASSIGN_NODE, $1, $3);}
	|identifier ASSIGN minus_expression				{$$ = new CGrammarNode(ASSIGN_NODE, $1, $3);}
	|identifier ASSIGN eq_expression				{$$ = new CGrammarNode(ASSIGN_NODE, $1, $3);}
	|identifier ASSIGN gt_expression				{$$ = new CGrammarNode(ASSIGN_NODE, $1, $3);}
	|identifier ASSIGN lt_expression				{$$ = new CGrammarNode(ASSIGN_NODE, $1, $3);}
	;

eq_expression
	:simple_expression EQ simple_expression			{$$ = new CGrammarNode(EQ_NODE, $1, $3);}
	;

gt_expression
	:simple_expression GT simple_expression			{$$ = new CGrammarNode(GT_NODE, $1, $3);}
	;

lt_expression
	:simple_expression LT simple_expression			{$$ = new CGrammarNode(LT_NODE, $1, $3);}
	;

minus_expression
	:simple_expression MINUS simple_expression		{$$ = new CGrammarNode(MINUS_NODE, $1, $3);}
	;
	
plus_expression
	:simple_expression PLUS simple_expression			{$$ = new CGrammarNode(PLUS_NODE, $1, $3);}
	;
	
simple_expression
	:identifier					{$$ = $1;}
	|const_string				{$$ = $1;}
	|const_int					{$$ = $1;}
	|OPEN_PARAM simple_expression CLOSE_PARAM		{$$ = $2;}
	;

const_int
	:INT
	{
		SYNTAX_VALUE value;
		value.type = SYNTAX_INT;
		value.Vun.intVal = $1;
		int index = syntaxTable.AddSyntax(syntaxTable.ConstructName(), value);
		$$ = new CGrammarNode(CONST_INT_NODE, index);
	}
	;

const_string
	:STR
	{
		SYNTAX_VALUE value;
		value.type = SYNTAX_STR;
		value.Vun.strVal = $1;
		int index = syntaxTable.AddSyntax(syntaxTable.ConstructName(), value);
		$$ = new CGrammarNode(CONST_STR_NODE, index);
	}
	;

identifier
	:ID
	{
		int exist = syntaxTable.FindSyntax($1);
		if(exist != -1)
		{
			$$ = new CGrammarNode(IDENTITY_NODE, exist);
		}
		else
		{
			SYNTAX_VALUE value;
			value.type = SYNTAX_INT;
			int index = syntaxTable.AddSyntax($1, value);
			$$ = new CGrammarNode(IDENTITY_NODE, index);
		}
	}
	;

%%

void yyerror(char *msg) {
   printf("Error: %s lineno:%d.\n", msg, lineno);
}