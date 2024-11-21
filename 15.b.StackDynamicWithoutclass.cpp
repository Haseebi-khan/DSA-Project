#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value = 0) : data(value), next(nullptr) {}
};

Node *Stacktop = nullptr;

void push(int value)
{
    Node *newNode = new Node(value);
    if (Stacktop == nullptr)
    {
        Stacktop = newNode;
    }
    else
    {
        newNode->next = Stacktop;
        Stacktop = newNode;
    }
}

void insertInEnd(int value)
{
    Node *newNode = new Node(value);
    if (Stacktop == nullptr)
    {
        Stacktop = newNode;
    }
    else
    {
        Node *temp = Stacktop;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void pop()
{
    if (Stacktop == nullptr)
    {
        cout << "Empty.\n";
    }
    else
    {
        Node *temp = Stacktop;
        Stacktop = temp->next;
        delete temp;
    }
}

void display()
{
    Node *temp = Stacktop;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{

    push(10);
    push(20);
    insertInEnd(30);
    insertInEnd(40);
    display();
    cout << endl;
    return 0;
}