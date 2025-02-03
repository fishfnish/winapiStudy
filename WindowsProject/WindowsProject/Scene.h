#pragma once

// ���漱��
class Object;

class Scene
{
private:	
	// ������Ʈ�� ���� �� ���� �� ���͸� �׷� ���� ��ŭ ����
	vector<Object*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			m_strName; // Scene �̸�

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void Update();
	void Render(HDC _dc);

	virtual void Enter() = 0;	// �ش� Scene �� ���� �� ȣ��
	virtual void Exit() = 0;	// �ش� Scene �� Ż�� �� ȣ��

protected:
	void ADDObject(Object* _pObj, GROUP_TYPE _eTYPE)
	{
		m_arrObj[(UINT)_eTYPE].push_back(_pObj);
	}

public:
	Scene();
	virtual ~Scene();
};

