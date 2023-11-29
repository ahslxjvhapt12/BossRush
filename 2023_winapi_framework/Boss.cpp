#include "pch.h"
#include "ResMgr.h"
#include "SelectGDI.h"
#include "Collider.h"
#include "EventMgr.h"
#include "Boss.h"
#include "Texture.h"
#include "State.h"
#include "StateMachine.h"
#include "Boss_Idle.h"
#include "Snow.h"
#include "Core.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Boss_Attack_Snow.h"

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

#pragma region 콜라이더
	CreateCollider();
	GetCollider()->SetOffSetPos(Vec2(40.f,89.f));
	GetCollider()->SetScale(Vec2(80.f, 177.f));
#pragma endregion

#pragma region FSM
	CreateStateMachine();
	//GetStateMachine()->SetOnwer(this);

	Boss_Idle* Idle = new Boss_Idle;
	GetStateMachine()->AddState(L"Idle", Idle);

	Boss_Attack_Snow* AttackSnow = new Boss_Attack_Snow;
	GetStateMachine()->AddState(L"AttackSnow", AttackSnow);
	GetStateMachine()->ChangeState(L"AttackSnow");
	//state->OnEnter();
#pragma endregion

	/*LONG maxXpos = Core::GetInst()->GetResolution().x;
	for (int i = 0; i < 50; i++)
	{
		float xPos = rand() % maxXpos;
		Object* snow = new Snow;
		snow->SetPos(Vec2(xPos, 0.f));
		snow->SetScale(Vec2(30.f, 30.f));
		snow->SetName(L"Snow");
		SceneMgr::GetInst()->GetCurScene()->AddObject(snow, OBJECT_GROUP::MONSTER);
	}*/

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
}

void Boss::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Bullet")
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"BossHit", L"null");
		m_iHp--;
		m_check++;
		//if (m_iHp <= 0)
			//EventMgr::GetInst()->DeleteObject(this);
	}
}

void Boss::ExitCollision(Collider* _pOther)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Boss", L"null");
	m_check--;
}

void Boss::Raser(Vec2 pos)
{
	//SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);
}