#include "pch.h"
#include "Player.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CKeyManager.h"
#include "TimeMgr.h"
#include "Bullet.h"

#include "PathMgr.h"
#include "ResMgr.h"
#include "Texture.h"

Player::Player()
	:m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->LoadTexture(L"PlayerTex", L"\\Galaga.bmp");
	int a = 0;
}

Player::~Player()
{
}

void Player::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 300.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 300.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateBullet();
	}

	SetPos(vPos);
}

void Player::Render(HDC _dc)
{
	int iWidth = (int)m_pTex->WIdth();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	//BitBlt(_dc,
	//	vPos.x - (float)(iWidth / 2),
	//	vPos.y - (float)(iWidth / 2),
	//	iWidth, iHeight,
	//	m_pTex->GetDc(),
	//	0,	0,	SRCCOPY);

	TransparentBlt(_dc,
		vPos.x - (float)(iWidth / 2), 
		vPos.y - (float)(iWidth / 2), 
		iWidth, iHeight, 
		m_pTex->GetDc(), 
		0, 0, iWidth, iHeight,
		RGB(255,0,255));
}

void Player::CreateBullet()
{
	Vec2 vBulletPos = GetPos();
	vBulletPos.y -= GetSize().y / 2.f;

	Bullet* pBullet = new Bullet;
	pBullet->SetPos(vBulletPos);
	pBullet->SetSize(Vec2(25.f, 25.f));

	Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	pCurScene->ADDObject(pBullet, GROUP_TYPE::DEFAULT);
}




