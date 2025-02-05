#pragma once
#include "Object.h"

class Texture;

class Player :
	public Object
{
private:
	Texture* m_pTex;

public:
	virtual void Update();
	virtual void Render(HDC _dc);

private:
	void CreateBullet();

public:
	Player();
	~Player();
};

