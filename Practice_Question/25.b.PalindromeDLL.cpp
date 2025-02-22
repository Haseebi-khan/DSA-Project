
#include <iostream>
using namespace std;

// Check for Palindrome
// Determine if a singly linked list is a palindrome (e.g., 1 -> 2 -> 2 -> 1 is a palindrome).

class node
{
public:
    int data;
    node *next;
    node *pre;
    node(int value = 0) : data(value), next(nullptr), pre(nullptr) {}
};

class doublyLinkedList
{
private:
    node *head, *tail;

public:
    doublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Check for Palindrome
    // Determine if a singly linked list is a palindrome (e.g., 1 -> 2 -> 2 -> 1 is a palindrome).
    void palindromeCheck()
    {
        if (head == nullptr)
        {
            cout << "empty.\n";
            return;
        }
        else if (head == tail)
        {
            cout << "Palidrome.\n";
        }
        else
        {
            bool Palidrome = true;
            node *left = head, *right = tail;
            while (left != right && left->pre != right)
            {
                if (left->data != right->data)
                {
                    Palidrome = false;
                }
                left = left->next;
                right = right->pre;
            }
            if (Palidrome)
            {
                cout << "List is Palidrome.\n";
            }
            else
            {
                cout << "List is not Palidrome.\n";
            }
        }
    }

    //  insert at the beginning,
    void insertAtBeginning(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    void Display()
    {
        if (head == nullptr)
        {
            cout << "Linked list Underflow.\n";
        }
        else
        {
            node *temp = head;
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
    doublyLinkedList dLinkedList;

    dLinkedList.insertAtBeginning(1);
    dLinkedList.insertAtBeginning(2);
    dLinkedList.insertAtBeginning(2);
    dLinkedList.insertAtBeginning(2);
    dLinkedList.insertAtBeginning(2);
    dLinkedList.insertAtBeginning(2);
    dLinkedList.insertAtBeginning(1);
    cout << "List: ";
    dLinkedList.Display();
    cout << endl;

    dLinkedList.palindromeCheck();
    cout << endl;
    cout << endl;

    cout << "Ater Updating List\n";
    cout << "Second Time\n";
    dLinkedList.insertAtBeginning(234);
    dLinkedList.palindromeCheck();

    cout << endl;
    return 0;
}