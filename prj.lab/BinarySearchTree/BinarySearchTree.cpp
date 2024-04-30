#include "BinarySearchTree.hpp"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear(root_);
}

void BinarySearchTree::clear(TreeNode* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

TreeNode* BinarySearchTree::getRoot() {
    return root_;
}

void BinarySearchTree::add(int data) {
    TreeNode* newNode = new TreeNode(data);
    if (root_ == nullptr) {
        root_ = newNode;
    } else {
        TreeNode* current = root_;
        while (true) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

bool BinarySearchTree::has(int data) {
    return find(data) != nullptr;
}

TreeNode* BinarySearchTree::find(int data) {
    TreeNode* current = root_;
    while (current != nullptr) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

void BinarySearchTree::remove(int data) {
    root_ = removeNode(root_, data);
}

TreeNode* BinarySearchTree::removeNode(TreeNode* root, int data) {
    if (root == nullptr) return root;
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    } else if (data > root->data) {
        root->right = removeNode(root->right, data);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

TreeNode* BinarySearchTree::findMinNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

int BinarySearchTree::min() {
    TreeNode* node = findMinNode(root_);
    if (node == nullptr) throw std::runtime_error("The tree is empty.");
    return node->data;
}

int BinarySearchTree::max() {
    TreeNode* current = root_;
    if (current == nullptr) throw std::runtime_error("The tree is empty.");
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}
