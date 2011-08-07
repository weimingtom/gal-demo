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
, m_curLine(-1)
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
	m_left = point.x + LEFT_SPACING;
	m_top = point.y;
	for (int i = 0; i < MAX_LINE_NUM; i++)
	{
		m_text[i].LoadFont(CfgMgr->GetSystenFont().c_str(), CfgMgr->GetFontSize());
		m_text[i].SetPos(m_left, m_top + (LINE_SPACING + m_textHeight) * i);
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
	
	if (m_curLine == -1)
	{
		return ;
	}

	//render the finished line
	for (int i = 0; i < m_curLine; i++)
	{
		m_text[i].Render();
	}

	HGE *hge = hgeCreate(HGE_VERSION);

	//then render the current line
	float textWidth = m_text[m_curLine].GetWidth();
	float totalWidth = m_backGround->GetWidth() - 2 * LEFT_SPACING;
	
	float len = textWidth * m_progress > 1 ? textWidth * m_progress : 1;
	
	hge->Gfx_SetClipping(m_left, m_top + (LINE_SPACING + m_textHeight) * m_curLine, 
		len, m_textHeight + 5);
	
	m_text[m_curLine].Render();
	hge->Gfx_SetClipping();
	hge->Release();
}

int CTextBox::Update( float dt )
{
	if (m_curLine == m_num)
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
	m_curLine = -1;
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

	float width = m_backGround->GetWidth() - 4 * LEFT_SPACING;
	
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

void CTextBox::SpeedUpLine()
{
	m_timer = m_delay;
}

void CTextBox::SpeedUpAll()
{
	m_curLine = m_num;
	m_progress = 1;
	m_timer = 0;
}