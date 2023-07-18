#pragma once
#include "FrameWork/Actors.h"
#include "../Engine/Input/InputSystem.h"

class Player : public Actor {
public:
	Player(const kiko::Transform& transform, const kiko::Modle& modle,const float speed, const float turn) :
		Actor{ transform, modle },
		m_speed{speed},
		m_turnRate{turn}
	{}
	
	void Update(float dt) override;
	

private:
	float m_speed = 0;
	float m_turnRate = 0;

};