#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int capacity;
    int top = -1;

public:
    stack(int size)
    {
        capacity = size;
        arr = new int[size];
    }
    ~stack()
    {

        free(arr);
    }
    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is Overflow.\n";
        }
        else
        {
            arr[++top] = value;
            cout << "Inserted value is: " << arr[top] << endl;
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow.\n";
            return -1;
        }
        else
        {

            cout << "popped value is: " << arr[top] << endl;
            return arr[top--];
        }
    }
    void peek() const
    {
        cout << "Top: " << arr[top] << endl;
    }
    void show()
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
        arr.push(i + 1);
    }
    cout << "First ARRAY.\n";
    arr.show();
    cout << "------------------------------\n";
    stack arr2(5);
    arr2.push(arr.pop());
    arr2.push(arr.pop());
    arr2.push(arr.pop());
    arr2.push(arr.pop());
    arr2.push(arr.pop());
    arr2.push(arr.pop());
    arr2.push(arr.pop());
    cout << "------------------------------\n";

    cout << "Second ARRAY.\n";
    arr2.show();

    cout << endl;
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;
//     node(int data = 0) : data(data), next(nullptr) {}
// };

// class stack
// {
// private:
//     node *top;

// public:
//     stack() : top(nullptr) {}
//     ~stack()
//     {
//         while (top != nullptr)
//         {
//             node *temp = top;
//             top = top->next;
//             delete temp;
//         }
//     }
//     void push(int value)
//     {
//         if (value == -1)
//         {
//             cout << "Value is not Pushed.\n";
//             return;
//         }

//         node *newnode = new node(value);
//         if (top == nullptr)
//         {
//             top = newnode;
//         }
//         else
//         {
//             newnode->next = top;
//             top = newnode;
//         }
//         cout << "Pushed Value is: " << value << endl;
//     }
//     int pop()
//     {
//         if (top == nullptr)
//         {
//             cout << "Empty.\n";
//             return -1;
//         }
//         node *temp = top;
//         int poppedData = top->data;
//         top = top->next;
//         delete temp;
//         cout << "Popped Value is: " << poppedData << endl;
//         return poppedData;
//     }
//     int peek()
//     {
//         if (top == nullptr)
//         {
//             cout << "Empty.\n";
//             return -1;
//         }
//         cout << "Top Value: " << top->data << endl;
//         return top->data;
//     }
//     void show()
//     {
//         if (top == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         node *temp = top;
//         while (temp != nullptr)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     stack s;
//     s.push(23);
//     s.push(323);
//     s.push(3);
//     s.push(11);
//     s.push(65);
//     cout << "First Stack: ";
//     s.show();

//     stack ss;
//     ss.push(s.pop());
//     ss.push(s.pop());
//     ss.push(s.pop());
//     ss.push(s.pop());
//     ss.push(s.pop());
//     ss.push(s.pop());
//     cout << "First Stack: ";
//     s.show();
    
//     cout << "Second Stack: ";
//     ss.show();
//     cout << endl;
//     return 0;
// }