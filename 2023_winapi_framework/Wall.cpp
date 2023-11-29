#include "pch.h"
#include "Wall.h"
#include "ResMgr.h"
#include "Texture.h"


Wall::Wall()
	:m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\Wall.bmp");
}

Wall::~Wall()
{
}

void Wall::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	for (int i = 0; i < 32; ++i)
	{
		//BitBlt(_dc, (int)(vPos.x - vScale.x / 2) + i * 32, (int)(vPos.y - vScale.y / 2) + i * 32, Width, Height, m_pTex->GetDC(), 0, 0, SRCCOPY);
		StretchBlt(_dc, (int)(vPos.x - vScale.x / 2) + i * 32, (int)(vPos.y - vScale.y / 2) + 64 * 32, Width * 2, Height * 2, m_pTex->GetDC(), 0, 0, Width, Height, SRCCOPY);
		//StretchBlt(_dc, (int)(vPos.x - vScale.x / 2) + i * 32, (int)(vPos.y - vScale.y / 2) + 64, Width * 2, Height * 2, m_pTex->GetDC(), 0, 0, Width, Height, SRCCOPY);
	}

}
