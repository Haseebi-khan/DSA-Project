/* Question 1:
We wish to add a method called searchAndPromote to our singly linked list class.
Each node in the list contains:

An integer key
A character value
A next pointer
Function Details
The function searchAndPromote searches the list for a given key.
If found, it promotes all nodes containing that key to the start of the list.
The nodes must appear at the start of the list in the same order they were found during the search.
The function must not delete or create new nodes; it should simply reconnect the existing nodes.
Example
Before calling: searchAndPromote(3)
After calling: Nodes (3, Q) and (3, B) appear at the start of the list, maintaining their original order: (3, Q) -> (3, B) -> ...

Node and List Definitions:

cpp
Copy code
class LinkedList {
    struct Node {
        int key; Agent 2's codes are incorrect (violates prefix-free property).


        char value;
        Node* next;
    };
    Node* head;

public:
    ...
    bool searchAndPromote(int key);
};
Task
Write the C++ definition of the function:

cpp
Copy code
bool searchAndPromote(int key);
Time Complexity
Analyze the time complexity of the function given there are n nodes in the list.
Answer: O(n)*/
#include <iostream>
using namespace std;
class LinkedList
{
private:
    struct Node
    {
        int key;
        char value;
        Node *next;
        Node(int k = 0, char c = '\0') : key(k), value(c) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addOnRear(int key, char value)
    {
        Node *newNode = new Node(key, value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool searchAndPromote(int key = 3)
    {
        bool found = false;
        Node *prev = nullptr;
        Node *cur = head;

        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                found = true;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (!found)
        {
            return found;
        }

        Node *newHead = cur;
        prev->next = nullptr;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        if (cur->next == nullptr)
        {
            cur->next = head;
        }
        head = newHead;
        return found;
    }

    void show()
    {
        Node *temp = head;
        cout << "list: ";
        while (temp)
        {
            cout << temp->key << temp->value << "-->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.addOnRear(1, 'A');
    list.addOnRear(4, 'A');
    list.addOnRear(3, 'b');
    list.addOnRear(2, 'b');
    list.addOnRear(5, 'C');
    list.addOnRear(2, 'C');
    list.addOnRear(1, 'A');
    list.show();
    list.searchAndPromote();
    list.show();

    cout << endl;
    return 0;
}


// #include <iostream>
// using namespace std;

// class LinkedList
// {
// private:
//     struct Node
//     {
//         int key;
//         char value;
//         Node *next;
//         Node(int k = 0, char c = '\0') : key(k), value(c), next(nullptr) {}
//     };
//     Node *head;

// public:
//     LinkedList() : head(nullptr) {}

//     void addOnRear(int key, char value)
//     {
//         Node *newNode = new Node(key, value);
//         if (!head)
//         {
//             head = newNode;
//             return;
//         }
//         Node *temp = head;
//         while (temp->next)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }

//     bool searchAndPromote(int key)
//     {
//         if (!head)
//             return false;

//         Node *dummy = new Node(); // Dummy node to simplify reconnections
//         dummy->next = head;

//         Node *prev = dummy;
//         Node *cur = head;

//         Node *promotedHead = nullptr; // New head for promoted nodes
//         Node *promotedTail = nullptr; // Tail for promoted nodes

//         bool found = false;

//         while (cur)
//         {
//             if (cur->key == key)
//             {
//                 found = true;

//                 // Disconnect the node
//                 prev->next = cur->next;

//                 // Add the node to the promoted list
//                 if (!promotedHead)
//                 {
//                     promotedHead = cur;
//                     promotedTail = cur;
//                 }
//                 else
//                 {
//                     promotedTail->next = cur;
//                     promotedTail = cur;
//                 }

//                 cur = prev->next; // Move to the next node
//                 promotedTail->next = nullptr; // Ensure end of promoted list
//             }
//             else
//             {
//                 prev = cur;
//                 cur = cur->next;
//             }
//         }

//         // Connect the promoted list to the rest of the list
//         if (promotedHead)
//         {
//             promotedTail->next = dummy->next;
//             head = promotedHead;
//         }

//         delete dummy;
//         return found;
//     }

//     void show()
//     {
//         Node *temp = head;
//         cout << "list: ";
//         while (temp)
//         {
//             cout << temp->key << temp->value << "-->";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main()
// {
//     LinkedList list;
//     list.addOnRear(1, 'A');
//     list.addOnRear(4, 'A');
//     list.addOnRear(3, 'b');
//     list.addOnRear(2, 'b');
//     list.addOnRear(5, 'C');
//     list.addOnRear(3, 'B');
//     list.addOnRear(1, 'A');

//     cout << "Original list:" << endl;
//     list.show();

//     cout << "After searchAndPromote(3):" << endl;
//     list.searchAndPromote(3);
//     list.show();

//     return 0;
// }
