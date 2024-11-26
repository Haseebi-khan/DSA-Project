
#include <iostream>
using namespace std;

// Doubly Linked List (DLL)

class node
{
public:
    int data;
    node *next;
    node *pre;
    node(int value = 0) : data(value), next(nullptr), pre(nullptr) {}
};

// 1 - Implement a simple doubly linked list
//     where you can perform basic operations like
class doublyLinkedList
{
private:
    node *head, *tail;

public:
    doublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    //  insert at the beginning,
    void insertAtBeginning(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }
    //  insert at the end,
    void insertAtEnd(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    //  delete from the beginning,
    void deleteFromBeginning()
    {
        if (head == tail)
        {
            delete head, tail;
            // doublyLinkedList();
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // delete from the end.
    void deleteFromEnd()
    {
        if (head == tail)
        {
            delete head, tail;
            // doublyLinkedList();
            head = tail = nullptr;
        }
        else
        {
            node *temp = tail;
            tail = tail->pre;
            tail->next = nullptr;
            delete temp;

        }
    }

    void Display()
    {
        if (head == nullptr)
        {
            cout << "Linked list Underflow.\n";
        }
        else
        {
            node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    doublyLinkedList dLinkedList;

    dLinkedList.insertAtBeginning(675);
    dLinkedList.insertAtBeginning(15);
    dLinkedList.insertAtBeginning(2);
    dLinkedList.insertAtBeginning(12);
    dLinkedList.insertAtBeginning(234);
    dLinkedList.insertAtBeginning(32);
    dLinkedList.insertAtEnd(20);
    dLinkedList.insertAtBeginning(5);
    dLinkedList.Display();

    dLinkedList.deleteFromBeginning();
    dLinkedList.Display();

    dLinkedList.deleteFromEnd();
    dLinkedList.Display();

    dLinkedList.deleteFromBeginning();
    dLinkedList.Display();

    cout << endl;
    return 0;
}