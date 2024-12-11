#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
        {
            return i;
        }
    }
    return -1;
}

void sortArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

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
    const int size = 10;
    int arr[size] = {34, 23, 1, 44, 5, 67, 23, 33, 23, 5};

    cout << "Before Sort: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Sort Arry: ";
    sortArray(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    // cout << "Enter Element for Search: ";
    // int element;
    // cin >> element;

    // int found = linearSearch(arr, size, element);

    // if (found != -1)
    // {
    //     cout << "Value found at Index: " << found << endl;
    // }
    // else
    // {
    //     cout << "Value is not found." << endl;
    // }

    cout << endl;
    return 0;
}