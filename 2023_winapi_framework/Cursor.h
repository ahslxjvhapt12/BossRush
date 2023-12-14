#pragma once
#include "Object.h"

class Texture;

class Cursor
	:public Object
{
public:
	Cursor();
	~Cursor();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};

