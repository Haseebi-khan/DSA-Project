#include <iostream>
using namespace std;

class Stack
{
private:
    int Capcity, top = -1, *arr;

public:
    Stack(int cap = 5) : Capcity(cap)
    {

        arr = new int[cap];
    }

    void push(int value)
    {
        if (top == Capcity - 1)
        {
            cout << "full.\n";
            return;
        }
        arr[++top] = value;
        cout << "Value: " << value << " is Pushed.\n";
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "empty.\n";
            return;
        }
        cout << "Value: " << arr[top--] << " is popped.\n";
    }
    void show()
    {
        if (top == -1)
        {
            cout << "empty.\n";
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
    Stack s(5);
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
    cout << endl;
    cout << endl;

    s.show();

    cout << endl;
    return 0;
}