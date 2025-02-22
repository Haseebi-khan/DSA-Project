#include <iostream>
using namespace std;

//  Implement a function to display the list

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

    //  from the head to the tail
    void displayHeadToTheTail()
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

    //  from the tail to the head.
    void displayTailToTheHead()
    {
        if (head == nullptr)
        {
            cout << "The linked list is empty." << endl;
            return;
        }

        node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->pre;
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
    cout << "Display funtion Head To The Tail." << endl;
    dLinkedList.displayHeadToTheTail();

    cout << "Display funtion Tail To The Head." << endl;
    dLinkedList.displayTailToTheHead();

    cout << endl;
    return 0;
}
