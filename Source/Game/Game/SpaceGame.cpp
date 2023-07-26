#include "SpaceGame.h"
#include "Player.h"
#include"Enemy.h"

#include"FrameWork/Scene.h"

#include "Audio/AudioSystem.h"
#include"Input/InputSystem.h"
#include"Render/Render.h"
#include "Render/Text.h"
#include "Render/modelManager.h"

bool SpaceGame::Initialize()
{
	//initialize
 	m_font = std::make_shared<kiko::Font>("C:\\Users\\mreyes\\source\\repos\\CSC196-game\\Build\\assets\\BodoniFLF-Bold.ttf", 54);

	m_scoreTxt = std::make_unique<kiko::Text>(m_font);
	m_scoreTxt->Create(kiko::g_ren, "Score 0000", kiko::Color{ 1, 1, 1, 1 });

	m_titleTxt = std::make_unique<kiko::Text>(m_font);
	m_titleTxt->Create(kiko::g_ren, "Azteriods", kiko::Color{ 1, 1, 1, 1 });
	
	kiko::g_audioSystem.AddAudio("Laser", "Laser_Shoot6.wav");


	m_scene = std::make_unique<kiko::Scene>();
	


	return true;
}

void SpaceGame::ShutDown()
{
}

void SpaceGame::Update(float dt)
{
	switch (m_state)
	{
	case SpaceGame::eState::Title:

		if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE)) {
			m_state = eState::Start;
		}
		break;
	case SpaceGame::eState::Start:
		m_score = 0;
		m_lives = 3;
		m_state = eState::StartLvl;
		break;
	case SpaceGame::eState::StartLvl:
		m_scene->removeAll();
		{
			//(const kiko::Transform & transform, std::shared_ptr<kiko::Modle>modle,
			//  const float speed, const float turn, std::string tag) :
				
			std::unique_ptr<Player> player = std::make_unique<Player>(kiko::Transform{ { 450,350 }, 0, 3 },
				kiko::g_manger.Get("ship.txt"),20.0f,
				kiko::pi , "player");
			player->m_game = this;
			m_scene->addActor(std::move(player));
			m_state = eState::Game;
		}
		break;
	case SpaceGame::eState::Game:
		m_spawnTimer += dt;
		if (m_spawnTimer >= m_spawnTime) {
			m_spawnTimer = 0;

			std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(
				kiko::Transform{
					{kiko::randomf(kiko::g_ren.GetWidth()),
					kiko::randomf(kiko::g_ren.GetHeight())},
					kiko::randomf(kiko::twoPi),
					2 },
					kiko::g_manger.Get("ship.txt"),
					kiko::randomf(25.0f, 50.0f),
					kiko::pi,
					 "Enemy");
			enemy->m_game = this;
			m_scene->addActor(std::move(enemy));

		}
		break;
	case eState::PlayerDeadStart:
		m_stateTimer = 3;
		m_state = eState::PlayerDead;
		if (m_lives == 0)m_state = eState::GameOver;
		
		break;

	case SpaceGame::eState::PlayerDead:
		if (m_lives == 0)m_state = eState::GameOver;
		else m_state = eState::StartLvl;
		break;
	case SpaceGame::eState::GameOver:
		break;
	default:
		break;
	}
	m_scoreTxt->Create(kiko::g_ren, std::to_string(m_score), {1,1,1,1});
	m_scene->Update(dt);
}

void SpaceGame::Draw(kiko::Renderer& renderer)
{
	if (m_state == eState::Title) {
		m_titleTxt->Draw(renderer, 400, 300);
	}
	m_scoreTxt->Draw(renderer, 40, 40);
	m_scene->Draw(renderer);
	
}
