#pragma once
#include "State.h"
class Object;

class Boss_DestructionRay : public State
{
public:
	Boss_DestructionRay();
	~Boss_DestructionRay();
public:
	void OnEnter() override;
	void Update() override;
	void Render(HDC _dc) override;
	void OnExit() override;
private:
	void CreateRay(Vec2 Pos);
private:
	const Object* m_player;
	float m_curTime;
	int m_count;
	int m_followcount;
	Object* m_rayVec;
};

