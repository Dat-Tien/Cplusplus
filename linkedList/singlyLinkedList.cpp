#include "singlyLinkedList.hpp"
#include <stdio.h>

void Node::setNext(Node* node) {
    next = node;
}

void Node::setData(std::string data) {
    mData = data;
}

void singlyLinkedList::insert(std::string data) {
    Node* newNode {new Node(data)};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->getNext() != nullptr) {
        temp = temp->getNext();
    }

    temp->setNext(newNode);
}

void singlyLinkedList::insert(std::string data, uint32_t pos) {
    Node* newNode {new Node(data)};
    Node *temp1 = head;
    Node* temp2 = nullptr;
    while(pos > 0) {
        
        temp1 = temp1->getNext();
        if (temp1 == nullptr) {
            printf("null\n");
            break;
        }
        pos--;
    }
    printf("%d",pos);
    if (pos > 0 && temp1 == nullptr) {
        printf("Position to insert is invalid \n");
    }
    else if (pos == 0) {
        newNode->setNext(temp1->getNext());
        temp1->setNext(newNode);
          // newNode->setNext(temp1);
    }
    else {
        // do nothing
    }
    // newNode->setNext();
}

void singlyLinkedList::deleteLinkedList(uint32_t node) {
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
  
    if (head == NULL) {
        std::cout << "List empty." << std::endl;
        return;
    }
  
    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->getNext();
        ListLen++;
    }
  
    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < node) {
        std::cout << "Index out of range"
             << std::endl;
        return;
    }
  
    // Declare temp1
    temp1 = head;
  
    // Deleting the head.
    if (node == 1) {
  
        // Update head
        head = head->getNext();
        delete temp1;
        return;
    }
  
    // Traverse the list to
    // find the node to be deleted.
    while (node-- > 1) {
  
        // Update temp2
        temp2 = temp1;
  
        // Update temp1
        temp1 = temp1->getNext();
    }
  
    // Change the next pointer
    // of the previous node.
    temp2->setNext(temp1->getNext());
  
    // Delete the node
    delete temp1;
}

void singlyLinkedList::printList() {
    Node* temp = head;

    if (head == nullptr) {
        printf("Linked list is nullptr \n");
        return;
    }

    while(temp != nullptr) {
        printf("%s -> ", temp->getData().c_str());
        temp = temp->getNext();
    }
}

int main() {
    printf("Here is test for singly linked list\n");
    singlyLinkedList linkedList;
    linkedList.insert("SIngly linked list 1");
    linkedList.insert("SIngly linked list 2");
    linkedList.insert("SIngly linked list 3");
    linkedList.insert("SIngly linked list insert into pos 1", 1);
    linkedList.printList();
    // linkedList.deleteLinkedList(1);
    // linkedList.printList();
}