#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteValueAtIndux(int arr[], int index, int &size, int cap)
{
    if (index < cap - 1)
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    else
    {
        cout << "Out Of Bound.\n";
    }
}

void myInsertionNewLogic(int arr[], int index, int element, int &size, int cap)
{
    if (size >= cap)
    {
        cout << "Full.\n";
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        size++;
        arr[index] = element;
    }
}

int main()
{
    int cap = 10;
    int arr[cap] = {56, 78, 99, 44, 22, 87};
    int size = 6;
    int index = 3;
    cout << "Arr Elements: ";
    display(arr, size);

    cout << "Arr Element Deleted At Thrid Index: ";
    deleteValueAtIndux(arr, index, size, cap);
    display(arr, size);

    cout << "Arr 12345 Added At Thrid Index: ";
    myInsertionNewLogic(arr, index, 12345, size, cap);
    display(arr, size);

    cout << endl;
    return 0;
}