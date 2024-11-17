#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full.\n";
            return;
        }
        arr[++rear] = x;
        cout << x << " added to the queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return -1;
        }
        int removed = arr[front++];
        cout << removed << " removed from the queue.\n";
        return removed;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element is: " << queue.getFront() << endl;
    cout << "Rear element is: " << queue.getRear() << endl;

    queue.dequeue();
    queue.dequeue();

    return 0;
}
