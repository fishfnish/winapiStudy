#pragma once

//class Collider;
class Animator;

class Object
{
private:
	//wstring m_strName;

	Vec2 m_vPos ;
	Vec2 m_vSize;

	//Collider* m_pCollider;
	Animator* m_pAnimator;

	//bool m_bAlive;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetSize(Vec2 _vSize) { m_vSize = _vSize; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetSize() { return m_vSize; }

public:
	virtual void Update() = 0;
	virtual void Render(HDC _dc);


public:
	Object();
	virtual ~Object();
};

