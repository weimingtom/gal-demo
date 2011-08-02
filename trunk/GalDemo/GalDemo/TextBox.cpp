#include "stdafx.h"
#include "TextBox.h"
#include "Quad.h"
#include "Text.h"

CTextBox::CTextBox(CQuad *quad, float delay, int id)
: CRenderableObject(id)
, m_delay(delay)
, m_isShow(TRUE)
, m_backGround(quad)
, m_timer(0)
, m_progress(0)
, m_curLine(0)
, m_num(0)
{
	CText t;
	t.LoadFont(CfgMgr->GetSystenFont().c_str(), CfgMgr->GetFontSize());
	if (t.IsLoaded())
	{
		t.SetText(L"²â");
		m_textHeight = t.GetHeight();
		m_textWidth = t.GetWidth();
	}
	else
	{
		assert(FALSE);
	};

	m_text = new CText[MAX_LINE_NUM];
	FPOINT point = quad->GetTopLeft();
	m_left = point.x + 15;
	m_top = point.y;
	for (int i = 0; i < MAX_LINE_NUM; i++)
	{
		m_text[i].LoadFont(CfgMgr->GetSystenFont().c_str(), CfgMgr->GetFontSize());
		m_text[i].SetPos(m_left, m_top + (5 + m_textHeight) * i);
		m_text[i].SetText(L"");
		if (!m_text[i].IsLoaded())
		{
			assert(FALSE);
		}
	}
}

CTextBox::~CTextBox(void)
{
	delete[] m_text;
	delete m_backGround;
}

void CTextBox::Render()
{
	m_backGround->Render();
	for (int i = 0; i < m_curLine; i++)
	{
		m_text[i].Render();
	}
	HGE *hge = hgeCreate(HGE_VERSION);
	
	float totalWidth = m_text[m_curLine].GetWidth();
	hge->Gfx_SetClipping(m_left, m_top + (5 + m_textHeight) * m_curLine, totalWidth * m_progress, m_textHeight + 5);
	m_text[m_curLine].Render();
	hge->Gfx_SetClipping();
	hge->Release();
}

int CTextBox::Update( float dt )
{
	if (m_curLine == m_num - 1)
	{
		return m_ID;
	}

	m_timer += dt;
	if (m_timer > m_delay)
	{
		m_progress = 1;
		m_timer = 0;
		m_curLine++;
	}
	else
	{
		m_progress = (m_timer / m_delay);
	}
	
	return 0;
}

void CTextBox::ClearText()
{
	m_curLine = 0;
	m_num = 0;
	for (int i = 0; i < MAX_LINE_NUM; i++)
	{
		m_text[i].SetText(L"");
	}
}

void CTextBox::SetText(const wchar_t *text )
{
	m_progress = 0;	
	m_timer = 0;
	m_curLine = 0;
	m_num = 0;

	FPOINT p[4];
	m_backGround->GetPosition(p);
	float width = p[1].x - p[0].x - 30;
	
	int len = wcslen(text);
	int num = width / m_textWidth;

	wchar_t *buff = new wchar_t[num + 1];
	
	for(int i = 0; i < MAX_LINE_NUM; i++)
	{
		ZeroMemory(buff, sizeof(wchar_t) * (num + 1));
		
		if (num < len)
		{
			memcpy_s(buff, sizeof(wchar_t) * num, text + num * i, num * sizeof(wchar_t));
		}
		else
		{
			memcpy_s(buff, sizeof(wchar_t) * num, text + num * i, len * sizeof(wchar_t));
		}
		len -= num;
		m_num++;
		m_text[i].SetText(buff);
		m_text[i].SetColor(0xff000000);
		if (len <= 0)
		{
			break;
		}
	}
	
	delete[] buff;
}
