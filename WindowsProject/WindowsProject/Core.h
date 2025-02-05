#pragma once

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����
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
//		// ���� ȣ�� �� ���
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
	HWND	m_hWnd;			// ���� ������ �ڵ�
	POINT	m_ptResoultion; // ���� ������ �ػ�
	HDC		m_hDc;			// ���� �����쿡 Draw �� DC

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

