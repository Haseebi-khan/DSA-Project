#include <iostream>
using namespace std;

// Q1: Print left view of a binary tree.

struct NodeT
{
public:
    int data;
    NodeT *left;
    NodeT *right;
    NodeT(int d = 0) : data(d), left(nullptr), right(nullptr) {}
};
struct NodeS
{
    NodeT *data;
    NodeS *next;
    NodeS(NodeT *d) : data(d), next(nullptr) {}
};

class Stack
{
private:
    NodeS *top;

public:
    Stack() : top(nullptr) {}

    void push(NodeT *value)
    {
        NodeS *newNode = new NodeS(value);
        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is UnderFlow.\n";
            return;
        }
        else
        {
            NodeS *temp = top;
            top = top->next;
            delete temp;
        }
    }
    NodeT *peek()
    {
        if (top == nullptr)
        {
            return nullptr;
        }
        else
        {
            return top->data;
        }
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
};

NodeT *root = nullptr;

void insert(int value)
{
    NodeT *newNode = new NodeT(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    NodeT *temp = root;
    while (temp)
    {
        if (value < temp->data)
        {
            if (!temp->left)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else if (value > temp->data)
        {
            if (!temp->right)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            cout << "Value Already Exist.\n";
            return;
        }
    }
}

// Q1: Print left view of a binary tree.

void LeftViewBST(NodeT *root)
{
    cout << "List: ";
    if (root == nullptr)
    {
        return;
    }
    Stack s;
    s.push(root);

    while (!s.isEmpty())
    {
        NodeT *cur = s.peek();
        s.pop();

        cout << cur->data << " ";

        if (cur->left)
        {
            s.push(cur->left);
        }
    }
}



int main()
{
    insert(30);
    insert(34);
    insert(25);
    insert(36);
    insert(10);
    insert(5);
    insert(2);
    insert(66);
    insert(55);

    LeftViewBST(root);

    cout << endl;
    return 0;
}