#include "stdafx.h"
#include "EffectAction.h"
#include "RenderableObject.h"
#include "GameState.h"

CEffectAction::CEffectAction( CRenderableObject * object):m_object(object)
{
}

CEffectAction::~CEffectAction(void)
{
}

int CEffectAction::execute( CGameState * state)
{
	HGE *hge = hgeCreate(HGE_VERSION);
	float dt = hge->Timer_GetDelta();
	hge->Release();

	int ret = m_object->Update(dt);
	
	if (ret)
	{
		state->RemoveObject(m_object->GetID());
		int id = m_object->GetID();
		delete m_object;
		return id;
	}
	else
	{
		return 0;
	}
}