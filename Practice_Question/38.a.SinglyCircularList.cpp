#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

Node *createNodesList(int n)
{
    if (n <= 0)
    {
        cout << "Number must be greater than zero." << endl;
        return nullptr;
    }

    for (int i = 1; i <= n; i++)
    {
        Node *newNode = new Node();
        newNode->data = i;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    return head;
}

void display()
{
    if (head == nullptr)
    {
        cout << "empty." << endl;
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    head = createNodesList(n);

    cout << "Circular Linked List: ";
    display();

    return 0;
}
