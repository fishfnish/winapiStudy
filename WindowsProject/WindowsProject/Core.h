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
	HWND m_hWnd; // ���� ������ �ڵ�
	POINT m_ptResoultion; // ���� ������ �ػ�

public:
	int init(HWND _hWnd, POINT _ptResoultion);
	void progress();

private:
	Core();
	~Core();
};

