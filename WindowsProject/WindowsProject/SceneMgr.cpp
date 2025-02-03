#include "pch.h"
#include "SceneMgr.h"

#include "Scene_start.h"

SceneMgr::SceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{

}

SceneMgr::~SceneMgr()
{
	//Scene 삭제
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::init()
{
	// scene 생성
	m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = new Scene_TOOL;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = new Scene_STAGE_01;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = new Scene_STAGE_02;

	// 현재 씬 시점
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}
