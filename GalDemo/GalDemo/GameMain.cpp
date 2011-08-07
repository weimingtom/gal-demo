#include "stdafx.h"
#include "GameMain.h"
#include "TextBox.h"
#include "Quad.h"
#include "utils.h"
#include "Interpreter.h"
#include "VM.h"
#include "lex.h"
#include "parser.h"
#include "TextAction.h"


CGameMain::CGameMain(void)
: m_keeySyntax(false)
{
	m_hge = hgeCreate(HGE_VERSION);
	m_interpreter = new CInterpreter;
	m_vm = new CVM;

	m_funcMap["print"] = &CGameMain::Func_Print;
}

CGameMain::~CGameMain(void)
{
	m_hge->Release();
	delete m_interpreter;
	delete m_vm;
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
	m_textbox = new CTextBox(bg, 2, ID_MAIN_TEXTBOX);
	
	m_renderGroup[1].insert(m_textbox);
	m_actionStack.push(new CTextAction(m_textbox));
	
	std::vector<const char *> words;
	for (FUNC_MAP::iterator iter = m_funcMap.begin(); iter != m_funcMap.end(); iter++)
	{
		words.push_back(iter->first);
	}
	CGrammarNode::RegisterKeyWord(words);
	
	m_vm->SetFuncCallBack(&CGameMain::FuncCallBack, this);

	SetScript("script\\start.gscr");
	m_vm->execute();
}

bool CGameMain::Execute( CGame * )
{
	int ret = m_actionStack.top()->execute(this);
	
	switch (ret)
	{
	case ID_MAIN_TEXTBOX:
		{
			m_vm->execute();
			break;
		}
	default:break;
	}
	return false;
}

void CGameMain::Exit( CGame * )
{
	while (m_actionStack.size())
	{
		delete m_actionStack.top();
		m_actionStack.pop();
	}
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

int CGameMain::FuncCallBack( const char* name, std::vector<SYNTAX_VALUE>& params, void* user)
{
	CGameMain *pThis = reinterpret_cast<CGameMain*>(user);
	for (FUNC_MAP::iterator iter = pThis->m_funcMap.begin(); iter != pThis->m_funcMap.end(); iter++)
	{
		if (!strcmp(iter->first, name))
		{
			return (pThis->*iter->second)(params);
		}
	}
	return 0;
}

void CGameMain::SetScript( char * filename )
{
	m_scriptFileName = filename;

	if (!m_keeySyntax)
	{
		syntaxTable.Destroy();
	}

	yyin = fopen(m_scriptFileName.c_str(), "r");
	try
	{
		yyparse();
	}
	catch(char *msg)
	{
		char errMsg[256];
		sprintf_s(errMsg, 256 * sizeof(char), "Script Error:%s at line: %d", msg, lineno);
		::MessageBox(NULL, errMsg, "Error", MB_OK | MB_ICONWARNING);
		fclose(yyin);
		PostQuitMessage(0);
	}
	catch(...)
	{
		::MessageBox(NULL, "Unknown Error!", "Error", MB_OK | MB_ICONWARNING);
		fclose(yyin);
		PostQuitMessage(0);
	}
	
	m_interpreter->Initialize(grammarList, &syntaxTable);
	m_vm->SetCommondList(m_interpreter->GenCmdList(), &syntaxTable);
	m_interpreter->Finalize();
}

int CGameMain::Func_Print( std::vector<SYNTAX_VALUE>& params)
{
	int n = MultiByteToWideChar(CP_ACP, 0, params[0].Vun.strVal, -1, NULL, 0);
	wchar_t *wbuff = new wchar_t[n];
	MultiByteToWideChar(CP_ACP, 0, params[0].Vun.strVal, -1, wbuff, n);
	m_textbox->SetText(wbuff);
	delete[] wbuff;
	return 1;
}