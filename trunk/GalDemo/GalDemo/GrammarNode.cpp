#include "StdAfx.h"
#include "GrammarNode.h"
#include "parser.h"

std::vector<const char *> CGrammarNode::keywords;

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
	if (!check())
	{
		throw "Grammar Error!";
	}
}

CGrammarNode::CGrammarNode( int type, CGrammarNode* child1, CGrammarNode* child2, CGrammarNode* child3 )
:m_type(type)
{
	m_syntaxIndex = -1;
	memset(m_childs, NULL, sizeof(CGrammarNode *) * MAX_CHILD_NUM);
	m_childs[0] = child1;
	m_childs[1] = child2;
	m_childs[2] = child3;
	if (!check())
	{
		throw "Grammar Error!";
	}
}

CGrammarNode::CGrammarNode( int type, CGrammarNode *child ):m_type(type)
{
	m_syntaxIndex = -1;
	memset(m_childs, NULL, sizeof(CGrammarNode *) * MAX_CHILD_NUM);
	m_childs[0] = child;
	
	if (!check())
	{
		throw "Grammar Error!";
	}
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

void CGrammarNode::RegisterKeyWord(const char ** words, int size)
{
	for (int i = 0; i < size; i++)
	{
		keywords.push_back(words[i]);
	}
}

bool CGrammarNode::check()
{
	switch (this->m_type)
	{
	case CALL_FUNC:
		{
			char *name = syntaxTable.GetSyntax(m_childs[0]->GetSyntaxIndex()).name;
			for (int i = 0; i < keywords.size(); i++)
			{
				if (!strcmp(keywords[i], name))
				{
					return true;
				}
			}
			return false;
		}
	case ASSIGN_NODE:
		{
			char *name = syntaxTable.GetSyntax(m_childs[0]->GetSyntaxIndex()).name;
			for (int i = 0; i < keywords.size(); i++)
			{
				if (!strcmp(keywords[i], name))
				{
					return false;
				}
			}
		}
	default:break;
	}
	return true;
}