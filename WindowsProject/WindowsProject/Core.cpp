#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeMgr.h"
#include "CKeyManager.h"
#include "SceneMgr.h"
#include "PathMgr.h"
//Core* Core::g_pInst = nullptr;

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

	PathMgr::GetInst()->init();
	TimeMgr::GetInst()->init();
	CKeyManager::GetInst()->init();
	SceneMgr::GetInst()->init();

	return S_OK;
}

void Core::progress()
{
	TimeMgr::GetInst()->Update();
	CKeyManager::GetInst()->Update();
	SceneMgr::GetInst()->Update();

	// 렌더링
	//==========
	//화면 claer
	Rectangle(m_memDc, -1, -1, m_ptResoultion.x + 1, m_ptResoultion.y + 1);
	
	SceneMgr::GetInst()->Render(m_memDc);

	BitBlt(m_hDc, 0, 0, m_ptResoultion.x, m_ptResoultion.y
		, m_memDc, 0, 0, SRCCOPY);

	//TimeMgr::GetInst()->Render();
}



