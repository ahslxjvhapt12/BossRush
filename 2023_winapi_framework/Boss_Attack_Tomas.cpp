#include "pch.h"
#include "Boss_Attack_Tomas.h"
#include "Tomas.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "StateMachine.h"
#include "Core.h"
#include "ResMgr.h"

Boss_Attack_Tomas::Boss_Attack_Tomas()
	: m_SpawnDelay(0)
	, m_curTime(0)
{
	Vec2 ScreenSize = Core::GetInst()->GetResolution();

#pragma region 어라운드 패턴

	float Distance = 90.f;
	Pattern aroundPattern;
	for(int i = 1; i <= 7; i++)
	{
		Patterns Left;
		Left.spawnPos = Vec2(0.f, ScreenSize.y - i * Distance);
		Left.patternDelay = 1.45f;
		Left.dir = Tomas::Dir::Left;
		aroundPattern.patterns.push_back(Left);

		Patterns Up;
		Up.spawnPos = Vec2(ScreenSize.x - i * Distance, ScreenSize.y);
		Up.patternDelay = 0;
		Up.dir = Tomas::Dir::Up;
		aroundPattern.patterns.push_back(Up);

		Patterns Right;
		Right.spawnPos = Vec2(ScreenSize.x, 0.f + i * Distance);
		Right.patternDelay = 0;
		Right.dir = Tomas::Dir::Right;
		aroundPattern.patterns.push_back(Right);

		Patterns Down;
		Down.spawnPos = Vec2(0.f + i * Distance, 0.f);
		Down.patternDelay = 0;
		Down.dir = Tomas::Dir::Down;
		aroundPattern.patterns.push_back(Down);
	}

	m_pattern.push_back(aroundPattern);
#pragma endregion

#pragma region 가로세로 패턴

	Pattern HorVer;

	for(int j = 0; j < 5; j++)
	{
		int spawnCount = 5;
		float xDist = ScreenSize.y / (spawnCount - 1);

		for(int i = 0; i < spawnCount; i++)
		{
			Patterns Vertical;
			Vertical.spawnPos = Vec2(0.f, xDist * i);
			Vertical.patternDelay = (i == 0 ? 1.7f : 0);
			Vertical.dir = Tomas::Dir::Right;
			HorVer.patterns.push_back(Vertical);
		}

		spawnCount = 6;
		xDist = ScreenSize.x / (spawnCount - 1);
		for (int i = 0; i < spawnCount; i++)
		{
			Patterns Horizontal;
			Horizontal.spawnPos = Vec2(xDist * i, 0.f);
			Horizontal.patternDelay = (((i == 0) && (j < 3)) ? 1.7f : 0);
			Horizontal.dir = Tomas::Dir::Down;
			HorVer.patterns.push_back(Horizontal);
		}
	}
	m_pattern.push_back(HorVer);

#pragma endregion

#pragma region 움직이는 토마스

	Pattern MovePattern;
	float moveRange = 90.f;

	for (int j = 0; j < 5; j++)
	{
		int spawnCount = 5;
		float xDist = ScreenSize.y / (spawnCount - 1);

		for (int i = 0; i < spawnCount; i++)
		{
			Patterns Vertical;
			Vertical.spawnPos = Vec2(0.f, xDist * i);
			Vertical.patternDelay = (i == 0 ? 1.7f : 0);
			Vertical.dir = Tomas::Dir::Right;
			MovePattern.patterns.push_back(Vertical);
		}

		spawnCount = 6;
		xDist = ScreenSize.x / (spawnCount - 1);
		for (int i = 0; i < spawnCount; i++)
		{
			Patterns Horizontal;
			Horizontal.spawnPos = Vec2((xDist * i) + ((j > 2 ? 1.f :- 1.f ) * (moveRange * j)), 0.f);
			Horizontal.patternDelay = 0;
			Horizontal.dir = Tomas::Dir::Down;
			MovePattern.patterns.push_back(Horizontal);
		}
	}

	m_pattern.push_back(MovePattern);

#pragma endregion


}

Boss_Attack_Tomas::~Boss_Attack_Tomas()
{
}

void Boss_Attack_Tomas::OnEnter()
{
	m_curTime = 0;
	m_curIndex = 0;
	m_spanCount = 3;
	m_curPattern = m_pattern[rand() % m_pattern.size()];
	ResMgr::GetInst()->Play(L"Tomas");
}

void Boss_Attack_Tomas::Update()
{
	m_curTime += fDT;

	if (m_curIndex >= m_curPattern.patterns.size())
	{
		if (m_curTime > 6.5f);
			GetOwner()->GetStateMachine()->ChangeRandomState();
		return;
	}
		

	Patterns curPattern = m_curPattern.patterns[m_curIndex];

	if(m_curTime >= curPattern.patternDelay)
	{
		CreateTomas(curPattern.speed, curPattern.spawnDelay, curPattern.dir, curPattern.spawnPos);
		m_curTime = 0;
		m_curIndex++;
	}
}

void Boss_Attack_Tomas::Render(HDC _dc)
{
}

void Boss_Attack_Tomas::OnExit()
{
	ResMgr::GetInst()->Stop(SOUND_CHANNEL::EFFECT);
}

void Boss_Attack_Tomas::CreateTomas(float speed, float delay, Tomas::Dir dir, Vec2 vPos)
{
	Object* tomas = new Tomas(speed, delay, dir, vPos);
	SceneMgr::GetInst()->GetCurScene()->AddObject(tomas, OBJECT_GROUP::MONSTER);
}


