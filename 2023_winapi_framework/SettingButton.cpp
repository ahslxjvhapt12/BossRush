#include "pch.h"
#include "SettingButton.h"
#include "ResMgr.h"
#include "Texture.h"

SettingButton::SettingButton()
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"SettingButton", L"Texture\\Button\\Setting.bmp");
}

SettingButton::~SettingButton()
{
}

void SettingButton::Update()
{
}

void SettingButton::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));
}
