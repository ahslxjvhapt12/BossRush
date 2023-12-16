#pragma once
#include "Object.h"
class Texture;

class Jang : public Object
{
public:
	Jang(float speed, int hp);
	~Jang();
public:
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;
	void Update() override;
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
	float m_fSpeed;
	int m_iHp;
	const Object* m_player;
};

