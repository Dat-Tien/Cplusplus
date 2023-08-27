#include "doubleLinkedList.hpp"

template<class T>
void DoubleLinkedList<T>::insertFirst(T data) {
    Node<T>* refNode = new Node<T>(data);

    if (head == nullptr) {
        head = refNode;
    }
    else {
        refNode->next = head;
        head->prev = refNode;
        head = refNode;
    }
}

template<class T>
uint32_t DoubleLinkedList<T>::length() {
    uint32_t res {0};
    Node<T>* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        res += 1;
    }
    delete temp;
    return res;
}

template<class T>
void DoubleLinkedList<T>::deleted(uint32_t pos) {
    Node<T>* temp = head;

    while (--pos > 0) {
        temp = temp->next;
    }
    Node<T>* node = temp->next->next;
    free(temp->next);
    temp->next = node;

}

template<class T>
void DoubleLinkedList<T>::insertBettween(T data, uint32_t pos) {
    Node<T>* refNode = new Node<T>(data);
    Node<T>* temp = head;
    if (this->length() == 0) {
        printf("Linked list cannot be null\n");
    }
    else if (pos <= this->length()) {
        while (pos > 0) {
            temp = temp->next;
            pos--;
        }
    }
    else {
        
    }
    refNode->next = temp->next;
    refNode->prev = temp->prev;
    temp->next = refNode;
}
template<class T>
void DoubleLinkedList<T>::printList() {
    Node<T>* temp = head;

    if (head == nullptr) {
        printf("Linked list is null \n");
    }

    while(temp != nullptr) {
        std::cout<<temp->mData<<" -> ";
        temp = temp->next;
    }
}

template<class T>
void DoubleLinkedList<T>::append(T data) {
    Node<T>* refNode = new Node<T>(data);
    Node<T>* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    refNode->prev = temp;
    temp->next = refNode;
}

int main() {
    DoubleLinkedList<int32_t> linkedlist;
    linkedlist.insertFirst(10);
    linkedlist.insertFirst(20);
    linkedlist.insertFirst(30);
    linkedlist.insertBettween(40, 0);
    linkedlist.append(50);
    linkedlist.printList();
    std::cout<<"\n";
    linkedlist.deleted(3);
    linkedlist.printList();
    // printf("\n%d\n",linkedlist.length());
    
}