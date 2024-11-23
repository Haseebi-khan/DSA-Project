#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node *next;

public:
    node(int value)
    {
        data = value;
        next = nullptr;
    }
    ~node()
    {
        cout << "Node with data " << data << " erased.\n";
        // Original code: delete next;
        // This line causes recursive deletion of the entire list,
        // which is not appropriate here. It may cause a double deletion
        // when the linkedList destructor tries to delete nodes.
    }
    node &setData(int value)
    {
        data = value;
        return *this;
    }
    node &setNext(node *a)
    {
        // Original code: next = a->next;
        // This line incorrectly sets `next` to `a->next`.
        // To link the current node to `a`, it should be `next = a;`.
        next = a;
        return *this;
    }
    int getData() const
    {
        return data;
    }
    node *getNext() const
    {
        return next;
    }
};

class linkedList
{
private:
    node *head, *tail;

public:
    linkedList()
    {
        head = tail = nullptr;
    }
    ~linkedList()
    {
        node *current = head;
        while (current != nullptr)
        {
            node *nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
        cout << "List destroyed.\n";

    }
    void insertionRear(int value)
    {
        node *temp = new node(value);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->setNext(temp);
            tail = temp;
        }
    }
    void display() const
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
    }
    void addAtFront(int value)
    {
        node *temp = new node(value);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            temp->setNext(head);
            head = temp;
        }
    }
    void peek() const
    {
        if (tail != nullptr)
        {
            cout << tail->getData() << endl;
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }
    void DeleteFromRear()
    {
        if (head == nullptr)
        {
            cout << "Linkedlist is empty.\n";
        }
        else if (head == tail)
        {
            delete head, tail;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            while (temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            delete tail;
            tail = temp;
            tail->setNext(nullptr);
        }
    }
};

int main()
{
    linkedList list;

    cout << "the value added is: 10 " << endl;
    list.insertionRear(10);

    cout << "the value added is: 12 " << endl;
    list.insertionRear(12);

    cout << "the value added is: 9 " << endl;
    list.insertionRear(9);

    cout << "the value added is: 67 " << endl;
    list.insertionRear(67);

    cout << "the value added is: 8 " << endl;
    list.insertionRear(8);

    cout << "the value added is: 100 " << endl;
    list.addAtFront(100);

    cout << "peek: ";
    list.peek();

    cout << "the value added is: 200 " << endl;
    list.addAtFront(200);

    cout << "peek: ";
    list.peek();

    cout << "the value added is: 300 " << endl;
    list.addAtFront(300);

    list.display();

    cout << "\n\n\nEnd of the program.\n";

    return 0;
}
