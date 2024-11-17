#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    CircularQueue(int size)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
        cout << x << " added to circular queue.\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        int removed = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << removed << " removed from circular queue.\n";
        return removed;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == capacity;
    }
};

int main()
{
    CircularQueue cqueue(5);

    cqueue.enqueue(10);
    cqueue.enqueue(20);
    cqueue.enqueue(30);
    cqueue.enqueue(40);
    cqueue.enqueue(50);

    cout << "Front element is: " << cqueue.getFront() << endl;
    cout << "Rear element is: " << cqueue.getRear() << endl;

    cqueue.dequeue();
    cqueue.enqueue(60);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// class CircularQueue
// {
// private:
//     int *arr;
//     int front;
//     int rear;
//     int capacity;

// public:
//     CircularQueue(int size)
//     {
//         arr = new int[size];
//         capacity = size;
//         front = rear = -1;
//     }

//     ~CircularQueue()
//     {
//         delete[] arr;
//     }

//     bool isFull()
//     {
//         return (rear + 1) % capacity == front;
//     }

//     bool isEmpty()
//     {
//         return front == -1;
//     }

//     void enqueue(int x)
//     {
//         if (isFull())
//         {
//             cout << "Queue is full.\n";
//             return;
//         }

//         if (isEmpty())
//         {
//             front = rear = 0;
//         }
//         else
//         {
//             rear = (rear + 1) % capacity;
//         }
//         arr[rear] = x;
//         cout << x << " added to the queue.\n";
//     }

//     int dequeue()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty.\n";
//             return -1;
//         }
//         int result = arr[front];
//         if (front == rear)
//         {
//             front = rear = -1;
//         }
//         else
//         {
//             front = (front + 1) % capacity;
//         }
//         cout << result << " removed from the queue.\n";
//         return result;
//     }

//     int getFront()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty.\n";
//             return -1;
//         }
//         return arr[front];
//     }

//     int getRear()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty.\n";
//             return -1;
//         }
//         return arr[rear];
//     }
// };
