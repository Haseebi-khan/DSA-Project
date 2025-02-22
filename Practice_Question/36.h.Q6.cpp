
// Q6: Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers
// from the original list.
// Example 1:
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5

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

    // Q6: Given a sorted linked list, delete all nodes that have duplicate numbers,
    // leaving only distinct numbers
    // from the original list.
    // Example 1:
    // Input: 1->2->3->3->4->4->5
    // Output: 1->2->5

    void duplicateNodes()
    {
        if (head == nullptr && head->next == nullptr)
            return;

        Node *dummy = new Node(0);
        dummy->next = head;
        Node *prev = dummy;
        Node *cur = head;
        // Input: 1->2->3->3->4->4->5
        while (cur != nullptr)
        {
            bool found = false;
            while (cur->next != nullptr && cur->data == cur->next->data)
            {
                found = true;
                Node *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }

            if (found)
            {
                Node *temp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete temp;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
            cout << prev<<endl;
        }
        head = dummy->next;
        delete dummy;
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
    list.addOnRear(1);
    list.addOnRear(2);
    // list.addOnRear(3);
    // list.addOnRear(3);
    // list.addOnRear(4);
    // list.addOnRear(4);
    // list.addOnRear(5);
    list.show();
    list.duplicateNodes();
    list.show();

    cout << endl;
    return 0;
}
