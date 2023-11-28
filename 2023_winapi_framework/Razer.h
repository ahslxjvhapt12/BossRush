#pragma once
#include "Object.h"

class Razer
	: public Object
{
public:
	Razer();
	~Razer();
public:
	void Update() override;
	void Render(HDC _dc) override;
	virtual void EnterCollision(Collider* _pOther) override;
private:
	Vec2 m_vDir;
	float m_shotDelay;
};

