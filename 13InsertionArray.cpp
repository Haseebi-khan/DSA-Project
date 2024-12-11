#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int insertionArray(int arr[], int &size, int element, int capcity, int index)
{
    if (size >= capcity)
    {
        cout << "Execeded." << endl;
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    (arr)[index] = element;
    size++;
    return 1;
}
int main()
{

    int arr[10] = {56, 78, 99, 44, 22, 87};
    int size = 6;
    int element = 777;
    int index = 3;
    display(arr, size);
    cout << endl;

    insertionArray(arr, size, element, 10, index - 1);

    cout << "--------------------" << endl;

    display(arr, size);

    index = 2;
    element = 999;
    insertionArray(arr, size, element, 10, index - 1);

    cout << "\n--------------------" << endl;
    display(arr, size);

    cout << endl;
    return 0;
}
