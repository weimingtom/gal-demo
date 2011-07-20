#pragma once
#include <list>
#include <set>
#include "hge.h"

class CDisplay;
class CGameFSM;
class CRenderableObject;

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

	static bool RenderFunc();
	static bool FrameFunc();

protected:
	HGE*							m_hge;
	CDisplay*						m_display;
	CGameFSM						*m_fsm;
};
