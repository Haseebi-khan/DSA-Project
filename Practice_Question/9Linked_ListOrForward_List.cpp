// working of remove(), remove_if(), splice_after() and
// clear().
#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
    forward_list<int> list = {10, 20, 30, 25, 40, 40};

    // Removing element using remove()
    // Removes all occurrences of 40
    list.remove(40);

    cout << "The forward list after remove operation : ";
    for (int &c : list)
        cout << c << " ";
    cout << endl;

    // Removing according to condition. Removes
    // elements greater than 20. Removes 25 and 30
    list.remove_if([](int x)
                   { return x > 20; });

    // Displaying the forward list

    cout << "The forward list after remove_if operation : ";
    for (int &c : list)
        cout << c << " ";

    // Shifting elements from first to second
    // forward list after 1st position
    forward_list<int> list2 = {40, 50, 60};
    list2.splice_after(list2.begin(), list);
    cout << "\nThe forward list after splice_after operation "
            ": ";
    for (int &c : list2)
        cout << c << " ";

    // Forward List becomes empty
    list.clear();

    // Printing the Forward list
    cout << "\nForward list after using clear function: ";
    for (auto it = list.begin(); it != list.end(); ++it)
        cout << ' ' << *it;
    cout << endl;

    cout << endl;

    return 0;
}
