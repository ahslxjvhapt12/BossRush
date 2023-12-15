#include "pch.h"
#include "SceneMgr.h"
#include "Start_Scene.h"
#include "daminScene.h"
#include "IntroScene.h"
#include "Setting.h"

void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	// �� ���
	RegisterScene(L"Start_Scene", std::make_shared<Start_Scene>());
	RegisterScene(L"daminScene", std::make_shared<daminScene>());
	RegisterScene(L"IntroScene", std::make_shared<IntroScene>());
	RegisterScene(L"Setting", std::make_shared<Setting>());

	// ù �� ����
	//LoadScene(L"Setting");
	//LoadScene(L"IntroScene");
	LoadScene(L"daminScene");
	//LoadScene(L"Start_Scene");
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{
	// ���� ������
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), { _scenename, _scene });
}
