#include <iostream>
using namespace std;

int main()
{

    int *num2 = nullptr;
    int b = 10;
    int *num = &b;
    cout << "Number1 Checking Condition.\n";
    if (num)
    {
        cout << "True.\n";
    }
    else
    {
        cout << "False.\n";
    }


    cout << "Number2 Checking Condition.\n";
    if (num2)
    {
        cout << "True.\n";
    }
    else
    {
        cout << "False.\n";
    }
    return 0;
}