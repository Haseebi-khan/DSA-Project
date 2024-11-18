#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    Queue(int size)
    {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }

    // Enqueue an element
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full.\n";
            return;
        }

        if (front == -1)  // Queue is empty, set front to 0
        {
            front = 0;
        }

        arr[++rear] = x;  // Add element to the rear of the queue
        cout << x << " added to the queue.\n";
    }

    // Dequeue an element
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty.\n";
            return -1;
        }

        int removed = arr[front++];  // Remove element from the front of the queue
        if (front > rear)  // Queue is empty after dequeue
        {
            front = rear = -1;  // Reset the queue
        }
        cout << removed << " removed from the queue.\n";
        return removed;
    }

    // Get the front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    // Check if the queue is full
    bool isFull()
    {
        return rear == capacity - 1;
    }
};

int main()
{
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);  // Add more elements
    queue.enqueue(50);
    queue.enqueue(60);  // This will show "Queue is Full"

    cout << "Front element is: " << queue.getFront() << endl;
    cout << "Rear element is: " << queue.getRear() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front element after dequeue is: " << queue.getFront() << endl;
    cout << "Rear element after dequeue is: " << queue.getRear() << endl;

    return 0;
}
