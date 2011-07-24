#pragma once
#include "renderableobject.h"
#include "hge.h"
#include "utils.h"

class CGame;

class CQuad :
	public CRenderableObject
{
public:
	CQuad(hgeQuad quad, int id = -1);
	CQuad(HTEXTURE tex, int id = -1);
	virtual ~CQuad(void);
	
	void SetBlendMode(int blend){m_quad.blend = blend;}
	int GetBlendMode(){return m_quad.blend;}
	
	void SetVertex(FPOINT pos[4]);
	void GetVertex(FPOINT pos[4]);

	void SetPosition(FPOINT pos[4]);
	void GetPosition(FPOINT pos[4]);

	void SetColor(int color[4]);
	void GetColor(int color[4]);
	
	void SetZ(float z[4]);
	void GetZ(float z[4]);

	void SetTexture(HTEXTURE tex){m_quad.tex = tex;}
	HTEXTURE GetTexture(){return m_quad.tex;}

	virtual void Render();
	virtual int  Update(float dt){return 0;}
protected:
	hgeQuad		m_quad;
};
