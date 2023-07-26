#include "weapon.h"

void Weapon::Update(float dt)
{
	Actor::Update(dt);



    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotations);
    m_transform.position += forward * m_speed * kiko::g_time.GetDeltaTime();
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_ren.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_ren.GetHeight());


}

void Weapon::OnCollision(Actor* other)
{
    m_destroyed = true;
}
