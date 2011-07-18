#pragma once
#include "State.h"

template<class OwnerType> class CStateMachine
{
public:
	CStateMachine(OwnerType *owner);
	virtual ~CStateMachine(void);

	void SetCurrentState(CState<OwnerType> *);
	void ChangeState(CState<OwnerType> *);
	void Update() const;

protected:
	CState<OwnerType>*			m_currentState;
	OwnerType*					m_owner;
};
