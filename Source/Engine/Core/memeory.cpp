#include "memeory.h"
#include <iostream>
using namespace std;

kiko::MemoryTracker kiko::g_memoryTracker;


void* operator new (size_t size) {
	cout << "allocated: " << size << endl;

	void* p = malloc(size);

	kiko::g_memoryTracker.Add(p, size);

	return p;
}
void operator delete(void* address, size_t size) {
	cout << "deallacoted: " << size << endl;
	kiko::g_memoryTracker.remove(address,size);


	//lower level delete function
	free(address);
}




	void kiko::MemoryTracker::Add(void* address, size_t size)
{
		m_bytesAllocated += size;
		m_numAllocations++;
}

void kiko::MemoryTracker::remove(void* address, size_t size)
{
	m_bytesAllocated -= size;
	m_numAllocations--;
}


void kiko::MemoryTracker::DisplayInfo()
{
}
