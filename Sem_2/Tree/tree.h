#ifndef TREE_H
#define TREE_H

#include <vector>

struct TreeNode {
    double value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(double v) : value(v), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Tree();
    ~Tree();

    void generateBalancedTree(int count);
    void convertToBST();
    double findMax() const;
    TreeNode* getRoot() const { return root; }

private:
    TreeNode* root;
    TreeNode* buildBalancedTree(const std::vector<double>& values, int start, int end);
    void inorderTraversal(TreeNode* node, std::vector<double>& out) const;
    void deleteTree(TreeNode* node);
};

#endif // TREE_H
