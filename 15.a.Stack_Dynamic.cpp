#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class stack
{
private:
    Node *top;

public:
    stack() : top(nullptr) {}
    ~stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        cout << "Memory is freed.\n";
    }
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed Value is: " << value << endl;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is Underflow.\n";
        }
        else
        {
            int poppedvalue = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            cout << "Popped Value is: " << poppedvalue << endl;
        }
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is Underflow.\n";
        }
        else
        {
            cout << "Top Value: " << top->data << endl;
        }
    }
    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is Empty.\n";
        }
        else
        {
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    stack arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.push(5);
    arr.peek();
    arr.display();

    arr.pop();
    arr.pop();
    arr.pop();
    arr.pop();
    arr.pop();
    arr.pop();

    arr.display();

    cout << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node()
//     {
//         next = nullptr;
//     }
// };

// class Stack
// {
//     Node *top;

// public:
//     Stack() : top(nullptr) {}
//     void push(int value)
//     {
//         Node *newNode = new Node();
//         newNode->data = value;
//         newNode->next = top;
//         top = newNode;
//         cout << "Pushed value is: " << value << endl;
//     }
//     void pop()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack is Underflow.";
//         }
//         else
//         {
//             Node *temp = top;
//             int poppedValue = top->data;
//             top = top->next;
//             delete temp;
//             cout << "Popped Value: " << poppedValue << endl;
//         }
//     }
//     void peek()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack is Underflow.";
//         }
//         else
//         {
//             cout << "Value at peek is: " << top->data << "\n";
//         }
//     }
//     void adressAtTopVarNext()
//     {
//         if (top->next == nullptr)
//         {
//             cout << "The Address is: " << top->next << endl;
//         }
//         else
//         {
//             cout << "The Address is not NULL: " << top->next << endl;
//         }
//     }
// };

// int main()
// {
//     Stack stack;
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     stack.push(4);
//     stack.push(5);

//     stack.peek();
//     stack.adressAtTopVarNext();

//     stack.pop();
//     stack.pop();
//     stack.pop();
//     stack.pop();
//     stack.pop();

//     cout << endl;
//     return 0;
// }