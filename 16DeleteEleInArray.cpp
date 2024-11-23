#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteNum(int arr[], int &size, int index)
{
    if (index < size - 1)
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        --size;
    }
}

int main()
{

    int arr[10] = {56, 78, 99, 44, 22, 87};
    int size = 6; // used memory
    int element = 777;
    int index = 3;

    cout << "--------------------" << endl;

    display(arr, size);

    index = 3;
    element = 999;
    deleteNum(arr, size, index);

    cout << "\n--------------------" << endl;
    display(arr, size);

    cout << endl;
    return 0;
}
