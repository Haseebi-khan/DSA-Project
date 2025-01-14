#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
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

// Q2: Print Level Order Traversal of a binary tree.
void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tress is Empty.\n";
        return;
    }
    cout << "Level Order: ";
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
}

int main()
{
    Node *root1 = nullptr;

    insertNode(root1, 15);
    insertNode(root1, 10);
    insertNode(root1, 20);
    insertNode(root1, 8);
    insertNode(root1, 12);
    insertNode(root1, 16);
    insertNode(root1, 25);
    LevelOrderTraversal(root1);

    cout << "\n";

    return 0;
}