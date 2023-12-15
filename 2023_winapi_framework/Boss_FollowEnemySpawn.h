#pragma once
#include "State.h"
#include "TimeLine.h"

class Boss_FollowEnemySpawn : public State
{
public:
	Boss_FollowEnemySpawn();
	~Boss_FollowEnemySpawn();
public:
	void OnEnter() override;
	void Update() override;
	void Render(HDC _dc) override;
	void OnExit() override;
public:
	void CreateJang(Vec2 pos);
private:
	TimeLine* m_timeLine;
};

