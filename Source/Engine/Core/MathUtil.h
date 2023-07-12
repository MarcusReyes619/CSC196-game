#pragma once
#include <cmath>

namespace kiko {
	constexpr float pi = 3.14159265359;
	constexpr float twoPi = 3.14159265359 * 2;
	constexpr float halfPi = 1.57079632679;

	constexpr float radiansToDegrees(float rad) { return rad * (180.0f / pi); }
	constexpr float degreesToRadians(float deg) { return deg * (pi / 180.0f); }

	constexpr int Wrap(int value, int max) { return (value % max) + ((value < 0) ? max : 0); }
	inline float Wrap(float value, float max) { return std::fmod(value, max) + ((value < 0) ? max : 0); }
	inline float Wrap(float value, int max) { return Wrap(value, (float)max); }
	inline float Wrap(int value, float max) {
		return Wrap((float)value, max);

	}

	template <typename T>

	inline T max(T a, T b) {
		return (a > b) ? a : b;
	}
	template <typename T>

	inline T min(T a, T b) {
		return (a > b) ? a : b;
	}
	template <typename T>
	inline T Clamp(T value, T min, T max) {

		if (min > max) std::swap(min, max);
		return (value < min) ? min : (value > max) ? max : value;

	}
	

}