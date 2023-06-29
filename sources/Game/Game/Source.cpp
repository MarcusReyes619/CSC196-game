#include <iostream>
#include "../../Engine/Core//random.h"
#include "../../Engine/Core//FileIO.h"
#include "../../Engine/Core/memeory.h"

#include "../../Engine/Core/Time.h"
#include"../../Engine/Render/Render.h"
using namespace std;



int main() {
	kiko::g_memoryTracker.DisplayInfo();

	int* p = new int;
	kiko::g_memoryTracker.DisplayInfo();

	delete p;
	kiko::g_memoryTracker.DisplayInfo();

	auto i = true;

	//useing a timer in nano secs
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++)
	{}
	auto end = std::chrono::high_resolution_clock::now();

	cout << 

	
	
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


}