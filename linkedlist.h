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
#include <type_traits>
#include "node.h"
#include "typetraits.h"

using std::string;

template <class T>
class LinkedList {
private:
    template <typename U>
    static constexpr bool isData = std::is_same<U, Data>::value;
    Node<T>* head;
public:
    
    // Constructor
    LinkedList() : head(nullptr) {};

    // Copy constructors
    LinkedList(const LinkedList& other) : head(nullptr) {
    if (other.head) {
        head = new Node<T>(other.head->getData());
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->getNext();

        while (otherCurrent) {
            Node<T>* newNode = new Node<T>(otherCurrent->getData());
            current->setNext(newNode);
            current = newNode;
            otherCurrent = otherCurrent->getNext();
        }
    }
}

LinkedList& operator=(const LinkedList& other) {
    if (this == &other) {
        return *this;
    }

    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;

    if (other.head) {
        head = new Node<T>(other.head->getData());
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->getNext();

        while (otherCurrent) {
            Node<T>* newNode = new Node<T>(otherCurrent->getData());
            current->setNext(newNode);
            current = newNode;
            otherCurrent = otherCurrent->getNext();
        }
    }
    return *this;
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

    // Getter
    Node<T>* getHead() const {
        return head;
    }
    
    // Setter
    void setHead(Node<T>* newHead) {
    head = newHead;
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
    
    bool removeNode(const std::string& commandToRemove) requires isData<T> {
        
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return false;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        Node<T>* temp;

        while(current != nullptr) {
            if (current->getData().command == commandToRemove) {
                if (current == head) {
                    head = current->getNext();
                } else {
                    previous->setNext(current->getNext());
                }
                delete current;
                return true;
            } else {
                previous = current;
                current = current->getNext();
            }
        }
        return false;
    }
    
};

#endif
