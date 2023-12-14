#include "pch.h"
#include "Boss_DestructionRay.h"
#include "Gaster.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Core.h"
#include "TimeMgr.h"
#include "StateMachine.h"

Boss_DestructionRay::Boss_DestructionRay()
	: m_player(nullptr)
	, m_curTime(0)
	, m_count(4)
	, m_followcount(3)
{

}

Boss_DestructionRay::~Boss_DestructionRay()
{
}

void Boss_DestructionRay::OnEnter()
{
	m_curTime = 0;
	m_count = 4;
	m_followcount = 3;
	ResMgr::GetInst()->Play(L"Laser");

	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	const vector<Object*>& player = pCurScene->GetGroupObject(OBJECT_GROUP::PLAYER);

	m_player = player[0];

	Vec2 vResolution = Core::GetInst()->GetResolution();

	int spawnCount = 13;
	float xDist = vResolution.x / spawnCount;

	for (int i = 0; i <= spawnCount; i++)
		CreateRay(Vec2(xDist * i, 50.f));
}

void Boss_DestructionRay::Update()
{
	m_curTime += fDT;
	if(m_curTime >= 3.f && m_count > 0)
	{
		int spawnCount = m_count % 2 == 0 ? 12 : 13;
		Vec2 vResolution = Core::GetInst()->GetResolution();
		float xDist = vResolution.x / spawnCount;
		for (int i = 0; i <= spawnCount; i++)
			CreateRay(Vec2(xDist * i, 50.f));
		m_curTime = 0;
		m_count--;
		return;
	}

	if (m_count > 0)
		return;
	//std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	//const vector<Object*>& player = pCurScene->GetGroupObject(OBJECT_GROUP::PLAYER);
	//char str[10];
	/*wchar_t str[10];
	wsprintf(str,str.length(),10);
	OutputDebugString("%d %d,m_count" );*/
	for(auto objects : m_rayVec)
	{
		if (m_curTime >= 1.f)
			continue;
		objects->SetPos(Vec2(m_player->GetPos().x, 50.f));
	}

	if(m_curTime >= 4.f && m_followcount > 0)
	{
		//wchar_t buf[20] = {}; //temporary buffer
		//swprintf(buf, L"%d","aaaa"); // convert
		//OutputDebugString(buf); // print

		CreateRay(Vec2(m_player->GetPos().x, 50.f));
		m_curTime = 0;
		m_followcount--;
	}
	else if(m_curTime >= 4.f && m_followcount <= 0)
	{
		GetOwner()->GetStateMachine()->ChangeRandomState();
		/*GetOwner()->GetStateMachine()->ChangeState(L"AttackSnow");*/

	}
}

void Boss_DestructionRay::Render(HDC _dc)
{
}

void Boss_DestructionRay::OnExit()
{
}

void Boss_DestructionRay::CreateRay(Vec2 Pos)
{
	Object* gaster = new Gaster;

	gaster->SetPos(Vec2(Pos.x, 50.f));
	SceneMgr::GetInst()->GetCurScene()->AddObject(gaster, OBJECT_GROUP::MONSTER);
	m_rayVec.push_back(gaster);
}