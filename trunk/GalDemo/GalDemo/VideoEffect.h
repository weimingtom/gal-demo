#pragma once
#include "renderableobject.h"

class CVideoEffect :
	public CRenderableObject
{
public:
	CVideoEffect(float delay, int id);
	virtual ~CVideoEffect(void);
	
	virtual int Update(float dt);
	
protected:
	float		m_delay;
	float		m_timer;
	float		m_progress;
};
