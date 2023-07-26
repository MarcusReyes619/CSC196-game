#include "Enemy.h"
#include "Player.h"
#include "SpaceGame.h"
#include "FrameWork/Scene.h"
#include <iostream>

void Enemy::OnCollision(Actor* other)
{
    if (dynamic_cast<Player*>(other)){

        m_game->AddPoints(100);

        if (hp <= 0) {
            m_destroyed = true;
        }
        else {
            hp -= 2;
        }
        

    }
}

void Enemy::Update(float dt) {

    Actor::Update(dt);
    
    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotations);
   Player* player = m_scene->getActor<Player>();

   if (player) {
       kiko::Vector2 direction = player->m_transform.position - m_transform.position;

       

       m_transform.rotations = direction.Angle() + kiko::halfPi;

      /* float angle = kiko::vec2::Angle(forward, direction.Normalize());
       if(angle < kiko::)*/
   }

    
    m_transform.position += forward * m_speed * kiko::g_time.GetDeltaTime();
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_ren.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_ren.GetHeight());

    std::cout << "2: " << m_transform.position.x << " - " << m_transform.position.y << std::endl;

}
