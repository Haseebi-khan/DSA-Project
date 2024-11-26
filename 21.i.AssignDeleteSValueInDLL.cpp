#include <iostream>
using namespace std;

// Write a function to delete all occurrences of a specific value in the doubly linked list.

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

    // delete all occurrences of a specific value
    void deleteAllOccurrencesOfASpecificValue(int value)
    {
        if (head == nullptr)
        {
            cout << "Linkedlist is empty." << endl;
            return;
        }

        node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                node *temp = current;
                current = current->pre;
                current->next = temp->next;
                delete temp;
            }

            current = current->next;
        }
    }
    // Function to insert node at the end
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

    // Function to display the list
    void Display()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty." << endl;
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
    doublyLinkedList dLinkedList1;
    dLinkedList1.insertAtEnd(7);
    dLinkedList1.insertAtEnd(4);
    dLinkedList1.insertAtEnd(5);
    dLinkedList1.insertAtEnd(4);
    dLinkedList1.insertAtEnd(3);
    dLinkedList1.insertAtEnd(4);
    dLinkedList1.insertAtEnd(1);
    dLinkedList1.Display();

    dLinkedList1.deleteAllOccurrencesOfASpecificValue(4);
    dLinkedList1.Display();

    cout << endl;
    return 0;
}