//Kaleigha Hayes
//1313037
//11/29/2023
//Project 5
//Class

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Private helper functions for tree operations
    void insert(Node*& node, int value);
    void displayInorder(Node* node) const;
    void displayPostorder(Node* node) const;
    void remove(Node*& node, int value);
    bool isAVL(Node* node) const;
    int height(Node* node) const;
    int balanceFactor(Node* node) const;
    void updateHeight(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    void displayInorder() const;
    void displayPostorder() const;
    void remove(int value);
    bool isAVL() const;
};

#endif // BINARYSEARCHTREE_H
