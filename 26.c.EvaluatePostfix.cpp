

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

void emptyTheStack()
{
    while (top != nullptr)
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

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

// EvaluatePostfix(Exp) using stack
// 23* 54*+ 9-
// output: 17

int EvaluatePostfix(string const &exp)
{
    int len = exp.length();
    // for (size_t i = 0; i < len; i++)
    // {
    //     cout << exp[i] << " ";
    // }
    // cout << "\n";
    for (int i = 0; i < len; i++)
    {
        // if (exp[i] == "")
        // {
        //     continue;
        // }
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(static_cast<int>(exp[i] -'0'));
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int value2 = peek();
            pop();
            int value1 = peek();
            pop();
            if (exp[i] == '+')
            {
                push(value1 + value2);
            }
            else if (exp[i] == '-')
            {
                push(value1 - value2);
            }
            else if (exp[i] == '/')
            {
                push(value1 / value2);
            }
            else if (exp[i] == '*')
            {
                push(value1 * value2);
            }
        }
    }
    return peek();
}

// 23* 54*+ 9-
// output: 17

int main()
{
    string num = "23*54*+9-";
    int result = EvaluatePostfix(num);
    cout << "Result: " << result << endl;
    cout << endl;
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// // Node class for stack implementation
// class Node
// {
// public:
//     char data;
//     Node *next;
//     Node(char ch) : data(ch), next(nullptr) {}
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
//     }

//     void push(char ch)
//     {
//         Node *newNode = new Node(ch);
//         newNode->next = top;
//         top = newNode;
//     }

//     char pop()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack Underflow.\n";
//             return '\0';
//         }
//         char poppedValue = top->data;
//         Node *temp = top;
//         top = top->next;
//         delete temp;
//         return poppedValue;
//     }

//     char peek()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack is empty.\n";
//             return '\0';
//         }
//         return top->data;
//     }

//     bool isEmpty()
//     {
//         return top == nullptr;
//     }

//     void display()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack is Empty.\n";
//         }
//         else
//         {
//             Node *temp = top;
//             while (temp != nullptr)
//             {
//                 cout << temp->data ;
//                 temp = temp->next;
//             }
//             cout << endl;
//         }
//     }
// };

// int main()
// {

//     //A+B*C**AH
//     Stack a;
//     a.push('A');
//     a.push('+');
//     a.push('B');
//     a.push('C');
//     a.push('*');
//     a.push('*');
//     a.push('A');
//     a.push('H');

//     cout << "Original Stack: ";
//     a.display();

//     Stack list2;
//     Stack list3;

//     while (!a.isEmpty())
//     {
//         char ch = a.pop();
//         if (isalpha(ch))
//         {
//             list2.push(ch);
//         }
//         else
//         {
//             list3.push(ch);
//         }
//     }

//     Stack list4;
//     while (!list3.isEmpty())
//     {
//         list4.push(list3.pop());
//     }

//     while (!list2.isEmpty())
//     {
//         list4.push(list2.pop());
//     }

//     cout << "Postfix Stack: ";
//     list4.display();

//     cout << endl;
//     return 0;
// }

// =========================================================

// #include <iostream>
// #include <cctype> // For isalpha and isdigit
// using namespace std;

// class Node
// {
// public:
//     char data;
//     Node *next;
//     Node(char ch) : data(ch), next(nullptr) {}
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
//         // cout << "Memory is freed.\n";
//     }

//     void push(char ch)
//     {
//         Node *newNode = new Node(ch);
//         newNode->next = top;
//         top = newNode;
//     }

//     char pop()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack Underflow.\n";
//             return '\0';
//         }
//         char poppedValue = top->data;
//         Node *temp = top;
//         top = top->next;
//         delete temp;
//         return poppedValue;
//     }

//     char peek()
//     {
//         if (top == nullptr)
//         {
//             cout << "Stack is empty.\n";
//             return '\0';
//         }
//         return top->data;
//     }

//     bool isEmpty()
//     {
//         return top == nullptr;
//     }
// };

// int precedence(char op)
// {
//     if (op == '+' || op == '-')
//     {
//         return 1;
//     }
//     else if (op == '*' || op == '/')
//     {
//         return 2;
//     }
//     else
//     {
//         return 0;
//     }
// }

// string infixToPostfix(const string &infix)
// {
//     Stack operators;
//     string postfix = "";

//     for (char ch : infix)
//     {
//         if (isalpha(ch))
//         {
//             postfix += ch; // Append operands directly
//         }
//         else if (ch == '(')
//         {
//             operators.push(ch);
//         }
//         else if (ch == ')')
//         {
//             while (!operators.isEmpty() && operators.peek() != '(')
//             {
//                 postfix += operators.pop();
//             }
//             operators.pop(); // Remove '(' from the stack
//         }
//         else
//         {
//             // Operator
//             while (!operators.isEmpty() && precedence(ch) <= precedence(operators.peek()))
//             {
//                 postfix += operators.pop();
//             }
//             operators.push(ch);
//         }
//     }

//     // Pop remaining operators
//     while (!operators.isEmpty())
//     {
//         postfix += operators.pop();
//     }

//     return postfix;
// }

// int main()
// {
//     string infix = "A+B*C**AH";
//     cout << "Infix Expression: " << infix << endl;

//     string postfix = infixToPostfix(infix);
//     cout << "Postfix Expression: " << postfix << endl;

//     return 0;
// }

// // Original Stack: HA**CB+A
// // Postfix Stack: HACBA**+