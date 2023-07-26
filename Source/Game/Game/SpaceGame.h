#pragma once
#include"FrameWork/Game.h"
#include "Render/Text.h"

class SpaceGame : public kiko::Game {
public:
	enum class eState {
		Title,
		Start,
		StartLvl,
		Game,
		PlayerDeadStart,
		PlayerDead,
		GameOver

	
	};


public:


	// Inherited via Game
	virtual bool Initialize() override;

	virtual void ShutDown() override;

	virtual void Update(float dt) override;

	virtual void Draw(kiko::Renderer& renderer) override;

	void setState(eState state) { m_state = state; }

private:
	eState m_state = eState::Title;
	float m_spawnTimer = 0;
	float m_spawnTime = 3;

	float m_stateTimer = 0;


	std::shared_ptr<kiko::Font> m_font;
	std::unique_ptr<kiko::Text> m_scoreTxt;
	std::unique_ptr<kiko::Text>m_titleTxt;
	std::unique_ptr<kiko::Text> m_helath;
	std::unique_ptr<kiko::Text> m_gameoverTxt;




};
