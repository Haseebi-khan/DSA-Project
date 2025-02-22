#include <iostream>
#include <array>
#include <vector>

// vector: A dynamic array that can resize itself as elements are added.
// push_back(): Adds an element to the end of the vector.
// size(): Returns the current number of elements in the vector.
// Iterators
// begin() – Returns an iterator pointing to the first element in the vector
// end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
// rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
// rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
// cbegin() – Returns a constant iterator pointing to the first element in the vector.
// cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
// crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
// crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

using namespace std;

int main()
{

    vector<double> arr{{20, 13, 34, 45}};
    vector<float> arrFilling;
    vector<int> arrSizeValue{5, 21};
    vector<double> arrCpy(arr);

    cout << arr.size() << " \n";

    for (auto value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    for (size_t i = 0; i < 5; i++)
    {
        arrFilling.push_back(i + 1);
    }
    for (auto i = arrFilling.begin(); i != arrFilling.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    for (auto i = arrFilling.cbegin(); i != arrFilling.cend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = arr.rbegin(); ir != arr.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = arr.crbegin(); ir != arr.crend(); ++ir)
        cout << *ir << " ";

    cout << endl;



    cout << endl;
    return 0;
}