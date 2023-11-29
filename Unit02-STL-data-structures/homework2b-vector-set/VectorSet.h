#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;

template<class T>
class VectorSet {

private:
    vector<T> elements;
public:
    VectorSet() {}

    bool contains(T item) const {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == item) {
                return true;
            }
        }
        return false;

        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        if (!contains(item)) {
            elements.push_back(item);
            return true;
        }
        return false;


        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        auto it = find(elements.begin(), elements.end(), item);
        if (it != elements.end()) {
            elements.erase(it);
            return true;
        }
        return false;

        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        return elements.size();

        // return the number of items in the set
    }

    bool empty() const {
        return elements.empty();
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        elements.clear();

        // remove all items from the set
    }
};
