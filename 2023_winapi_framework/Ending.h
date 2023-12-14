#pragma once
#include "Scene.h"
class Ending :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
public:
    void ButtonDown();
};