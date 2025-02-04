#pragma once
class CRes
{
private:
	wstring m_strKey;			// 리소스 키
	wstring m_strRelativePath;	// 상대 경로

public:
	void SetKey(const wstring& _strkey) { m_strKey = _strkey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = _strPath; }

	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }

public:
	CRes();
	~CRes();
};

