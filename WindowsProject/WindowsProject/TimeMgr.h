#pragma once



class TimeMgr
{
	SINGLE(TimeMgr)
private:
	LARGE_INTEGER	m_IICurCount;
	LARGE_INTEGER	m_IIPrevCount;
	LARGE_INTEGER	m_IIFregquency;

	double			m_dDT; // ������ ������ �ð���
	double			m_dAcc; // 1�� üũ�� ���� ���� �ð�
	UINT			m_iCallCount; // �Լ� ȣ�� ȸ�� üũ
	UINT			m_iFPS; // ���� ȣ�� Ƚ��

public:
	void init();
	void Update();
	void Render();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

