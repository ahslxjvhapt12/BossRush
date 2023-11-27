#include "pch.h"
#include "ResMgr.h"
#include "Boss_Idle.h"

Boss_Idle::Boss_Idle()
{
}

Boss_Idle::~Boss_Idle()
{
}

void Boss_Idle::OnEnter()
{
}

void Boss_Idle::Update()
{
}

void Boss_Idle::Render(HDC _dc)
{
	RECT_RENDER(0, 5, 10, 10, _dc);
}

void Boss_Idle::OnExit()
{
}
