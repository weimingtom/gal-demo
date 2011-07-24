#pragma once
#include "state.h"
#include "hgegui.h"
#include "RenderableObject.h"
#include <assert.h>
#include <set>
#include <stack>

class CGame;
class CAction;

class CGameState :
	public CState<CGame>
{
	static const int MAX_GROUP_NUM = 3;
public:

	virtual bool Render() = 0;
	
	virtual bool IsFinished(){return true;}

	void DestoryGroupObject(int group)
	{
		assert(group < MAX_GROUP_NUM);
		std::set<CRenderableObject *>::iterator iter = m_renderGroup[group].begin();
		while(iter != m_renderGroup[group].end())
		{
			delete (*iter);
			iter++;
		}
	}

	void DestoryAllObject()
	{
		for (int i = 0; i < MAX_GROUP_NUM; i++)
		{
			DestoryGroupObject(i);
		}		
	}

	void RenderGroupObject(int group)
	{
		assert(group < MAX_GROUP_NUM);
		std::set<CRenderableObject *>::iterator iter = m_renderGroup[group].begin();
		while(iter != m_renderGroup[group].end())
		{
			(*iter)->Render();
			iter++;
		}
	}
	
	void RenderAllObject()
	{
		for(int i = 0; i < MAX_GROUP_NUM; i++)
		{
			RenderGroupObject(i);
		}
	}

	CRenderableObject* GetObject(int id)
	{
		std::set<CRenderableObject *>::iterator iter = NULL;
		for (int i = 0; i < MAX_GROUP_NUM; i++)
		{
			iter = m_renderGroup[i].begin();
			while(iter != m_renderGroup[i].end())
			{
				if ((*iter)->GetID() == id)
				{
					return (*iter);
				}
				iter++;
			}
		}

		return NULL;
	}

	CRenderableObject* RemoveObject(int id)
	{
		CRenderableObject *object = NULL;
		std::set<CRenderableObject *>::iterator iter = NULL;
		for (int i = 0; i < MAX_GROUP_NUM; i++)
		{
			iter = m_renderGroup[i].begin();
			while(iter != m_renderGroup[i].end())
			{
				if ((*iter)->GetID() == id)
				{
					object = (*iter);
					m_renderGroup[i].erase(iter);
					return object;
				}
				iter++;
			}
		}
		return NULL;
	}

protected:
	std::set<CRenderableObject *>	m_renderGroup[MAX_GROUP_NUM];
	std::stack<CAction *>			m_actionStack;
};
