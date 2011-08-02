#pragma once
#include "gamestate.h"

class HGE;

class CGameMain :
	public CGameState
{
public:
	CGameMain(void);
	virtual ~CGameMain(void);

	static CGameMain* GetInstance();

	virtual void Enter(CGame *);
	virtual bool Execute(CGame *);
	virtual void Exit(CGame *);
	virtual bool Render();

private:
	HGE		*m_hge;
};
