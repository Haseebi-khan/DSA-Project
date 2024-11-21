#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value = 0) : data(value), next(nullptr) {}
};

Node *Stacktop = nullptr;

void insert(int value)
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

void insertAtEnd(int value)
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

    insert(10);
    insert(20);
    insertAtEnd(30);
    insertAtEnd(40);
    display();
    cout << endl;
    return 0;
}