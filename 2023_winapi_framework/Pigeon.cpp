#include "pch.h"
#include "Collider.h"
#include "Pigeon.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Player.h"
#include "TimeMgr.h"
#include "EventMgr.h"

Pigeon::Pigeon()
	:m_lifeTime(10.f)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(50.f, 100.f));

	m_pTex = ResMgr::GetInst()->TexLoad(L"Pigeon", L"Texture\\Pigeon.bmp");
}

Pigeon::~Pigeon()
{
}

void Pigeon::Update()
{
	m_lifeTime -= fDT;
	Vec2 vPos = GetPos();
	
	vPos.x += 500.f * fDT;
	vPos.y += 500.f * fDT;

	
	
	SetPos(vPos);
	if (m_lifeTime <= 0) {
		EventMgr::GetInst()->DeleteObject(this);
	}

}

void Pigeon::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

}

void Pigeon::EnterCollision(Collider* _pOther)
{
}
