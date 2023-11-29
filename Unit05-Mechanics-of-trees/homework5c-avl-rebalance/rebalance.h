#pragma once
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
int getHeight(Node *n) {
    if (n == nullptr) {
        return -1;
    }
    return n->height;
}

void updateHeight(Node*& root) {
    //update the height of the node passed in
    int rootMax = max(getHeight(root->left), getHeight(root->right));
    root->height = rootMax + 1;
}


void promote_left(Node*& root) { //this is rotate right
    // implement promote_left here
}

void promote_right(Node*& root) { //this is rotate left
    // implement promote_right here
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root = newRoot;
    updateHeight(newRoot->left);
    updateHeight(newRoot);
    //have not changed the heights yet so you still  need to do that
}

void rebalance(Node*& root) {
    // implement rebalance here
}
