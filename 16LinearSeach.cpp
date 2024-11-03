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

int main()
{
    const int size = 10;
    int arr[size] = {34, 23, 1, 44, 5, 67, 23, 33, 23, 5};

    cout << "Enter Element for Search: ";
    int element;
    cin >> element;

    int found = linearSearch(arr, size, element);

    if (found != -1)
    {
        cout << "Value found at Index: " << found << endl;
    }
    else
    {
        cout << "Value is not found." << endl;
    }

    cout << endl;
    return 0;
}