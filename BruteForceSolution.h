#pragma once

#include <iostream>
#include "ISolutional.h"

class BruteForceSolution : public ISolutional {
    void query(const Point& point);
public:
    std::vector<Rectangle>* rectangles = nullptr;

    BruteForceSolution();

    virtual void build(std::vector<Rectangle>* rectangles);

    void queries(const std::vector<Point>& points);
};

