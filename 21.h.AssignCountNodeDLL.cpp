#include <iostream>
using namespace std;

// Implement a function to count the number of nodes in a doubly linked list.

#include <iostream>
using namespace std;

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

    // Implement a function to count the number of nodes in a doubly linked list.
    int countTheNumberOfNodes()
    {
        if (head == nullptr)
        {
            cout << "lindlist is empty." << endl;
            return 0;
        }
        node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
           temp = temp->next;
           count++;
        }
        return count;
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
    dLinkedList1.insertAtEnd(6);
    dLinkedList1.insertAtEnd(5);
    dLinkedList1.insertAtEnd(4);
    dLinkedList1.insertAtEnd(3);
    dLinkedList1.insertAtEnd(2);
    dLinkedList1.insertAtEnd(1);
    dLinkedList1.Display();
    cout << "Numeber of Nodes: " <<dLinkedList1.countTheNumberOfNodes();

    cout << endl;
    return 0;
}