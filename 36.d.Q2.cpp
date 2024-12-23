// Q5:
// Department of Computer SciencePage 2

// A biotonic doubly linked list is a doubly linked list which is first increasing and then decreasing. A
// strictly increasing or a strictly decreasing list is also a biotonic doubly linked list.
// For example
// list is an example of biotonic doubly linked list.

// 2<-> 5 <-> 7 <-> 12 <-> 10 <-> 6 <-> 4 <-> 1

// Write down a code in C++ to sort the biotonic list. The algorithm must be as efficient as possible.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev; // Pointer to the previous node

    Node(int value = 0) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head, *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addOnFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addOnRear(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void show()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // swap(Node * node1, Node * node2)

    void sorting()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *temp = head;
        Node *temp2 = head;
        while (temp->next->next != nullptr)
        {
            while (temp2 != nullptr)
            {
                if (temp->data > temp2->data)
                {
                    int value = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = value;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
};

// 2<-> 5 <-> 7 <-> 12 <-> 10 <-> 6 <-> 4 <-> 1

int main()
{

    DoublyLinkedList a;
    a.addOnRear(2);
    a.addOnRear(5);
    a.addOnRear(7);
    a.addOnRear(12);
    a.addOnRear(10);
    a.addOnRear(6);
    a.addOnRear(4);
    a.addOnRear(1);
    a.show();
    a.sorting();
    a.show();

    cout << endl;
    return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////


// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int value) : data(value), next(nullptr) {}
// };

// class LinkedList {
// private:
//     Node* head;

// public:
//     LinkedList() : head(nullptr) {}

//     void addOnRear(int value) {
//         Node* newNode = new Node(value);
//         if (!head) {
//             head = newNode;
//             return;
//         }
//         Node* temp = head;
//         while (temp->next) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }

//     void show() {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }

//     Node* merge(Node* left, Node* right) {
//         if (!left) return right;
//         if (!right) return left;

//         if (left->data <= right->data) {
//             left->next = merge(left->next, right);
//             return left;
//         } else {
//             right->next = merge(left, right->next);
//             return right;
//         }
//     }

//     Node* mergeSort(Node* head) {
//         if (!head || !head->next) return head;

//         // Split the list into two halves
//         Node* slow = head;
//         Node* fast = head->next;

//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         Node* mid = slow->next;
//         slow->next = nullptr;

//         // Recursively sort each half
//         Node* left = mergeSort(head);
//         Node* right = mergeSort(mid);

//         // Merge the sorted halves
//         return merge(left, right);
//     }

//     void sort() {
//         head = mergeSort(head);
//     }
// };

// int main() {
//     LinkedList list;
//     list.addOnRear(4);
//     list.addOnRear(2);
//     list.addOnRear(8);
//     list.addOnRear(5);
//     list.addOnRear(1);

//     cout << "Original List: ";
//     list.show();

//     list.sort();

//     cout << "Sorted List: ";
//     list.show();

//     return 0;
// }





// // Q5:
// // Department of Computer SciencePage 2

// // A biotonic doubly linked list is a doubly linked list which is first increasing and then decreasing. A
// // strictly increasing or a strictly decreasing list is also a biotonic doubly linked list. For example, the given
// // list is an example of biotonic doubly linked list.

// // 2<-> 5 <-> 7 <-> 12 <-> 10 <-> 6 <-> 4 <-> 1

// // Write down a code in C++ to sort the biotonic list. The algorithm must be as efficient as possible.

// // Q3: Merge two sorted lists
// // Linked List 1 : 23-> 45-> 65
// // Linked List 2 : 12->67->78
// // Department of Computer SciencePage 1