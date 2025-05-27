#include "tree.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

Tree::Tree() : root(nullptr) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

Tree::~Tree() {
    deleteTree(root);
}

void Tree::generateBalancedTree(int count) {
    deleteTree(root);
    std::vector<double> values(count);
    for (double &v : values)
        v = (std::rand() % 1000) / 10.0;

    root = buildBalancedTree(values, 0, count - 1);
}

TreeNode* Tree::buildBalancedTree(const std::vector<double>& values, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(values[mid]);
    node->left = buildBalancedTree(values, start, mid - 1);
    node->right = buildBalancedTree(values, mid + 1, end);
    return node;
}

void Tree::convertToBST() {
    std::vector<double> values;
    inorderTraversal(root, values);
    std::sort(values.begin(), values.end());
    deleteTree(root);
    root = buildBalancedTree(values, 0, values.size() - 1);
}

double Tree::findMax() const {
    TreeNode* curr = root;
    while (curr && curr->right) curr = curr->right;
    return curr ? curr->value : -1;
}

void Tree::inorderTraversal(TreeNode* node, std::vector<double>& out) const {
    if (!node) return;
    inorderTraversal(node->left, out);
    out.push_back(node->value);
    inorderTraversal(node->right, out);
}

void Tree::deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
