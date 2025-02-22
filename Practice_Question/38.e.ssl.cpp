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

    void deleteNodes(int j, int k)
    {
        if (head == nullptr || j > k || j <= 0)
        {
            cout << "Empty list.\n";
            return;
        }

        node *prev = nullptr, *current = head;
        int count = 1;

        while (count < j && current->next != head)
        {
            prev = current;
            current = current->next;
            count++;
        }

        if (count < j)
        {
            cout << "Position j is out of bounds.\n";
            return;
        }

        node *start = current;
        int deleteCount = 0;
        while (deleteCount < k - j + 1 && current != head)
        {
            node *temp = current;
            current = current->next;
            delete temp;
            deleteCount++;
        }

        if (prev == nullptr)
        {
            head = current;
            tail->next = head;
        }
        else
        {
            prev->next = current;
        }

        if (current == head)
        {
            tail = prev;
        }
    }
};

int main()
{
    SingleCircularLL list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    cout << "List: ";
    list.show();

    list.deleteNodes(2, 3);

    cout << "List: ";
    list.show();

    return 0;
}
