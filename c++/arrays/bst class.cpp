#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        }

        if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    void inorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        inorderTraversalRecursive(current->left);
        std::cout << current->data << " ";
        inorderTraversalRecursive(current->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;

    // Insert some values
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform in-order traversal
    std::cout << "In-order traversal: ";
    bst.inorderTraversal();

    // Search for values
    std::cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;

    return 0;
}