#pragma once
#include "Object.h"

class Texture;
class SettingButton
	:public Object
{
public:
	SettingButton();
	~SettingButton();

public:
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* m_pTex;
};

