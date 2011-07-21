#pragma once
#include "action.h"

class CGame;
class HGE;

class CGameDefaultAction :
	public CAction
{
public:
	CGameDefaultAction(void);
	virtual ~CGameDefaultAction(void);

	virtual bool execute(CGameState *state);

protected:
	HGE*		m_hge;
};
