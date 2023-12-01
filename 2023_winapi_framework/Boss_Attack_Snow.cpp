#include "pch.h"
#include "Boss_Attack_Snow.h"
#include "Core.h"
#include "Snow.h"
#include "Scene.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Boss_Idle.h"
#include "TimeMgr.h"
#include "StateMachine.h"
#include "SceneMgr.h"

Boss_Attack_Snow::Boss_Attack_Snow()
	:m_lifetTime(0)
	, count(3)
{
}

Boss_Attack_Snow::~Boss_Attack_Snow()
{
}

void Boss_Attack_Snow::OnEnter()
{
	ResMgr::GetInst()->Play(L"SnowSong");
}

void Boss_Attack_Snow::Update()
{
	/*if (m_lifetTime % 5 == 0)
		CreateSnow();*/

	m_lifetTime -= fDT;
	if(m_lifetTime <= 0)
	{
		count--;
		CreateSnow();
		m_lifetTime = 3;
		if(count <= 0)
			GetOwner()->GetStateMachine()->ChangeState(L"Idle");

	}
}

void Boss_Attack_Snow::Render(HDC _dc)
{
}

void Boss_Attack_Snow::OnExit()
{
}

void Boss_Attack_Snow::CreateSnow()
{
	LONG maxXpos = Core::GetInst()->GetResolution().x;
	for (int i = 0; i < 30; i++)
	{
		float xPos = rand() % maxXpos;
		Object* snow = new Snow;
		snow->SetPos(Vec2(xPos, 0.f));
		snow->SetScale(Vec2(30.f, 30.f));
		snow->SetName(L"Snow");
		SceneMgr::GetInst()->GetCurScene()->AddObject(snow, OBJECT_GROUP::MONSTER);
	}
}
