#pragma once
#include <list>
#include "hge.h"

class CDisplay;
template<class OwnerType> class CStateMachine;

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

	BOOL Initialize();
	BOOL Finalize();
	BOOL Start();
	
	BOOL Update();

	void GetKeyInfo(KEY_INFO *, int keycode = 0);
	BOOL GetCurrentKeyState(int);

	static BOOL RenderFunc();
	static BOOL FrameFunc();
protected:
	HGE*						m_hge;
	CDisplay*					m_display;
	CStateMachine<CGame>		*m_fsm;
};
