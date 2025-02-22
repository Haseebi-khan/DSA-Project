#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear;
    int cap;

public:
    Queue(int n)
    {
        arr = new int[9];
        rear = -1;
        front = -1;
        cap = n;
    }
    void push(int value)
    {
        if (rear == cap - 1)
        {
            cout << "Queue is Overflow.\n";
            return;
        }
        else
        {
            if (front == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = value;
        }
    }

    void pop()
    {
        if (front == -1)
        {
            cout << "Queue is Underflow.\n";
            return;
        }
        arr[front++];

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    void show()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);

    q.push(23);
    q.push(4);
    q.push(5);
    q.push(6);

    q.show();

    q.pop();
    q.pop();
    q.pop();
    q.show();
    cout << endl;
    cout << q.peek() <<endl;
    return 0;
}