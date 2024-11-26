#include <iostream>
using namespace std;

// Write a program to merge two doubly linked
// lists into a single sorted doubly linked list.

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
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert node at the end
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

    // Function to display the list
    void Display()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty." << endl;
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

    // Write a program to merge two doubly linked
    // lists into a single sorted doubly linked list.

    static doublyLinkedList mergeDLL(doublyLinkedList &_1st, doublyLinkedList &_2nd)
    {
        doublyLinkedList mergeObj;
        node *head1 = _1st.head;
        node *head2 = _2nd.head;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data <= head2->data)
            {
                mergeObj.insertAtEnd(head1->data);
                head1 = head1->next;
            }
            else
            {
                mergeObj.insertAtEnd(head2->data);
                head2 = head2->next;
            }
        }

        while (head1 != nullptr)
        {
            mergeObj.insertAtEnd(head1->data);
            head1 = head1->next;
        }
        while (head2 != nullptr)
        {
            mergeObj.insertAtEnd(head2->data);
            head2 = head2->next;
        }
        return mergeObj;
    }
};

int main()
{
    doublyLinkedList dLinkedList1;
    dLinkedList1.insertAtEnd(5);
    dLinkedList1.insertAtEnd(3);
    dLinkedList1.insertAtEnd(4);
    dLinkedList1.insertAtEnd(1);
    dLinkedList1.Display();

    doublyLinkedList dLinkedList2;
    dLinkedList2.insertAtEnd(2);
    dLinkedList2.insertAtEnd(3);
    dLinkedList2.insertAtEnd(2);
    dLinkedList2.insertAtEnd(4);


    dLinkedList2.Display();

    doublyLinkedList mergedList = doublyLinkedList::mergeDLL(dLinkedList1, dLinkedList2);

    cout << "Merged list: ";
    mergedList.Display();

    return 0;
}
