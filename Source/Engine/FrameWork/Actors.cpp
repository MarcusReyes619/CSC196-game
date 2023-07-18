#include "Actors.h"


void Actor::Draw(kiko::Renderer& ren)
{
	m_modle.Draw(ren,m_transform);
}
