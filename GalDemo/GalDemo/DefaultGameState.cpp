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
	HTEXTURE tex = ResMgr->GetTexture(ID_TEXTURE_TEST);
	m_quad->SetTexture(tex);
	FPOINT vs[4] = {{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}};
	m_quad->SetVertex(vs);
	FPOINT pos[4] = {{0, 0}, {488, 0}, {488, 512}, {0, 512}};
	m_quad->SetPosition(pos);
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

BOOL CDefaultGameState::Render( CGame * )
{
	return TRUE;
}