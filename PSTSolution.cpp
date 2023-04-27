#include "PSTSolution.h"

PSTSolution::PSTSolution() {}

int PSTSolution::query(const Point& p) {
    if (p.x < xToPST.begin()->first or p.y < bijectionY.begin()->second) {
        return 0;
    }

    auto closestX = xToPST.upper_bound(p.x);
    closestX--;

    auto closestY = bijectionY.upper_bound(p.y);
    closestY--;

    return xToPST[closestX->first].getSum(closestY->second);
}

//creation utilities
void PSTSolution::formActionsAndBijections(const std::vector<Rectangle>& rectangles) {
    int counterY = 0;

    for (auto& i : rectangles) {
        addBijection(i.getBottom());
        addBijection(i.getTop());
        addBijection(i.getTop() + 1);

    }

    for (auto& i : bijectionY) {
        i.second = counterY++;
    }

    for (auto& i : rectangles) {
        addAction(i.getLeft(), bijectionY[i.getBottom()], bijectionY[i.getTop()], 1);
        addAction(i.getRight() + 1, bijectionY[i.getBottom()], bijectionY[i.getTop()], -1);
    }
}

void PSTSolution::addBijection(const int& value) {
    if (bijectionY.find(value) == bijectionY.end()) {
        bijectionY[value] = value;
    }
}

void PSTSolution::addAction(const int& x, const int& left, const int& right, const int& action) {
    if (actions.find(x) == actions.end()) {
        actions[x] = std::vector<Action>(0);
    }

    actions[x].emplace_back(left, right, action);
}

void PSTSolution::build(std::vector<Rectangle>* rectangles) {
    formActionsAndBijections(*rectangles);
    int PSTSize = 1;
    if (bijectionY.size()) {
        PSTSize = bijectionY.size() - 1;
    }

    persistentSegmentTree emptyPST(PSTSize);

    auto lastPST = xToPST.end();

    for (auto& x : actions) {
        if (lastPST == xToPST.end()) {
            xToPST.emplace(x.first, emptyPST);
        }
        else {
            xToPST.emplace(x.first, lastPST->second);
        }

        for (auto& actionsVector : x.second) {
            xToPST[x.first].root = persistentSegmentTree::update(xToPST[x.first].root, xToPST[x.first].left, xToPST[x.first].right,
                actionsVector.interval, actionsVector.action);
        }

        lastPST = xToPST.find(x.first);
    }

    actions.clear();
}

void PSTSolution::queries(const std::vector<Point>& points) {
    for (auto& i : points) {
        query(i);
        //std::cout << query(i) << " ";
    }
    //std::cout << std::endl;
}
