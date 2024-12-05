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
