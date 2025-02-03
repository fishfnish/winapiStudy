#pragma once

// 전방선언
class Object;

class Scene
{
private:	
	// 오브잭트를 저장 및 관리 할 벡터를 그룹 갯수 만큼 선언
	vector<Object*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			m_strName; // Scene 이름

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void Update();
	void Render(HDC _dc);

	virtual void Enter() = 0;	// 해당 Scene 에 집인 시 호출
	virtual void Exit() = 0;	// 해당 Scene 에 탈출 시 호출

protected:
	void ADDObject(Object* _pObj, GROUP_TYPE _eTYPE)
	{
		m_arrObj[(UINT)_eTYPE].push_back(_pObj);
	}

public:
	Scene();
	virtual ~Scene();
};

