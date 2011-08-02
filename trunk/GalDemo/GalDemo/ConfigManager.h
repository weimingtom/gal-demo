#pragma once
#include <string>

class CConfigManager 
{
public:
	CConfigManager();
	~CConfigManager(void);

	static CConfigManager* GetInstance();
	bool Initialize(char * fname);
	bool Finalize();

	void SetConfigSection(std::string section){m_section = section;}
	int	 GetWindowWidth();
	int	 GetWindowHeight();
	int  GetScreenDepth();
	bool IsWindowed();

	std::string GetWindowTitle();
	std::string	GetLogFileName();
	std::string	GetSystenFont();
	int			GetFontSize();

private:
	std::string					m_configFileName;
	std::string					m_section;
};
