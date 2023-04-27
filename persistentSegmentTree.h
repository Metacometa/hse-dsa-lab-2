#pragma once
#include <memory>
#include "Interval.h"

class persistentSegmentTree {
    struct Node {
        int value = 0;
        std::shared_ptr<Node> left = {};
        std::shared_ptr<Node> right = {};
        Node() {}
        Node(const int& value_) : value(value_) {}
        ~Node() {}
    };

    void createTree(std::shared_ptr<Node>& root, const int& left, const int& right);

public:
    std::shared_ptr<Node> root = {};
    int left = 0;
    int right = 0;

    persistentSegmentTree();
    persistentSegmentTree(const int& length);

    persistentSegmentTree(const persistentSegmentTree& source); 

    static std::shared_ptr<Node> update(std::shared_ptr<Node> root, const int& left, const int& right, const Interval& subinterval, const int& value);

    int getSum(const int& target);

    int getSumRecursively(std::shared_ptr<Node>& root, const int& target, const int& left, const int& right);

};
