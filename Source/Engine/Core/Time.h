#pragma once
#include <chrono>

namespace kiko
{
	class Time
	{
	private:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_rep = clock::rep;

	public:
		Time() :
			m_startTime{ clock::now() },
			m_frameTime{
			clock::now()
			}
		{}

		void Tick();

		void Reset() { m_startTime = clock::now(); }

		clock_rep GetElapsedNanoseconds();
		clock_rep GetElapsedMicroseconds();
		clock_rep GetElapsedMilliseconds();
		float GetElapsedSeconds();

		float GetTime() const { return m_time; }
		float GetDeltaTime() const { return m_deltaTime * m_time_scale; }
		float getUnscaledDeltaTime()const { return m_deltaTime; }
		
		float getTimeScale()const { return m_time_scale; }
		void setTimeScale(float time){ m_time_scale = time; }

	private:
		clock::time_point m_startTime;
		clock::time_point m_frameTime;

		float m_time;
		float m_time_scale = 1;
		float m_deltaTime;
};

	extern Time g_time;
}