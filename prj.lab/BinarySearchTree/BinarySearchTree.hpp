#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    TreeNode* getRoot();
    void add(int data);
    bool has(int data);
    TreeNode* find(int data);
    void remove(int data);
    int min();
    int max();

private:
    TreeNode* root_;
    TreeNode* removeNode(TreeNode* root, int data);
    TreeNode* findMinNode(TreeNode* node);
    void clear(TreeNode* node);
};

#endif // BINARY_SEARCH_TREE_HPP
