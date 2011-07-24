#include "stdafx.h"
#include "ShadowMenu.h"
#include "Text.h"

CShadowMenu::CShadowMenu(int _id, LPCWSTR text, FPOINT pos): m_pos(pos), m_offset(0.0), m_dance(false)
{
	id = _id;
	m_text = new CText;
	m_shadow = new CText;

	m_text->LoadFont(CfgMgr->GetSystenFont().c_str(), TITLE_FONT_SIZE);
	m_shadow->LoadFont(CfgMgr->GetSystenFont().c_str(), TITLE_FONT_SIZE);

	m_text->SetText(text);
	m_shadow->SetText(text);

	m_mainColor.SetHWColor(0xFF000050);
	m_shadowColor.SetHWColor(0x60000000);
	m_highlightColor.SetHWColor(0xFF0000FF);

	rect.Set(pos.x, pos.y, pos.x + m_text->GetWidth(), pos.y + m_text->GetHeight());
}

CShadowMenu::~CShadowMenu(void)
{
	delete m_text;
	delete m_shadow;
}

void CShadowMenu::Render()
{
	FPOINT pos(m_pos.x + m_offset + 2, m_pos.y + 2);
	m_shadow->SetPos(pos);
	m_shadow->SetColor(m_shadowColor.GetHWColor());
	m_shadow->Render();

	
	m_text->SetPos(m_pos - m_offset);
	m_text->SetColor(m_color.GetHWColor());
	m_text->Render();
}

void CShadowMenu::Update( float dt )
{
	if (m_dance)
	{
		m_timer += dt;
		if (m_timer > 0.2)
		{
			m_offset = m_dstOffset;
			m_color = m_dstColor;
			m_dance = false;
			m_timer = 0;
		}
		else
		{
			float doff = m_dstOffset - m_offset;
			m_offset = m_srcOffset + doff * m_timer * 5;
			
			hgeColor dcolor = m_dstColor - m_color;
			m_color = m_srcColor + dcolor * m_timer * 5;
		}
	}
	else if (0 != m_finished)
	{
		m_timer += dt;
		if (m_timer > 0.5)
		{
			m_timer = 0;
			if (1 == m_finished)
			{
				m_color.SetHWColor(ARGB(255, GETR(m_mainColor.GetHWColor()),
					GETG(m_mainColor.GetHWColor()), GETB(m_mainColor.GetHWColor())));
				m_shadowColor.SetHWColor(0x60000000);
			}
			else
			{
				m_color.SetHWColor(ARGB(0, GETR(m_mainColor.GetHWColor()),
					GETG(m_mainColor.GetHWColor()), GETB(m_mainColor.GetHWColor())));
				m_color.SetHWColor(0x00000000);
			}
			
			m_finished = 0;
		}
		else
		{
			if (1 == m_finished)
			{
				int alpha = 255 * m_timer * 2;
				int saplha = 96 * m_timer * 2;
				m_color.SetHWColor(ARGB(alpha, GETR(m_mainColor.GetHWColor()),
					GETG(m_mainColor.GetHWColor()), GETB(m_mainColor.GetHWColor())));
				m_shadowColor.SetHWColor(ARGB(saplha, 0, 0, 0));
			}
			else
			{
				int alpha = 255 - 255 * m_timer * 2;
				int saplha = 96 - 96 * m_timer * 2;
				m_color.SetHWColor(ARGB(alpha, GETR(m_mainColor.GetHWColor()),
					GETG(m_mainColor.GetHWColor()), GETB(m_mainColor.GetHWColor())));
				m_shadowColor.SetHWColor(ARGB(saplha, 0, 0, 0));
			}
		}
	}
}

void CShadowMenu::Enter()
{
	m_offset = 0;
	m_timer = 0;
	m_dance = false;
	m_color.SetHWColor(ARGB(0, GETR(m_mainColor.GetHWColor()),
		GETG(m_mainColor.GetHWColor()), GETB(m_mainColor.GetHWColor())));

	m_finished = 1;
}

void CShadowMenu::Leave()
{
	m_finished = -1;
}

bool CShadowMenu::IsDone()
{
	return m_finished == 0;
}

void CShadowMenu::Focus( bool bFocused )
{

}

void CShadowMenu::MouseOver( bool bOver )
{
	if (bOver)
	{
		m_srcOffset = m_offset;
		m_dstOffset = 3;
		m_srcColor = m_color;
		m_dstColor = m_highlightColor;
		m_dance = true;
	}
	else
	{
		m_srcOffset = m_offset;
		m_dstOffset = 0;
		m_srcColor = m_color;
		m_dstColor = m_mainColor;
		m_dance = true;
	}
}

bool CShadowMenu::MouseLButton( bool bDown )
{
	m_oldOffset = m_offset;
	if (bDown)
	{
		m_oldOffset = m_offset;
		m_offset = 0;
		return true;
	}
	else
	{
		m_offset = m_oldOffset;
	}
	return false;
}

bool CShadowMenu::KeyClick( int key, int chr )
{
	return false;
}