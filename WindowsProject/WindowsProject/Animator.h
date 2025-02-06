#pragma once

class Object;
class Animation;

class Animator
{
private:
	map<wstring, Animation*>	m_mapAnim;
	Object*						m_pOwner;
	
public:
	void CreateAnimation();
	void FindAnimation();
	void Play();

public:
	Animator();
	~Animator();

	friend class Object;
};

