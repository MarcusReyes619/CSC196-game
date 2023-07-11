#pragma once

namespace kiko {
	class Vector2 {
	public:
		float x, y;

	public:
		Vector2() : x{ 0 } ,y{0} { x = 0; y = 0; }
		Vector2(float v) :x{ v }, y{ v } {}
		Vector2(float x, float y) : x{x}, y{y} {}
		Vector2(int x, int y): x{(float)x}, y{(float)y} {}
		
		Vector2 operator +(const Vector2& v)const { return Vector2(x + v.x, y + v.y); }
		Vector2 operator -(const Vector2& v)const { return Vector2(x - v.x, y - v.y); }
		Vector2 operator /(const Vector2& v)const { return Vector2(x / v.x, y / v.y); }
		Vector2 operator *(const Vector2& v)const { return Vector2(x * v.x, y * v.y); }

		Vector2 operator *(float s)const { return Vector2(x * s, y * s); }
		Vector2 operator +(float s)const { return Vector2(x + s, y + s); }
		Vector2 operator -(float s)const { return Vector2(x - s, y - s); }
		Vector2 operator /(float s)const { return Vector2(x / s, y / s); }
		
		Vector2& operator +=(const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator *=(const Vector2& v) { x *= v.x; y *= v.y; return *this; }
		Vector2& operator /=(const Vector2& v) { x /= v.x; y /= v.y; return *this; }


		float LongthSqu() { return (x * x) + (y * y); }
		float Length() { return sqrt(LongthSqu()); }

		Vector2 Normalized() { return *this/Length(); }

		void Normalize() { *this /= Length(); }
		
		
	};

	using vec2 = Vector2;
}
//Severity	Code	Description	Project	File	Line	Suppression State
//rror	LNK2019	unresolved external symbol SDL_main referenced in function main_getcmdline	Game(Game\Game)	C:\Users\mreyes\source\repos\CSC196 - game\Source\Game\Game\Render.lib(SDL_windows_main.obj)	1
