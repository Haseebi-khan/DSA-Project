#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value = 0) : data(value), next(nullptr) {}
};

class singlyll
{
private:
    node *head;

public:
    singlyll() : head(nullptr) {}
    void insertAthead(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        node *newNode = new node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "Empty\n";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        node *temp = head;
        node *current = nullptr;

        while (temp->next != nullptr)
        {
            current = temp;
            temp = temp->next;
        }
        current->next = nullptr;
        delete temp;
    }
    void deleteFromEnd_()
    {
        if (head == nullptr)
        {
            cout << "Empty\n";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        node *temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void reverseIteration()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        node *prev = head;
        node *curr = head->next;

        while (curr != nullptr)
        {
            node *NextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = NextNode;
        }
        head->next = nullptr;
        head = prev;
    }

    void show()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteFromHead()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        node *temp = head;
        head = head->next;
        delete temp;
    }
};

int main()
{
    singlyll list;
    // inseert at begging
    list.insertAthead(444);
    list.insertAthead(34);
    list.insertAthead(2);
    list.insertAthead(78);
    // list.show();
    // insert at end
    list.insertAtEnd(4545);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.show();

    // cout << "Working well.\n";
    // cout << endl;

    // cout << "Delete from End: ";
    // list.deleteFromEnd();
    // list.show();

    // cout << "Delete from head: ";
    // list.deleteFromHead();
    // list.show();

    cout << "Reverse Iteration: ";

    list.reverseIteration();
    list.show();

    cout << endl;
    return 0;
}
