#pragma once
#include "State.h"
class Object;

class Boss_Attack_Snow : public State
{
public:
	Boss_Attack_Snow();
	~Boss_Attack_Snow();
public:
	void OnEnter() override;
	void Update() override;
	void Render(HDC _dc) override;
	void OnExit() override;
};

