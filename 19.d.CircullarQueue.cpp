#include <iostream>
using namespace std;

int CircularQueue[5];
int rear = -1, front = 0, qsize = 5, count = 0;

void insertq(int value)
{
    if (count == qsize)
    {
        cout << "Queue is Overflow.\n";
    }
    else
    {
        rear++;
        rear = rear % qsize;
        CircularQueue[rear] = value;
        count++;
        cout << "Value: " << value << " add to queue.\n";
    }
}

void delq()
{
    if (count == 0)
    {
        cout << "Queue is underflow.\n";
    }
    else
    {
        cout << "Remove value: " << CircularQueue[front] << endl;
        front++;
        front = front % qsize;
        count--;
    }
}

void show()
{
    if (count == 0)
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Elements in the circular queue are: ";
    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % qsize;
        cout << CircularQueue[index] << " ";
    }
    cout << endl;
}

int main()
{
    insertq(56);
    insertq(32);
    insertq(45);
    insertq(67);
    insertq(89);
    show();
    delq();
    delq();
    insertq(1);
    insertq(5);
    show();
    delq();
    delq();
    delq();
    delq();
    show();

    cout << endl;
    return 0;
}