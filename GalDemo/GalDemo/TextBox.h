#pragma once
#include "RenderableObject.h"

class CText;
class CQuad;

class CTextBox :
	public CRenderableObject
{
	static const int MAX_LINE_NUM = 3;
	static const int LINE_SPACING = 5;
	static const int LEFT_SPACING = 15;
public:
	CTextBox(CQuad *quad, float delay, int id);
	virtual ~CTextBox(void);
	
	virtual void Render();
	virtual int Update(float dt);

	void SetText(const wchar_t *text);
	void ClearText();
	
	void SpeedUpLine();
	void SpeedUpAll();

protected:
	bool		m_isShow;
	CQuad		*m_backGround;
	CText		*m_text;
	float		m_delay;
	float		m_timer;
	float		m_progress;
	int			m_curLine;
	float		m_textHeight;
	float       m_textWidth;
	float       m_left;
	float       m_top;
	int			m_num;
};
