#include <iostream>
using namespace std;

// Implement the delete operation to remove a specific node
// in a circular linked list by value or position
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
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            deleteFromBeginning();
        }
    }

    // Implement the delete operation to remove a specific node
    // in a circular linked list by value or position

    void insertAtPostion(int value, int pos)
    {
        if (head == nullptr || pos <= 0)
        {
            insertAtBeginning(value);
            return;
        }

        node *current = head;
        int iteration = 0;
        while (current->next != nullptr && iteration < pos)
        {
            current = current->next;
            iteration++;
        }

        if (current == head)
        {
            insertAtEnd(value);
        }
        else
        {
            node *newNode = new node(value);

            newNode->next = current;
            current->pre->next = newNode;
            newNode->pre = current->pre;
            current->pre = newNode;
        }
    }

    //  insert at the beginning,
    void insertAtBeginning(int value)
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
            newNode->next = head;
            newNode->pre = tail;
            head->pre = newNode;
            tail->next = newNode;
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
            head->pre = tail;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
            head->pre = tail;
            tail->next = head;
        }
    }

    //  delete from the beginning,
    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {

            node *temp = head;
            head = head->next;
            head->pre = tail;
            tail->next = head;
            delete temp;
        }
    }
    // delete from the end.
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {

            node *temp = tail;
            tail = tail->pre;
            tail->next = head;
            head->pre = tail;
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
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);

            cout << endl;
        }
    }
};

int main()
{
    doublyLinkedList dLinkedList;

    dLinkedList.insertAtBeginning(20);
    dLinkedList.insertAtEnd(1);
    dLinkedList.insertAtEnd(2);
    dLinkedList.insertAtEnd(3);
    dLinkedList.insertAtEnd(4);
    dLinkedList.insertAtEnd(5);
    dLinkedList.Display();

    dLinkedList.insertAtPostion(10, 3);
    dLinkedList.Display();

    cout << endl;
    return 0;
}