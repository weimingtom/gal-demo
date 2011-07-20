#include "stdafx.h"
#include "DefaultGameState.h"
#include "GameDefaultAction.h"
#include "Action.h"
#include "Game.h"
#include "ResourceManager.h"
#include "IDdefines.h"
#include "utils.h"
#include "Quad.h"
#include "constdefines.h"

CDefaultGameState::CDefaultGameState(void)
{
	
}

CDefaultGameState::~CDefaultGameState(void)
{
	
}

void CDefaultGameState::Enter( CGame * game )
{
	CGameDefaultAction *action = new CGameDefaultAction;
	m_actionStack.push(action);

	CQuad *quad = new CQuad;
	m_renderGroup[0].insert(quad);
	HTEXTURE tex = ResMgr->GetTexture(ID_TEXTURE_TEST);
	quad->SetTexture(tex);
	FPOINT vs[4] = {{0.0, 0.0}, {1.0, 0.0},
	{1.0, 1.0}, {0.0, 1.0}};
	quad->SetVertex(vs);
	FPOINT pos[4] = {{0, 0}, {488, 0}, {488, 512}, {0, 512}};
	quad->SetPosition(pos);
}

BOOL CDefaultGameState::Execute( CGame * game )
{
	return m_actionStack.top()->execute(this);
}

void CDefaultGameState::Exit( CGame * game )
{
	while(m_actionStack.size())
	{
		delete m_actionStack.top();
		m_actionStack.pop();
	}
	for(int i = 0; i < 3; i++)
	{
		std::set<CRenderableObject *>::iterator iter = m_renderGroup[i].begin();
		while(iter != m_renderGroup[i].end())
		{
			delete (*iter);
			iter++;
		}
	}
}

CDefaultGameState* CDefaultGameState::GetInstance()
{
	static CDefaultGameState instance;
	return &instance;
}

BOOL CDefaultGameState::Render( )
{
	HGE *hge = hgeCreate(HGE_VERSION);
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	
	for(int i = 0; i < 3; i++)
	{
		std::set<CRenderableObject *>::iterator iter = m_renderGroup[i].begin();
		while(iter != m_renderGroup[i].end())
		{
			(*iter)->Render();
			iter++;
		}
	}

	hge->Gfx_EndScene();
	hge->Release();
	return TRUE;
}