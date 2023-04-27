#pragma once
#include <vector>
#include "Rectangle.h"
class ISolutional {
public:
	virtual void build(std::vector<Rectangle>* rectangles) = 0;
	virtual void queries(const std::vector<Point>& points) = 0;
};

