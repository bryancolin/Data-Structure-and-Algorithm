#include "Queue.h"

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
Queue<T>::Queue() // Constructor
{
}

template <typename T>
Queue<T>::~Queue() // Deconstructor
{
}

template <typename T>
bool Queue<T>::empty()
{
    return queue_stack.empty();
}

template <typename T>
size_t Queue<T>::size()
{
    return queue_stack.size();
}

template <typename T>
T Queue<T>::front()
{
    stack<T> original_queue_stack = queue_stack;
    T item = pop();

    queue_stack = original_queue_stack;
    return item;  
}

template <typename T>
void Queue<T>::push(T data)
{
    queue_stack.push(data);
}

template <typename T>
T Queue<T>::pop()
{
    if (empty())
    {
        cout << "Queue is empty";
        exit(0);
    }

    T data = queue_stack.top();
    queue_stack.pop();

    if (empty())
    {
        return data;
    }

    int item = pop();
    queue_stack.push(data);

    return item;
}

template <typename T>
void Queue<T>::display()
{
    stack<T> original_queue_stack = queue_stack;

    while (!queue_stack.empty()) 
    {
        cout << pop() << " ";
    }

    queue_stack = original_queue_stack;
}