#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    struct Node *next;
    Node(int x) : value(x), next(nullptr) {}
};

// Function to insert a new_node in
// the result list.
Node *sortedInsert(Node *newnode, Node *sorted)
{
    // Special case for the head end
    if (sorted == NULL || sorted->value >= newnode->value)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        Node *curr = sorted;

        // Locate the node before the point
        // of insertion
        while (curr->next != NULL &&
               curr->next->value < newnode->value)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }

    return sorted;
}

Node *insertionSort(Node *head)
{
    // Initialize sorted linked list
    Node *sorted = NULL;
    Node *curr = head;

    // Traverse the given linked list and insert
    // every node to sorted
    while (curr != NULL)
    {

        // Store next for next iteration
        Node *next = curr->next;

        // Insert current in sorted linked list
        sorted = sortedInsert(curr, sorted);

        // Update current
        curr = next;
    }

    return sorted;
}

void printList(Node *curr)
{
    while (curr != NULL)
    {
        cout << " " << curr->value;
        curr = curr->next;
    }
}

int main()
{

    // Create a hard-coded linked list:
    // 5->4->1->3->2
    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    head = insertionSort(head);

    printList(head);

    cout << endl;
    return 0;
}