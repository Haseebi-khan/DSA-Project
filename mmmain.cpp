#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *link;
};

int main() {
    // Initialize the linked list
    Node *first = nullptr;

    // Creating a sample linked list: 10 -> 20 -> 30 -> 40
    first = new Node{10, nullptr};
    first->link = new Node{20, nullptr};
    first->link->link = new Node{30, nullptr};
    first->link->link->link = new Node{40, nullptr};

    // Variables for traversal and modification
    Node *current = first, *trailCurrent = nullptr, *newNode = nullptr;
    bool found = false;

    // Search for the node with info == 30
    while (current != nullptr && !found) {
        if (current->info == 30) {
            found = true;
        } else {
            trailCurrent = current;
            current = current->link;
        }
    }

    // If found, delete the node
    if (found) {
        if (trailCurrent != nullptr) {
            trailCurrent->link = current->link;
        } else {
            first = current->link; // Deleting the first node
        }
        delete current;
    }

    // Insert a new node with info == 50 after `trailCurrent`
    if (trailCurrent != nullptr) {
        newNode = new Node{50, trailCurrent->link};
        trailCurrent->link = newNode;
    } else {
        // Special case: list was empty or first node was deleted
        newNode = new Node{50, first};
        first = newNode;
    }

    // Print the list
    cout << "Current linked list: ";
    current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;

    // Delete all nodes to free memory
    current = first;
    while (current != nullptr) {
        Node *temp = current;
        current = current->link;
        delete temp;
    }
    first = nullptr; // Avoid dangling pointer

    return 0;
}
