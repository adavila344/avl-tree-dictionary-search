#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

class AVLTree {
private:
    struct Node {
        std::string key;
        Node* left;
        Node* right;
        int height;
        Node(const std::string& k)
                : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* n);
    int balanceFactor(Node* n);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, const std::string& key);

public:
    AVLTree();
    void insert(const std::string& key);


    int search(const std::string& key);
};

#endif
