#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeMgr.h"
#include "CKeyManager.h"
//Core* Core::g_pInst = nullptr;

Object g_obj;

Core::Core()
	: m_hWnd(0)
	, m_ptResoultion{}
	, m_hDc(0)
	, m_hBit(0)
	, m_memDc(0)
{

}
Core::~Core()
{
	ReleaseDC(m_hWnd, m_hDc);

	DeleteDC(m_memDc);
	DeleteObject(m_hBit);
}
int Core::init(HWND _hWnd, POINT _ptResoultion)
{
	m_hWnd = _hWnd;
	m_ptResoultion = _ptResoultion;

	RECT rt = { 0,0,m_ptResoultion.x, m_ptResoultion.y };
	AdjustWindowRect(&rt, WS_OVERLAPPED, true);
	SetWindowPos(m_hWnd, nullptr, 100, 30, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDc = GetDC(m_hWnd);

	// 이중 버퍼링 용도의 비트맵과 DC 를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDc, m_ptResoultion.x, m_ptResoultion.y);
	m_memDc = CreateCompatibleDC(m_hDc);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDc, m_hBit);
	DeleteObject(hOldBit);

	TimeMgr::GetInst()->init();
	CKeyManager::GetInst()->init();

	g_obj.SetPos(Vec2((float)(m_ptResoultion.x / 2), (float)(m_ptResoultion.y / 2)));
	g_obj.SetSize(Vec2(100, 100));

	return S_OK;
}

void Core::progress()
{
	TimeMgr::GetInst()->Update();

	Update();

	Render();
}

void Core::Update()
{
	Vec2 vPos = g_obj.GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 200.f * DT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 200.f * DT;
	}

	g_obj.SetPos(vPos);
}

void Core::Render()
{
	//화면 claer
	Rectangle(m_memDc, -1, -1, m_ptResoultion.x + 1, m_ptResoultion.y + 1);

	Vec2 vPos = g_obj.GetPos();
	Vec2 vSize = g_obj.GetSize();

	Rectangle(m_memDc
		, int(vPos.x - vSize.x / 2.f)
		, int(vPos.y - vSize.y / 2.f)
		, int(vPos.x + vSize.x / 2.f)
		, int(vPos.y + vSize.y / 2.f));

	BitBlt(m_hDc, 0, 0, m_ptResoultion.x, m_ptResoultion.y
		, m_memDc, 0, 0, SRCCOPY);
}



