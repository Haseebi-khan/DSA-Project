// 7. Reverse the Circular Linked List:
//     ◦ Write a program to reverse the entire circular linked list while maintaining its circular structure.
//     ◦ Example:
//         ▪ Input: 1 -> 2 -> 3 -> 4 -> (back to 1)
//         ▪ Output: 4 -> 3 -> 2 -> 1 -> (back to 4)

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

    void reverse()
    {
        if (head == nullptr || head == tail)
        {
            cout << "Empty.\n";
            return;
        }

        node *prev = nullptr;
        node *current = head;
        node *nextNode = nullptr;
        tail = head;

        do
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        head = prev;
        tail->next = head;
    }
};

int main()
{
    SingleCircularLL list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "List: ";
    list.show();

    list.reverse();

    cout << "Reversed List: ";
    list.show();

    return 0;
}
