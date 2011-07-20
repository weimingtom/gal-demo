#include "stdafx.h"
#include "DefaultGameState.h"
#include "GameDefaultAction.h"
#include "Action.h"
#include "Game.h"
#include "ResourceManager.h"
#include "IDdefines.h"
#include "utils.h"
#include "Quad.h"
#include "constdefines.h"

CDefaultGameState::CDefaultGameState(void)
{
	m_actionStack.push(CGameDefaultAction::GetInstance());

	m_quad = new CQuad;
	HTEXTURE tex = Game->GetHgeHandle()->Texture_Load("test.png");
	//HTEXTURE tex = ResMgr->GetTexture(ID_TEXTURE_TEST);
	m_quad->SetTexture(tex);
	FPOINT vs[4] = {{96.0/128.0, 64.0/128.0}, {128.0/128.0, 64.0/128.0},
	{128.0/128.0, 96.0/128.0}, {96.0/128.0, 96.0/128.0}};
	m_quad->SetVertex(vs);
	FPOINT pos[4] = {{0, 0}, {16, 0}, {16, 16}, {0, 16}};
	m_quad->SetPosition(pos);
	int col[4] = {0xFFFFA000, 0xFFFFA000, 0xFFFFA000, 0xFFFFA000};
	float z[4] = {0.5, 0.5, 0.5, 0.5};

	m_quad->SetZ(z);
	m_quad->SetColor(col);

}

CDefaultGameState::~CDefaultGameState(void)
{
	delete m_quad;
}

void CDefaultGameState::Enter( CGame * game )
{
	
}

BOOL CDefaultGameState::Execute( CGame * game )
{
	return m_actionStack.top()->execute(game);
}

void CDefaultGameState::Exit( CGame * game )
{
	
}

CDefaultGameState* CDefaultGameState::GetInstance()
{
	static CDefaultGameState instance;
	return &instance;
}

BOOL CDefaultGameState::Render( CGame * game )
{
	m_quad->Render(game);
	return TRUE;
}