#include "MapSolution.h"

MapSolution::MapSolution() {}

void MapSolution::defineBijections(const std::vector<Rectangle>& rectangles) {
    for (auto& i : rectangles) {
        Point leftBottom = i.getLeftBottom();
        Point rightTop = i.getRightTop();

        addPointToMap(leftBottom.x, bijectionX);
        addPointToMap(rightTop.x, bijectionX);
        addPointToMap(rightTop.x + 1, bijectionX);

        addPointToMap(leftBottom.y, bijectionY);
        addPointToMap(rightTop.y, bijectionY);
        addPointToMap(rightTop.y + 1, bijectionY);
    }
    setCorrectBijections(bijectionX);
    setCorrectBijections(bijectionY);
}

void MapSolution::setCorrectBijections(std::map<int, int>& bijection) {
    int bijectionValue = 0;
    for (auto& i : bijection) {
        i.second = bijectionValue;
        bijectionValue++;
    }
}

int MapSolution::getClosestBijection(std::map<int, int>& bijection, const int& bijectionFrom) {
    std::map<int, int>::iterator bijectionTo = bijection.upper_bound(bijectionFrom);
    bijectionTo--;
    return bijectionTo->second;
}

void MapSolution::addPointToMap(int coord, std::map<int, int>& m) {
    if (m.find(coord) == m.end()) {
        m[coord] = m.size();
    }
}

void MapSolution::fillMap(const std::vector<Rectangle>& rectangles) {
    for (auto& i : rectangles) {
        Point leftDownAngle(getClosestBijection(bijectionX, i.getLeftBottom().x), getClosestBijection(bijectionY, i.getLeftBottom().y));
        Point rightTopAngle(getClosestBijection(bijectionX, i.getRightTop().x), getClosestBijection(bijectionY, i.getRightTop().y));

        for (int x = leftDownAngle.x; x <= rightTopAngle.x; ++x) {

            for (int y = leftDownAngle.y; y <= rightTopAngle.y; ++y) {
                map[x][y]++;
            }
        }
    }
}

int MapSolution::query(const Point& p) {
    if (p.x < bijectionX.begin()->first or p.y < bijectionY.begin()->first) {
        return 0;
    }

    int closestX = getClosestBijection(bijectionX, p.x);
    int closestY = getClosestBijection(bijectionY, p.y);

    return map[closestX][closestY];
}

void MapSolution::build(std::vector<Rectangle>* rectangles) {
    defineBijections(*rectangles);


    map.resize(bijectionX.size());
    for (auto& i : map) {
        i.resize(bijectionY.size());
    }

    fillMap(*rectangles);
}

void MapSolution::queries(const std::vector<Point>& points) {
    for (auto& i : points) {
        query(i);
        //std::cout << query(i) << " ";
    }
    //std::cout << std::endl;
}
