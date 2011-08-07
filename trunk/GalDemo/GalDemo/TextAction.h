#pragma once
#include "action.h"

class CTextBox;


class CTextAction :
	public CAction
{
public:
	CTextAction(CTextBox *);
	virtual ~CTextAction(void);

	virtual int execute(CGameState *);

private:
	CTextBox *m_textbox;
};
