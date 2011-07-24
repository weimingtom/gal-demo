#include "stdafx.h"
#include "Game.h"
#include "ConfigManager.h"
#include "constdefines.h"
#include "hge.h"
#include "GameFSM.h"
#include "DefaultGameState.h"
#include "ResourceManager.h"
#include "GameTile.h"

CGame::CGame(void):m_hge(NULL), m_fsm(NULL), m_over(true)
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

bool CGame::Initialize()
{
	CfgMgr->Initialize(CONFIG_FILE_NAME);
	ResMgr->Initialize("default");

	m_hge = hgeCreate(HGE_VERSION);

	m_hge->System_SetState(HGE_WINDOWED, CfgMgr->IsWindowed());
	m_hge->System_SetState(HGE_SCREENWIDTH, CfgMgr->GetWindowWidth());
	m_hge->System_SetState(HGE_SCREENHEIGHT, CfgMgr->GetWindowHeight());
	m_hge->System_SetState(HGE_SCREENBPP, CfgMgr->GetScreenDepth());

	m_hge->System_SetState(HGE_LOGFILE, CfgMgr->GetLogFileName().c_str());
	m_hge->System_SetState(HGE_TITLE, CfgMgr->GetWindowTitle().c_str());

	m_hge->System_SetState(HGE_FRAMEFUNC, &CGame::FrameFunc);
	m_hge->System_SetState(HGE_RENDERFUNC, &CGame::RenderFunc);
	m_hge->System_SetState(HGE_EXITFUNC, &CGame::ExitFunc);
	
	//m_hge->System_SetState(HGE_HIDEMOUSE, false);

	if (!m_hge->System_Initiate())
	{
		return false;
	}
	m_over = false;

	return true;
}

bool CGame::Finalize()
{
	m_fsm->ShutDown();
	CfgMgr->Finalize();
	ResMgr->Finalize();
	m_hge->System_Shutdown();
	m_hge->Release();

	return true;
}

bool CGame::Start()
{
	m_fsm->StartUp(TitleState);
	m_hge->System_Start();
	return true;
}

bool CGame::RenderFunc()
{
	Game->Render();
	return false;
}

bool CGame::FrameFunc()
{
	return Game->Update();
}

bool CGame::ExitFunc()
{
	if (MessageBox(NULL, "确定要退出吗?", "退出", MB_YESNO | MB_ICONINFORMATION) == IDYES)
	{
		return true;
	}
	return false;
}

bool CGame::Update()
{
	if (m_over)
	{
		return true;
	}

	return m_fsm->Update();
}

bool CGame::Render()
{
	return m_fsm->Render();
}

