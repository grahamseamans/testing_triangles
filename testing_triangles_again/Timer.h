#pragma once

#include <chrono>
#include <thread>
#include <iostream>

class Timer
{
	using clk = std::chrono::steady_clock;

	clk::time_point b;
	clk::time_point e;

public:

	Timer();
	void clear();
	void start();
	void end();

	double secs() const;

	friend std::ostream& operator << (std::ostream& cout, const Timer& timer);
};
