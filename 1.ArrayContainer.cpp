#include <iostream>
#include <array> // for array and at()
#include <tuple> // for get();
using namespace std;



int main() {
    size_t a;
    cout << sizeof(a) <<endl;

    array <double,6> arr = {1,2,3,4,5,6};
    array <string, 2> arrstr = {"string1", "string2"};

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "The Arrary Element are using at()\n";
    for (int i = 0; i < size ; i++)
    {
        cout << arr.at(i) << " ";
        if (i >= 0 && i <= 1)
        {
            cout << arrstr.at(i);
        }

    }

    cout << endl;

    cout << "The Arrary Element are using get()\n";
    cout << get<0>(arr) << " " << get<1>(arr) <<endl; 
    cout << get<2>(arr) << " " << get<3>(arr) <<endl; 
    cout << get<4>(arr) << " " << get<5>(arr) <<endl;
    cout << "The String Arrary Element are using get()\n";
    cout << get<0>(arrstr) << " " << get<1>(arrstr) <<endl; 

    // cout << get<6>(arr) << " " << get<7>(arr) <<endl;    // Cause Run time error due to accessing data out of range.

    // for (int N = 0; N < size; N++)
    // {
    //     cout << get<N>(arr) << " " ;
    // }

    cout << endl;

    cout << "The Arrary Element are using array operator\n";
    for (size_t i = 0; i < size ; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Each Array Elements Addresses using Imperson (&)\n";
    for (size_t i = 0; i < size; i++)
    {
        cout << &arr.at(i) << " ";
    }

    cout << endl;

    for (size_t i = 0; i < size; i++)
    {
        cout << &arr[i] << " ";
    }


    return 0;
}


#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int main ()
{
    const char* str = "Haseeb khan / Shams Ullah ";
    const int size = sizeof(str);
    array<char,size + 1> arr;
    memcpy (arr.data(),str,size);
    cout << arr.data() << '\n';
    
    array <char, size> str2;
    memcpy(str2, arr, size);
    return 0;
}