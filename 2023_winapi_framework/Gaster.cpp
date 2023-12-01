#include "pch.h"
#include "Core.h"
#include "Scene.h"
#include "Razer.h"
#include "ResMgr.h"
#include "Gaster.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "PathMgr.h"
#include "Animator.h"
#include "Collider.h"
#include "SceneMgr.h"
#include "EventMgr.h"
#include "SelectGDI.h"
#include "Animation.h"

Gaster::Gaster()
	:m_shotTime(0)
	, m_shotDelay(3)
	, m_pTex(nullptr)
	, m_vDir(0.f, 1.f)
{
	CreateCollider();

#pragma region Animation

	CreateAnimator();
	m_pTex = ResMgr::GetInst()->TexLoad(L"Gaster", L"Texture\\RazerTurretBig.bmp");
	GetAnimator()->CreateAnim(L"Gaster", m_pTex, Vec2(0.f, 0.f), Vec2(48.f * 2, 57.f * 2), Vec2(48.f * 2, 0.f), 7, m_shotDelay / 7);
	GetAnimator()->PlayAnim(L"Gaster", false);

#pragma endregion


#pragma region SpawnLaser

#pragma endregion
}

Gaster::~Gaster()
{
}

void Gaster::Update()
{
	if (m_shotTime >= m_shotDelay)
	{
		Razer* pRazer = new Razer;
		Vec2 pRazerPos = GetPos();
		Vec2 pRazerScale = GetScale();
		pRazerScale.y = Core::GetInst()->GetResolution().y;
		pRazerPos.y = Core::GetInst()->GetResolution().y / 2;
		pRazer->SetPos(pRazerPos);
		pRazerScale.x /= 2;
		pRazer->SetScale(pRazerScale);
		pRazer->SetName(L"Boss_Razer");
		SceneMgr::GetInst()->GetCurScene()->AddObject(pRazer, OBJECT_GROUP::MONSTER);
		EventMgr::GetInst()->DeleteObject(this);
		/*Vec2 vPos = GetPos();
		vPos.x += 300.f * fDT * m_vDir.x;
		vPos.y += 300.f * fDT * m_vDir.y;
		SetPos(vPos);*/
		return;
	}

	m_shotTime += fDT;

	GetAnimator()->Update();
}

void Gaster::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();


	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	/*Plgblt(_dc
			, (int)(vPos.x - vScale.x / 2)
			, (int)(vPos.y - vScale.y / 2)
			, Width, Height, m_pTex->GetDC()
			, 0, 0, Width, Height, RGB(255, 0, 255));*/
			//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
			//TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2)-3, (int)(vPos.y - vScale.y / 2)-3, Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

			//PEN_TYPE ePen = PEN_TYPE::RED;
			//BRUSH_TYPE eBrush = BRUSH_TYPE::RED;
			//if (m_showRazer)
			//{
			//	/*RECT_RENDER(vPos.x, vPos.y
			//		,vScale.x
			//		, Core::GetInst()->GetResolution().y * 100
			//		, _dc
			//	);*/
			//	

			//	RECT_RENDER(vPos.x, vPos.y
			//		, m_vDir.x == 0.f ? vScale.x : Core::GetInst()->GetResolution().x * 500
			//		, m_vDir.y == 0.f ? vScale.y : Core::GetInst()->GetResolution().y * 500
			//		, _dc
			//	);
			//}
			//SelectGDI pen(_dc, ePen);
			//SelectGDI brush(_dc, eBrush);
			//RECT_RENDER(vPos.x, vPos.y
			//	, vScale.x
			//	, Core::GetInst()->GetResolution().y * 100
			//	, _dc
			//);


	Component_Render(_dc);
}