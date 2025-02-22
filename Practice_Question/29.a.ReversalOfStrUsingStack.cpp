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

string reversalOfString(string const &s, int len)
{
    string str = "";
    for (int i = 0; i < len; i++)
    {
        push(s[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str += peek();
        pop();
    }

    return str;
}

int main()
{

    string str;
    cout << "Enter the String: ";
    cin >> str;

    string newStr = reversalOfString(str, str.length());
    cout << newStr;
    cout << endl;
    return 0;
}