#include "pch.h"
#include<math.h> 
#include "Core.h"
#include "Tomas.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "EventMgr.h"
#include "Collider.h"
#include "SelectGDI.h"
#include "Player.h"

Tomas::Tomas(float speed, float delay, Dir dir, Vec2 vPos)
	:m_pTex(nullptr)
	, m_lifeTime(0)
	, m_delay(0)
	, m_speed(0)
{
	m_speed = speed;
	m_dir = dir;
	m_delay = delay;

	SetPos(vPos);
	m_ScreenSize = Core::GetInst()->GetResolution();

	CreateCollider();
	Vec2 curPos = GetPos();

	switch (m_dir)
	{
	case Tomas::Dir::Left:
		m_pTex = ResMgr::GetInst()->TexLoad(L"Tomas_Left", L"Texture\\Tomas\\Tomas_Left.bmp");
		SetScale(Vec2(200.f, 100.f));
		GetCollider()->SetScale(Vec2(150.f, 100.f));
		m_Vec = Vec2(-1.f, 0.f);
		SetPos(Vec2(m_ScreenSize.x, curPos.y));
		break;
	case Tomas::Dir::Right:
		m_pTex = ResMgr::GetInst()->TexLoad(L"Tomas_Right", L"Texture\\Tomas\\Tomas_Right.bmp");
		SetScale(Vec2(200.f, 100.f));
		GetCollider()->SetScale(Vec2(150.f, 100.f));
		m_Vec = Vec2(1.f, 0.f);
		SetPos(Vec2(0.f, curPos.y));
		break;
	case Tomas::Dir::Down:
		m_pTex = ResMgr::GetInst()->TexLoad(L"Tomas_Down", L"Texture\\Tomas\\Tomas_Down.bmp");
		SetScale(Vec2(100.f, 200.f));
		GetCollider()->SetScale(Vec2(100.f, 150.f));
		m_Vec = Vec2(0.f, 1.f);
		SetPos(Vec2(curPos.x, 0.f));
		break;
	case Tomas::Dir::Up:
		m_pTex = ResMgr::GetInst()->TexLoad(L"Tomas_Up", L"Texture\\Tomas\\Tomas_Up.bmp");
		SetScale(Vec2(100.f, 200.f));
		GetCollider()->SetScale(Vec2(100.f, 150.f));
		m_Vec = Vec2(0.f, -1.f);
		SetPos(Vec2(curPos.x, m_ScreenSize.y));
		break;
	}
}

Tomas::~Tomas()
{
}

void Tomas::Update()
{
	m_lifeTime += fDT;

	if (m_lifeTime < m_delay)
		return;

	Vec2 vPos = GetPos();
	vPos.x += m_Vec.x * m_speed * fDT;
	vPos.y += m_Vec.y * m_speed * fDT;

	if(vPos.x > m_ScreenSize.x || vPos.x < 0
		|| vPos.y < 0 || vPos.y > m_ScreenSize.y)
		EventMgr::GetInst()->DeleteObject(this);

	SetPos(vPos);
}

void Tomas::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), vScale.x, vScale.y, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);

	if (m_lifeTime >= m_delay)
		return;

	PEN_TYPE ePen = PEN_TYPE::RED;
	BRUSH_TYPE eBrush = BRUSH_TYPE::RED;

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, eBrush);

	
	RECT_RENDER
	(
		(m_Vec.x != 0 ? m_ScreenSize.x / 2 : GetPos().x),
		(m_Vec.y != 0 ? m_ScreenSize.y / 2 : GetPos().y),
		(m_Vec.x != 0.f ? m_ScreenSize.x : vScale.x),
		(m_Vec.y != 0.f ? m_ScreenSize.y : vScale.y),
		_dc
	);
}

void Tomas::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"player")
	{
		Player* player = (Player*)&pOtherObj;
		player->OnHit();
	}
}
