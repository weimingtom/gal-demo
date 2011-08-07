#include "stdafx.h"
#include "Game.h"

int WINAPI WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{

#ifdef _DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
#endif // _DEBUG
	
	CGame *game = CGame::GetInstance();
	
	if (!game->Initialize())
	{
		MessageBox(NULL, "³õÊ¼»¯Ê§°Ü!", "´íÎó", MB_OK | MB_ICONWARNING);
		return 1;
	}
	game->Start();
	game->Finalize();
	return 0;
}