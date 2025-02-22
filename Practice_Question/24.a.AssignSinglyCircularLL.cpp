#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int v = 0) : data(v), next(nullptr) {}
};

class SingleCircularLL
{
private:
    node *head, *tail;

public:
    SingleCircularLL() : head(nullptr), tail(nullptr) {}
    void insertAtFront(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

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

    void deleteFromFront()
    {
        if (head == nullptr)
        {
            cout << "Empty.\n";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "Empty.\n";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
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
    // void TraverseTailToEnd()
    // {
    //     if (head == nullptr)
    //     {
    //         cout << "List is empty.\n";
    //         return;
    //     }
    //     int count = 0;
    //     node *newHead = tail
    // }
};

int main()
{
    SingleCircularLL list;

    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "list: ";
    list.show();
    list.deleteFromFront();

    cout << "Deleting from front: ";
    list.show();

    list.deleteFromEnd();
    cout << "Deleting from end: ";
    list.show();
    cout << endl;
    return 0;
}