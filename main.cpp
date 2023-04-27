#include <iostream>
#include <fstream>
#include "AlgorithmTesting.h"

int main()
{
    AlgorithmTesting test;
    std::vector<Rectangle> rectangles;
    std::vector<Point> points;

    std::ofstream file("measurements.txt");

    int n = 1;
    int max_n = 1000;

    MapSolution m;
    for (int i = n; i < max_n; i+=20) {
        file << i << " ";
        std::cout << i << " ";

        rectangles = AlgorithmTesting::generateRectangles(i);
        points = AlgorithmTesting::generatePoints(i);

        test.measureSpeed(file, rectangles, points);  
    }
 
    file.close();
}

