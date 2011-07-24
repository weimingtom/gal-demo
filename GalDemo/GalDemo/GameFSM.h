#pragma once
#include "StateMachine.h"
#include "GameState.h"

class CGame;

class CGameFSM :
	public CStateMachine<CGame>
{
public:
	CGameFSM(CGame *owner):CStateMachine<CGame>(owner), m_isChaningState(false){}

	bool Render()
	{
		if (m_isChaningState)
		{
			bool pfinished = reinterpret_cast<CGameState *>(m_currentState)->IsFinished();
			bool cfinished = reinterpret_cast<CGameState *>(m_previousState)->IsFinished();
			
			if (!pfinished)
			{
				reinterpret_cast<CGameState *>(m_previousState)->Render();
			}
			else if (!cfinished)
			{
				reinterpret_cast<CGameState *>(m_currentState)->Render();
			}
		}
		else
		{
			reinterpret_cast<CGameState *>(m_currentState)->Render();
		}
		return false;
	}

	virtual bool Update()
	{
		bool ret = true;
		if (m_isChaningState)
		{
			bool pfinished = reinterpret_cast<CGameState *>(m_currentState)->IsFinished();
			bool cfinished = reinterpret_cast<CGameState *>(m_previousState)->IsFinished();
			
			if (!pfinished)
			{
				ret = m_previousState->Execute(m_owner);
			}
			else if (!cfinished)
			{
				ret = m_currentState->Execute(m_owner);
			}

			if (pfinished && cfinished)
			{
				ret = m_currentState->Execute(m_owner);
				m_isChaningState = false;
			}
		}
		else
		{
			ret = m_currentState->Execute(m_owner);
		}
		return ret;
	}

	virtual void ChangeState(CGameState * state)
	{
		CStateMachine::ChangeState(state);
		m_isChaningState = true;
	}
protected:
	bool	m_isChaningState;
};
