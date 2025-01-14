#include <iostream>
#include <stack>
using namespace std;

// 1. Binary Search Trees(BSTs)
// (a) Draw the BST where the data value at each node is an integer and the values are entered in the following order: 36, 22, 10, 44, 42
// (b) Draw the BST after the following insertions have been done in the tree of part (a): 16, 25, 3, 23, 24 (there is no attempt at being tricky; parts (a) and (b) could be combined into a single one but we want you to check your work so that you don't make a silly mistake)
// (c) Now draw the tree after deletions of 42, 23 and 22 in this order
// (d) Write down the order on which the node values are reached when the BST of part
// (c) is traversed (I) in in order (ii) in post order (iii) in preorder
// (e) What is the height of the tree of part

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height = 0;
    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

struct QueueNode
{
    Node *data;
    QueueNode *next;
    QueueNode(Node *node) : data(node), next(nullptr) {}
};

class Queue
{
    QueueNode *front;
    QueueNode *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(Node *data)
    {
        QueueNode *newNode = new QueueNode(data);
        if (front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    Node *dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return nullptr;
        }
        QueueNode *temp = front;
        Node *value = front->data;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        return value;
    }
    Node *peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return nullptr;
        }
        return front->data;
    }
    bool empty()
    {
        return front == nullptr;
    }
};

struct NodeS
{
    Node *data;
    NodeS *next;
    NodeS(Node *d) : data(d), next(nullptr) {}
};

class Stack
{
private:
    NodeS *top;

public:
    Stack() : top(nullptr) {}

    void push(Node *value)
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
    Node *peek()
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

void insertNode(Node *&root, int value)
{
    Node *newNode = new Node(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    while (temp)
    {
        if (value > temp->data)
        {
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else if (value < temp->data)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            cout << "New Node Already Attached.\n";
            return;
        }
    }
}

void ShowLevelOrder(Node *root)
{
    cout << "List: ";
    if (root == nullptr)
    {
        return;
    }
    Queue q;
    q.enqueue(root);

    while (!q.empty())
    {
        Node *cur = q.peek();
        q.dequeue();

        cout << cur->data << " ";

        if (cur->left)
        {
            q.enqueue(cur->left);
        }

        if (cur->right)
        {
            q.enqueue(cur->right);
        }
    }
    cout << endl;
}

void DeleteAllTree(Node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    Queue q;
    q.enqueue(root);
    while (!q.empty())
    {
        Node *cur = q.peek();
        q.dequeue();

        if (cur->left)
        {
            q.enqueue(cur->left);
        }
        if (cur->right)
        {
            q.enqueue(cur->right);
        }

        delete cur;
    }
    root = nullptr;
}

Node *Successer(Node *node)
{
    Node *curr = node;

    
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    
    return curr;
}

int main()
{

    Node *root = nullptr;
    // 36, 22, 10, 44, 42
    insertNode(root, 36);
    insertNode(root, 22);
    insertNode(root, 10);
    insertNode(root, 44);
    insertNode(root, 42);

    ShowLevelOrder(root);

    DeleteAllTree(root);

    ShowLevelOrder(root);

    cout << "\n";
    return 0;
}