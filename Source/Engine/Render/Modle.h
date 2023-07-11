#pragma once
#include "Core/Core.h"
#include <vector>
namespace kiko {

	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2>& points): m_points{points} {}
		void Draw(ren::Renderer& renderer, const vec2& posistion, float scale);

	private:
		std::vector<vec2> m_points;
		
	};
}
