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
		55,							// 글자 크기
		0,                          // 폭 (기본값 0)
		0,                          // 각도 (기본값 0)
		0,                          // 기울임 각도 (기본값 0)
		FW_NORMAL,					// 글자 두께
		false,						// 기울임 여부
		false,						// 밑줄 여부
		0,                          // 취소 선 여부 (기본값 0)
		ANSI_CHARSET,               // 문자 집합 (기본값 ANSI_CHARSET)
		OUT_DEFAULT_PRECIS,         // 출력 정밀도 (기본값 OUT_DEFAULT_PRECIS)
		CLIP_DEFAULT_PRECIS,        // 클리핑 정밀도 (기본값 CLIP_DEFAULT_PRECIS)
		DEFAULT_QUALITY,            // 출력 품질 (기본값 DEFAULT_QUALITY)
		DEFAULT_PITCH | FF_DONTCARE,// 피치 및 글꼴 패밀리 (기본값)
		L"Arial"                    // 글꼴 이름
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