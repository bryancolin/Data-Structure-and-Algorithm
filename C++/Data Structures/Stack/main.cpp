#include "Stack.cpp"

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    Stack<int> stack;
    
    stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    
    cout << stack.top() << endl;
    cout << stack.empty() << endl;

    stack.display();
}