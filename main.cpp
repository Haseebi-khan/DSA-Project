#include <iostream>
#include <stack>
using namespace std;

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

        cout << cur->data;
        cout << endl;

        if (cur->left)
        {
            q.enqueue(cur->left);
        }

        cout << "";

        if (cur->right)
        {
            q.enqueue(cur->right);
        }
    }
}

int main()
{
    Node *root1 = nullptr;
    // 36, 22, 10, 44, 42
    insertNode(root1, 36);
    insertNode(root1, 22);
    insertNode(root1, 10);
    insertNode(root1, 44);
    insertNode(root1, 42);

    ShowLevelOrder(root1);

    cout << "\n";
    return 0;
}