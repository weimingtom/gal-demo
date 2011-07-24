#pragma once

class CGame;
class CGameState;

class CAction
{
public:
	virtual ~CAction(void){};

	virtual int execute(CGameState *) = 0;
};
