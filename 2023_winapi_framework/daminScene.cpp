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
#include "Tomas.h"

Boss* bossObj;

void daminScene::Init()
{
	RECT rt = {};
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

	// ���� ����
	ResMgr::GetInst()->LoadSound(L"SnowSong", L"Sound\\SnowSong.wav", false);
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->LoadSound(L"Laser", L"Sound\\razer.wav", false);
	ResMgr::GetInst()->LoadSound(L"Pigeon", L"Sound\\Pigeon.wav", false);
	//ResMgr::GetInst()->Play(L"BGM");

	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(128.f, 128.f));
	pObj->SetName(L"player");
	AddObject(pObj, OBJECT_GROUP::PLAYER);


	Boss* boss = new Boss;
	boss->SetName(L"Boss");
	boss->SetScale(Vec2(200.f ,400.f));
	boss->SetPos((Vec2({ Core::GetInst()->GetResolution().x- 100, Core::GetInst()->GetResolution().y / 2 })));
	AddObject(boss, OBJECT_GROUP::MONSTER);
	bossObj = boss;
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



	// �浹üũ�ؾߵǴ°͵��� ��������.
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::BULLET);
	//CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::PLAYER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::MONSTER);
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

	Vec2 screenSize = Core::GetInst()->GetResolution();

	SetBkMode(_dc, 0);
	HFONT font = CreateFontW(
		55,							// ���� ũ��
		0,                          // �� (�⺻�� 0)
		0,                          // ���� (�⺻�� 0)
		0,                          // ����� ���� (�⺻�� 0)
		FW_NORMAL,					// ���� �β�
		false,						// ����� ����
		false,						// ���� ����
		0,                          // ��� �� ���� (�⺻�� 0)
		ANSI_CHARSET,               // ���� ���� (�⺻�� ANSI_CHARSET)
		OUT_DEFAULT_PRECIS,         // ��� ���е� (�⺻�� OUT_DEFAULT_PRECIS)
		CLIP_DEFAULT_PRECIS,        // Ŭ���� ���е� (�⺻�� CLIP_DEFAULT_PRECIS)
		DEFAULT_QUALITY,            // ��� ǰ�� (�⺻�� DEFAULT_QUALITY)
		DEFAULT_PITCH | FF_DONTCARE,// ��ġ �� �۲� �йи� (�⺻��)
		L"Arial"                    // �۲� �̸�
	);
	std::wstring socre = std::to_wstring(bossObj->GetScore());
	SelectObject(_dc, font);
	
	RECT rt = RECT_MAKE(screenSize.x - 100, 60, 100,60);
	DrawTextW(_dc, socre.c_str(), -1, &rt, DT_CENTER | DT_VCENTER);
	DeleteObject(font);

}

void daminScene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}

