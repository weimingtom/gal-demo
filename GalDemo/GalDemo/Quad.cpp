#include "stdafx.h"
#include "Quad.h"
#include "Game.h"
#include <assert.h>

CQuad::CQuad( hgeQuad quad, int id):CRenderableObject(id)
{
	memset(&m_quad, 0x0, sizeof(hgeQuad));
	memcpy(&m_quad, &quad, sizeof(hgeQuad));
}

CQuad::CQuad(HTEXTURE tex, int id):CRenderableObject(id)
{
	assert(tex != 0);
	memset(&m_quad, 0x0, sizeof(hgeQuad));
	for (int i = 0; i < 4; i++)
	{
		m_quad.v[i].col = 0xffffffff;
		m_quad.v[i].z = 0.5;
	}

	m_quad.blend = BLEND_DEFAULT;
	m_quad.tex = tex;
	
	HGE *hge = hgeCreate(HGE_VERSION);
	
	float width = hge->Texture_GetWidth(tex);
	float height = hge->Texture_GetHeight(tex);
	hge->Release();

	m_quad.v[0].tx = 0;
	m_quad.v[0].ty = 0;
	
	m_quad.v[1].tx = 1;
	m_quad.v[1].ty = 0;

	m_quad.v[2].tx = 1;
	m_quad.v[2].ty = 1;
	
	m_quad.v[3].tx = 0;
	m_quad.v[3].ty = 1;

	m_quad.v[0].x = 0;
	m_quad.v[0].y = 0;

	m_quad.v[1].x = width;
	m_quad.v[1].y = 0;

	m_quad.v[2].x = width;
	m_quad.v[2].y = height;

	m_quad.v[3].x = 0;
	m_quad.v[3].y = height;
}

CQuad::~CQuad(void)
{
}

void CQuad::Render()
{
	HGE *hge = hgeCreate(HGE_VERSION);
	hge->Gfx_RenderQuad(&m_quad);	
	
	hge->Release();
}

void CQuad::SetVertex( FPOINT pos[4] )
{
	for (int i = 0; i < 4; i++)
	{
		m_quad.v[i].tx = pos[i].x;
		m_quad.v[i].ty = pos[i].y;
	}
}

void CQuad::GetVertex(FPOINT pos[4])
{
	for (int i = 0; i < 4; i++)
	{
		pos[i].x = m_quad.v[i].tx;
		pos[i].y = m_quad.v[i].ty;
	}
}

void CQuad::SetPosition( FPOINT pos[4] )
{
	for (int i = 0; i < 4; i++)
	{
		m_quad.v[i].x = pos[i].x;
		m_quad.v[i].y = pos[i].y;
	}
}

void CQuad::GetPosition( FPOINT pos[4] )
{
	for (int i = 0; i < 4; i++)
	{
		pos[i].x = m_quad.v[i].x;
		pos[i].y = m_quad.v[i].y;
	}
}

void CQuad::SetColor( int color[4] )
{
	for (int i = 0; i < 4; i++)
	{
		m_quad.v[i].col = color[i];
	}
}

void CQuad::GetColor( int color[4] )
{
	for (int i = 0; i < 4; i++)
	{
		color[i] = m_quad.v[i].col;
	}
}	

void CQuad::SetZ( float z[4] )
{
	for (int i = 0; i < 4; i++)
	{
		m_quad.v[i].z = z[i];
	}
}

void CQuad::GetZ( float z[4] )
{
	for (int i = 0; i < 4; i++)
	{
		z[i] = m_quad.v[i].z;
	}
}

FPOINT CQuad::GetTopLeft()
{
	return FPOINT(m_quad.v[0].x, m_quad.v[0].y);
}

void CQuad::SetTopLeft( FPOINT point )
{
	float width = GetWidth();
	float height = GetHeight();

	m_quad.v[0].x = point.x; m_quad.v[0].y  = point.y;
	m_quad.v[1].x = point.x + width; m_quad.v[1].y  = point.y;
	m_quad.v[2].x = point.x + width; m_quad.v[2].y  = point.y + height;
	m_quad.v[3].x = point.x; m_quad.v[3].y  = point.y + height;
}

float CQuad::GetWidth()
{
	return m_quad.v[1].x - m_quad.v[0].x;
}

float CQuad::GetHeight()
{
	return m_quad.v[2].y - m_quad.v[1].y;
}