#pragma once
#include "../Engine/Core/Core.h"
#include"../Engine/Render/Modle.h"
#include <memory>


namespace kiko {
	class Actor {
	public:
		Actor() = default;
		Actor(const kiko::Transform& transform, const  std::shared_ptr<kiko::Modle>& modle, std::string tag) :
			m_transform{ transform },
			m_model{ modle },
			m_tag{ tag }

		{}

		virtual void Update(float dt);
		virtual void Draw(kiko::Renderer& ren);

		float GetRadius() { return m_model->getRadius() * m_transform.scale; }
		virtual void OnCollision(Actor* other){}

		void addForces(const vec2& forces) { m_velocity = forces; }
		void setDamping(float damp) { m_damping = damp; }

		class Scene* m_scene = nullptr;
		friend class Scene;
		
		class Game* m_game = nullptr;

		kiko::Transform m_transform;
		std::string m_tag;

	protected:
		bool m_destroyed = false;
		float m_lifespan = -1.0f;
		float m_damping;
		vec2 m_velocity;

		std::shared_ptr<kiko::Modle>m_model;

	};

}