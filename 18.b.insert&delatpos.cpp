#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};

class linkedList
{
private:
    Node *head, *tail;

public:
    linkedList()
    {
        head = tail = nullptr;
    }
    void add_Rear(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void add_Front(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            head->next = temp;
            head = temp;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void delete_Rear()
    {
        Node *temp = tail;
        if (head == nullptr)
        {
            cout << "Stack is underflow.\n";
        }
        else if (head == tail)
        {
            delete head, tail;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    void delete_front()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "Already Empty.\n";
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    void insertAtPosition(int value, int position)
    {
        Node *temp = new Node();
        temp->data = value;

        if (position <= 0 || head == nullptr) 
        {
            add_Front(value);
        }
        else
        {
            Node *current = head;
            int currentPos = 0;
            while (current != nullptr && currentPos < position - 1)
            {
                current = current->next;
                currentPos++;
            }
            if (current == nullptr) 
            {
                add_Rear(value);
            }
            else
            {
                temp->next = current->next;
                current->next = temp;
            }
        }
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
        }
        else if (position <= 0)
        {
            delete_front(); 
        }
        else
        {
            Node *current = head;
            Node *previous = nullptr;
            int currentPos = 0;
            while (current != nullptr && currentPos < position)
            {
                previous = current;
                current = current->next;
                currentPos++;
            }
            if (current == nullptr) 
            {
                cout << "Position out of range.\n";
            }
            else
            {
                previous->next = current->next;
                if (current == tail) 
                {
                    tail = previous;
                }
                delete current;
            }
        }
    }
};
int main()
{
    linkedList list;
    list.add_Rear(10);
    list.add_Front(20);
    list.add_Front(20);
    list.add_Front(20);
    list.add_Front(20);
    list.display(); 
    list.insertAtPosition(15, 1);
    list.insertAtPosition(15, 1); 
    list.insertAtPosition(15, 1); 
    list.insertAtPosition(15, 1); 
    list.display();              

    list.deleteAtPosition(1); 
    list.display();           

    cout << endl;
    return 0;
}