#pragma once
#include "CRes.h"

class CTexture :
	public CRes
{
	HDC		m_dc;
	HBITMAP	m_hBit;

public:
	void Load(const wstring& _strFilePath);

public:
	CTexture();
	~CTexture();
};

