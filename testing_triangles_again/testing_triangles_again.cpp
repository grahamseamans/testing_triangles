// Graham Seamans

#include <iostream>
#include "Timer.h"

bool is_triangle()
{
	double distances[3];

	double a = rand() / double(RAND_MAX);
	double b = rand() / double(RAND_MAX);

	// double smaller = a * (a < b) + b * (b < a);
	// double larger = a * (a > b) + b * (b > a);

	// literally the same runtime with this :(
	// these compilers are speedy, guess I should just go for readability...

	double smaller, larger;
	if (a < b)
	{
		smaller = a;
		larger = b;
	}
	else
	{
		larger = a;
		smaller = b;
	}

	distances[0] = smaller - 0;
	distances[1] = larger - smaller;
	distances[2] = 1 - larger;

	return !((distances[0] > 0.5) + (distances[1] > 0.5) + (distances[2] > 0.5));
}

int main()
{
	int reps = 10000000;
	int triangles = 0;
	Timer t;

	t.start();

	for (int i = 0; i < reps; ++i)
	{
		triangles += is_triangle();
	}

	t.end();

	std::cout << "It took: " << t << " to find that the probability is: " << triangles / (double)reps;

	return 1;
}