#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int top = -1;
    int capacity;

public:
    stack(int size)
    {
        arr = (int *)malloc(size * sizeof(int));
        capacity = size;
    }
    ~stack()
    {
        free(arr);
    }
    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow." << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Insertion Complete." << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow." << endl;
        }
        else
        {
            arr[top--];
        }
    }
    void peek() const
    {
        cout << "Top: " << top << endl;
    }
    void display() const
    {
        if (top == -1)
        {
            cout << "Stack is Empty.\n";
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    stack arr(5);

    for (int i = 0; i < 5; i++)
    {
        arr.push(i+1);
    }
    arr.display();

    arr.pop();
    arr.pop();
    arr.display();
    arr.pop();


    

    cout << endl;
    return 0;
}

// ==================================================================================================================
// ==================================================================================================================
// ==================================================================================================================

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// class Stack
// {
// private:
//     int *arr;
//     int top;
//     int capacity;

// public:
//     Stack(int size)
//     {
//         arr = (int *)malloc(size * sizeof(int));
//         capacity = size;
//         top = -1;
//     }
//     ~Stack()
//     {
//         free(arr);
//     }

//     void push(int x)
//     {
//         if (isFull())
//         {
//             cout << "Stack is Full.\n";
//             return;
//         }
//         else
//         {
//             arr[++top] = x;
//             cout << "Insertion is complete.\n";
//         }
//     }

//     int peek()
//     {
//         if (isEmpty())
//         {
//         }
//         cout << "Stack is empty." << endl;
//         return -1;
//         return arr[top];
//     }

//     int pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Array is Empty.";
//             return -1;
//         }
//         return arr[top--];
//     }

//     void display()
//     {
//         for (int i = 0; i <= top; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

//     int size() const
//     {
//         return top + 1;
//     }

//     bool isEmpty() const
//     {
//         return top == -1;
//     }

//     bool isFull() const
//     {
//         return top == capacity - 1;
//     }
// };

// int main()
// {

//     Stack stack(6);

//     for (int i = 0; i < 6; i++)
//     {
//         stack.push(i + 1);
//     }

//     cout << "Current stack using display Func : ";
//     stack.display();

//     cout << "Popping elements to show LIFO behavior:" << endl;
//     while (!stack.isEmpty())
//     {
//         cout << "Popped: " << stack.pop() << endl;
//     }
//     cout << endl;
//     return 0;
// }