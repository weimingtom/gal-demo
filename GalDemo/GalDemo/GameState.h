#pragma once
#include "state.h"
#include <set>
class CGame;
class CRenderableObject;

class CGameState :
	public CState<CGame>
{
public:

	virtual bool Render() = 0;

protected:
	std::set<CRenderableObject *>	m_renderGroup[3];//0 BG 1 character 2 gui
};
