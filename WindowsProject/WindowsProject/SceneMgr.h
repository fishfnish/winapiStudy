#pragma once

class Scene;

class SceneMgr
{
	SINGLE(SceneMgr);
private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];	// 모든 씬 목록
	Scene* m_pCurScene;							// 현재 씬 목록

public:
	void init();
	void Update();
	void Render(HDC _dc);
};

