#pragma once
#include "Object.h"

class Texture;
class QuitButton
	:public Object
{
public:
	QuitButton();
	~QuitButton();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};

