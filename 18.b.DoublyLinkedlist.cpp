#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev; // Pointer to the previous node

    Node(int value = 0) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head, *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

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
            head->prev = newNode;
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
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteOnFront()
    {
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
            return;
        }

        Node *temp = head;
        if (head == tail) // Only one node
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void deleteOnRear()
    {
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
            return;
        }

        Node *temp = tail;
        if (head == tail) // Only one node
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void showForward()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void showBackward()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.addOnFront(10);
    list.addOnFront(20);
    list.addOnRear(5);
    list.addOnRear(1);

    cout << "List in forward direction: ";
    list.showForward();

    cout << "List in backward direction: ";
    list.showBackward();

    list.deleteOnFront();
    cout << "After deleting from front: ";
    list.showForward();

    list.deleteOnRear();
    cout << "After deleting from rear: ";
    list.showForward();

    return 0;
}
