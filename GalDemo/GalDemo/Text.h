#pragma once
#include "renderableobject.h"
#include "utils.h"

class hgeTTFont;

class CText :
	public CRenderableObject
{
public:
	CText(int id = -1);
	virtual ~CText(void);
	
	bool IsLoaded(){return m_ttfFont != NULL;}
	bool LoadFont(LPCSTR, int);
	void SetColor(DWORD);
	void SetText(LPCWSTR);
	
	void SetPos(FPOINT pos){m_pos.x = pos.x; m_pos.y = pos.y;}
	void SetPos(float x, float y){m_pos.x = x; m_pos.y = y;}
	void SetAlian(int alian){m_alian = alian;}
	
	float GetHeight();
	float GetWidth();
	float TestWidth(LPCWSTR str);

	virtual void Render();
	virtual int Update(float dt){return 0;}

protected:
	hgeTTFont*		m_ttfFont;
	FPOINT			m_pos;
	LPWSTR			m_text;
	int				m_alian;
};
