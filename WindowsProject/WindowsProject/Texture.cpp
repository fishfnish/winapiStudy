#include "pch.h"
#include "Texture.h"
#include "Core.h"
#include <Gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

Texture::Texture()
	: m_dc(0)
	, m_hBit(0)
    , m_bitInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void Texture::Load(const wstring& _strFilePath)
{
    // ���� �κ��� �ε��� �����͸� ��Ʈ������ ����
    m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    assert(m_hBit);

    // ��Ʈ������ ������ DC
    m_dc = CreateCompatibleDC(Core::GetInst()->GetMainDc());

    // ��Ʈ�ʰ� Dc����
    HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
    DeleteObject(hPrevBit);

    // ��Ʈ�� ����
    GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);

    /*Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    Gdiplus::Bitmap* bitmap = Gdiplus::Bitmap::FromFile(_strFilePath.c_str());
    if (bitmap && bitmap->GetLastStatus() == Gdiplus::Ok)
    {
        bitmap->GetHBITMAP(Gdiplus::Color(255, 255, 255), &m_hBit);
        assert(m_hBit);
    }
    else
    {
        MessageBox(NULL, L"Invalid frame dimensions!", L"Error", MB_ICONEXCLAMATION | MB_OK);
    }

    m_dc = CreateCompatibleDC(Core)

    delete bitmap;
    Gdiplus::GdiplusShutdown(gdiplusToken);*/
}


