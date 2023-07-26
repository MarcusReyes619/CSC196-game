#pragma once
#pragma once
#include "FrameWork/Actors.h"


class Enemy : public kiko::Actor {
public:
	Enemy(const kiko::Transform& transform, std::shared_ptr<kiko::Modle>modle, const float speed, const float turn,std::string tag) :
		Actor{ transform, modle, tag },
		m_speed{ speed },
		m_turnRate{ turn }
	{
		m_fireTime = 2.0f;
		m_fireTimer = m_fireTime;
	}

	void OnCollision(Actor* other)override;


	void Update(float dt) override;


private:
	float m_speed = 0;
	float m_turnRate = 0;

	float m_fireTimer = 0;
	float m_fireTime = 0;

	int hp = 10;
	
};