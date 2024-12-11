#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value = 0) : data(value), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void show()
    {
        if (head == nullptr)
        {
            cout << "List empty.\n";
        }
        else
        {
            cout << "List: ";
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void deleteFromHead()
    {
        if (head == nullptr)
        {
            cout << "Empty.\n";
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromTail()
    {
        if (head == nullptr)
        {
            cout << "empty.\n";
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deletePosition(int index)
    {
        if (head == nullptr || index < 1)
        {
            cout << "Out of range.\n";
        }
        else if (index == 1)
        {

            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else
        {
            Node *curr = head;
            Node *pre = nullptr;
            int count = 1;
            while (curr != nullptr && count < index)
            {
                pre = curr;
                curr = curr->next;
                count++;
            }
            if (curr == nullptr)
            {
                cout << "Out of Range.\n";
                return;
            }

            pre->next = curr->next;
            delete curr;
        }
    }


    void SwappingPority_(int Mcount, int NCount)
    {
        Node *newhead = head;
        Node *M = head;
        int count = 0;
        while (M != nullptr && count < Mcount - 1)
        {
            M = M->next;
            count++;
        }
        Node *N = nullptr;
        bool firstHead = true;
        while (M != nullptr)
        {
            for (int i = NCount; i >= 0; i--)
            {
                N = M->next;
                Node *temp = N->next;
                if (firstHead)
                {
                    N->next = newhead;
                    M->next = temp;
                    head = newhead;
                    newhead = newhead->next;
                    firstHead = false;
                }
                N->next = newhead;
                M->next = temp;
                newhead = newhead->next;
            }
        }
    }

    // void SwappingPority(int Mcount, int NCount)
    // {
    //     if (head == nullptr || Mcount <= 0 || NCount <= 0)
    //         return; // Edge case: empty list or invalid inputs

    //     Node *prev = nullptr; // Keeps track of the node before the current segment
    //     Node *current = head; // Points to the current node being processed

    //     while (current != nullptr)
    //     {
    //         // Step 1: Identify the first M elements
    //         Node *M_start = current;
    //         Node *M_end = M_start;
    //         for (int i = 1; i < Mcount && M_end != nullptr; i++)
    //         {
    //             M_end = M_end->next;
    //         }
    //         if (M_end == nullptr) // If there are fewer than M elements, we're done
    //         {
    //             break;
    //         }

    //         // Step 2: Identify the next N elements
    //         Node *N_start = M_end->next;
    //         Node *N_end = N_start;
    //         for (int i = 1; i < NCount && N_end != nullptr; i++)
    //         {
    //             N_end = N_end->next;
    //         }

    //         if (N_start == nullptr) // If there are no N elements after M, we're done
    //         {
    //             break;
    //         }

    //         // Step 3: Save the pointer to the next segment
    //         Node *nextSegment = N_end != nullptr ? N_end->next : nullptr;

    //         // Step 4: Swap the M and N segments
    //         if (prev != nullptr)
    //         {
    //             prev->next = N_start; // Link the previous part of the list to the N group
    //         }
    //         else
    //         {
    //             head = N_start; // Update the head of the list if swapping the first group
    //         }
    //         N_end->next = M_start;     // Link the end of N group to the start of M group
    //         M_end->next = nextSegment; // Link the end of M group to the next segment

    //         // Step 5: Update prev and current for the next iteration
    //         prev = M_end;
    //         current = nextSegment;
    //     }
    // }
};

int main()
{

    SinglyLinkedList s;

    s.insertAtEnd(1);
    s.insertAtEnd(2);
    s.insertAtEnd(3);
    s.insertAtEnd(4);
    s.insertAtEnd(5);
    s.insertAtEnd(6);
    s.insertAtEnd(7);
    s.insertAtEnd(8);
    s.insertAtEnd(9);
    s.insertAtEnd(10);
    s.show();
    // s.SwappingPority(3, 2);
    s.show();

    cout << endl;
    return 0;
}