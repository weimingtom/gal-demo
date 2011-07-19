#pragma once
#include "action.h"

class CGame;

class CGameDefaultAction :
	public CAction
{
public:
	CGameDefaultAction(void);
	virtual ~CGameDefaultAction(void);
	static CGameDefaultAction* GetInstance();

	virtual BOOL execute(CGame *);
};
