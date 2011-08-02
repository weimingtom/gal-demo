#pragma once
#include <list>
#include <vector>
#include "GrammarNode.h"
#include "SyntaxTable.h"

class CInterpreter
{
public:
	CInterpreter(void);
	~CInterpreter(void);
	void Initialize(std::list<CGrammarNode *> list, CSyntaxTable* table);
	void Finalize();

	int Step();

private:
	const SYNTAX_VALUE ParseNode(CGrammarNode *);


	std::list<CGrammarNode *>				m_grammarList;
	CSyntaxTable*							m_syntaxTable;
	std::list<CGrammarNode *>::iterator		m_cur;
	std::vector<SYNTAX_VALUE>				m_funcParams;
};
