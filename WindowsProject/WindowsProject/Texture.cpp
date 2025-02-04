#include "pch.h"
#include "Texture.h"

Texture::Texture()
	: m_dc(0)
	, m_hBit(0)
{
}

Texture::~Texture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void Texture::Load(const wstring& _strFilePath)
{
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	//assert(m_hBit)
	if (nullptr == m_hBit)
	{
		MessageBox(NULL, L"Failed to load bitmap!", L"Error", MB_ICONEXCLAMATION | MB_OK);
	}
}