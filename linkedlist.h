//
//  header.h
//  PA1
//
//  Created by Warren Christian on 1/24/25.
//
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
#include "node.h"

using std::string;

template <class T>
class LinkedList {
private:
    
    Node<T>* head;
public:
    
    // Constructor
    LinkedList() : head(nullptr) {};

    // Destructor
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->getNext();
            delete current;
            current = next;
        }
    }

    // Insert
    void insertAtFront(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
    }

    // Getter
    Node<T>* getHead() const {
        return head;
    }

    // Display
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << "- ";
            std::cout << current->getData() << std::endl;
            current = current->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif
