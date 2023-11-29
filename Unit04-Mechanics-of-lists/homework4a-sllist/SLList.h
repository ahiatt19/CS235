#pragma once
#include <iostream>
using namespace std;

template <class T>
class SLList {

public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
        //Node(T v) {
         //   value = v;
         //   next = nullptr;
        //}
    };

    Node* head;
    Node* tail;
    int count;


    SLList() {
        cout << "SLList: constructor" << endl;
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~SLList() {
        cout << "SLList: deconstructor" << endl;
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_back(T item) {
        // Step 1: create the Node
        Node* nodeNum = new Node(item);
        // Step 2: update tail --> next to point to the new mode
        if (head == nullptr) {
            tail = nodeNum;
            head = nodeNum;
        }
        // Step 3 update head and tail appropriatel
        else{
            tail->next = nodeNum;
            tail = nodeNum;
        }
        count ++;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }

        if (count == 1) {
            // If there is only one node, delete it and set head to nullptr
            delete head;
            head = tail = nullptr;
        } else {
            // Traverse to the second-to-last node and delete the last node
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;


        }

        count--; // Decrement the size of the list
    }


    const T& front() const {
        return head->value;
    }

    void remove(int position) {
        if (position >= size())
            return;
// case 1: position = 0
        if (position == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
// case 2: position = size()-1;
        else if (position == (size()-1)) {
// find the object before the last one
            Node* itr = head;
            for (int i = 0; i < (position-1); i++)
                itr = itr->next;
            Node* tmp = tail;
            itr->next = nullptr;
            delete tmp;
            tail = itr;
        }
// case 3: removing something in the middle
        else {
            Node* itr = head;
            for (int i = 0; i < (position-1); i++)
                itr = itr->next;
            Node* tmp = itr->next;
            itr->next = itr->next->next;
            delete tmp;
        }
        count --;
    }

    int size() const {
        return count;
    }

    void clear() {
        // implement clear here
        while (head != nullptr) {
            remove(0);
        }
    }

    void print() {
        cout << "Linked list is: ";
        Node* itr = head;
        while (itr != nullptr) {
            cout << itr->value << ", ";
            itr = itr->next; // can also try to look at itr->value
        }
        cout << endl;
    }
};

