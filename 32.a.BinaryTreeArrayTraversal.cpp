#include <iostream>
using namespace std;

int arr[7]; // Binary tree array (assuming a root + 6 child nodes)
void fill_binary_Tree()
{
    cout << "Enter value for root: ";
    cin >> arr[0]; // Root node

    for (int i = 0; i < 7/2 ; i++) // Fill left and right children for nodes at indices 0, 1, 2
    {
        cout << "Enter value for left child of node " << arr[i] << ": ";
        cin >> arr[2 * i + 1]; // Left child

        cout << "Enter value for right child of node " << arr[i] << ": ";
        cin >> arr[2 * i + 2]; // Right child
    }
}

void print_binary_Tree()
{
    cout << "Binary tree stored in array: ";
    for (int i = 0; i < 7; i++) // Print the entire array
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    fill_binary_Tree();
    print_binary_Tree();

    return 0;
}
