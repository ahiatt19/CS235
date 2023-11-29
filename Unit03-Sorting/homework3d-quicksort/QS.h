#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int middle = (left + right)/2;

    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }
    if (array[middle] > array[right]) {
        std::swap(array[middle], array[right]);
    }
    if (array[left] > array[middle]) {
        std::swap(array[left], array[middle]);
    }

    return middle;
}


template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int pivotIndex = medianOfThree(array, left, right);
    //swap array[left] and array[middle]
    //T pivotValue = array[pivotIndex];

    std::swap(array[pivotIndex], array[left]);

    int up = left + 1;
    int down = right;
    do {
        while (up < right && array[up] <= array[left]) {
            up ++;
        }
        while (down > left && array[down] > array[left]) {
            down --;
        }
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    } while (up < down);

    std::swap(array[left], array[down]);

    return down;
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    //if (array.size() <= 1) {return 0;}
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(array, left, right);
    sort_helper(array, left, pivotIndex - 1);
    sort_helper(array, pivotIndex + 1, right);
}


template<class T>
void sort(std::vector<T>& array) {
    if (array.empty()) {
        return;
    }
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    sort_helper(array, 0, array.size() - 1);
}