#include "stdafx.h"
#include "FadeOut.h"
#include "Quad.h"

CFadeOut::CFadeOut(HTEXTURE tex, float delay, int id,  int *srcAlpha/* = NULL*/)
: CVideoEffect(delay, id)
, m_tex(tex)
{
	if (srcAlpha)
	{
		m_srcAplha[0] = srcAlpha[0];
		m_srcAplha[1] = srcAlpha[1];
		m_srcAplha[2] = srcAlpha[2];
		m_srcAplha[3] = srcAlpha[3];
	}
	else
	{
		m_srcAplha[0] = 0xff;
		m_srcAplha[1] = 0xff;
		m_srcAplha[2] = 0xff;
		m_srcAplha[3] = 0xff;
	}
	m_quad = new CQuad(tex);
}

CFadeOut::~CFadeOut(void)
{
	delete m_quad;
}

void CFadeOut::Render()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	
	int col[4];
	m_quad->GetColor(col);
	col[0] = (col[0] & 0x00ffffff) + ((int)(m_srcAplha[0] * (1.0 - m_progress)) << 24);
	col[1] = (col[1] & 0x00ffffff) + ((int)(m_srcAplha[1] * (1.0 - m_progress)) << 24);
	col[2] = (col[2] & 0x00ffffff) + ((int)(m_srcAplha[2] * (1.0 - m_progress)) << 24);
	col[3] = (col[3] & 0x00ffffff) + ((int)(m_srcAplha[3] * (1.0 - m_progress)) << 24);
	m_quad->SetColor(col);
	m_quad->Render();

	hge->Release();
}
