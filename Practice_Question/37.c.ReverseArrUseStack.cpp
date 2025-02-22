#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value = 0) : data(value), next(nullptr) {}
};

Node *Stacktop = nullptr;

void push(int value)
{
    Node *newNode = new Node(value);
    newNode->next = Stacktop;
    Stacktop = newNode;
}

void pop()
{
    if (Stacktop == nullptr)
    {
        cout << "Empty.\n";
    }
    else
    {
        Node *temp = Stacktop;
        Stacktop = temp->next;
        delete temp;
    }
}

int peek()
{
    if (Stacktop == nullptr)
    {
        cout << "Stack is empty.\n";
        return -1;
    }
    return Stacktop->data;
}

void reverseArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = peek();
        pop();
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    reverseArray(arr, n);

    cout << "\nUpdated Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
