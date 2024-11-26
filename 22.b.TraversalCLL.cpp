#include <iostream>
using namespace std;

// Implement a traversal function that starts from the head and
// loops around back to the head

// Circular Linked List (CLL)

class node
{
public:
    int data;
    node *next;
    node *pre;
    node(int value = 0) : data(value), next(nullptr), pre(nullptr) {}
};

class doublyLinkedList
{
private:
    node *head, *tail;

public:
    doublyLinkedList() : head(nullptr), tail(nullptr) {}
    // ~doublyLinkedList()
    // {
    //     while (head != nullptr)
    //     {
    //         node *temp = head;
    //         head = head->next;
    //         head->pre = tail;
    //         tail->next = head;
    //         delete temp;
    //         // segmatation fault due to exccessing tail next
    //     }
    // }

    //  insert at the end,
    void insertAtEnd(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            head->pre = tail;
            tail->next = head;
        }
        else
        {
            // tail->next = newNode;
            // newNode->pre = tail;
            // newNode->next = head;
            // tail = newNode;

            tail->next = newNode;
            newNode->pre = tail;
            newNode->next = head;
            // why
            head->pre = newNode;
            tail->next = newNode;
            head->pre = newNode;
            tail = newNode;
        }
    }

    //  delete from the beginning,

    void Display()
    {
        if (head == nullptr)
        {
            cout << "CLL is empty." << endl;
            return;
        }
        node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    doublyLinkedList dLinkedList;

    dLinkedList.insertAtEnd(1);
    dLinkedList.insertAtEnd(2);
    dLinkedList.insertAtEnd(3);
    dLinkedList.insertAtEnd(4);
    dLinkedList.insertAtEnd(5);
    dLinkedList.Display();

    cout << endl;
    return 0;
}