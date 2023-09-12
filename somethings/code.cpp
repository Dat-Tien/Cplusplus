#include <iostream>
#include <bits/stdc++.h>

//1. Reverse a String:
void reverseString(std::string& str) {
    if (str.empty()) {
        return;
    }
    else {
        uint32_t left {0};
        auto right {str.length() - 1};
        while (left < right)
        {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
    }
}

//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the missing number. (e.g., [3, 0, 1] should return 2)
uint32_t missingNumber(uint32_t* arr, uint32_t length) {
    uint32_t actualSum {0};
    auto i {0};
    while(i < length - 1) {
        actualSum += arr[i];
        i++;
    }
    uint32_t idealSum = (length*(length + 1))/2;
    return idealSum - actualSum;
}

template<class T>
uint32_t pattition(T arr[], const uint32_t low, const uint32_t high) {
    T privot {arr[high]};
    uint32_t i {low - 1};

    for (auto j{0}; j < high - 1; j++) {
        if (arr[j] < privot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i+1], arr[high]);
    return i + 1;
}

template<class T>
void quickSort(T arr[], const uint32_t low, const uint32_t high) {
    if (low < high) {
        uint32_t pi = patition(arr, low, high);

        quickSort(arr, low, pi -1);
        quickSort(arr, pi +1, high);
    }
}

int main(void) {
    uint32_t arr[] = {1,2,3,4,5,6,7,8,10};
    std::array<uint32_t, sizeof(arr)/sizeof(arr[0])>::iterator itr = arr;

    std::cout<<missingNumber(itr, sizeof(arr)/sizeof(arr[0])) <<std::endl;

    return 0;
}