#pragma once
#include "hgegui.h"
#include "hgecolor.h"
#include "utils.h"

class CText;

class CShadowMenu :
	public hgeGUIObject
{
public:
	CShadowMenu(int _id, LPCWSTR text, FPOINT pos);
	virtual ~CShadowMenu(void);

	virtual void	Render();
	virtual void	Update(float dt);

	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);
	virtual void	MouseOver(bool bOver);

	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);

protected:
	hgeColor		m_shadowColor;
	hgeColor		m_mainColor;
	hgeColor		m_highlightColor;
	hgeColor		m_color;
	hgeColor		m_srcColor, m_dstColor;
	CText*			m_text;
	CText*			m_shadow;
	FPOINT			m_pos;
	float			m_offset;
	float			m_oldOffset, m_dstOffset, m_srcOffset;
	bool			m_dance;
	int				m_finished;
	float			m_timer;
};
