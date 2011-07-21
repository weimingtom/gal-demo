#pragma once
#include "hgeresource.h"

#include <map>

class CResourceIdentity
{
public:
	const static int MAX_RESNAME_LEN = 64;
	bool LoadIdentities(LPCSTR);
	LPCTSTR LookUp(int id);
	void Destory();
private:
	std::map<LONG, LPTSTR> m_resIdMap;
};

class CResourceManager
{
public:
	CResourceManager(void);
	virtual ~CResourceManager(void);
	
	const static int MAX_RES_GROUP = 5; 

	static CResourceManager* GetInstance();
	
	bool Initialize(LPCTSTR);
	bool Finalize();

	bool SetScript(LPCSTR);
	bool LoadResGroup(int);

	HTEXTURE GetTexture(LONG ID, int group = 0);

protected:
	hgeResourceManager	m_resMgr;
	CResourceIdentity	m_resIds;
};
