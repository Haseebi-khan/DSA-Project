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

void printorder(Node *root)
{
    if (root == nullptr)
        return;
    printorder(root->left);
    printorder(root->right);
    cout << root->data << " ";
}

bool checkIdenticalTree(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }

    Queue q1, q2;
    q1.enqueue(root1);
    q2.enqueue(root2);

    while (!q1.empty() && !q2.empty())
    {
        Node *node1 = q1.dequeue();
        Node *node2 = q2.dequeue();

        if (node1->data != node2->data)
        {
            return false;
        }

        if (node1->left && node2->left)
        {
            q1.enqueue(node1->left);
            q2.enqueue(node2->left);
        }
        else if (node1->left || node2->left)
        {
            return false;
        }

        if (node1->right && node2->right)
        {
            q1.enqueue(node1->right);
            q2.enqueue(node2->right);
        }
        else if (node1->right || node2->right)
        {
            return false;
        }
    }

    return q1.empty() && q2.empty();
}

int main()
{
    Node *root1 = nullptr;
    Node *root2 = nullptr;

    insertNode(root1, 15);
    insertNode(root1, 10);
    insertNode(root1, 20);
    insertNode(root1, 8);
    insertNode(root1, 12);
    insertNode(root1, 16);
    insertNode(root1, 25);

    insertNode(root2, 15);
    insertNode(root2, 10);
    insertNode(root2, 20);
    insertNode(root2, 8);
    insertNode(root2, 12);
    insertNode(root2, 16);
    insertNode(root2, 25);

    cout << "First Tree: ";
    printorder(root1);
    cout << endl;
    cout << "Second Tree: ";
    printorder(root2);
    cout << endl;

    if (checkIdenticalTree(root1, root2))
    {
        cout << "The trees are identical.\n";
    }
    else
    {
        cout << "The trees are not identical.\n";
    }

    return 0;
}
