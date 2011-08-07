#pragma once
#include <list>
#include <vector>
#include "GrammarNode.h"
#include "SyntaxTable.h"

enum 
{
	CMD_PUSH, // push the syntax value to the stack
	CMD_LT,
	CMD_EQ,
	CMD_GT,
	CMD_PLUS, // plus and minus calculate the 0regA and regB, and push the result in the stack
	CMD_MINUS,
	CMD_ASN,
	CMD_JZ,
	CMD_JMP,
	CMD_CALL,
};

typedef struct  
{
	int op;
	int arg;
}COMMAND;

class CInterpreter
{
public:
	CInterpreter(void);
	~CInterpreter(void);
	void Initialize(std::list<CGrammarNode *> list, CSyntaxTable* table);
	void Finalize();

	int Step();
	std::vector<COMMAND> GenCmdList();
	
private:
	int GenCommand(CGrammarNode *, std::vector<COMMAND>&);
	void FixJump(std::vector<COMMAND>&, int);
	const SYNTAX_VALUE ParseNode(CGrammarNode *);

	std::list<CGrammarNode *>				m_grammarList;
	CSyntaxTable*							m_syntaxTable;
	std::list<CGrammarNode *>::iterator		m_cur;
	std::vector<SYNTAX_VALUE>				m_funcParams;
	std::vector<COMMAND>					m_cmdList;
};
