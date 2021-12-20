#include "Stack.h"
#include "Node.h"

#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
Stack<T>::Stack() // Constructor
{
    this->length = 0;
    this->head = NULL;
}

template <typename T>
Stack<T>::~Stack() // Deconstructor
{
    while (this->head) 
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    cout << "Stack Deleted!" << endl;
}

template <typename T>
bool Stack<T>::empty()
{
    return this->head == nullptr;
}

template <typename T>
size_t Stack<T>::size()
{
    return this->length;
}

template <typename T>
T Stack<T>::top()
{
    if (this->head)
    {
        return this->head->data;
    }
    else
    {
        return -1;
    }
}

template <typename T>
void Stack<T>::push(T data)
{
    Node<T> *current_node = new Node<T>();
    current_node->data = data;
    current_node->next = this->head;

    this->head = current_node;
    this->length++;
}

template <typename T>
void Stack<T>::pop()
{
    if (this->head)
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        this->length--;
        delete temp;
    }
}

template <typename T>
void Stack<T>::display()
{
    cout << "Stack: ";

    Node<T> *current_node = this->head;
    while (current_node)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }

    cout << "\nStack Length: " << this->length << endl;
}
