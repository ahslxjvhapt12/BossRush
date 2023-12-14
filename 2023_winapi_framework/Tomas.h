#pragma once
#include "Object.h"
class Texture;

class Tomas:
	public Object
{
public :
	enum Dir
	{
		Left, Right, Up, Down
	};
public:
	Tomas(float speed, float delay,Dir dir, Vec2 vPos);
	~Tomas();
public:
	void Update() override;
	void Render(HDC _dc) override;
	virtual void EnterCollision(Collider* _pOther) override;
private:
	Texture* m_pTex;
	Dir m_dir;
	Vec2 m_Vec;
	Vec2 m_ScreenSize;
	float m_speed;
	float m_lifeTime;
	float m_delay;
};

