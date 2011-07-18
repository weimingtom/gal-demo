#pragma once

template<class OwnerType> class CState
{
public:
	virtual ~CState();
	virtual void Enter(OwnerType *) = 0;
	virtual void Execute(OwnerType *) = 0;
	virtual void Exit(OwnerType *) = 0;
};
