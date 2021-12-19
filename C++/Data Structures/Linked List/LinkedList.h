#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList
{

private:
    T length;
    Node<T> *head;
    Node<T> *createNode(T data);

public:
    LinkedList();
    ~LinkedList();
    void prepend(T data);
    void append(T data);
    void removeByValue(T data);
    void removeByPosition(int position);
    void insertByPosition(int position, T data);
    void ascendingSort();
    void reverse();
    void display();
};

#endif // LINKEDLIST_H