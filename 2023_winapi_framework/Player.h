#pragma once
#include "Object.h"
class Texture;
class Player :
	public Object
{
public:
	Player();
	~Player();
public:
	void Update() override;
	void Render(HDC _dc) override;
private:
	void CreateBullet();
	void Dash();
	void AnimationStateControl();
private:
	Texture* m_pTex;
	PLAYER_DIR m_playerDir;
	PLAYER_STATE m_playerState;
	float m_shootRemainTime;
	float m_shootDelay;
	float m_dashCool;
	float m_movementSpeed;
	float m_dashSpeed;
	bool m_onShoot;
	bool m_onDash;

	float m_hp;
};