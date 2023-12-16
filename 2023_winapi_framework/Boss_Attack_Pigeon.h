#pragma once
#include "State.h"
class Object;

class Boss_Attack_Pigeon
	: public State
{
public:
	Boss_Attack_Pigeon();
	~Boss_Attack_Pigeon();

public:
	void OnEnter() override;
	void Update() override;
	void Render(HDC _dc) override;
	void OnExit() override;
};

