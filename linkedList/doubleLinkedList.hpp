#include<iostream>
#include<stdio.h>

template<class T>
class Node {
public:
    Node() : next(nullptr), prev(nullptr) {}
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}  

    T data;
    Node<T>* next;
    Node<T>* prev;
};

template<class T>
class DoubleLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    uint32_t mSize;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), mSize(0) {}
    ~DoubleLinkedList();
    void pushFront(T data);
    void insertBettween(T data, uint32_t pos);
    void append(T data);
    void deleted(uint32_t pos);
    void printList();
    uint32_t length();
    bool isEmpty();
};