#pragma once
#include "Object.h"
class Bullet :
    public Object
{
private:
    //float     m_fThete;
    Vec2        m_vDir;

public:
    virtual void Update();
    virtual void Render(HDC _dc);

public:
   // void SetDir(float _fThete) { m_fThete = _fThete; }

public:
    Bullet();
    ~Bullet();
};

