

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














// #include <iostream>

// using namespace std;

// int CircularQueue[5];
// int rear = -1, front = 0, qsize = 5, count = 0;

// void enQueue(int value)
// {
//     if (count == qsize)
//     {
//         cout << "Queue is Overflow.\n";
//     }
//     else
//     {
//         rear++;
//         rear = rear % qsize;
//         CircularQueue[rear] = value;
//         count++;
//         cout << "Value: " << value << " add to queue.\n";
//     }
// }

// void deQueue()
// {
//     if (count == 0)
//     {
//         cout << "Queue is underflow.\n";
//     }
//     else
//     {
//         cout << "Remove value: " << CircularQueue[front] << endl;
//         front++;
//         front = front % qsize;
//         count--;
//     }
// }

// void show()
// {
//     if (count == 0)
//     {
//         cout << "Queue is empty.\n";
//         return;
//     }
//     cout << "Elements in the circular queue are: ";
//     for (int i = 0; i < count; i++)
//     {
//         int index = (front + i) % qsize;
//         cout << CircularQueue[index] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     enQueue(50);
//     enQueue(5);
//     enQueue(30);
//     enQueue(10);
//     enQueue(65);
//     show();

//     deQueue();
//     deQueue();
//     enQueue(3);
//     enQueue(1);
//     show();

//     deQueue();
//     deQueue();
//     deQueue();
//     deQueue();
//     deQueue();
//     deQueue();
//     show();

//     cout << endl;
//     return 0;
// }