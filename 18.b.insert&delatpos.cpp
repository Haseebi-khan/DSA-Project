#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value = 0) : data(value), next(nullptr) {}
};

class linkedlist
{
private:
    node *head, *tail;

public:
    linkedlist() : head(nullptr), tail(nullptr) {}

    void insertAtRear(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtFront(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtPos(int value, int pos)
    {
        if (head == nullptr || pos <= 0)
        {
            insertAtFront(value);
        }
        else
        {
            node *current = head;
            int count = 0;
            while (current != nullptr && count < pos - 1)
            {
                current = current->next;
                count++;
            }
            if (current == nullptr)
            {
                insertAtRear(value);
            }
            else
            {
                node *newNode = new node(value);
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void show()
    {
        node *temp = head;
        cout << "Linkedlist: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteFromRear()
    {
        if (head == nullptr)
        {
            cout << "Stack is underflow\n";
        }
        else if (head == tail)
        {
            delete head, tail;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    void deleteFromFront()
    {
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            head = temp->next;
            delete temp;
        }
    }

    void deleteFromPos(int pos)
    {
        if (head == nullptr)
        {
            cout << "Stack underflow.\n";
        }
        else if (pos <= 0)
        {
            deleteFromFront();
        }
        else
        {
            node *current = head;
            node *previous = nullptr;
            int count = 0;
            while (current != nullptr && count < pos - 1)
            {
                previous = current;
                current = current->next;
                count++;
            }
            if (current == nullptr)
            {
                cout << "Out of Range.\n";
            }
            else
            {
                previous->next = current->next;
                if (current == tail)
                {
                    tail = previous;
                }
                delete current;
            }
        }
    }
};

int main()
{

    linkedlist list;
    list.insertAtRear(10);
    list.insertAtFront(20);
    list.insertAtFront(20);
    list.insertAtFront(20);
    list.insertAtFront(20);
    list.show();
    list.insertAtPos(15, 1);
    list.insertAtPos(15, 1);
    list.insertAtPos(15, 1);
    list.insertAtPos(15, 1);
    list.show();

    list.deleteFromPos(1);
    list.show();

    cout << endl;
    return 0;
}