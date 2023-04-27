#pragma once

struct Point {
    long x;
    long y;
    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(long x, long y) {
        this->x = x;
        this->y = y;
    }
};

