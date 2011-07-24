#pragma once
#include "State.h"
#include <assert.h>

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
	
	virtual void ChangeState(CState<OwnerType> * state)
	{
		assert(m_currentState && state);
		m_currentState->Exit(m_owner);
		m_previousState = m_currentState;
		m_currentState = state;
		m_currentState->Enter(m_owner);
	}

	void ShutDown()
	{
		m_currentState->Exit(m_owner);
	}

	virtual bool Update()
	{
		return m_currentState->Execute(m_owner);
	}

protected:
	CState<OwnerType>*			m_currentState;
	CState<OwnerType>*			m_previousState;
	OwnerType*					m_owner;
};
