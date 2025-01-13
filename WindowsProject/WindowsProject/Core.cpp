#include "pch.h"
#include "Core.h"
//Core* Core::g_pInst = nullptr;

Core::Core()
{

}
Core::~Core()
{

}
int Core::init(HWND _hWnd, POINT _ptResoultion)
{
	m_hWnd = _hWnd;
	m_ptResoultion = _ptResoultion;

	RECT rt = { 0,0,m_ptResoultion.x, m_ptResoultion.y };

	AdjustWindowRect(&rt, WS_OVERLAPPED, true);
	//SetWindowPos(m_hWnd, )

	_ptResoultion.x;
	_ptResoultion.y;

	return S_OK;
}

void Core::progress()
{

}