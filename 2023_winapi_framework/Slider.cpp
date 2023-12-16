#include "pch.h"
#include "Slider.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Texture.h"
#include "Core.h"

Slider::Slider()
	:m_volume(5)
{
	m_pFillTex = ResMgr::GetInst()->TexLoad(L"Fill", L"Texture\\Slider\\Bar.bmp");
	m_pSliderTex = ResMgr::GetInst()->TexLoad(L"Slider", L"Texture\\Slider\\Slider.bmp");
	m_volumeTex = ResMgr::GetInst()->TexLoad(L"Volume", L"Texture\\Volume.bmp");
	m_setting = ResMgr::GetInst()->TexLoad(L"Setting", L"Texture\\Setting.bmp");
}

Slider::~Slider()
{

}

void Slider::Update()
{
	if (KEY_DOWN(KEY_TYPE::RIGHT)) {
		if (m_volume < 10)
			m_volume += 1;
		ResMgr::GetInst()->Volume(SOUND_CHANNEL::END, m_volume * 0.1f);
	}

	if (KEY_DOWN(KEY_TYPE::LEFT)) {
		if (m_volume >= 0)
			m_volume -= 1;
		ResMgr::GetInst()->Volume(SOUND_CHANNEL::END, m_volume * 0.1f);
	}
}

void Slider::Render(HDC _dc)
{
	Vec2 rectPos = Core::GetInst()->GetResolution();
	RECT_RENDER(rectPos.x / 2, rectPos.y / 2, 1000, 500, _dc);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	vPos.x += 200;
	vPos.y += 200;

	int Width = m_setting->GetWidth();
	int Height = m_setting->GetHeight();

	TransparentBlt(_dc, rectPos.x / 2 - 150, 20, Width, Height, m_setting->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

	Width = m_pSliderTex->GetWidth();
	Height = m_pSliderTex->GetHeight();

	for (int i = 0; i < 10; i++)
	{
		TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2) + i * 50, (int)(vPos.y - vScale.y / 2) + 100, Width, Height, m_pSliderTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));
	}

	Width = m_pFillTex->GetWidth();
	Height = m_pFillTex->GetHeight();

	for (int i = 0; i < m_volume; i++)
	{
		TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2) + i * 50, (int)(vPos.y - vScale.y / 2) + 100, Width, Height, m_pFillTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));
	}

	Width = m_volumeTex->GetWidth();
	Height = m_volumeTex->GetHeight();
	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), Width, Height, m_volumeTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));

}
