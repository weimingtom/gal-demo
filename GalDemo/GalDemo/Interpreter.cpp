#include "StdAfx.h"
#include "Interpreter.h"
#include <iostream>

CInterpreter::CInterpreter(void)
{
}

CInterpreter::~CInterpreter(void)
{
}

void CInterpreter::Finalize()
{
	for (std::list<CGrammarNode *>::iterator iter = m_grammarList.begin(); iter != m_grammarList.end();
		iter++)
	{
		delete (*iter);
	}
}

int CInterpreter::Step()
{
	ParseNode((*m_cur));
	m_cur++;
	if (m_cur != m_grammarList.end())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CInterpreter::Initialize( std::list<CGrammarNode *> list, CSyntaxTable* table)
{
	assert(list.size());
	assert(table);
	m_grammarList = list;
	m_syntaxTable = table;
	m_cur = m_grammarList.begin();
}

const SYNTAX_VALUE CInterpreter::ParseNode( CGrammarNode * node )
{
	//默认返回值是 int 0
	SYNTAX_VALUE ret;
	
	switch(node->GetType())
	{
	case PARAM_LIST:
		{
			ret = ParseNode(node->GetChild(0));
			m_funcParams.push_back(ret);

			if (node->GetChild(1))
			{
				ParseNode(node->GetChild(1));
			}
			
			break;
		}
	case CALL_FUNC:
		{
			SYNTAX_NODE funcNode = m_syntaxTable->GetSyntax(node->GetChild(0)->GetSyntaxIndex());
			if (node->GetChild(1))
			{
				ParseNode(node->GetChild(1));
			}
		
			if (!strcmp(funcNode.name, "print"))
			{
				for(int i = 0; i < m_funcParams.size(); i++)
				{
					if (m_funcParams[i].type == SYNTAX_STR)
					{
						std::cout << m_funcParams[i].Vun.strVal << " ";
					}
					else if (m_funcParams[i].type == SYNTAX_INT)
					{
						std::cout << m_funcParams[i].Vun.intVal << " "; 
					}
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "calling func:" << funcNode.name << std::endl;
			}
			m_funcParams.clear();
			break;
		}
	case STATEMENT_LIST:
		{
			if (node->GetChild(0))
			{
				ParseNode(node->GetChild(0));
			}
			if (node->GetChild(1))
			{
				ParseNode(node->GetChild(1));
			}
			break;
		}
	case IF_NODE:
		{
			SYNTAX_VALUE value = ParseNode(node->GetChild(0));
			
			if (value.Vun.intVal)
			{
				ParseNode(node->GetChild(1));		
			}
			else if(node->GetChild(2))
			{
				ParseNode(node->GetChild(2));
			}
			break;
		}
	case ELSE_NODE:
		{
			ParseNode(node->GetChild(0));
			break;
		}
	//case PRINT_NODE:
	//	{
	//		SYNTAX_VALUE value = ParseNode(node->GetChild(0));
	//		if (value.type == SYNTAX_STR)
	//		{
	//			std::cout << value.Vun.strVal << std::endl;
	//		}
	//		else
	//		{
	//			std::cout << value.Vun.intVal << std::endl;
	//		}
	//		break;
	//	}
	case ASSIGN_NODE:
		{
			SYNTAX_NODE& syntax = m_syntaxTable->GetSyntax(node->GetChild(0)->GetSyntaxIndex());
			SYNTAX_VALUE value = ParseNode(node->GetChild(1));
			syntax.value = value;
			ret = value;
			break;
		}
	case EQ_NODE:
		{
			SYNTAX_VALUE value1 = ParseNode(node->GetChild(0));
			SYNTAX_VALUE value2 = ParseNode(node->GetChild(1));

			ret.Vun.intVal = value1 == value2;
			break;
		}
	case LT_NODE:
		{
			SYNTAX_VALUE value1 = ParseNode(node->GetChild(0));
			SYNTAX_VALUE value2 = ParseNode(node->GetChild(1));

			ret.Vun.intVal = value1 < value2;
			break;
		}
	case GT_NODE:
		{
			SYNTAX_VALUE value1 = ParseNode(node->GetChild(0));
			SYNTAX_VALUE value2 = ParseNode(node->GetChild(1));
			
			ret.Vun.intVal = value1 > value2;
			break;
		}
	case MINUS_NODE://字符串当作是0
		{
			SYNTAX_VALUE value1 = ParseNode(node->GetChild(0));
			SYNTAX_VALUE value2 = ParseNode(node->GetChild(1));

			ret = value1 - value2;
			break;
		}
	case PLUS_NODE://如果string和int相加string的值当作是0
		{
			SYNTAX_VALUE value1 = ParseNode(node->GetChild(0));
			SYNTAX_VALUE value2 = ParseNode(node->GetChild(1));
			
			ret = value1 + value2;
			break;
		}
	case CONST_STR_NODE:
	case CONST_INT_NODE:
	case IDENTITY_NODE:
		{
			ret = m_syntaxTable->GetSyntax(node->GetSyntaxIndex()).value;
			break;
		}
	default:break;
	}	
	
	return ret;
}