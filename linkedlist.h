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


using std::string;
using std::iostream;

template <class T>
class LinkedList {
private:
    
    Node<T> head*;
public:
    // public
    
    // Constructor
    LinkedList() {
        head = nullptr;
    }

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

    // Head Getter
    Node<T>* getHead() const {
        return head;
    }

    // Display
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            current = current->getNext();
        }
    }
};

#endif
