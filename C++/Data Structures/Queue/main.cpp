#include "Queue.cpp"

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    
    queue.display();
}