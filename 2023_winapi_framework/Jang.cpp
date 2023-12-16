#include "pch.h"
#include "Jang.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "EventMgr.h"
#include "Player.h"

Jang::Jang(float speed, int hp)
	: m_fSpeed(speed)
	, m_iHp(hp)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Jang", L"Texture\\jang.bmp");
	CreateCollider();

	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	const vector<Object*>& player = pCurScene->GetGroupObject(OBJECT_GROUP::PLAYER);
	SetPos(Vec2(500.f, 500.f));
	if(player.size() > 0)
		m_player = player[0];
}

Jang::~Jang()
{
}

void Jang::Update()
{
	if (m_player == nullptr)
		return;
	Vec2 curPos = GetPos();
	Vec2 targetPos = m_player->GetPos();
	//Vec2 dir = Vec2
	//(
	//	(targetPos.x < curPos.x ? -1.f : 1.f),
	//	(targetPos.y < curPos.y ? -1.f : 1.f)
	//);
	curPos.x += 
		(targetPos.x < curPos.x ? -1.f : 1.f) * m_fSpeed * fDT;
	curPos.y += 
		(targetPos.y < curPos.y ? -1.f : 1.f) * m_fSpeed * fDT;

	SetPos(curPos);
}

void Jang::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), vScale.x, vScale.y, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
}

void Jang::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player_Bullet")
	{
		m_iHp--;
		if (m_iHp <= 0)
		{
			ResMgr::GetInst()->Play(L"Jang");
			EventMgr::GetInst()->DeleteObject(this);
		}
	}

	if (pOtherObj->GetName() == L"player")
	{
		Player* player = (Player*)&pOtherObj;
		player->OnHit();
	}
}

void Jang::ExitCollision(Collider* _pOther)
{
}

void Jang::StayCollision(Collider* _pOther)
{
}
