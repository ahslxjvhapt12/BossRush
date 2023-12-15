#include "pch.h"
#include "Jang.h"
#include "ResMgr.h"

Jang::Jang(float speed, Vec2 pos, int hp)
	: m_fSpeed(speed)
	, m_iHp(hp)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Tomas_Left", L"Texture\\jang.bmp");
}

Jang::~Jang()
{
}

void Jang::Update()
{
}

void Jang::EnterCollision(Collider* _pOther)
{
}

void Jang::ExitCollision(Collider* _pOther)
{
}

void Jang::StayCollision(Collider* _pOther)
{
}
