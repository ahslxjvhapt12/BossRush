#include "pch.h"
#include "ResMgr.h"
#include "SelectGDI.h"
#include "Collider.h"
#include "EventMgr.h"
#include "Boss.h"
#include "Texture.h"

Boss::Boss()
	: m_pTex(nullptr)
	, m_iHp(100)
	, m_check(0)
{

	//m_pTex = ResMgr::GetInst()->TexLoad(L"Boss", L"Texture\\Bullet.bmp");
	//m_pTex = ResMgr::GetInst()->TexLoad(L"Boss", L"Texture\\Untitled - _1_.bmp");
	m_pTex = ResMgr::GetInst()->TexLoad(L"BossHit", L"Texture\\cylinderhit.bmp");
	m_pTex = ResMgr::GetInst()->TexLoad(L"Boss", L"Texture\\cylinder.bmp");
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	CreateCollider();
	GetCollider()->SetOffSetPos(Vec2(40.f,89.f));
	GetCollider()->SetScale(Vec2(80.f, 177.f));
}

Boss::~Boss()
{

}

void Boss::Update()
{
}

void Boss::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	//RECT_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	Component_Render(_dc);
#pragma region �ǰ�ȿ��

	PEN_TYPE epen = PEN_TYPE::HOLLOW;
	BRUSH_TYPE ebtrush = BRUSH_TYPE::HOLLOW;
	if (m_check)
	{
		epen = PEN_TYPE::RED;
		//ebtrush = BRUSH_TYPE::RED;
	}
		//RECT_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
		//epen = PEN_TYPE::RED;
	SelectGDI pen(_dc, epen);
	SelectGDI brush(_dc, ebtrush);

#pragma endregion
	Component_Render(_dc);
}

void Boss::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Bullet")
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"BossHit", L"Texture\\cylinderhit.bmp");
		m_iHp--;
		m_check++;
		if (m_iHp <= 0)
			EventMgr::GetInst()->DeleteObject(this);
	}
}

void Boss::ExitCollision(Collider* _pOther)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Boss", L"Texture\\cylinder.bmp");
	m_check--;
}

void Boss::Raser(Vec2 pos)
{
	//SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);
}
