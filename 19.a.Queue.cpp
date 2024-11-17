#include <iostream>
using namespace std;

int queue[5], n = 5, front = -1, rear = -1;

void Insert()
{
    int val;
    if (rear == n - 1)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {

        if (front == -1)
        {
            front = 0;
        }
        cout << "Insert the element in queue : ";
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}
void Delete()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow ";
        return;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void Display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}
int main()
{

    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();

    Display();

    Delete();
    Delete();
    Delete();
    Delete();
    Delete();
    Delete();

    cout << "\nFront: " << front << ", Rear: " << rear << ".\n";

    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();

    cout << "\n";

    Display();

    return 0;
}