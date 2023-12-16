#include "pch.h"
#include "Setting.h"
#include "Slider.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

void Setting::Init()
{
	Object* slider = new Slider;
	slider->SetPos(Vec2(100.f, 100.f));
	slider->SetScale(Vec2(200.f, 200.f));
	AddObject(slider, OBJECT_GROUP::UI);
}

void Setting::Update()
{
	if (KEY_DOWN(KEY_TYPE::ESC)) {
		SceneMgr::GetInst()->LoadScene(L"IntroScene");
	}
	Scene::Update();
}

void Setting::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Setting::Release()
{
	Scene::Release();
}
