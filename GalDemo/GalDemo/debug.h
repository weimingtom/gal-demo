#pragma once

#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include<stdlib.h>
	#include<crtdbg.h>

	#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
	#define new DEBUG_NEW
#endif // _DEBUG

#ifdef _DEBUG
	inline void DebugMsg(char *szFormat, ...)
	{
		char szInfo[512];
		va_list ArgumentList;

		va_start(ArgumentList, szFormat); 
		vsprintf(szInfo, szFormat, ArgumentList);
		va_end(ArgumentList);
		OutputDebugString(szInfo);
	}
#endif // _DEBUG
