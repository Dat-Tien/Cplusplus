#include<iostream>


class Node {
private:
    std::string mData;
    Node* next;
public:
    Node() : next(nullptr) {}
    Node(std::string data) : mData(data), next(nullptr) {}

    void setNext(Node* node);
    void setData(std::string data);
    Node* getNext() const { return next; }
    std::string getData() const { return mData; }
};

class singlyLinkedList {
private:
    Node* head;
public:
    singlyLinkedList() : head(nullptr) {}

    void insert(std::string data);
    void insert(std::string data, uint32_t pos);
    void find(std::string data);
    void find(uint32_t pos);
    void printList();
    void deleteLinkedList(std::string data);
    void deleteLinkedList(uint32_t node);
    void sortLinkedList();
};