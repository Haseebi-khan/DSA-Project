// Question 11:
// Given a string containing only lowercase letters and spaces, remove pairs of matching characters. This
// matching starts from the end of the string.
// For example:
// Input: “assassin”
// Output: “in“
// Input: “pacific ocean”
// Output: “pcf oen“
// Input: “an assassin sins”
// Output: “an“

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> st2;
    stack<char> st;
    string str = "an assassin sins";
    string newstr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            st.push(str[i]);
        }
        else if (!st.empty() && str[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {

        st2.push(st.top());
        st.pop();
    }
    while (!st2.empty())
    {
        newstr += st2.top();
        st2.pop();
    }

    cout << "string: " << newstr << endl;

    cout << endl;
    return 0;
}