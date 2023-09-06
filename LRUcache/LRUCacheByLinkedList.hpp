#include "../linkedList/doubleLinkedList.hpp"
#include <iostream>

template<class T>
struct Node {
    T value;
    T key;
    Node* next;
    Node* prev;
    Node(T k, T val) : prev(nullptr), next(nullptr), key(k), value(val) {}
};

template<class T>
class Cache {
protected:
    std::map<T, Node*> mp; //Map the key to linked list
    uint32_t cp; //capacity of Cache
    Node* tail;
    Node* head;

    virtual void set(T k, T val) = 0;
    virtual T get(T k) = 0;
};

template<class T>
class LRUCache : public Cache<T> {
public:
    LRUCache(const uint32_t size);

    ~LRUCache();

    void set(T key, T value) override;
    T get(T key) override;
private:
};
