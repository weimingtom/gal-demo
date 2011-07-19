#include "stdafx.h"
#include "ResourceManager.h"
#include <fstream>
#include <string>

using namespace std;

CResourceManager::CResourceManager(void)
{
}

CResourceManager::~CResourceManager(void)
{
}

CResourceManager* CResourceManager::GetInstance()
{
	static CResourceManager instance;
	return &instance;
}

BOOL CResourceManager::Initialize(LPCTSTR name)
{
	string sname = name;
	sname.append(".gres");
	string iname = name;
	iname.append(".gids");
	m_resMgr.ChangeScript(sname.c_str());
	return m_resIds.LoadIdentities(iname.c_str());
}

BOOL CResourceManager::SetScript( LPCSTR name)
{
	string sname = name;
	sname.append(".gres");
	string iname = name;
	iname.append(".gids");
	m_resMgr.ChangeScript(sname.c_str());
	m_resIds.Destory();
	return m_resIds.LoadIdentities(iname.c_str());
}

BOOL CResourceManager::Finalize()
{
	
	m_resMgr.Purge(0);
	
	m_resIds.Destory();
	return TRUE;
}

BOOL CResourceManager::LoadResGroup(int group)
{
	//m_resMgr.Precache(group);
	return FALSE;
}

HTEXTURE CResourceManager::GetTexture( LONG ID, int group /*= 0*/ )
{
	return m_resMgr.GetTexture(m_resIds.LookUp(ID), group);
}

BOOL CResourceIdentity::LoadIdentities( LPCSTR fname)
{
	Destory();
	ifstream infile;
	infile.open(fname);
	if (!infile.is_open())
	{
		return FALSE;
	}
	char buff[MAX_RESNAME_LEN];
	int id = 0;
	while(infile.getline(buff, MAX_RESNAME_LEN))
	{
		char *resName = new char[MAX_RESNAME_LEN];
		memcpy(resName, buff, MAX_RESNAME_LEN);
		m_resIdMap[id++] = resName;
	}
	return TRUE;
}

LPCTSTR CResourceIdentity::LookUp( int id )
{
	return m_resIdMap[id];
}

void CResourceIdentity::Destory()
{
	std::map<LONG, LPTSTR>::iterator iter = m_resIdMap.begin();

	while (iter != m_resIdMap.end())
	{
		delete[] iter->second;
		iter->second = 0;
		iter++;
	}
	m_resIdMap.clear();
}