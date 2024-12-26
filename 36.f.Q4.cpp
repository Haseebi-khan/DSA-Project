
// Q4: Given a linked list, swap every two adjacent nodes and return its head. Example:
// Given 1->2->3->4, you should return the list as 2->1->4->3.
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

    // Q4: Given a linked list, swap every two adjacent nodes and return its head. Example:
    // Given ( dummy 0-> ) 1-> 2-> 3-> 4, you should return the list as 2->1->4->3.
                //   p     c   n   

    void swapAdjacentNodes()
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *prev = dummy;
        Node *cur = head;

        while (cur && cur->next)
        {
            Node *next = cur->next;
            cur->next = next->next;
            next->next = cur;
            prev->next = next;

            prev = cur;
            cur = cur->next;
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
    list.addOnRear(2);
    list.addOnRear(3);
    list.addOnRear(4);
    list.addOnRear(5);
    list.addOnRear(6);
    list.show();
    list.swapAdjacentNodes();
    list.show();

    cout << endl;
    return 0;
}