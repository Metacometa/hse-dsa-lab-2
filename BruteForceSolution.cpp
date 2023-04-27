#include "BruteForceSolution.h"

BruteForceSolution::BruteForceSolution() {}

void BruteForceSolution::build(std::vector<Rectangle>* rectangles) {
    this->rectangles = rectangles;
}

void BruteForceSolution::queries(const std::vector<Point>& points) {
    for (auto& i : points) {
        query(i);
    }
    //std::cout << std::endl;
}

void BruteForceSolution::query(const Point& point) {
    int counter = 0;

    for (auto& i : *rectangles) {
        if (i.isPointInside(point))
            counter++;
    }

    //std::cout << counter << " ";
}
