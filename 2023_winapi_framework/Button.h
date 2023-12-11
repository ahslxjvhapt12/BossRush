#pragma once
#include "Object.h"

class Texture;
class Button :
	public Object
{
public:
	Button();
	~Button();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};