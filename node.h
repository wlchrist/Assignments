//
//  node.h
//  PA1
//
//  Created by Warren Christian on 1/24/25.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>


using std::string;
using std::iostream;

typename<class T> {
    class Node {
    private:
        T data;
        Node<T>* next;
    public:
        // Constructors
        Node() {
            data = T();
            next = nullptr;
        }


        Node(T newData) {
            data = newData;
            next = nullptr;
        }

        // Destructor
        ~Node() {
        };
        
        
        // Getters and Setters
        T& getData() {
            return data;
        }

        Node<T>* getNext() const {
            return next;
        }

        void setData(T newData) {
            data = newData;
        }

        void setNext(Node<T>* node) {
            next = node;
        }
    }
};

#endif
