#pragma once

class Scene;

class SceneMgr
{
	SINGLE(SceneMgr)
private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];	// ¸ðµç ¾À ¸ñ·Ï
	Scene* m_pCurScene;							// ÇöÀç ¾À ¸ñ·Ï

public:
	void init();
	void Update();
	void Render(HDC _dc);

public:
	Scene* GetCurScene() { return m_pCurScene; }
};

