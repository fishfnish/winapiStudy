#pragma once
class Object
{
private:
	Vec2 m_vPos ;
	Vec2 m_vSize;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetSize(Vec2 _vSize) { m_vSize = _vSize; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetSize() { return m_vSize; }

public:
	Object();
	~Object();
};

