#include <iostream>
using namespace std;

int main()
{

    int n = 5;
    int arr[5] = {4, 2, 3, 7, 5};

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (int i = start; i < end; i++)
            {
                cout << arr[i];
            }
            cout << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////


