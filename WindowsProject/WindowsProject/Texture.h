#pragma once
#include "CRes.h"
class Texture :
    public CRes
{
	HDC		m_dc;
	HBITMAP	m_hBit;

public:
	void Load(const wstring& _strFilePath);

public:
	Texture();
	~Texture();
};

