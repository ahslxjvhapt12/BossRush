#include "pch.h"
#include "daminScene.h"
#include "Object.h"
#include "Core.h"
#include "Player.h"
#include "Boss.h"
#include "Monster.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Razer.h"

void daminScene::Init()
{
	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(128.f, 128.f));
	AddObject(pObj, OBJECT_GROUP::PLAYER);

	Razer* razer = new Razer;
	//razer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	razer->SetPos(Vec2(50, 50));
	razer->SetDir(Vec2(0.f, 1.f));
	razer->SetScale(Vec2(25.f, 25.f));
	razer->SetName(L"Boss_Razer");
	AddObject(razer, OBJECT_GROUP::BULLET);
	razer->ShotRazer();

	Object* boss = new Boss;
	boss->SetPos((Vec2({ Core::GetInst()->GetResolution().x- 100, Core::GetInst()->GetResolution().y / 2 })));
	//boss->SetScale(Vec2(100.f, 200.f));
	AddObject(boss, OBJECT_GROUP::MONSTER);

	// 몬스터 세팅 마구마구 배치를 해봅시다.

	Vec2 vResolution = Core::GetInst()->GetResolution();
	Monster* pMonster = nullptr;
	int iMonster = 10;		// 몬스터 수 
	float fMoveDist = 30.f; // 움직일 거리
	float fMonsterScale = 50.f; // 몬스터 크기
	// 해상도x - ( 움직일 거리 + 오브젝트 크기 /2) * 2 / 몬스터수 -1 
	float fTerm = (vResolution.x - (fMoveDist + fMonsterScale / 2.f) * 2)
		/ (float)(iMonster - 1);
	for (int i = 0; i < iMonster; ++i)
	{
		pMonster = new Monster;
		pMonster->SetPos(Vec2(
			(fMoveDist + fMonsterScale / 2.f) + i * fTerm
			, 300.f));
		pMonster->SetScale(Vec2(fMonsterScale, fMonsterScale));
		pMonster->SetCenterPos(pMonster->GetPos());
		pMonster->SetMoveDis(fMoveDist);
		AddObject(pMonster, OBJECT_GROUP::MONSTER);
	}

	// 사운드 세팅
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");

	// 충돌체크해야되는것들을 설정하자.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
}

void daminScene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// 씬 변경
}

void daminScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void daminScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}

