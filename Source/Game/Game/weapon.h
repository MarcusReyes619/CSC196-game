#pragma once
#include "FrameWork/Actors.h"

class Weapon : public kiko::Actor {
public: 
	Weapon(const kiko::Transform& transform, std::shared_ptr<kiko::Modle>modle, const float speed, const float turn,std::string tag) :
		Actor{ transform,modle,tag },
		m_speed{ speed }

	{
		m_lifespan = 2.0f;
	}
	void Update(float dt) override;
	void OnCollision(Actor* other)override;


private:
	float m_speed = 0;

};