
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addOnRear(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Q2: Remove Nth Node From End of List : Given a linked list, remove the n-th node from the end of list
    // and return its head.
    // Example:
    // Given linked list: 1->2->3->4->5, and n = 2.
    // After removing the second node from the end, the linked list becomes 1->2->3->5.

    void removingNthNodeFromTail(int n)
    {
        if (head == nullptr)
            return;
        Node *cur = head;
        int count = 0;
        while (cur != nullptr)
        {
            cur = cur->next;
            count++;
        }
        cout << "Count: " << count << endl;
        int nthNode = count - n;
        cout << "Nth Node: " << nthNode << endl;

        if (nthNode == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        cur = head;
        Node *prev = nullptr;
        count = 0;

        while (cur != nullptr && count < nthNode)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if (cur == nullptr)
        {
            return;
        }
        prev->next = cur->next;
        delete cur;
    }

    void show()
    {
        Node *temp = head;
        cout << "list: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.addOnRear(1);
    list.addOnRear(2);
    list.addOnRear(3);
    list.addOnRear(4);
    list.addOnRear(5);
    list.show();
    list.removingNthNodeFromTail(2);
    list.show();
    cout << endl;
    return 0;
}