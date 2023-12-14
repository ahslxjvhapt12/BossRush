#include "pch.h"
#include "Cursor.h"
#include "ResMgr.h"
#include "Texture.h"

Cursor::Cursor()
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Cursor", L"Texture\\Button\\Cursor.bmp");
}

Cursor::~Cursor()
{
}

void Cursor::Update()
{
}

void Cursor::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_dc, (int)(vPos.x - vScale.x / 2), (int)(vPos.y - vScale.y / 2), Width, Height, m_pTex->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));
}
