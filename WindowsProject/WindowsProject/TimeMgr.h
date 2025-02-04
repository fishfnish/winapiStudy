#pragma once



class TimeMgr
{
	SINGLE(TimeMgr)
private:
	LARGE_INTEGER	m_IICurCount;
	LARGE_INTEGER	m_IIPrevCount;
	LARGE_INTEGER	m_IIFregquency;

	double			m_dDT; // 프레임 사이의 시간값
	double			m_dAcc; // 1초 체크를 위한 누적 시간
	UINT			m_iCallCount; // 함수 호출 회수 체크
	UINT			m_iFPS; // 초장 호출 횟수

public:
	void init();
	void Update();
	void Render();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

