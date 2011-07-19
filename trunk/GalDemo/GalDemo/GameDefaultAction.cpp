#include "stdafx.h"
#include "constdefines.h"
#include "GameDefaultAction.h"
#include "Game.h"


CGameDefaultAction::CGameDefaultAction(void)
{
}

CGameDefaultAction::~CGameDefaultAction(void)
{
}

BOOL CGameDefaultAction::execute(CGame *game)
{
	BOOL esc = Game->GetCurrentKeyState(HGEK_ESCAPE);
	if (esc)
	{
		if (MessageBox(NULL, "确定要退出吗?", "退出", MB_YESNO | MB_ICONINFORMATION) == IDYES)
		{
			return TRUE;
		}
	}
	return FALSE;
}

CGameDefaultAction* CGameDefaultAction::GetInstance()
{
	static CGameDefaultAction instance;
	return &instance;
}
