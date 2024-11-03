// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// class Stack
// {
// private:
//     Node *top;

// public:
//     Stack() : top(nullptr) {}
//     ~Stack()
//     {
//         while (top != nullptr)
//         {
//             Node *temp = top;
//             top = top->next;
//             delete temp;
//         }
//         cout << "memory is freed.\n";
//     }
//     void push(int value)
//     {
//         Node *newNode = new Node();
//         newNode->data = value;
//         newNode->next = top; // top is now null_ptr.it will store in newnode->next.
//         top = newNode;
//         cout << "Pushed Value is: " << value << endl;
//     }
//     void pop()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack Underflow\n";
//         }
//         else
//         {
//             int poped_value;
//             poped_value = top->data;
//             Node *temp = top;
//             top = top->next;
//             delete temp;
//             cout << "Popped value is: " << poped_value << endl;
//         }
//     }
//     void peek() const
//     {
//         cout << "Peek Value is: " << top->data << endl;
//     }
// };

// int main()
// {
//     Stack arr;
//     arr.push(1);
//     arr.push(2);
//     arr.push(3);
//     arr.push(4);
//     arr.push(5);
//     arr.peek();
//     arr.pop();
//     arr.pop();
//     arr.pop();
//     arr.pop();
//     arr.pop();
//     arr.pop();

//     cout << endl;
//     return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack() : top(nullptr) {}
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed value is: " << value << endl;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is Underflow.";
        }
        else
        {
            Node *temp = top;
            int poppedValue = top->data;
            top = top->next;
            delete temp;
            cout << "Popped Value: " << poppedValue << endl;
        }
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is Underflow.";
        }
        else
        {
            cout << "Value at peek is: " << top->data << "\n";
        }
    }
    void adressAtTopVarNext()
    {
        if (top->next == nullptr)
        {
            cout << "The Address is: " << top->next << endl;
        }
        else
        {
            cout << "The Address is not NULL: " << top->next << endl;
        }
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.peek();
    stack.adressAtTopVarNext();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    cout << endl;
    return 0;
}