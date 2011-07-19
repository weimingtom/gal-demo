#include "stdafx.h"
#include "DefaultGameState.h"
#include "GameDefaultAction.h"
#include "Action.h"
#include "Game.h"

CDefaultGameState::CDefaultGameState(void)
{
	m_actionStack.push(CGameDefaultAction::GetInstance());
}

CDefaultGameState::~CDefaultGameState(void)
{

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
