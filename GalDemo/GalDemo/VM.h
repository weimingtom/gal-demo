#pragma once
#include <vector>
#include <stack>
#include "Interpreter.h"

typedef int (* FUNC_CALLBACK)(const char *, std::vector<SYNTAX_VALUE>&, void *user);
//the function return 1 for it need to break and 0 not

class CVM
{
public:
	CVM();
	~CVM(void);

	void SetCommondList(std::vector<COMMAND> list, CSyntaxTable *table);
	void execute(int);
	void execute(char *);
	void execute();
	void SetFuncCallBack(FUNC_CALLBACK, void* user);

private:
	int ExecCmd(COMMAND);
	std::vector<COMMAND> m_cmdList;
	int		m_cur;
	std::stack<SYNTAX_VALUE> m_stack;			
	CSyntaxTable*		m_syntaxTable;
	FUNC_CALLBACK		m_callback;
	void*				m_user;
};
