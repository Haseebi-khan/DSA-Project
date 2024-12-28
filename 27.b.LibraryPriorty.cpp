#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char ch = ' ') : data(ch), next(nullptr) {}
};

// Library Book Removal Policy:
//     • Problem Statement: A library shelf contains books arranged by their publication dates. To make room for new books, implement the following removal policy:
//         1. For every I books on the shelf, the next J books are removed and stored in a separate section.
//         2. If the remaining books are fewer than I or J, remove only the available books. If no removal is possible, leave the list unchanged.
//     • Example Scenarios:
//         ◦ Case 1:
//             ▪ I = 2, J = 2
//             ▪ Input: A -> B -> C -> D -> E -> F -> G -> H
//             ▪ Output: A -> B -> E -> F -> G -> H
//         ◦ Case 3 (Fewer Books):
//             ▪ I = 3, J = 4
//             ▪ Input: A -> B -> C -> D -> E
//             ▪ Output: A -> B -> C
//         ◦ Case 4 (Very Few Books):
//             ▪ I = 3, J = 4
//             ▪ Input: A -> B
//             ▪ Output: A -> B (unchanged)

class SinglyLinkList
{
private:
    Node *head;

public:
    SinglyLinkList() : head(nullptr) {}
    ~SinglyLinkList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(char ch)
    {
        Node *newNode = new Node(ch);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

        //         ◦ Case 2:
        //             ▪ I = 3, J = 2
        //             ▪ Input: A -> B -> C -> D -> E -> F -> G -> H -> I -> J
        //             ▪ Output: A -> B -> C -> G -> H -> I -> J
    void removal_Policy(int I, int J)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *cur = head;
        Node *prev = nullptr;

        while (cur != nullptr)
        {
            for (int i = 0; i < I && cur != nullptr; ++i)
            {
                prev = cur;
                cur = cur->next;
            }

            if (cur == nullptr)
            {
                break;
            }

            for (int j = 0; j < J && cur != nullptr; ++j)
            {
                Node *temp = cur;
                cur = cur->next;
                delete temp;
            }

            prev->next = cur;
        }
    }

    void show()
    {
        if (!head)
        {
            cout << "Empty.\n";
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkList l;
    l.insertAtHead('J');
    l.insertAtHead('I');
    l.insertAtHead('H');
    l.insertAtHead('G');
    l.insertAtHead('F');
    l.insertAtHead('E');
    l.insertAtHead('D');
    l.insertAtHead('C');
    l.insertAtHead('B');
    l.insertAtHead('A');

    cout << "List: ";
    l.show();

    l.removal_Policy(2, 2);

    cout << "After Updating: ";
    l.show();

    return 0;
}
