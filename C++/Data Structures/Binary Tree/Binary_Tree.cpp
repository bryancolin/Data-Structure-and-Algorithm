#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class vertex
{
    int id;
    int weight;
    struct vertex *left;
    struct vertex *right;
    vertex(int x, int y) : id(x), weight(y)
    {
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void preOrder1(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        struct Node *node = s.top();
        cout << node->data << " ";
        s.pop();

        if (node->right != NULL)
        {
            s.push(node->right);
        }
        if (node->left != NULL)
        {
            s.push(node->left);
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrder1(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> s;

    while (!s.empty() || root != NULL)
    {
        while (root != NULL)
        {
            s.push(root); // 1 2 3 4 5 1 2 4
            root = root->left;
        }
        root = s.top();            // 4
        s.pop();                   // 4
        cout << root->data << " "; // 4
        root = root->right;
    }
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void postOrder1(Node *root)
{
}

void BFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

Node *search(Node *node, int x)
{
    if (node == NULL || node->data == x)
    {
        return node;
    }
    else if (node->data < x)
    {
        return search(node->right, x);
    }
    return search(node->left, x);
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        return new Node(data);
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }

    return node;
}

Node *minValue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *maxValue(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    // delete leaves
    if (x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        //delete one child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(temp);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(temp);
            return temp;
        }

        //delete two child
        struct Node *temp = minValue(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node *root = new Node(4);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 5);

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    cout << root->left->right->data << endl;
    cout << root->left->right->right->data << endl;
    //cout << root->left->left->right->data << endl;
    //cout << root->left->left->right->right->data << endl;

    preOrder(root);
    preOrder1(root);
    cout << '\n';

    //inOrder(root);
    inOrder1(root);
    cout << '\n';

    postOrder(root);
    postOrder1(root);
    cout << '\n';

    BFS(root);
    cout << '\n';

    return 0;
}