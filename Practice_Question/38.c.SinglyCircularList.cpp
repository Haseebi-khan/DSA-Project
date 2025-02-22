#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data = 0) : data(data), next(nullptr) {}
};

class SingleCircularLL
{
private:
    node *head, *tail;

public:
    SingleCircularLL() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    void sortedInsert(int value)
    {
        node *newNode = new node(value);

        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        if (value <= head->data)
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
            return;
        }

        node *current = head;
        while (current->next != head && current->next->data < value)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        if (current == tail)
        {
            tail = newNode;
        }
    }

    void show()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main()
{
    SingleCircularLL list;

    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(5);
    list.insertAtEnd(7);

    cout << "List: ";
    list.show();

    list.sortedInsert(0);
    list.sortedInsert(4);
    list.sortedInsert(8);

    cout << "Sorted List: ";
    list.show();

    return 0;
}
