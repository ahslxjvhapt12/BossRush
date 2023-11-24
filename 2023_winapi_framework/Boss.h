#pragma once
#include "Object.h"
class Texture;
class Boss :
	public Object
{
public:
	Boss();
	~Boss();
public:
	void Update() override;
	void Render(HDC _dc) override;
	void Attack();
	virtual void EnterCollision(Collider* _pOther) override;
private:
	Texture* m_pTex;
};

