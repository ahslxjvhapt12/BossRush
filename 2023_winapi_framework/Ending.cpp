#include "pch.h"
#include "Ending.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
//#include "ResMgr.h"

void Ending::Init()
{
	
}

void Ending::Update()
{
	if (KEY_DOWN(KEY_TYPE::SPACE))
	{
		ButtonDown();
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

void Ending::ButtonDown()
{
	SceneMgr::GetInst()->LoadScene(L"IntroScene");
}
