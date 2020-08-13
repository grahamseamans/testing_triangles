// Graham Seamans

#include <chrono>
#include <iostream>

class Timer
{
	using clk = std::chrono::steady_clock;
public:
	Timer();
	void clear();
	void start();
	void end();
	double secs() const;
	friend std::ostream& operator << (std::ostream& cout, const Timer& timer);
protected:
	clk::time_point b;
	clk::time_point e;
};
