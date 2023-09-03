#include <bits/stdc++.h>
using namespace std;
 
class LRUCache {
    // store keys of cache
    list<int32_t> dq;
    // store references of key in cache
    unordered_map<int32_t, list<int32_t>::iterator> ma;
    int32_t csize; // maximum capacity of cache
 
public:
    LRUCache(const int32_t size) : csize(size) {}
    void set(const int32_t);
    void display();
};