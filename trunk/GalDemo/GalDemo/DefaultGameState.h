#pragma once
#include "GameState.h"
#include <stack>

class CAction;
class CGame;
class CQuad;

class CDefaultGameState :
	public CGameState
{
public:
	CDefaultGameState(void);
	virtual ~CDefaultGameState(void);
	
	static CDefaultGameState* GetInstance();
	virtual void Enter(CGame *);
	virtual BOOL Execute(CGame *);
	virtual void Exit(CGame *);
	virtual BOOL Render(CGame *);

protected:
	std::stack<CAction *>	m_actionStack;
	CQuad					*m_quad;
};
