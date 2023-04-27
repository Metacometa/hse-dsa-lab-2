#pragma once
#include "Point.h"
#include <algorithm>

struct Rectangle {
    Point leftBottom;
    Point rightTop;

    Rectangle(const int& left, const int& bottom, const int& right, const int& top) : leftBottom(left, bottom), rightTop(right,top) {}

    bool isPointInside(const Point& point) {
        return leftBottom.x <= point.x and leftBottom.y <= point.y and rightTop.x >= point.x and rightTop.y >= point.y;
    }

    int getLeft() const {
        return leftBottom.x;
    }

    int getRight() const {
        return rightTop.x;
    }

    int getBottom() const {
        return leftBottom.y;
    }

    int getTop() const {
        return rightTop.y;
    }

    Point getLeftBottom() const {
        return leftBottom;
    }

    Point getRightTop() const {
        return rightTop;
    }
};
