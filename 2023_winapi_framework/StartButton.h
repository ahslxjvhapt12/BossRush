#pragma once
#include "Object.h"

class Texture;
class StartButton :
	public Object
{
public:
	StartButton();
	~StartButton();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};