#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

int main()
{

    forward_list<int> number;
    forward_list<int> number2;
    forward_list<int> number3;

    number.assign({34, 23, 45, 34});
    number2.assign({3, 2, 5, 4});
    number3.assign({9, 8, 6, 7});
    // ==============================================================

    cout << "Linked List 1: ";
    for (auto &nums : number)
    {
        cout << nums << " ";
    }
    cout << "\n";
    // ==============================================================
    cout << "Linked List 2: ";
    for (auto &nums : number2)
    {
        cout << nums << " ";
    }
    cout << "\n";
    // ==============================================================

    cout << "Linked List 3: ";
    for (auto &nums : number3)
    {
        cout << nums << " ";
    }
    cout << "\n";
    // ==============================================================

    // Inserting value using insert_after()
    // starts insertion from second position
    forward_list<int>::iterator ptr;
    ptr = number3.insert_after(number3.begin(), {26, 22, 11, 54});

    cout << "Linked List 3 after insert_after: ";
    for (auto &nums : number3)
    {
        cout << nums << " ";
    }
    cout << "\n";
    // ==============================================================

    // Inserting value using emplace_after()
    // inserts 2333 after ptr
    cout << "Linked List 3 after emplace_after: ";
    ptr = number3.emplace_after(ptr, 2333);
    for (auto &num : number3)
    {
        cout << num << " ";
    }
    cout << endl;

    // ==============================================================

    // Deleting value using erase.after Deleted 2333
    // after ptr
    ptr = number3.erase_after(ptr);
    cout << "Linked List 3 after erase_after (after ptr): ";
    for (auto &num : number3)
        cout << num << " ";
    // ==============================================================

    // Deleting value in a range
    // another variant of erase which uses start and end iterator
    // and deletes all the values in between them
    ptr = number3.erase_after(number3.begin(), number3.end());
    cout << "\nLinked list 3 afer fully Erase: ";
    for (auto &num : number3)
    {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}