// 7. Reverse the Circular Linked List:
//     ◦ Write a program to reverse the entire circular linked list while maintaining its circular structure.
//     ◦ Example:
//         ▪ Input: 1 -> 2 -> 3 -> 4 -> (back to 1)
//         ▪ Output: 4 -> 3 -> 2 -> 1 -> (back to 4)

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data = 0) : data(data), next(nullptr) {}
};

class SingleCircularLL
{
private:
    node *head, *tail;

public:
    SingleCircularLL() : head(nullptr), tail(nullptr) {}

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

    void reverse()
    {
        if (head == nullptr || head == tail)
        {
            cout << "Empty.\n";
            return;
        }

        node *prev = nullptr;
        node *current = head;
        node *nextNode = nullptr;
        tail = head;

        do
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        head = prev;
        tail->next = head;
    }
};

int main()
{
    SingleCircularLL list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "List: ";
    list.show();

    list.reverse();

    cout << "Reversed List: ";
    list.show();

    return 0;
}

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(char x = 0) : data(x), next(nullptr) {}
// };

// class LL
// {
// private:
//     Node *head;

// public:
//     LL() : head(nullptr) {}

//     void insertAthead(int value)
//     {
//         Node *newNode = new Node(value);
//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }
//         newNode->next = head;
//         head = newNode;
//     }

//     void addAtEnd(int value)
//     {
//         Node *newNode = new Node(value);
//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }
//         Node *temp = head;
//         while (temp->next != nullptr)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }

//     void DeleteFromHead()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//     }

//     void deleteFromRear()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         else if (head->next == nullptr)
//         {
//             delete head;
//             head = nullptr;
//             return;
//         }

//         Node *temp = head;
//         while (temp->next->next != nullptr)
//         {
//             temp = temp->next;
//         }
//         delete temp->next;
//         temp->next = nullptr;
//     }
//     void ReverseLL()
//     {
//         if (head == nullptr && head->next == nullptr)
//         {
//             cout << "Not Possible.\n";
//             return;
//         }

//         Node *prev = head;
//         Node *cur = head->next;

//         while (cur != nullptr)
//         {
//             Node *next = cur->next;
//             cur->next = prev;

//             prev = cur;
//             cur = next;
//         }
//         head->next = nullptr;
//         head = prev;
//     }

//     void insertAtPositon(int value, int pos)
//     {
//         Node *newNode = new Node(value);
//         if (pos <= 0 || head == nullptr)
//         {
//             newNode->next = head;
//             head = newNode;
//         }
//         else
//         {
//             Node *prev = nullptr;
//             Node *cur = head;
//             for (int i = 0; i < pos && cur != nullptr; i++)
//             {
//                 prev = cur;
//                 cur = cur->next;
//             }

//             if (prev != nullptr)
//             {
//                 prev->next = newNode;
//             }

//             newNode->next = cur;
//         }
//     }
//     void deleteAtpos(int pos)
//     {
//         if (head == nullptr || pos < 0)
//         {
//             cout << "Empty.\n";
//         }
//         else if (pos == 0)
//         {
//             DeleteFromHead();
//             return;
//         }
//         else
//         {
//             Node *prev = nullptr;
//             Node *cur = head;
//             for (int i = 0; i < pos && cur != nullptr; i++)
//             {
//                 prev = cur;
//                 cur = cur->next;
//             }

//             if (cur == nullptr)
//             {
//                 cout << "Out of range.\n";
//             }
//             else
//             {
//                 prev->next = cur->next;
//                 delete cur;
//             }
//         }
//     }

//     void palindromeCheck()
//     {
//         if (head == nullptr || head->next == nullptr) // Case 1: Empty or single-node list
//         {
//             cout << "The list is a palindrome.\n";
//             return;
//         }

//         Node *slow = head;
//         Node *fast = head;

//         while (fast != nullptr && fast->next != nullptr)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         Node *prev = nullptr;
//         Node *cur = slow;
//         while (cur != nullptr)
//         {
//             Node *next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }

//         Node *firstHalf = head;
//         Node *secondHalf = prev;
//         bool isPalindrome = true;

//         while (secondHalf != nullptr)
//         {
//             if (firstHalf->data != secondHalf->data)
//             {
//                 isPalindrome = false;
//                 break;
//             }
//             firstHalf = firstHalf->next;
//             secondHalf = secondHalf->next;
//         }

//         cur = prev;
//         prev = nullptr;
//         while (cur != nullptr)
//         {
//             Node *next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }

//         if (isPalindrome)
//         {
//             cout << "The list is a palindrome.\n";
//         }
//         else
//         {
//             cout << "The list is not a palindrome.\n";
//         }
//     }

