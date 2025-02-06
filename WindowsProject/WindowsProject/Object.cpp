#include "pch.h"
#include "Object.h"

#include "CKeyManager.h"
#include "TimeMgr.h"

Object::Object()
	:m_vPos{}
	,m_vSize{}
{

}

Object::~Object()
{
	//if (nullptr != m_pCollider) delete m_pCollider;

	if (nullptr != m_pAnimator) delete m_pAnimator;
}

void Object::Render(HDC _dc)
{
	Rectangle(_dc,
		(int)m_vPos.x - m_vSize.x / 2.f,
		(int)m_vPos.y - m_vSize.y / 2.f,
		(int)m_vPos.x + m_vSize.x / 2.f,
		(int)m_vPos.y + m_vSize.y / 2.f);
}
