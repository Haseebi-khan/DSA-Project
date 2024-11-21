// Given a string, reverse it using stack.

// Example:

// Input: str = “GeeksQuiz”
// Output: ziuQskeeG

// Input: str = “abc”
// Output: cba

#include <iostream>
using namespace std;

class stack
{
private:
    char *arr;
    int cap;
    int top = -1;

public:
    stack(int size = 10)
    {
        arr = new char[size];
        cap = size;
    }
    ~stack()
    {
        delete[] arr;
    }
    void push(char ch)
    {
        if (top == cap - 1)
        {
            cout << "Stack is Overflow.\n";
        }
        else
        {
            top++;
            arr[top] = ch;
        }
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow.\n";
            return '\0';
        }
        else
        {

            return arr[top--];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void show()
    {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack a, b;
    a.push('G');
    a.push('e');
    a.push('e');
    a.push('k');
    a.push('s');
    a.push('Q');
    a.push('u');
    a.push('i');
    a.push('z');
    a.show();
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.push(a.pop());
    b.show();

    cout << endl;
    return 0;
}
