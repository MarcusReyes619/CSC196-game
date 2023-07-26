#include "Player.h"
#include "FrameWork/Scene.h"
#include "Input/InputSystem.h"
#include "weapon.h"
#include "SpaceGame.h"
void Player::Update(float dt)
{
    Actor::Update(dt);
	
    bool sprint = kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_LSHIFT);

    float rotate = 0;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
    m_transform.rotations += rotate * m_turnRate * kiko::g_time.GetDeltaTime();

    float thrust = 0;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotations);
    m_transform.position += forward * m_speed * thrust * kiko::g_time.GetDeltaTime() * ((sprint) ? 2 : 1);
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_ren.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_ren.GetHeight());

    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !kiko::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE)) {
        //create weapon
        kiko::Transform tran{ m_transform.position,m_transform.rotations,1 };
        std::unique_ptr<Weapon>weapon = std::make_unique<Weapon>(kiko::Transform{ m_transform.position, m_transform.rotations, 1 }, m_model, 400.0f, kiko::halfPi, m_tag);
        m_scene->addActor(std::move(weapon));

        kiko::Transform tran2{ m_transform.position,m_transform.rotations,1 };

        /*std::unique_ptr<Weapon>weapon = std::make_unique<Weapon>(kiko::Transform{ m_transform.position, m_transform.rotations, 1 }, m_model, 400.0f, kiko::halfPi, m_tag);
        m_scene->addActor(std::move(weapon));*/
    }
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_C)) kiko::g_time.setTimeScale(0.5f);
    else kiko::g_time.setTimeScale(1.0f);

    kiko::vec2 forward2 = kiko::vec2{ 0,-1 }.Rotate(m_transform.rotations - kiko::degreesToRadians(10.0f));
    addForces(forward2 * m_speed * thrust);
}

void Player::OnCollision(Actor* other)
{
    if (other->m_tag == "Enemy") {

        m_game->SetLives(m_game->GetLives() - 1);
        dynamic_cast<SpaceGame*>(m_game)->setState(SpaceGame::eState::PlayerDead);
        m_destroyed = true;
    }
   
}



