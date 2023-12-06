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
#include "Gaster.h"
#include "Snow.h"
#include "BackGround.h"
#include "Wall.h"
#include "Fence.h"

void daminScene::Init()
{

	Object* pBG = new BackGround;
	pBG->SetPos(Vec2(100.f, 100.f));
	pBG->SetScale(Vec2(200.f, 200.f));
	AddObject(pBG, OBJECT_GROUP::BACKGROUND);

	Object* pWall = new Wall;
	pWall->SetPos(Vec2(100.f, 100.f));
	pWall->SetScale(Vec2(200.f, 200.f));
	AddObject(pWall, OBJECT_GROUP::WALL);

	Fence* pFence = new Fence;
	pFence->SetPos(Vec2(100.f, 100.f));
	pFence->SetScale(Vec2(200.f, 200.f));
	AddObject(pFence, OBJECT_GROUP::HOLE);

	// 사운드 세팅
	ResMgr::GetInst()->LoadSound(L"SnowSong", L"Sound\\SnowSong.wav", false);
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->LoadSound(L"Laser", L"Sound\\razer.wav", false);
	//ResMgr::GetInst()->Play(L"BGM");

	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(128.f, 128.f));
	pObj->SetName(L"player");
	AddObject(pObj, OBJECT_GROUP::PLAYER);


	Object* boss = new Boss;
	boss->SetPos((Vec2({ Core::GetInst()->GetResolution().x- 100, Core::GetInst()->GetResolution().y / 2 })));
	AddObject(boss, OBJECT_GROUP::MONSTER);



	/*LONG maxXpos = Core::GetInst()->GetResolution().x;
	for (int i = 0; i < 50; i++) 
	{
		float xPos = rand() % maxXpos;
		Object* snow = new Snow;
		snow->SetPos(Vec2(xPos, 0.f));
		snow->SetScale(Vec2(30.f, 30.f));
		snow->SetName(L"Snow");
		AddObject(snow, OBJECT_GROUP::MONSTER);
	}*/

	// 몬스터 세팅 마구마구 배치를 해봅시다.



	// 충돌체크해야되는것들을 설정하자.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::BULLET);
	//CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::PLAYER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::MONSTER);
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

