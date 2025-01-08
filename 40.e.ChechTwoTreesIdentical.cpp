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
    int dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        QueueNode *temp = front;
        int value = front->data->data;
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
        if (front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
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

    Queue part1;
    Queue tempq;
    Node *temp = root1;
    tempq.enqueue(root1);

    while (!tempq.empty())
    {
        Node *curr = tempq.peek();
        part1.enqueue(curr);

        if (curr->left)
        {
            tempq.enqueue(curr->left); 
        }
        if (curr->right)
        {
            tempq.enqueue(curr->right);
        }
    }

    Queue part2;
    Node *temp = root1;
    tempq.enqueue(root1);

    while (!tempq.empty())
    {
        Node *curr = tempq.peek();
        part1.enqueue(curr);

        if (curr->left)
        {
            tempq.enqueue(curr->left); 
        }
        if (curr->right)
        {
            tempq.enqueue(curr->right);
        }
    }


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
    printorder(root1);
    cout << endl;

    cout << endl;
    return 0;
}