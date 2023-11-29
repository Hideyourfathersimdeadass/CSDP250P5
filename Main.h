//Kaleigha Hayes
//1313037
//11/29/2023
//Project 5
//Main cpp

#include "BinarySearchTree.h"
#include <iostream>


int main() {
    const int size = 35;
    int numbers[size] = {
        23, 45, 12, 67, 89, 34, 56, 78, 90, 12,
        43, 65, 87, 23, 78, 45, 67, 89, 34, 56,
        78, 90, 12, 43, 65, 87, 23, 78, 45, 67,
        89, 34, 56, 78, 90
    };

    BinarySearchTree bst;

    // Insert numbers into the binary search tree
    for (int i = 0; i < size; ++i) {
        bst.insert(numbers[i]);
    }

    // Display the binary search tree with inorder DFS
    std::cout << "Binary Search Tree (Inorder DFS): ";
    bst.displayInorder();
    std::cout << std::endl;

    // Prompt user to delete a node
    int valueToDelete;
    std::cout << "Enter a value to delete from the tree: ";
    std::cin >> valueToDelete;
    bst.remove(valueToDelete);

    // Display the updated tree with postorder DFS
    std::cout << "Updated Tree (Postorder DFS): ";
    bst.displayPostorder();
    std::cout << std::endl;

    // Test if the tree is AVL
    if (bst.isAVL()) {
        std::cout << "The tree is an AVL tree." << std::endl;
    }
    else {
        std::cout << "The tree is not an AVL tree." << std::endl;
    }

    return 0;
}
