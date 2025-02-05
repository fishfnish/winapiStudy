#pragma once

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능
//
//class Core
//{
//private:
//	static Core* g_pInst;
//
//
//public:
//	static Core* GetInstance()
//	{
//		// 최초 호출 된 경우
//		if (nullptr == g_pInst)
//		{
//			g_pInst = new Core;
//			return g_pInst;
//		}
//		return g_pInst;
//	}
//
//	static void Release()
//	{
//		if (nullptr != g_pInst)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//	}
//
//private:
//	Core();
//	~Core();
//
//};

class Core
{
	SINGLE(Core);
private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	POINT	m_ptResoultion; // 메인 윈도우 해상도
	HDC		m_hDc;			// 메인 윈도우에 Draw 할 DC

	HBITMAP	m_hBit;
	HDC		m_memDc;

public:
	int init(HWND _hWnd, POINT _ptResoultion);
	void progress();

private:
	void Update();
	void Render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDc() { return m_hDc; }
	POINT GetResolution() { return m_ptResoultion; }
};

