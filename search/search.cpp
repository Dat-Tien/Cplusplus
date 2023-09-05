#include "search.hpp"

template<class T>
int32_t SearchAlgorithms<T>::iterativeBinarySearch(T arr[], const uint32_t length, const T searchData) {
    uint32_t low {0};
    uint32_t hight {length};

    while (low < hight) {
        uint32_t mid {low + (hight - low)/2};
        if (arr[mid] == searchData) {
            return mid;
        }
        if(arr[mid] < low) {
            low = mid + 1;
        }
        else {
            hight = mid -1;
        }
    }
    return -1;
}

int main(void) {
    printf("hello world\n");
    uint32_t arr[] = {0, 1, 2, 4, 5, 6, 4, 10, 7, 9, 8};
    std::array<uint32_t, sizeof(arr)/sizeof(arr[0] - 1)>::iterator itr = arr;
    SearchAlgorithms<uint32_t> search;
    auto ret {search.iterativeBinarySearch(itr, sizeof(arr)/sizeof(arr[0] - 1), 6)};
    (ret == -1) 
        ? std::cout << "Element is not present in array\n"
        : std::cout << "Element is present at index " << ret << std::endl;


}
