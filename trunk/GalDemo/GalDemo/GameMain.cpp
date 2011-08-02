#include "stdafx.h"
#include "GameMain.h"
#include "TextBox.h"
#include "Quad.h"
#include "utils.h"

CGameMain::CGameMain(void)
{
	m_hge = hgeCreate(HGE_VERSION);
}

CGameMain::~CGameMain(void)
{
	m_hge->Release();
}

CGameMain* CGameMain::GetInstance()
{
	static CGameMain instance;
	return &instance;
}

void CGameMain::Enter( CGame * )
{
	CQuad * bg = new CQuad(ResMgr->GetTexture(RES_TEXTURE_TEXTBOX));
	bg->SetTopLeft(FPOINT(0, 280));
	CTextBox *textBox = new CTextBox(bg, 1.5, 100);
	
	m_renderGroup[1].insert(textBox);
}

bool CGameMain::Execute( CGame * )
{
	float dt = m_hge->Timer_GetDelta();
	CTextBox * textBox = reinterpret_cast<CTextBox *>(GetObject(100));	
	if (textBox)
	{
		textBox->Update(dt);
		if (m_hge->Input_GetKeyState(HGEK_LBUTTON))
		{
			textBox->SetText(L"ÎÔ²ÝÄàÂíÀÕ¸ô±Ú£¡ÎÒ²ÝÄàÂíÁË¸ô±ÚÑ½£¡ÎÔ²ÝÄàÂíÀÕ¸ô±Ú£¡ÎÒ²ÝÄàÂíÁË¸ô±ÚÑ½£¡ÎÔ²ÝÄàÂíÀÕ¸ô±Ú£¡ÎÒ²ÝÄàÂíÁË¸ô±ÚÑ½£¡ÎÔ²ÝÄàÂíÀÕ¸ô±Ú£¡ÎÒ²ÝÄàÂíÁË¸ô±ÚÑ½£¡");
		}
	}
	return false;
}

void CGameMain::Exit( CGame * )
{
	DestoryAllObject();
}

bool CGameMain::Render()
{
	m_hge->Gfx_BeginScene();
	m_hge->Gfx_Clear(0);
	RenderAllObject();
	m_hge->Gfx_EndScene();
	return false;
}