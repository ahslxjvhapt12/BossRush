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

void daminScene::Init()
{
	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(128.f, 128.f));
	pObj->SetName(L"player");
	AddObject(pObj, OBJECT_GROUP::PLAYER);

	Gaster* razer = new Gaster();
	//razer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	razer->SetPos(Vec2(50, 50));
	razer->SetScale(Vec2(100.f, 100.f));
	razer->SetName(L"Boss_Razer");
	AddObject(razer, OBJECT_GROUP::BULLET);

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

	// ���� ���� �������� ��ġ�� �غ��ô�.

	Vec2 vResolution = Core::GetInst()->GetResolution();
	Monster* pMonster = nullptr;
	int iMonster = 10;		// ���� �� 
	float fMoveDist = 30.f; // ������ �Ÿ�
	float fMonsterScale = 50.f; // ���� ũ��
	// �ػ�x - ( ������ �Ÿ� + ������Ʈ ũ�� /2) * 2 / ���ͼ� -1 
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

	// ���� ����
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");

	// �浹üũ�ؾߵǴ°͵��� ��������.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::BULLET, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::PLAYER);
}

void daminScene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// �� ����
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

