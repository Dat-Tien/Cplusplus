#include <iostream>
#include <bits/stdc++.h>

template<class T>
class SortAlgorithms {
public:
    SortAlgorithms() = default;
    ~SortAlgorithms() {
        mSize = 0;
    }

    SortAlgorithms(T array[], const uint32_t size) : mArray(array), mSize(size) {}
    void selectionSort();
    void bubbleSort();
    void insertionSort();
    void mergeSort();
    void quickSort();
    void heapSort();
    void radixSort();
    void bucketSort();

    void print();
private:
    T* mArray;
    uint32_t mSize;
};