#include <iostream>
#include <string>
using namespace std;

// Q5: Family Tree Representation
// A family tree contains nodes representing family members. Each node has information about the family member's name, age, and relationship.
// Scenario: You need to store and traverse a family tree to answer questions like:
//     • Who are the children of a particular person?
//     • Who is the oldest member in the tree?

class Node
{
public:
    string name;
    int age;
    Node *child;
    Node *sibling;

    Node(string name, int age) : name(name), age(age), sibling(nullptr), child(nullptr) {}
};

class QueueNode
{
public:
    Node *data;
    QueueNode *next;

    QueueNode(Node *data) : data(data), next(nullptr) {}
};

class Queue
{
private:
    QueueNode *front;
    QueueNode *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(Node *node)
    {
        QueueNode *newNode = new QueueNode(node);
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
        Node *node = front->data;
        front = front->next;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return node;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

class FamilyTree
{
private:
    Node *root;

public:
    FamilyTree() : root(nullptr) {}

    void insert(string parentName, string name, int age)
    {
        Node *newNode = new Node(name, age);
        
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *parent = findParent(root, parentName);

        if (parent == nullptr)
        {
            cout << "Parent name not found.\n";
            return;
        }

        if (parent->child == nullptr)
        {
            parent->child = newNode;
        }
        else
        {
            Node *sibling = parent->child;
            while (sibling->sibling != nullptr)
            {
                sibling = sibling->sibling;
            }
            sibling->sibling = newNode;
        }
    }

    void findOldestMember()
    {
        cout << "Oldest Person.\n";
        cout << "Name: " << root->name << " Age: " << root->age << endl;
    }

    Node *findParent(Node *node, string name)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->name == name)
        {
            return node;
        }

        Node *child = node->child;

        while (child != nullptr)
        {
            Node *result = findParent(child, name);
            if (result != nullptr)
            {
                return result;
            }
            child = child->sibling;
        }

        return nullptr;
    }

    void LevelOrderTraversal()
    {
        if (root == nullptr)
        {
            cout << "The tree is empty.\n";
            return;
        }

        Queue q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            Node *current = q.dequeue();
            cout << "Name: " << current->name << ", Age: " << current->age << "\n";

            Node *child = current->child;
            while (child != nullptr)
            {
                q.enqueue(child);
                child = child->sibling;
            }
        }
    }
};

int main()
{
    FamilyTree family;

    family.insert("something", "zoiab", 70);
    family.insert("zoiab", "diltaj", 50);
    family.insert("zoiab", "noman", 45);
    family.insert("noman", "ijaz", 34);
    family.insert("zoiabnoman", "asd", 23);

    cout << "Family Tree:\n";
    family.LevelOrderTraversal();

    family.findOldestMember();
    return 0;
}

