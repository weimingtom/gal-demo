#include "stdafx.h"
#include "Quad.h"
#include "Game.h"

CQuad::CQuad( hgeQuad quad )
{
	memset(&m_quad, 0x0, sizeof(hgeQuad));
	m_quad = quad;
}

CQuad::CQuad()
{
	memset(&m_quad, 0x0, sizeof(hgeQuad));
}

CQuad::~CQuad(void)
{
}

void CQuad::Render( CGame * owner )
{
	owner->GetHgeHandle()->Gfx_RenderQuad(&m_quad);	
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