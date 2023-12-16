#pragma once
#include "Object.h"
class Texture;

class Pigeon :
	public Object
{
public:
	Pigeon();
	~Pigeon();
public:
	void Update() override;
	void Render(HDC _dc) override;
	virtual void EnterCollision(Collider* _pOther) override;
private:
	Texture* m_pTex;
	float m_lifeTime;
};

