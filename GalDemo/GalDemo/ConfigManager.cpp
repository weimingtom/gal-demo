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

bool CConfigManager::Initialize(char * fname)
{
	m_configFileName = fname;
	m_section = CONFIG_BASIC_SECTION;
	return true;
}

bool CConfigManager::Finalize()
{
	return true;
}

int CConfigManager::GetWindowWidth()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_WIDTH, 640, m_configFileName.c_str());
}

int CConfigManager::GetWindowHeight()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_HEIGHT, 480, m_configFileName.c_str());
}

bool CConfigManager::IsWindowed()
{
	if (1 == GetPrivateProfileInt(m_section.c_str(), SCREEN_WINDOWED, 1, m_configFileName.c_str()))
	{
		return true;
	}
	return false;
}

int CConfigManager::GetScreenDepth()
{
	return GetPrivateProfileInt(m_section.c_str(), SCREEN_DEPTH, 32, m_configFileName.c_str());
}

std::string CConfigManager::GetWindowTitle()
{
	char title[256];
	ZeroMemory(title, 256 * sizeof(char));
	GetPrivateProfileString(m_section.c_str(), WINDOW_TITLE, "GameDefault", title, 256 * sizeof(char), m_configFileName.c_str());
	return title;
}

std::string CConfigManager::GetLogFileName()
{
	char name[256];
	ZeroMemory(name, 256 * sizeof(char));
	GetPrivateProfileString(m_section.c_str(), LOG_FILE, "GameDefault", name, 256 * sizeof(char), m_configFileName.c_str());
	return name;
}

std::string CConfigManager::GetSystenFont()
{
	char font[256];
	ZeroMemory(font, 256 * sizeof(char));
	GetPrivateProfileString(m_section.c_str(), FONT_PATH, "font", font, 256 * sizeof(char), m_configFileName.c_str());
	return font;
}

int CConfigManager::GetFontSize()
{
	return GetPrivateProfileInt(m_section.c_str(), FONT_SIZE, 20, m_configFileName.c_str());
}