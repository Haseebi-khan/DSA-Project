#include <iostream>
using namespace std;

// Array must be Shorted in Binary Search Case. 

int BinarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size = 100;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    cout << "Enter element for searching in array: ";
    int element;
    cin >> element;

    int found = BinarySearch(arr, size, element);
    if (found == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element found at index: " << found << endl;
    }

    return 0;
}
