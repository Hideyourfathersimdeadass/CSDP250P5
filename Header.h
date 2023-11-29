//Kaleigha Hayes
//1313037
//11/25/2023
//Project 5
//Header
#include "BinarySearchTree.h"
#include <iostream>

// Private helper functions for tree operations

// Insert a value into the tree
void BinarySearchTree::insert(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    }
    else if (value < node->data) {
        insert(node->left, value);
    }
    else if (value > node->data) {
        insert(node->right, value);
    }
    // Note: if value is equal to node->data, it is ignored (assuming no duplicates).
}

// Display the tree with inorder DFS
void BinarySearchTree::displayInorder(Node* node) const {
    if (node != nullptr) {
        displayInorder(node->left);
        std::cout << node->data << " ";
        displayInorder(node->right);
    }
}

// Display the tree with postorder DFS
void BinarySearchTree::displayPostorder(Node* node) const {
    if (node != nullptr) {
        displayPostorder(node->left);
        displayPostorder(node->right);
        std::cout << node->data << " ";
    }
}

// Remove a value from the tree
void BinarySearchTree::remove(Node*& node, int value) {
    if (node == nullptr) {
        return;
    }
    else if (value < node->data) {
        remove(node->left, value);
    }
    else if (value > node->data) {
        remove(node->right, value);
    }
    else {
        // Node to delete found
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            node = temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            node = temp;
        }
        else {
            // Node has two children
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->data = successor->data;
            remove(node->right, successor->data);
        }
    }
}

// Check if the tree is AVL
bool BinarySearchTree::isAVL(Node* node) const {
    if (node == nullptr) {
        return true;
    }

    int balance = balanceFactor(node);

    return (std::abs(balance) <= 1) && isAVL(node->left) && isAVL(node->right);
}

// Get the height of a node
int BinarySearchTree::height(Node* node) const {
    return (node == nullptr) ? 0 : node->data;
}

// Calculate the balance factor of a node
int BinarySearchTree::balanceFactor(Node* node) const {
    return height(node->left) - height(node->right);
}

// Update the height of a node
void BinarySearchTree::updateHeight(Node* node) {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->data = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Public member functions for the BinarySearchTree class

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    // Implement code to deallocate memory for the nodes (use a postorder traversal)
}

// Insert a value into the tree
void BinarySearchTree::insert(int value) {
    insert(root, value);
}

// Display the tree with inorder DFS
void BinarySearchTree::displayInorder() const {
    displayInorder(root);
    std::cout << std::endl;
}

// Display the tree with postorder DFS
void BinarySearchTree::displayPostorder() const {
    displayPostorder(root);
    std::cout << std::endl;
}

// Remove a value from the tree
void BinarySearchTree::remove(int value) {
    remove(root, value);
}

// Check if the tree is AVL
bool BinarySearchTree::isAVL() const {
    return isAVL(root);
}
