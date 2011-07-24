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
	CGameFSM* GetFSM(){return m_fsm;}

	bool Initialize();
	bool Finalize();
	bool Start();
	
	bool Update();
	bool Render();

	static bool RenderFunc();
	static bool FrameFunc();
	static bool ExitFunc();

	void EndGame(){m_over = true;}

protected:
	HGE*							m_hge;
	CDisplay*						m_display;
	CGameFSM*						m_fsm;
	bool							m_over;
};
