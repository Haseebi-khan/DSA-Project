#include <iostream>
using namespace std;

int const s = 5;
int CirQueue[s];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

bool isFull()
{
    return ((rear + 1) % s == front);
}

void Enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is Overflow.\n";
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % s; // Proper circular increment
    }
    CirQueue[rear] = value;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Underflow.\n";
        return;
    }
    if (front == rear)
    {
        // Only one element in the queue
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % s; // Proper circular increment
    }
}

void show()
{
    if (isEmpty())
    {
        cout << "Queue is Underflow.\n";
        return;
    }
    cout << "Queue contents: ";
    int i = front;
    while (true)
    {
        cout << CirQueue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % s; // Circular iteration
    }
    cout << endl;
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    show();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    show();

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(4);
    Enqueue(4);
    Enqueue(4);

    show();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    show();


    return 0;
}