//     void show()
//     {
//         if (head == nullptr)
//         {
//             cout << "empty.\n";
//             return;
//         }
//         Node *temp = head;
//         cout << "List: ";
//         while (temp != nullptr)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "\n";
//     }
// };

// class NodeD
// {
// public:
//     int data;
//     NodeD *pre;
//     NodeD *next;
//     NodeD(int d = 0) : data(d), pre(nullptr), next(nullptr) {}
// };

// class DLL
// {
// private:
//     NodeD *head, *tail;

// public:
//     DLL() : head(nullptr), tail(nullptr) {}
//     void InsertAtFront(int value)
//     {
//         NodeD *newNode = new NodeD(value);
//         if (head == nullptr)
//         {
//             head = tail = newNode;
//             return;
//         }
//         newNode->next = head;
//         head->pre = newNode;
//         head = newNode;
//     }
//     void InsertAtEnd(int value)
//     {
//         NodeD *newNode = new NodeD(value);
//         if (head == nullptr)
//         {
//             head = tail = newNode;
//             return;
//         }
//         tail->next = newNode;
//         newNode->pre = tail;
//         tail = newNode;
//     }
//     void deleteFront()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         else if (head == tail)
//         {
//             delete head;
//             head = tail = nullptr;
//             return;
//         }

//         NodeD *temp = head;
//         head = head->next;
//         delete temp;
//     }

//     void deleteEnd()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         if (head == tail)
//         {
//             delete head;
//             head = tail = nullptr;
//             return;
//         }
//         NodeD *temp = tail;
//         tail = tail->pre;
//         tail->next = nullptr;
//         delete temp;
//     }

//     void insertAtPos(int value, int pos)
//     {
//         if (head == nullptr || pos <= 0)
//         {
//             InsertAtFront(value);
//             return;
//         }
//         NodeD *prev = nullptr;
//         NodeD *cur = head;
//         for (int i = 0; i < pos && cur != nullptr; i++)
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//         if (cur == nullptr)
//         {
//             InsertAtEnd(value);
//         }
//         else
//         {
//             NodeD *newNode = new NodeD(value);
//             prev->next = newNode;
//             newNode->pre = prev;
//             newNode->next = cur;
//             cur->pre = newNode;
//         }
//     }

//     void deleteFromPos(int pos)
//     {
//         if (head == nullptr || pos < 0)
//         {
//             cout << "Empty.\n";
//             return;
//         }

//         NodeD *prev = nullptr;
//         NodeD *cur = head;
//         for (int i = 0; i < pos && cur != nullptr; i++)
//         {
//             prev = cur;
//             cur = cur->next;
//         }

//         if (cur == nullptr)
//         {
//             cout << "Out of Range.\n";
//             return;
//         }
//         else
//         {
//             prev->next = cur->next;
//             if (cur->next != nullptr)
//             {
//                 cur->next->pre = prev;
//             }
//             delete cur;
//         }
//     }

//     void reverseDLL()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         else
//         {
//             NodeD *newHead = nullptr;
//             NodeD *temp = head;
//             while (temp != nullptr)
//             {
//                 NodeD *swap = temp->next;
//                 temp->next = temp->pre;
//                 temp->pre = swap;
//                 temp = temp->pre;
//             }
//             newHead = tail;
//             tail = head;
//             head = newHead;
//         }
//     }

//     void searchData__Delete(int value)
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         bool found = false;
//         NodeD *cur = head;
//         while (cur != nullptr)
//         {
//             if (cur->data == value)
//             {
//                 found = true;
//                 break;
//             }
//             cur = cur->next;
//         }
//         if (found)
//         {
//             NodeD *temp = cur->pre;
//             temp->next = cur->next;
//             delete cur;
//         }
//     }

//     void deleteAllOccurrencesOfASpecificValue(int value)
//     {
//         if (head == nullptr)
//         {
//             cout << "List is empty.\n";
//             return;
//         }

//         NodeD *cur = head;

//         while (cur != nullptr)
//         {
//             if (cur->data == value)
//             {
//                 NodeD *temp = cur;

//                 if (cur == head)
//                 {
//                     head = head->next;
//                     if (head != nullptr)
//                     {
//                         head->pre = nullptr;
//                     }
//                 }
//                 else
//                 {
//                     cur->pre->next = cur->next;
//                 }

//                 if (cur->next != nullptr)
//                 {
//                     cur->next->pre = cur->pre;
//                 }

//                 cur = cur->next;
//                 delete temp;
//             }
//             else
//             {
//                 cur = cur->next;
//             }
//         }
//     }

