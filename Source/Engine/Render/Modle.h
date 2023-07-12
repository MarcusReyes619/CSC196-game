#pragma once
#include "Core/Core.h"
//#include "Core/Vector2.h"
#include "Render/Render.h"
#include <vector>

namespace kiko {

	class Modle {


	public:

		Modle() = default;
		Modle(std::vector<Vector2>& points) : m_points{ points } {};
		//Model(std::vector<vec2> points) { m_points = points; };
		//bool Load(const std::string& filename);

		void Draw(ren::Renderer& renderer, const vec2& position, float scale);

	private:

		std::vector<Vector2> m_points;

	};
	
}
