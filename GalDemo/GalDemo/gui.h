#pragma once
#include "renderableobject.h"
#include "hgegui.h"

class CGUI :
	public CRenderableObject, public hgeGUI
{
public:
	CGUI(int id = -1);
	virtual ~CGUI(void);

	virtual void Render(){hgeGUI::Render();}
	virtual int Update(float dt){return hgeGUI::Update(dt);}
};
