#include "Enemy.h"
#include <iostream>

void Enemy::Update(float dt) {

    std::cout << "1: " << m_transform.position.x << " - " << m_transform.position.y << std::endl;

    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotations);
    m_transform.position += forward * m_speed * kiko::g_time.GetDeltaTime();
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_ren.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_ren.GetHeight());

    std::cout << "2: " << m_transform.position.x << " - " << m_transform.position.y << std::endl;

}
