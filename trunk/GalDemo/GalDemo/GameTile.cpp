#include "stdafx.h"
#include "GameTile.h"
#include "MenuAction.h"
#include "ShadowMenu.h"
#include "Quad.h"
#include "Text.h"
#include "DefaultGameState.h"
#include "Game.h"
#include "GameFSM.h"
#include "gui.h"
#include "FadeOut.h"
#include "EffectAction.h"

CGameTile::CGameTile(void)
{
	m_hge = hgeCreate(HGE_VERSION);
}

CGameTile::~CGameTile(void)
{
	m_hge->Release();
}

void CGameTile::Enter( CGame * )
{
	CText t;
	t.LoadFont(CfgMgr->GetSystenFont().c_str(), TITLE_FONT_SIZE);
	float testWidth = t.TestWidth(L"四字测试");

	FPOINT pos((float)(CfgMgr->GetWindowWidth() - testWidth) / 2, 300.0);
	CGUI* menu = new CGUI(ID_TITLE_MAIN_MENU);
	menu->AddCtrl(new CShadowMenu(TITLE_MENU_START, L"开始游戏", pos));
	pos.y += t.GetHeight() + 10;
	menu->AddCtrl(new CShadowMenu(TITLE_MENU_CONTINUE, L"继续游戏", pos));
	pos.y += t.GetHeight() + 10;
	menu->AddCtrl(new CShadowMenu(TITLE_MENU_EXIT, L"离开游戏", pos));
	
	HTEXTURE tex = ResMgr->GetTexture(RES_TEXTURE_CURSOR);
	m_cursor = new hgeSprite(ResMgr->GetTexture(RES_TEXTURE_CURSOR), 0, 0, 32, 32);
	menu->SetCursor(m_cursor);
	
	menu->Enter();
	m_renderGroup[2].insert(menu);

	m_renderGroup[0].insert(new CQuad(ResMgr->GetTexture(RES_TEXTURE_TITLE), ID_TITLE_BACK_GROUND));

	m_actionStack.push(new CMenuAction(menu));
}

bool CGameTile::Execute( CGame * game )
{
	
	int result = m_actionStack.top()->execute(this);

	switch(result)
	{
	case TITLE_MENU_START:
		{
			CQuad *bg = reinterpret_cast<CQuad *>(RemoveObject(ID_TITLE_BACK_GROUND));
			CFadeOut *fadeout = new CFadeOut(bg->GetTexture(), 0.5, 133);
			delete bg;
			m_renderGroup[0].insert(fadeout);
			m_actionStack.push(new CEffectAction(fadeout));
			//game->GetFSM()->ChangeState(CDefaultGameState::GetInstance());
			break;
		}
	case TITLE_MENU_CONTINUE:
		{
			reinterpret_cast<CGUI *>(GetObject(ID_TITLE_MAIN_MENU))->Enter();
			break;
		}
	case TITLE_MENU_EXIT:
		return true;
		break;
	default:
		break;
	}

	if (result == 133)
	{
		game->GetFSM()->ChangeState(CDefaultGameState::GetInstance());
	}
	return false;
}

void CGameTile::Exit( CGame * )
{
	while(m_actionStack.size())
	{
		delete m_actionStack.top();
		m_actionStack.pop();
	}

	DestoryAllObject();
	delete m_cursor;
}

bool CGameTile::Render()
{
	m_hge->Gfx_BeginScene();
	m_hge->Gfx_Clear(0);
	RenderAllObject();
	m_hge->Gfx_EndScene();
	return false;
}

CGameTile* CGameTile::GetInstance()
{
	static CGameTile instance;
	return &instance;
}
