#pragma once
#include <string>
#include <../ThirdParty/SDL2-2.28.1/include/SDL.h>

namespace kiko
{
	class Renderer {
		
	public:
		Renderer() = default;
		~Renderer() = default;

		bool Initialize();
		void shutDown();

		void CreateWindow(const std::string& title, int width, int height);
		void BeginFrane();
		void EndFrame();

		void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
		void DrawLine(int x1, int y1, int x2, int y2);
		void DrawPoint(int x, int y);

		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

		SDL_Renderer* m_renderer = nullptr;

	private:
		int m_width = 0;
		int m_height = 0;

		SDL_Window* m_window = nullptr;
	};

	extern Renderer g_ren;
}