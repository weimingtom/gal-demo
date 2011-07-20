#pragma once

class CRenderableObject
{
public:
	virtual ~CRenderableObject(void){};

	virtual void Render() = 0;
};
