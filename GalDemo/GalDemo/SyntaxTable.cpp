#include "StdAfx.h"
#include "SyntaxTable.h"
#include <assert.h>

CSyntaxTable::CSyntaxTable(void)
{
}

CSyntaxTable::~CSyntaxTable(void)
{
	m_syntaxArray.clear();
}

unsigned int CSyntaxTable::FindSyntax( const char *name )
{
	for (int i = 0; i < m_syntaxArray.size(); i++)
	{
		if (!_tcscmp(m_syntaxArray[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void CSyntaxTable::SetValue( unsigned int index, SYNTAX_VALUE value )
{
	assert(index < m_syntaxArray.size());
	m_syntaxArray[index].value = value;
}

unsigned int CSyntaxTable::AddSyntax( SYNTAX_NODE syntax )
{
	m_syntaxArray.push_back(syntax);
	return m_syntaxArray.size() - 1;
}

unsigned int CSyntaxTable::AddSyntax( char *name, SYNTAX_VALUE value )
{
	SYNTAX_NODE node;
	node.name = name;
	node.value = value;
	m_syntaxArray.push_back(node);
	return m_syntaxArray.size() - 1;
}

char* CSyntaxTable::ConstructName()
{
	char *name = new char[MAX_SYNTAX_NAME_LEN];
	sprintf_s(name, MAX_SYNTAX_NAME_LEN, _T("const %d"), m_syntaxArray.size());
	return name;
}

SYNTAX_NODE & CSyntaxTable::GetSyntax( int index )
{
	return m_syntaxArray[index];
}

bool operator <(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2)
{
	bool ret;
	if (value1.type == SYNTAX_STR && value2.type == SYNTAX_STR)
	{
		ret = strcmp(value1.Vun.strVal, value2.Vun.strVal) < 0;	
	}
	else if (value1.type == SYNTAX_STR)
	{
		ret = 1;
	}
	else if (value2.type == SYNTAX_STR)
	{
		ret = 0;
	}
	else
	{
		ret = value1.Vun.intVal < value2.Vun.intVal;
	}
	return ret;
}
bool operator >(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2)
{
	bool ret;
	if (value1.type == SYNTAX_STR && value2.type == SYNTAX_STR)
	{
		ret = strcmp(value1.Vun.strVal, value2.Vun.strVal) > 0;	
	}
	else if (value1.type == SYNTAX_STR)
	{
		ret = 0;
	}
	else if (value2.type == SYNTAX_STR)
	{
		ret = 1;
	}
	else
	{
		ret = value1.Vun.intVal > value2.Vun.intVal;
	}
	return ret;
}
bool operator ==(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2)
{
	bool ret;
	if (value1.type == SYNTAX_STR && value2.type == SYNTAX_STR)
	{
		ret = strcmp(value1.Vun.strVal, value2.Vun.strVal) == 0;	
	}
	else if (value1.type == SYNTAX_STR)
	{
		ret = 0;
	}
	else if (value2.type == SYNTAX_STR)
	{
		ret = 0;
	}
	else
	{
		ret = value1.Vun.intVal == value2.Vun.intVal;
	}
	return ret;
}
SYNTAX_VALUE operator +(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2)
{
	SYNTAX_VALUE ret;
	ret.type = SYNTAX_INT;
	if (value1.type == SYNTAX_STR && value2.type == SYNTAX_STR)
	{
		ret.type = SYNTAX_STR;
		char *str = new char[strlen(value1.Vun.strVal) + strlen(value2.Vun.strVal) + 1];
		memset(str, 0x0, strlen(value1.Vun.strVal) + strlen(value2.Vun.strVal) + 1);
		memcpy(str, value1.Vun.strVal, strlen(value1.Vun.strVal));
		memcpy(str + strlen(value1.Vun.strVal), value2.Vun.strVal, strlen(value2.Vun.strVal));
		ret.Vun.strVal = str;
	}
	else if (value1.type == SYNTAX_STR)
	{
		ret.Vun.intVal = value2.Vun.intVal;
	}
	else if (value2.type == SYNTAX_STR)
	{
		ret.Vun.intVal = value1.Vun.intVal;
	}
	else
	{
		ret.Vun.intVal = value1.Vun.intVal + value2.Vun.intVal;
	}
	return ret;	
}

SYNTAX_VALUE operator -(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2)
{
	SYNTAX_VALUE ret;
	ret.type = SYNTAX_INT;
	if (value1.type == SYNTAX_STR && value2.type == SYNTAX_STR)
	{
		ret.Vun.intVal = 0;
	}
	else if (value1.type == SYNTAX_STR)
	{
		ret.Vun.intVal = 0 - value2.Vun.intVal;
	}
	else if (value2.type == SYNTAX_STR)
	{
		ret.Vun.intVal = value1.Vun.intVal;
	}
	else
	{
		ret.Vun.intVal = value1.Vun.intVal - value2.Vun.intVal;
	}
	return ret;	
}

SYNTAX_VALUE& SYNTAX_VALUE::operator=( const SYNTAX_VALUE& value )
{
	if (this == &value)
	{
		return *this;
	}

	if (this->type == SYNTAX_STR)
	{
		delete[] this->Vun.strVal;
	}

	if (value.type == SYNTAX_STR)
	{
		this->type = SYNTAX_STR;
		this->Vun.strVal = new char[strlen(value.Vun.strVal) + 1];
		memcpy(this->Vun.strVal, value.Vun.strVal, strlen(value.Vun.strVal) + 1);
	}
	else
	{
		this->type = SYNTAX_INT;
		this->Vun.intVal = value.Vun.intVal;
	}

	return *this;
}

SYNTAX_VALUE::~SYNTAX_VALUE()
{
	if (this->type == SYNTAX_STR)
	{
		delete[] this->Vun.strVal;
	}
}

SYNTAX_VALUE::SYNTAX_VALUE( const SYNTAX_VALUE& value )
{
	this->type = SYNTAX_INT;
	this->Vun.intVal = 0;

	if (value.type == SYNTAX_STR)
	{
		this->type = SYNTAX_STR;
		this->Vun.strVal = new char[strlen(value.Vun.strVal) + 1];
		memcpy(this->Vun.strVal, value.Vun.strVal, strlen(value.Vun.strVal) + 1);
	}
	else
	{
		this->type = SYNTAX_INT;
		this->Vun.intVal = value.Vun.intVal;
	}
}

SYNTAX_VALUE::SYNTAX_VALUE()
{
	this->type = SYNTAX_INT;
	this->Vun.intVal = 0;
}