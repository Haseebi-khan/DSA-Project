
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};
// Question 7:

// Given a linked list and a value x,
// partition it such that all nodes less than x come before nodes greater than or equal to x.
// Example:
// Input: head = 1->4->3->2->5->2 1  and x = 3
// Output: 1->2->2->4->3->5
// Tasks:
// a. Write down an algorithm for the aforementioned problem.
// b. Write down code in C++ to accomplish the aforementioned task.

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

    // Input: head = 1->4->3->2->5->2 1  and x = 3
    // Output: 1->2->2->4->3->5

    void partitionOfNodes(int x = 3)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *lesshead = new Node(0);
        Node *greaterhead = new Node(0);

        Node *less = lesshead;
        Node *greater = greaterhead;

        Node *cur =head;

        while (cur!=nullptr)
        {
            if (cur->data < x)
            {
                less->next = cur;
                less = less->next;
            }else
            {
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }
        less->next = greaterhead->next;
        greater->next = nullptr;
        head = lesshead->next;

        delete lesshead,greaterhead; 
    }


    // void partitionOfNodes(int x = 3)
    // {
    //     if (head == nullptr || head->next == nullptr)
    //         return;

    //     Node *prev = nullptr;
    //     Node *cur = head;

    //     while (cur != nullptr && cur->data != x)
    //     {
    //         prev = cur;
    //         cur = cur->next;
    //     }

    //     Node *pos = cur;

    //     while (cur->next != nullptr)
    //     {
    //         if (cur->next->data <= pos->data)
    //         {
    //             prev->next = cur->next;
    //             pos->next = cur->next->next;
    //             prev = prev->next;
    //             cur = cur->next;
    //         }
    //         else
    //         {
    //             cur->next = cur->next->next;
    //         }
    //     }
    //     cur->next = nullptr;
    //     prev->next = pos;
    // }

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
    list.addOnRear(4);
    list.addOnRear(3);
    list.addOnRear(2);
    list.addOnRear(5);
    list.addOnRear(2);
    list.addOnRear(1);
    list.show();
    list.partitionOfNodes();
    list.show();

    cout << endl;
    return 0;
}
