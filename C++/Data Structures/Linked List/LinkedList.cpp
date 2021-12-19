#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() // Constructor
{
    this->length = 0;
    this->head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() // Deconstructor
{
    while (this->head)
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    cout << "Linked List Deleted!" << endl;
}

template <typename T>
Node<T> *LinkedList<T>::createNode(T data)
{
    Node<T> *new_node = new Node<T>();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

template <typename T>
void LinkedList<T>::prepend(T data)
{
    Node<T> *new_node = createNode(data);
    new_node->next = this->head;
    this->head = new_node;
    this->length++;
}

template <typename T>
void LinkedList<T>::append(T data)
{
    Node<T> *current_node = this->head;

    // If LinkedList<T> is Empty then prepend
    if (current_node == NULL)
    {
        prepend(data);
        return;
    }

    // If LinkedList<T> is not Empty then append
    Node<T> *new_node = createNode(data);

    while (current_node->next)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    this->length++;
}

template <typename T>
void LinkedList<T>::removeByValue(T data)
{
    Node<T> *current_node = this->head;
    Node<T> *prev_node;

    // If value is in the head
    if (current_node != NULL && current_node->data == data)
    {
        this->head = current_node->next;
        this->length--;
        return;
    }

    // If value is not in the head
    while (current_node && current_node->data != data)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    // If value is not in LinkedList<T>
    if (current_node == NULL)
    {
        return;
    }

    prev_node->next = current_node->next;
    current_node = prev_node;

    this->length--;
}

template <typename T>
void LinkedList<T>::removeByPosition(int position)
{
    Node<T> *current_node = this->head;
    Node<T> *prev_node = this->head;

    // If position is not valid
    if ((0 <= position && position <= length) == false)
    {
        return;
    }

    int i = 0;
    while (i < position)
    {
        prev_node = current_node;
        current_node = current_node->next;
        i++;
    }

    if (position == 0)
    {
        this->head = current_node->next;
    }
    else
    {
        prev_node->next = current_node->next;
        current_node = prev_node;
    }

    this->length--;
}

template <typename T>
void LinkedList<T>::insertByPosition(int position, T data)
{
    Node<T> *current_node = this->head;
    Node<T> *new_node = createNode(data);

    if (position == 0)
    {
        prepend(data);
        return;
    }
    else if (position >= length)
    {
        append(data);
        return;
    }

    while (position > 1)
    {
        current_node = current_node->next;
        position--;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;

    this->length++;
}

template <typename T>
void LinkedList<T>::ascendingSort()
{
    Node<T> *current_node = this->head;
    Node<T> *next_node;

    if (current_node == NULL)
    {
        return;
    }

    while (current_node)
    {
        next_node = current_node->next;

        while (next_node)
        {
            if (current_node->data > next_node->data) // If first bigger than the second, then swap
            {
                int temp_data = current_node->data;
                current_node->data = next_node->data;
                next_node->data = temp_data;
            }
            next_node = next_node->next;
        }

        current_node = current_node->next;
    }
}

template <typename T>
void LinkedList<T>::reverse()
{
    Node<T> *current_node = this->head;
    Node<T> *prev_node, *next_node;

    while (current_node)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    this->head = prev_node;
}

template <typename T>
void LinkedList<T>::display()
{
    cout << "Linked List: ";

    Node<T> *current_node = this->head;
    while (current_node)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }

    cout << "\nLinked List Length: " << this->length << endl;
}