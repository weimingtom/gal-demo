#pragma once

class CGame;

class CAction
{
public:
	virtual ~CAction(void){};

	virtual BOOL execute(CGame *) = 0;
};
