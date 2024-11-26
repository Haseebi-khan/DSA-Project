#include <iostream>
using namespace std;

// Search for a node with a given value and
// delete it from the doubly linked list.

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

    // Search for a node with a given value and
    // delete it from the doubly linked list.

    void searchData__Delete(int value)
    {
        if (head == nullptr)
        {
            cout << "Linklist is empty." << endl;
            return;
        }
        bool found = false;
        node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << "Value " << current->data << " is going to delete." << endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (found)
        {
            node *temp = current->pre;
            temp->next = current->next;
            delete current;
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

    dLinkedList.searchData__Delete(5);

    dLinkedList.Display();

    cout << endl;
    return 0;
}