//     void show()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty.\n";
//             return;
//         }
//         cout << "DLL List: ";
//         NodeD *temp = head;
//         while (temp != nullptr)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "\n";
//     }
// };

// // class Queue
// // {
// // private:
// //     int *arr;
// //     int rear, front, cap;

// // public:
// //     Queue(int Size)
// //     {
// //         arr = new int[Size];
// //         rear = -1;
// //         front = -1;
// //         cap = Size;
// //     }
// //     ~Queue()
// //     {
// //         delete[] arr;
// //     }
// //     void Enqueue(int value)
// //     {
// //         if (rear == cap - 1)
// //         {
// //             cout << "Queue Overflow.\n";
// //             return;
// //         }
// //         if (front == -1)
// //         {
// //             front = 0;
// //         }
// //         rear++;
// //         arr[rear] = value;
// //     }
// //     void Dequeue()
// //     {
// //         if (front == -1 || front > rear)
// //         {
// //             cout << "Queue Underflow.\n";
// //             return;
// //         }
// //         arr[front++];

// //         if (front > rear)
// //         {
// //             rear = front = -1;
// //         }
// //     }
// //     void show()
// //     {
// //         if (front == -1 || front > rear)
// //         {
// //             cout << "Queue is Empty.\n";
// //             return;
// //         }
// //         cout << "Queue list: ";
// //         for (int i = front; i <= rear; i++)
// //         {
// //             cout << arr[i] << " ";
// //         }
// //         cout << "\n";
// //     }
// // };
// ///////////////////////////////////////////////////////////////////////
// // const int sizeQ = 5;
// // int Queue[sizeQ];
// // int front = -1;
// // int rear = -1;

// // void Enqueue(int value)
// // {
// //     if (rear == sizeQ - 1)
// //     {
// //         cout << "Queue is Full.\n";
// //         return;
// //     }
// //     if (front == -1)
// //     {
// //         front++;
// //     }

// //     Queue[++rear] = value;
// // }

// // void Dequeue()
// // {
// //     if (front == -1 || front > rear)
// //     {
// //         cout << "Queue is Empty.\n";
// //         return;
// //     }
// //     front++;
// //     if (front > rear)
// //     {
// //         rear = front = -1;
// //     }
// // }

// // void show()
// // {
// //     if (front == -1)
// //     {
// //         cout << "Empty Queue.\n";
// //         return;
// //     }
// //     cout << "Queue list: ";
// //     for (int i = front; i <= rear; i++)
// //     {
// //         cout << Queue[i] << " ";
// //     }
// //     cout << endl;
// // }

// ///////////////////////////////////////////////////////////////////////////////////

// // int stack[sizeQ];
// // int top = -1;

// // void push(int value)
// // {
// //     if (top == sizeQ - 1)
// //     {
// //         cout << "Stack Overflow.\n";
// //         return;
// //     }
// //     top++;
// //     stack[top] = value;
// // }
// // void pop()
// // {
// //     if (top == -1)
// //     {
// //         cout << "Stack UnderFlow.\n";
// //         return;
// //     }
// //     stack[--top];
// // }
// // void show()
// // {
// //     if (top == -1)
// //     {
// //         cout << "Stack is Empty.\n";
// //         return;
// //     }
// //     cout << "Stack list: ";
// //     for (int i = top; i >= 0; i--)
// //     {
// //         cout << stack[i] << " ";
// //     }
// //     cout << "\n";
// // }

// /////////////////////////////////////////////////////////////////

// // int const s = 5;
// // int CirQueue[s];
// // int front = -1, rear = -1;

// // void Enqueue(int value)
// // {
// //     if ((rear + 1) % s == front)
// //     {
// //         cout << "Queue OverFlow.\n";
// //         return;
// //     }
// //     if (front == -1)
// //     {
// //         rear = front = 0;
// //     }
// //     else
// //     {
// //         rear = (rear + 1) % s;
// //     }
// //     CirQueue[rear] = value;
// // }
// // void dequeue()
// // {
// //     if (front == -1)
// //     {
// //         cout << "Queue Underflow.\n";
// //         return;
// //     }
// //     if (front == rear)
// //     {
// //         front = rear = -1;
// //     }
// //     else
// //     {
// //         front = (front + 1) % s;
// //     }
// // }

// // void show()
// // {
// //     if (front == -1)
// //     {
// //         cout << "Queue is underflow.\n";
// //         return;
// //     }
// //     cout << "Queue list: ";
// //     int i = front;
// //     while (true)
// //     {
// //         cout << CirQueue[i] << " ";
// //         if (i == rear)
// //             break;
// //         i = (i + 1) % s;
// //     }
// //     cout << "\n";
// // }

