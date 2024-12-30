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

    void removeDup()
    {
        if (head == nullptr || head->next == head)
        {
            return;
        }

        node *current = head;

        do
        {
            node *nextNode = current->next;
            if (current->data == nextNode->data)
            {
                current->next = nextNode->next;
                if (nextNode == tail)
                {
                    tail = current;
                }
                delete nextNode;
            }
            else
            {
                current = current->next;
            }
        } while (current != tail);
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
    list.insertAtEnd(2);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(3);
    list.insertAtEnd(5);
    list.insertAtEnd(5);

    cout << "List: ";
    list.show();
    list.removeDup();

    cout << "New List : ";
    list.show();

    return 0;
}
