#pragma once
#include "Vector2.h"

namespace kiko {

	class Transform {
	public:
		vec2 position;
		float rotations;
		float scale =1;

	public:
		Transform(const vec2& position, float rot, float scale = 1) :
			position{ position },
			rotations{ rot },
			scale{ scale }{}
		Transform() = default;

	};
}
