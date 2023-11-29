#pragma once
#include "Object.h"
class Texture;

class Snow
	:public Object
{
public:
	Snow();
	~Snow();
public:
	void Update() override;
	void Render(HDC _dc) override;
	virtual void EnterCollision(Collider* _pOther) override;
private:
	Texture* m_pTex;
	float m_Xdir;
	float m_Yspeed;
	float m_Xspeed;
	float m_ChangeDirDelay;
	float m_LifeTime;
};

