#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Player::Player()
	: m_pTex(nullptr)
	, m_shootRemainTime(0.f)
	, m_onShoot(false)
	, m_playerState(PLAYER_STATE::IDLE)
	, m_shootDelay(0.f)
{
	//m_pTex = new Texture;
	//wstring strFilePath = PathMgr::GetInst()->GetResPath();
	//strFilePath += L"Texture\\plane.bmp";
	//m_pTex->Load(strFilePath);
	//m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\plane.bmp");
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\Player\\PlayerAnimationSheet.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(32.f, 32.f));
	//GetCollider()->SetOffSetPos(Vec2(50.f,0.f));

	CreateAnimator();
	//GetAnimator()->CreateAnim(L"Jiwoo_Front", m_pTex, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Back", m_pTex, Vec2(0.f, 100.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Left", m_pTex, Vec2(0.f, 0.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Right", m_pTex, Vec2(0.f, 50.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->CreateAnim(L"Jiwoo_Attack", m_pTex, Vec2(0.f, 200.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);

	// Idle
	GetAnimator()->CreateAnim(L"Idle_Up", m_pTex, Vec2(0.f, 0.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Idle_Down", m_pTex, Vec2(0.f, 96.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Idle_Left", m_pTex, Vec2(0.f, 192.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Idle_Right", m_pTex, Vec2(0.f, 288.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);

	// Walk
	GetAnimator()->CreateAnim(L"Walk_Up", m_pTex, Vec2(0.f, 384.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Walk_Down", m_pTex, Vec2(0.f, 480.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Walk_Left", m_pTex, Vec2(0.f, 576.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Walk_Right", m_pTex, Vec2(0.f, 672.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);

	// Shoot
	GetAnimator()->CreateAnim(L"Shoot_Up", m_pTex, Vec2(0.f, 768.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Shoot_Down", m_pTex, Vec2(0.f, 864.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Shoot_Left", m_pTex, Vec2(0.f, 960.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);
	GetAnimator()->CreateAnim(L"Shoot_Right", m_pTex, Vec2(0.f, 1056.f), Vec2(96.f, 96.f), Vec2(96.f, 0.f), 4, 0.2f);

	GetAnimator()->PlayAnim(L"Idle_Down", true);

	//// 오프셋 건드리기
	//Animation* pAnim = GetAnimator()->FindAnim(L"Jiwoo_Front");
	//// 하나만
	//pAnim->SetFrameOffset(0, Vec2(0.f, 20.f));

	//// 프레임 다 
	//for (size_t i = 0; i < pAnim->GetMaxFrame(); ++i)
	//	pAnim->SetFrameOffset(i, Vec2(0.f, 20.f));
}
Player::~Player()
{
	//if (nullptr != m_pTex)
	//	delete m_pTex;
}
void Player::Update()
{
	Vec2 vPos = GetPos();

	m_playerState = PLAYER_STATE::IDLE;

	if (m_onShoot == true)
	{
		m_playerState = PLAYER_STATE::SHOOT;
		m_shootRemainTime -= fDT;
		if (m_shootRemainTime <= 0)
		{
			m_onShoot = false;
		}
	}

	if (m_onShoot == false)
	{
		m_playerState = PLAYER_STATE::IDLE;
	}

#pragma region 이동

	if (KEY_PRESS(KEY_TYPE::LEFT))
	{
		m_playerDir = PLAYER_DIR::LEFT;
		m_playerState = PLAYER_STATE::WALK;
		vPos.x -= 100.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::RIGHT))
	{
		m_playerDir = PLAYER_DIR::RIGHT;
		m_playerState = PLAYER_STATE::WALK;
		vPos.x += 100.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::UP))
	{
		m_playerDir = PLAYER_DIR::UP;
		m_playerState = PLAYER_STATE::WALK;
		vPos.y -= 100.f * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::DOWN))
	{
		m_playerDir = PLAYER_DIR::DOWN;
		m_playerState = PLAYER_STATE::WALK;
		vPos.y += 100.f * fDT;
	}

#pragma endregion

#pragma region 발사

	if (KEY_PRESS(KEY_TYPE::SPACE))
	{
		if (m_shootDelay <= 0) {
			CreateBullet();
			ResMgr::GetInst()->Play(L"Shoot");
			m_playerState = PLAYER_STATE::SHOOT;
			m_shootRemainTime = 0.5f;
			m_shootDelay = 0.1f;
		}
		else {
			m_shootDelay -= fDT;
		}
	}

#pragma endregion

	AnimationStateControl();
	SetPos(vPos);
	GetAnimator()->Update();
}

void Player::CreateBullet()
{
	Bullet* pBullet = new Bullet();
	//Vec2 vBulletPos = GetPos();
	//vBulletPos.y -= GetScale().y / 2.f;
	pBullet->SetPos(GetPos());
	pBullet->SetScale(Vec2(25.f, 25.f));

	switch (m_playerDir)
	{
	case PLAYER_DIR::UP:
		pBullet->SetDir(Vec2(0.f, -1.f));
		break;
	case PLAYER_DIR::DOWN:
		pBullet->SetDir(Vec2(0.f, 1.f));
		break;
	case PLAYER_DIR::LEFT:
		pBullet->SetDir(Vec2(-1.f, 0.f));
		break;
	case PLAYER_DIR::RIGHT:
		pBullet->SetDir(Vec2(1.f, 0.f));
		break;
	}

	pBullet->SetName(L"Player_Bullet");
	SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);
}

void Player::AnimationStateControl()
{
	switch (m_playerDir)
	{
	case PLAYER_DIR::UP:
	{
		if (m_playerState == PLAYER_STATE::SHOOT)
		{
			GetAnimator()->PlayAnim(L"Shoot_Up", true);
		}
		else if (m_playerState == PLAYER_STATE::WALK)
		{
			GetAnimator()->PlayAnim(L"Walk_Up", true);
		}
		else if (m_playerState == PLAYER_STATE::IDLE)
		{
			GetAnimator()->PlayAnim(L"Idle_Up", true);
		}
	}
	break;
	case PLAYER_DIR::DOWN:
	{
		if (m_playerState == PLAYER_STATE::SHOOT)
		{
			GetAnimator()->PlayAnim(L"Shoot_Down", true);
		}
		else if (m_playerState == PLAYER_STATE::WALK)
		{
			GetAnimator()->PlayAnim(L"Walk_Down", true);
		}
		else if (m_playerState == PLAYER_STATE::IDLE)
		{
			GetAnimator()->PlayAnim(L"Idle_Down", true);
		}
	}
	break;
	case PLAYER_DIR::LEFT:
	{
		if (m_playerState == PLAYER_STATE::SHOOT)
		{
			GetAnimator()->PlayAnim(L"Shoot_Left", true);
		}
		else if (m_playerState == PLAYER_STATE::WALK)
		{
			GetAnimator()->PlayAnim(L"Walk_Left", true);
		}
		else if (m_playerState == PLAYER_STATE::IDLE)
		{
			GetAnimator()->PlayAnim(L"Idle_Left", true);
		}
	}
	break;
	case PLAYER_DIR::RIGHT:
	{
		if (m_playerState == PLAYER_STATE::SHOOT)
		{
			GetAnimator()->PlayAnim(L"Shoot_Right", false);
		}
		else if (m_playerState == PLAYER_STATE::WALK)
		{
			GetAnimator()->PlayAnim(L"Walk_Right", true);
		}
		else if (m_playerState == PLAYER_STATE::IDLE)
		{
			GetAnimator()->PlayAnim(L"Idle_Right", true);
		}
	}
	break;
	}
}

void Player::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	//// 1. 기본 옮기기
	//BitBlt(_dc
	//	,(int)(vPos.x - vScale.x /2)
	//	,(int)(vPos.y - vScale.y /2)
	//	, Width,Height, m_pTex->GetDC()
	//	,0,0,SRCCOPY);

	//// 2. 색상 걷어내기
	//TransparentBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, Width,Height, RGB(255,0,255));

	//// 3. 확대 및 축소
	//StretchBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width ,Height, m_pTex->GetDC()
	//	, 0, 0, Width, Height, SRCCOPY);

	// 4. 회전
	// 삼각함수, 회전행렬
	//Plgblt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}
