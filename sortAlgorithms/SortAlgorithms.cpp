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
void SortAlgorithms<T>::mergeSort() {
    
}

template<class T>
void merge(T arr[], const uint32_t l, const uint32_t m, const uint32_t r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    T L[n1];
    T R[n2];

    for (auto i{0}; i < m - l + 1; i++) {
        L[i] = arr[l + i];
    }

    for (auto i{0}; i < r - m; i++) {
        R[i] = arr[m + 1 + i];
    }

     // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

template<class T>
void mergeSort(T arr[], const uint32_t l, const uint32_t r) {
    if (l < r) {
        uint32_t m = l + (r - l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    mergeSort<uint32_t>(arr, 0, 7);
    for (auto i{0}; i< 8; i++) {
        std::cout<<arr[i]<< " ";
    } 
    SortAlgorithms<uint32_t> sort(arr, sizeof(arr)/sizeof(arr[0]));
    sort.selectionSort();
    sort.bubbleSort();
    sort.print();
    return 0;
}