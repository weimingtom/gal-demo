#pragma once
#include "renderableobject.h"
#include "utils.h"

class hgeTTFont;

class CText :
	public CRenderableObject
{
public:
	CText();
	virtual ~CText(void);
	
	bool IsLoaded(){return m_ttfFont != NULL;}
	bool LoadFont(LPCSTR, int);
	void SetColor(DWORD);
	void SetText(LPWSTR);
	
	void SetPos(FPOINT pos){m_pos.x = pos.x; m_pos.y = pos.y;}
	void SetAlian(int alian){m_alian = alian;}
	virtual void Render();

protected:
	hgeTTFont*		m_ttfFont;
	FPOINT			m_pos;
	LPWSTR			m_text;
	int				m_alian;
};
