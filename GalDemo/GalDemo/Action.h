#pragma once

template<class OwnerType>
class CAction
{
public:
	virtual ~CAction(void){};

	virtual BOOL execute(OwnerType *) = 0;
};
