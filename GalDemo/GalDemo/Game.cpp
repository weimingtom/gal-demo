#include "stdafx.h"
#include "Game.h"
#include "ConfigManager.h"
#include "constdefines.h"
#include "hge.h"
#include "GameFSM.h"
#include "DefaultGameState.h"
#include "ResourceManager.h"

CGame::CGame(void):m_hge(NULL), m_fsm(NULL)
{
	m_fsm = new CGameFSM(this);
}

CGame::~CGame(void)
{
	if (m_fsm)
	{
		delete m_fsm;
		m_fsm = NULL;
	}
}

CGame* CGame::GetInstance()
{
	static CGame instance;
	return &instance;
}

BOOL CGame::Initialize()
{
	CfgMgr->Initialize(CONFIG_FILE_NAME);
	ResMgr->Initialize(".\\default");

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

	m_fsm->SetCurrentState(CDefaultGameState::GetInstance());

	return TRUE;
}

BOOL CGame::Finalize()
{
	CfgMgr->Finalize();
	ResMgr->Finalize();
	m_hge->System_Shutdown();
	m_hge->Release();

	return TRUE;
}

BOOL CGame::Start()
{
	m_hge->System_Start();
	return TRUE;
}

BOOL CGame::RenderFunc()
{
	
	return TRUE;
}

BOOL CGame::FrameFunc()
{
	if (Game->Update())
	{
		return TRUE;
	}
	return FALSE;
}

void CGame::GetKeyInfo( KEY_INFO * kinfo, int keycode)
{
	if (keycode)
	{
		kinfo->keycode = keycode;
		kinfo->down = m_hge->Input_KeyDown(keycode);
		kinfo->up = m_hge->Input_KeyUp(keycode);
		kinfo->keyname = m_hge->Input_GetKeyName(keycode);
	}
	kinfo->lastkeychar = m_hge->Input_GetChar();
	kinfo->lastkeycode = m_hge->Input_GetKey();
}

BOOL CGame::GetCurrentKeyState( int keycode )
{
	return m_hge->Input_GetKeyState(keycode);
}

BOOL CGame::Update()
{
	return m_fsm->Update();
}

BOOL CGame::Render()
{
	return TRUE;
}
