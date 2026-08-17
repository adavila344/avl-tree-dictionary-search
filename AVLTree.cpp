#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(Node* n) {
    return n ? n->height : 0;
}

int AVLTree::balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

AVLTree::Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLTree::Node* AVLTree::insert(Node* node, const string& key) {
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(const string& key) {
    root = insert(root, key);
}

int AVLTree::search(const string& key) {
    Node* current = root;
    int comparisons = 0;

    while (current) {
        comparisons++;
        if (key == current->key)
            return comparisons;
        else if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    return -comparisons; // not found
}

