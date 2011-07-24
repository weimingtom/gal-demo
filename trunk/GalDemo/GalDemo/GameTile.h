#pragma once
#include "gamestate.h"
#include <stack>

enum _title_menu_id_{
	TITLE_MENU_BEGIN = 0,
	TITLE_MENU_START,
	TITLE_MENU_CONTINUE,
	TITLE_MENU_EXIT,
	TITLE_MENU_END
};

enum _title_objects_
{
	ID_TITLE_BEGIN = 0,
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
