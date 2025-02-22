#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

class Queue
{
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    void show()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout << "Queue elements: ";
    q.show();

    q.dequeue();
    q.dequeue();

    cout << "Queue after dequeuing two elements: ";
    q.show();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
