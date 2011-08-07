#pragma once
#include <vector>
#include <string>
#include <map>
#include "gamestate.h"

enum
{
	ID_MAIN_BEGIN = 0,
	ID_MAIN_TEXTBOX,
	ID_MAIN_END,
};

class HGE;
class CInterpreter;
class CVM;
class SYNTAX_VALUE;
class CTextBox;



class CGameMain :
	public CGameState
{

typedef int (CGameMain::*SCRIPT_FUNC)(std::vector<SYNTAX_VALUE>&);
typedef std::map<const char*, SCRIPT_FUNC>	FUNC_MAP;

public:
	CGameMain(void);
	virtual ~CGameMain(void);

	static CGameMain* GetInstance();

	virtual void Enter(CGame *);
	virtual bool Execute(CGame *);
	virtual void Exit(CGame *);
	virtual bool Render();
	
	void SetScript(char * filename);

	static int FuncCallBack(const char *, std::vector<SYNTAX_VALUE>&, void *);
	int Func_Print(std::vector<SYNTAX_VALUE>&);

private:
	HGE		*m_hge;
	CInterpreter*		m_interpreter;
	CVM*				m_vm;
	std::string			m_scriptFileName;
	bool				m_keeySyntax;
	CTextBox*			m_textbox;
	FUNC_MAP			m_funcMap;
};
