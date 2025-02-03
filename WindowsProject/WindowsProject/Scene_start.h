#pragma once
#include "Scene.h"

class Scene_start :
    public Scene
{
public:
   virtual void Enter();
   virtual void Exit();

public:
    Scene_start();
    ~Scene_start();
};

