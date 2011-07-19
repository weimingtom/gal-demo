#pragma once

template<class OwnerType>
class CRenderableObject
{
public:
	virtual ~CRenderableObject(void){};

	virtual void Render(OwnerType *) = 0;
};
