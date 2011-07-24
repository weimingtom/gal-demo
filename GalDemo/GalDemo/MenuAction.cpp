#include "stdafx.h"
#include "MenuAction.h"
#include "GameTile.h"
#include "Gui.h"

int CMenuAction::execute( CGameState * )
{
	HGE* hge = hgeCreate(HGE_VERSION);
	float dt = hge->Timer_GetDelta();
	hge->Release();

	int select = m_menu->Update(dt);
	
	if (select > 0)
	{
		m_menu->Leave();
		m_select = select;
	}
	else if (select < 0)
	{
		return m_select;
	}
	return 0;
}