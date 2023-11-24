#include "pch.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Boss.h"

Boss::Boss()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\cylinder.png");

	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f,45.f));
}

Boss::~Boss()
{

}

void Boss::Update()
{
}

void Boss::Render(HDC _dc)
{
}

void Boss::EnterCollision(Collider* _pOther)
{

}
