#include "StdAfx.h"
#include "GrammarNode.h"
#include "parser.h"

CGrammarNode::CGrammarNode( int type, int syntax ):m_type(type), m_syntaxIndex(syntax)
{
	memset(m_childs, NULL, sizeof(CGrammarNode *) * MAX_CHILD_NUM);
}

CGrammarNode::CGrammarNode( int type, CGrammarNode* child1, CGrammarNode* child2 ):m_type(type)
{
	m_syntaxIndex = -1;
	memset(m_childs, NULL, sizeof(CGrammarNode *) * MAX_CHILD_NUM);
	m_childs[0] = child1;
	m_childs[1] = child2;
}

CGrammarNode::CGrammarNode( int type, CGrammarNode* child1, CGrammarNode* child2, CGrammarNode* child3 )
:m_type(type)
{
	m_syntaxIndex = -1;
	memset(m_childs, NULL, sizeof(CGrammarNode *) * MAX_CHILD_NUM);
	m_childs[0] = child1;
	m_childs[1] = child2;
	m_childs[2] = child3;
}

CGrammarNode::CGrammarNode( int type, CGrammarNode *child ):m_type(type)
{
	m_syntaxIndex = -1;
	memset(m_childs, NULL, sizeof(CGrammarNode *) * MAX_CHILD_NUM);
	m_childs[0] = child;
}
CGrammarNode::~CGrammarNode(void)
{
	for (int i = 0; i < MAX_CHILD_NUM; i++)
	{
		if (m_childs[i])
		{
			delete m_childs[i];
			m_childs[i] = NULL;
		}
	}
}
