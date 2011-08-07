#include "stdafx.h"
#include "TextAction.h"
#include "TextBox.h"

CTextAction::CTextAction(CTextBox *textbox)
: m_textbox(textbox)
{
}

CTextAction::~CTextAction(void)
{
}

int CTextAction::execute( CGameState * )
{
	HGE *hge = hgeCreate(HGE_VERSION);
	float dt = hge->Timer_GetDelta();
	int ret = m_textbox->Update(dt);
	//DebugMsg("textbox ret: %d\n", ret);
	bool lbtndown = hge->Input_KeyDown(HGEK_LBUTTON);

	if (ret > 0)
	{
		if (lbtndown)
		{
			return m_textbox->GetID();
		}
	}
	else
	{
		if (lbtndown)
		{
			//m_textbox->SpeedUpLine();
			m_textbox->SpeedUpAll();
		}
	}
	hge->Release();
	return 0;
}