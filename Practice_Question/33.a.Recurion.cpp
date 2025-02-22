#include <iostream>
using namespace std;

int fact(int n)
{
    // BASE CONDITION
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int Sum_(int i, int j)
{
    if (i == j)
    {
        return j;
    }

    return i + Sum_(i + 1, j);
}

void numb(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    
    cout << n << " ";
    numb(n -1);

}

int main()
{
    cout << "Factorial of 5 : " << fact(5);

    cout << endl;
    cout << endl;

    cout << "From Sum 1 of 5 : " << Sum_(1, 5);
    cout << endl;
    cout << endl;

    cout << "Print numbers from 1 to 10: \n";
    cout << "Numbers: ";
    numb(10);
    


    cout << endl;

    return 0;
}