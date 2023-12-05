#include "pch.h"
#include "Core.h"
#include "Snow.h"
#include "Scene.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Boss_Idle.h"
#include "State.h"
#include "TimeMgr.h"
#include "StateMachine.h"

Boss_Idle::Boss_Idle()
	:m_curTime(0)
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
	m_curTime += fDT;
	if (m_curTime >= 3.f)
		GetOwner()->GetStateMachine()->ChangeRandomState();
}

void Boss_Idle::Render(HDC _dc)
{
	//RECT_RENDER(0, 5, 10, 10, _dc);
}

void Boss_Idle::OnExit()
{
}
