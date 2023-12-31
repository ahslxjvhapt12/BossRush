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
	virtual void ExitCollision(Collider* _pOther)  override;
	int GetScore() { return m_score; }
public:
	void Raser(Vec2 pos);
private:
	int m_score;
	Texture* m_pTex;
	UINT m_check;
};

