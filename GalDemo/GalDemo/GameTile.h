#pragma once
#include "gamestate.h"
#include <stack>

enum {
	ID_TITLE_BEGIN = 0,
	//menu
	ID_TITLE_MENU_START,
	ID_TITLE_MENU_CONTINUE,
	ID_TITLE_MENU_EXIT,
	
	//objects
	ID_TITLE_MAIN_MENU,
	ID_TITLE_BACK_GROUND,
	ID_TITLE_FADE_OUT,

	ID_TITLE_END,
};

class CGameTile :
	public CGameState
{
public:
	
	CGameTile(void);
	virtual ~CGameTile(void);

	static CGameTile* GetInstance();
	
	virtual void Enter(CGame *);
	virtual bool Execute(CGame *);
	virtual void Exit(CGame *);
	virtual bool Render();
	
private:
	HGE*			m_hge;
	hgeSprite*		m_cursor;
	int				m_select;
};
