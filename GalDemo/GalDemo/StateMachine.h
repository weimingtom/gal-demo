#pragma once
#include "State.h"

template<class OwnerType> class CStateMachine
{
public:
	CStateMachine(OwnerType *owner):m_owner(owner), m_currentState(NULL){}
	virtual ~CStateMachine(void){};
	
	void StartUp(CState<OwnerType> * state)
	{
		m_currentState = state;
		state->Enter(m_owner);
	}

	void SetCurrentState(CState<OwnerType> * state)
	{
		m_currentState = state;
	}
	
	void ChangeState(CState<OwnerType> * state)
	{
		assert(m_currentState && state);
		m_currentState->Exit(m_owner);
		m_currentState = state;
		m_currentState->Enter(m_owner);
	}

	void ShutDown()
	{
		m_currentState->Exit(m_owner);
	}

	bool Update() const
	{
		return m_currentState->Execute(m_owner);
	}

protected:
	CState<OwnerType>*			m_currentState;
	OwnerType*					m_owner;
};
