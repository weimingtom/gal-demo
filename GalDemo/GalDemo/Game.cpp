#include "stdafx.h"
#include "Game.h"
#include "ConfigManager.h"
#include "constdefines.h"
#include "hge.h"
#include "GameFSM.h"
#include "DefaultGameState.h"
#include "ResourceManager.h"


static WNDPROC g_oldWndProc = NULL;

LRESULT CALLBACK MyWindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CLOSE:
		{
			if (MessageBox(NULL, "确定要退出吗?", "退出", MB_YESNO | MB_ICONINFORMATION) == IDNO)
			{
				return FALSE;
			}
		}
		break;
	default:
		break;
	}
	g_oldWndProc(hwnd, uMsg, wParam, lParam);
}

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
	
	if (!m_hge->System_Initiate())
	{
		return FALSE;
	}
	
	g_oldWndProc = SubclassWindow(m_hge->System_GetState(HGE_HWND), MyWindowProc);

	m_fsm->StartUp(CDefaultGameState::GetInstance());

	return TRUE;
}

BOOL CGame::Finalize()
{
	m_fsm->ShutDown();
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

bool CGame::RenderFunc()
{
	Game->Render();
	return TRUE;
}

bool CGame::FrameFunc()
{
	return Game->Update();
}

BOOL CGame::Update()
{
	return m_fsm->Update();
}

BOOL CGame::Render()
{
	return m_fsm->Render();
}
