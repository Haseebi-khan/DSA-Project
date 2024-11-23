#include <iostream>
using namespace std;

const int n = 5;
int queue[n], front = -1, rear = -1;

void Enqueue(int value)
{
    if (rear == n - 1)
    {
        cout << "Queue Overflow." << endl;
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        queue[rear] = value;
    }
}

void Dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow." << endl;
    }
    else
    {
        cout << "Dequeued: " << queue[front] << endl;
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
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) // Fix here
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Enqueue(45);
    Enqueue(3);
    Enqueue(2);
    Enqueue(1);
    Enqueue(9);
    Enqueue(7); // This will cause "Queue Overflow" because the queue size is 5

    Display();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    // Dequeuing here will result in "Queue Underflow" after all elements are removed
    Dequeue();
    Dequeue();

    cout << "\nFront: " << front << ", Rear: " << rear << ".\n";

    Enqueue(56);
    Enqueue(44);
    Enqueue(33);
    Enqueue(22);
    Enqueue(11);
    Enqueue(5); // This will cause "Queue Overflow" since the queue size is 5

    cout << "\n";
    Display();
    cout << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int queue[5], n = 5, front = -1, rear = -1;

// void Insert()
// {
//     int val;
//     if (rear == n - 1)
//     {
//         cout << "Queue Overflow" << endl;
//     }
//     else
//     {

//         if (front == -1)
//         {
//             front = 0;
//         }
//         cout << "Insert the element in queue : ";
//         cin >> val;
//         rear++;
//         queue[rear] = val;
//     }
// }
// void Delete()
// {
//     if (front == -1 || front > rear)
//     {
//         cout << "Queue Underflow ";
//         return;
//     }
//     else
//     {
//         cout << "Element deleted from queue is : " << queue[front] << endl;
//         front++;
//         if (front > rear)
//         {
//             front = rear = -1;
//         }
//     }
// }
// void Display()
// {
//     if (front == -1)
//         cout << "Queue is empty" << endl;
//     else
//     {
//         cout << "Queue elements are : ";
//         for (int i = front; i <= rear; i++)
//             cout << queue[i] << " ";
//         cout << endl;
//     }
// }
// int main()
// {

//     Insert();
//     Insert();
//     Insert();
//     Insert();
//     Insert();
//     Insert();

//     Display();

//     Delete();
//     Delete();
//     Delete();
//     Delete();
//     Delete();
//     Delete();

//     cout << "\nFront: " << front << ", Rear: " << rear << ".\n";

//     Insert();
//     Insert();
//     Insert();
//     Insert();
//     Insert();
//     Insert();

//     cout << "\n";

//     Display();

//     return 0;
// }