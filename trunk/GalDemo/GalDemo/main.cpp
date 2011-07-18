#include "stdafx.h"
#include "hge.h"
#include "Game.h"


int WINAPI WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{
	CGame *game = CGame::GetInstance();
	game->Initialize();
	game->Start();
	game->Finalize();
	return 0;
}