#include "pch.h"
#include "IntroScene.h"
#include "StartButton.h"
#include "SettingButton.h"
#include "QuitButton.h"
#include "Cursor.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"

void IntroScene::Init()
{
	Object* start = new StartButton;
	start->SetPos(Vec2(100.f, 500.f));
	start->SetScale(Vec2(200.f, 200.f));
	AddObject(start, OBJECT_GROUP::UI);

	Object* setting = new SettingButton;
	setting->SetPos(Vec2(100.f, 600.f));
	setting->SetScale(Vec2(200.f, 200.f));
	AddObject(setting, OBJECT_GROUP::UI);

	Object* quit = new QuitButton;
	quit->SetPos(Vec2(100.f, 700.f));
	quit->SetScale(Vec2(200.f, 200.f));
	AddObject(quit, OBJECT_GROUP::UI);

	idx = 0;
	cursor = new Cursor;
	cursor->SetPos(Vec2(100.f, 700.f));
	cursor->SetScale(Vec2(200.f, 200.f));
	AddObject(cursor, OBJECT_GROUP::UI);

}

void IntroScene::Update()
{
	if (KEY_DOWN(KEY_TYPE::UP))
	{
		if (idx > 0)
			idx--;
	}
	if (KEY_DOWN(KEY_TYPE::DOWN))
	{
		if (idx < 2)
			idx++;
	}
	if (KEY_DOWN(KEY_TYPE::SPACE))
	{
		ButtonDown();
	}
	cursor->SetPos({ 100.f, 500 + idx * 100.f });

	Scene::Update();
}

void IntroScene::ButtonDown() {
	if (idx == 0) {
		SceneMgr::GetInst()->LoadScene(L"daminScene");
	}
	else if (idx == 1) {
		SceneMgr::GetInst()->LoadScene(L"Setting");
	}
	else if (idx == 2) {
		exit(0);
	}

}

void IntroScene::Render(HDC _dc)
{
	Scene::Render(_dc);

}

void IntroScene::Release()
{
	Scene::Release();
}
