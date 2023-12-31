#include "pch.h"
#include "Object.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "StateMachine.h"

Object::Object()
	: m_pCollider(nullptr)
	, m_vPos{}
	, m_vScale{}
	, m_IsAlive(true)
	, m_pAnimator(nullptr)
	, m_pStateMachine(nullptr)
{
}

Object::~Object()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
	if (nullptr != m_pStateMachine)
		delete m_pStateMachine;

}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}

void Object::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pOwner = this;
}

void Object::CreateStateMachine()
{
	m_pStateMachine = new StateMachine;
	m_pStateMachine->m_pOwner = this;
}

void Object::Update()
{
	//Vec2 vPos = m_obj.GetPos();

//	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
//	if(KeyMgr::GetInst()->GetKey(KEY_TYPE::LEFT) == KEY_STATE::UP)

	//m_obj.SetPos(vPos);
}

void Object::FinalUpdate()
{
	if (m_pCollider)
		m_pCollider->FinalUpdate();

	if (m_pStateMachine != nullptr)
		m_pStateMachine->Update();
}

void Object::Render(HDC _dc)
{
	/*Vec2 vPos = m_obj.GetPos();
	Vec2 vScale = m_obj.GetScale();*/
	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
	Component_Render(_dc);
}

void Object::EnterCollision(Collider* _pOther)
{
}

void Object::ExitCollision(Collider* _pOther)
{
}

void Object::StayCollision(Collider* _pOther)
{

}

void Object::Component_Render(HDC _dc)
{
	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc);
	if (nullptr != m_pAnimator)
		m_pAnimator->Render(_dc);
	if (nullptr != m_pStateMachine)
		m_pStateMachine->Render(_dc);
}

