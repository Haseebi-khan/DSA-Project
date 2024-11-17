#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value = 0) : data(value), next(nullptr) {}
};

Node *Stacktop = nullptr;

void insert(int value)
{
    Node *newNode = new Node(value);
    if (Stacktop == nullptr)
    {
        Stacktop = newNode;
    }
    else
    {
        newNode->next = Stacktop;
        Stacktop = newNode;
    }
}

void insertAtEnd(int value)
{
    Node *newNode = new Node(value);
    if (Stacktop == nullptr)
    {
        Stacktop = newNode;
    }
    else
    {
        Node *temp = Stacktop;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display()
{
    Node *temp = Stacktop;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{

    insert(10);
    insert(20);
    insertAtEnd(30);
    insertAtEnd(40);
    display(); // Expected output: 20 10 30 40
    cout << endl;
    return 0;
}





// #include <iostream>
// #include <malloc.h>
// using namespace std;

// class myArray
// {
// private:
//     int totalSize;
//     int usedSize;
//     int *ptr;

// public:
//     myArray(int t_size, int u_size)
//     {
//         this->totalSize = t_size;
//         this->usedSize = u_size;
//         this->ptr = (int *)malloc(t_size * sizeof(int));
//     }
//     void setValue()
//     {
//         for (int i = 0; i < usedSize; i++)
//         {
//             ptr[i] = i + 1;
//         }
//     }
//     void show()
//     {
//         for (int i = 0; i < usedSize; i++)
//         {
//             cout << (ptr)[i] << " ";
//         }
//     }
// };

// int main()
// {
//     myArray marks(15, 5);
//     marks.setValue();
//     marks.show();

//     cout << endl;
//     return 0;
// }