#pragma once
#include "Object.h"
class Texture;

class Fence :
	public Object
{
public:
	Fence();
	~Fence();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

