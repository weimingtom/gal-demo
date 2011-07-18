#pragma once
#include <string>

class CConfigManager 
{
public:
	CConfigManager();
	~CConfigManager(void);

	static CConfigManager* GetInstance();
	BOOL Initialize(char * fname);
	BOOL Finalize();

	void SetConfigSection(std::string section){m_section = section;}
	int	 GetWindowWidth();
	int	 GetWindowHeight();
	int  GetScreenDepth();
	BOOL IsWindowed();

	std::string GetWindowTitle();
	std::string	GetLogFileName();

private:
	std::string					m_configFileName;
	std::string					m_section;
};
