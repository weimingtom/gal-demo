#include "stdafx.h"
#include "Game.h"
#include "ConfigManager.h"
#include "constdefines.h"
#include "hge.h"
#include "StateMachine.h"

CGame::CGame(void):m_hge(NULL)
{
}

CGame::~CGame(void)
{

}

CGame* CGame::GetInstance()
{
	static CGame instance;
	return &instance;
}

BOOL CGame::Start()
{
	m_hge->System_Start();
	return TRUE;
}

BOOL CGame::Initialize()
{
	CfgMgr->Initialize(CONFIG_FILE_NAME);

	m_hge = hgeCreate(HGE_VERSION);

	m_hge->System_SetState(HGE_WINDOWED, CfgMgr->IsWindowed());
	m_hge->System_SetState(HGE_SCREENWIDTH, CfgMgr->GetWindowWidth());
	m_hge->System_SetState(HGE_SCREENHEIGHT, CfgMgr->GetWindowHeight());
	m_hge->System_SetState(HGE_SCREENBPP, CfgMgr->GetScreenDepth());

	m_hge->System_SetState(HGE_LOGFILE, CfgMgr->GetLogFileName().c_str());
	m_hge->System_SetState(HGE_TITLE, CfgMgr->GetWindowTitle().c_str());
	
	m_hge->System_SetState(HGE_FRAMEFUNC, &CGame::FrameFunc);
	m_hge->System_SetState(HGE_RENDERFUNC, &CGame::RenderFunc);

	if (!m_hge->System_Initiate())
	{
		return FALSE;
	}

	return TRUE;
}


BOOL CGame::Finalize()
{
	CConfigManager::GetInstance()->Finalize();

	m_hge->System_Shutdown();
	m_hge->Release();

	return TRUE;
}

BOOL CGame::RenderFunc()
{

	return TRUE;
}

BOOL CGame::FrameFunc()
{
	if (CGame::GetInstance()->m_hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		return TRUE;
	}
	return FALSE;
}

