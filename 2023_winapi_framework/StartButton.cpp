#include "pch.h"
#include "StartButton.h"
#include "ResMgr.h"
#include "Texture.h"

StartButton::StartButton()
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"StartButton", L"Texture\\Button\\StartButton.bmp");
}

StartButton::~StartButton()
{

}

void StartButton::Update()
{

}

void StartButton::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));
}
