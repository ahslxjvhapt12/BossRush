#include "pch.h"
#include "Ending.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Pigeon.h"

void Ending::Init()
{
	//Object* obj = new Pigeon;
	//obj->SetPos(Vec2(100.f, 100.f));
	//obj->SetScale(Vec2(200.f, 200.f));
	//AddObject(obj, OBJECT_GROUP::MONSTER);
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
}

void Ending::Release()
{
	Scene::Release();
}