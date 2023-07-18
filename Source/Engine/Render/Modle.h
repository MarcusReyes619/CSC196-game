#pragma once
#include "Core/Core.h"
#include "Render/Render.h"
#include <vector>

namespace kiko {

	class Modle {


	public:

		Modle() = default;
		Modle(std::vector<Vector2>& points) : m_points{ points } {};
		//Model(std::vector<vec2> points) { m_points = points; };
		bool Load(const std::string& filename);

		void Draw(kiko::Renderer& renderer, const vec2& position,float rotation, float scale);
		void Draw(kiko::Renderer& renderer, const kiko::Transform& trans);

	private:

		std::vector<Vector2> m_points;

	};
	
}
