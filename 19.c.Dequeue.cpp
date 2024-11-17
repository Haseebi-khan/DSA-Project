#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size)
    {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = 0;
    }

    ~Deque()
    {
        delete[] arr;
    }

    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Deque is full.\n";
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        cout << x << " added to front of deque.\n";
    }

    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Deque is full.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        cout << x << " added to rear of deque.\n";
    }

    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty.\n";
            return -1;
        }
        int removed = arr[front];
        front = (front + 1) % capacity;
        cout << removed << " removed from front of deque.\n";
        return removed;
    }

    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty.\n";
            return -1;
        }
        int removed = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        cout << removed << " removed from rear of deque.\n";
        return removed;
    }

    bool isEmpty()
    {
        return (front == rear + 1) % capacity == 0;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }
};

int main()
{
    Deque deque(5);

    deque.insertRear(10);
    deque.insertFront(20);
    deque.insertRear(30);

    cout << "Deleting from front:\n";
    deque.deleteFront();

    cout << "Deleting from rear:\n";
    deque.deleteRear();

    return 0;
}


#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size)
    {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = 0;
    }

    ~Deque()
    {
        delete[] arr;
    }

    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Deque is full.\n";
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        cout << x << " added to front of deque.\n";
    }

    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Deque is full.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        cout << x << " added to rear of deque.\n";
    }

    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty.\n";
            return -1;
        }
        int removed = arr[front];
        front = (front + 1) % capacity;
        cout << removed << " removed from front of deque.\n";
        return removed;
    }

    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty.\n";
            return -1;
        }
        int removed = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        cout << removed << " removed from rear of deque.\n";
        return removed;
    }

    bool isEmpty()
    {
        return (front == rear + 1) % capacity == 0;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }
};

int main()
{
    Deque deque(5);

    deque.insertRear(10);
    deque.insertFront(20);
    deque.insertRear(30);

    cout << "Deleting from front:\n";
    deque.deleteFront();

    cout << "Deleting from rear:\n";
    deque.deleteRear();

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = x;
        cout << x << " added to front of deque.\n";
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        cout << x << " added to rear of deque.\n";
    }

    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        int result = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        cout << result << " removed from front of deque.\n";
        return result;
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        int result = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        cout << result << " removed from rear of deque.\n";
        return result;
    }
};
