#pragma once
#include <list>
#include <set>
#include "hge.h"

class CDisplay;
class CGameFSM;
template<class OwnerType> class CRenderableObject;
typedef struct _key_info_ 
{
	int			keycode;
	char*		keyname;
	BOOL		down;
	BOOL		up;
	int			lastkeycode;
	int			lastkeychar;
}KEY_INFO;

class CGame
{
public:
	CGame(void);
	virtual ~CGame(void);

	static CGame* GetInstance();

	HGE* GetHgeHandle(){return m_hge;}

	BOOL Initialize();
	BOOL Finalize();
	BOOL Start();
	
	BOOL Update();
	BOOL Render();

	void GetKeyInfo(KEY_INFO *, int keycode = 0);
	BOOL GetCurrentKeyState(int);

	static BOOL RenderFunc();
	static BOOL FrameFunc();
protected:
	HGE*							m_hge;
	CDisplay*						m_display;
	CGameFSM						*m_fsm;
	std::set<CRenderableObject *>	m_renderGroup[3];//0 BG 1 character 2 gui
};
