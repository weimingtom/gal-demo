#pragma once
#include "StateMachine.h"
#include "GameState.h"

class CGame;

class CGameFSM :
	public CStateMachine<CGame>
{
public:
	CGameFSM(CGame *owner):CStateMachine<CGame>(owner){}

	bool Render() const
	{
		return reinterpret_cast<CGameState *>(m_currentState)->Render();
	}
};
