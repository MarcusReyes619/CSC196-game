#pragma once
#include "Actors.h"
#include <list>

namespace kiko {
	class Renderer;

	class Scene {

	public:
		Scene() = default;
		
		void upDate(float dt);
		void Draw(kiko::Renderer& ren);

		void addActor(Actor* actor);
		void removeActor(Actor* actor);
		void removeAll();
		friend class Actor;

	private:
		std::list <Actor*> m_actors;


	};

}
