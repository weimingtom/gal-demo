#pragma once

class CGame;
class CGameState;

class CAction
{
public:
	virtual ~CAction(void){};

	virtual bool execute(CGameState *) = 0;
};
