
#include <iostream>
using namespace std;

// Implement insert and delete operations at a specific position
// in the doubly linked list, where the user can specify the index.

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
    // Insert At Specific Position.
    void insertAtPodition(int value, int pos)
    {

        if (head == nullptr || pos <= 0)
        {
            insertAtBeginning(value);
        }
        else
        {
            int count = 0;
            node *current = head;
            while (current != nullptr && count < pos)
            {
                current = current->next;
                count++;
            }
            if (current == nullptr)
            {
                insertAtEnd(value);
            }
            else
            {

                node *newNode = new node(value);
                node *previous = current->pre;

                newNode->next = current;
                newNode->pre = previous;

                current->pre = newNode;
                if (previous != nullptr)
                {
                    previous->next = newNode;
                }
                else
                {
                    head = newNode;
                }
            }
        }
    }

    // Delte At Position.
    void deleteFromPosition(int pos)
    {
        if (head == nullptr || pos <= 0)
        {
            deleteFromBeginning();
            return;
        }
        int count = 0;
        node *current = head;
        while (current != nullptr && count < pos)
        {
            current = current->next;
            count++;
        }
        if (current == nullptr)
        {
            deleteFromEnd();
        }
        else
        {
            node *previous = current->pre;
            node *forward = current->next;

            if (previous != nullptr)
            {
                previous->next = forward;
            }
            else
            {
                head = forward;
            }
            if (forward != nullptr)
            {
                forward->pre = previous;
            }
            else
            {
                tail = previous;
            }
            delete current;
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
        if (head == nullptr)
        {
            return;
        }
        else if (head == tail)
        {
            delete head; // tail;
            // doublyLinkedList();
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->pre = nullptr;
            delete temp;
        }
    }
    // delete from the end.
    void deleteFromEnd()
    {
        if (head == nullptr) // Empty list case
        {
            return;
        }
        else if (head == tail)
        {
            delete head; // tail;
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

    dLinkedList.insertAtPodition(23,2);
    dLinkedList.insertAtPodition(45,0);
    dLinkedList.insertAtPodition(1,4);
    dLinkedList.Display();

    dLinkedList.deleteFromPosition(1);
    dLinkedList.deleteFromPosition(4);
    dLinkedList.deleteFromPosition(2);
    dLinkedList.Display();

    cout << endl;
    return 0;
}
