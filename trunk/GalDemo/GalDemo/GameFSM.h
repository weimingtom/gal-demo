#pragma once
#include "StateMachine.h"
#include "GameState.h"

class CGame;

class CGameFSM :
	public CStateMachine<CGame>
{
public:
	CGameFSM(CGame *owner):CStateMachine<CGame>(owner){}

	BOOL Render() const
	{
		return m_currentState->Render(m_owner);
	}

protected:
	CGameState*			m_currentState;
};
