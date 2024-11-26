
#include <iostream>
using namespace std;

// Circular Linked List (CLL)

class node
{
public:
    int data;
    node *next;
    node *pre;
    node(int value = 0) : data(value), next(nullptr), pre(nullptr) {}
};

// 1 - Implement a simple Circular linked list
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
            deleteFromBeginning();
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
            // newNode->next =head;
            // newNode->pre = tail;
            // head = newNode;

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
            // tail->next = newNode;
            // newNode->pre = tail;
            // newNode->next = head;
            // tail = newNode;

            tail->next = newNode;
            newNode->pre = tail;
            newNode->next = head;
            head->pre = newNode;
            tail->next = newNode;
            head->pre = newNode;
            tail = newNode;
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
            // doublyLinkedList();
            head = tail = nullptr;
        }
        else
        {
            // node *temp = head;
            // head = head->next;
            // head->pre = tail;
            // delete temp;

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
            // doublyLinkedList();
            head = tail = nullptr;
        }
        else
        {
            // node *temp = tail;
            // tail = tail->pre;
            // tail->next = head;
            // delete temp;

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

    dLinkedList.insertAtEnd(1);
    dLinkedList.insertAtEnd(2);
    dLinkedList.insertAtEnd(3);
    dLinkedList.insertAtEnd(4);
    dLinkedList.insertAtEnd(5);
    dLinkedList.insertAtBeginning(20);
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