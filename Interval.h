#pragma once

struct Interval {
    long left;
    long right;
    Interval() { left = 0; right = 0; }
    Interval(const long& left_, const long& right_) : left(left_), right(right_) {}
};

