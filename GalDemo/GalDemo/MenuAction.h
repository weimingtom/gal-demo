#pragma once
#include "action.h"

class CGUI;

class CMenuAction :
	public CAction
{
public:
	CMenuAction(CGUI *gui):m_menu(gui){}
	virtual ~CMenuAction(void){}

	virtual int execute(CGameState *); //返回选中菜单的ID 否则返回0

private:
	CGUI*		m_menu;
	int			m_select;
};
