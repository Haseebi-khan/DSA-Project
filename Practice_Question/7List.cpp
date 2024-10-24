#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void show(list <int> nums)
{
    list <int> ::iterator i;
    for ( i = nums.begin(); i != nums.end(); i++)
    {
        cout << *i << " " ; 
    }
    cout << "\n";
    
}

int main() {
    
    list<int> numbers, numbers2;
    for (size_t i = 0; i < 10; i++)
    {
        numbers.push_back(i * 2);
        numbers2.push_back(i * 3);

    }

    cout << "List1: ";
    show(numbers);

    cout << "List2: ";
    show(numbers2);

    cout << "numbers.front() : " << numbers.front();
    cout << "\nnumbers.back() : " << numbers2.back();

    cout << "\nNumbers Reverse: ";
    numbers.reverse();
    show(numbers);

    cout << "Number Sort: ";
    numbers.sort();
    show(numbers);
    
    

    
    
    cout << endl;
    return 0;
}