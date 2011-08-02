#pragma once
#include "GrammarNode.h"
#include "SyntaxTable.h"
#include <list>

extern std::list<CGrammarNode*> grammarList;
extern CSyntaxTable syntaxTable;

extern int yyparse();