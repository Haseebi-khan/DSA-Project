#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int v = 0) : data(v), next(nullptr) {}
};

class SingleCircularLL
{
private:
    node *head, *tail;

public:
    SingleCircularLL() : head(nullptr), tail(nullptr) {}

    void insertAtFront(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtEnd(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    void deleteFromFront()
    {
        if (head == nullptr)
        {
            cout << "Empty.\n";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "Empty.\n";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
        }
    }

    void deletePos(int position)
    {
        if (head == nullptr || position < 0)
        {
            cout << "Postion is not avialble." << endl;
            return;
        }
        if (position == 1)
        {
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            else
            {
                node *temp = head;
                head = head->next;
                delete temp;
                tail->next = head;
            }
            return;
        }
        int count = 1;
        node *current = head;
        node *pre = nullptr;
        do
        {
            pre = current;
            current = current->next;
            count++;

            if (count == position)
            {
                if (current == nullptr)
                {
                    tail = pre;
                    delete current;
                }
                else
                {
                    pre->next = current->next;
                    delete current;
                    break;
                }
            }

        } while (current != nullptr);
    }

    void show()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main()
{
    SingleCircularLL list;

    list.insertAtFront(2);
    list.insertAtFront(1);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "list: ";
    list.show();
    list.deletePos(3);
    cout << "list: ";

    list.show();

    return 0;
}
