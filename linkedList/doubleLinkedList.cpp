#include "doubleLinkedList.hpp"

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while(!isEmpty()) {
       Node<T>* temp = head;   
        if(head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        mSize--; 
    }
    
}

template<class T>
void DoubleLinkedList<T>::pushFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    if(isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    mSize++;
}

template<class T>
bool DoubleLinkedList<T>::isEmpty() {
    bool ret = false;
    if (mSize == 0) {
        ret = true;
    }
    return ret;
}

template<class T>
uint32_t DoubleLinkedList<T>::length() {
    return mSize;
}

template<class T>
void DoubleLinkedList<T>::deleted(uint32_t pos) {
    Node<T>* temp = head;

    while (--pos > 0) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    mSize--;
    delete(temp);
}

template<class T>
void DoubleLinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    mSize ++;
}

template<class T>
void DoubleLinkedList<T>::insertBettween(T data, uint32_t pos) {
    Node<T>* newNode = new Node<T>(data);
    Node<T>* temp = head;
    if (this->length() == 0) {
        printf("Linked list cannot be null\n");
    }
    else if (pos < mSize) {
        while (pos > 0) {
            temp = temp->next;
            pos--;
        }
    }
    else {
        
    }
    newNode->next = temp->next;
    newNode->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    mSize++;
    
}
template<class T>
void DoubleLinkedList<T>::printList() {
    Node<T>* temp = head;

    if (head == nullptr) {
        printf("Linked list is null \n");
    }

    while(temp != nullptr) {
        std::cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    DoubleLinkedList<int32_t> linkedlist;
    linkedlist.pushFront(10);
    linkedlist.pushFront(20);
    linkedlist.pushFront(30);
    linkedlist.append(100);
    linkedlist.insertBettween(40, 2);
    linkedlist.append(50);
    linkedlist.pushFront(60);
    linkedlist.deleted(3);
    linkedlist.printList();
    printf("Linked list length %d\n",linkedlist.length());
}