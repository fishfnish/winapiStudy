#include "pch.h"
#include "ResMgr.h"

#include "PathMgr.h"
#include "Texture.h"

ResMgr::ResMgr()
{

}

ResMgr::~ResMgr()
{
	map<wstring, Texture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

Texture* ResMgr::LoadTexture(const wstring& _strkey, const wstring& _strRelativPath)
{
	Texture* pTex = FindTexture(_strkey);
	if (nullptr != pTex)
	{
		return pTex;
	}

	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativPath;

	pTex = new Texture;
	pTex->Load(strFilePath);
	pTex->SetKey(_strkey);
	pTex->SetRelativePath(_strRelativPath);

	m_mapTex.insert(make_pair(_strkey, pTex));

	return pTex;
}

Texture* ResMgr::FindTexture(const wstring& _strkey)
{
	map<wstring, Texture*>::iterator iter = m_mapTex.find(_strkey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return iter->second;
}
