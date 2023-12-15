#include "pch.h"
#include "Setting.h"
#include "Slider.h"

void Setting::Init()
{
	Object* slider = new Slider;
	slider->SetPos(Vec2(150.f, 300.f));
	slider->SetScale(Vec2(200.f, 200.f));
	AddObject(slider, OBJECT_GROUP::UI);
}

void Setting::Update()
{
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
