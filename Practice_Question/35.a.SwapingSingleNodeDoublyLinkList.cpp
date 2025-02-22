#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
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

    void deleteOnFront()
    {
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
            return;
        }

        Node *temp = head;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void deleteOnRear()
    {
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
            return;
        }

        Node *temp = tail;
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void showData()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *indexAddress(int pos)
    {
        Node *current = head;
        int count = 1;
        while (current != nullptr && count < pos)
        {
            current = current->next;
            count++;
        }

        // 1 2 3 4 5 6 7 8 0
        // 1 2 3 4 5 6 7 8 9

        return current;
    }
    int searchZero()
    {

        bool found = false;
        Node *current = head;
        int iteration = 1;
        while (current != nullptr)
        {
            if (current->data == 0)
            {
                // cout << "Value is: " << current->data;
                // cout << " Index is: " << iteration << endl;
                found = true;
                break;
            }
            current = current->next;
            iteration++;
        }

        if (found)
        {
            return iteration;
        }
        return -1;
    }
    void opreate()
    {
        int zeroIndex = searchZero();
        if (zeroIndex == -1)
        {
            cout << "Zero not found in the list.\n";
            return;
        }

        char input;
        Node *swapNode = nullptr;

        cout << "Move Input: ";
        cin >> input;
        if (input == 'z')
        {
            return;
        }

        // Validate input
        while (input != 'w' && input != 'W' &&
               input != 's' && input != 'S' &&
               input != 'a' && input != 'A' &&
               input != 'd' && input != 'D')
        {
            cout << "Please enter a valid input.\n";
            cout << "Enter valid move input: ";
            cin >> input;
        }

        Node *zeroAddress = indexAddress(zeroIndex);

        // Handle moves based on input
        if (input == 'W' || input == 'w') // Move up
        {
            if (zeroIndex > 3) // Valid only if zero is not in the first row
            {
                swapNode = indexAddress(zeroIndex - 3);
                Swap(zeroAddress, swapNode);
            }
            else
            {
                cout << "Move not allowed. Zero is in the top row.\n";
            }
        }
        else if (input == 'S' || input == 's') // Move down
        {
            if (zeroIndex <= 6) // Valid only if zero is not in the last row
            {
                swapNode = indexAddress(zeroIndex + 3);
                Swap(zeroAddress, swapNode);
            }
            else
            {
                cout << "Move not allowed. Zero is in the bottom row.\n";
            }
        }
        else if (input == 'A' || input == 'a') // Move left
        {
            if ((zeroIndex - 1) % 3 != 0) // Valid only if zero is not in the first column
            {
                swapNode = indexAddress(zeroIndex - 1);
                Swap(zeroAddress, swapNode);
            }
            else
            {
                cout << "Move not allowed. Zero is in the first column.\n";
            }
        }
        else if (input == 'D' || input == 'd') // Move right
        {
            if (zeroIndex % 3 != 0) // Valid only if zero is not in the last column
            {
                swapNode = indexAddress(zeroIndex + 1);
                Swap(zeroAddress, swapNode);
            }
            else
            {
                cout << "Move not allowed. Zero is in the last column.\n";
            }
        }

        showData();
        opreate();
    }
    void Swap(Node *Node1, Node *Node2)
    {
        if (Node1 && Node2)
        {
            int temp = Node1->data;
            Node1->data = Node2->data;
            Node2->data = temp;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.addOnRear(1);
    list.addOnRear(2);
    list.addOnRear(3);
    list.addOnRear(4);
    list.addOnRear(5);
    list.addOnRear(6);
    list.addOnRear(7);
    list.addOnRear(8);
    list.addOnRear(0);

    list.opreate();

    list.showData();

    return 0;
}
