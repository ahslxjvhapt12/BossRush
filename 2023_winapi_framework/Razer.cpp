#include "pch.h"
#include "Razer.h"
#include "ResMgr.h"
#include "Core.h"
#include "Texture.h"
#include "TimeMgr.h"
#include "SelectGDI.h"

Razer::Razer()
	:m_shotTime(0)
	,m_shotDelay(3)
	,m_showRazer(false)
	, m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Bullet", L"Texture\\Bullet.bmp");
	CreateCollider();
	
}

Razer::~Razer()
{

}

void Razer::Update()
{
	if(m_shotTime >= 1 + m_shotDelay)
	{
		m_showRazer = false;
		Vec2 vPos = GetPos();
		vPos.x += 100.f * fDT * m_vDir.x;
		vPos.y += 100.f * fDT * m_vDir.y;
		SetPos(vPos);
		return;
	}

	if (m_shotTime >= 1)
		m_shotTime += fDT;

	if ((int)m_shotTime % 2 == 0)
		m_showRazer = true;
	else
		m_showRazer = false;
}

void Razer::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();


	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2)-3, (int)(vPos.y - vScale.y / 2)-3, Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	PEN_TYPE ePen = PEN_TYPE::HOLLOW;
	BRUSH_TYPE eBrush = BRUSH_TYPE::HOLLOW;
	if (m_showRazer)
	{
		ePen = PEN_TYPE::RED;
		eBrush = BRUSH_TYPE::RED;
		RECT_RENDER(vPos.x, vPos.y
			, m_vDir.x == 0 ? Core::GetInst()->GetResolution().x : vScale.x
			, m_vDir.y == 0 ? Core::GetInst()->GetResolution().y : vScale.y
			, _dc
		);
	}

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, eBrush);

	Component_Render(_dc);
}

void Razer::ShotRazer()
{
	m_shotTime = 1;
}
