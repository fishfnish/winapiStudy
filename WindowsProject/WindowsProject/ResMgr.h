#pragma once

class Texture;

class ResMgr
{
	SINGLE(ResMgr);
private:
	map<wstring, Texture*>	m_mapTex;

public:
	Texture* LoadTexture(const wstring& _strkey, const wstring& _strRelativPath);
	Texture* FindTexture(const wstring& _strkey);
};

