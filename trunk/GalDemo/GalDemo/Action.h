#pragma once

class CGame;
class CGameState;

class CAction
{
public:
	virtual ~CAction(void){};

	virtual BOOL execute(CGameState *) = 0;
};
