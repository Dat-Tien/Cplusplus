#include "LRUCache.hpp"

void LRUCache::display() {
    for (auto itr {dq.begin()}; itr != dq.end(); itr++) {
        std::cout<<*itr <<" ";
    }
    std::cout<<endl;
}

void LRUCache::set(const int32_t data) {
    if (ma.find(data) == ma.end()) {
        if (dq.size() == csize) {
            const int32_t last {dq.back()};
            dq.pop_back();
            ma.erase(last);
        }  
    }
    else {
        dq.erase(ma[data]);
    }
    dq.push_front(data);
    ma[data] = dq.begin();
}

int main()
{
    LRUCache ca(4);
 
    ca.set(1);
    ca.set(2);
    ca.set(3);
    ca.set(1);
    ca.set(4);
    ca.set(5);
    ca.set(20);
    ca.set(1);
    ca.display();
 
    return 0;
}