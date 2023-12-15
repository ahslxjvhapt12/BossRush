#pragma once
#include "Object.h"

class Texture;
class Slider :
    public Object
{
public:
	Slider();
	~Slider();

public:
	void Update() override;
	void Render(HDC _dc) override;

public:
	int m_volume;
private:
	Texture* m_pSliderTex;
	Texture* m_pFillTex;
	Texture* m_volumeTex;
};