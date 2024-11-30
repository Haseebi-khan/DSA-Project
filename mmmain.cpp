#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {
                22, 18, 135, 15, 90, 78, 69, 98, 102,
                83, 55, 28, 121, 120, 13, 22, 124, 112,
                70, 66, 74, 89, 103, 24, 21, 112, 21,
                40, 98, 87, 132, 115, 21, 28, 43, 37,
                50, 96, 118, 158, 74, 78, 83, 93, 95
                };

    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest = 3, highist = 32;
    int classWidth = (highist - smallest) / 6;
    sort(arr, n);
    int sum = 0;
    int count = 1;
    cout << "X" << "  " << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
        sum += arr[i];
        count +=1;
    }
    cout << endl;
    cout << endl;
    cout << "class intervel"<<endl; 
    for (int i = 3; i <= 32 ; i++)
    {
        cout << i << "--" << i + 4 << endl;
        i +=4;
    }

    cout << endl;
    cout << endl;

    cout << "Small: " << smallest << "  Highest: " << highist << endl;
    cout << "Class width : " << classWidth << endl;
    cout << "Count : " << count << endl;
    cout << "Sum: " << sum << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}
