#include <iostream>
using namespace std;
// Stack implementation

void push(int stack[], int &n, int &top)
{
    if (top == n - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        cout << "Enter the Value in stack: ";
        cin >> stack[top];
    }
}

void pop(int stack[], int n, int &top)
{
    if (top == -1)
    {
        cout << "Array is Empty.\n";
    }
    else
    {
        stack[--top];
    }
}

void peek(int stack[], int top)
{
    if (top != -1)
    {
        cout << stack[top] << endl;
    }
    else
    {
        cout << "Stack is empty." << endl;
    }
}

void display(int stack[], int top)
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
}

int main()
{

    int n = 5;
    int stack[n];
    int top = -1;

    push(stack, n, top);
    push(stack, n, top);
    push(stack, n, top);
    push(stack, n, top);
    push(stack, n, top);

    peek(stack, top);

    push(stack, n, top);

    display(stack, top);

    cout << endl;

    display(stack, top);

    cout << endl;

    peek(stack, top);

    cout << endl;
    return 0;
}