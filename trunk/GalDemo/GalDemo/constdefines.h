#define CONFIG_FILE_NAME		".\\config.ini"
#define CONFIG_BASIC_SECTION	"Basic"

#define SCREEN_WIDTH			"ScreenWidth"
#define SCREEN_HEIGHT			"ScreenHeight"
#define SCREEN_DEPTH			"ScreenDepth"
#define SCREEN_WINDOWED			"Windowed"
#define WINDOW_TITLE			"WinodwTitle"
#define LOG_FILE				"LogFile"
#define FONT_PATH				"Font"

#define CfgMgr					CConfigManager::GetInstance()
#define ResMgr					CResourceManager::GetInstance()
#define Game					CGame::GetInstance()