#include <iostream>
#include <chrono>
#include <thread>

// Just want a timer that counts up

using Time = std::chrono::steady_clock;
using secs = std::chrono::seconds;
using mins = std::chrono::minutes;
using hrs = std::chrono::hours;
using float_sec = std::chrono::duration<float>;
using float_time_point = std::chrono::time_point<Time, float_sec>;

int ONE_SECOND{ 1000 };

float_time_point getCurrentTime();

int main()
{
	auto startTime = getCurrentTime();
	std::cout << "Start Time: " << startTime.time_since_epoch().count() << '\n';

	while(true)
	{
		auto elapsedTime = getCurrentTime() - startTime;
		auto a = std::chrono::duration_cast<hrs>(elapsedTime);
		auto b = std::chrono::duration_cast<mins>(elapsedTime - a);
		auto c = std::chrono::duration_cast<secs>(elapsedTime - a - b);
		std::cout << a.count() << 'h' << b.count() << 'm' << c.count() << "s\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(ONE_SECOND));
	}

	return EXIT_SUCCESS;
}

float_time_point getCurrentTime()
{
	return Time::now();
}
