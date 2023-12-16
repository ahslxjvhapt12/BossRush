#include "pch.h"
#include "TimeLine.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Jang.h"
#include "Boss_FollowEnemySpawn.h"
#include "Core.h"
#include "TimeMgr.h"
#include "StateMachine.h"

Boss_FollowEnemySpawn::Boss_FollowEnemySpawn()
{
	Vec2 ScreenSize = Core::GetInst()->GetResolution();
	CreateJang(Vec2(500.f, 500.f));
	CreateJang(Vec2(0.f, 0.f));

	//m_timeLine = new TimeLine;

#pragma region ½ºÆù
	//m_timeLine->CreateTrack(L"SpawnEdge");

	class MyClass
	{
	public:
		void operator()() 
		{
			
		}
	};
	//m_timeLine->AddTimeLine(L"SpawnEdge", L"LeftTop", 1, 2, RnadomSpawnJang);
#pragma endregion

}
void a()
{
}

Boss_FollowEnemySpawn::~Boss_FollowEnemySpawn()
{

}

void Boss_FollowEnemySpawn::OnEnter()
{
	m_fCurTime += fDT;
	//for(auto enemy : m_vEnemy)
	//{
	//	if (enemy == nullptr)
	//		m_vEnemy.erase(enemy);
	//}
	if(m_vEnemy.size() <= 0 && m_fCurTime >= 3)
		GetOwner()->GetStateMachine()->ChangeRandomState();
}

void Boss_FollowEnemySpawn::Update()
{
}

void Boss_FollowEnemySpawn::Render(HDC _dc)
{
}

void Boss_FollowEnemySpawn::OnExit()
{
}

void Boss_FollowEnemySpawn::CreateJang(Vec2 pos)
{
	Object* jang = new Jang(70.f, 2);
	SceneMgr::GetInst()->GetCurScene()->AddObject(jang, OBJECT_GROUP::MONSTER);
	jang->SetPos(pos);
	jang->SetScale(Vec2(100.f, 125.f));
	m_vEnemy.push_back(jang);
}
//
//void Spawn()
//{
//	Boss_FollowEnemySpawn::RnadomSpawnJang();
//}

void Boss_FollowEnemySpawn::RnadomSpawnJang()
{
	Vec2 ScreenSize = Core::GetInst()->GetResolution();
	int x = rand() % (int)ScreenSize.x;
	int y = rand() % (int)ScreenSize.y;
	CreateJang(Vec2(x, y));
}
