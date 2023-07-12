#include <iostream>

#include "../Engine/Core/Core.h"
#include "../Engine/Input/InputSystem.h"
#include "Render/Modle.h"

using namespace std;

class Star {
public:
	kiko::Vector2 m_pos;
	kiko::Vector2 m_vel;
	
	Star(const kiko:: Vector2& pos, const kiko :: Vector2& vel):
		m_pos{pos},
		m_vel{vel}
	{}

	void Update(int width, int height) {
		m_pos += m_vel;
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;

	}

	void Draw(ren::Renderer& renderer) {
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}
};


int main(int argc, char* argv[]) {
	ren::Renderer ren;


	kiko::seedRandom((unsigned int)time(nullptr));

	ren.Initialize();
	ren.CreateWindow("YES SIR", 800, 600);

	//std::vector <kiko::vec2> points{ {-10,5},{10,5},{0,-5},{-10,5} };
	//kiko::Modle modle {points};

	/*while (true) {
		ren.SetColor(0, 0, 0, 0);
		ren.BeginFrane();
		ren.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), kiko::random(256));
		modle.Draw(ren, kiko::Vector2{ 200,200 }, 3.0f);
	}*/


	

	

	
	/*ren::Renderer ree;
	ree.Initialize();
	ree.CreateWindow("cs190", 800, 600);
	std::vector<kiko::vec2>points;*/

	/*ren::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);
	kiko::InputSystem inputSystem;
	inputSystem.Initialize();*/


	//kiko::vec2 position(400, 300);


	//iputs

	/*ren::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);
	kiko::InputSystem inputSystem;
	inputSystem.Initialize();
	

	bool quit = false;
	while (!quit)
	{
		


		inputSystem.Update();
		if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			

			quit = true;
		}


		if (inputSystem.GetMouseButtonDown(0) || inputSystem.GetMouseButtonDown(1) || inputSystem.GetMouseButtonDown(2)) {
			std::cout << "reee";
			

		}
		

		ren.EndFrame();
	}*/

	
	




	//STARS
	
	//kiko::vec2 v{ 5,5 };
	//v.Normalize();

	//ren::Renderer render;

	//render.Initialize();
	//render.CreateWindow("CS196",800,600);
	//vector<kiko::Vector2> points;
	//vector<Star> stars;
	//
	//for (int i = 0; i < 1000; i++)
	//{
	//	kiko::Vector2 pos(kiko::Vector2(kiko::random(render.GetWidth()), kiko::random(render.GetHeight())));
	//	kiko::Vector2 vel(kiko::randomf(1.0f, 4.0f), 0.0f);
	//	stars.push_back(Star(pos, vel));

	//}
	//
	//while (true) {
	//	render.SetColor(0, 0, 0, 0);
	//	render.BeginFrane();
	//	//draw
	//	for (auto& star : stars) {
	//		star.Update(render.GetWidth(), render.GetHeight());
	//		render.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
	//		star.Draw(render);
	//	}
	//	render.EndFrame();

	//}









	/*kiko::seedRandom((unsigned int)time(nullptr));

	cout << kiko::randomf(20, 30) << endl;

	
	cin.get();

	cout << kiko::randomf() << endl;

	for (int i = 0; i < 1000; i++) {
		kiko::Vector2 pos(kiko::randomf());
	}*/

	//for(int i=1; i <= 10; i++) cout (1)


	//kiko::g_memoryTracker.DisplayInfo();

	//int* p = new int;
	//kiko::g_memoryTracker.DisplayInfo();

	//delete p;
	//kiko::g_memoryTracker.DisplayInfo();

	//auto i = true;

	////useing a timer in nano secs
	//auto start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 10000000; i++)
	//{}
	//auto end = std::chrono::high_resolution_clock::now();

	//cout << 

	
	
	/*

	cout << kiko::getFilePath() << endl;
	kiko::setFilePath("Assets");
	cout << kiko::getFilePath << endl;
	size_t size = 0;
	kiko::getFileSize("GameData.txt", size);
	cout << size;

	std::string s;
	kiko::readFile("GameData.txt", s);
	cout << s << endl;
	


	kiko::seedRandom(time(nullptr));
	for (int i = 0; i < 20; i++) {
		cout << kiko::random(10,20) << endl;
	}*/

	return 0;
}