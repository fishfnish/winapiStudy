#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"

TimeMgr::TimeMgr()
	: m_IICurCount{}
	, m_IIPrevCount{}
	, m_IIFregquency{}
	, m_dDT(0.)
	, m_dAcc(0.)
	, m_iCallCount(0)
	, m_iFPS(0)
{

}

TimeMgr::~TimeMgr()
{

}

void TimeMgr::init()
{
	//현재 카운트
	QueryPerformanceCounter(&m_IIPrevCount);

	//초당 카운트 횟수
	QueryPerformanceFrequency(&m_IIFregquency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&m_IICurCount);

	// 이전 프레임의 카운팅과, 현재 프레임의 카운팅 값의 차이를 구한다
	m_dDT = (double)(m_IICurCount.QuadPart - m_IIPrevCount.QuadPart) / (double)m_IIFregquency.QuadPart;
	
	// 이전 카운트 값을 현재값으로 갱신(다음번 계산을 위해서)
	m_IIPrevCount = m_IICurCount;
}

void TimeMgr::Render()
{
	++m_iCallCount;
	m_dAcc += m_dDT; // DT 누적

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0;
		m_iCallCount = 0;

		wchar_t sszBuffer[255] = {};
		wsprintf(sszBuffer, L"FPS : %d, DT : %lf ", m_iFPS, m_dDT);
		//wsprintfW(sszBuffer, L"FPS : %d, DT : ", m_iFPS, (int)(m_dDT * 1000000000));
		SetWindowText(Core::GetInst()->GetMainHwnd(), sszBuffer);
	}
}
