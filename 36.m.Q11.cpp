#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
};

// Function to insert a node at the end of the list
void insert(Node *&head, int value) {
    Node *newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to delete every alternate node
void deleteAlternate(Node *&head) {
    Node *current = head, *prev = nullptr;
    bool deleteFlag = false;

    while (current != nullptr) {
        if (deleteFlag) {
            Node *temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
        deleteFlag = !deleteFlag;
    }
}

// Function to split the list into two: even-indexed nodes in one list, odd-indexed in another
void splitList(Node *head, Node *&list1, Node *&list2) {
    Node *current = head;
    int index = 0;

    while (current != nullptr) {
        if (index % 2 == 0) {
            insert(list1, current->data);
        } else {
            insert(list2, current->data);
        }
        current = current->next;
        index++;
    }
}

// Function to merge two lists based on conditions
Node *mergeLists(Node *list1, Node *list2) {
    Node *merged = nullptr, **tail = &merged;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data % 2 == 0) {
            insert(*tail, list1->data);
            list1 = list1->next;
        } else {
            insert(*tail, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != nullptr) {
        insert(*tail, list1->data);
        list1 = list1->next;
    }

    while (list2 != nullptr) {
        insert(*tail, list2->data);
        list2 = list2->next;
    }

    return merged;
}

// Function to reverse the list in groups of k
Node *reverseInGroups(Node *head, int k) {
    Node *current = head, *prev = nullptr, *next = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseInGroups(next, k);
    }

    return prev;
}

int main() {
    Node *head = nullptr;

    // Step 1: Insert values into the list
    for (int i = 1; i <= 10; i++) {
        insert(head, i);
    }

    // Trace Point 1: Print the initial list
    cout << "Trace Point 1: ";
    printList(head);

    // Step 2: Delete alternate nodes
    deleteAlternate(head);

    // Trace Point 2: Print the list after alternate node deletion
    cout << "Trace Point 2: ";
    printList(head);

    // Step 3: Split the list into two sublists
    Node *list1 = nullptr, *list2 = nullptr;
    splitList(head, list1, list2);

    // Trace Point 3: Print the two split lists
    cout << "Trace Point 3 - List 1: ";
    printList(list1);
    cout << "Trace Point 3 - List 2: ";
    printList(list2);

    // Step 4: Merge the two lists based on conditions
    Node *merged = mergeLists(list1, list2);

    // Trace Point 4: Print the merged list
    cout << "Trace Point 4: ";
    printList(merged);

    // Step 5: Reverse the list in groups of 3
    merged = reverseInGroups(merged, 3);

    // Trace Point 5: Print the final list after reversing in groups
    cout << "Trace Point 5: ";
    printList(merged);

    return 0;
}
