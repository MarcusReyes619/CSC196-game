#pragma once
#include "../Engine/Core/Core.h"
#include"../Engine/Render/Modle.h"

class Actor {
public:
	Actor() = default;
	Actor(const kiko:: Transform& transform, const kiko:: Modle& modle):
		m_transform{transform},
		m_modle{modle}
	{}
	virtual void Update(float dt) = 0;
	virtual void Draw(kiko::Renderer& ren);
	class Scene* m_scene = nullptr;
protected:
	kiko::Transform m_transform;
	kiko::Modle m_modle;

};
