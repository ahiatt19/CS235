#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    Node* root;
    int treeSize;

    BST() : root(nullptr), treeSize(0) {}

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return root;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
        if (!contains(item)) {
            root = insertRecursive(root, item);
            treeSize++;
            return true;
        }
        return false;
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        if (contains(item)) {
            root = removeRecursive(root, item);
            treeSize--;
            return true;
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return containsRecursive(root, item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
        clearRecursive(root);
        root = nullptr;
        treeSize = 0;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return treeSize;
    }
private:
    Node* insertRecursive(Node* current, const T& item) {
        if (current == nullptr) {
            return new Node(item);
        }

        if (item < current->value) {
            current->left = insertRecursive(current->left, item);
        } else if (item > current->value) {
            current->right = insertRecursive(current->right, item);
        }

        return current;
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* removeRecursive(Node* current, const T& item) {
        if (current == nullptr) {
            return nullptr;
        }

        if (item < current->value) {
            current->left = removeRecursive(current->left, item);
        } else if (item > current->value) {
            current->right = removeRecursive(current->right, item);
        } else {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            } else if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            } else {
                Node* temp = findMinNode(current->right);
                current->value = temp->value;
                current->right = removeRecursive(current->right, temp->value);
            }
        }
        return current;
    }

    bool containsRecursive(Node* current, const T& item) const {
        if (current == nullptr) {
            return false;
        }

        if (item == current->value) {
            return true;
        } else if (item < current->value) {
            return containsRecursive(current->left, item);
        } else {
            return containsRecursive(current->right, item);
        }
    }

    void clearRecursive(Node* node) {
        if (node != nullptr) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }
};
