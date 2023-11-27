#pragma once
#include "State.h"

class Boss_Idle : public State
{
public:
	Boss_Idle();
	~Boss_Idle();
public:
	void OnEnter() override;
	void Update() override;
	void Render(HDC _dc) override;
	void OnExit() override;
};

