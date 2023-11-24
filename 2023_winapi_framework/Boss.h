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
	virtual void EnterCollision(Collider* _pOther) override;
public:
	void Raser(Vec2 pos);
private:
	Texture* m_pTex;
	int m_iHp;
};

