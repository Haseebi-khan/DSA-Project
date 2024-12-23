// 3. Write a C++ program to sort a given stack (using an array) using another stack.
// Test Data:
// Input some elements onto the stack:
// Stack elements: 0 1 5 2 4 7
// Sort the elements in the stack:
// Display the sorted elements of the stack:
// Stack elements: 0 1 2 4 5 7
// Remove two elements:
// Stack elements: 2 4 5 7
// Input two more elements
// Stack elements: 10 -1 2 4 5 7
// Sort the elements in the stack:
// Display the sorted elements of the stack:
// Stack elements: -1 2 4 5 7 10

#include <iostream>
#include <stack>
using namespace std;
stack <int> st;

void sorting()
{
    stack <int> temp;

    while (!st.empty())
    {
        int value = st.top();
        st.pop();
        while (!temp.empty() && temp.top() > value)
        {
            st.push(temp.top());
            temp.pop();
        }
        temp.push(value);
    }

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

void show()
{
    if (!st.empty())
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }
    
}

int main() 
{
    
    st.push(5);
    st.push(4);
    st.push(2);
    st.push(6);
    st.push(7);
    st.push(1);

    sorting();
    show();
    cout << endl;
    return 0;
}