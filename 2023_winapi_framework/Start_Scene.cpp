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

void Start_Scene::Init()
{
	// 
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

	//Object* pObj = new Player;
	//pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	//pObj->SetScale(Vec2(200.f, 200.f));
	//AddObject(pObj, OBJECT_GROUP::PLAYER);

	// ���� ���� �������� ��ġ�� �غ��ô�.

	//Vec2 vResolution = Core::GetInst()->GetResolution();
	//Monster* pMonster = nullptr;
	//int iMonster = 10;		// ���� �� 
	//float fMoveDist = 30.f; // ������ �Ÿ�
	//float fMonsterScale = 50.f; // ���� ũ��
	//// �ػ�x - ( ������ �Ÿ� + ������Ʈ ũ�� /2) * 2 / ���ͼ� -1 
	//float fTerm = (vResolution.x - (fMoveDist + fMonsterScale / 2.f) * 2) / (float)(iMonster - 1);
	//for (int i = 0; i < iMonster; ++i)
	//{
	//	pMonster = new Monster;
	//	pMonster->SetPos(Vec2(
	//		(fMoveDist + fMonsterScale / 2.f) + i * fTerm
	//		, 300.f));
	//	pMonster->SetScale(Vec2(fMonsterScale, fMonsterScale));
	//	pMonster->SetCenterPos(pMonster->GetPos());
	//	pMonster->SetMoveDis(fMoveDist);
	//	AddObject(pMonster, OBJECT_GROUP::MONSTER);
	//}
	// ���� ����



	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");

	// �浹üũ�ؾߵǴ°͵��� ��������.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::WALL);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::WALL);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::HOLE);
}

void Start_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// �� ����
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
