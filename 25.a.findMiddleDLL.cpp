
#include <iostream>
using namespace std;

// Find Middle Node
// Write a program to find the middle element of a singly linked list.

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

    // Find Middle Node
    // Write a program to find the middle element of a singly linked list.

    void middleNode()
    {
        if (head == nullptr)
        {
            cout << "Empty.\n";
        }
        else if (head == tail)
        {
            cout << "Its First Node and Data is: " << head->data << endl;
        }
        else
        {
            int count = 1;
            node *current = head;
            while (current != nullptr)
            {
                count++;
                current = current->next;
            }

            int middle = count / 2;
            current = head;

            count = 1;
            while (current != nullptr && count < middle)
            {
                count++;
                current = current->next;
            }
            cout << "Middle: " << current->data << endl;
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
    // Find Middle Node
    // Write a program to find the middle element of a singly linked list.

    // Second Approuch Middle node
    void middleNode_Second_Approuch()
    {
        if (head == nullptr)
        {
            cout << "empty.\n";
            return;
        }
        else if (head == tail)
        {
            cout << "First Node Data: " << head->data << endl;
            return;
        }
        node *fast = head;
        node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout  << slow->data << endl;
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
    dLinkedList.insertAtBeginning(5);
    cout << "List: ";
    dLinkedList.Display();

    // dLinkedList.deleteFromBeginning();
    // dLinkedList.Display();

    // dLinkedList.deleteFromEnd();
    // dLinkedList.Display();

    // dLinkedList.deleteFromBeginning();

    cout << "Middle Node data: ";
    dLinkedList.middleNode();

    cout << "Second_Approuch Middle Node data: ";

    dLinkedList.middleNode_Second_Approuch();
    

    cout << endl;
    return 0;
}
