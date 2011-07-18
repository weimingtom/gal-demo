#pragma once
#include <list>
#include "hge.h"


class CDisplay;

class CGame
{
public:
	CGame(void);
	virtual ~CGame(void);

	static CGame* GetInstance();

	BOOL Initialize();
	BOOL Finalize();
	
	BOOL Start();
	
	static BOOL RenderFunc();
	static BOOL FrameFunc();
protected:
	HGE*						m_hge;
	CDisplay*					m_display;
};
