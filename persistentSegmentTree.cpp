#include "persistentSegmentTree.h"

void persistentSegmentTree::createTree(std::shared_ptr<Node>& root, const int& left, const int& right) {
    if (left == right) {
        return;
    }

    int mid = left + (right - left) / 2;

    root->left = std::shared_ptr<Node>(new Node(0));
    root->right = std::shared_ptr<Node>(new Node(0));

    createTree(root->left, left, mid);
    createTree(root->right, mid + 1, right);
}

persistentSegmentTree::persistentSegmentTree() {}

persistentSegmentTree::persistentSegmentTree(const int& length) {
    right = length;
    root = std::shared_ptr<Node>(new Node(0));
    createTree(root, 0, length);
}

persistentSegmentTree::persistentSegmentTree(const persistentSegmentTree& source) {
    left = source.left;
    right = source.right;
    root = std::shared_ptr<Node>(new Node(*source.root));
}

std::shared_ptr<persistentSegmentTree::Node> persistentSegmentTree::update(std::shared_ptr<Node> root, 
    const int& left, const int& right, const Interval& subinterval, const int& value) {

    if (subinterval.right < left or right < subinterval.left) {
        return root;
    }
    std::shared_ptr<Node> new_root(new Node(*root));

    if (subinterval.left <= left and right <= subinterval.right) {
        new_root->value += value;
        return new_root;
    }

    int mid = left + (right - left) / 2;
    if (new_root->left) {
        new_root->left = update(new_root->left, left, mid, subinterval, value);
    }

    if (new_root->right) {
        new_root->right = update(new_root->right, mid + 1, right, subinterval, value);
    }

    return new_root;
}

int persistentSegmentTree::getSum(const int& target) {
    return getSumRecursively(root, target, left, right);
}

int persistentSegmentTree::getSumRecursively(std::shared_ptr<Node>& root, const int& target, const int& left, const int& right) {
    if (left == right) {
        return root->value;
    }

    int mid = left + (right - left) / 2;

    if (target <= mid) {
        return root->value + getSumRecursively(root->left, target, left, mid);
    }
    else {
        return root->value + getSumRecursively(root->right, target, mid + 1, right);
    }
}
