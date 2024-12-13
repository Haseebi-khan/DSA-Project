#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char Data;
    Node *next;
    Node(char d) : Data(d), next(nullptr) {}
};

Node *top = nullptr;

void push(char ch)
{
    Node *newNode = new Node(ch);

    if (top == nullptr)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void pop()
{
    if (top == nullptr)
    {
        cout << "Stack is UnderFlow.\n";
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}
char peek()
{
    if (top == nullptr)
    {
        cout << "Stack is empty.\n";
        return '\0';
    }
    else
    {
        return top->Data;
    }
}

void show()
{
    if (top == nullptr)
    {
        cout << "Stack is empty.\n";
        return;
    }
    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void CheckForBalanceOfParantheses(string const &s, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == nullptr)
            {
                cout << "Parantheses are not Balance.\n";
                return;
            }
            if (peek() == '(' && s[i] == ')' || peek() == '{' && s[i] == '}' || peek() == '[' && s[i] == ']')
            {
                pop();
            }
            else
            {
                cout << "Parantheses are not Balance.\n";
                return;
            }
        }
    }
    if (top == nullptr)
    {
        cout << "Parantheses are Balance.\n";
    }
    else
    {
        cout << "Parantheses are not Balance.\n";
    }
}

int main()
{
    string s = "[{()}";
    string s2 = "()()";
    string s3 = "()[()]";
    CheckForBalanceOfParantheses(s3, s3.length());

    cout << endl;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// struct Node
// {
//     char data;
//     int count = 0;
//     Node *next;
//     Node()
//     {
//         next = nullptr;
//     }
// };

// Node *top = nullptr;

// void push(char ch)
// {
//     Node *newNode = new Node;
//     newNode->data = ch;
//     newNode->count++;
//     if (top == nullptr)
//     {
//         top = newNode;
//     }
//     else
//     {
//         newNode->next = top;
//         top = newNode;
//     }
//     cout << "Pushed: " << ch << endl;
// }

// void pop()
// {
//     if (top == nullptr)
//     {
//         cout << "UnderFlow\n";
//     }
//     else
//     {
//         char ch = top->data;
//         Node *temp = top;
//         top = top->next;
//         delete temp;
//         cout << "Popped: " << ch << endl;
//     }
// }

// void display()
// {
//     if (top == nullptr)
//     {
//         cout << "Stack is empty.\n";
//     }
//     else
//     {
//         Node *temp = top;
//         cout << "Stack elements: ";
//         while (temp != nullptr)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// }

// // Valid Parentheses in an Expression
// // Last Updated : 16 Sep, 2024
// // Given an expression string s, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

// // Example:

// // Input: s = “[()]{}{[()()]()}”
// // Output: true
// // Explanation: All the brackets are well-formed

// // Input: s = “[(])”
// // Output: false
// // Explanation: 1 and 4 brackets are not balanced because
// // there is a closing ‘]’ before the closing ‘(‘
// bool validationParentheses(const string &str)
// {
//     for (char ch : str)
//     {
//         if (ch == '(' || ch == '{' || ch == '[')
//         {
//             push(ch);
//         }
//         else
//         {
//             if (top == nullptr)
//             {
//                 return false;
//             }
//             if ((top->data == '(' && ch == ')') || (top->data == '{' && ch == '}') || (top->data == '[' && ch == ']'))
//             {
//                 pop();
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
//     bool isValid = (top == nullptr);
//     while (top != nullptr)
//     {
//         pop();
//     }
//     return isValid;
// }

// int main()
// {

//     string a = "(){}[(){()}]";
//     string b = "[(}]";

//     if (validationParentheses(a))
//     {
//         cout << "Vaild string.\n";
//     }
//     else
//     {
//         cout << "Invaild String.\n";
//     }
//     if (validationParentheses(b))
//     {
//         cout << "Vaild string.\n";
//     }
//     else
//     {
//         cout << "Invaild String.\n";
//     }

//     cout << endl;

//     return 0;
// }
