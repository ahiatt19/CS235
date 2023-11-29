#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    Node* head; // pointer to the head of the list
    Node* tail; // pointer to the tail of the list
    int listSize; // current size of the list

    DLList() : head(nullptr), tail(nullptr), listSize(0) {}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        Node* newNode = new Node(item);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        listSize++;
    }
    void push_back(T item) {
        Node* newNode = new Node(item);

        if (!head) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Otherwise, add the new node to the end and update the tail pointer
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        listSize++; // Increment the size of the list
    }

    void insert(T item, int position) {
        if (position < 0 || position > listSize) {
            throw std::out_of_range("Index out of range");
        }

        if (position == 0) {
            push_front(item);
        } else if (position == listSize) {
            push_back(item);
        } else {
            Node* newNode = new Node(item);
            Node* current = head;

            for (int i = 0; i < position; ++i) {
                current = current->next;
            }

            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;

            listSize++; // Increment the size of the list
        }
    }

    void pop_front() {
        if (!head) {
            throw std::length_error("List is empty");
        }

        if (listSize == 1) {
            // If there is only one node, delete it and set head and tail to nullptr
            delete head;
            head = tail = nullptr;
        } else {
            // Otherwise, remove the front node and update the head pointer
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        listSize--;
    }

    void pop_back() {
        if (!head) {
            throw std::length_error("List is empty");
        }

        if (listSize == 1) {
            // If there is only one node, delete it and set head and tail to nullptr
            delete head;
            head = tail = nullptr;
        } else {
            // Otherwise, remove the back node and update the tail pointer
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }

        listSize--;
    }
    void remove(int position) {
        if (position < 0 || position >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        if (position == 0) {
            pop_front();
        } else if (position == listSize - 1) {
            pop_back();
        } else {
            Node* current = head;

            for (int i = 0; i < position; ++i) {
                current = current->next;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;

            listSize--; // Decrement the size of the list
        }
    }

    const T& front() const {
        if (!head) {
            throw std::length_error("List is empty");
        }

        return head->value;
    }
    const T& back() const {
        if (!head) {
            throw std::length_error("List is empty");
        }

        return tail->value;
    }
    const T& at(int index) const {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->value;
    }

    bool contains(const T& item) const {
        Node* current = head;

        while (current) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    int size() const {
        return listSize;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr; // Reset the tail pointer
        listSize = 0;
    }
};
