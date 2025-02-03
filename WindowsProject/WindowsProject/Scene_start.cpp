#include "pch.h"
#include "Scene_start.h"

#include "Object.h"

Scene_start::Scene_start()
{
}

Scene_start::~Scene_start()
{
}

void Scene_start::Enter()
{
	Object* pObj = new Object;
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetSize(Vec2(100.f, 100.f));

	ADDObject(pObj, GROUP_TYPE::DEFAULT);
}

void Scene_start::Exit()
{

}
