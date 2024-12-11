#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value = 0) : data(value), next(nullptr) {}
};

class linkedlist
{
private:
    Node *head, *tail;

public:
    linkedlist() : head(nullptr), tail(nullptr) {}
    void addOnFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void addOnRear(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteOnFront()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head = temp->next;
            delete temp;
        }
    }
    void deleteOnRear()
    {
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }
    void show()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    
    cout << endl;
    return 0;
}