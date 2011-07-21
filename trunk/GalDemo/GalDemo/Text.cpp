#include "stdafx.h"
#include "Text.h"
#include "hgeTTFont.h"
#include "hgeTTFontManager.h"
#include "hgefont.h"

CText::CText(): m_ttfFont(NULL), m_text(NULL), m_alian(HGETEXT_LEFT)
{
	m_pos.x = 0.0;
	m_pos.y = 0.0;
}

CText::~CText(void)
{
	if (m_text)
	{
		delete[] m_text;
		m_text = NULL;
	}
}

void CText::Render()
{
	if (m_ttfFont)
	{
		m_ttfFont->Render(m_pos.x, m_pos.y, m_alian, m_text);
	}
}

bool CText::LoadFont(LPCSTR name, int size)
{
	m_ttfFont = TTFontManager::GetInstance()->getFont(name, size);
	return m_ttfFont != NULL;
}

void CText::SetColor( DWORD color)
{
	m_ttfFont->SetColor(color);
}

void CText::SetText( LPWSTR text)
{
	if (text)
	{
		int size = wcslen(text) + 1;
		m_text = new wchar_t[size];
		wcscpy(m_text, text);
	}
}