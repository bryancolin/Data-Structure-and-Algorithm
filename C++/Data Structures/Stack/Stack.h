#ifndef STACK_H
#define STACK_H

#include "Node.h"

#include <iostream>

template <typename T>
class Stack
{

private:
    Node<T> *head;
    size_t length;

public:
    Stack();
    ~Stack();
    bool empty();
    size_t size();
    T top();
    void push(T data);
    void pop();
    void display();
};

#endif // STACK_H