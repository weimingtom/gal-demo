#include "stdafx.h"
#include "constdefines.h"
#include "GameDefaultAction.h"
#include "Game.h"


CGameDefaultAction::CGameDefaultAction(void)
{
	m_hge = hgeCreate(HGE_VERSION);
}

CGameDefaultAction::~CGameDefaultAction(void)
{
	m_hge->Release();
}

bool CGameDefaultAction::execute(CGameState *state)
{
	
	bool esc = m_hge->Input_GetKeyState(HGEK_ESCAPE);
	if (esc)
	{
		if (MessageBox(NULL, "确定要退出吗?", "退出", MB_YESNO | MB_ICONINFORMATION) == IDYES)
		{
			return true;
		}
	}
	return false;
}
