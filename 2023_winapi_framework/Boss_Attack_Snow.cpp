#include "pch.h"
#include "Boss_Attack_Snow.h"
#include "Core.h"
#include "Snow.h"
#include "Scene.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Boss_Idle.h"

Boss_Attack_Snow::Boss_Attack_Snow()
{
}

Boss_Attack_Snow::~Boss_Attack_Snow()
{
}

void Boss_Attack_Snow::OnEnter()
{
	LONG maxXpos = Core::GetInst()->GetResolution().x;
	for (int i = 0; i < 50; i++)
	{
		float xPos = rand() % maxXpos;
		Object* snow = new Snow;
		snow->SetPos(Vec2(xPos, 0.f));
		snow->SetScale(Vec2(30.f, 30.f));
		snow->SetName(L"Snow");
		SceneMgr::GetInst()->GetCurScene()->AddObject(snow, OBJECT_GROUP::MONSTER);
	}
}

void Boss_Attack_Snow::Update()
{
}

void Boss_Attack_Snow::Render(HDC _dc)
{
}

void Boss_Attack_Snow::OnExit()
{
}
