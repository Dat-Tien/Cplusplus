#include<iostream>
#include<stdio.h>

template<class T>
class Node {
public:
    Node() : next(nullptr), prev(nullptr) {}
    Node(T data) : mData(data), next(nullptr), prev(nullptr) {}  

public:
    T mData;
    Node* next;
    Node* prev;
};

template<class T>
class DoubleLinkedList {
public:
    Node<T>* head;

public:
    DoubleLinkedList() : head(nullptr) {}

    void insertFirst(T data);
    void insertBettween(T data, uint32_t pos);
    void append(T data);
    void deleted(uint32_t pos);
    void printList();
    uint32_t length();
};