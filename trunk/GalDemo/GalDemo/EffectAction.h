#pragma once
#include "action.h"

class CRenderableObject;

class CEffectAction :
	public CAction
{
public:
	CEffectAction(CRenderableObject *);
	virtual ~CEffectAction(void);

	virtual int execute(CGameState *);//效果完成后返回 ID 否则0

private:
	CRenderableObject *m_object;
};
