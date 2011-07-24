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
#include "Text.h"
#include "ConfigManager.h"

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
	
	m_renderGroup[0].insert(new CQuad(ResMgr->GetTexture(RES_TEXTURE_TEST)));
	CText *text = new CText;

	if (!text->LoadFont(CfgMgr->GetSystenFont().c_str(), 60))
	{
		MessageBox(NULL, "无法加载字体!", "错误", MB_OK | MB_ICONWARNING);
		game->EndGame();
	}
	else
	{
		text->SetText(L"haha！");
		text->SetColor(ARGB(255, 0, 0, 0));
		FPOINT p(100.0, 100.0);
		text->SetPos(p);
		m_renderGroup[2].insert(text);
	}
}

bool CDefaultGameState::Execute( CGame * game )
{

	if (m_actionStack.top()->execute(this))
	{
		return true;
	}
	return false;
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

bool CDefaultGameState::Render()
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
	return true;
}