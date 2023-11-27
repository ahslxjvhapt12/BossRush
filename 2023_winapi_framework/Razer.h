#pragma once
#include "Object.h"
class Texture;

class Razer
	: public Object
{
public:
	Razer();
	~Razer();
public:
	void Update() override;
	void Render(HDC _dc) override;
	void ShotRazer();
	void SetDir(Vec2 _vDir)
	{
		m_vDir = _vDir;
		m_vDir.Normalize();
	}
	void SetShotDealy(float delay) { m_shotDelay = delay; }
private:
	Vec2 m_vDir;
	float m_shotTime;
	float m_shotDelay;
	bool m_showRazer;
	Texture* m_pTex;
};

