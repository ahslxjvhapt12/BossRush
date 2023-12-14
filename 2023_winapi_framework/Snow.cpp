#include "pch.h"
#include "Snow.h"
#include "Core.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "Collider.h"
#include "EventMgr.h"

Snow::Snow()
	:m_Xdir(1)
	, m_Yspeed(100.f)
	, m_ChangeDirDelay(0)
	, m_LifeTime(0)
	, m_Xspeed(70)
	, m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Snow", L"Texture\\SnowFlake.bmp");

	m_Yspeed = rand() % 90 + 40;
	m_Xspeed = rand() % 75 + 30;
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 20.f));
}

Snow::~Snow()
{

}

void Snow::Update()
{
	m_ChangeDirDelay -= fDT;

	if (m_ChangeDirDelay <= 0)
	{
		m_ChangeDirDelay = rand() % 6 + 1;
		m_Xdir *= -1;
	}

#pragma region ÀÌµ¿

	Vec2 vCurPos = GetPos();
	vCurPos.y += m_Yspeed * fDT;
	vCurPos.x += m_Xspeed * fDT * m_Xdir;

	if (vCurPos.y > Core::GetInst()->GetResolution().y)
		EventMgr::GetInst()->DeleteObject(this);

	SetPos(vCurPos);

#pragma endregion
}

void Snow::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), vScale.x, vScale.y, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
}

void Snow::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"player")
		EventMgr::GetInst()->DeleteObject(this);
}
