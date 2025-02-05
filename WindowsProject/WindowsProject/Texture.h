#pragma once
#include "CRes.h"

class Texture :
    public CRes
{
	HDC		m_dc;
	HBITMAP	m_hBit;
	BITMAP	m_bitInfo;

public:
	void Load(const wstring& _strFilePath);

	UINT WIdth() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }
	HDC GetDc() { return m_dc; }

private:
	Texture();
	~Texture();

	friend class ResMgr;
};

