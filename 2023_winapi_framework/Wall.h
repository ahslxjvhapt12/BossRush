#pragma once
#include "Object.h"
class Texture;
class Wall :
	public Object
{
public:
	Wall();
	~Wall();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};