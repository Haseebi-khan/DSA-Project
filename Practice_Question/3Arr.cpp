#include <iostream>
#include <array>
#include <string>

using namespace std;

int main()
{
    const int size = 10;

    char cha = 10;
    int ch = cha;

    cout << static_cast<int>(cha) << "\n";

    array<char, size> arr5;

    for (int i = 0; i < size; i++)
    {
        arr5.at(i) = '0' + (i + 1); /// Assci of 1 = 49
    }
    cout << endl;
    cout << endl;

    for (const auto &str : arr5)
    {
        cout << static_cast<int>(str) << " ";
    }
    cout << endl;
    cout << '\n';
    for (const auto &str : arr5)
    {
        cout << static_cast<int>(str) << " ";
    }

    cout << endl;

    array<string, 3> arr;

    std::cout << "plz Enter 3 strings: ";

    for (size_t i = 0; i < 3; i++)
    {
        getline(cin, arr.at(i));
    }

    for (const auto &x : arr)
    {
        std::cout << x << endl;
    }

    array<string, 3> arr2;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j != '\0'; j++)
        {
            arr[i][j] = arr2[i][j];
        }
    }

    for (const auto &x : arr2)
    {
        std::cout << x << endl;
    }

    return 0;
}