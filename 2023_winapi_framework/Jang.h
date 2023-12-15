#pragma once
#include "Object.h"
class Texture;

class Jang : public Object
{
public:
	Jang(float speed, Vec2 pos, int hp);
	~Jang();
public:
	void Update() override;
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;
private:
	Texture* m_pTex;
	float m_fSpeed;
	int m_iHp;
};

