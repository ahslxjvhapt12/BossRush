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
#include "Boss_DestructionRay.h"
#include "Boss_Attack_Tomas.h"
#include "Boss_FollowEnemySpawn.h"

Boss::Boss()
	: m_pTex(nullptr)
	, m_score(0)
	, m_check(0)
{

	m_pTex = ResMgr::GetInst()->TexLoad(L"BossHit", L"Texture\\cylinderhit.bmp");
	m_pTex = ResMgr::GetInst()->TexLoad(L"Boss", L"Texture\\cylinder.bmp");

#pragma region 콜라이더
	CreateCollider();
	//GetCollider()->SetOffSetPos(Vec2(40.f,89.f));
	GetCollider()->SetScale(Vec2(200.f ,400.f));
#pragma endregion

#pragma region FSM
	CreateStateMachine();
	//GetStateMachine()->SetOnwer(this);

	Boss_Attack_Snow* AttackSnow = new Boss_Attack_Snow;
	Boss_DestructionRay* DestructionRay = new Boss_DestructionRay;
	Boss_Attack_Tomas* AttackTomas = new Boss_Attack_Tomas;
	Boss_FollowEnemySpawn* FollowEnemy = new Boss_FollowEnemySpawn;

	GetStateMachine()->AddState(L"AttackSnow", AttackSnow);
	GetStateMachine()->AddState(L"DestructionRay", DestructionRay);
	GetStateMachine()->AddState(L"AttackTomas", AttackTomas);
	GetStateMachine()->AddState(L"FollowEnemy", FollowEnemy);
	
	GetStateMachine()->ChangeState(L"FollowEnemy");
	//GetStateMachine()->ChangeRandomState();
#pragma endregion
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

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), vScale.x, vScale.y, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
}

void Boss::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Bullet")
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"BossHit", L"null");
		m_score++;
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