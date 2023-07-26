#pragma once
#include "FrameWork/Actors.h"
#include "../Engine/Input/InputSystem.h"

class Player : public kiko::Actor {
public:
	Player(const kiko::Transform& transform, std::shared_ptr<kiko::Modle>modle,const float speed, const float turn,std::string tag) :
		Actor{ transform, modle,tag },
		m_speed{speed},
		m_turnRate{turn}
	{}
	
	void Update(float dt) override;
	void OnCollision(Actor* other)override;

	


private:
	float m_speed = 0;
	float m_turnRate = 0;
	int hp = 100;

};