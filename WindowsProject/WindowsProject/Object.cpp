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

}

void Object::Update()
{
	if (CKeyManager::GetInst()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		m_vPos.y -= 200.f * fDT;
	}
	if (CKeyManager::GetInst()->GetKeyState(KEY::S) == KEY_STATE::HOLD)
	{
		m_vPos.y += 200.f * fDT;
	}
	if (CKeyManager::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		m_vPos.x -= 200.f * fDT;
	}
	if (CKeyManager::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		m_vPos.x += 200.f * fDT;
	}
}

void Object::Render(HDC _dc)
{
	Rectangle(_dc,
		(int)m_vPos.x - m_vSize.x / 2.f,
		(int)m_vPos.y - m_vSize.y / 2.f,
		(int)m_vPos.x + m_vSize.x / 2.f,
		(int)m_vPos.y + m_vSize.y / 2.f);
}
