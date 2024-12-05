#include <iostream>
using namespace std;

// Implement a function to reverse the entire doubly linked list
// without using extra space.

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
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }


    // Implement a function to reverse the entire doubly linked list
    // without using extra space.

    void reverseDLL()
    {
        if (head == nullptr)
        {
            cout << "Linkedlist is empty.\n";
            return;
        }
        else
        {
            node *newhead = nullptr;
            node *temp = head;
            while (temp != nullptr)
            {
                node *swap = temp->next;
                temp->next = temp->pre;
                temp->pre = swap;
                temp = temp->pre;
            }
            newhead = tail;
            tail = head;
            head = newhead;
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

    void Display()
    {
        if (head == nullptr)
        {
            cout << "The linked list is empty." << endl;
            return;
        }

        node *temp = head;
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
    doublyLinkedList dLinkedList;

    dLinkedList.insertAtEnd(1);
    dLinkedList.insertAtEnd(2);
    dLinkedList.insertAtEnd(3);
    dLinkedList.insertAtEnd(4);
    dLinkedList.insertAtEnd(5);
    dLinkedList.insertAtEnd(6);
    dLinkedList.insertAtEnd(7);

    dLinkedList.Display();

    dLinkedList.reverseDLL();

    dLinkedList.searchData__Delete(5);

    dLinkedList.Display();

    cout << endl;
    return 0;
}
