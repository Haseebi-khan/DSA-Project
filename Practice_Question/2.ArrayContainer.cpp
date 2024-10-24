#include <iostream>
#include <array> // for Array, get(), swap(), fill() and empty().
#include <tuple> // for at(), Back(), front(), size() and max_size().

using namespace std;

int main()
{
    array<double, 6> num = {1, 2, 3, 4, 5, 6};

    cout << "First Element Of Array: ";
    // int &firstelement = static_cast<int>(num.front());   // cause error bcz static_ cast, int cant change double array value.
    const int &firstelement = static_cast<int>(num.front());
    cout << firstelement << endl;
    double &firstNum = num.front();
    cout << firstNum << "\n";
    firstNum = 33;
    cout << firstNum << " " << firstelement << endl;

    cout << "Last Element Of Array\n";
    double &lastNum = num.back();
    cout << lastNum << endl;

    firstNum = lastNum = 9;

    cout << "Array after updating first and last elements. " << endl;
    for (auto x : num)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "The number of array elements is : ";
    cout << num.size() << endl;

    cout << "Maximum elements array can hold is : ";
    cout << num.max_size() << endl;

    // Swapping num values with num2

    array<double, 6> num2 = {7, 8, 9, 0, 1, 2};

    cout << "Array1  and Array2  values.\n";
    for (auto value : num)
    {
        cout << value << " ";
    }
    cout << endl;
    for (auto value : num2)
    {
        cout << value << " ";
    }

    // Swapping num values with num2

    cout << "\nSwapping num values with num.";

    num.swap(num2);

    cout << "\nUpdated Array1  and Array2  values.\n";
    for (auto value : num)
    {
        cout << value << " ";
    }
    cout << endl;
    for (auto value : num2)
    {
        cout << value << " ";
    }
    cout << endl;

    num.empty() ? cout << "Num array is Empty\n" : cout << "Num array is not Empty\n";

    for (auto value : num)
    {
        cout << value << " ";
    }
    cout << endl;

    cout << "Filling Num array with 0.\n";
    num.fill(0);
    for (auto value : num)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}