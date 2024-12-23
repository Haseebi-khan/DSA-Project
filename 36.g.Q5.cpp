// Q5: Given a linked list, rotate the list to the right by k places, where k is non-negative.
// Example 1:
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL

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

    // Q5: Given a linked list, rotate the list to the right by k places, where k is non-negative.
    // Example 1:
    // Input: 1->2->3->4->5->NULL, k = 2
    // Output: 4->5->1->2->3->NULL
    // Explanation:
    // rotate 1 steps to the right: 5->1->2->3->4->NULL
    // rotate 2 steps to the right: 4->5->1->2->3->NULL

    void RotationOfLL(int k)
    {
        if (head == nullptr && head->next == nullptr)
        {
            return;
        }

        for (int i = 0; i < k; i++)
        {
            Node *prev = nullptr;
            Node *cur = head;
            while (cur->next != nullptr)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
            cur->next = head;
            head = cur;
        }
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
    list.addOnRear(6);
    list.show();
    list.RotationOfLL(2);
    list.show();


    cout << endl;
    return 0;
}