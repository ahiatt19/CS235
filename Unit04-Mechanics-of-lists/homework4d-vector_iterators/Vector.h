#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:
    class Iterator {
    public:
        T& operator*() {
            // implement operator* here
            return *ptr;
        }

        Iterator& operator++() {
            // implement operator++ here
            ptr++;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        Iterator(T* p) : ptr(p) {}

    private:
        T* ptr;
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }

    // paste in your methods from the vector assignment
    Vector() : data(nullptr), capacity(0), size(0) {}

    void push_back(const T& value) {
        if (size >= capacity) {
            if (capacity == 0)
                reserve(1);
            else
                reserve(2 * capacity);
        }

        data[size++] = value;
    }

    void reserve(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    size_t getSize() const {
        return size;
    }

    ~Vector() {
        delete[] data;
    }

private:
    T* data;
    size_t capacity;
    size_t size;
};