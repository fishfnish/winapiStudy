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
	//���� ī��Ʈ
	QueryPerformanceCounter(&m_IIPrevCount);

	//�ʴ� ī��Ʈ Ƚ��
	QueryPerformanceFrequency(&m_IIFregquency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&m_IICurCount);

	// ���� �������� ī���ð�, ���� �������� ī���� ���� ���̸� ���Ѵ�
	m_dDT = (double)(m_IICurCount.QuadPart - m_IIPrevCount.QuadPart) / (double)m_IIFregquency.QuadPart;
	
	// ���� ī��Ʈ ���� ���簪���� ����(������ ����� ���ؼ�)
	m_IIPrevCount = m_IICurCount;
}

void TimeMgr::Render()
{
	++m_iCallCount;
	m_dAcc += m_dDT; // DT ����

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
