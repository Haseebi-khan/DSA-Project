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
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
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
    void check()
    {
        cout << "0000000000000000000000000000000000000000000" << endl;
        Node *temp = head;
        cout << "Address check: ";
        cout << temp->next->next << endl;
        cout << "0000000000000000000000000000000000000000000" << endl;
        while (temp != nullptr)
        {
            cout << temp << " ";
            temp = temp->next;
        }
        cout << endl;
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
};

int main()
{

    SinglyLinkedList s;
    s.insertAtFront(34);
    s.insertAtFront(45);
    s.insertAtFront(3);
    s.insertAtFront(98);
    s.insertAtFront(33);
    s.show();
    s.insertAtEnd(11);
    s.insertAtEnd(22);
    s.insertAtEnd(33);
    s.insertAtEnd(44);
    s.insertAtEnd(55);
    s.insertAtEnd(66);
    s.insertAtEnd(77);
    s.insertAtEnd(88);
    s.show();
    s.deleteFromHead();
    s.deleteFromHead();
    s.deleteFromHead();
    s.deleteFromHead();
    s.deleteFromHead();

    s.show();
    cout << "==============================================.\n";

    s.deletePosition(1);
    // s.show();
    cout << "Asdsadasdasd.\n";
    s.show();

    // s.check();

    // s.deleteFromTail();
    // s.deleteFromTail();
    // s.deleteFromTail();

    // s.show();

    cout << endl;
    return 0;
}