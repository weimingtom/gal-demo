#pragma once
#include "GameState.h"
#include <stack>

class CAction;
class CGame;

class CDefaultGameState :
	public CGameState
{
public:
	CDefaultGameState(void);
	virtual ~CDefaultGameState(void);
	
	static CDefaultGameState* GetInstance();

	virtual void Enter(CGame *);
	virtual bool Execute(CGame *);
	virtual void Exit(CGame *);
	virtual bool Render();

protected:
	std::stack<CAction *>	m_actionStack;
};
