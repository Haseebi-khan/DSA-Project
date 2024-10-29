#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = (int *)malloc(size * sizeof(int));
        capacity = size;
        top = -1;
    }
    ~Stack()
    {
        free(arr);
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is Full.\n";
            return;
        }
        else
        {
            arr[++top] = x;
            cout << "Insertion is complete.\n";
        }
    }

    int peek()
    {
        if (isEmpty())
        {
        }
        cout << "Stack is empty." << endl;
        return -1;
        return arr[top];
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Array is Empty.";
            return;
        }
        arr[top--];
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() const
    {
        return top + 1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == capacity - 1;
    }
};

int main()
{

    Stack stack(6);

    for (int i = 0; i < stack.isFull(); i++)
    {
        int randomNum = rand() % 100;
        stack.push(randomNum);
    }

    cout << "Current stack using display Func : ";
    stack.display();

    cout << "Popping elements to show LIFO behavior:" << endl;
    while (!stack.isEmpty())
    {
        cout << "Popped: " << stack.pop() << endl;
    }
    cout << endl;
    return 0;
}
