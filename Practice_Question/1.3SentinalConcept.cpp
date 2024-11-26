#include <iostream>
using namespace std;

int main()
{
    int value = 5; // Value to search for
    int data[] = {34, 2, 4, 324, 24, 43, 23, 5, 32, 3, -1}; // Array ending with -1 (sentinel value)
    int count = 0; // Start searching from index 0
    int foundData = 0; // Flag to indicate if the value was found

    while (data[count] != -1) // Stop when we reach the sentinel value
    {
        if (data[count] == value) // Check if the value matches
        {
            cout << "count iteration: " << count + 1 << endl;
            cout << "Data: " << data[count] << " Value: " << value << endl;
            foundData = 1; // Set flag to indicate the value was found
            break; // Exit the loop since we found the value
        }
        count++; // Increment the counter
    }

    if (!foundData)
    {
        cout << "Value not found in the array." << endl;
    }

    cout << "Final count value: " << count << endl;

    return 0;
}
