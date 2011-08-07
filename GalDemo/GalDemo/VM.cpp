#include "StdAfx.h"
#include "VM.h"

CVM::CVM()
: m_callback(NULL)
{

}

CVM::~CVM(void)
{
}

void CVM::execute()
{
	while(true)
	{
		if (m_cur >= m_cmdList.size())
		{
			return ;
		}
		if (ExecCmd(m_cmdList[m_cur]))
		{
			m_cur++;
			break;
		}
		m_cur++;
	}
}

void CVM::execute( int v)
{
	SYNTAX_VALUE value;
	value.type = SYNTAX_INT;
	value.Vun.intVal = v;
	m_stack.push(value);
	execute();
}

void CVM::execute( char * str)
{
	SYNTAX_VALUE value;
	value.type = SYNTAX_STR;
	value.Vun.strVal = new char[strlen(str) + 1];
	memcpy(value.Vun.strVal, str, strlen(str) + 1);
	m_stack.push(value);
	execute();
}
int CVM::ExecCmd( COMMAND cmd)
{
	switch(cmd.op)
	{
	case CMD_PUSH:
		{
			m_stack.push(m_syntaxTable->GetSyntax(cmd.arg).value);
			break;
		}
	case CMD_LT:
		{
			SYNTAX_VALUE value2 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value1 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value3;
			value3.Vun.intVal = value1 < value2;
			m_stack.push(value3);
			break;
		}
	case CMD_EQ:
		{
			SYNTAX_VALUE value2 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value1 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value3;
			value3.Vun.intVal = value1 == value2;
			m_stack.push(value3);
			break;
		}
	case CMD_GT:
		{
			SYNTAX_VALUE value2 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value1 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value3;
			value3.Vun.intVal = value1 > value2;
			m_stack.push(value3);
			break;
		}
	case CMD_PLUS:
		{
			SYNTAX_VALUE value2 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value1 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value3;
			value3 = value1 + value2;
			m_stack.push(value3);
			break;
		}
	case CMD_MINUS:
		{
			SYNTAX_VALUE value2 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value1 = m_stack.top();
			m_stack.pop();
			SYNTAX_VALUE value3;
			value3 = value1 - value2;
			m_stack.push(value3);
			break;
			break;
		}
	case CMD_ASN:
		{
			SYNTAX_VALUE value = m_stack.top();
			m_stack.pop();
			SYNTAX_NODE& node = m_syntaxTable->GetSyntax(cmd.arg);
			node.value = value;
			m_stack.push(value);
			break;
		}
	case CMD_JZ:
		{
			SYNTAX_VALUE value = m_stack.top();
			m_stack.pop();
			int test = 0;
			if (value.type == SYNTAX_INT)
			{
				test = value.Vun.intVal;
			}
			if (!test)
			{
				m_cur = cmd.arg;
			}
			
			break;
		}
	case CMD_JMP:
		{
			m_cur = cmd.arg;
			break;
		}
	case CMD_CALL:
		{
			SYNTAX_VALUE value = m_stack.top();
			m_stack.pop();
			std::vector<SYNTAX_VALUE> params;
			for (int i = 0; i < cmd.arg; i++)
			{
				params.push_back(m_stack.top());
				m_stack.pop();
			}
			return m_callback(value.Vun.strVal, params, m_user);
		}
	default:break;
	}
	return 0;
}

void CVM::SetFuncCallBack( FUNC_CALLBACK func, void *user )
{
	m_callback = func;
	m_user = user;
}

void CVM::SetCommondList( std::vector<COMMAND> list, CSyntaxTable *table )
{
	m_cmdList = list;
	m_syntaxTable = table;
	m_cur = 0;
}