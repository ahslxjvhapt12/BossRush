#pragma once
#include "State.h"
#include "Tomas.h"

class Boss_Attack_Tomas : public State
{
public:
	Boss_Attack_Tomas();
	~Boss_Attack_Tomas();
public:
	struct Patterns
	{
	public:
		Vec2 spawnPos;
		Tomas::Dir dir;
		float patternDelay;
		float spawnDelay = 1.2f;
		float speed = 2300.f;
	};
	struct Pattern
	{
	public:
		vector<Patterns> patterns;
	};
public:
	void OnEnter() override;
	void Update() override;
	void Render(HDC _dc) override;
	void OnExit() override;
public:
	void CreateTomas(float speed, float delay, Tomas::Dir dir, Vec2 vPos);
private:
	float m_SpawnDelay;
	float m_curTime;
	float m_spanCount;
	vector<Pattern> m_pattern;
	int m_curIndex;
	Pattern m_curPattern;
};

