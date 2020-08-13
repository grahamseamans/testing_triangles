#include "Timer.h"

Timer::Timer()
{
	clear();
}

void Timer::clear()
{
	b = e = clk::now();
}

void Timer::start()
{
	b = clk::now();
}

void Timer::end()
{
	e = clk::now();
}

double Timer::secs() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(e - b).count();
}

std::ostream& operator << (std::ostream& o, const Timer& timer)
{
	return o << timer.secs() << " ms";
}
