#include "pch.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Boss.h"
#include "EventMgr.h"

Boss::Boss()
	: m_pTex(nullptr)
	, m_iHp(100)
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

}

void Boss::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Bullet")
	{
		
		m_iHp--;
		if (m_iHp <= 0)
			EventMgr::GetInst()->DeleteObject(this);
	}
}

void Boss::Raser(Vec2 pos)
{
	//SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);
}
