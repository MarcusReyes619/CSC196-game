#pragma once
#include "Actors.h"
#include <list>

namespace kiko {
	class Renderer;

	class Scene {

	public:
		Scene() = default;
		
		void Update(float dt);
		void Draw(kiko::Renderer& ren);

		void addActor(std::unique_ptr<Actor> actor);
		
		void removeAll();

		template <typename t>
		t* getActor();

		friend class Actor;

	private:
		std::list <std::unique_ptr<Actor>> m_actors;	

	};

	template <typename t>
	inline t* Scene::getActor() {
		for (auto& actor : m_actors) {
			t* result = dynamic_cast <t*>(actor.get());

			if (result) return result;
		}

		return nullptr;
	}

}
