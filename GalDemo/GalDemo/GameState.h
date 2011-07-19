#pragma once
#include "state.h"
class CGame;

class CGameState :
	public CState<CGame>
{
public:

	virtual BOOL Render(CGame *) = 0;
};
