#include "pch.h"
#include "SelectGDI.h"
#include "Collider.h"
#include "EventMgr.h"
#include "ResMgr.h"
#include "Boss.h"

Boss::Boss()
	: m_pTex(nullptr)
	, m_iHp(100)
	, m_check(0)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\cylinder.png");
	
	CreateCollider();
	//GetCollider()->SetScale(Vec2(20.f,45.f));
}

Boss::~Boss()
{

}

void Boss::Update()
{
}

void Boss::Render(HDC _dc)
{

#pragma region 피격효과
	Vec2 vScale = GetScale();

	PEN_TYPE ePen = PEN_TYPE::HOLLOW;
	if (m_check)
		ePen = PEN_TYPE::RED;
	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);

	RECT_RENDER(vScale.x, vScale.y, vScale.x, vScale.y, _dc);
#pragma endregion

}

void Boss::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Bullet")
	{
		
		m_iHp--;
		m_check++;
		if (m_iHp <= 0)
			EventMgr::GetInst()->DeleteObject(this);
	}
}

void Boss::ExitCollision(Collider* _pOther)
{
	m_check--;
}

void Boss::Raser(Vec2 pos)
{
	//SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);
}
