#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Queue
{

private:
    stack<T> queue_stack;

public:
    Queue();
    ~Queue();
    bool empty();
    size_t size();
    T front();
    void push(T data);
    T pop();
    void display();
};

#endif // QUEUE_H