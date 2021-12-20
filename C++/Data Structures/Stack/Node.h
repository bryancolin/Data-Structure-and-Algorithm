#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node *next;
    T data;
};

#endif // NODE_H