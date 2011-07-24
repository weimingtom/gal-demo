#pragma once
#include "VideoEffect.h"
#include "hge.h"

class CQuad;

class CFadeOut :
	public CVideoEffect
{
public:
	CFadeOut(HTEXTURE tex, float delay, int id, int *srcAlpha = NULL);
	virtual ~CFadeOut(void);
	
	virtual void Render();

private:
	HTEXTURE	m_tex;
	int			m_srcAplha[4];
	CQuad*		m_quad;
};
