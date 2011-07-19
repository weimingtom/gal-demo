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
	return esc;
}

CGameDefaultAction* CGameDefaultAction::GetInstance()
{
	static CGameDefaultAction instance;
	return &instance;
}
