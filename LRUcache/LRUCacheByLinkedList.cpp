#include "LRUCacheByLinkedList.hpp"

template<class T>
LRUCache<T>::LRUCache(const uint32_t size) {
    cp = size;
    head = new Node<T>(static_cast<T>(0), static_cast<T>(0));
    tail = new Node<T>(static_cast<T>(0), static_cast<T>(0));
    head->next = tail;
    tail->prev = head;
}

template<class T>
LRUCache<T>::~LRUCache() {
    while (auto itr : mp) {
        if (itr != mp.end()) // just in case
        {
            delete (*itr).second;
            mp.erase(itr);
        }
    }
}

template<class T>
void LRUCache<T>::set(T key, T value) {
    auto itr {mp.find(key)};
    if (itr == mp.end()) {
        Node* newNode = new Node(key, value);
        if (mp.size() < cp) {
            mp[key] = newNode;
            newNode->next = head->next;
            newNode->prev = head;
            head->next = newNode;
            newNode->next->prev = newNode;
        }
        else {
            Node* deleteNode {tail->prev};
            T deleteKey {deleteNode->key};
            mp.erase(deleteKey);
            deleteNode->prev->next = tail;
            tail->prev = deleteNode->prev;
            delete deleteNode;
            mp[key] = newNode;
            newNode->next = head->next;
            newNode->prev = head;
            head->next = newNode;
            newNode->next->prev = newNode;
        }
    }
    else {
        auto node {itr->second};
        node->value = value;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
}

template<class T>
T LRUCache<T>::get(T key) {
    auto itr = mp.find(key);
    if (itr == mp.end()) {
        return (T)(-1);
    }
    return itr->second->value;
}

int main(){
    printf("hello world\n");
    return 0;
}