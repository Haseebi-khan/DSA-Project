#include <iostream>
#include <vector>
using namespace std;

// Write a program to merge two doubly linked
// lists into a single sorted doubly linked list.

class node
{
public:
    int data;
    node *next;
    node *pre;

    node(int value = 0) : data(value), next(nullptr), pre(nullptr) {}
};

class doublyLinkedList
{
private:
    node *head, *tail;

public:
    doublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert node at the end
    void insertAtEnd(int value)
    {
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    // Function to display the list
    void Display()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty." << endl;
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

    // Write a program to merge two doubly linked
    // lists into a single sorted doubly linked list.

    static doublyLinkedList mergeDLL(doublyLinkedList &_1st, doublyLinkedList &_2nd)
    {
        doublyLinkedList mergeObj;
        node *head1 = _1st.head;
        node *head2 = _2nd.head;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data <= head2->data)
            {
                mergeObj.insertAtEnd(head1->data);
                head1 = head1->next;
            }
            else
            {
                mergeObj.insertAtEnd(head2->data);
                head2 = head2->next;
            }
        }

        while (head1 != nullptr)
        {
            mergeObj.insertAtEnd(head1->data);
            head1 = head1->next;
        }
        while (head2 != nullptr)
        {
            mergeObj.insertAtEnd(head2->data);
            head2 = head2->next;
        }
        return mergeObj;
    }
};

int main()
{
    doublyLinkedList dLinkedList1;
    dLinkedList1.insertAtEnd(5);
    dLinkedList1.insertAtEnd(3);
    dLinkedList1.insertAtEnd(4);
    dLinkedList1.insertAtEnd(1);
    dLinkedList1.Display();

    doublyLinkedList dLinkedList2;
    dLinkedList2.insertAtEnd(2);
    dLinkedList2.insertAtEnd(3);
    dLinkedList2.insertAtEnd(2);
    dLinkedList2.insertAtEnd(4);

    dLinkedList2.Display();

    doublyLinkedList mergedList = doublyLinkedList::mergeDLL(dLinkedList1, dLinkedList2);

    cout << "Merged list: ";
    mergedList.Display();

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]

// void merge(vector<int> &arr, int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Create temp vectors
//     vector<int> L(n1), R(n2);

//     // Copy data to temp vectors L[] and R[]
//     for (int i = 0; i < n1; i++)
//     {
//         L[i] = arr[left + i];
//     }
//     for (int j = 0; j < n2; j++)
//     {
//         R[j] = arr[mid + 1 + j];
//     }

//     int i = 0, j = 0;
//     int k = left;

//     // Merge the temp vectors back
//     // into arr[left..right]
//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j])
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[],
//     // if there are any
//     while (i < n1)
//     {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[],
//     // if there are any
//     while (j < n2)
//     {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// // begin is for left index and end is right index
// // of the sub-array of arr to be sorted
// void mergeSort(vector<int> &arr, int left, int right)
// {
//     if (left >= right)
//     {
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     // mergeSort(arr, left, mid);
//     // mergeSort(arr, mid + 1, right);
//     merge(arr, left, mid, right);
// }

// // Function to print a vector
// void printVector(vector<int> &arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// // Driver code
// int main()
// {
//     vector<int> arr = {12, 11, 13, 5, 6, 7};
//     int n = arr.size();

//     cout << "Given vector is \n";
//     printVector(arr);

//     mergeSort(arr, 0, n - 1);

//     cout << "\nSorted vector is \n";
//     printVector(arr);
//     return 0;
// }