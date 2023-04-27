#pragma once
#include <iostream>
#include <map>

#include "ISolutional.h"
#include "Interval.h"
#include "persistentSegmentTree.h"

class PSTSolution : public ISolutional {
    struct Action {
        Interval interval;
        int action;
        Action() { action = 0; }
        Action(const int& left, const int& right, const int& inputAction) {
            interval.left = left;
            interval.right = right;
            action = inputAction;
        }
    };

    std::map<int, std::vector<Action>> actions;
    std::map<int, persistentSegmentTree> xToPST;
    std::map<int, int> bijectionY;

    int query(const Point& p);

    //creation utilities
    void formActionsAndBijections(const std::vector<Rectangle>& rectangles);
    void addBijection(const int& value);
    void addAction(const int& x, const int& left, const int& right, const int& action);
public:
    PSTSolution();
    void build(std::vector<Rectangle>* rectangles);
    void queries(const std::vector<Point>& points);
};