// // class Cqueue
// // {
// // private:
// //     int *arr;
// //     int cap, front, rear;

// // public:
// //     Cqueue(int size) : front(-1), rear(-1), cap(size), arr(new int[size]) {}

// //     ~Cqueue()
// //     {
// //         delete[] arr;
// //     }

// //     void Enqueue(int value)
// //     {
// //         if ((rear + 1) % cap == front)
// //         {
// //             cout << "Queue is OverFlow.\n";
// //             return;
// //         }
// //         else if (front == -1)
// //         {
// //             front = rear = 0;
// //         }
// //         else
// //         {
// //             rear = (rear + 1) % cap;
// //         }

// //         arr[rear] = value;
// //     }

// //     void Dequeue()
// //     {
// //         if (front == -1)
// //         {
// //             cout << "Empty.\n";
// //             return;
// //         }
// //         else if (front == rear)
// //         {
// //             front = rear = -1;
// //         }
// //         else
// //         {
// //             front = (front + 1) % cap;
// //         }
// //     }

// //     void show()
// //     {
// //         if (front == -1)
// //         {
// //             cout << "Empty.\n";
// //             return;
// //         }
// //         int i = front;
// //         cout << "List: ";
// //         while (true)
// //         {
// //             cout << arr[i] << " ";
// //             if (i == rear)
// //             {
// //                 break;
// //             }
// //             i = (i + 1) % cap;
// //         }
// //         cout << "\n";
// //     }
// // };

// int main()
// {
//     // LL l;
//     // l.addAtEnd(1);
//     // l.addAtEnd(2);
//     // l.addAtEnd(3);
//     // l.addAtEnd(4);
//     // l.addAtEnd(4);
//     // l.addAtEnd(4);
//     // l.addAtEnd(4);
//     // l.insertAthead(0);
//     // l.ReverseLL();
//     // l.DeleteFromHead();
//     // l.deleteFromRear();
//     // l.ReverseLL();
//     // l.addAtEnd(4);
//     // l.insertAthead(0);
//     // l.insertAtPositon(5, 5);
//     // l.deleteAtpos(7);
//     // l.deleteAtpos(6);
//     // l.deleteAtpos(6);

//     // l.show();

//     DLL d;
//     d.InsertAtFront(1);
//     d.InsertAtFront(2);
//     d.InsertAtFront(3);
//     d.InsertAtFront(4);
//     d.InsertAtFront(4);
//     d.InsertAtFront(4);
//     d.InsertAtFront(4);
//     d.InsertAtFront(4);
//     d.InsertAtFront(4);
//     d.InsertAtFront(4);
//     d.InsertAtFront(5);
//     d.InsertAtEnd(0);
//     d.deleteFront();
//     d.deleteEnd();
//     d.insertAtPos(7, 2);
//     d.insertAtPos(8, 6);
//     d.deleteFromPos(2);
//     d.deleteFromPos(4);
//     // d.reverseDLL();
//     d.searchData__Delete(2);
//     d.deleteAllOccurrencesOfASpecificValue(4);
//     d.show();

//     // Enqueue(0);
//     // Enqueue(1);
//     // Enqueue(2);
//     // Enqueue(3);
//     // Enqueue(4);
//     // // show();
//     // Dequeue();
//     // // show();

//     // push(0);
//     // push(1);
//     // push(2);
//     // push(3);
//     // push(4);
//     // push(5);
//     // // show();
//     // pop();
//     // pop();
//     // pop();
//     // // show();

//     // Queue Q(5);
//     // Q.Enqueue(0);
//     // Q.Enqueue(1);
//     // Q.Enqueue(2);
//     // Q.Enqueue(3);
//     // Q.Enqueue(4);
//     // Q.Enqueue(5);

//     // Q.show();

//     // Enqueue(0);
//     // Enqueue(1);
//     // Enqueue(2);
//     // Enqueue(3);
//     // Enqueue(4);
//     // Enqueue(5);
//     // show();
//     // dequeue();
//     // show();
//     // Enqueue(5);
//     // show();

//     // Cqueue c(5);
//     // c.Enqueue(0);
//     // c.Enqueue(1);
//     // c.Enqueue(2);
//     // c.Enqueue(3);
//     // c.Enqueue(4);
//     // c.Enqueue(4);
//     // c.show();
//     // c.Dequeue();
//     // c.Enqueue(3);
//     // c.Dequeue();
//     // c.Dequeue();
//     // c.show();

//     cout << endl;
//     return 0;
// }