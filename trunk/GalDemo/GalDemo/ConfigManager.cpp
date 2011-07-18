#include "stdafx.h"
#include "ConfigManager.h"
#include "constdefines.h"

CConfigManager::CConfigManager()
{
}

CConfigManager::~CConfigManager(void)
{
}

CConfigManager* CConfigManager::GetInstance()
{
	static CConfigManager instance;
	return &instance;
}

BOOL CConfigManager::Initialize(char * fname)
{
	m_configFileName = fname;
	m_section = CONFIG_BASIC_SECTION;
	return TRUE;
}

BOOL CConfigManager::Finalize()
{
	return TRUE;
}

int CConfigManager::GetWindowWidth()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_WIDTH, 640, m_configFileName.c_str());
}

int CConfigManager::GetWindowHeight()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_HEIGHT, 480, m_configFileName.c_str());
}

BOOL CConfigManager::IsWindowed()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_WINDOWED, 1, m_configFileName.c_str());
}

int CConfigManager::GetScreenDepth()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_DEPTH, 32, m_configFileName.c_str());
}

std::string CConfigManager::GetWindowTitle()
{
	char title[256];
	ZeroMemory(title, 256 * sizeof(char));
	GetPrivateProfileString(m_section.c_str(), WINDOW_TITLE, "GalDefault", title, 256 * sizeof(char), m_configFileName.c_str());
	return title;
}

std::string CConfigManager::GetLogFileName()
{
	char name[256];
	ZeroMemory(name, 256 * sizeof(char));
	GetPrivateProfileString(m_section.c_str(), LOG_FILE, "GalDefault", name, 256 * sizeof(char), m_configFileName.c_str());
	return name;
}