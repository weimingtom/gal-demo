#pragma once

class CRenderableObject
{
public:
	CRenderableObject(void);
	virtual ~CRenderableObject(void);

	virtual void Render() = 0;
};
