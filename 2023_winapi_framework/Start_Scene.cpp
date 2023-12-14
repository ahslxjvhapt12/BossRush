#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Core.h"
#include "Player.h"
#include "BackGround.h"
#include "Wall.h"
#include "Monster.h"
#include "KeyMgr.h"
#include "Fence.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "Boss.h"

void Start_Scene::Init()
{
	ResMgr::GetInst()->LoadSound(L"SnowSong", L"Sound\\SnowSong.wav", false);
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->LoadSound(L"Laser", L"Sound\\razer.wav", false);

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

	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(128.f, 128.f));
	pObj->SetName(L"player");
	AddObject(pObj, OBJECT_GROUP::PLAYER);

	Object* boss = new Boss;
	boss->SetPos((Vec2({ Core::GetInst()->GetResolution().x - 100, Core::GetInst()->GetResolution().y / 2 })));
	AddObject(boss, OBJECT_GROUP::MONSTER);

	//Object* pObj = new Player;
	//pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	//pObj->SetScale(Vec2(200.f, 200.f));
	//AddObject(pObj, OBJECT_GROUP::PLAYER);

	// 충돌체크해야되는것들을 설정하자.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::WALL);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::WALL);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::HOLE);
}

void Start_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// 씬 변경
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
