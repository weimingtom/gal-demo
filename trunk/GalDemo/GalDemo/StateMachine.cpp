#include "stdafx.h"
#include "StateMachine.h"

template<class OwnerType> 
CStateMachine<OwnerType>::CStateMachine(OwnerType* owner):
m_owner(owner),
m_currentState(NULL)
{

}

template<class OwnerType> 
CStateMachine<OwnerType>::~CStateMachine( void )
{

}

template<class OwnerType> 
void CStateMachine<OwnerType>::ChangeState( CState<OwnerType> * state) 
{
	assert(m_currentState && state);

	m_currentState->Exit(m_owner);
	m_currentState = state;
	m_currentState->Enter(m_owner);
}


template<class OwnerType>
void CStateMachine<OwnerType>::Update() const
{
	m_currentState->Execute(m_owner);
}


template<class OwnerType>
void CStateMachine<OwnerType>::SetCurrentState( CState<OwnerType> *state )
{
	m_currentState = state;
}
