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

#include"define.h"

class Core
{
	Single

private:
	Core();
	~Core();
};

