#include "doubleLinkedList.hpp"

template<class T>
void DoubleLinkedList<T>::insertFirst(T data) {
    Node<T>* refNode = new Node(data);

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
    while (head != nullptr) {
        head = head->next;
        res += 1;
    }
    return res;
}

template<class T>
void DoubleLinkedList<T>::deleteList(T pos) {
    /* Determine which node shall be deleted*/
    // if (static_cast<uint32_t>(pos) > )
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
    delete temp;
}

int main() {
    DoubleLinkedList<int32_t> linkedlist;
    linkedlist.printList();
    printf("\n%d\n",linkedlist.length());
    linkedlist.insertFirst(10);
    linkedlist.insertFirst(20);
    linkedlist.insertFirst(30);
    linkedlist.printList();
    printf("\n%d\n",linkedlist.length());
    printf("Hello world \n");
    
}