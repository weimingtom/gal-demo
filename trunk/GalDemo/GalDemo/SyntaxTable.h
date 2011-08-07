#pragma once
#include <vector>

#define MAX_SYNTAX_NAME_LEN 256

typedef enum _syntax_type_ 
{
	SYNTAX_INT,
	SYNTAX_STR,
}SYNTAX_TYPE;

class SYNTAX_VALUE
{
public:
	SYNTAX_VALUE();
	~SYNTAX_VALUE();
	SYNTAX_VALUE(const SYNTAX_VALUE& value);
	SYNTAX_VALUE& operator =(const SYNTAX_VALUE& value);
	
	int		type;
	union
	{
		int		intVal;
		char*	strVal;
	}Vun;
};

bool operator <(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2);
bool operator >(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2);
bool operator ==(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2);
SYNTAX_VALUE operator +(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2);
SYNTAX_VALUE operator -(const SYNTAX_VALUE& value1, const SYNTAX_VALUE& value2);

typedef struct _syntax_node_
{
	char* name;
	SYNTAX_VALUE	value;
}SYNTAX_NODE;

class CSyntaxTable
{
public:
	CSyntaxTable(void);
	~CSyntaxTable(void);

	unsigned int FindSyntax(const char *name);
	unsigned int AddSyntax(SYNTAX_NODE syntax);
	unsigned int AddSyntax(char *name, SYNTAX_VALUE value);
	void SetValue(unsigned int index, SYNTAX_VALUE value);
	SYNTAX_NODE &GetSyntax(int index);
	unsigned int	GetCount(){return m_syntaxArray.size();}
	char* ConstructName();
	void Destroy();
private:
	std::vector<SYNTAX_NODE>		m_syntaxArray;
};
