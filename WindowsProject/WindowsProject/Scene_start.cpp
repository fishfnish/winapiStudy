#include "pch.h"
#include "Scene_start.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"

#include "PathMgr.h"
#include "Texture.h"

Scene_start::Scene_start()
{
}

Scene_start::~Scene_start()
{
}

void Scene_start::Enter()
{
	Object* pObj = new Player;
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetSize(Vec2(100.f, 100.f));
	ADDObject(pObj, GROUP_TYPE::DEFAULT);

	int iMonCount = 16;
	float fMoveDist = 25.f;
	float fObjSize = 50.f;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	Monster* pMonsterObj = nullptr;

	float fTerm = (vResolution.x - ((fMoveDist + fObjSize / 2.f) * 2)) / (float)(iMonCount-1);

	for (int i = 0; i < iMonCount; ++i)
	{
		// monster object Ãß°¡
		Monster* pMonsterObj = new Monster;
		pMonsterObj->SetPos(Vec2((fMoveDist + fObjSize / 2.f) + (float)i * fTerm, 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		pMonsterObj->SetSize(Vec2(fObjSize, fObjSize));
		ADDObject(pMonsterObj, GROUP_TYPE::DEFAULT);
	}

}

void Scene_start::Exit()
{

}
