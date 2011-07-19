#pragma once
#include "state.h"
#include <stack>

template<class OwnerType> class CAction;
class CGame;

class CDefaultGameState :
	public CState<CGame>
{
public:
	CDefaultGameState(void);
	virtual ~CDefaultGameState(void);
	
	static CDefaultGameState* GetInstance();
	virtual void Enter(CGame *);
	virtual BOOL Execute(CGame *);
	virtual void Exit(CGame *);

protected:
	std::stack<CAction<CGame> *>			m_actionStack;
};
