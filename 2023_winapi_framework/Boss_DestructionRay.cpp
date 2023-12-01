#include "pch.h"
#include "Boss_DestructionRay.h"
#include "Gaster.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Core.h"

Boss_DestructionRay::Boss_DestructionRay()
	:m_player(nullptr)
{

}

Boss_DestructionRay::~Boss_DestructionRay()
{
}

void Boss_DestructionRay::OnEnter()
{
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
}