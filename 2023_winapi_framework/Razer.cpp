#include "pch.h"
#include "Razer.h"
#include "ResMgr.h"
#include "SelectGDI.h"
#include "Collider.h"
#include "Core.h"
#include "Texture.h"
#include "TimeMgr.h"
#include "EventMgr.h"


Razer::Razer()
	: m_shotDelay(1)

{
	CreateCollider();
	
	GetCollider()->SetScale(Vec2(50.f, 1000.f));
}

Razer::~Razer()
{

}

void Razer::Update()
{
	m_shotDelay -= fDT;
	if (m_shotDelay <= 0)
		EventMgr::GetInst()->DeleteObject(this);

}

	void Razer::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetCollider()->GetScale();

	PEN_TYPE ePen = PEN_TYPE::GREEN;
	BRUSH_TYPE eBrush = BRUSH_TYPE::GREEN;

	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, eBrush);

	RECT_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);


	Component_Render(_dc);
}

	void Razer::EnterCollision(Collider* _pOther)
	{
		const Object* pOtherObj = _pOther->GetObj();
		if (pOtherObj->GetName() == L"player")
		{
			// 昏力贸府秦林搁蹬.
			
		}
	}

