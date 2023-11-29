#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
private:
    T* elements;
    int capacity;
    int currentSize;

    void resize() {
        if (currentSize >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newElements = new T[newCapacity];
            for (int i = 0; i < currentSize; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;

        }
    }
public:
    Vector() : elements(nullptr), capacity(0), currentSize(0) {}

    ~Vector() {
        delete[] elements;
    }

    void push_back(T item) {
        resize();
        elements[currentSize++] = item;
    }

    void insert(T item, int position) {
        if (position < 0 || position > currentSize) {
            throw std:: out_of_range("Index out of range");
        }
        resize();
        for (int i = currentSize; i > position; --i) {
            elements[i] = elements[i - 1];
        }
        elements[position] = item;
        ++currentSize;
    }

    void remove(int position) {
        if (position < 0 || position >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = position; i < currentSize - 1; ++i) {
            elements[i] = elements[i + 1];
        }
        --currentSize;

    }

    T& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    int size() const {
        return currentSize;
    }

    void clear() {
        delete[] elements;
        elements = nullptr;
        capacity = 0;
        currentSize = 0;
    }
};
