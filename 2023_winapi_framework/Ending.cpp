#include "pch.h"
#include "Ending.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Core.h"
#include "Pigeon.h"
#include "Jang.h"

void Ending::Init()
{
	Vec2 screenSize = Core::GetInst()->GetResolution();

	//Object* obj = new Pigeon;
	//obj->SetPos(Vec2(100.f, 100.f));
	//obj->SetScale(Vec2(200.f, 200.f));
	//AddObject(obj, OBJECT_GROUP::MONSTER);
	Object* jang = new Jang(5, 5);
	jang->SetPos(Vec2(screenSize.x / 2, screenSize.y / 2 - 60));
	AddObject(jang, OBJECT_GROUP::MONSTER);
}

void Ending::Update()
{
	if (KEY_DOWN(KEY_TYPE::SPACE))
	{
		SceneMgr::GetInst()->LoadScene(L"IntroScene");
	}

	Scene::Update();
}

void Ending::Render(HDC _dc)
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

	std::wstring socre = std::to_wstring(Core::GetInst()->score);
	
	SelectObject(_dc, font);

	RECT rt = RECT_MAKE(screenSize.x / 2,screenSize.y / 2, 100, 60);
	DrawTextW(_dc, socre.c_str(), -1, &rt, DT_CENTER | DT_VCENTER);
	DeleteObject(font);
}

void Ending::Release()
{
	Scene::Release();
}