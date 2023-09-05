#include "SortAlgorithms.hpp"

template<class T>
void SortAlgorithms<T>::bubbleSort() {
    for (uint32_t i{0}; i < mSize - 1; i++) {
        bool swapped {false};
        for (uint32_t j {0}; j < mSize - i - 1; j++) {
            if (mArray[j] > mArray[j + 1]) {
                std::swap(mArray[j], mArray[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

template<class T>
void SortAlgorithms<T>::selectionSort() {
    for (uint32_t i{0}; i < mSize - 1; i++) {
        uint32_t idx {i};
        for (uint32_t j{i + 1}; j < mSize; j++) {
            if(mArray[j] < mArray[idx]) {
                idx = j;
            }
        }
        if (idx != i) {
            std::swap(mArray[idx], mArray[i]);
        }
    }
}

template<class T>
void SortAlgorithms<T>::insertionSort() {
    for (uint32_t i{1}; i < mSize; i++) {
        T key {mArray[i]};
        uint32_t j {i - 1};
 
        while (j >= 0 && mArray[j] > key) {
            mArray[j + 1] = mArray[j];
            j = j - 1;
        }
        mArray[j + 1] = key;
    }
}


template<class T>
void SortAlgorithms<T>::print() {
    for (uint32_t i{0}; i < mSize; i++) {
        std::cout<<mArray[i]<<" ";
    }
    std::cout<<std::endl;
}


int main(void) {

    uint32_t arr[] {0, 90, 25, 10, 100, 70, 1, 50};
    SortAlgorithms<uint32_t> sort(arr, sizeof(arr)/sizeof(arr[0]));
    sort.selectionSort();
    sort.bubbleSort();
    sort.print();
    return 0;
}