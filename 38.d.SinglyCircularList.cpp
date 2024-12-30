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
            cout << "empty.\n";
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

    void reverseKNodes(int k)
    {
        if (head == nullptr || k <= 1)
        {
            return;
        }

        node *current = head, *prevTail = nullptr, *newHead = nullptr;
        bool firstPass = true;

        do
        {
            node *segmentHead = current, *prev = nullptr;
            int count = 0;

            do
            {
                node *nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
                count++;
            } while (count < k && current != head);

            if (firstPass)
            {
                newHead = prev;
                firstPass = false;
            }
            else
            {
                prevTail->next = prev;
            }

            prevTail = segmentHead;
        } while (current != head);

        prevTail->next = newHead;
        head = newHead;
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
    list.insertAtEnd(7);

    cout << "List: ";
    list.show();
    list.reverseKNodes(3);
    cout << "Reverse List 3 Nodes: ";
    list.show();

    return 0;
}
