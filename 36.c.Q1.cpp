// Q1: a. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in
// reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked
// list. [You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Moreover, keep in mind the concept of carry in addition]
// Example:
// Enter the First number: 342
// Enter the Second Number: 465
// Linked List for the first number: (2 -> 4 -> 3)
// Linked List for the second number: (5 -> 6 -> 4)
// Add the Linked Lists: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Answer: 807
// Explanation: 342 + 465 = 807.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0) : data(data) {}
};

class SLL
{
private:
    Node *head;

public:
    SLL() : head(nullptr) {}
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void show()
    {
        if (head == nullptr)
        {
            cout << "Empty SLL.\n";
            return;
        }
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int static ADDTwoLLs(SLL const a, SLL const b)
    {
        int num1 = 0, num2 = 0;
        Node *temp = a.head;
        while (temp != nullptr)
        {
            num1 = num1 * 10 + temp->data;
            temp = temp->next;
        }

        Node *temp2 = b.head;
        while (temp2 != nullptr)
        {
            num2 = num2 * 10 + temp2->data;
            temp2 = temp2->next;
        }

        int sum = num1 + num2;
        return sum;
    }
};

int main()
{
    SLL a, b;

    a.insertAtHead(2);
    a.insertAtHead(4);
    a.insertAtHead(3);
    b.insertAtHead(5);
    b.insertAtHead(6);
    b.insertAtHead(4);
    a.show();
    b.show();
    cout << "Total Sum: " << SLL::ADDTwoLLs(a, b) << endl;

    cout << endl;
    return 0;
}