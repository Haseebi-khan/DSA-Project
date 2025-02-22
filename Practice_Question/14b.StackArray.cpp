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
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow.\n";
        }
        else
        {
            cout << "popped value is: " << arr[top--] << endl;
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
    void shortStack()
    {
        if (top == -1)
        {
            cout << "Empty.\n";
            return;
        }

        for (int i = 0; i < top + 1; i++)
        {
            for (int j = 0; j < top + 1; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void reverse()
    {
        if (top == -1)
        {
            cout << "Stack is Empty. Cannot reverse.\n";
            return;
        }
        int temptop = top;
        for (int i = 0; i < top / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[temptop];
            arr[temptop] = temp;
            temptop--;
        }
    }
};

int main()
{
    stack s(5);
    s.push(47);
    s.push(34);
    s.push(3);
    s.push(2);
    s.push(45);
    s.push(1);
    s.push(3324);
    cout << "Stack Data: ";
    s.show();
    cout << "Sorted Stack: ";
    s.shortStack();
    s.show();
    cout << "Reverse Stack: ";
    s.reverse();
    s.show();

    cout << endl;
    return 0;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// // Stack implementation using String data type.

// class stack
// {
// private:
//     string *arr;
//     int top = -1;
//     int capacity;

// public:
//     stack(int size) : capacity(size)
//     {
//         arr = (string *)malloc(size * sizeof(string));
//     }
//     ~stack()
//     {
//         free(arr);
//     }
//     void push(string ch_string)
//     {
//         if (top == capacity - 1)
//         {
//             cout << "Stack is Overflow.\n";
//         }
//         else
//         {
//             arr[++top] = ch_string;
//             cout << "String had pushed: " << ch_string << endl;
//         }
//     }
//     void poped()
//     {
//         if (top == -1)
//         {
//             cout << "Stack is Underflow\n";
//         }
//         else
//         {
//             cout << "the string have poped: " << arr[top] << endl;
//             arr[top--];
//         }
//     }
//     void peek()
//     {
//         if (top != -1)
//         {
//             cout << "The peek is: " << arr[top] << endl;
//         }
//         else
//         {
//             cout << "Stack is Underflow.\n";
//         }
//     }
// };

// int main()
// {
//     stack arr(2);
//     arr.push("Haseeb khan");
//     arr.push("aaaaaaaaaaa");
//     arr.push("sssssssssss");
//     arr.push("rrrrrrrrrrr");

//     arr.peek();
//     arr.poped();
//     arr.poped();
//     arr.poped();
//     arr.poped();
//     arr.poped();

//     cout << endl;
//     return 0;
// }

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// // Stack implementation using char data type.

// class stack
// {
// private:
//     char *arr;
//     int top;
//     int capacity;

// public:
//     stack(int size) : capacity(size), top(-1)
//     {
//         arr = new char[size];
//     }
//     ~stack()
//     {
//         delete[] arr;
//     }
//     void push(char ch)
//     {
//         if (top == capacity - 1)
//         {
//             cout << "Stack is Overflow.\n";
//         }
//         else
//         {
//             arr[++top] = ch;
//             cout << "Character has been pushed: " << ch << endl;
//         }
//     }
//     void poped()
//     {
//         if (top == -1)
//         {
//             cout << "Stack is Underflow\n";
//         }
//         else
//         {
//             cout << "The character that has been popped: " << arr[top--] << endl;
//         }
//     }
//     void peek()
//     {
//         if (top != -1)
//         {
//             cout << "The peek is: " << arr[top] << endl;
//         }
//         else
//         {
//             cout << "Stack is Underflow.\n";
//         }
//     }
// };

// int main()
// {
//     stack arr(2);
//     arr.push('A');
//     arr.push('B');
//     arr.push('C');
//     arr.push('D');

//     arr.peek();
//     arr.poped();
//     arr.poped();
//     arr.poped();

//     cout << endl;
//     return 0;
// }