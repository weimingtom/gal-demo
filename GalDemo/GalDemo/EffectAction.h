#pragma once
#include "action.h"

class CRenderableObject;

class CEffectAction :
	public CAction
{
public:
	CEffectAction(CRenderableObject *);
	virtual ~CEffectAction(void);

	virtual int execute(CGameState *);//Ч����ɺ󷵻� ID ����0

private:
	CRenderableObject *m_object;
};
