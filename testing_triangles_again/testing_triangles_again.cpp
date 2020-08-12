// Graham Seamans

#include <iostream>


bool is_triangle()
{
    double distances[3];
   
    double a = rand() / double(RAND_MAX);
    double b = rand() / double(RAND_MAX);

    double smaller = a * (a < b) + b * (b < a);
    double larger = a * (a > b) + b * (b > a);

    distances[0] = smaller - 0;
    distances[1] = larger - smaller;
    distances[2] = 1 - larger;

    return !((distances[0] > 0.5) + (distances[1] > 0.5) + (distances[2] > 0.5));
}


int main()
{

    int reps = 10000000;
    int triangles = 0;

    for (int i = 0; i < reps; ++i)
    {
        triangles += is_triangle();
    }

    std::cout << triangles / double(reps);
}
