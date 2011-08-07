#pragma once
#include <vector>

enum _grammar_node_type_
{
	STATEMENT_NODE = 0,
	STATEMENT_LIST,
	PARAM_LIST,
	CALL_FUNC,
	IF_NODE,
	ELSE_NODE,
	ASSIGN_NODE,
	EQ_NODE,
	LT_NODE,
	GT_NODE,
	PLUS_NODE,
	MINUS_NODE,
	CONST_STR_NODE,
	CONST_INT_NODE,
	IDENTITY_NODE,
};

class CGrammarNode
{
public:
	static const int MAX_CHILD_NUM = 3;

	CGrammarNode(int type, int syntax);
	CGrammarNode(int type, CGrammarNode *child);
	CGrammarNode(int type, CGrammarNode* child1, CGrammarNode* child2);
	CGrammarNode(int type, CGrammarNode* child1, CGrammarNode* child2, CGrammarNode* child3);

	~CGrammarNode(void);
	CGrammarNode*	GetChild(int i){return m_childs[i];}
	int				GetType(){return m_type;}
	int				GetSyntaxIndex(){return m_syntaxIndex;}
	
	static void RegisterKeyWord(const char **, int);
	static void RegisterKeyWord(std::vector<const char*> words){keywords = words;}
private:
	bool		check();

	CGrammarNode*		m_childs[MAX_CHILD_NUM];
	int					m_type;
	int					m_syntaxIndex;
	static std::vector<const char *> keywords;
};
