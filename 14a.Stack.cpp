#include <iostream>
using namespace std;

const int n = 5;
int stack[n];
int top = -1;

void push(int value)
{
    if (top == n - 1)
    {
        cout << "Stack is Overflow.\n";
    }
    else
    {
        stack[++top] = value;
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
        cout << "popped value: " << stack[top--] << endl;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is Empty.\n";
    }
    else
    {
        cout << stack[top] << endl;
    }
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
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    show();

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    peek();

    show();

    pop();
    pop();
    show();
    pop();
    pop();
    pop();
    pop();

    cout << endl;
    return 0;
}
// ////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;
// // Stack implementation using INT data type.

// void push(int stack[], int &n, int &top)
// {
//     if (top == n - 1)
//     {
//         cout << "Stack is full" << endl;
//     }
//     else
//     {
//         top++;
//         cout << "Enter the Value in stack: ";
//         cin >> stack[top];
//     }
// }

// void pop(int stack[], int n, int &top)
// {
//     if (top == -1)
//     {
//         cout << "Array is Empty.\n";
//     }
//     else
//     {
//         stack[--top];
//     }
// }

// void peek(int stack[], int top)
// {
//     if (top != -1)
//     {
//         cout << stack[top] << endl;
//     }
//     else
//     {
//         cout << "Stack is empty." << endl;
//     }
// }

// void display(int stack[], int top)
// {
//     for (int i = top; i >= 0; i--)
//     {
//         cout << stack[i] << " ";
//     }
// }

// int main()
// {

//     int n = 5;
//     int stack[n];
//     int top = -1;

//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);

//     peek(stack, top);

//     push(stack, n, top);

//     display(stack, top);

//     cout << endl;

//     display(stack, top);

//     cout << endl;

//     peek(stack, top);

//     cout << endl;
//     return 0;
// }

// ////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;
// // Stack implementation using STRING Data type.

// void push(string stack[], int &n, int &top)
// {
//     if (top == n - 1)
//     {
//         cout << "Stack is full" << endl;
//     }
//     else
//     {
//         top++;
//         cout << "Enter the String in stack: ";
//         cin >> stack[top];
//     }
// }

// void pop(string stack[], int n, int &top)
// {
//     if (top == -1)
//     {
//         cout << "Stack is Empty.\n";
//     }
//     else
//     {
//         cout << "Stack had free the string: " << stack[top] << "\n";
//         stack[--top];
//     }
// }

// void peek(string stack[], int top)
// {
//     if (top != -1)
//     {
//         cout << stack[top] << endl;
//     }
//     else
//     {
//         cout << "Stack is empty." << endl;
//     }
// }

// void display(string stack[], int top)
// {
//     for (int i = top; i >= 0; i--)
//     {
//         cout << stack[i] << "\n";
//     }
// }

// int main()
// {

//     int n = 2;
//     string stack[n];
//     int top = -1;

//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);

//     peek(stack, top);

//     push(stack, n, top);

//     cout << endl;

//     cout << endl;

//     pop(stack, n, top);
//     pop(stack, n, top);

//     pop(stack, n, top);
//     pop(stack, n, top);

//     cout << endl;
//     return 0;
// }

// //////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// // Stack implementation using CHAR Data type.

// void push(char stack[], int &n, int &top)
// {
//     if (top == n - 1)
//     {
//         cout << "Stack is full" << endl;
//     }
//     else
//     {
//         top++;
//         cout << "Enter the Character in stack: ";
//         cin >> stack[top];
//     }
// }

// void pop(char stack[], int n, int &top)
// {
//     if (top == -1)
//     {
//         cout << "Stack is Empty.\n";
//     }
//     else
//     {
//         cout << "Stack had freed the character: " << stack[top--] << "\n";
//     }
// }

// void peek(char stack[], int top)
// {
//     if (top != -1)
//     {
//         cout << stack[top] << endl;
//     }
//     else
//     {
//         cout << "Stack is empty." << endl;
//     }
// }

// void display(char stack[], int top)
// {
//     for (int i = top; i >= 0; i--)
//     {
//         cout << stack[i] << "\n";
//     }
// }

// int main()
// {
//     int n = 5;
//     char stack[n];
//     int top = -1;

//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);
//     push(stack, n, top);

//     peek(stack, top);

//     push(stack, n, top);

//     cout << endl;

//     pop(stack, n, top);
//     pop(stack, n, top);
//     pop(stack, n, top);
//     pop(stack, n, top);
//     pop(stack, n, top);
//        pop(stack, n, top);
//           pop(stack, n, top);
//              pop(stack, n, top);
//     cout << endl;
//     return 0;
// }