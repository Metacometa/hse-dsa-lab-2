#pragma once
#include <iostream>
#include <map>

#include "ISolutional.h"

class MapSolution : public ISolutional {
    std::map<int, int> bijectionX;
    std::map<int, int> bijectionY;
    std::vector<std::vector<int>> map;

    //bijections 
    void defineBijections(const std::vector<Rectangle>& rectangles);
    void setCorrectBijections(std::map<int, int>& bijection);
    int getClosestBijection(std::map<int, int>& bijection, const int &bijectionFrom);

    //building
    void addPointToMap(int coord, std::map<int, int>& m);
    void fillMap(const std::vector<Rectangle>& rectangles);

    int query(const Point& p);
public:
    MapSolution();
    void build(std::vector<Rectangle>* rectangles);
    void queries(const std::vector<Point>& points);
};

