#pragma once



class TimeMgr
{
	SINGLE(TimeMgr)
private:
	LARGE_INTEGER m_IICurCount;
	LARGE_INTEGER m_IIFregquency;

public:
	void init();
};

