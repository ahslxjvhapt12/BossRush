#include "pch.h"
#include "Button.h"
#include "ResMgr.h"

Button::Button()
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Button", L"Texture\\Bullet.bmp");
}

Button::~Button()
{

}

void Button::Update()
{

}

void Button::Render(HDC _dc)
{

}
