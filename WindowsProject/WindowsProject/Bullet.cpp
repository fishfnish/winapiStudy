#include "pch.h"
#include "Bullet.h"
#include "TimeMgr.h"

Bullet::Bullet()
	//: m_fThete(PI / 2.f)
	: m_vDir(Vec2(0.f, 1.f))
{
	m_vDir.Normalize();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Vec2 vPos = GetPos();
	
	/*vPos.x += 600.f * fDT * cosf(m_fThete);
	vPos.y -= 600.f * fDT * sinf(m_fThete);*/

	vPos.x += 600.f * m_vDir.x * fDT;
	vPos.y -= 600.f * m_vDir.y * fDT;

	SetPos(vPos);
}

void Bullet::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	Ellipse(_dc,
		(int)vPos.x - vSize.x / 2.f,
		(int)vPos.y - vSize.y / 2.f,
		(int)vPos.x + vSize.x / 2.f,
		(int)vPos.y + vSize.y / 2.f);
}
