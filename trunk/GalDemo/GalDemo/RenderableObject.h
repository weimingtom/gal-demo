#pragma once

class CRenderableObject
{
public:
	CRenderableObject(int id = -1):m_ID(id){}
	virtual ~CRenderableObject(void){};
	
	int		GetID(){return m_ID;}

	virtual void Render() = 0;
	virtual int Update(float dt) = 0;

	bool operator ==(CRenderableObject object){return this->m_ID == object.m_ID;}
	bool operator ==(int id){return this->m_ID == id;}

protected:
	int		m_ID;
};
