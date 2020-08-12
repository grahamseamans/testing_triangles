// testing_triangles_again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


bool is_triangle()
{
    // double points[4];
    double distances[3];
    // points[0] = 0.0;
    // points[3] = 1.0;
   
    double a = rand() / double(RAND_MAX);
    double b = rand() / double(RAND_MAX);

    // std::cout << "a: " << a << " " << " b: " << b << std::endl;

    double smaller = a * (a < b) + b * (b < a);
    double larger = a * (a > b) + b * (b > a);

    distances[0] = smaller - 0;
    distances[1] = larger - smaller;
    distances[2] = 1 - larger;

    /*
 
    points[1] = a * (a < b) + b * (b < a);
    points[2] = a * (a > b) + b * (b > a);

    distances[0] = points[1] - points[0];
    distances[1] = points[2] - points[1];
    distances[2] = points[3] - points[2];

    std::cout << "distances: " << distances[0] << " " << distances[1] << " " << distances[2] << std::endl;

    bool test[3];
    test[0] = (distances[0] > 0.5);
    test[1] = (distances[1] > 0.5);
    test[2] = (distances[2] > 0.5);

    std::cout << "test: " << test[0] << " " << test[1] << " " << test[2] << std::endl;
    */

    return !((distances[0] > 0.5) + (distances[1] > 0.5) + (distances[2] > 0.5));
    // return max < .5
}


int main()
{

    int reps = 10000000;
    int triangles = 0;

    for (int i = 0; i < reps; ++i)
    {
        triangles += is_triangle();
        //std::cout << "is it a triange? " << is_triangle() << std::endl;
    }

    std::cout << triangles / double(reps);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
