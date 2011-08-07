#include "StdAfx.h"
#include "Interpreter.h"
#include <iostream>
#include <algorithm>

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

int CInterpreter::GenCommand( CGrammarNode *node, std::vector<COMMAND>& cmdList)
{
	
	switch(node->GetType())
	{
	case PARAM_LIST:
		{
			GenCommand(node->GetChild(0), cmdList);
			if (node->GetChild(1))
			{
				GenCommand(node->GetChild(1), cmdList);
			}
			break;
		}
	case CALL_FUNC:
		{
			int argNum = 0;
			CGrammarNode *temp = node->GetChild(1);
			while(temp->GetChild(0))
			{
				argNum++;
				temp = temp->GetChild(0);
			}
			
			SYNTAX_NODE &syntax = m_syntaxTable->GetSyntax(node->GetChild(0)->GetSyntaxIndex());
			SYNTAX_VALUE value;
			value.type = SYNTAX_STR;
			value.Vun.strVal = new char[strlen(syntax.name) + 1];
			memcpy(value.Vun.strVal, syntax.name, strlen(syntax.name) + 1);
			syntax.value = value;

			GenCommand(node->GetChild(1), cmdList);
			GenCommand(node->GetChild(0), cmdList);
			COMMAND cmd = {CMD_CALL, argNum};
			cmdList.push_back(cmd);
			break;
		}
	case STATEMENT_LIST:
		{
			GenCommand(node->GetChild(0), cmdList);
			if (node->GetChild(1))
			{
				GenCommand(node->GetChild(1), cmdList);
			}
			break;
		}
	case IF_NODE:
		{
			std::vector<COMMAND> ifList;
			
			int endCond = GenCommand(node->GetChild(0), cmdList);
			int endif = GenCommand(node->GetChild(1), ifList);
			
			if (!node->GetChild(2))
			{
				COMMAND cmd;
				cmd.op = CMD_JZ;
				cmd.arg = endCond + endif;
				cmdList.push_back(cmd);
				FixJump(ifList, endCond + 1);
				std::copy(ifList.begin(), ifList.end(), back_inserter(cmdList));
			}
			else
			{
				std::vector<COMMAND> elseList;
				int endelse = GenCommand(node->GetChild(2), elseList);
				
				COMMAND cmd;
				cmd.op = CMD_JZ;
				cmd.arg = endCond + endif + 1;
				cmdList.push_back(cmd);
				std::copy(ifList.begin(), ifList.end(), back_inserter(cmdList));
				
				COMMAND cmd2;
				cmd2.op = CMD_JMP;
				cmd2.arg = endCond + endif + endelse + 1;
				cmdList.push_back(cmd2);
				
				FixJump(elseList, endCond + endif + 2);
				std::copy(elseList.begin(), elseList.end(), back_inserter(cmdList));
			}
			
			break;
		}
	case ELSE_NODE:
		{
			GenCommand(node->GetChild(0), cmdList);
			break;
		}
	case ASSIGN_NODE:
		{
			GenCommand(node->GetChild(1), cmdList);
			COMMAND cmd = {CMD_ASN, node->GetChild(0)->GetSyntaxIndex()};
			cmdList.push_back(cmd);
			break;
		}
	case EQ_NODE:
		{
			GenCommand(node->GetChild(0), cmdList);
			GenCommand(node->GetChild(1), cmdList);
			COMMAND cmd = {CMD_EQ, -1};
			cmdList.push_back(cmd);
			break;
		}
	case LT_NODE:
		{
			GenCommand(node->GetChild(0), cmdList);
			GenCommand(node->GetChild(1), cmdList);
			COMMAND cmd = {CMD_LT, -1};
			cmdList.push_back(cmd);
			break;
		}
	case GT_NODE:
		{
			GenCommand(node->GetChild(0), cmdList);
			GenCommand(node->GetChild(1), cmdList);
			COMMAND cmd = {CMD_GT, -1};
			cmdList.push_back(cmd);
			break;
		}
	case MINUS_NODE:
		{
			GenCommand(node->GetChild(0), cmdList);
			GenCommand(node->GetChild(1), cmdList);
			COMMAND cmd = {CMD_MINUS, -1};
			cmdList.push_back(cmd);
			break;
		}
	case PLUS_NODE:
		{
			GenCommand(node->GetChild(0), cmdList);
			GenCommand(node->GetChild(1), cmdList);
			COMMAND cmd = {CMD_PLUS, -1};
			cmdList.push_back(cmd);
			break;
		}
	case CONST_STR_NODE:
	case CONST_INT_NODE:
	case IDENTITY_NODE:
		{
			COMMAND cmd = {CMD_PUSH, node->GetSyntaxIndex()};
			cmdList.push_back(cmd);
			break;
		}
	default:break;
	}
	return cmdList.size();
}

void CInterpreter::FixJump( std::vector<COMMAND>& list, int start)
{
	for (std::vector<COMMAND>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->op == CMD_JZ || iter->op == CMD_JMP)
		{
			iter->arg = start + iter->arg;
		}
	}
}

std::vector<COMMAND> CInterpreter::GenCmdList()
{
	for (std::list<CGrammarNode *>::iterator iter = m_grammarList.begin(); iter != m_grammarList.end(); iter++)
	{
		GenCommand((*iter), m_cmdList);
	}
	return m_cmdList;
}