#include "Actors.h"


void Actor::Draw(ren::Renderer& ren)
{
	m_modle.Draw(ren,m_transform);
}
