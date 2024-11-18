#include <iostream>
#include <vector>
#include <array>
using namespace std;
template <class T>  // templete for data-type 
void display(vector<T> &vecarr)
{
    for (auto &value : vecarr)
    {
        cout << value << " ";
    }
}

int main()
{

    vector<int> arr;
    cout << "Enter the size of the Vector: ";
    int size;
    cin >> size;

    int element;
    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter element in the vector: ";
        cin >> element;
        arr.push_back(element);
    }
    arr.pop_back();
    display(arr);
    cout << "\nEnter New Value in Vector: ";
    int Value;
    cin >> Value;
    vector<int>::iterator position = arr.begin();

    arr.insert(position, Value);
    display(arr);

    vector<char> arr3;
    vector<char>::iterator position2 = arr3.begin();

    // cout << position2<<"\n"; how it works ?

    char ch;
    cout << "\n";
    for (auto i = 0; i < 4; i++)
    {
        cout << "Enter data in arr3: ";
        cin >> ch;
        position2 = arr3.insert(position2, ch);
        position2++;
    }

    for (char c : arr3)
    {
        cout << c << " ";
    }

    cout << "\nCopyed array\n";

    vector<char> arr4(arr3);

    for (auto ch : arr4)
    {
        cout << ch << " ";
    }

    vector<string> str;
    string characters;
    cout << "Enter how many string you want to store: ";
    int str_size;
    cin >> str_size;
    cin.ignore();
    for (size_t i = 0; i < str_size; i++)
    {
        cout << "Enter the Strings: ";
        getline(cin, characters);
        str.push_back(characters);
    }
    for (size_t i = 0; i < str_size; i++)
    {
        cout << str[i] << endl;
    }

    cout << endl;// OR
    
    for(auto &strings : str)
    {
        cout << strings <<endl;
    }

    cout << endl;
    return 0;
}