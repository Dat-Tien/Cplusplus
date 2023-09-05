#include <iostream>
#include <bits/stdc++.h> 

template<class T>
class SearchAlgorithms {
public:
    SearchAlgorithms()  {} //= default;
    ~SearchAlgorithms() {} // = default;

    int32_t iterativeBinarySearch(T arr[], const uint32_t length, const T searchData);
    int32_t recursiveBinarySearch(T arr[], const uint32_t low, const uint32_t hight, const T searchData);
private:
};