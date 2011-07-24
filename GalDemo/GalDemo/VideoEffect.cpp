#include "stdafx.h"
#include "VideoEffect.h"

CVideoEffect::CVideoEffect( float delay, int id )
: CRenderableObject(id)
, m_delay(delay)
, m_timer(0)
, m_progress(0)
{

}
CVideoEffect::~CVideoEffect(void)
{
}

int CVideoEffect::Update( float dt )
{
	m_timer += dt;
	if (m_timer > m_delay)
	{
		m_progress = 1.0;
		return m_ID;
	}
	else
	{
		m_progress  = m_timer / m_delay;
	}
	return 0;
}